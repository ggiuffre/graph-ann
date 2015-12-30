#include "net.h"

// =============================================
// =============================================
// ==================== TUTTO DA RISCRIVERE ====
// ==================== ___________________ ====
// =============================================
// =============================================
// =============================================

void Net::incr_training(const int n_examples, const float ** examples, const float ** target, const float learning_rate, const float momentum, const float desired_err)
{
	float	in_momentum_term = 0.0f,
			hid_momentum_term = 0.0f;



	// --- set the bias neurons to 1.0f:

	hid_outputs[0] = 1.0f;
	out_outputs[0] = 1.0f;



	/* The network will converge if and only if the target
	outputs are in the image of the activating
	function or can be expressed as an element of the
	image plus/minus the desired error (e.g. the sigmoid function
	has image (0,1) so target outputs will have to be in
	(0-a,1+a) where a is the desired error)  */

	float tot_err = 0.0f;
	int num_epochs = 0, i = -1;
	std::ofstream predictions("log.txt");
	std::ofstream err_1("err.txt");

	do		// --- until the termination condition is met, do...
	{
		num_epochs++;
		predictions << num_epochs << ' ';
		err_1 << num_epochs << ' ';

		srand(time(NULL));
		std::vector<int> inds(n_examples);		// randomly shuffled indexes
		for (int i = 0; i < n_examples; ++i)
			inds[i] = i;
		std::random_shuffle(inds.begin(), inds.end());

		for (int t = 0; t < n_examples; ++t)	// --- for each training example, do...
		{
			i = inds[t];
			//std::cout << "example " << i << std::endl;



			// --- propagate input forward:

			for (int j = 1; j < n_hid + 1; ++j)
				hid_outputs[j] = sigmoid_unit(examples[i], hid_weights[j], n_in + 1);

			for (int j = 1; j < n_out + 1; ++j)
				out_outputs[j] = sigmoid_unit(hid_outputs, out_weights[j], n_hid + 1);



			// --- compute error terms:

			float err = 0.0f;
			for (int j = 1; j < n_out + 1; ++j)
			{
				out_delta[j] = out_outputs[j] * (1.0f - out_outputs[j]) * (target[i][j] - out_outputs[j]);
				predictions << out_outputs[j] << ' ';
				err += fabs(target[i][j] - out_outputs[j]);
				err_1 << err << ' ';
			}
			err /= n_out;

			for (int j = 1; j < n_hid + 1; ++j)
			{
				float tmp_sum = 0.0f;
				for (int k = 1; k < n_out + 1; ++k)
					tmp_sum += out_weights[k][j] * out_delta[k];
				hid_delta[j] = hid_outputs[j] * (1.0f - hid_outputs[j]) * tmp_sum;
			}



			// --- update network weights:

			for (int j = 1; j < n_out + 1; ++j)
				for (int k = 0; k < n_hid + 1; ++k)		// dovrebbe essere giusto cosi'...
				{
					out_weights[j][k] += learning_rate * out_delta[j] * hid_outputs[k] + momentum * hid_momentum_term;
					hid_momentum_term = learning_rate * out_delta[j] * hid_outputs[k] + momentum * hid_momentum_term;
				}

			for (int j = 1; j < n_hid + 1; ++j)
				for (int k = 0; k < n_in + 1; ++k)
				{
					hid_weights[j][k] += learning_rate * hid_delta[j] * examples[i][k] + momentum * in_momentum_term;
					in_momentum_term = learning_rate * hid_delta[j] * examples[i][k] + momentum * in_momentum_term;
				}



			tot_err += err;
		}
		tot_err /= n_examples;
		std::cout << '\r' << num_epochs << '\t' << tot_err;
		predictions << std::endl;
		err_1 << std::endl;

	} while (tot_err > desired_err);

	delete [] out_outputs;
	delete [] hid_outputs;
	delete [] out_delta;
	delete [] hid_delta;

	std::cout << std::endl;
	//std::cout << " epochs" << std::endl;
	predictions.close();
	err_1.close();
}
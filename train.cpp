#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "layered_net.h"

void layeredNet::incremental_training(const unsigned int n_examples, float ** const examples, float ** const target, const float learning_rate, const float momentum, const float desired_err)
{
	float * momentum_terms = new float [n_layers];
	for (layers_iterator i = l_begin(); i < l_end(); ++i)
		momentum_terms[i] = 0.0f;

	unit * units = new unit [size()];
	for (nodes_iterator i = begin(l_begin()); i < end(l_end() - 1); ++i)
		units[i] = unit();		// ma forse ci pensa già il costruttore di default! <<<<<

	init(RAND, 1.0f);



	/* The training algorithm  will converge only if the target outputs are in the image of the activating function or can be expressed as an element of the image plus/minus the desired error (e.g. the sigmoid function has image (0,1) so target outputs will have to be in (0-e,1+e) where e is the desired error) */

	float tot_err = 0.0f;
	unsigned int num_epochs = 0;
	unsigned int output_size = is_biased ? layers[l_end() - 1].size - 1 : layers[l_end() - 1].size;

	do		// --- until the termination condition is met, do...
	{
		num_epochs++;
		std::cout << "\n[" << num_epochs << "]\n";

		srand(time(NULL));
		std::vector<int> inds(n_examples);		// randomly shuffled indexes
		for (unsigned int i = 0; i < n_examples; ++i)
			inds[i] = i;
		std::random_shuffle(inds.begin(), inds.end());

		for (unsigned int r = 0; r < n_examples; ++r)	// --- for each training example, do...
		{
			unsigned int e = inds[r];

			std::cout << "<";
			for (unsigned int i = 0; i < output_size; ++i)
				std::cout << target[e][i] << ", ";
			std::cout << "\b\b>\t";



			// --- store the example, input it to the network and store the output of every unit:

			store(std::vector<float>(examples[e], examples[e] + network::input_size()));

			for (nodes_iterator i = begin(l_begin()); i < end(l_begin()); ++i)
				units[i].out = neuron(i);

			for (layers_iterator l = l_begin() + 1; l < l_end(); ++l)
				for (nodes_iterator i = begin(l); i < end(l); ++i)
					units[i].out = neuron(i);

			std::cout << "(";
			for (nodes_iterator i = begin(l_end() - 1); i < end(l_end() - 1); ++i)
				std::cout << units[i].out << ", ";
			std::cout << "\b\b)\t";

			// (SI PUO MIGLIORARE!)  ^^^^^



			// --- compute the error terms:

			float err = 0.0f;

			unsigned int t = 0;
			for (nodes_iterator i = begin(l_end() - 1) + is_biased; i < end(l_end() - 1); ++i)	// is_biased?
			{
				units[i].delta = units[i].out * (1.0f - units[i].out) * (target[e][t] - units[i].out);
//				if (!is_biased || i != begin(l_end() - 1))
					err += fabs(target[e][t] - units[i].out);
				t++;
			}
			err /= output_size;
			std::cout << err << "\n";

			for (layers_iterator l = l_end() - 2; l != l_begin(); --l)
				for (nodes_iterator i = begin(l) + is_biased; i < end(l); ++i)	// is_biased?
				{
					float downstream = 0.0f;
					for (nodes_iterator j = begin(l + 1); j < end(l + 1); ++j)
						downstream += edge(i, j) * units[j].delta;
					units[i].delta = units[i].out * (1.0f - units[i].out) * downstream;
				}

			for (nodes_iterator i = begin(l_begin()) + is_biased; i < end(l_begin()); ++i)	// is_biased?
			{
				float downstream = 0.0f;
				for (nodes_iterator j = begin(l_begin() + 1); j < end(l_begin() + 1); ++j)
					downstream += edge(i, j) * units[j].delta;
				units[i].delta = units[i].out * (1.0f - units[i].out) * downstream;
			}



			// --- update the network weights:

			for (layers_iterator l = l_begin(); l < l_end() - 1; ++l)
				for (nodes_iterator i = begin(l) + is_biased; i < end(l); ++i)	// is_biased?
				{
					for (nodes_iterator j = begin(l + 1); j < end(l + 1); ++j)
					{
						if (edge(i, j))
						{
							edge(i, j) += learning_rate * units[j].delta * units[i].out + momentum * momentum_terms[l];
							momentum_terms[l] = learning_rate * units[j].delta * units[i].out + momentum * momentum_terms[l];
						}
					}
				}



			tot_err += err;
		}
		tot_err /= n_examples;
		std::cout << "error: " << tot_err << " > " << desired_err << "\n";
	} while (tot_err > desired_err);

	delete [] units;
	delete [] momentum_terms;
}
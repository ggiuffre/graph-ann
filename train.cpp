#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "nets.h"

void layeredSigmoidNet::incremental_training(const unsigned int n_examples, float ** const examples, float ** const targets, const float learning_rate, const float momentum, const float desired_err)
{
	std::vector<unit> units(size());
	std::vector<float> momentum_terms(n_layers(), 0.0f);

	init(RAND, 0.5f);

	/* The training algorithm  will converge only if the target outputs are in the image of the activating function or can be expressed as an element of the image plus/minus the desired error (e.g. the sigmoid function has image (0,1) so target outputs will have to be in (0-e,1+e) where e is the desired error) */

	float tot_err = 0.0f;
	unsigned int num_epochs = 0;



	do		// --- until the termination condition is met, do...
	{
		tot_err = 0.0f;
		num_epochs++;
		std::cout << "[" << num_epochs << "]\t";

		srand(time(NULL));
		std::vector<int> inds(n_examples);		// randomly shuffled indexes
		for (unsigned int i = 0; i < n_examples; ++i)
			inds[i] = i;
		std::random_shuffle(inds.begin(), inds.end());

		for (unsigned int r = 0; r < n_examples; ++r)	// --- for each training example, do...
		{
			unsigned int e = inds[r];

//			std::cout << "<";
//			for (unsigned int i = 0; i < output_size(); ++i)
//				std::cout << targets[e][i] << ", ";
//			std::cout << "\b\b>\t";

			// --- store the example, input it to the network and store the output of every unit:

			store(std::vector<float>(examples[e], examples[e] + network::input_size()));

			for (nodes_iterator i = begin(l_begin()); i < end(l_begin()); ++i)
				units[i].out = neuron(i);

			for (layers_iterator l = l_begin() + 1; l < l_end(); ++l)
				for (nodes_iterator i = begin(l); i < end(l); ++i)
					units[i].out = neuron(i);

//			std::cout << "(";
//			for (nodes_iterator i = begin(l_end() - 1); i < end(l_end() - 1); ++i)
//				std::cout << units[i].out << ", ";
//			std::cout << "\b\b)\t";

			// (SI PUO MIGLIORARE!)  ^^^^^

			// --- compute the error terms:

			float err = 0.0f;

			unsigned int t = 0;
			for (nodes_iterator i = begin(l_end() - 1) + 1; i < end(l_end() - 1); ++i)
			{
				units[i].delta = units[i].out * (1.0f - units[i].out) * (targets[e][t] - units[i].out);
//				if (i != begin(l_end() - 1))
					err += fabs(targets[e][t] - units[i].out);
				t++;
			}
			err /= output_size();
//			std::cout << err << '\n';

			for (layers_iterator l = l_end() - 2; l != l_begin(); --l)
				for (nodes_iterator i = begin(l) + 1; i < end(l); ++i)
				{
					float downstream = 0.0f;
					for (nodes_iterator j = begin(l + 1); j < end(l + 1); ++j)
						downstream += edge(i, j) * units[j].delta;
					units[i].delta = units[i].out * (1.0f - units[i].out) * downstream;
				}

			for (nodes_iterator i = begin(l_begin()) + 1; i < end(l_begin()); ++i)
			{
				float downstream = 0.0f;
				for (nodes_iterator j = begin(l_begin() + 1); j < end(l_begin() + 1); ++j)
					downstream += edge(i, j) * units[j].delta;
				units[i].delta = units[i].out * (1.0f - units[i].out) * downstream;
			}

			// --- update the network weights:

			for (layers_iterator l = l_begin(); l < l_end() - 1; ++l)
				for (nodes_iterator i = begin(l) + 1; i < end(l); ++i)
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
		std::cout << "error: " << tot_err << "\r";
	} while (tot_err > desired_err);
}

void layeredSigmoidNet::incremental_training(const std::string data_file, const float learning_rate, const float momentum, const float desired_err)
{
	unsigned int n_examples = 0;
	unsigned int n_in = 0;
	unsigned int n_out = 0;

	std::ifstream fin(data_file);
	fin >> n_examples >> n_in >> n_out;

	float ** examples = new float * [n_examples];
	for (unsigned int i = 0; i < n_examples; ++i)
		examples[i] = new float [n_in];

	float ** targets = new float * [n_examples];
	for (unsigned int i = 0; i < n_examples; ++i)
		targets[i] = new float [n_out];

	for (unsigned int e = 0; e < n_examples; ++e)
	{
		for (unsigned int i = 0; i < n_in; ++i)
			fin >> examples[e][i];
		for (unsigned int i = 0; i < n_out; ++i)
			fin >> targets[e][i];
	}

	fin.close();

	incremental_training(n_examples, examples, targets, learning_rate, momentum, desired_err);
}
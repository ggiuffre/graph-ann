#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

#include <time.h>
#include <stdlib.h>

#include <iostream>	// debugging
#include <string>
#include "layered_biased_net.h"

using std::vector;

class unit
{
public:
	float out, delta;
	unit() : out(0.0f), delta(0.0f) {}
};



void layeredBiasedNet::incremental_training(const vector<vector<float> >& examples, const vector<vector<float> >& targets, const float learning_rate, const float momentum, float& error, const unsigned int max_epochs)
{
	vector<unit> units(size());
	vector<float> momentum_terms(n_layers(), 0.0f);

	/* The training algorithm  will converge only if the target outputs are in the image of the activating function plus/minus the desired error (e.g. the sigmoid function has image (0,1) so target outputs will have to be in (0-e,1+e) where e is the desired error) */

	float tot_err = 0.0f;
	unsigned int num_epochs = 0;
	vector<unsigned int> inds;
	for (unsigned int i = 0; i < examples.size(); ++i)
		inds.push_back(i);



	do		// --- until the termination condition is met, do:
	{
		tot_err = 0.0f;
		++num_epochs;
		std::cout << "\r[" << num_epochs << "]\t";

		std::random_shuffle(inds.begin(), inds.end());

		for (auto e = inds.begin(); e < inds.end(); ++e)	// --- for each training example, do...
		{

			// --- store the example, input it to the network and store the output of every unit:

			store(examples[*e]);

			for (layers_iterator l = begin(); l < end(); ++l)
				for (nodes_iterator i = begin(l); i < end(l); ++i)
					units[i].out = neuron(i);

			// (SI PUO MIGLIORARE!)  ^^^^^

//			std::cout << "(";
//			for (nodes_iterator i = begin(end() - 1); i < end(end() - 1); ++i)
//				std::cout << units[i].out << ", ";
//			std::cout << "\b\b)\t";



			// --- compute the error terms:

			float err = 0.0f;

			unsigned int t = 0;
			for (nodes_iterator i = begin(end() - 1) + 1; i < end(end() - 1); ++i)
			{
				units[i].delta = activation_derivative(units[i].out) * (targets[*e][t] - units[i].out);		// senza derivata (?)
				err += fabs(targets[*e][t] - units[i].out);
				++t;
			}
			err /= output_size() - 1;
//			std::cout << err << '\n';

			for (layers_iterator l = end() - 2; l > begin(); --l)
				for (nodes_iterator i = begin(l) + 1; i < end(l); ++i)
				{
					float downstream = 0.0f;
					for (nodes_iterator j = begin(l + 1); j < end(l + 1); ++j)
						downstream += edge(i, j) * units[j].delta;
					units[i].delta = activation_derivative(units[i].out) * downstream;
				}

			for (nodes_iterator i = begin(begin()) + 1; i < end(begin()); ++i)
			{
				float downstream = 0.0f;
				for (nodes_iterator j = begin(begin() + 1); j < end(begin() + 1); ++j)
					downstream += edge(i, j) * units[j].delta;
				units[i].delta = activation_derivative(units[i].out) * downstream;
			}



			// --- update the network weights:

			for (layers_iterator l = begin(); l < end() - 1; ++l)
				for (nodes_iterator i = begin(l) + 1; i < end(l); ++i)
					for (nodes_iterator j = begin(l + 1) + 1; j < end(l + 1); ++j)
						if (edge(i, j))
						{
							link(i, j, edge(i, j) + learning_rate * units[j].delta * units[i].out + momentum * momentum_terms[l]);
							momentum_terms[l] = learning_rate * units[j].delta * units[i].out + momentum * momentum_terms[l];
						}

			tot_err += err;
		}
		tot_err /= examples.size();
		std::cout << "error: " << tot_err;
	} while (tot_err > error && num_epochs < max_epochs);
	error = tot_err;
	std::cout << '\n';
}

void layeredBiasedNet::incremental_training(const std::string data_file, const float learning_rate, const float momentum, float& error, const unsigned int max_epochs)
{
	unsigned int n_examples = 0;
	unsigned int n_in = 0;
	unsigned int n_out = 0;

	std::ifstream fin(data_file);
	fin >> n_examples >> n_in >> n_out;

	vector<vector<float> > examples(n_examples, vector<float>(n_in));
	vector<vector<float> > targets(n_examples, vector<float>(n_out));

	for (unsigned int e = 0; e < n_examples; ++e)
	{
		for (unsigned int i = 0; i < n_in; ++i)
			fin >> examples[e][i];
//		float min = *std::min_element(examples[e].begin(), examples[e].end());
// 						===============

		for (unsigned int i = 0; i < n_out; ++i)
			fin >> targets[e][i];
	}

	fin.close();

	incremental_training(examples, targets, learning_rate, momentum, error);
}

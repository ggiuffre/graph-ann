#include <cmath>
#include <algorithm>
#include <iostream>
#include "nets.h"

sigmoidNet::sigmoidNet(const unsigned int s) : network(s) {}

float sigmoidNet::activation_function(const float x) const
{
	return 1.0f / (1.0f + exp(-x));
}

float sigmoidNet::activation_derivative(const float y) const
{
	return y * (1.0f - y);
}





tanhNet::tanhNet(const unsigned int s) : network(s) {}

float tanhNet::activation_function(const float x) const
{
	return (2.0f / (1.0f + exp(-2.0f * x))) - 1.0f;
}

float tanhNet::activation_derivative(const float y) const
{
	return 1.0f - (y * y);
}





perceptron::perceptron(const unsigned int n_in, const float v, const float f) : verum(v), falsum(f)
{
	addLayer(n_in);
	addLayer(1);
}

float perceptron::activation_function(const float x) const
{
	return x > 0.0f ? verum : falsum;
}

void perceptron::train(const std::vector<std::vector<float> >& examples, const std::vector<std::vector<float> >& targets, const float learning_rate, float& error, const unsigned int max_epochs)
{
	std::vector<unit> units(size());
	std::vector<unsigned int> inds;
	for (unsigned int i = 0; i < examples.size(); ++i)
		inds.push_back(i);

	unsigned int epoch = 0;
	float tot_err = 0.0f;

	do
	{
		++epoch;
		tot_err = 0.0f;
//		std::cout << "\r[" << epoch << "]\t";
		std::cout << "\n[" << epoch << "]";
//		std::cout << *this << '\n';

		std::random_shuffle(inds.begin(), inds.end());
		for (auto e = inds.begin(); e < inds.end(); ++e)
		{
			store(examples[*e]);
			for (layers_iterator l = begin(); l < end(); ++l)
				for (nodes_iterator i = begin(l); i < end(l); ++i)
					units[i].out = neuron(i);

			std::cout << '{';
			float err = 0.0f;
			unsigned int t = 0;
			for (nodes_iterator i = begin(end() - 1) + 1; i < end(end() - 1); ++i)
			{
				units[i].delta = targets[*e][t];
				std::cout << units[i].delta << ' ';
				err += fabs(targets[*e][t] - units[i].out);
				++t;
			}
			err /= output_size() - 1;
			std::cout << "\b} -> " << err << "; ";

			for (nodes_iterator i = begin(begin()); i < end(begin()); ++i)
				for (nodes_iterator j = begin(end() - 1) + 1; j < end(end() - 1); ++j)
					if (edge(i, j))
						link(i, j, edge(i, j) + learning_rate * units[j].delta * units[i].out);

			tot_err += err;
		}
		tot_err /= examples.size();
		std::cout << "error: " << tot_err;
	} while (tot_err > error && epoch < max_epochs);
	error = tot_err;
	std::cout << '\n';
}





layeredSigmoidNet::layeredSigmoidNet(const float bv) : layeredBiasedNet(bv) {}

layeredSigmoidNet::layeredSigmoidNet(const std::string netfile, const float bv) : layeredBiasedNet(netfile, bv) {}





layeredTanhNet::layeredTanhNet(const float bv) : layeredBiasedNet(bv) {}

layeredTanhNet::layeredTanhNet(const std::string netfile, const float bv) : layeredBiasedNet(netfile, bv) {}

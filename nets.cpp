#include "nets.h"
#include <cmath>
#include <algorithm>
#include <iostream>

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





perceptron::perceptron(const unsigned int n_in, const float lr) : layeredBiasedNet(lr, 0.0f, true)
{
	addLayer(n_in);
	addLayer(1);
}

float perceptron::activation_function(const float x) const
{
	return x > 0.0f ? 1.0f : -1.0f;
}

void perceptron::train(const std::vector<std::vector<float> >& examples, const std::vector<std::vector<float> >& targets, float& error, const unsigned int max_epochs)
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

		std::random_shuffle(inds.begin(), inds.end());
		for (auto e = inds.begin(); e < inds.end(); ++e)
		{
			store(examples[*e]);
			for (layers_iterator l = begin(); l < end(); ++l)
				for (nodes_iterator i = begin(l); i < end(l); ++i)
					units[i].out = neuron(i);

std::cout << "ok\n";
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
						link(i, j, edge(i, j) + learningRate() * units[j].delta * units[i].out);

			tot_err += err;
		}
		tot_err /= examples.size();
		std::cout << "error: " << tot_err;
	} while (tot_err > error && epoch < max_epochs);

	error = tot_err;
	std::cout << '\n';
}





layeredSigmoidNet::layeredSigmoidNet(const float lr, const float m, const bool bp) : layeredBiasedNet(lr, m, bp) {}

layeredSigmoidNet::layeredSigmoidNet(const std::string netfile, const float lr, const float m, const bool bp) : layeredBiasedNet(netfile, lr, m, bp) {}





layeredTanhNet::layeredTanhNet(const float lr, const float m, const bool bp) : layeredBiasedNet(lr, m, bp) {}

layeredTanhNet::layeredTanhNet(const std::string netfile, const float lr, const float m, const bool bp) : layeredBiasedNet(netfile, lr, m, bp) {}

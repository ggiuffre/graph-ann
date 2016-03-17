#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "network.h"



// network

network::network(const unsigned int s) : DAG(s) {}

network::network(const std::string netfile)
{
	init(netfile);
}

network::network(const network& net) : DAG(net), input_map() {}

void network::init(init_t mode, const float bound)
{
	if (mode == RAND)
	{
		srand(time(NULL));
		for (nodes_iterator i = begin(); i < end(); ++i)
			for (weights_iterator j = begin(i); j < end(i); ++j)
				if (edge(j, i))
					link(j, i, (rand() % 1000) * ((2.0f * bound) / 1000.0f) - bound);
	}
	else if (mode == ZERO)
	{
		for (nodes_iterator i = begin(); i < end(); ++i)
			for (weights_iterator j = begin(i); j < end(i); ++j)
				link(j, i, 0.0f);
	}
}

void network::init(const std::string netfile)
{
	std::ifstream fin(netfile);

	if (fin)
	{
		unsigned int n_nodes = 0;
		fin >> n_nodes;
		*this = network(n_nodes);
		fin >> *this;
	}

	fin.close();
}

void network::sleep(const float threshold)
{
	for (nodes_iterator i = begin(); i < end(); ++i)
		for (weights_iterator j = begin(i); j < end(i); ++j)
			if (fabs(edge(j, i)) < threshold)
				link(j, i, edge(j, i) * 0.8f);
}

bool network::is_output(const unsigned int node) const
{
	if (node >= size())		// eccezione
		return 0;

	bool is_out = true;

	for (nodes_iterator i = begin(); i < end() && is_out; ++i)
		is_out = !edge(node, i);

	return is_out;
}

bool network::is_input(const unsigned int node) const
{
	if (node >= size())		// eccezione
		return 0;

	bool has_in = false;
	for (weights_iterator i = begin(node); i < end(node) && !has_in; ++i)
		has_in = edge(i, node);

	return !has_in;
}

unsigned int network::input_size() const
{
	unsigned int input_size = 0;
	for (nodes_iterator i = begin(); i < end(); ++i)
		if (is_input(i))
			input_size++;

	return input_size;
}

unsigned int network::output_size() const
{
	unsigned int output_size = 0;
	for (nodes_iterator i = begin(); i < end(); ++i)
		if (is_output(i))
			output_size++;

	return output_size;
}

void network::store(const std::vector<float>& in)
{
	if (in.size() >= input_size())
	{
		std::vector<float>::const_iterator it = in.begin();
		for (nodes_iterator i = begin(); i < end(); ++i)
			if (is_input(i))
				input_map[i] = *(it++);
	}
}

float network::activation_function(const float x) const
{
	return x;
}

float network::activation_derivative(const float y) const
{
	return 1.0f;
}

float network::neuron(const unsigned int i) const
{
	if (i >= size())		// eccezione
		return 0.0f;

	if (is_input(i))
		return input_map.find(i)->second;

	float result = 0.0f;
	for (weights_iterator j = begin(i); j < end(i); ++j)
		if (edge(j, i))
			result += edge(j, i) * neuron(j);

	return activation_function(result);
}

std::vector<float> network::operator()(const std::vector<float>& in)
{
	store(in);

	std::vector<float> result;
	for (nodes_iterator i = begin(); i < end(); ++i)
		if (is_output(i))
			result.push_back(neuron(i));

	input_map.clear();
	return result;
}

void network::save(const std::string netfile) const
{
	std::ofstream fout(netfile);
	fout << size() << std::endl << *this;
}

// DA ELIMINARE ___________________________________________
void network::random_pretraining(const std::string datafile, const unsigned int epochs)
{
	network random_try(*this);
	float err_1 = 0.0f;
	float err_2 = 0.0f;
	std::ifstream fin;
	for (unsigned int i = 0; i < epochs; ++i)
	{
		float epoch_err = 0.0f;
		random_try.init(RAND, 0.5f);
		fin.open(datafile);
		unsigned int n_examples, n_in, n_out;
		fin >> n_examples >> n_in >> n_out;
		for (unsigned int j = 0; j < n_examples; ++j)
		{
			float err = 0.0f;
			std::vector<float> input(n_in);
			for (unsigned int k = 0; k < n_in; ++k)
				fin >> input[k];
			std::vector<float> target(n_out);
			for (unsigned int k = 0; k < n_out; ++k)
				fin >> target[k];
			std::vector<float> output = random_try(input);
			for (unsigned int k = 0; k < n_out; ++k)
				err += fabs(output[k] - target[k]);
			epoch_err += err / n_out;
		}
		fin.close();
		if (i == 0)
			err_1 = epoch_err / n_examples;
		err_2 = epoch_err / n_examples;
		if (err_2 < err_1)
			*this = random_try;
	}
}



// operatori esterni

std::ostream& operator<<(std::ostream& os, const network& net)
{
	for (auto i = net.begin(); i < net.end(); ++i)
	{
		os << std::endl;
		for (auto j = net.begin(); j < net.end() - 1; ++j)
			os << net.edge(j, i) << ' ';
		os << net.edge(net.end() - 1, i);
	}

	return os;
}

std::istream& operator>>(std::istream& is, network& net)
{
	float edge;
	for (auto i = net.begin(); i < net.end(); ++i)
		for (auto j = net.begin(); j < net.end(); ++j)
		{
			is >> edge;
			net.link(j, i, edge);
		}

	return is;
}

#include "network.h"
#include <fstream>
#include <cmath>
#include <time.h>
#include <stdlib.h>



// network

network::network(const unsigned int s) : DGraph(s) {}

network::network(const std::string netfile)
{
	init(netfile);
	for (unsigned int i = 0; i < input_size(); ++i)
		input_map[i] = 0.0f;
}

network::network(const network& net) : DGraph(net), input_map()
{
	for (unsigned int i = 0; i < input_size(); ++i)
		input_map[i] = 0.0f;
}

void network::init(const float bound)
{
	srand(time(NULL));
	for (nodes_iterator i = begin(); i < end(); ++i)
		for (weights_iterator j = begin(i); j < end(i); ++j)
			if (edge(j, i))
				link(j, i, (rand() % 1000) * ((2.0f * bound) / 1000.0f) - bound);
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
	auto it = in.begin();
	for (nodes_iterator i = begin(); i < end(); ++i)
		if (is_input(i))
		{
			if (it < in.end())
				input_map[i] = *(it++);
			else
				input_map[i] = 0.0f;
		}
}

float network::activation_function(const float x) const
{
	return x;
}

float network::activation_derivative(const float) const
{
	return 1.0f;
}

float network::neuron(const unsigned int i) const
{
	if (i < size())
	{
		if (is_input(i))
			return input_map.find(i)->second;

		float result = 0.0f;
		for (weights_iterator j = begin(i); j < end(i); ++j)
			if (edge(j, i))
				result += edge(j, i) * neuron(j);

		return activation_function(result);
	}
	else
		return 0.0f;
}

std::vector<float> network::operator()(const std::vector<float>& in)
{
	if (!in.empty())	// if empty --> abbiamo già fatto una store()
		store(in);

	std::vector<float> result;
	if (!input_map.empty())
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



// operatori esterni di network

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

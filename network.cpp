#include <time.h>
#include <stdlib.h>
#include <vector>
#include "network.h"

network::network(const unsigned int s) : dGraph(s) {}

network::network(const network& n) : dGraph(n)
{
	outputs = n.outputs;
}

void network::add(const unsigned int n)
{
	// aggiorna la matrice di adiacenza:
	dGraph::add(n);

	// segna ogni nuovo nodo come output:
	for (unsigned int i = size() - n; i < size(); ++i)
		outputs.insert(i);
}

void network::pop_back(const unsigned int n)
{
	for (unsigned int i = size() - 1; i > size() - n - 1; ++i)
		outputs.erase(i);

	dGraph::pop_back();
}

void network::remove(const unsigned int node)
{
	// aggiorna la matrice di adiacenza:
	dGraph::remove(node);

	// ricalcola gli indici degli output:
	outputs.clear();
	for (unsigned int i = 0; i < size(); ++i)
		if (is_output(i))
			outputs.insert(i);
}

void network::init(init_t mode)
{
	if (mode == RAND)
	{
		srand(time(NULL));

		for (unsigned int i = 0; i < size(); ++i)
			for (unsigned int j = 0; j < size(); ++j)
				if (connections[i][j])
					connections[i][j] = (rand() % 100) / 10.0f;
	}
	else if (mode == ZERO)
	{
		for (unsigned int i = 0; i < size(); ++i)
			for (unsigned int j = 0; j < size(); ++j)
				if (connections[i][j])
					connections[i][j] = 0.0f;
	}
}

void network::link(const unsigned int a, const unsigned int b, const float w)
{
	dGraph::link(a, b, w);

	outputs.erase(a);
	outputs.insert(b);
}

void network::unlink(const unsigned int a, const unsigned int b)
{
	// aggiorna la matrice di adiacenza:
	link(a, b, 0.0f);

	// se il nodo a è diventato un output, aggiorna outputs:
	if (is_output(a))
		outputs.insert(a);
}

bool network::is_output(const unsigned int node) const
{
	bool out = true;

	for (unsigned int i = 0; i < node && out; ++i)
		if (connections[i][node - 1])
			out = false;

	for (unsigned int i = node + 1; i < size() && out; ++i)
		if (connections[i][node])
			out = false;

	return out;
}

bool network::is_input(const unsigned int node) const
{
	bool internal = false;
	for (unsigned int i = 0; i < size() - 1; ++i)
		internal = internal || connections[node][i];

	return !internal;
}

bool network::is_connected(const unsigned int node) const
{
	return !(is_input(node) && is_output(node));
}

unsigned int network::input_size() const
{
	unsigned int input_size = 0;
	for (unsigned int i = 0; i < size(); ++i)
		if (is_input(i))
			input_size++;

	return input_size;
}

float network::neuron(const unsigned int i) const
{
	if (is_input(i))
		return input_buffer[i];

	float result = 0.0f;
	for (unsigned int j = 0; j < i; ++j)
		if (connections[i][j])
			result += connections[i][j] * neuron(j);
	for (unsigned int j = i; j < size() - 1; ++j)
		if (connections[i][j])
			result += connections[i][j] * neuron(j + 1);
	return activation_function(result);
}

std::vector<float> network::operator()(const std::vector<float>& in)
{
	std::vector<float> result;
	// store(in);
	input_buffer = in;

	for (std::set<unsigned int>::const_iterator it = outputs.begin(); it != outputs.end(); ++it)
		result.push_back(neuron(*it));

	return result;
}
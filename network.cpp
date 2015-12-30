#include <time.h>
#include <stdlib.h>
#include <vector>
#include <cmath>		// sigmoid
#include "network.h"

Network::Network(const unsigned int s) : DGraph(s) {}

/*Network::Network(const unsigned int s) : sz(s), cpty(sz ? sz : 4), connections(cpty ? new float * [cpty] : 0)
{
	for (unsigned int i = 0; i < cpty; ++i)
		connections[i] = new float [cpty - 1];
}

Network::Network(const Network& n) : sz(n.size()), cpty(n.capacity())
{
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			connections[i][j] = n.connections[i][j];
}

Network::~Network()
{
	delete [] connections;
}

Network& Network::operator=(const Network& n)
{
	sz = n.size();
	cpty = n.capacity();
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			connections[i][j] = n.connections[i][j];

	return *this;
}

unsigned int Network::size() const
{
	return sz;
}

unsigned int Network::capacity() const
{
	return cpty;
}

bool Network::empty() const
{
	return sz == 0;
}

void Network::add(const unsigned int n)
{
	while (sz + n > cpty)
		reserve(2 * cpty);
	sz += n;

	for (unsigned int i = sz - n; i < sz; ++i)
		for (unsigned int j = 0; j < sz - 1; ++j)
			connections[i][j] = 0.0f;
}

void Network::pop_back(const unsigned int n)
{
	if (n <= sz)
		sz -= n;
}

void Network::clear()
{
	sz = 0;
	cpty = 0;
	delete [] connections;
	connections = 0;
}

void Network::reserve(const unsigned int new_capacity)
{
	if (new_capacity > cpty)
	{
		float ** newconnections = new float * [new_capacity];
		for (unsigned int i = 0; i < cpty; ++i)
			newconnections[i] = new float [cpty - 1];

		for (unsigned int i = 0; i < sz; i++)
			for (unsigned int j = 0; j < sz - 1; ++j)
				newconnections[i][j] = connections[i][j];

		cpty = new_capacity;
		delete [] connections;
		connections = newconnections;
	}
	else
	{
		for (unsigned int i = new_capacity; i < cpty; ++i)
			delete (connections + i);
		cpty = new_capacity;
	}
}

void Network::resize(const unsigned int s)
{
	reserve(s);
	sz = s;
}*/

void Network::init(init_t mode)
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

/*void Network::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a > b)
		connections[b][a - 1] = w;
	else if (a < b)
		connections[b][a] = w;

	outputs.erase(a);
	outputs.insert(b);
}*/

float Network::neuron(const unsigned int i) const
{
	bool internal = false;
	for (unsigned int j = 0; j < size() - 1; ++j)
		internal = internal || connections[i][j];
	if (!internal)
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

std::vector<float> Network::operator()(const std::vector<float>& in)
{
	std::vector<float> result;
	// store(in);
	input_buffer = in;

	for (std::set<unsigned int>::const_iterator it = outputs.begin(); it != outputs.end(); ++it)
		result.push_back(neuron(*it));

	return result;
}
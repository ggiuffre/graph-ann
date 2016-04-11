#include "internetwork.h"
#include <iostream>

using std::vector;

void internetwork::push_back(network& net)
{
	network::push_back();
	netContainer::push_back(net);
}

void internetwork::pop_back(const unsigned int n)
{
	network::pop_back(n);
	netContainer::pop_back(n);
}

void internetwork::clear()
{
	network::clear();
	netContainer::clear();
}

unsigned int internetwork::size() const
{
	return netContainer::size();
}

unsigned int internetwork::input_size() const
{
	unsigned int in_sz = 0;
	for (nodes_iterator i = begin(); i < end(); ++i)
		if (is_input(i))
			in_sz += (*this)[i].input_size();

	return in_sz;
}

network::nodes_iterator internetwork::begin() const
{
	return network::begin();
}

network::nodes_iterator internetwork::end() const
{
	return network::end();
}

network::weights_iterator internetwork::begin(const nodes_iterator n) const
{
	return network::begin(n);
}

network::weights_iterator internetwork::end(const nodes_iterator n) const
{
	return network::end(n);
}

network& internetwork::operator[](const int i) const
{
	return this->netContainer::operator[](i);
}

void internetwork::store(const vector<float>& in)
{
	if (in.size() >= input_size())		// eccezione...?
	{
		auto it = in.begin();
		for (nodes_iterator i = begin(); i < end(); ++i)
			if (is_input(i))
				(*this)[i].store({it, it += (*this)[i].input_size()});
	}
}

float internetwork::neuron(const unsigned int i) const
{
	if (i >= size())		// eccezione
		return 0.0f;

	if (is_input(i))
		return (*this)[i]()[0];

	vector<float> result;
	for (weights_iterator j = begin(i); j < end(i); ++j)
		if (edge(j, i))
			result.push_back(edge(j, i) * neuron(j));
	return (*this)[i](result)[0];
}

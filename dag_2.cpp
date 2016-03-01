#include <iostream>
#include <vector>
#include "dag_2.h"



// DAG_2::weights_iterator

DAG_2::weights_iterator::weights_iterator(const unsigned int i, const nodes_iterator n) : nodes_iterator(i), self(n) {}

DAG_2::weights_iterator& DAG_2::weights_iterator::operator++()		// prefisso
{
	std::vector<std::vector<float> >::operator++();
	if (*this == self)
		std::vector<std::vector<float> >::operator++();

	return *this;
}

DAG_2::weights_iterator DAG_2::weights_iterator::operator++(int)	// postfisso
{
	weights_iterator aux = *this;
	std::vector<std::vector<float> >::operator++();
	if (*this == self)
		std::vector<std::vector<float> >::operator++();

	return aux;
}



// DAG_2

DAG_2::DAG_2(const unsigned int s) : weights(new std::vector<std::vector<float> >(s, std::vector<float>(s, 0.0f))) {}

DAG_2::DAG_2(const DAG_2& g) : weights(g.weights) {}

DAG_2& DAG_2::operator=(const DAG_2& g)
{
	weights = g.weights;
	return *this;
}

DAG_2::nodes_iterator DAG_2::begin() const
{
	return 0;
}

DAG_2::nodes_iterator DAG_2::end() const
{
	return weights.size();
}

DAG_2::weights_iterator DAG_2::begin(const nodes_iterator n) const
{
	if (n != begin())
		return {0, n};
	else
		return {0, 1};
}

DAG_2::weights_iterator DAG_2::end(const nodes_iterator n) const
{
	return {weights.size(), n};
}

float DAG_2::edge(const unsigned int a, const unsigned int b) const
{
//	if (a >= weights.size() || b >= weights.size())				// eccezione (!)
//		throw ...

	return weights[b][a];
}

unsigned int DAG_2::size() const
{
	return weights.size();
}

bool DAG_2::empty() const
{
	return weights.empty();
}

void DAG_2::push_back(const unsigned int n)
{
	unsigned int sz = weights.size();
	for (auto i = weights.begin(); i < weights.end(); ++i)
		i->resize(sz + n, 0.0f);
	weights.resize(sz + n, std::vector<float>(sz + n, 0.0f));
}

void DAG_2::pop_back(const unsigned int n)
{
	weights.resize(weights.size() - n);
}

void DAG_2::remove(const unsigned int pos)
{
	if (pos < weights.size())
	{
		weights.erase(pos);
		for (auto i = weights.begin(); i < weights.end(); ++i)
			i->erase(pos);
	}
}

void DAG_2::clear()
{
	weights.clear();
}

void DAG_2::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a != b && a < weights.size() && b < weights.size())		// eccezione...?
		weights[b][a] = w;
}

void DAG_2::unlink(const unsigned int a, const unsigned int b)
{
	link(a, b, 0.0f);
}
#include "dgraph.h"
#include <iostream>

using std::vector;



// DGraph::nodes_iterator

DGraph::nodes_iterator::nodes_iterator(const unsigned int i) : index(i) {}

DGraph::nodes_iterator::operator unsigned int() const
{
	return index;
}

DGraph::nodes_iterator& DGraph::nodes_iterator::operator++()	// prefisso
{
	index++;
	return *this;
}

DGraph::nodes_iterator DGraph::nodes_iterator::operator++(int)	// postfisso
{
	nodes_iterator aux = *this;
	index++;
	return aux;
}



// DGraph::weights_iterator

DGraph::weights_iterator::weights_iterator(const unsigned int i, const nodes_iterator n) : nodes_iterator(i), self(n) {}

DGraph::weights_iterator& DGraph::weights_iterator::operator++()	// prefisso
{
	nodes_iterator::operator++();
	if (*this == self)
		nodes_iterator::operator++();

	return *this;
}

DGraph::weights_iterator DGraph::weights_iterator::operator++(int)	// postfisso
{
	weights_iterator aux = *this;
	nodes_iterator::operator++();
	if (*this == self)
		nodes_iterator::operator++();

	return aux;
}



// DGraph

DGraph::DGraph(const unsigned int s) : vector<vector<float> >(s, vector<float>(s, 0.0f)) {}

DGraph::~DGraph() {}

DGraph::nodes_iterator DGraph::begin() const
{
	return 0;
}

DGraph::nodes_iterator DGraph::end() const
{
	return size();
}

DGraph::weights_iterator DGraph::begin(const nodes_iterator n) const
{
	if (n != 0)
		return {0, n};
	else
		return {0, 1};
}

DGraph::weights_iterator DGraph::end(const nodes_iterator n) const
{
	return {end(), n};
}

float DGraph::edge(const unsigned int a, const unsigned int b) const
{
	if (a < size() && b < size())
		return (*this)[b][a];
	else
		return 0.0f;
}

void DGraph::push_back(const unsigned int n)
{
	unsigned int sz = size();
	for (auto i = vector<vector<float> >::begin(); i < vector<vector<float> >::end(); ++i)
		i->resize(sz + n, 0.0f);
	resize(sz + n, vector<float>(sz + n, 0.0f));
}

void DGraph::pop_back(const unsigned int n)
{
	resize(size() - n);
}

void DGraph::remove(const unsigned int pos)
{
	if (pos < size())
	{
		erase(vector<vector<float> >::begin() + pos);
		for (auto i = vector<vector<float> >::begin(); i < vector<vector<float> >::end(); ++i)
			i->erase(i->begin() + pos);
	}
}

void DGraph::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a != b && a < size() && b < size())
		(*this)[b][a] = w;
}

void DGraph::unlink(const unsigned int a, const unsigned int b)
{
	link(a, b, 0.0f);
}

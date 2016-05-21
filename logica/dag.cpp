#include "dag.h"
#include <iostream>

using std::vector;



// DAG::nodes_iterator

DAG::nodes_iterator::nodes_iterator(const unsigned int i) : index(i) {}

DAG::nodes_iterator::operator unsigned int() const
{
	return index;
}

DAG::nodes_iterator& DAG::nodes_iterator::operator++()		// prefisso
{
	index++;
	return *this;
}

DAG::nodes_iterator DAG::nodes_iterator::operator++(int)	// postfisso
{
	nodes_iterator aux = *this;
	index++;
	return aux;
}



// DAG::weights_iterator

DAG::weights_iterator::weights_iterator(const unsigned int i, const nodes_iterator n) : nodes_iterator(i), self(n) {}

DAG::weights_iterator& DAG::weights_iterator::operator++()		// prefisso
{
	nodes_iterator::operator++();
	if (*this == self)
		nodes_iterator::operator++();

	return *this;
}

DAG::weights_iterator DAG::weights_iterator::operator++(int)	// postfisso
{
	weights_iterator aux = *this;
	nodes_iterator::operator++();
	if (*this == self)
		nodes_iterator::operator++();

	return aux;
}



// DAG

DAG::DAG(const unsigned int s) : vector<vector<float> >(s, vector<float>(s, 0.0f)) {}

DAG::~DAG() {}

DAG::nodes_iterator DAG::begin() const
{
	return 0;
}

DAG::nodes_iterator DAG::end() const
{
	return size();
}

DAG::weights_iterator DAG::begin(const nodes_iterator n) const
{
	if (n != 0)
		return {0, n};
	else
		return {0, 1};
}

DAG::weights_iterator DAG::end(const nodes_iterator n) const
{
	return {end(), n};
}

float DAG::edge(const unsigned int a, const unsigned int b) const
{
//	if (a >= size() || b >= size())				// eccezione (!)
//		throw ...

	return (*this)[b][a];
}

void DAG::push_back(const unsigned int n)
{
	unsigned int sz = size();
	for (auto i = vector<vector<float> >::begin(); i < vector<vector<float> >::end(); ++i)
		i->resize(sz + n, 0.0f);
	resize(sz + n, vector<float>(sz + n, 0.0f));
}

void DAG::pop_back(const unsigned int n)
{
	resize(size() - n);
}

void DAG::remove(const unsigned int pos)
{
	if (pos < size())
	{
		erase(vector<vector<float> >::begin() + pos);
		for (auto i = vector<vector<float> >::begin(); i < vector<vector<float> >::end(); ++i)
			i->erase(i->begin() + pos);
	}
}

void DAG::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a != b && a < size() && b < size())		// eccezione...?
		(*this)[b][a] = w;
}

void DAG::unlink(const unsigned int a, const unsigned int b)
{
	link(a, b, 0.0f);
}

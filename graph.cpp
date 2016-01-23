#include "graph.h"



// graph::nodes_iterator

graph::nodes_iterator::nodes_iterator(const unsigned int i) : index(i) {}

graph::nodes_iterator::operator unsigned int() const
{
	return index;
}

graph::nodes_iterator& graph::nodes_iterator::operator++()
{
	index++;
	return *this;
}

graph::nodes_iterator graph::nodes_iterator::operator++(int)
{
	return ++(*this);
}



// graph::weights_iterator

graph::weights_iterator::weights_iterator(const unsigned int i, const nodes_iterator n) : index(i), self(n) {}

graph::weights_iterator::operator unsigned int() const
{
	return index;
}

graph::weights_iterator& graph::weights_iterator::operator++()
{
	index++;
	if (index == self)
		index++;

	return *this;
}

graph::weights_iterator graph::weights_iterator::operator++(int)
{
	return ++(*this);
}



// graph

graph::graph(const unsigned int s) : sz(s), cpty(sz ? sz : 4), weights(cpty ? new float * [cpty] : nullptr)
{
	for (unsigned int i = 0; i < cpty; ++i)
	{
		weights[i] = new float [cpty];
		for (unsigned int j = 0; j < cpty; ++j)
			weights[i][j] = 0.0f;
	}
}

graph::graph(const graph& g) : sz(g.size()), cpty(g.capacity()), weights(sz ? new float * [cpty] : nullptr)
{
	for (unsigned int i = 0; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			weights[i][j] = g.weights[i][j];
}

graph::~graph()
{
	delete [] weights;
}

graph& graph::operator=(const graph& g)
{
	resize(g.size());
	for (unsigned int i = 0; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			weights[i][j] = g.weights[i][j];

	return *this;
}

graph::nodes_iterator graph::begin() const
{
	return nodes_iterator(0);
}

graph::nodes_iterator graph::end() const
{
	return nodes_iterator(sz);
}

graph::weights_iterator graph::begin(const nodes_iterator n) const
{
	if (n != begin())
		return weights_iterator(0, n);
	else
		return weights_iterator(0, 1);
}

graph::weights_iterator graph::end(const nodes_iterator n) const
{
	return weights_iterator(sz, n);
}

float& graph::edge(const unsigned int a, const unsigned int b) const
{
//	if (a >= sz || b >= sz)				// eccezione (!)
//		throw ...

	return weights[b][a];
}

unsigned int graph::size() const
{
	return sz;
}

unsigned int graph::capacity() const
{
	return cpty;
}

bool graph::empty() const
{
	return sz == 0;
}

void graph::add(const unsigned int n)
{
	// crea nuovo spazio e aggiorna sz:
	resize(sz + n);

	// espandi le righe precedenti con connessioni nulle:
	for (unsigned int i = 0; i < sz - n; ++i)
		for (unsigned int j = sz - n; j < sz; ++j)
			weights[i][j] = 0.0f;

	// crea n nuove righe con connessioni nulle
	for (unsigned int i = sz - n; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			weights[i][j] = 0.0f;
}

void graph::pop_back(const unsigned int n)
{
	if (n <= sz)
		resize(sz - n);
}

void graph::remove(const unsigned int node)
{
	if (node < sz)
	{
		// elimina le connessioni di node con tutti:
		for (unsigned int i = node; i < sz - 1; ++i)
			for (unsigned int j = 0; j < node; ++j)
				weights[i][j] = weights[i + 1][j];

		// elimina le connessioni di tutti con node:
		for (unsigned int i = 0; i < sz; ++i)
			for (unsigned int j = node; j < sz - 1; ++j)
				weights[i][j] = weights[i][j + 1];

		resize(sz - 1);
	}
}

void graph::clear()
{
	sz = 0;
	cpty = 0;
	delete [] weights;
	weights = nullptr;
}

void graph::reserve(const unsigned int new_capacity)
{
	if (sz > new_capacity)
		sz = new_capacity;		// (?)

	float ** new_weights = new float * [new_capacity];
	for (unsigned int i = 0; i < new_capacity; ++i)
		new_weights[i] = new float [new_capacity];

	for (unsigned int i = 0; i < sz; i++)
		for (unsigned int j = 0; j < sz; ++j)
			new_weights[i][j] = weights[i][j];

	cpty = new_capacity;
	delete [] weights;
	weights = new_weights;
}

void graph::resize(const unsigned int s)
{
	if (s > cpty)
		while (s > cpty)
			reserve(2 * cpty);
	else
		while (s < cpty / 2)
			reserve(cpty / 2);

	sz = s;
}

void graph::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a < sz && b < sz)
		weights[b][a] = weights[a][b] = w;
}

void graph::unlink(const unsigned int a, const unsigned int b)
{
	link(a, b, 0.0f);
}
#include "dag.h"



// DAG::nodes_iterator

DAG::nodes_iterator::nodes_iterator(const unsigned int i) : index(i) {}

DAG::nodes_iterator::operator unsigned int() const
{
	return index;
}

DAG::nodes_iterator& DAG::nodes_iterator::operator++()
{
	index++;
	return *this;
}

DAG::nodes_iterator DAG::nodes_iterator::operator++(int)
{
	return ++(*this);
}



// DAG::weights_iterator

DAG::weights_iterator::weights_iterator(const unsigned int i, const nodes_iterator n) : index(i), self(n) {}

DAG::weights_iterator::operator unsigned int() const
{
	return index;
}

DAG::weights_iterator& DAG::weights_iterator::operator++()
{
	index++;
	if (index == self)
		index++;

	return *this;
}

DAG::weights_iterator DAG::weights_iterator::operator++(int)
{
	return ++(*this);
}



// DAG

DAG::DAG(const unsigned int s) : sz(s), cpty(sz ? sz : 4), weights(cpty ? new float * [cpty] : nullptr)
{
	for (unsigned int i = 0; i < cpty; ++i)
	{
		weights[i] = new float [cpty];
		for (unsigned int j = 0; j < cpty; ++j)
			weights[i][j] = 0.0f;
	}
}

DAG::DAG(const DAG& g) : sz(g.sz), cpty(g.cpty), weights(sz ? new float * [cpty] : nullptr)
{
	for (unsigned int i = 0; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			weights[i][j] = g.weights[i][j];
}

DAG::~DAG()
{
	delete [] weights;
}

DAG& DAG::operator=(const DAG& g)
{
	resize(g.sz);
	for (unsigned int i = 0; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			weights[i][j] = g.weights[i][j];

	return *this;
}

DAG::nodes_iterator DAG::begin() const
{
	return 0;
}

DAG::nodes_iterator DAG::end() const
{
	return sz;
}

DAG::weights_iterator DAG::begin(const nodes_iterator n) const
{
	if (n != begin())
		return weights_iterator(0, n);
	else
		return weights_iterator(0, 1);
}

DAG::weights_iterator DAG::end(const nodes_iterator n) const
{
	return weights_iterator(sz, n);
}

float DAG::edge(const unsigned int a, const unsigned int b) const
{
//	if (a >= sz || b >= sz)				// eccezione (!)
//		throw ...

	return weights[b][a];
}

unsigned int DAG::size() const
{
	return sz;
}

unsigned int DAG::capacity() const
{
	return cpty;
}

bool DAG::empty() const
{
	return sz == 0;
}

void DAG::add(const unsigned int n)
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

void DAG::pop_back(const unsigned int n)
{
	if (n <= sz)
		resize(sz - n);
}

void DAG::remove(const unsigned int node)
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

void DAG::clear()
{
	sz = 0;
	cpty = 0;
	delete [] weights;
	weights = nullptr;
}

void DAG::reserve(const unsigned int new_capacity)
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

void DAG::resize(const unsigned int s)
{
	if (s > cpty)
		while (s > cpty)
			reserve(2 * cpty);
	else
		while (s < cpty / 2)
			reserve(cpty / 2);

	sz = s;
}

void DAG::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a != b && a < sz && b < sz)		// eccezione...?
		weights[b][a] = w;
}

void DAG::unlink(const unsigned int a, const unsigned int b)
{
	link(a, b, 0.0f);
}
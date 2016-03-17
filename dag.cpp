#include <iostream>
#include "dag.h"



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

DAG::DAG(const unsigned int s) : sz(0), cpty(0), weights(cpty ? new float * [cpty] : nullptr)
{
	resize(s);

	for (unsigned int i = 0; i < cpty; ++i)
	{
		weights[i] = new float [cpty];
		for (unsigned int j = 0; j < cpty; ++j)
			weights[i][j] = 0.0f;
	}
}

DAG::DAG(const DAG& g) : sz(g.sz), cpty(g.cpty), weights(sz ? new float * [cpty] : nullptr)
{
	for (unsigned int i = 0; i < cpty; ++i)
		weights[i] = new float [cpty];

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
		return {0, n};
	else
		return {0, 1};
}

DAG::weights_iterator DAG::end(const nodes_iterator n) const
{
	return {sz, n};
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

void DAG::push_back(const unsigned int n)
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

void DAG::remove(const unsigned int pos)
{
	if (pos < sz)
	{
		// trasla in alto (elimina le connessioni del nodo in pos con tutti):
		for (unsigned int i = pos; i < sz - 1; ++i)
			for (unsigned int j = 0; j < pos; ++j)
				weights[i][j] = weights[i + 1][j];

		// trasla a sinistra (elimina le connessioni di tutti con il nodo in pos):
		for (unsigned int i = 0; i < sz; ++i)
			for (unsigned int j = pos; j < sz - 1; ++j)
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

	for (unsigned int i = 0; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			new_weights[i][j] = weights[i][j];

	cpty = new_capacity;
	delete [] weights;
	weights = new_weights;
}

void DAG::resize(const unsigned int new_size)
{
	unsigned int new_capacity = cpty ? cpty : 1;
	while (new_size < new_capacity)
		new_capacity /= 2;
	while (new_size > new_capacity)
		new_capacity *= 2;

	reserve(new_capacity);
	sz = new_size;
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

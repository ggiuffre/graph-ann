//#include <set>
#include "dgraph.h"

dGraph::dGraph(const unsigned int s) : sz(s), cpty(sz ? sz : 4), connections(cpty ? new float * [cpty] : 0)
{
	for (unsigned int i = 0; i < cpty; ++i)
		connections[i] = new float [cpty - 1];
}

dGraph::dGraph(const dGraph& n) : sz(n.size()), cpty(n.capacity())
{
	for (unsigned int i = 0; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			connections[i][j] = n.connections[i][j];
}

dGraph::~dGraph()
{
	delete [] connections;
}

dGraph& dGraph::operator=(const dGraph& n)
{
	sz = n.size();
	cpty = n.capacity();
	for (unsigned int i = 0; i < sz; ++i)
		for (unsigned int j = 0; j < sz; ++j)
			connections[i][j] = n.connections[i][j];

	return *this;
}

unsigned int dGraph::size() const
{
	return sz;
}

unsigned int dGraph::capacity() const
{
	return cpty;
}

bool dGraph::empty() const
{
	return sz == 0;
}

void dGraph::add(const unsigned int n)
{
	// crea nuovo spazio e aggiorna sz:
	resize(sz + n);

	// espandi le righe precedenti con connessioni nulle:
	for (unsigned int i = 0; i < sz - n; ++i)
		for (unsigned int j = sz - n - 1; j < sz - 1; ++j)
			connections[i][j] = 0.0f;

	// crea n nuove righe con connessioni nulle
	for (unsigned int i = sz - n; i < sz; ++i)
		for (unsigned int j = 0; j < sz - 1; ++j)
			connections[i][j] = 0.0f;

//	// segna ogni nuovo nodo come output:
//	for (unsigned int i = sz - n; i < sz; ++i)
//		outputs.insert(i);
}

void dGraph::pop_back(const unsigned int n)
{
	if (n <= sz)
		resize(sz - n);
}

void dGraph::remove(const unsigned int node)
{
	if (sz > 0)
	{
		// trasla a sinistra le connessioni dei nodi di indice minore:
		for (unsigned int i = 0; i < node; ++i)
			for (unsigned int j = node - 1; j < sz - 2; ++j)
				connections[i][j] = connections[i][j + 1];

		// porta in alto i nodi di indice maggiore, traslando le connessioni reciproche a sinistra:
		for (unsigned int i = node; i < sz - 1; ++i)
		{
			for (unsigned int j = 0; j < node; ++j)
				connections[i][j] = connections[i + 1][j];
			for (unsigned int j = node; j < sz - 2; ++j)
				connections[i][j] = connections[i + 1][j + 1];
		}

		resize(sz - 1);
	}
}

void dGraph::clear()
{
	sz = 0;
	cpty = 0;
	delete [] connections;
	connections = 0;
}

void dGraph::reserve(const unsigned int new_capacity)
{
	if (sz > new_capacity)
		sz = new_capacity;		// (?)

	float ** newconnections = new float * [new_capacity];
	for (unsigned int i = 0; i < new_capacity; ++i)
		newconnections[i] = new float [new_capacity - 1];

	for (unsigned int i = 0; i < sz; i++)
		for (unsigned int j = 0; j < sz - 1; ++j)
			newconnections[i][j] = connections[i][j];

	cpty = new_capacity;
	delete [] connections;
	connections = newconnections;
}

void dGraph::resize(const unsigned int s)
{
	if (s > cpty)
		while (s > cpty)
			reserve(2 * cpty);
	else
		while (s < cpty / 2)
			reserve(cpty / 2);

	sz = s;
}

void dGraph::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a > b)
		connections[b][a - 1] = w;
	else if (a < b)
		connections[b][a] = w;

//	outputs.erase(a);
//	outputs.insert(b);
}

void dGraph::unlink(const unsigned int a, const unsigned int b)
{
	link(a, b, 0.0f);
}
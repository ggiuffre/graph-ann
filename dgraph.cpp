#include <vector>
#include "dgraph.h"

/*DGraph::iterator& DGraph::iterator::operator++()
{
	punt++;
	return *this;
}

DGraph::iterator DGraph::iterator::operator++(int)
{
	punt++;
	return *this;
}

bool DGraph::operator==(const DGraph::iterator& x) const
{
	return punt == x.punt;
}

bool DGraph::operator!=(const DGraph::iterator& x) const
{
	return punt != x.punt;
}*/

DGraph::DGraph(const unsigned int s) : sz(s), cpty(sz ? sz : 4), connections(cpty ? new float * [cpty] : 0)
{
	for (unsigned int i = 0; i < cpty; ++i)
		connections[i] = new float [cpty - 1];
}

DGraph::DGraph(const DGraph& n) : sz(n.size()), cpty(n.capacity())
{
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			connections[i][j] = n.connections[i][j];
}

DGraph::~DGraph()
{
	delete [] connections;
}

DGraph& DGraph::operator=(const DGraph& n)
{
	sz = n.size();
	cpty = n.capacity();
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			connections[i][j] = n.connections[i][j];

	return *this;
}

unsigned int DGraph::size() const
{
	return sz;
}

unsigned int DGraph::capacity() const
{
	return cpty;
}

bool DGraph::empty() const
{
	return sz == 0;
}

void DGraph::add(const unsigned int n)
{
	while (sz + n > cpty)
		reserve(2 * cpty);
	sz += n;

	for (unsigned int i = sz - n; i < sz; ++i)
		for (unsigned int j = 0; j < sz - 1; ++j)
			connections[i][j] = 0.0f;
}

void DGraph::pop_back(const unsigned int n)
{
	if (n <= sz)
		sz -= n;
}

void DGraph::clear()
{
	sz = 0;
	cpty = 0;
	delete [] connections;
	connections = 0;
}

/*DGraph::iterator DGraph::begin() const
{
	iterator aux;
	aux.punt = 0;
	return aux;
}

DGraph::iterator DGraph::end() const
{
	iterator aux;
	aux.punt = sz;
	return aux;
}*/

void DGraph::reserve(const unsigned int new_capacity)
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

void DGraph::resize(const unsigned int s)
{
	reserve(s);
	sz = s;
}

void DGraph::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a > b)
		connections[b][a - 1] = w;
	else if (a < b)
		connections[b][a] = w;

	outputs.erase(a);
	outputs.insert(b);
}
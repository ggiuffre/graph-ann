#include "net_container.h"



// netContainer::iterator

netContainer::iterator::iterator(network ** const p) : punt(p) {}

network * netContainer::iterator::operator*() const
{
	return *punt;
}

bool netContainer::iterator::operator==(const iterator& it) const
{
	return punt == it.punt;
}

bool netContainer::iterator::operator!=(const iterator& it) const
{
	return !(*this == it);
}

bool netContainer::iterator::operator<(const iterator& it) const
{
	return punt < it.punt;
}

netContainer::iterator& netContainer::iterator::operator++()	// prefisso
{
	punt++;
	return *this;
}

netContainer::iterator netContainer::iterator::operator++(int)	// postfisso
{
	iterator aux = *this;
	punt++;
	return aux;
}



// netContainer::const_iterator

network * const netContainer::const_iterator::operator*() const
{
	return iterator::operator*();
}



// netContainer

netContainer::netContainer() : sz(0), cpty(0), nets(nullptr) {}

netContainer::~netContainer()
{
	delete [] nets;
}

netContainer::netContainer(const netContainer& nc) : sz(nc.sz), cpty(nc.cpty), nets(sz ? new network * [cpty] : nullptr)
{
	for (unsigned int i = 0; i < sz; ++i)
		nets[i] = nc.nets[i];
}

netContainer& netContainer::operator=(const netContainer& nc)
{
	resize(nc.sz);
	for (unsigned int i = 0; i < sz; ++i)
		nets[i] = nc.nets[i];

	return *this;
}

void netContainer::reserve(const unsigned int new_capacity)
{
	if (sz > new_capacity)
		sz = new_capacity;		// (?)

	network ** new_nets = new network * [new_capacity];
	for (unsigned int i = 0; i < sz; ++i)
		new_nets[i] = nets[i];

	cpty = new_capacity;
	delete [] nets;
	nets = new_nets;
}

void netContainer::resize(const unsigned int new_size)
{
	unsigned int new_capacity = cpty ? cpty : 1;
	while (new_size < new_capacity)
		new_capacity /= 2;
	while (new_size > new_capacity)
		new_capacity *= 2;

	reserve(new_capacity);
	sz = new_size;
}

void netContainer::push_back(network& net)
{
	resize(sz + 1);
	nets[sz - 1] = &net;
}

void netContainer::pop_back(const unsigned int n)
{
	if (n <= sz)
		resize(sz - n);
}

void netContainer::clear()
{
	sz = 0;
	cpty = 0;
	delete [] nets;
	nets = nullptr;
}

netContainer::iterator netContainer::begin() const
{
	return nets;
}

netContainer::iterator netContainer::end() const
{
	return nets + sz;
}

unsigned int netContainer::size() const
{
	return sz;
}
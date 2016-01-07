#include "internetwork.h"

internetwork::internetwork(const unsigned int s) : network(s)
{
	if (capacity())
		nets = new network [capacity()];
}

internetwork::~internetwork()
{
	delete [] nets;
}

void internetwork::add(const network& n)
{
	network::add();
	nets[size() - 1] = n;
}

internetwork::iterator& internetwork::iterator::operator++()
{
	punt++;
	return *this;
}

internetwork::iterator internetwork::iterator::operator++(int)
{
	punt++;
	return *this;
}

bool internetwork::iterator::operator==(const internetwork::iterator& x) const
{
	return punt == x.punt;
}

bool internetwork::iterator::operator!=(const internetwork::iterator& x) const
{
	return punt != x.punt;
}

internetwork::iterator internetwork::begin() const
{
	iterator aux;
	aux.punt = nets;
	return aux;
}

internetwork::iterator internetwork::end() const
{
	iterator aux;
	aux.punt = nets + size();
	return aux;
}
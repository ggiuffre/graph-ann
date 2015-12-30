#ifndef INTERNETWORK_H
#define INTERNETWORK_H

#include "dgraph.h"
#include "network.h"

// a network of networks...
class Internetwork : public DGraph
{
public:
//	Internetwork();
//	~Internetwork();
	void add(const Network& n);		// pushes network n into the internetwork
private:
	Network * nets;
};

#endif
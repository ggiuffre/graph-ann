#ifndef DAG_H
#define DAG_H

#include "graph.h"

class DAG : public graph
{
public:
	DAG(unsigned int s = 0);
	virtual void link(unsigned int a, unsigned int b, float w = 1.0f);
};

#endif
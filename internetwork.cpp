#include "internetwork.h"

void Internetwork::add(const Network& n)
{
	DGraph::add();
	nets[size() - 1] = n;
}
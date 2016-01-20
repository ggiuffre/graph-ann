#include "dag.h"

DAG::DAG(const unsigned int s) : graph(s) {}

void DAG::link(const unsigned int a, const unsigned int b, const float w)
{
	if (a != b && a < size() && b < size())		// eccezione (?)
		edge(a, b) = w;
}
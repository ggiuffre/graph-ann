#ifndef DGRAPH_H
#define DGRAPH_H

class dGraph
{
private:
	unsigned int sz;
	unsigned int cpty;

protected:
	float ** connections;
//	std::set<unsigned int> outputs;

public:
	dGraph(unsigned int s = 0);
	dGraph(const dGraph& n);
	~dGraph();					// virtual (?)
	dGraph& operator=(const dGraph& n);

	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	void add(unsigned int n = 1);			// pushes n neurons into the graph
	void pop_back(unsigned int n = 1);		// pops n neurons out of the graph
	void remove(unsigned int node);			// removes node n from the graph
	void clear();

	void reserve(unsigned int new_capacity);
	void resize(unsigned int s);

	void link(unsigned int a, unsigned int b, float w = 1.0f);
	void unlink(unsigned int a, unsigned int b);
};

#endif
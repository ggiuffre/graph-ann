#ifndef DGRAPH_H
#define DGRAPH_H

#include <set>

class DGraph
{
private:
	unsigned int sz;
	unsigned int cpty;

protected:
	float ** connections;
	std::set<unsigned int> outputs;

public:
	DGraph(unsigned int s = 0);
	DGraph(const DGraph& n);
	~DGraph();					// virtual (?)
	DGraph& operator=(const DGraph& n);
//	friend class iterator;

//	class iterator {			// protected (?)
//		friend class DGraph;
//	public:
//		iterator& operator++();		// prefisso
//		iterator operator++(int);	// postfisso
//		bool operator==(const iterator& x) const;
//		bool operator!=(const iterator& x) const;
//	private:
//		float * punt;
//	};

	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	void add(unsigned int n = 1);			// pushes n neurons in the graph
	void pop_back(unsigned int n = 1);		// pops n neurons out of the graph
	void clear();
//	iterator begin() const;
//	iterator end() const;

	void reserve(unsigned int new_capacity);
	void resize(unsigned int s);

	void link(unsigned int a, unsigned int b, float w = 1.0f);
};

#endif
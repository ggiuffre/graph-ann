#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>		// per ostream e istream

class graph
{
private:
	unsigned int sz;
	unsigned int cpty;
	float ** weights;

	void reserve(unsigned int new_capacity);
	void resize(unsigned int s);

public:
	graph(unsigned int s = 0);
	graph(const graph& n);
	virtual ~graph();
	graph& operator=(const graph& n);

	class nodes_iterator {
	private:
		unsigned int index;
	public:
		nodes_iterator(unsigned int i);
		operator unsigned int() const;		// tutti confronti passano per gli interi
		nodes_iterator& operator++();
		nodes_iterator operator++(int);
	};

	class weights_iterator {
	private:
		unsigned int index;
		const nodes_iterator self;
	public:
		weights_iterator(unsigned int i, nodes_iterator n);
		operator unsigned int() const;		// tutti confronti passano per gli interi
		weights_iterator& operator++();
		weights_iterator operator++(int);
	};

	nodes_iterator begin() const;
	nodes_iterator end() const;
	weights_iterator begin(nodes_iterator n) const;
	weights_iterator end(nodes_iterator n) const;
	float& edge(unsigned int a, unsigned int b) const;

	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	void add(unsigned int n = 1);			// pushes n neurons into the graph
	void pop_back(unsigned int n = 1);		// pops n neurons out of the graph
	void remove(unsigned int node);			// removes node n from the graph
	// PROBLEMA: dopo una remove(), gli indici con cui l'utente si interfaccia non sono più validi
	void clear();

	virtual void link(unsigned int a, unsigned int b, float w = 1.0f);
	void unlink(unsigned int a, unsigned int b);
};

std::ostream& operator<<(std::ostream& os, const graph& g);
std::istream& operator>>(std::istream& is, const graph& g);

#endif
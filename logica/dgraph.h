#ifndef DGRAPH_H
#define DGRAPH_H

#include <vector>

class DGraph : public std::vector<std::vector<float> >
{
protected:
	void remove(unsigned int pos);			// rimuovi il nodo in pos
	// PROBLEMA: dopo una remove(), gli indici con cui l'utente si interfaccia non sono più validi

public:
	explicit DGraph(unsigned int s = 0);	// un int non definisce univocamente un DGraph
	virtual ~DGraph();

	class nodes_iterator {
	private:
		unsigned int index;
	public:
		nodes_iterator(unsigned int i);
		operator unsigned int() const;		// i confronti passano per gli interi
		nodes_iterator& operator++();
		nodes_iterator operator++(int);
	};

	class weights_iterator : public nodes_iterator {
	private:
		const nodes_iterator self;
	public:
		weights_iterator(unsigned int i, nodes_iterator n);
		weights_iterator& operator++();
		weights_iterator operator++(int);
	};

	nodes_iterator begin() const;
	nodes_iterator end() const;
	weights_iterator begin(nodes_iterator n) const;
	weights_iterator end(nodes_iterator n) const;
	float edge(unsigned int a, unsigned int b) const;

	void push_back(unsigned int n = 1);		// inserisci n nodi in testa
	void pop_back(unsigned int n = 1);		// rimuovi gli ultimi n nodi immessi
//	void insert(unsigned int pos);			// inserisci un nodo in pos

	void link(unsigned int a, unsigned int b, float w = 1.0f);
	void unlink(unsigned int a, unsigned int b);
};

#endif

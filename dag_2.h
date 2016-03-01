#ifndef DAG_2_H
#define DAG_2_H

#include <vector>

class DAG_2
{
private:
	std::vector<std::vector<float> > weights;

protected:
	void remove(unsigned int pos);			// rimuovi il nodo in pos
	// PROBLEMA: dopo una remove(), gli indici con cui l'utente si interfaccia non sono più validi

public:
	explicit DAG_2(unsigned int s = 0);		// un int non caratterizza univocamente un dag_2
	DAG_2(const DAG_2& g);
	virtual ~DAG_2() = default;
	DAG_2& operator=(const DAG_2& g);

	class nodes_iterator : public std::vector<std::vector<float> >::iterator {};

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

	unsigned int size() const;
	bool empty() const;
	void push_back(unsigned int n = 1);			// inserisci n nodi in testa
	void pop_back(unsigned int n = 1);		// rimuovi gli ultimi n nodi immessi
//	void insert(unsigned int pos);			// inserisci un nodo in pos
	void clear();

	void link(unsigned int a, unsigned int b, float w = 1.0f);
	void unlink(unsigned int a, unsigned int b);
};

#endif
#ifndef DAG_H
#define DAG_H

class DAG
{
private:
	unsigned int sz;
	unsigned int cpty;
	float ** weights;

	void reserve(unsigned int new_capacity);
	void resize(unsigned int new_size);

protected:
	void remove(unsigned int pos);			// rimuovi il nodo in pos
	// PROBLEMA: dopo una remove(), gli indici con cui l'utente si interfaccia non sono più validi

public:
	explicit DAG(unsigned int s = 0);		// un int non caratterizza univocamente un dag
	DAG(const DAG& g);
	virtual ~DAG();
	DAG& operator=(const DAG& g);

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
	float edge(unsigned int a, unsigned int b) const;

	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	void push_back(unsigned int n = 1);			// inserisci n nodi in testa
	void pop_back(unsigned int n = 1);		// rimuovi gli ultimi n nodi immessi
//	void insert(unsigned int pos);			// inserisci un nodo in pos
	void clear();

	void link(unsigned int a, unsigned int b, float w = 1.0f);
	void unlink(unsigned int a, unsigned int b);
};

#endif
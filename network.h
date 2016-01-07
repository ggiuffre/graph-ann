#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <set>
#include "dgraph.h"

class network : public dGraph
{
private:
	std::set<unsigned int> outputs;
	std::vector<float> input_buffer;
	void store(const std::vector<float>& in);
	float interpret(float x) const { return x; }		// id (default)

	float neuron(unsigned int index) const;
	virtual float activation_function(float x) const { return x; }	// id (default)
	// N.B. : il virtual è necessario, sennò le sottoclassi usano sempre e solo l'identità qui definita.

protected:
	bool is_output(unsigned int node) const;
	bool is_input(unsigned int node) const;
	bool is_connected(unsigned int node) const;

public:
	network(unsigned int s = 0);
	network(const network& n);

	// PROBLEMA: dopo una remove(), gli indici con cui l'utente si interfaccia non sono più validi!

	enum init_t { ZERO, RAND };
	void init(init_t mode = RAND);
	unsigned int input_size() const;
	void add(unsigned int n = 1);
	void pop_back(unsigned int n = 1);
	void remove(unsigned int node);
	void link(unsigned int a, unsigned int b, float w = 1.0f);
	void unlink(unsigned int a, unsigned int b);

	std::vector<float> operator()(const std::vector<float>& in);
};

#endif
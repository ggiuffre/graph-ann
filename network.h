#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "dgraph.h"

class Network : public DGraph
{
public:
	Network(unsigned int s = 0);
	enum init_t { ZERO, RAND };
	void init(init_t mode = RAND);
	std::vector<float> operator()(const std::vector<float>& in);

private:
	std::vector<float> input_buffer;
	void store(const std::vector<float>& in);
	float interpret(float x) const { return x; } // id (default)

	float neuron(unsigned int index) const;
	virtual float activation_function(float x) const { return x; } // id (default)
	// oppure la funzione SIGN() come deafult ??
	// N.B. : il virtual è necessario, sennò le sottoclassi usano sempre e solo l'identità qui definita.
};





#endif
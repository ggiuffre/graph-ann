#ifndef INTERNETWORK_H
#define INTERNETWORK_H

#include "network.h"
#include "net_container.h"
#include <map>
#include <vector>

class internetwork : public network, public netContainer
{
protected:
	virtual float neuron(unsigned int index) const;

public:
	void push_back(network& n);		// inserisce la rete n in testa all'interrete
	void pop_back(unsigned int n = 1);		// rimuovi gli ultimi n nodi immessi
	void clear();
	virtual void store(const std::vector<float>& in);

	unsigned int size() const;
	virtual unsigned int input_size() const /*override*/;
	nodes_iterator begin() const;
	nodes_iterator end() const;
	weights_iterator begin(nodes_iterator n) const;
	weights_iterator end(nodes_iterator n) const;
	network& operator[](int i) const;
};

#endif

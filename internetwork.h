#ifndef INTERNETWORK_H
#define INTERNETWORK_H

#include "network.h"

class internetwork : public network
{
private:
	network ** nets;		// a network of networks
	unsigned int nets_sz;

public:
	internetwork();
	virtual ~internetwork() override;
	internetwork(const internetwork& net);
	internetwork& operator=(const internetwork& net);

	void adapt();
	void add(network& n);		// inserisce la rete n in testa all'interrete
	void pop_back(unsigned int n = 1);		// rimuovi gli ultimi n nodi immessi
	void clear();

	void link(unsigned int a, unsigned int b);
	void unlink(unsigned int a, unsigned int b);

	network& operator[](unsigned int i) const;
	std::vector<float> operator()(const std::vector<float>& in);
};

#endif
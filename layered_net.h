#ifndef LAYERED_NET_H
#define LAYERED_NET_H

#include "network.h"

class layeredNet : virtual public network
{
private:
	class layer {
	public:
		unsigned int begin;
		unsigned int size;
		layer(unsigned int b = 0, unsigned int s = 0);
	};
	const bool is_biased;
	unsigned int n_layers;
	layer * layers;
	void reserveLayer(unsigned int n = 0);

//	float * hid_outputs;
//	float * out_outputs;

public:
	layeredNet(bool b = false, unsigned int n_l = 0);
	layeredNet(const layeredNet& net);
	~layeredNet();

	void addLayer(unsigned int n_nodes);
	void linkLayer(unsigned int l);
	void removeLayer(unsigned int l);
};

#endif
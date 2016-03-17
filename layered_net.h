#ifndef LAYERED_NET_H
#define LAYERED_NET_H

#include <vector>
#include <string>
#include "network.h"

class layeredNet : virtual public network
{
private:
	class layer {
	private:
		unsigned int st;
		unsigned int sz;
	public:
		unsigned int start() const;
		unsigned int size() const;
		explicit layer(unsigned int a = 0, unsigned int b = 0);
	};

	unsigned int n_lays;
	layer * layers;

	void reserveLayer(unsigned int start, unsigned int n_nodes);

public:
	layeredNet();
	layeredNet(const layeredNet& net);
	layeredNet(std::string netfile);
	virtual ~layeredNet() override;
	layeredNet& operator=(const layeredNet& net);

	class layers_iterator {
	private:
		unsigned int index;
	public:
		layers_iterator(unsigned int i);
		layers_iterator(const layers_iterator& l);
		operator unsigned int() const;		// tutti i confronti passano per gli interi
		layers_iterator& operator++();
		layers_iterator operator++(int);
		layers_iterator& operator--();
		layers_iterator operator--(int);
	};

	layers_iterator begin() const;
	layers_iterator end() const;
	nodes_iterator begin(layers_iterator l) const;
	nodes_iterator end(layers_iterator l) const;
	virtual unsigned int input_size() const override;		// virtual, per internetwork!
	unsigned int n_layers() const;

	void init(init_t mode = RAND, float bound = 0.5f);
	void init(std::string netfile);
	void save(std::string netfile = "untitled.net") const;

	virtual void addLayer(unsigned int n_nodes);
	virtual void linkLayer(unsigned int l);
	void removeLayer(unsigned int l);
};

#endif

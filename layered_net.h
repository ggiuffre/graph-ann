#ifndef LAYERED_NET_H
#define LAYERED_NET_H

#include <vector>
#include "network.h"



class unit		// nested ?
{
public:
	float out;
	float delta;
	unit();
};



class layeredNet : virtual public network
{
//	friend class layer;
private:
	class layer {
	public:
		unsigned int start;
		unsigned int size;
		layer(unsigned int st = 0, unsigned int si = 0);
	};

	const bool is_biased;
	const float bias_value;
	unsigned int n_layers;
	layer * layers;

	void reserveLayer(unsigned int n = 0);

protected:
	void store(const std::vector<float>& in);

public:
	layeredNet(bool b = false, float bv = 1.0f);
	layeredNet(const layeredNet& net);
	virtual ~layeredNet();
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

	layers_iterator l_begin() const;
	layers_iterator l_end() const;
	nodes_iterator begin(layers_iterator l) const;
	nodes_iterator end(layers_iterator l) const;
	unsigned int input_size() const;				// (virtual?)
	bool is_bias(unsigned int n) const;

	void init(init_t mode = RAND, float bound = 0.5f);		// virtual ????
	void addLayer(unsigned int n_nodes);
	void linkLayer(unsigned int l);
	void removeLayer(unsigned int l);

//	std::vector<float> operator()(const std::vector<float>& in);
	void incremental_training(unsigned int n_examples, float ** examples, float ** target, float learning_rate, float momentum, float desired_err);
};

#endif
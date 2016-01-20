#include <iostream>
#include "layered_net.h"



// unit

unit::unit() : out(0.0f), delta(0.0f) {}



// layeredNet::layer

layeredNet::layer::layer(const unsigned int st, const unsigned int si) : start(st), size(si) {}



// layeredNet::layers_iterator

layeredNet::layers_iterator::layers_iterator(const unsigned int i) : index(i) {}

layeredNet::layers_iterator::layers_iterator(const layeredNet::layers_iterator& l) : index(l.index) {}

layeredNet::layers_iterator::operator unsigned int() const
{
	return index;
}

layeredNet::layers_iterator& layeredNet::layers_iterator::operator++()
{
	index++;
	return *this;
}

layeredNet::layers_iterator layeredNet::layers_iterator::operator++(int)
{
	return ++(*this);
}

layeredNet::layers_iterator& layeredNet::layers_iterator::operator--()
{
	index--;
	return *this;
}

layeredNet::layers_iterator layeredNet::layers_iterator::operator--(int)
{
	return --(*this);
}



// layeredNet

layeredNet::layeredNet(const bool b, const float bv) : network(), n_layers(0), layers(nullptr), is_biased(b), bias_value(bv) {}

layeredNet::layeredNet(const layeredNet& net) : network(net), is_biased(net.is_biased), bias_value(net.bias_value), n_layers(net.n_layers)
{
	for (unsigned int i = 0; i < n_layers; ++i)
		layers[i] = net.layers[i];
}

layeredNet::~layeredNet()
{
	delete [] layers;
}

layeredNet& layeredNet::operator=(const layeredNet& net)
{
	layeredNet::operator=(net);

	return *this;
}

void layeredNet::reserveLayer(const unsigned int n_nodes)
{
	n_layers++;
	layer * aux = new layer [n_layers];

	for (layers_iterator l = l_begin(); l != l_end() - 1; ++l)
		aux[l] = layers[l];

	aux[l_end() - 1] = layer(size() - n_nodes, n_nodes);

	delete [] layers;
	layers = aux;
}

layeredNet::layers_iterator layeredNet::l_begin() const
{
	return 0;
}

layeredNet::layers_iterator layeredNet::l_end() const
{
	return n_layers;
}

graph::nodes_iterator layeredNet::begin(const layeredNet::layers_iterator l) const
{
	return layers[l].start;
}

graph::nodes_iterator layeredNet::end(const layeredNet::layers_iterator l) const
{
	return begin(l) + layers[l].size;
}

unsigned int layeredNet::input_size() const
{
	return is_biased ? layers[0].size - 1 : layers[0].size;
}

bool layeredNet::is_bias(unsigned int n) const
{
	if (is_biased)
	{
		for (layers_iterator l = l_begin(); l != l_end(); ++l)
			if (n == begin(l))
				return true;
	}

	return false;
}

void layeredNet::init(const init_t mode, const float bound)
{
	network::init(mode, bound);

	// eguaglia i pesi dei bias:
	for (layers_iterator l = l_begin(); l != l_end() - 1; ++l)
		for (nodes_iterator i = begin(l + 1) + 1; i != end(l + 1); ++i)
			edge(begin(l), i) = edge(begin(l), begin(l + 1) + 1);
}

void layeredNet::addLayer(const unsigned int n_nodes)
{
	if (!is_biased)
	{
		add(n_nodes);
		reserveLayer(n_nodes);
	}
	else
	{
		add(n_nodes + 1);
		reserveLayer(n_nodes + 1);
	}

	if (n_layers > 1)
		linkLayer(n_layers - 1);
}

void layeredNet::linkLayer(const unsigned int l)
{
	if (l > 0 && l < n_layers)
	{
		if (!is_biased)
			for (nodes_iterator i = begin(l); i != end(l); ++i)
				for (nodes_iterator j = begin(l - 1); j != end(l - 1); ++j)
					link(j, i);
		else
			for (nodes_iterator i = begin(l) + 1; i != end(l); ++i)
				for (nodes_iterator j = begin(l - 1); j != end(l - 1); ++j)
					link(j, i);
	}
}

void layeredNet::removeLayer(const unsigned int lay)
{
	if (lay < n_layers)
	{
		for (nodes_iterator i = begin(lay); i != end(lay); ++i)
			remove(i);

		for (layers_iterator l = lay; l != l_end() - 1; ++l)
			layers[l] = layers[l + 1];

		n_layers--;

		// "riempi il vuoto", collegando il vecchio strato lay+1, ora diventato lay:
		linkLayer(lay);
	}
}

void layeredNet::store(const std::vector<float>& in)
{
	if (is_biased)
	{
		unsigned int t = 0;
		std::vector<float> aux;
		for (nodes_iterator i = begin(l_begin()); i < end(l_end() - 1); ++i)
		{
			if (is_bias(i))
				aux.push_back(bias_value);
			else if (is_input(i))
				aux.push_back(in[t++]);
		}

		network::store(aux);
	}
	else
		network::store(in);
}
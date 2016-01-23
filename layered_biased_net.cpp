#include <string>
#include "layered_biased_net.h"

layeredBiasedNet::layeredBiasedNet(const float bv) : bias_value(bv) {}

layeredBiasedNet::layeredBiasedNet(const std::string netfile, const float bv) : layeredNet(netfile), bias_value(bv) {}

unsigned int layeredBiasedNet::input_size() const
{
	return layeredNet::input_size() - 1;
}

unsigned int layeredBiasedNet::output_size() const
{
	unsigned int n_biases = 0;
	for (nodes_iterator i = begin(l_end() - 1); i < end(l_end() - 1); ++i)
		n_biases += is_bias(i);

	return layeredNet::output_size() - n_biases;
}

bool layeredBiasedNet::is_bias(unsigned int n) const
{
	for (layers_iterator l = l_begin(); l != l_end(); ++l)
		if (n == begin(l))
			return true;

	return false;
}

void layeredBiasedNet::init(const init_t mode, const float bound)
{
	layeredNet::init(mode, bound);

	// eguaglia i pesi dei bias:
	for (layers_iterator l = l_begin(); l != l_end() - 1; ++l)
		for (nodes_iterator i = begin(l + 1) + 1; i < end(l + 1); ++i)
			edge(begin(l), i) = edge(begin(l), begin(l + 1) + 1);
}

void layeredBiasedNet::init(const std::string netfile)
{
	layeredNet::init(netfile);
}

void layeredBiasedNet::addLayer(const unsigned int n_nodes)
{
	layeredNet::addLayer(n_nodes + 1);
}

void layeredBiasedNet::linkLayer(const unsigned int l)
{
	if (l > 0 && l < n_layers())
		for (nodes_iterator i = begin(l) + 1; i < end(l); ++i)
			for (nodes_iterator j = begin(l - 1); j < end(l - 1); ++j)
				link(j, i);
}

void layeredBiasedNet::store(const std::vector<float>& in)
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

	layeredNet::store(aux);
}
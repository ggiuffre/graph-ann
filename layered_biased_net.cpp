#include "layered_biased_net.h"
#include <iostream>

const float layeredBiasedNet::bias_value = 1.0f;

layeredBiasedNet::layeredBiasedNet(const float lr, const float mc, const bool bp) : learning_rate(lr), momentum_coeff(mc), bias_plasticity(bp) {}

layeredBiasedNet::layeredBiasedNet(const std::string netfile, const float lr, const float mc, const bool bp) : layeredNet(netfile), learning_rate(lr), momentum_coeff(mc), bias_plasticity(bp) {}

layeredBiasedNet& layeredBiasedNet::operator=(const layeredBiasedNet& net)
{
	layeredNet::operator=(net);
	learning_rate = net.learning_rate;
	momentum_coeff = net.momentum_coeff;
	// bias_plasticity rimane com'era... bisogna forse NON permettere l'operatore di uguaglianza? <<<<<<<<<<<<<<<
	return *this;
}

bool layeredBiasedNet::is_bias(unsigned int n) const
{
	for (layers_iterator l = begin(); l < end(); ++l)
		if (n == begin(l))
			return true;

	return false;
}

unsigned int layeredBiasedNet::input_size() const
{
	if (n_layers())
		return layeredNet::input_size() - 1;

	return 0;
}

float layeredBiasedNet::learningRate() const
{
	return learning_rate;
}

float layeredBiasedNet::momentum() const
{
	return momentum_coeff;
}

void layeredBiasedNet::init(const init_t mode, const float bound)
{
	layeredNet::init(mode, bound);

	// eguaglia i pesi dei bias:
	if (n_layers() > 1)
	{
		float first_bias_conn = edge(begin(begin()), begin(begin() + 1) + 1);
		for (layers_iterator l = begin() + 1; l < end(); ++l)
			for (nodes_iterator i = begin(l) + 1; i < end(l); ++i)
				link(begin(l - 1), i, first_bias_conn);
	}
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
	layeredNet::linkLayer(l);

	// scollega le connessioni verso il bias:
	if (l > begin() && l < end())
		for (nodes_iterator j = begin(l - 1); j < end(l - 1); ++j)
				unlink(j, begin(l));
}

void layeredBiasedNet::store(const std::vector<float>& in)
{
	std::vector<float> aux = in;
	aux.insert(aux.begin(), bias_value);
	for (layers_iterator l = begin() + 1; l < end(); ++l)
		aux.push_back(bias_value);

	layeredNet::store(aux);
}

std::vector<float> layeredBiasedNet::operator()(const std::vector<float>& in)
{
	std::vector<float> aux = layeredNet::operator()(in);
	return {aux.begin() + 1, aux.end()};		// togli il bias
}

#include "layered_net.h"

layeredNet::layer::layer(const unsigned int b, const unsigned int s) : begin(b), size(s) {}

layeredNet::layeredNet(const bool b, const unsigned int n_l) : network(), n_layers(0), layers(0), is_biased(b) {}

layeredNet::layeredNet(const layeredNet& net) : network(net), is_biased(net.is_biased), n_layers(net.n_layers)
{
	for (unsigned int i = 0; i < n_layers; ++i)
	{
		layers[i] = net.layers[i];
//		hid_units += layers[i].size;
	}
//	hid_units -= layers[n_layers - 1].size;
//
//	for (unsigned int i = 0; i < hid_units; ++i)
//		hid_outputs[i] = net.hid_outputs[i];
//
//	for (unsigned int i = 0; i < N[n_layers - 1]; ++i)
//		out_outputs[i] = net.out_outputs[i];
}

layeredNet::~layeredNet()
{
	delete [] layers;
//	delete [] hid_outputs;
//	delete [] out_outputs;
}

void layeredNet::reserveLayer(const unsigned int n_nodes)
{
	n_layers++;
	layer * aux = new layer [n_layers];

	for (unsigned int i = 0; i < n_layers - 1; ++i)
		aux[i] = layers[i];

	aux[n_layers - 1].size = n_nodes;
	aux[n_layers - 1].begin = size() - n_nodes;
	delete [] layers;
	layers = aux;
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
	if (!is_biased)
		for (unsigned int i = layers[l].begin; i < layers[l].begin + layers[l].size; ++i)
			for (unsigned int j = layers[l - 1].begin; j < layers[l - 1].begin + layers[l - 1].size; ++j)
				link(j, i);
	else
		for (unsigned int i = layers[l].begin + 1; i < layers[l].begin + layers[l].size; ++i)
			for (unsigned int j = layers[l - 1].begin; j < layers[l - 1].begin + layers[l - 1].size; ++j)
				link(j, i);
}

void layeredNet::removeLayer(const unsigned int l)
{
	for (unsigned int i = layers[l].begin; i < layers[l].begin + layers[l].size; ++i)
		remove(i);

	for (unsigned int i = l; i < n_layers - 1; ++i)
		layers[l] = layers[l + 1];

	n_layers--;

	// "riempi il vuoto", collegando il vecchio strato l+1, ora diventato l:
	linkLayer(l);
}
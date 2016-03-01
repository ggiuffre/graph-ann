#include <iostream>
#include <fstream>
#include "layered_net.h"



// layeredNet::layer

layeredNet::layer::layer(const unsigned int a, const unsigned int b) : st(a), sz(b) {}

unsigned int layeredNet::layer::start() const
{
	return st;
}

unsigned int layeredNet::layer::size() const
{
	return sz;
}



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
	layers_iterator aux = *this;
	index++;
	return aux;
}

layeredNet::layers_iterator& layeredNet::layers_iterator::operator--()
{
	index--;
	return *this;
}

layeredNet::layers_iterator layeredNet::layers_iterator::operator--(int)
{
	layers_iterator aux = *this;
	index--;
	return aux;
}



// layeredNet

layeredNet::layeredNet() : n_lays(0), layers(nullptr) {}

layeredNet::layeredNet(const layeredNet& net) : network(net), n_lays(net.n_lays)
{
	layers = new layer [n_lays];
	for (unsigned int i = 0; i < n_lays; ++i)
		layers[i] = net.layers[i];
}

layeredNet::layeredNet(const std::string netfile) : n_lays(0), layers(nullptr)
{
	init(netfile);
}

layeredNet::~layeredNet()
{
	delete [] layers;
}

layeredNet& layeredNet::operator=(const layeredNet& net)
{
	return layeredNet::operator=(net);
}

void layeredNet::reserveLayer(const unsigned int start, const unsigned int n_nodes)
{
	++n_lays;
	layer * aux = new layer [n_lays];

	for (layers_iterator l = begin(); l != end() - 1; ++l)
		aux[l] = layers[l];

	aux[end() - 1] = layer(start, n_nodes);

	delete [] layers;
	layers = aux;
}

layeredNet::layers_iterator layeredNet::begin() const
{
	return 0;
}

layeredNet::layers_iterator layeredNet::end() const
{
	return n_lays;
}

DAG::nodes_iterator layeredNet::begin(const layeredNet::layers_iterator l) const
{
	if (l < n_lays)
		return layers[l].start();

	return end(end());
}

DAG::nodes_iterator layeredNet::end(const layeredNet::layers_iterator l) const
{
	if (l < n_lays)
		return begin(l) + layers[l].size();

	return end(end());
}

unsigned int layeredNet::input_size() const
{
	if (layers)
		return layers[0].size();

	return 0;
}

unsigned int layeredNet::n_layers() const
{
	return n_lays;
}

void layeredNet::init(const init_t mode, const float bound)
{
	network::init(mode, bound);
}

void layeredNet::init(const std::string netfile)
{
	network::init(netfile);

	std::ifstream fin(netfile);

	float idle;
	for (unsigned int i = 0; i < size() * size() + 1; ++i)
		fin >> idle;

	unsigned int tmp_n_layers = 0;
	fin >> tmp_n_layers;
	for (unsigned int i = 0; i < tmp_n_layers; ++i)
	{
		unsigned int layer_start, n_nodes;
		fin >> layer_start >> n_nodes;
		reserveLayer(layer_start, n_nodes);
	}

	fin.close();
}

void layeredNet::save(const std::string netfile) const
{
	network::save(netfile);

	std::ofstream fout(netfile, std::ios::app);
	fout << std::endl << std::endl << n_lays << std::endl;
	for (layers_iterator l = begin(); l < end(); ++l)
		fout << std::endl << layers[l].start() << ' ' << layers[l].size() << ' ';
}

void layeredNet::addLayer(const unsigned int n_nodes)
{
	push_back(n_nodes);
	reserveLayer(size() - n_nodes, n_nodes);

	if (n_lays > 1)
		linkLayer(n_lays - 1);
}

void layeredNet::linkLayer(const unsigned int l)
{
	if (l > 0 && l < n_lays)
		for (nodes_iterator i = begin(l); i < end(l); ++i)
			for (nodes_iterator j = begin(l - 1); j < end(l - 1); ++j)
				link(j, i);
}

void layeredNet::removeLayer(const unsigned int lay)
{
	if (lay < n_lays)
	{
		for (nodes_iterator i = begin(lay); i < end(lay); ++i)
			remove(i);

		for (layers_iterator l = lay; l != end() - 1; ++l)
			layers[l] = layers[l + 1];

		--n_lays;

		// "riempi il vuoto", collegando il vecchio strato lay+1, ora diventato lay:
		linkLayer(lay);
	}
}
#include "internetwork.h"

internetwork::internetwork() : nets(capacity() ? new network * [capacity()] : nullptr) {}

internetwork::~internetwork()
{
	delete [] nets;
}

internetwork::internetwork(const internetwork& net) : network(net)
{
	adapt();
	for (unsigned int i = 0; i < size(); ++i)
		nets[i] = net.nets[i];
}

internetwork& internetwork::operator=(const internetwork& net)
{
	network::operator=(net);

	adapt();
	for (unsigned int i = 0; i < net.size(); ++i)
		nets[i] = net.nets[i];

	return *this;
}

void internetwork::adapt()
{
	network ** aux = new network * [capacity()];
	for (unsigned int i = 0; i < nets_sz; ++i)
		aux[i] = nets[i];

	delete [] nets;
	nets = aux;
	nets_sz = size();
}

void internetwork::add(network& net)
{
	network::add();
	adapt();
	nets[nets_sz - 1] = &net;
}

void internetwork::pop_back(const unsigned int n)
{
	network::pop_back(n);
	adapt();
}

void internetwork::clear()
{
	network::clear();
	delete [] nets;
	nets = nullptr;
}

void internetwork::link(const unsigned int a, const unsigned int b)
{
	// ometto il controllo sulla corerenza dei bias
	if (a != b && a < size() && b < size() && nets[a]->output_size() == nets[b]->input_size())
		network::link(a, b);
}

void internetwork::unlink(const unsigned int a, const unsigned int b)
{
	network::link(a, b, 0.0f);
}

network& internetwork::operator[](const unsigned int i) const
{
	return *nets[i];
}

std::vector<float> internetwork::neuron(const unsigned int i) const
{
	if (i >= size())		// eccezione
		return 0.0f;

	if (is_input(i))
		return input_map.find(i)->second;

	float result = 0.0f;
	for (weights_iterator j = begin(i); j < end(i); ++j)
		if (edge(j, i))
			result += neuron(j);

	return result;
}

std::vector<float> internetwork::operator()(const std::vector<float>& in)
{
	network::store(in);

	std::vector<float> result;
	for (nodes_iterator i = begin(); i < end(); ++i)
		if (is_output(i))
			for (unsigned int j = 0; j < nets[j]->output_size(); ++j)
				result.push_back(neuron(i)[j]);

	return result;
}
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <map>
#include "dag.h"

class network : public DAG
{
private:
	std::map<unsigned int, float> input_map;
	virtual float activation_function(float x) const;

protected:
	float neuron(unsigned int index) const;
	virtual void store(const std::vector<float>& in);

public:
	network(unsigned int s = 0);
	network(const network& net);
	network& operator=(const network& net);

	enum init_t { ZERO, RAND };
	void init(init_t mode = RAND, float bound = 0.5f);

	bool is_output(unsigned int node) const;
	bool is_input(unsigned int node) const;
	bool is_connected(unsigned int node) const;
	unsigned int input_size() const;

	std::vector<float> operator()(const std::vector<float>& in);
};

#endif
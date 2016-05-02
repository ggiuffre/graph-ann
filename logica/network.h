#ifndef NETWORK_H
#define NETWORK_H

#include "dag.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

class network : public DAG
{
private:
	virtual float activation_function(float x) const;
	std::map<unsigned int, float> input_map;			// private?

protected:
	virtual float activation_derivative(float y) const;
	virtual float neuron(unsigned int index) const;		// private? (train.cpp la usa...)

public:
	virtual void store(const std::vector<float>& in);
	explicit network(unsigned int s = 0);
	network(std::string netfile);
	network(const network& net);

	void init(float bound = 0.5f);
	void init(std::string netfile);
	void save(std::string netfile = "untitled.net") const;

	bool is_input(unsigned int node) const;
	bool is_output(unsigned int node) const;
	virtual unsigned int input_size() const;
	virtual unsigned int output_size() const;

	virtual std::vector<float> operator()(const std::vector<float>& in = std::vector<float>());
};

std::ostream& operator<<(std::ostream& os, const network& net);
std::istream& operator>>(std::istream& is, network& net);

#endif

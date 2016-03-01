#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "dag.h"

class network : public DAG
{
private:
	std::map<unsigned int, float> input_map;
	virtual float activation_function(float x) const;

protected:
	virtual float activation_derivative(float y) const;
	float neuron(unsigned int index) const;		// private? (train.cpp la usa...)
	virtual void store(const std::vector<float>& in);

public:
	explicit network(unsigned int s = 0);
	network(std::string netfile);
	network(const network& net);

	enum init_t { ZERO, RAND };
	void init(init_t mode = RAND, float bound = 0.5f);
	void init(std::string netfile);
	void save(std::string netfile = "untitled.net") const;
	void random_pretraining(std::string datafile, unsigned int epochs = 200);	// da togliere prima della consegna...

	bool is_input(unsigned int node) const;
	bool is_output(unsigned int node) const;
	virtual unsigned int input_size() const;
	virtual unsigned int output_size() const;

	std::vector<float> operator()(const std::vector<float>& in);
};

std::ostream& operator<<(std::ostream& os, const network& net);
std::istream& operator>>(std::istream& is, network& net);

#endif
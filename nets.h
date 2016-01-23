#ifndef NETS_H
#define NETS_H

#include <string>
#include "network.h"
#include "layered_biased_net.h"



// Sigmoid-activated network:

class sigmoidNet : virtual public network
{
private:
	virtual float activation_function(float x) const;

public:
	sigmoidNet(unsigned int s = 0);
};



// Perceptron:

class perceptron : virtual public network
{
private:
	const float verum;
	const float falsum;
	virtual float activation_function(float x) const;

public:
	perceptron(float v = 1.0f, float f = 0.0f, unsigned int s = 0);
};



// Sigmoid-activated layered network:

class layeredSigmoidNet : public layeredBiasedNet, public sigmoidNet
{
public:
	layeredSigmoidNet(float b = 1.0f);
	layeredSigmoidNet(std::string netfile, float b = 1.0f);

	void incremental_training(unsigned int n_examples, float ** examples, float ** target, float learning_rate, float momentum, float desired_err);
	void incremental_training(std::string data_file, float learning_rate, float momentum, float desired_err);
};



// Layered perceptron:

class layeredPerceptron : public layeredBiasedNet, public perceptron
{
public:
	layeredPerceptron();
};

#endif
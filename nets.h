#ifndef NETS_H
#define NETS_H

#include "network.h"
#include "layered_net.h"



// Sigmoid-activated network:

class sigmoidNet : virtual public network
{
private:
	virtual float activation_function(float x) const;
};



// Perceptron:

class perceptron : virtual public network
{
public:
	perceptron(float v = 1.0f, float f = 0.0f, unsigned int s = 0);
private:
	const float verum;
	const float falsum;
	virtual float activation_function(float x) const;
};



// Sigmoid-activated layered network:

class layeredSigmoidNet : public layeredNet, public sigmoidNet
{
public:
	layeredSigmoidNet(bool b = false, unsigned int n_l = 0);
};



// Layered perceptron:

class layeredPerceptron : public layeredNet, public perceptron
{
public:
	layeredPerceptron(unsigned int n_l = 0);
};

#endif
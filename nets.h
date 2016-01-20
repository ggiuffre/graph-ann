#ifndef NETS_H
#define NETS_H

#include "network.h"
#include "layered_net.h"



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

class layeredSigmoidNet : public layeredNet, public sigmoidNet
{
public:
	layeredSigmoidNet(bool b = false);
};



// Layered perceptron:

class layeredPerceptron : public layeredNet, public perceptron
{
public:
	layeredPerceptron();
};

#endif
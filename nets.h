#ifndef NETS_H
#define NETS_H

#include "network.h"

class SigmoidNet : public Network
{
private:
	virtual float activation_function(float x) const;
};

// [altri ...]

class Perceptron : public Network
{
public:
	Perceptron(float v = 1.0f, float f = 0.0f, unsigned int s = 0);
private:
	const float verum;
	const float falsum;
	virtual float activation_function(float x) const;
};

#endif
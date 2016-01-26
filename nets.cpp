#include <cmath>
#include <string>
#include "nets.h"

sigmoidNet::sigmoidNet(const unsigned int s) : network(s) {}

float sigmoidNet::activation_function(const float x) const
{
	return 1.0f / (1.0f + exp(-x));
}

float sigmoidNet::activation_derivative(const float y) const
{
	return y * (1.0f - y);
}





tanhNet::tanhNet(const unsigned int s) : network(s) {}

float tanhNet::activation_function(const float x) const
{
	return (2.0f / (1.0f + exp(-2.0f * x))) - 1.0f;
}

float tanhNet::activation_derivative(const float y) const
{
	return 1.0f - (y * y);
}





perceptron::perceptron(const float v, const float f, const unsigned int s) : network(s), verum(v), falsum(f) {}

float perceptron::activation_function(const float x) const
{
	return x > 0.0f ? verum : falsum;
}





layeredSigmoidNet::layeredSigmoidNet(const float bv) : layeredBiasedNet(bv) {}

layeredSigmoidNet::layeredSigmoidNet(const std::string netfile, const float bv) : layeredBiasedNet(netfile, bv) {}





layeredTanhNet::layeredTanhNet(const float bv) : layeredBiasedNet(bv) {}

layeredTanhNet::layeredTanhNet(const std::string netfile, const float bv) : layeredBiasedNet(netfile, bv) {}





layeredPerceptron::layeredPerceptron() : layeredBiasedNet() {}
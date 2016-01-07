#include <cmath>
#include "nets.h"

float sigmoidNet::activation_function(const float x) const
{
	return 1.0f / (1.0f + exp(-x));
}



perceptron::perceptron(const float v, const float f, const unsigned int s) : network(s), verum(v), falsum(f) {}

float perceptron::activation_function(const float x) const
{
	return x > 0.0f ? verum : falsum;
}



layeredSigmoidNet::layeredSigmoidNet(const bool b, const unsigned int n_l) : layeredNet(b, n_l) {}



layeredPerceptron::layeredPerceptron(const unsigned int n_l) : layeredNet(true, n_l) {}
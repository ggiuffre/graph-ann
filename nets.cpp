#include <cmath>
#include "nets.h"

sigmoidNet::sigmoidNet(const unsigned int s) : network(s) {}

float sigmoidNet::activation_function(const float x) const
{
	return 1.0f / (1.0f + exp(-x));
}



perceptron::perceptron(const float v, const float f, const unsigned int s) : network(s), verum(v), falsum(f) {}

float perceptron::activation_function(const float x) const
{
	return x > 0.0f ? verum : falsum;
}



layeredSigmoidNet::layeredSigmoidNet(const bool b) : layeredNet(b) {}



layeredPerceptron::layeredPerceptron() : layeredNet(true) {}
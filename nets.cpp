#include <cmath>
#include "nets.h"

// Sigmoid-thresholded Network:

float SigmoidNet::activation_function(const float x) const
{
	return 1.0f / (1.0f + exp(-x));
}



// Perceptron:

Perceptron::Perceptron(const float v, const float f, const unsigned int s) : Network(s), verum(v), falsum(f) {}

float Perceptron::activation_function(const float x) const
{
	return x > 0.0f ? verum : falsum;
}
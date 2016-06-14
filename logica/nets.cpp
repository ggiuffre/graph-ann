#include "nets.h"
#include <cmath>

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





atanNet::atanNet(const unsigned int s) : network(s) {}

float atanNet::activation_function(const float x) const
{
	return atan(x);
}

float atanNet::activation_derivative(const float y) const
{
	return 1.0f / (pow(tan(y), 2) + 1.0f);
}





layeredSigmoidNet::layeredSigmoidNet(const float lr, const float m) : layeredBiasedNet(lr, m) {}

layeredSigmoidNet::layeredSigmoidNet(const std::string netfile, const float lr, const float m) : layeredBiasedNet(netfile, lr, m) {}





layeredTanhNet::layeredTanhNet(const float lr, const float m) : layeredBiasedNet(lr, m) {}

layeredTanhNet::layeredTanhNet(const std::string netfile, const float lr, const float m) : layeredBiasedNet(netfile, lr, m) {}





layeredAtanNet::layeredAtanNet(const float lr, const float m) : layeredBiasedNet(lr, m) {}

layeredAtanNet::layeredAtanNet(const std::string netfile, const float lr, const float m) : layeredBiasedNet(netfile, lr, m) {}

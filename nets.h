#ifndef NETS_H
#define NETS_H

#include <string>
#include <vector>
#include "network.h"
#include "layered_biased_net.h"



// Sigmoid-activated network:

class sigmoidNet : virtual public network
{
private:
	virtual float activation_function(float x) const override;

protected:
	virtual float activation_derivative(float y) const override;

public:
	explicit sigmoidNet(unsigned int s = 0);
};



// Hyperbolic tangent-activated network:

class tanhNet : virtual public network
{
private:
	virtual float activation_function(float x) const override;

protected:
	virtual float activation_derivative(float y) const override;

public:
	explicit tanhNet(unsigned int s = 0);
};



// Perceptron:

class perceptron : public layeredBiasedNet
{
private:
	const float verum;
	const float falsum;
	virtual float activation_function(float x) const override;

public:
	perceptron(unsigned int n_in = 2, float v = 1.0f, float f = -1.0f);
	void train(const std::vector<std::vector<float> >& examples, const std::vector<std::vector<float> >& targets, float learning_rate, float& error, unsigned int max_epochs = 1000);
};



// Sigmoid-activated layered network:

class layeredSigmoidNet : public layeredBiasedNet, public sigmoidNet
{
public:
	explicit layeredSigmoidNet(float bv = 1.0f);
	layeredSigmoidNet(std::string netfile, float bv = 1.0f);
};



// Hyperbolic tangent-activated layered network:

class layeredTanhNet : public layeredBiasedNet, public tanhNet
{
public:
	explicit layeredTanhNet(float bv = 1.0f);
	layeredTanhNet(std::string netfile, float bv = 1.0f);
};

#endif

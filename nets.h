#ifndef NETS_H
#define NETS_H

#include "layered_biased_net.h"
#include "network.h"
#include <string>
#include <vector>



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
	virtual float activation_function(float x) const override;

public:
	explicit perceptron(unsigned int n_in = 2, float lr = 0.5f);
	void train(const std::vector<std::vector<float> >& examples, const std::vector<std::vector<float> >& targets, float& error, unsigned int max_epochs = 200);
};



// Sigmoid-activated layered network:

class layeredSigmoidNet : public layeredBiasedNet, public sigmoidNet
{
public:
	explicit layeredSigmoidNet(float lr = 0.5f, float m = 0.2f, bool bp = true);
	layeredSigmoidNet(std::string netfile, float lr = 0.5f, float m = 0.2f, bool bp = true);
};



// Hyperbolic tangent-activated layered network:

class layeredTanhNet : public layeredBiasedNet, public tanhNet
{
public:
	explicit layeredTanhNet(float lr = 0.5f, float m = 0.2f, bool bp = true);
	layeredTanhNet(std::string netfile, float lr = 0.5f, float m = 0.2f, bool bp = true);
};

#endif

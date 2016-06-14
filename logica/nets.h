#ifndef NETS_H
#define NETS_H

#include "layered_biased_net.h"
#include "network.h"
#include <string>



// Rete con neuroni ad attivazione sigmoidale:

class sigmoidNet : virtual public network
{
private:
	virtual float activation_function(float x) const /*override*/;

protected:
	virtual float activation_derivative(float y) const /*override*/;

public:
	explicit sigmoidNet(unsigned int s = 0);
};



// Rete con neuroni attivati da tangente iperbolica:

class tanhNet : virtual public network
{
private:
	virtual float activation_function(float x) const /*override*/;

protected:
	virtual float activation_derivative(float y) const /*override*/;

public:
	explicit tanhNet(unsigned int s = 0);
};



// Rete con neuroni attivati da arco-tangente:

class atanNet : virtual public network
{
private:
	virtual float activation_function(float x) const /*override*/;

protected:
	virtual float activation_derivative(float y) const /*override*/;

public:
	explicit atanNet(unsigned int s = 0);
};









// Rete a strati ad attivazione sigmoidale:

class layeredSigmoidNet : public layeredBiasedNet, public sigmoidNet
{
public:
	explicit layeredSigmoidNet(float lr = 0.5f, float m = 0.7f);
	layeredSigmoidNet(std::string netfile, float lr = 0.5f, float m = 0.7f);
};



// Rete a strati attivata da tangenti iperboliche:

class layeredTanhNet : public layeredBiasedNet, public tanhNet
{
public:
	explicit layeredTanhNet(float lr = 0.4f, float m = 0.3f);
	layeredTanhNet(std::string netfile, float lr = 0.4f, float m = 0.3f);
};



// Rete a strati attivata da arco-tangenti:

class layeredAtanNet : public layeredBiasedNet, public atanNet
{
public:
	explicit layeredAtanNet(float lr = 0.1f, float m = 0.2f);
	layeredAtanNet(std::string netfile, float lr = 0.1f, float m = 0.2f);
};

#endif

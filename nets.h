#ifndef NETS_H
#define NETS_H

#include "layered_biased_net.h"
#include "network.h"
#include <string>
#include <vector>



// Rete con neuroni ad attivazione sigmoidale:

class sigmoidNet : virtual public network
{
private:
	virtual float activation_function(float x) const override;

protected:
	virtual float activation_derivative(float y) const override;

public:
	explicit sigmoidNet(unsigned int s = 0);
};



// Rete con neuroni attivati da tangente iperbolica:

class tanhNet : virtual public network
{
private:
	virtual float activation_function(float x) const override;

protected:
	virtual float activation_derivative(float y) const override;

public:
	explicit tanhNet(unsigned int s = 0);
};



// Rete con neuroni attivati da arco-tangente:

class arcTan : virtual public network
{
private:
	virtual float activation_function(float x) const override;

protected:
	virtual float activation_derivative(float y) const override;

public:
	explicit arcTan(unsigned int s = 0);
};







// =====   RETI A STRATI:



// Rete a strati ad attivazione sigmoidale:

class layeredSigmoidNet : public layeredBiasedNet, public sigmoidNet
{
public:
	explicit layeredSigmoidNet(float lr = 0.5f, float m = 0.2f, bool bp = true);
	layeredSigmoidNet(std::string netfile, float lr = 0.5f, float m = 0.2f, bool bp = true);
};



// Rete a strati attivata da tangenti iperboliche:

class layeredTanhNet : public layeredBiasedNet, public tanhNet
{
public:
	explicit layeredTanhNet(float lr = 0.5f, float m = 0.2f, bool bp = true);
	layeredTanhNet(std::string netfile, float lr = 0.5f, float m = 0.2f, bool bp = true);
};



// Rete a strati attivata da arco-tangenti:

class layeredArcTan : public layeredBiasedNet, public arcTan
{
public:
	explicit layeredArcTan(float lr = 0.2f, float m = 0.7f, bool bp = false);
	layeredArcTan(std::string netfile, float lr = 0.2f, float m = 0.7f, bool bp = false);
};

#endif

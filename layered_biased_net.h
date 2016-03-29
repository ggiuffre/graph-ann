#ifndef LAYERED_BIASED_NET_H
#define LAYERED_BIASED_NET_H

#include <vector>
#include <string>
#include "layered_net.h"

class unit
{
public:
	float out, delta;
	unit(float o = 0.0f, float d = 0.0f) : out(o), delta(d) {}
};

class layeredBiasedNet : public layeredNet
{
private:
	const float bias_value;

protected:
	virtual void store(const std::vector<float>& in) override;

public:
	explicit layeredBiasedNet(float bv = 1.0f);		// il float è soltanto un parametro
	layeredBiasedNet(const layeredBiasedNet& net);
	layeredBiasedNet& operator=(const layeredBiasedNet& net);
	layeredBiasedNet(std::string netfile, float bv = 1.0f);

	bool is_bias(unsigned int n) const;

	void init(init_t mode = RAND, float bound = 0.5f);
	void init(std::string netfile);
	virtual void addLayer(unsigned int n_nodes) override;
	virtual void linkLayer(unsigned int l) override;				// virtual...

	void incremental_training(const std::vector<std::vector<float> >& examples, const std::vector<std::vector<float> >& targets, float learning_rate, float momentum, float& error, unsigned int max_epochs = 28000);
	void incremental_training(std::string data_file, float learning_rate, float momentum, float& error, unsigned int max_epochs = 28000);
};

#endif

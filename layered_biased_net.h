#ifndef LAYERED_BIASED_NET_H
#define LAYERED_BIASED_NET_H

#include <vector>
#include <string>
#include "layered_net.h"

class layeredBiasedNet : public layeredNet
{
private:
	const float bias_value;

protected:
	void store(const std::vector<float>& in);

public:
	layeredBiasedNet(float bv = 1.0f);
	layeredBiasedNet(std::string netfile, float bv = 1.0f);

	unsigned int input_size() const;				// (virtual?)
	unsigned int output_size() const;
	bool is_bias(unsigned int n) const;

	void init(init_t mode = RAND, float bound = 0.5f);
	void init(std::string netfile);
	virtual void addLayer(unsigned int n_nodes);
	virtual void linkLayer(unsigned int l);				// virtual...

/*
	virtual void incremental_training(unsigned int n_examples, float ** examples, float ** target, float learning_rate, float momentum, float desired_err);
	virtual void incremental_training(std::string data_file, float learning_rate, float momentum, float desired_err);
*/
};

#endif
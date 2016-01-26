#ifndef LAYERED_BIASED_NET_H
#define LAYERED_BIASED_NET_H

#include <vector>
#include <string>
#include "layered_net.h"



class unit		// nested ?
{
public:
	float out;
	float delta;
	unit();
};



class layeredBiasedNet : public layeredNet
{
private:
	const float bias_value;

protected:
	virtual void store(const std::vector<float>& in) override;

public:
	explicit layeredBiasedNet(float bv = 1.0f);		// il float è soltanto un parametro
	layeredBiasedNet(std::string netfile, float bv = 1.0f);

	unsigned int input_size() const;
	unsigned int output_size() const;
	bool is_bias(unsigned int n) const;

	void init(init_t mode = RAND, float bound = 0.5f);
	void init(std::string netfile);
	virtual void addLayer(unsigned int n_nodes) override;
	virtual void linkLayer(unsigned int l) override;				// virtual...

	void incremental_training(unsigned int n_examples, float ** examples, float ** target, float learning_rate, float momentum, float desired_err);
	void incremental_training(std::string data_file, float learning_rate, float momentum, float desired_err);
};

#endif
#ifndef INTERNETWORK_H
#define INTERNETWORK_H

#include "network.h"

// a network of networks...
class internetwork : public network
{
private:
	network * nets;

public:
	internetwork(unsigned int s = 0);
	~internetwork();
	void add(const network& n);		// pushes network n into the internetwork
	std::vector<float> operator()(const std::vector<float>& in);

	friend class iterator;
	class iterator {
		friend class internetwork;
	public:
		iterator& operator++();		// prefisso
		iterator operator++(int);	// postfisso
		bool operator==(const iterator& x) const;
		bool operator!=(const iterator& x) const;
	private:
		network * punt;
	};
	iterator begin() const;
	iterator end() const;
};

#endif
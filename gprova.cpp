#include <iostream>
#include "nets.h"
using namespace std;	

int main()
{
	layeredSigmoidNet net;
//	layeredTanhNet net;

	net.addLayer(2);
	net.addLayer(5);
	net.addLayer(1);

	net.init(network::RAND, 0.5f);
	float error = 0.015f;
	net.incremental_training("./data/or.data", 0.5f, 0.15f, error);
	net.save("./nets/or.net");

//	net.init("./nets/or.net");

	vector<float> in(2);
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = net(in);

	cout << "result: ";
	for (unsigned int i = 1; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;

	return 0;
}
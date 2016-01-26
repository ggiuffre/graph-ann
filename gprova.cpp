#include <iostream>
#include "nets.h"
using namespace std;	

int main()
{
	layeredSigmoidNet net;
//	layeredTanhNet net;

	net.addLayer(16);
	net.addLayer(12);
	net.addLayer(4);

	net.incremental_training("./data/mat.data", 0.5f, 0.15f, 0.01f);
	net.save("./nets/mat.net");

//	net.init("./nets/mat.net");

	vector<float> in(16);
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
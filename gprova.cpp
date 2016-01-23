#include <iostream>
#include "layered_net.h"
#include "nets.h"
using namespace std;

int main()
{
	layeredSigmoidNet net;
/*
	net.addLayer(2);
	net.addLayer(7);
	net.addLayer(1);

	net.incremental_training("./data/sum.data", 0.5f, 0.1f, 0.01f);
	net.save("./nets/sum.net");
*/

	net.init("./nets/sum.net");

	vector<float> in(2);
	cout << "test: ";
	cin >> in[0] >> in[1];
	vector<float> out = net(in);

	for (int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;

	return 0;
}
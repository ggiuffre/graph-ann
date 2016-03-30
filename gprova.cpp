#include <iostream>
#include "nets.h"
using namespace std;	

int main()
{
	const unsigned int n_in = 2;

/*	perceptron net(n_in);
	net.init(network::RAND, 0.5f);
	float err = 0.015f;
	net.train({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}, {{-1}, {-1}, {-1}, {1}}, 0.2f, err, 50);
	cout << net << endl;		*/

	layeredSigmoidNet net;
//	layeredTanhNet net;

	net.addLayer(n_in);
	net.addLayer(4);
	net.addLayer(1);

	net.init(network::RAND, 0.5f);	// network::ZERO manda in vacca tutto
									// ----------------------------------
	float err = 0.015f;
	net.incremental_training("./data/and.data", 0.5f, 0.15f, err);
	net.save("./nets/and.net");

//	net.init("./nets/and.net");

	vector<float> in(n_in);
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = net(in);

	cout << "result: ";
	for (unsigned int i = 1; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;
}

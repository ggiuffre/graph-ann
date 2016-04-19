#include "nets.h"
#include "net_container.h"
#include "internetwork.h"
#include <iostream>
using namespace std;	

int main()
{
	const unsigned int n_in = 2;
	float err = 0.015f;

/*	perceptron net_1(n_in);
	net_1.init(network::RAND, 0.5f);
	net_1.train({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}, {{-1}, {-1}, {-1}, {1}}, err, 50);

	perceptron net_2(n_in);
	net_2.init(network::RAND, 0.5f);
	net_2.train({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}, {{-1}, {1}, {1}, {1}}, err, 50);

	perceptron net_3(n_in);
	net_3.init(network::RAND, 0.5f);
	net_3.train({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}, {{-1}, {1}, {1}, {1}}, err, 50);

	internetwork internet;
	internet.push_back(net_1);
	internet.push_back(net_2);
	internet.push_back(net_3);
	internet.link(0, 2);
	internet.link(1, 2);	*/

/*	vector<float> in(net_1.input_size());
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = net_1(in);

	cout << "result: ";
	for (unsigned int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;	*/

	layeredSigmoidNet net;
//	layeredTanhNet net;

	net.addLayer(n_in);
	net.addLayer(4);
	net.addLayer(1);

	net.init(network::RAND, 0.5f);	// network::ZERO manda in vacca tutto
									// ----------------------------------
	net.incremental_training("./data/and.data", err);
	net.save("./nets/and.net");

//	net.init("./nets/and.net");
	cout << net.is_input(8) << ' ' << net.is_output(8) << endl;

	vector<float> in(n_in);
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = net(in);

	cout << "result: ";
	for (unsigned int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;
}

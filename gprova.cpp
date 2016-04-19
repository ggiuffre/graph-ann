#include "nets.h"
#include "net_container.h"
#include "internetwork.h"
#include <iostream>
using namespace std;	

int main()
{
	const unsigned int n_in = 2;
	float err = 0.015f;

	perceptron net_1(n_in);
	net_1.init(network::RAND, 0.5f);
	err = 0.015f;
	net_1.train({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}, {{-1}, {-1}, {-1}, {1}}, err, 50);

	perceptron net_2(n_in);
	net_2.init(network::RAND, 0.5f);
	err = 0.015f;
	net_2.train({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}, {{-1}, {1}, {1}, {1}}, err, 50);

/*	perceptron net_3(n_in);
	net_3.init(network::RAND, 0.5f);
	err = 0.015f;
	net_3.train({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}, {{-1}, {1}, {1}, {1}}, err, 50);	*/

	layeredSigmoidNet net_4;
	net_4.addLayer(n_in);
	net_4.addLayer(4);
	net_4.addLayer(1);

	net_4.init(network::RAND, 0.5f);	// network::ZERO manda in vacca tutto
										// ----------------------------------
	err = 0.015f;
	net_4.incremental_training("./data/or.data", err);
	net_4.save("./nets/or.net");

	internetwork internet;
	internet.push_back(net_4);
	internet.push_back(net_4);
	internet.push_back(net_4);
	internet.link(0, 2);			// OCCHIO A NON COLLEGARE RETI BIPOLARI CON RETI BINARIE sennò non ha senso il risultato
	internet.link(1, 2);

	vector<float> in(internet.input_size());
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = internet(in);

	cout << "result: ";
	for (unsigned int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;

/*	layeredSigmoidNet net;
//	layeredTanhNet net;

	net.addLayer(n_in);
	net.addLayer(4);
	net.addLayer(1);

	net.init(network::RAND, 0.5f);	// network::ZERO manda in vacca tutto
									// ----------------------------------
	net.incremental_training("./data/and.data", err);
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
	cout << endl;		*/
}

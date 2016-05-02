#include "nets.h"
#include "internetwork.h"
#include <iostream>
using namespace std;	

int main()
{
/*	layeredSigmoidNet net_1("./nets/and.net");
	layeredSigmoidNet net_2("./nets/or.net");
	layeredSigmoidNet net_3("./nets/xor.net");

	internetwork internet;
	internet.push_back(net_1);
	internet.push_back(net_2);
	internet.push_back(net_3);
	internet.link(0, 2);
	internet.link(1, 2);
	// NON COLLEGARE RETI BIPOLARI CON RETI BINARIE sennò non ha senso il risultato

	vector<float> in(internet.input_size());
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = internet(in);

	cout << "result: ";
	for (unsigned int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;*/

	const unsigned int n_in = 2;
	float err = 0.0015f;

	layeredSigmoidNet net;		// --> ideale per input in [0,1]
//	layeredTanhNet net;			// --> ideale per input in [-1,1]
//	layeredAtanNet net;			// --> ideale per input in [-1,1]

	net.addLayer(n_in);
	net.addLayer(4);
	net.addLayer(1);

	net.init(0.5f);
	net.incremental_training("./data/media.data", err);
	net.save("./nets/media.net");
//	net.init("./nets/media.net");

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

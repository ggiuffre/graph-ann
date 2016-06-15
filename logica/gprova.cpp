#include "nets.h"
#include "internetwork.h"
#include <iostream>
using namespace std;	

int main()
{
	layeredSigmoidNet net_1("./nets/Sigmoide/and.net");
	layeredSigmoidNet net_2("./nets/Sigmoide/or.net");
	layeredSigmoidNet net_3("./nets/Sigmoide/xor.net");

	internetwork internet;
	internet.push_back(&net_1);
	internet.push_back(&net_2);
	internet.push_back(&net_3);
	internet.link(0, 2);
	internet.link(1, 2);
	// NON COLLEGARE RETI BIPOLARI CON RETI BINARIE sennò non ha senso il risultato

	cout << internet({1, 1, 0, 0})[0] << endl;
/*
	vector<float> in(internet.input_size());
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = internet(in);

	cout << "result: ";
	for (unsigned int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;*/

/*	const unsigned int n_in = 4;
	float err = 0.02f;

//	layeredSigmoidNet net;		// --> ideale per input in [0,1]
//	layeredTanhNet net;			// --> ideale per input in [-1,1]
	layeredAtanNet net;			// --> ideale per input in [-1,1]

	net.addLayer(n_in);
	net.addLayer(6);
	net.addLayer(4);

	net.init(0.5f);
	net.train("./data/bin++_2.data", err);
//	net.save("./nets/_____/bin++_2.net");
//	net.init("./nets/_____/bin++_2.net");

	vector<float> in(n_in);
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = net(in);

	cout << "result: ";
	for (unsigned int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;*/
}

#include "nets.h"
#include "internetwork.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	layeredSigmoidNet net_1("./nets/Sigmoide/and.net");
	layeredSigmoidNet net_2("./nets/Sigmoide/or.net");
	layeredSigmoidNet net_3("./nets/Sigmoide/xor.net");

	internetwork prova;
	prova.push_back(&net_1);
	prova.push_back(&net_2);
	prova.push_back(&net_3);
	prova.link(0, 2);
	prova.link(1, 2);
	// NON COLLEGARE RETI BIPOLARI CON RETI BINARIE sennò non ha senso il risultato

	vector<float> out = prova({0, 0, 1, 1});
	cout << "result: ";
	for (unsigned int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;
/*
	vector<float> in(prova.input_size());
	cout << "test: ";
	for (unsigned int i = 0; i < in.size(); ++i)
		cin >> in[i];
	vector<float> out = prova(in);

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

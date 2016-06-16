#include "/home/0/2014/ggiuffre/Documents/ann_2/logica/nets.h"
#include "/home/0/2014/ggiuffre/Documents/ann_2/logica/internetwork.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	layeredSigmoidNet net_1("/home/0/2014/ggiuffre/Documents/ann_2/logica/nets/Sigmoide/and.net");
	layeredSigmoidNet net_2("/home/0/2014/ggiuffre/Documents/ann_2/logica/nets/Sigmoide/or.net");
	layeredSigmoidNet net_3("/home/0/2014/ggiuffre/Documents/ann_2/logica/nets/Sigmoide/xor.net");

	internetwork prova;
	prova.push_back(&net_1);
	prova.push_back(&net_2);
	prova.push_back(&net_3);
	prova.link(0, 2);
	prova.link(1, 2);

	vector<float> out = prova({0, 0, 1, 1});
	cout << "result: " << out[0] << endl;
//	for (unsigned int i = 0; i < out.size(); ++i)
//		cout << out[i] << ' ';
//	cout << endl;
}

#include <iostream>
#include <vector>
#include "internetwork.h"
#include "nets.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int n_in = 2;
	Perceptron net_1(1, -1);
	net_1.add(3);
	net_1.link(0, 2, 2.0f);
	net_1.link(1, 2, 3.0f);

	Perceptron net_2(1, -1);
	net_2.add(3);
	net_2.link(0, 2);
	net_2.link(1, 2, 2.0f);

	Internetwork nets;
	nets.add(net_1);
	nets.add(net_2);

//	vector<float> inputs(n_in);
//	cout << "inputs: ";
//	for (int i = 0; i < nets.size(); ++i)
//	{
//		for (int j = 0; j < n_in; ++j)
//			cin >> inputs[j];
//
//		vector<float> outputs = nets[i](inputs);
//		cout << "outputs: ";
//		for (int j = 0; j < outputs.size(); ++j)
//			cout << outputs[j] << ' ';
//		cout << endl;
//	}

	return 0;
}
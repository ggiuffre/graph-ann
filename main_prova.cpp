#include <iostream>
#include <vector>
#include "network.h"
#include "layered_net.h"
#include "nets.h"
#include "internetwork.h"

using namespace std;

int main(int argc, char const *argv[])
{
	layeredSigmoidNet net_1;
	net_1.addLayer(2);
	net_1.addLayer(1);

	vector<float> inputs(net_1.input_size());
	cout << "inputs: ";
	for (int j = 0; j < net_1.input_size(); ++j)
		cin >> inputs[j];

	vector<float> outputs = net_1(inputs);
	cout << "outputs: ";
	for (int j = 0; j < outputs.size(); ++j)
		cout << outputs[j] << ' ';
	cout << endl;

	perceptron net_2(1, -1);
	net_2.add(3);
	net_2.link(0, 2);
	net_2.link(1, 2, 2.0f);

	internetwork nets;
	nets.add(net_1);
	nets.add(net_2);

/*
	for (internetwork::iterator it = nets.begin(); it != nets.end(); ++it)
	{
		vector<float> inputs(net_1.input_size());
		cout << "inputs: ";
		for (int j = 0; j < net_1.input_size(); ++j)
			cin >> inputs[j];

		vector<float> outputs = (*it)(inputs);
		cout << "outputs: ";
		for (int j = 0; j < outputs.size(); ++j)
			cout << outputs[j] << ' ';
		cout << endl;
	}
*/

	return 0;
}
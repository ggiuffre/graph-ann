#include <iostream>
#include "layered_net.h"
#include "nets.h"
using namespace std;

int main()
{
	layeredSigmoidNet net = layeredSigmoidNet(true);
	net.addLayer(2);
	net.addLayer(7);
	net.addLayer(1);

	float ** examples = new float * [4];
	for (int i = 0; i < 4; ++i)
		examples[i] = new float [2];
	examples[0][0] = -1.0f;	examples[0][1] = -1.0f;
	examples[1][0] = -1.0f;	examples[1][1] =  1.0f;
	examples[2][0] =  1.0f;	examples[2][1] = -1.0f;
	examples[3][0] =  1.0f;	examples[3][1] =  1.0f;

	float ** targets = new float * [4];
	for (int i = 0; i < 4; ++i)
		targets[i] = new float [1];
	targets[0][0] = 0.02f;
	targets[1][0] = 0.98f;
	targets[2][0] = 0.98f;
	targets[3][0] = 0.02f;

	net.incremental_training(4, examples, targets, 0.5f, 0.1f, 0.007f);
	cout << net << endl;

/*
	float ** examples = new float * [1];
	examples[0] = new float [2];
	examples[0][0] = 0.05f;	examples[0][1] = 0.10f;

	float ** targets = new float * [1];
	targets[0] = new float [2];
	targets[0][0] = 0.01f; targets[0][1] = 0.99f;

	net.edge(0, 4) = net.edge(0, 5) = 0.35f;
	net.edge(1, 4) = 0.15f;
	net.edge(1, 5) = 0.25f;
	net.edge(2, 4) = 0.20f;
	net.edge(2, 5) = 0.30f;

	net.edge(3, 7) = net.edge(3, 8) = 0.60f;
	net.edge(4, 7) = 0.40f;
	net.edge(4, 8) = 0.50f;
	net.edge(5, 7) = 0.45f;
	net.edge(5, 8) = 0.55f;

	net.incremental_training(1, examples, targets, 0.5f, 0.0f, 0.001f);
	cout << net << endl;
*/

	vector<float> in(2);
	cin >> in[0] >> in[1];
	vector<float> out = net(in);

	for (int i = 0; i < out.size(); ++i)
		cout << out[i] << ' ';
	cout << endl;

	return 0;
}
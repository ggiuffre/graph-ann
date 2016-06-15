#include "net_interface.h"
#include <QDir>
#include <QString>

netInterface::netInterface(const QFileInfo i, QWidget * parent) : QTabWidget(parent), info(i), net(fromFile(info))
{
	runner = new netRunnerWidget(net, this);
	trainer = new netTrainerWidget(net, this);

	addTab(runner, "Collauda la rete");
	addTab(trainer, "Allena la rete");
}

netInterface::~netInterface()
{
	delete trainer;
	delete runner;
	delete net;
}

layeredBiasedNet * netInterface::fromFile(const QFileInfo i)
{
	layeredBiasedNet * net = nullptr;

	QString dir = i.absoluteDir().dirName();
	if (dir == "Sigmoide")
		net = new layeredSigmoidNet(i.absoluteFilePath().toStdString());
	else if (dir == "Arcotangente")
		net = new layeredAtanNet(i.absoluteFilePath().toStdString());
	else if (dir == "Tangente Iperbolica")
		net = new layeredTanhNet(i.absoluteFilePath().toStdString());

	return net;
}

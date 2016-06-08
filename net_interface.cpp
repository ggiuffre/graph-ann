#include "net_interface.h"
#include <QMessageBox>
#include <QDir>

netInterface::netInterface(const QFileInfo i, QWidget * parent) : QTabWidget(parent), info(i), net(nullptr) // assume che i sia valido
{
	QString dir = info.absoluteDir().dirName();
	if (dir == "Sigmoide")
		net = new layeredSigmoidNet(info.absoluteFilePath().toStdString());
	else if (dir == "Arcotangente")
		net = new layeredAtanNet(info.absoluteFilePath().toStdString());
	else if (dir == "Tangente Iperbolica")
		net = new layeredTanhNet(info.absoluteFilePath().toStdString());

	runner = new netRunnerWidget(net, this);
	trainer = new netTrainerWidget(info.completeBaseName(), net, this);

	addTab(runner, "Collauda la rete");
	addTab(trainer, "Allena la rete");
}

netInterface::~netInterface()
{
	// delete trainer; ???
	// delete runner;  ???
	delete net;
}

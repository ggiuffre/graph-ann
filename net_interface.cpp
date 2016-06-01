#include "net_interface.h"
#include <QMessageBox>
#include <QDir>

netInterface::netInterface(const QFileInfo i, QWidget * parent) : QTabWidget(parent), info(i), net(new layeredBiasedNet(info.absoluteFilePath().toStdString()))//, runner(new netRunnerWidget(info.completeBaseName(), net)), trainer(new netTrainerWidget(info.completeBaseName(), net)) // assume che i sia valido
{
	QString dir = info.absoluteDir().dirName();
	if (dir == "sigmoid")
		net = dynamic_cast<layeredSigmoidNet *>(net);
	else if (dir == "arctan")
		net = dynamic_cast<layeredAtanNet *>(net);
	else if (dir == "tanh")
		net = dynamic_cast<layeredTanhNet *>(net);

	runner = new netRunnerWidget(info.completeBaseName(), net);
	trainer = new netTrainerWidget(info.completeBaseName(), net);

	addTab(runner, "Collauda la rete");
	addTab(trainer, "Allena la rete");
}

netInterface::~netInterface()
{
	delete net;
}

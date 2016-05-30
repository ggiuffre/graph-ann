#include "net_interface.h"

netInterface::netInterface(const QString t, QWidget * parent) : QTabWidget(parent), title(t), runner(new netRunnerWidget(title)), trainer(new netTrainerWidget(title)), net(new layeredBiasedNet("logica/nets/" + title.toStdString() + ".net")) // assume che t sia valido
{
	// aggiungere controllo nome rete...?
	addTab(runner, "Collauda la rete");
	addTab(trainer, "Allena la rete");
}

netInterface::~netInterface()
{
	delete net;
}

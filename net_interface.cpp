#include "net_interface.h"

netInterface::netInterface(const QString t, QWidget * parent) : QTabWidget(parent), title(t), net(new layeredBiasedNet("logica/nets/" + title.toStdString() + ".net")), runner(new netRunnerWidget(title, net)), trainer(new netTrainerWidget(title, net)) // assume che t sia valido
{
	// aggiungere controllo nome rete...?
	addTab(runner, "Collauda la rete");
	addTab(trainer, "Allena la rete");
}

netInterface::~netInterface()
{
	delete net;
}

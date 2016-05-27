#include "net_interface.h"

netInterface::netInterface(const QString t, QWidget * parent) : QTabWidget(parent), title(t), runner(new netRunnerWidget(title)), trainer(new netTrainerWidget(title))
{
	// aggiungere controllo nome rete...?
	addTab(runner, "Collauda la rete");
	addTab(trainer, "Allena la rete");
}

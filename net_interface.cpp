#include "net_interface.h"

netInterface::netInterface(const QString t, QWidget * parent) : QTabWidget(parent), title(t), runner(new netRunnerWidget(title)), trainer(new netTrainerWidget(title))
{
	addTab(runner, "Allena la rete");
	addTab(trainer, "Collauda la rete");
}

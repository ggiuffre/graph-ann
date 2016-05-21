#include "net_interface.h"

netInterface::netInterface(const QString t, QWidget * parent) : QTabWidget(parent), title(t), runner(new netRunnerWidget(title)), trainer(new netTrainerWidget(title))
{
	addTab(runner, "Allena la rete");
	addTab(trainer, "Collauda la rete");
}

/*void netInterface::run()
{
	if (runner)
		delete runner;
	runner = new netRunnerWidget(title);
	addWidget(runner);
	setCurrentWidget(runner);
}

void netInterface::train()
{
	if (trainer)
		delete trainer;
	trainer = new netTrainerWidget(title);
	addWidget(trainer);
	setCurrentWidget(trainer);
}*/

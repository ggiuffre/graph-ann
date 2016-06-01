#ifndef NET_INTERFACE_H
#define NET_INTERFACE_H

#include "net_runner_widget.h"
#include "net_trainer_widget.h"
#include "logica/nets.h"
#include <QTabWidget>
#include <QString>
#include <QFileInfo>

class netInterface : public QTabWidget
{
	Q_OBJECT

private:
	const QFileInfo info;
	layeredBiasedNet * net;
	netRunnerWidget * runner;
	netTrainerWidget * trainer;

public:
	netInterface(QFileInfo i, QWidget * parent = nullptr);
	~netInterface();
};

#endif

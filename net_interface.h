#ifndef NET_INTERFACE_H
#define NET_INTERFACE_H

#include "net_runner_widget.h"
#include "net_trainer_widget.h"
#include <QTabWidget>
#include <QString>

class netInterface : public QTabWidget
{
	Q_OBJECT

private:
	QString title;
	netRunnerWidget * runner;
	netTrainerWidget * trainer;

public:
	netInterface(QString t = "", QWidget * parent = nullptr);
};

#endif

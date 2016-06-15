#ifndef NET_RUNNER_WIDGET_H
#define NET_RUNNER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include "logica/network.h"		// meglio: nets.h   ?

class netRunnerWidget : public QWidget
{
	Q_OBJECT

private:
	network * net;
	QFormLayout * layout;
	QTextEdit * input_text;
	QPushButton * trigger;
	QLabel * result;

public:
	netRunnerWidget(network * n, QWidget * parent = nullptr);

public slots:
	void calculate();
};

#endif

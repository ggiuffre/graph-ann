#ifndef NET_RUNNER_WIDGET_H
#define NET_RUNNER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QString>
#include "logica/layered_biased_net.h"		// meglio: nets.h   ?

class netRunnerWidget : public QWidget
{
	Q_OBJECT

private:
	QString title;
	layeredBiasedNet * net;
	QFormLayout * layout;
	QTextEdit * input_text;
	QPushButton * trigger;
	QLabel * result;

public:
	netRunnerWidget(QString t, layeredBiasedNet * n, QWidget * parent = nullptr);

protected slots:
	void calculate();
};

#endif

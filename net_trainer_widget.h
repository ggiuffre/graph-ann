#ifndef NET_TRAINER_WIDGET_H
#define NET_TRAINER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QLineEdit>
#include "logica/layered_biased_net.h"		// meglio: nets.h   ?

class netTrainerWidget : public QWidget
{
	Q_OBJECT

private:
	QString title;
	layeredBiasedNet * net;
	QSpinBox * n_epochs;
	QFormLayout * layout;

public:
	netTrainerWidget(QString t, layeredBiasedNet * n, QWidget * parent = nullptr);
};

#endif

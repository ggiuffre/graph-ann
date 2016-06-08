#ifndef NET_TRAINER_WIDGET_H
#define NET_TRAINER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include "logica/layered_biased_net.h"		// meglio: nets.h   ?

class netTrainerWidget : public QWidget
{
	Q_OBJECT

private:
	QString title;
	layeredBiasedNet * net;
	QLineEdit * data_file;
	QSpinBox * n_epochs;
	QPushButton * trigger;
	QFormLayout * layout;

public:
	netTrainerWidget(QString t, layeredBiasedNet * n, QWidget * parent = nullptr);

public slots:
	void train();
};

#endif

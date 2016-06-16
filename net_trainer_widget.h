#ifndef NET_TRAINER_WIDGET_H
#define NET_TRAINER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "logica/layered_biased_net.h"

class netTrainerWidget : public QWidget
{
	Q_OBJECT

private:
	layeredBiasedNet * net;
	QLineEdit * data_file;
	QSpinBox * n_epochs;
	QDoubleSpinBox * desired_error;
	QPushButton * trigger;
	QLabel * result;
	QFormLayout * layout;

public:
	netTrainerWidget(layeredBiasedNet * n, QWidget * parent = nullptr);

public slots:
	void train();
};

#endif

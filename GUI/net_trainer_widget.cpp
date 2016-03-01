#include "net_trainer_widget.h"

netTrainerWidget::netTrainerWidget(QWidget * parent) : QWidget(parent)
{
	n_epochs = new QSpinBox;
	n_epochs->setMinimum(1);
	n_epochs->setMaximum(10);

	layout = new QFormLayout;
	layout->addRow("Data file:", new QLineEdit);
	layout->addRow("Number of epochs:", n_epochs);

	setLayout(layout);
}
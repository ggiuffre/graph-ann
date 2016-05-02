#include "net_trainer_widget.h"
#include <QLabel>

netTrainerWidget::netTrainerWidget(const QString t, QWidget * parent) : QWidget(parent), title(t), n_epochs(new QSpinBox), layout(new QFormLayout)
{
	n_epochs->setMinimum(1);
	n_epochs->setMaximum(100000);

	if (title == "")
		layout->addRow("Rete da allenare:", new QLineEdit);
	else
		layout->addRow(title, new QLabel);
	layout->addRow("File di allenamento:", new QLineEdit);
	layout->addRow("Numero di epoche:", n_epochs);

	setLayout(layout);
}

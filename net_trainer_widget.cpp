#include "net_trainer_widget.h"
#include <QLabel>
#include <QMessageBox>

netTrainerWidget::netTrainerWidget(const QString t, layeredBiasedNet * n, QWidget * parent) : QWidget(parent), title(t), net(n), data_file(new QLineEdit), n_epochs(new QSpinBox), trigger(new QPushButton("Allena")), layout(new QFormLayout)
{
	n_epochs->setMinimum(1);
	n_epochs->setMaximum(100000);

	layout->addRow(title, new QLabel);
	layout->addRow("File di allenamento:", data_file);
	layout->addRow("Numero di epoche:", n_epochs);

	layout->addWidget(trigger);
	connect(trigger, SIGNAL(clicked()), this, SLOT(train()));

	setLayout(layout);
}

void netTrainerWidget::train()
{
	if (net)
	{
		float err = -1.0f;
		net->train(data_file->text().toStdString(), err);
		QMessageBox::warning(this, "Successo", "La rete e' stata allenata con successo.");
	}
}
//void train(std::string data_file, float& error, unsigned int max_epochs = 28000);

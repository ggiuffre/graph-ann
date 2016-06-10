#include "net_trainer_widget.h"
#include <QMessageBox>

netTrainerWidget::netTrainerWidget(layeredBiasedNet * n, QWidget * parent) : QWidget(parent), net(n), data_file(new QLineEdit), n_epochs(new QSpinBox), desired_error(new QDoubleSpinBox), trigger(new QPushButton("Allena")), result(new QLabel), layout(new QFormLayout)
{
	layout->addRow("File di allenamento:", data_file);

	n_epochs->setMinimum(1);
	n_epochs->setMaximum(100000);
	layout->addRow("Massimo numero di epoche:", n_epochs);

	desired_error->setDecimals(4);
	desired_error->setMinimum(0.0000);
	desired_error->setMaximum(0.5);
	desired_error->setSingleStep(0.0001);
	layout->addRow("Massimo errore tollerato:", desired_error);

	layout->addWidget(trigger);
	connect(trigger, SIGNAL(clicked()), this, SLOT(train()));

	result->setWordWrap(true);
	layout->addRow(result);

	setLayout(layout);
}

void netTrainerWidget::train()
{
	if (net)
	{
		float err = static_cast<float>(desired_error->value());
		net->train("logica/data/" + data_file->text().toStdString(), err, static_cast<unsigned int>(n_epochs->value()));
		if (err <= desired_error->value())
			result->setText("La rete è stata allenata con successo!");
		else
			result->setText("L'allenamento non ha funzionato: prova ad alzare la tolleranza sull'errore o il numero di epoche e controlla che il nome del file sia valido. Inoltre, il numero di neuroni potrebbe essere troppo basso (creare una nuova rete).");
	}
	else
		QMessageBox::warning(this, "Errore", "La rete non è definita: forse il file .net è stato ridenominato durante la sessione attuale.");
}

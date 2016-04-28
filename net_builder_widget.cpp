#include "net_builder_widget.h"

netBuilderWidget::netBuilderWidget(QWidget * parent) : QWidget(parent)
{
//	setStyleSheet( "QWidget{ background-color : rgba(240, 240, 240, 128); }" );
	name = new QLineEdit;

	neuron_type = new QComboBox;
	neuron_type->insertItem(0, "Sigmoide");
	neuron_type->insertItem(1, "Tangente Iperbolica");
	neuron_type->insertItem(2, "Arcotangente");

	n_layers = new QSpinBox;
	n_layers->setMinimum(1);
	n_layers->setMaximum(10);

	biased = new QCheckBox;

	layout = new QFormLayout;
	layout->addRow("Nome della rete:", name);
	layout->addRow("Tipo di neurone:", neuron_type);
	layout->addRow("Numero di livelli:", n_layers);
	layout->addRow("La rete è biased:", biased);

	trigger = new QPushButton("Crea");
	connect(trigger, SIGNAL(clicked()), this, SLOT(netAdded()));
	layout->addWidget(trigger);

	setLayout(layout);
}

void netBuilderWidget::netAdded()
{
	emit newNet(name->text(), neuron_type->currentText(), n_layers->value(), biased->isChecked());
}

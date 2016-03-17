#include "net_builder_widget.h"
#include <QMessageBox>

netBuilderWidget::netBuilderWidget(QWidget * parent) : QWidget(parent)
{
	name = new QLineEdit;

	neuron_type = new QComboBox;
	neuron_type->insertItem(0, "Sigmoid");
	neuron_type->insertItem(1, "Tanh");

	n_layers = new QSpinBox;
	n_layers->setMinimum(1);
	n_layers->setMaximum(10);

	biased = new QCheckBox;

	layout = new QFormLayout;
	layout->addRow("Network name:", name);
	layout->addRow("Neuron type:", neuron_type);
	layout->addRow("Number of layers:", n_layers);
	layout->addRow("Biased:", biased);

	trigger = new QPushButton("Create");
	bool x = connect(trigger, SIGNAL(clicked()), parent, SLOT(addNet()));
	layout->addWidget(trigger);

	setLayout(layout);
}

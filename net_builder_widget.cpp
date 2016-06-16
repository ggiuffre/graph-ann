#include "net_builder_widget.h"
#include <QLayoutItem>
#include <QLabel>

netBuilderWidget::netBuilderWidget(QWidget * parent) : QWidget(parent), layout(new QFormLayout), name(new QLineEdit), neuron_type(new QComboBox), n_layers(new QSpinBox), next(new QPushButton("Prosegui...")), trigger(new QPushButton("Crea")), new_net(nullptr)
{
	neuron_type->insertItem(0, "Sigmoide");
	neuron_type->insertItem(1, "Tangente Iperbolica");
	neuron_type->insertItem(2, "Arcotangente");

	n_layers->setMinimum(1);
	n_layers->setMaximum(8);

	layout->addRow("Nome della rete:", name);
	layout->addRow("Tipo di neurone:", neuron_type);
	layout->addRow("Numero di livelli:", n_layers);

	layout->addWidget(next);
	setLayout(layout);

	connect(next, SIGNAL(clicked()), this, SLOT(setLayers()));
}

void netBuilderWidget::setLayers()
{
	layout->removeWidget(next);
	delete next;

	name->setEnabled(false);
	neuron_type->setEnabled(false);
	n_layers->setEnabled(false);

	const QString type = neuron_type->currentText();
	if (type == "Sigmoide")
		new_net = new layeredSigmoidNet;
	else if (type == "Tangente Iperbolica")
		new_net = new layeredTanhNet;
	else if (type == "Arcotangente")
		new_net = new layeredAtanNet;

	QSpacerItem * spacer = new QSpacerItem(1, 20);
	layout->addItem(spacer);
	layout->addRow("Numero di unità per livello:", new QLabel);
	for (int i = 0; i < n_layers->value(); ++i)
	{
		layers_arch.push_back(new QSpinBox);
		layers_arch[i]->setMinimum(1);
		layers_arch[i]->setMaximum(64);
		layout->addRow("Livello " + QString::number(i + 1) + ":", layers_arch[i]);
	}

	layout->addWidget(trigger);
	connect(trigger, SIGNAL(clicked()), this, SLOT(addNet()));
}

void netBuilderWidget::addNet()
{
	for (auto it = layers_arch.begin(); it < layers_arch.end(); ++it)
		(*it)->setEnabled(false);

	if (new_net)
	{
		for (int i = 0; i < n_layers->value(); ++i)
			new_net->addLayer(layers_arch[i]->value());

		new_net->init(0.5f);
		new_net->save("./logica/nets/" + neuron_type->currentText().toStdString() + "/" + name->text().toStdString() + ".net");
	}
}

#include "data_builder_widget.h"
#include <QInputDialog>
#include <fstream>

dataBuilderWidget::dataBuilderWidget(QWidget * parent) : QWidget(parent), layout(new QFormLayout), input_buffer(new QTextEdit), target_buffer(new QTextEdit), next(new QPushButton("Aggiungi")), trigger(new QPushButton("Aggiungi e crea")), n_examples(0)
{
	layout->addRow("Input data:", new QLabel);
	layout->addWidget(input_buffer);
	layout->addRow("Desired output data:", new QLabel);
	layout->addWidget(target_buffer);

	layout->addWidget(next);
	connect(next, SIGNAL(clicked()), this, SLOT(addExample()));
	layout->addWidget(trigger);
	connect(trigger, SIGNAL(clicked()), this, SLOT(storeData()));

	setLayout(layout);
}

void dataBuilderWidget::addExample()
{
	unsigned int in_count = input_buffer->toPlainText().split(" ").filter(QRegularExpression("\\d")).size();
	unsigned int out_count = input_buffer->toPlainText().split(" ").filter(QRegularExpression("\\d")).size();
	if (n_examples == 0)
	{
		n_in = in_count;
		n_out = out_count;
	}
	n_examples++;
	tot_data += std::endl + input_buffer->toPlainText() + std::endl;
	tot_data += target_buffer->toPlainText() + std::endl;
}

void dataBuilderWidget::storeData()
{
	addExample();
	tot_data.insert(tot_data.begin(), num2str(n_examples) + " " + num2str(n_in) + " " + num2str(n_out) + " " );
	QString file_title = QInputDialog::getText(this, "Save File", "Datafile title:");
	ofstream result("./logica/data/" + file_title + ".data");
	result << tot_data;
}

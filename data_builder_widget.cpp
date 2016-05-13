#include "data_builder_widget.h"
#include <QRegularExpression>
#include <QInputDialog>
#include <QMessageBox>
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
	unsigned int in_count = input_buffer->toPlainText().split(" ").filter(QRegularExpression("\\d+")).size();
	unsigned int out_count = target_buffer->toPlainText().split(" ").filter(QRegularExpression("\\d+")).size();
	if (n_examples == 0)
	{
		n_in = in_count;
		n_out = out_count;
		tot_data += QString::number(n_examples) + " " + QString::number(n_in) + " " + QString::number(n_out);
	}
	else if (in_count != n_in || out_count != n_out)
	{
		QMessageBox err_box;
		QString err_msg = "Il numero di elementi deve essere coerente con gli esempi precedenti:";
		if (in_count != n_in)
			err_msg += "\nhai immesso" + QString::number(in_count) + "elementi di input anziché" + QString::number(n_in);
		if (out_count != n_out)
			err_msg += "\nhai immesso" + QString::number(out_count) + "elementi di output anziché" + QString::number(n_out);
		err_box.setText(err_msg);
		err_box.exec();
		return;
	}

	n_examples++;
	tot_data += "\n" + input_buffer->toPlainText() + "\n";
	tot_data += target_buffer->toPlainText() + "\n";
	input_buffer->clear();
	target_buffer->clear();
}

void dataBuilderWidget::storeData()
{
	addExample();
	QString file_title = QInputDialog::getText(this, "Save File", "Datafile title:");
	std::ofstream result("./logica/data/" + file_title.toStdString() + ".data");
	result << tot_data.toStdString();
	result.close();
}

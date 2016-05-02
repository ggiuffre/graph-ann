#include "net_runner_widget.h"
#include <QLabel>

netRunnerWidget::netRunnerWidget(const QString t, QWidget * parent) : QWidget(parent), title(t), layout(new QFormLayout), trigger(new QPushButton("Calcola")), result(new QLabel)
{
	prova = 0.90f;
	layout->addRow("Input:", new QLineEdit);

	layout->addWidget(trigger);
	connect(trigger, SIGNAL(clicked()), this, SLOT(calculate()));

	layout->addRow(result);

	setLayout(layout);

}

void netRunnerWidget::calculate()
{
	prova += 0.1f;
	result->setText(title + ": " + QString::number(prova));
	update();
}

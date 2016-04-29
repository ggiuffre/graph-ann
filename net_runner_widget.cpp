#include "net_runner_widget.h"
#include <QLabel>

netRunnerWidget::netRunnerWidget(const QString t, QWidget * parent) : QWidget(parent), title(t)
{
	prova = 0.90f;
	layout = new QFormLayout;
	layout->addRow("Input:", new QLineEdit);

	trigger = new QPushButton("Calcola");
	layout->addWidget(trigger);
	connect(trigger, SIGNAL(clicked()), this, SLOT(calculate()));

	result = new QLabel;
	layout->addRow(result);

	setLayout(layout);

}

void netRunnerWidget::setTitle(const QString t)
{
//	title = t;
//	update();
}

void netRunnerWidget::calculate()
{
	prova += 0.1f;
	result->setText(title + ": " + QString::number(prova));
	update();
}

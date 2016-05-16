#include "net_runner_widget.h"
#include <QLabel>
#include <QMenuBar>

netRunnerWidget::netRunnerWidget(const QString t, QWidget * parent) : QWidget(parent), title(t), layout(new QFormLayout), trigger(new QPushButton("Calcola")), result(new QLabel)
{
	QMenuBar * mbar = new QMenuBar;
	QMenu * menu = new QMenu("Menù");
	menu->addAction("Allena");
	menu->addAction("Collauda");
	mbar->addMenu(menu);
	layout->addWidget(mbar);

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

#include "net_runner_widget.h"
#include <QSpacerItem>

netRunnerWidget::netRunnerWidget(QWidget * parent) : QWidget(parent)
{
	boh = new QSpinBox;
	boh->setMinimum(1);
	boh->setMaximum(240);

	layout = new QFormLayout;
	layout->addRow("boh:", new QLineEdit);
	layout->addRow("kajhskja:", boh);

	trigger = new QPushButton("Run");
	layout->addWidget(trigger);

	setLayout(layout);

}

void netRunnerWidget::calculate()
{
	return;
}
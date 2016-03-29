#include "net_runner_widget.h"
#include <QSpacerItem>
#include <QLabel>

netRunnerWidget::netRunnerWidget(QWidget * parent, const QString t) : QWidget(parent), title(t)
{
	boh = new QSpinBox;
	boh->setMinimum(1);
	boh->setMaximum(240);

	layout = new QFormLayout;
	if (title == "")
		layout->addRow("title:", new QLineEdit);
	else
		layout->addRow(title, new QLabel);
	layout->addRow("kajhskja:", boh);

	trigger = new QPushButton("Run");
	layout->addWidget(trigger);

	setLayout(layout);

}

void netRunnerWidget::set_title(const QString t)
{
	title = t;
}

void netRunnerWidget::calculate()
{
	return;
}

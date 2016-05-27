#include "net_runner_widget.h"
#include <vector>

netRunnerWidget::netRunnerWidget(const QString t, QWidget * parent) : QWidget(parent), title(t), layout(new QFormLayout), input_text(new QLineEdit), trigger(new QPushButton("Calcola")), result(new QLabel), net(title == "" ? nullptr : new layeredBiasedNet("logica/nets/" + title.toStdString()))
{
	prova = 0.90f;
	layout->addRow("Input:", input_text);

	layout->addWidget(trigger);
	connect(trigger, SIGNAL(clicked()), this, SLOT(calculate()));

	layout->addRow(result);

	setLayout(layout);

}

void netRunnerWidget::calculate()
{
	if (net)
	{
//		std::vector<float> input = input_text->toPlainText().split(" ").filter(QRegularExpression("\\d+"));
//		std::vector<float> ans = (*net)();
		prova += 0.1f;
		result->setText(title + ": " + QString::number(prova));
		update();
	}
}

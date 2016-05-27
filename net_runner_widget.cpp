#include "net_runner_widget.h"
#include <QStringList>
#include <vector>

netRunnerWidget::netRunnerWidget(const QString t, QWidget * parent) : QWidget(parent), title(t), layout(new QFormLayout), input_text(new QTextEdit), trigger(new QPushButton("Calcola")), result(new QLabel), net(new layeredBiasedNet("logica/nets/" + title.toStdString() + ".net")) // assume che t sia valido
{
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
		QStringList input_list = input_text->toPlainText().split(" ", QString::SkipEmptyParts).filter(QRegularExpression("\\d+")); // QInputValidator ?
		std::vector<float> input;
		for(auto it = input_list.begin(); it < input_list.end(); ++it)
    		input.push_back(it->toFloat());
		std::vector<float> ans = (*net)();

		QString output_list;
		for (auto it = ans.begin(); it < ans.end(); ++it)
			output_list += QString::number(*it) + " ";
		result->setText(output_list);
		update();
	}
}

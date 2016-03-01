#ifndef NET_RUNNER_WIDGET_H
#define NET_RUNNER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>

class netRunnerWidget : public QWidget
{
	Q_OBJECT

private:
	QPushButton * trigger;
	QSpinBox * boh;
	QFormLayout * layout;

protected slots:
	void calculate();

public:
	netRunnerWidget(QWidget * parent = nullptr);
};

#endif
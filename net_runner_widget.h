#ifndef NET_RUNNER_WIDGET_H
#define NET_RUNNER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>

class netRunnerWidget : public QWidget
{
	Q_OBJECT

private:
	QString title;
	QFormLayout * layout;
	QPushButton * trigger;
	QLabel * result;
	float prova;

protected slots:
	void calculate();

public:
	netRunnerWidget(QString t, QWidget * parent = nullptr);
};

#endif

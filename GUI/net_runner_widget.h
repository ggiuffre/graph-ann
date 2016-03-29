#ifndef NET_RUNNER_WIDGET_H
#define NET_RUNNER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

class netRunnerWidget : public QWidget
{
	Q_OBJECT

private:
	QPushButton * trigger;
	QSpinBox * boh;
	QFormLayout * layout;
	QString title;

protected slots:
	void calculate();

public:
	netRunnerWidget(QWidget * parent = nullptr, QString t = "");
	void set_title(QString t);
};

#endif

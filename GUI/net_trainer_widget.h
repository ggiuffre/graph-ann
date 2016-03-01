#ifndef NET_TRAINER_WIDGET_H
#define NET_TRAINER_WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QFormLayout>
#include <QLineEdit>

class netTrainerWidget : public QWidget
{
	Q_OBJECT

private:
	QSpinBox * n_epochs;
	QFormLayout * layout;

public:
	netTrainerWidget(QWidget * parent = nullptr);
};

#endif
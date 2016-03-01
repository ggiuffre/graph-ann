#ifndef NET_BUILDER_WIDGET_H
#define NET_BUILDER_WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

class netBuilderWidget : public QWidget
{
	Q_OBJECT

private:
	QLineEdit * name;
	QComboBox * neuron_type;
	QSpinBox * n_layers;
	QCheckBox * biased;
	QPushButton * trigger;
	QFormLayout * layout;

public:
	netBuilderWidget(QWidget * parent = nullptr);
};

#endif
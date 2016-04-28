#ifndef NET_BUILDER_WIDGET_H
#define NET_BUILDER_WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

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

public slots:
	void netAdded();

signals:
	void newNet(QString t, QString type, int nl, bool b);

public:
	netBuilderWidget(QWidget * parent = nullptr);
};

#endif

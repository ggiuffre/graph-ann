#ifndef NET_BUILDER_WIDGET_H
#define NET_BUILDER_WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <vector>
#include "logica/nets.h"

class netBuilderWidget : public QWidget
{
	Q_OBJECT

private:
	QFormLayout * layout;
	QLineEdit * name;
	QComboBox * neuron_type;
	QSpinBox * n_layers;
	QPushButton * next, * trigger;
	layeredBiasedNet * new_net;
	std::vector<QSpinBox *> layers_arch;

public slots:
	void setLayers();
	void addNet();

public:
	netBuilderWidget(QWidget * parent = nullptr);
};

#endif

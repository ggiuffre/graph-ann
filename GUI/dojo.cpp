#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>
#include "dojo.h"
#include <QMessageBox>

dojo::dojo()
{
	setWindowTitle("Neural Network Training Dojo");

	net_menu = new QMenu("Net");
	net_menu->addAction("New Network", this, SLOT(netBuilder()));
	net_menu->addAction("Train Network", this, SLOT(netTrainer()));
	net_menu->addAction("Open Network...", this, SLOT(netRunner("")));
	menu_bar = new QMenuBar;
	menu_bar->addMenu(net_menu);
	setMenuBar(menu_bar);

//	intro = [presentazione di come si usa l'app... disegni, frecce... boh]
	builder = new netBuilderWidget;
	trainer = new netTrainerWidget;
	runner = new netRunnerWidget;
	ctrl = new QStackedWidget(this);
//	ctrl->addWidget(intro);
	ctrl->addWidget(builder);
	ctrl->addWidget(trainer);
	ctrl->addWidget(runner);

	nets_dock = new nets_list(this);

	setCentralWidget(ctrl);
	addDockWidget(Qt::LeftDockWidgetArea, nets_dock);
}

QSize dojo::minimumSizeHint() const
{
	return QSize(600, 337);
}

QSize dojo::sizeHint() const
{
	return QSize(810, 500);
}

void dojo::netBuilder()
{
	ctrl->setCurrentWidget(builder);
}

void dojo::netTrainer()
{
	ctrl->setCurrentWidget(trainer);
}

void dojo::netRunner(const QString t)
{
	runner->set_title(t);
	QMessageBox msgBox;
	msgBox.setText(t);
	msgBox.exec();

	ctrl->setCurrentWidget(runner);
}

void dojo::addNet()
{
//	std::string name = builder->name();
	return;
}

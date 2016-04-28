#include "palestra.h"
//#include "ann_module/layered_biased_net.h"
//#include "ann_module/layered_net.h"
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>

#include <QMessageBox>	// debugging

palestra::palestra()
{
	setWindowTitle("Palestra per reti neurali");

	net_menu = new QMenu("Net");
	net_menu->addAction("New Network", this, SLOT(netBuilder()));
	net_menu->addAction("Train Network", this, SLOT(netTrainer()));
//	net_menu->addAction("Open Network...", this, SLOT(netRunner("")));
	menu_bar = new QMenuBar;
	menu_bar->addMenu(net_menu);
	setMenuBar(menu_bar);

//	intro = [presentazione di come si usa l'app... disegni, frecce... boh]
	builder = new netBuilderWidget;
	connect(builder, SIGNAL(newNet(QString, QString, int, bool)), this, SLOT(netAdded(QString, QString, int, bool)));
	ctrl = new QStackedWidget(this);
	trainer = new netTrainerWidget;

//	ctrl->addWidget(intro);
	ctrl->addWidget(builder);
	ctrl->addWidget(trainer);

	nets_dock = new nets_list(this);
	connect(nets_dock, SIGNAL(netSelected(QString)), this, SLOT(netRunner(QString)));

	setCentralWidget(ctrl);
	addDockWidget(Qt::LeftDockWidgetArea, nets_dock);
}

QSize palestra::minimumSizeHint() const
{
	return QSize(600, 337);
}

QSize palestra::sizeHint() const
{
	return QSize(810, 500);
}

void palestra::netBuilder()
{
	ctrl->setCurrentWidget(builder);
}

void palestra::netTrainer()
{
	ctrl->setCurrentWidget(trainer);
}

void palestra::netRunner(const QString t)
{
	runner = new netRunnerWidget(t);
	ctrl->addWidget(runner);
	ctrl->setCurrentWidget(runner);
}

void palestra::netAdded(const QString t, const QString type, const int nl, const bool biased)
{
	auto x = 3;
}

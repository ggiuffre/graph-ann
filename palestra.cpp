#include "palestra.h"
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QMessageBox>	// debugging

palestra::palestra() : menu_bar(new QMenuBar), net_menu(new QMenu("Rete")), data_menu(new QMenu("Dati")),
			ctrl(new QStackedWidget(this)), builder(new netBuilderWidget), trainer(new netTrainerWidget),
			runner(nullptr), data_builder(nullptr), nets_dock(new nets_list(this))
{
	setWindowTitle("Palestra per reti neurali");

	net_menu->addAction("Nuova Rete", this, SLOT(netBuilder()));
	net_menu->addAction("Allena una rete", this, SLOT(netTrainer()));
	menu_bar->addMenu(net_menu);

	data_menu->addAction("Nuovo foglio di esempi", this, SLOT(dataBuilder()));
	menu_bar->addMenu(data_menu);

	setMenuBar(menu_bar);

//	intro = [presentazione di come si usa l'app... disegni, frecce... boh]

	connect(builder, SIGNAL(newNet(layeredBiasedNet *)), this, SLOT(addNet(layeredBiasedNet *)));
	connect(nets_dock, SIGNAL(netSelected(QString)), this, SLOT(netRunner(QString)));

//	ctrl->addWidget(intro);
	ctrl->addWidget(builder);
	ctrl->addWidget(trainer);

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
	if (runner)
		delete runner;
	runner = new netRunnerWidget(t);
	ctrl->addWidget(runner);
	ctrl->setCurrentWidget(runner);
}

void palestra::dataBuilder()
{
	if (data_builder)
		delete data_builder;
	data_builder = new dataBuilderWidget();
	ctrl->addWidget(data_builder);
	ctrl->setCurrentWidget(data_builder);
}

void palestra::addNet(layeredBiasedNet * const new_net)
{
	// ...
}

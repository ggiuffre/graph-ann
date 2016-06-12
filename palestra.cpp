#include "palestra.h"

palestra::palestra() : menu_bar(new QMenuBar), net_menu(new QMenu("Rete")), data_menu(new QMenu("Dati")),
			ctrl(new QStackedWidget(this)), net_interface(nullptr), net_builder(new netBuilderWidget), data_builder(nullptr), nets_dock(new nets_list(this))
{
	setWindowTitle("Piattaforma per allenare reti neurali");
//	setStyleSheet("QMainWindow {border-image: url(./sfondo.jpg); border-width: 200px;}");

	net_menu->addAction("Nuova Rete", this, SLOT(showNetBuilder()));
	menu_bar->addMenu(net_menu);
	data_menu->addAction("Nuovo foglio di esempi", this, SLOT(showDataBuilder()));
	menu_bar->addMenu(data_menu);
	setMenuBar(menu_bar);

	connect(nets_dock, SIGNAL(netSelected(QString)), this, SLOT(showNetInterface(QString)));
	addDockWidget(Qt::LeftDockWidgetArea, nets_dock);

	ctrl->addWidget(net_builder);
	setCentralWidget(ctrl);
}

QSize palestra::minimumSizeHint() const
{
	return QSize(600, 337);
}

QSize palestra::sizeHint() const
{
	return QSize(810, 500);
}

void palestra::showNetBuilder()
{
	ctrl->setCurrentWidget(net_builder);
}

void palestra::showNetInterface(const QString t)
{
	if (net_interface)
		delete net_interface;
	net_interface = new netInterface(t);
	ctrl->addWidget(net_interface);
	ctrl->setCurrentWidget(net_interface);
}

void palestra::showDataBuilder()
{
	if (data_builder)
		delete data_builder;
	data_builder = new dataBuilderWidget();
	ctrl->addWidget(data_builder);
	ctrl->setCurrentWidget(data_builder);
}

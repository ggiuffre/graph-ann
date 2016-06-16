#include "corn_window.h"

CornWindow::CornWindow() : menu_bar(new QMenuBar), net_menu(new QMenu("Rete")), data_menu(new QMenu("Dati")),
			ctrl(new QStackedWidget(this)), net_interface(nullptr), net_builder(new netBuilderWidget), data_builder(nullptr), internet_interface(new internetInterface), nets_dock(new netsList(this))
{
	setWindowTitle("CORN");

	net_menu->addAction("Nuova Rete", this, SLOT(showNetBuilder()));
	net_menu->addAction("Inter-rete", this, SLOT(showInternetBuilder()));
	menu_bar->addMenu(net_menu);
	data_menu->addAction("Nuovo Foglio di Esempi", this, SLOT(showDataBuilder()));
	menu_bar->addMenu(data_menu);
	setMenuBar(menu_bar);

	connect(nets_dock, SIGNAL(netSelected(QFileInfo)), this, SLOT(showNetInterface(QFileInfo)));
	connect(nets_dock, SIGNAL(netAddedToInternet(QFileInfo)), internet_interface, SLOT(addNet(QFileInfo)));
	addDockWidget(Qt::LeftDockWidgetArea, nets_dock);

	ctrl->addWidget(net_builder);
	ctrl->addWidget(internet_interface);
	setCentralWidget(ctrl);
}

QSize CornWindow::sizeHint() const
{
	return QSize(810, 500);
}

void CornWindow::showNetBuilder()
{
	ctrl->setCurrentWidget(net_builder);
}

void CornWindow::showInternetBuilder()
{
	ctrl->setCurrentWidget(internet_interface);
}

void CornWindow::showNetInterface(const QFileInfo i)
{
	if (net_interface)
		delete net_interface;
	net_interface = new netInterface(i);
	ctrl->addWidget(net_interface);
	ctrl->setCurrentWidget(net_interface);
}

void CornWindow::showDataBuilder()
{
	if (data_builder)
		delete data_builder;
	data_builder = new dataBuilderWidget();
	ctrl->addWidget(data_builder);
	ctrl->setCurrentWidget(data_builder);
}

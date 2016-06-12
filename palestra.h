#ifndef PALESTRA_H
#define PALESTRA_H

#include "net_interface.h"
#include "net_builder_widget.h"
#include "data_builder_widget.h"
#include "nets_list.h"
#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>
#include <QString>

class palestra : public QMainWindow
{
	Q_OBJECT

private:
	QMenuBar * menu_bar;
	QMenu * net_menu;
	QMenu * data_menu;

	QStackedWidget * ctrl;
	netInterface * net_interface;
	netBuilderWidget * net_builder;
	dataBuilderWidget * data_builder;
	nets_list * nets_dock;

public slots:
	void showNetInterface(QString t);
	void showNetBuilder();
	void showDataBuilder();

public:
	palestra();
	QSize minimumSizeHint() const Q_DECL_OVERRIDE;
	QSize sizeHint() const Q_DECL_OVERRIDE;
};

#endif

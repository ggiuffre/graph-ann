#ifndef CORN_WINDOW_H
#define CORN_WINDOW_H

#include "net_interface.h"
#include "net_builder_widget.h"
#include "data_builder_widget.h"
#include "internet_interface.h"
#include "nets_list.h"
#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>
#include <QFileInfo>

class CornWindow : public QMainWindow
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
	internetInterface * internet_interface;
	netsList * nets_dock;

public:
	CornWindow();
	QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
	void showNetInterface(QFileInfo i);
	void showNetBuilder();
	void showInternetBuilder();
	void showDataBuilder();
};

#endif

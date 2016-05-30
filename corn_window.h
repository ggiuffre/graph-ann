#ifndef CORN_WINDOW_H
#define CORN_WINDOW_H

#include "net_interface.h"
#include "net_builder_widget.h"
#include "data_builder_widget.h"
#include "nets_list.h"
#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>
#include <QString>

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
	netsList * nets_dock;

public:
	CornWindow();
	QSize minimumSizeHint() const Q_DECL_OVERRIDE;
	QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
	void showNetInterface(QString t);
	void showNetBuilder();
	void showInternetBuilder();
	void showDataBuilder();
};

#endif

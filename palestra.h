#ifndef PALESTRA_H
#define PALESTRA_H

#include "net_builder_widget.h"
#include "net_trainer_widget.h"
#include "net_runner_widget.h"
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
	netBuilderWidget * builder;
	netTrainerWidget * trainer;
	netRunnerWidget * runner;
	dataBuilderWidget * data_builder;

	nets_list * nets_dock;

public slots:
	void netBuilder();
	void netTrainer();
	void netRunner(QString t);
	void dataBuilder();
	void netAdded(QString t, QString type, int nl, bool b);

public:
	palestra();
	QSize minimumSizeHint() const Q_DECL_OVERRIDE;
	QSize sizeHint() const Q_DECL_OVERRIDE;
};

#endif

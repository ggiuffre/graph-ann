#ifndef INTERNET_INTERFACE_H
#define INTERNET_INTERFACE_H

#include "logica/internetwork.h"
#include "net_runner_widget.h"
#include <QFileInfo>
#include <QTableWidget>
#include <QPushButton>
#include <QFormLayout>

class internetInterface : public QWidget
{
	Q_OBJECT

private:
	internetwork * internet;
	QTableWidget * adj_matrix;
	QPushButton * trigger;
	QFormLayout * layout;

	netRunnerWidget * runner;

public:
	internetInterface(QWidget * parent = nullptr);
	~internetInterface();

public slots:
	void toggle_link(int row, int column);
	void addNet(QFileInfo net_info);
	void showRunner();
};

#endif
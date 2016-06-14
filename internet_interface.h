#ifndef INTERNET_INTERFACE_H
#define INTERNET_INTERFACE_H

#include <QFileInfo>
#include <QTableWidget>
#include <QPushButton>
#include <QFormLayout>

class internetInterface : public QWidget
{
	Q_OBJECT

private:
	QTableWidget * adj_matrix;
	QFormLayout * layout;

public:
	internetInterface(QWidget * parent = nullptr);

public slots:
	void link(int row, int column);
	void addNet(QFileInfo net_info);
	void createInternet();
};

#endif
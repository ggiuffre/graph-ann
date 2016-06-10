#ifndef INTERNET_INTERFACE_H
#define INTERNET_INTERFACE_H

#include <QFileInfo>
#include <QTableWidget>
#include <QCheckBox>
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
	void keep_checked(int row, int column, int x, int y);
	void addNet(QFileInfo net_info);
};

#endif
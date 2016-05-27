#ifndef NETS_LIST
#define NETS_LIST

#include <QDockWidget>
#include <QFileSystemModel>
#include <QListView>
#include <QString>

class netsList : public QDockWidget
{
	Q_OBJECT

private:
	QFileSystemModel * fs;
	QListView * files;

public slots:
	void selectNet(QModelIndex i);

signals:
	void netSelected(QString t);

public:
	netsList(QWidget * parent = nullptr);
};

#endif

#ifndef NETS_LIST
#define NETS_LIST

#include <QDockWidget>
#include <QFileSystemModel>
#include <QListView>

class netsList : public QDockWidget
{
	Q_OBJECT

private:
	QFileSystemModel * fs;
	QListView * files;

public:
	netsList(QWidget * parent = nullptr);

public slots:
	void selectNet(QModelIndex i);

signals:
	void netSelected(QFileInfo net_info);
	void netAddedToInternet(QFileInfo net_info);
};

#endif

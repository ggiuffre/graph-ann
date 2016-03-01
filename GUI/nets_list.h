#ifndef NETS_LIST
#define NETS_LIST

#include <QWidget>
#include <QDockWidget>
#include <QFileSystemModel>
#include <QListView>

class nets_list : public QDockWidget
{
	Q_OBJECT

private:
	QFileSystemModel * fs;
	QListView * files;

public:
	nets_list(QWidget * parent = nullptr);
};

#endif
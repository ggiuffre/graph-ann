#ifndef NETS_LIST
#define NETS_LIST

#include <QDockWidget>
#include <QLabel>
#include <QFileSystemModel>
#include <QListView>
#include <QString>

class nets_list : public QDockWidget
{
	Q_OBJECT

private:
	QLabel * header;
	QFileSystemModel * fs;
	QListView * files;

public slots:
	void selectNet(QModelIndex i);

signals:
	void netSelected(QString t);

public:
	nets_list(QWidget * parent = nullptr);
};

#endif

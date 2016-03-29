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

protected slots:
	void NetClicked(QModelIndex i) const;
	void prova(QString t);

signals:
	void NetSelected(QString t) const;

public:
	nets_list(QWidget * parent = nullptr);
};

#endif

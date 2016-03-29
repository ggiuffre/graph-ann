#include "nets_list.h"
#include <QListWidgetItem>
#include <QMessageBox>

nets_list::nets_list(QWidget * parent) : QDockWidget(parent)
{
	header = new QLabel(this);
	header->setText("Open...");
	setTitleBarWidget(header);

	fs = new QFileSystemModel(this);
	fs->setRootPath(QDir::currentPath());

	files = new QListView(this);
	files->setModel(fs);
	files->setRootIndex(fs->index("/Users/giorgiogiuffre/Documents/C++/oop-ann/nets/"));
	files->setGridSize({90, 30});
	connect(files, SIGNAL(clicked(QModelIndex)), this, SLOT(NetClicked(QModelIndex)));
	connect(this, SIGNAL(NetSelected(QString)), parent, SLOT(NetRunner(QString)));
//	connect(this, SIGNAL(NetSelected(QString)), this, SLOT(prova(QString)));

	setFeatures(QDockWidget::DockWidgetClosable);
	files->setMinimumWidth(90);
	files->setMaximumWidth(180);
	setWidget(files);
}

void nets_list::NetClicked(const QModelIndex i) const
{
	QString title = fs->fileName(i);
	emit NetSelected(title);
}

void nets_list::prova(const QString title)
{
	QMessageBox msgBox;
	msgBox.setText(title);
	msgBox.exec();
}

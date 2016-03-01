#include "nets_list.h"

nets_list::nets_list(QWidget * parent) : QDockWidget(parent)
{
	fs = new QFileSystemModel(this);
	fs->setRootPath(QDir::currentPath());

	files = new QListView(this);
	files->setModel(fs);
	files->setRootIndex(fs->index("/Users/giorgiogiuffre/Documents/C++/oop-ann/nets/"));

	setFeatures(QDockWidget::DockWidgetClosable);
	files->setMinimumWidth(90);
	files->setMaximumWidth(180);
	setWidget(files);
}
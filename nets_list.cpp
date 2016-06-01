#include "nets_list.h"

netsList::netsList(QWidget * parent) : QDockWidget(parent), fs(new QFileSystemModel(this)), files(new QListView(this))
{
	setFeatures(NoDockWidgetFeatures);

	fs->setRootPath(QDir::currentPath());
	fs->setFilter(QDir::AllEntries | QDir::NoDot);
	files->setModel(fs);
	files->setRootIndex(fs->index("./logica/nets/"));
	files->setGridSize({90, 30});
	connect(files, SIGNAL(clicked(QModelIndex)), this, SLOT(selectNet(QModelIndex)));

	files->setMinimumWidth(90);
	files->setMaximumWidth(180);
	setWidget(files);
}

void netsList::selectNet(const QModelIndex i)
{
	if (fs->fileInfo(i).isDir())
		files->setRootIndex(fs->index(fs->fileInfo(i).absoluteFilePath()));
	else
		emit netSelected(fs->fileInfo(i));
//		emit netSelected(fs->fileInfo(i).completeBaseName());
}

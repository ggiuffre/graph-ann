#include "nets_list.h"

netsList::netsList(QWidget * parent) : QDockWidget(parent), fs(new QFileSystemModel(this)), files(new QListView(this))
{
	setFeatures(NoDockWidgetFeatures);

	fs->setRootPath(QDir::currentPath());
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
	emit netSelected(fs->fileInfo(i).completeBaseName());
}

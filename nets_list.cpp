#include "nets_list.h"
#include <QListWidgetItem>

nets_list::nets_list(QWidget * parent) : QDockWidget(parent), header(new QLabel(this)), fs(new QFileSystemModel(this)), files(new QListView(this))
{
	header->setText("Apri...");
	setTitleBarWidget(header);

	fs->setRootPath(QDir::currentPath());

	files->setModel(fs);
	files->setRootIndex(fs->index("./logica/nets/"));
	files->setGridSize({90, 30});
	connect(files, SIGNAL(clicked(QModelIndex)), this, SLOT(selectNet(QModelIndex)));

	setFeatures(QDockWidget::DockWidgetClosable);
	files->setMinimumWidth(90);
	files->setMaximumWidth(180);
	setWidget(files);
}

void nets_list::selectNet(const QModelIndex i)
{
	emit netSelected(fs->fileName(i));
}

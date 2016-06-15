#include "internet_interface.h"
#include "net_interface.h"
#include "logica/nets.h"
#include <QMessageBox>
#include <QString>

internetInterface::internetInterface(QWidget * parent) : QWidget(parent), internet(new internetwork), adj_matrix(new QTableWidget(0, 0)), trigger(new QPushButton("Collauda...")), layout(new QFormLayout), runner(nullptr)
{
	connect(adj_matrix, SIGNAL(cellClicked(int, int)), this, SLOT(link(int, int)));
	layout->addWidget(adj_matrix);

	connect(trigger, SIGNAL(clicked()), this, SLOT(showRunner()));
	layout->addWidget(trigger);

	setLayout(layout);
}

internetInterface::~internetInterface()
{
	delete runner;
	delete internet;
}

void internetInterface::link(const int row, const int column)
{
	if (row != column)
	{
		if (adj_matrix->item(row, column)->background() != QBrush(QColor(0, 0, 0)))
		{
			adj_matrix->item(row, column)->setBackground(QBrush(QColor(0, 0, 0)));
			internet->link(column, row);
//			QMessageBox::warning(this, "...", QString::number((*internet)({1, 0, 1, 1})[0]));
		}
		else
		{
			adj_matrix->item(row, column)->setBackground(QBrush(QColor(255, 255, 255)));
			internet->unlink(column, row);
		}
	}
}

void internetInterface::addNet(const QFileInfo net_info)
{
	adj_matrix->insertRow(adj_matrix->rowCount());
	adj_matrix->insertColumn(adj_matrix->columnCount());

	unsigned int cur_net_index = adj_matrix->rowCount() - 1;

	QTableWidgetItem * header = new QTableWidgetItem(net_info.baseName());
	adj_matrix->setVerticalHeaderItem(cur_net_index, header);
	adj_matrix->setHorizontalHeaderItem(cur_net_index, header);

	for (unsigned int i = 0; i < cur_net_index; ++i)
	{
		adj_matrix->setItem(i, cur_net_index, new QTableWidgetItem);
		adj_matrix->setItem(cur_net_index, i, new QTableWidgetItem);
		adj_matrix->item(i, cur_net_index)->setFlags(Qt::ItemIsUserCheckable);
		adj_matrix->item(cur_net_index, i)->setFlags(Qt::ItemIsUserCheckable);
	}
	adj_matrix->setItem(cur_net_index, cur_net_index, new QTableWidgetItem);
	adj_matrix->item(cur_net_index, cur_net_index)->setFlags(Qt::NoItemFlags);

	layeredBiasedNet * new_net = netInterface::fromFile(net_info);
	internet->push_back(new_net);
}

void internetInterface::showRunner()
{
	layeredSigmoidNet net_1("/home/0/2014/ggiuffre/Documents/graph-ann/logica/nets/Sigmoide/and.net");
	layeredSigmoidNet net_2("/home/0/2014/ggiuffre/Documents/graph-ann/logica/nets/Sigmoide/or.net");
	layeredSigmoidNet net_3("/home/0/2014/ggiuffre/Documents/graph-ann/logica/nets/Sigmoide/xor.net");

	internetwork prova;
	prova.push_back(&net_1);
	prova.push_back(&net_2);
	prova.push_back(&net_3);
	prova.link(0, 2);
	prova.link(1, 2);

	QMessageBox::warning(this, "...", QString::number(prova({0, 0, 1, 1})[0]));
	runner = new netRunnerWidget(internet);
	runner->show();
}

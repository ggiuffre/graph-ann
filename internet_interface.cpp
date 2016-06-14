#include "internet_interface.h"

internetInterface::internetInterface(QWidget * parent) : QWidget(parent), adj_matrix(new QTableWidget(0, 0)), trigger(new QPushButton("Collauda...")), layout(new QFormLayout)
{
	connect(adj_matrix, SIGNAL(cellClicked(int, int)), this, SLOT(link(int, int)));
	layout->addWidget(adj_matrix);

	connect(trigger, SIGNAL(clicked()), this, SLOT(createInternet()));
	layout->addWidget(trigger);

	setLayout(layout);
}

void internetInterface::link(const int row, const int column)
{
	if (adj_matrix->item(row, column))
	{
		if (adj_matrix->item(row, column)->background() != QBrush(QColor(0, 0, 0)))
			adj_matrix->item(row, column)->setBackground(QBrush(QColor(0, 0, 0)));
		else
			adj_matrix->item(row, column)->setBackground(QBrush(QColor(255, 255, 255)));
	}
}

void internetInterface::addNet(const QFileInfo net_info)
{
	adj_matrix->insertRow(adj_matrix->rowCount());
	adj_matrix->insertColumn(adj_matrix->columnCount());

	QTableWidgetItem * header = new QTableWidgetItem(net_info.baseName());
	adj_matrix->setVerticalHeaderItem(adj_matrix->rowCount() - 1, header);
	adj_matrix->setHorizontalHeaderItem(adj_matrix->columnCount() - 1, header);

	for (int i = 0; i < adj_matrix->rowCount() - 1; ++i)
		adj_matrix->setItem(i, adj_matrix->columnCount() - 1, new QTableWidgetItem);
	for (int i = 0; i < adj_matrix->columnCount() - 1; ++i)
		adj_matrix->setItem(adj_matrix->rowCount() - 1, i, new QTableWidgetItem);
}

void internetInterface::createInternet()
{
	// ...
}

#include "internet_interface.h"

internetInterface::internetInterface(QWidget * parent) : QWidget(parent), adj_matrix(new QTableWidget(0, 0)), layout(new QFormLayout)
{
//	QTableWidgetItem * cell = new QTableWidgetItem("abc");
//	adj_matrix->setItemPrototype(cell);
//	connect(adj_matrix, SIGNAL(cellClicked(int, int)), adj_matrix, SLOT(link(int, int)));
	connect(adj_matrix, SIGNAL(currentCellChanged(int, int, int, int)), adj_matrix, SLOT(keep_checked(int, int, int, int)));

	layout->addWidget(adj_matrix);
	setLayout(layout);
}

/*void internetInterface::link(int row, int column)
{
	adj_matrix->item(row, column)->setSelected(true);
}*/

void internetInterface::keep_checked(int cur_r, int cur_c, int prev_r, int prev_c)
{
	adj_matrix->item(cur_r, cur_c)->setSelected(true);
	adj_matrix->item(prev_r, prev_c)->setSelected(true);
}

void internetInterface::addNet(const QFileInfo net_info)
{
	adj_matrix->insertRow(adj_matrix->rowCount());
	adj_matrix->insertColumn(adj_matrix->columnCount());

	QTableWidgetItem * header = new QTableWidgetItem(net_info.baseName());
	adj_matrix->setVerticalHeaderItem(adj_matrix->rowCount() - 1, header);
	adj_matrix->setHorizontalHeaderItem(adj_matrix->columnCount() - 1, header);

//	QTableWidgetItem * newItem = new QTableWidgetItem("rete");
	adj_matrix->setItem(adj_matrix->rowCount() - 1, adj_matrix->columnCount() - 1, 0);
}

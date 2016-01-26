#include <QApplication>
#include <QMouseEvent>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include "lcdrange.h"
#include "lcdgrid.h"
#include "calc.h"

gameField::gameField(QWidget * parent) : QWidget(parent)
{
	setMouseTracking(true);

	calcWindow * w_2 = new calcWindow;
	QPushButton * calc = new QPushButton(tr("Compute"), this);
	connect(calc, SIGNAL(clicked()), w_2, SLOT(show()));

	QPushButton * quit = new QPushButton(tr("Quit"), this);
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

	QGridLayout * grid = new QGridLayout;

	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			LCDRange * range = new LCDRange;
			grid->addWidget(range, row, col);
		}
	}

	QVBoxLayout * vblayout = new QVBoxLayout;
	vblayout->addWidget(quit);
	vblayout->addWidget(calc);
	vblayout->addLayout(grid);
	setLayout(vblayout);
}

void gameField::mouseMoveEvent(QMouseEvent * event)
{
	QPoint mouse_coords = event->pos();
}
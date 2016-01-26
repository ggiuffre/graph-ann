#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "calc.h"

calcWindow::calcWindow(QWidget * parent) : QWidget(parent)
{
	setWindowTitle("Computation");
	resize(200, 120);
	QLabel * num_display = new QLabel;
	num_display->setNum(7.4);
	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(num_display);
	setLayout(layout);

	QPushButton * quit = new QPushButton(tr("Back"), this);
	connect(quit, SIGNAL(clicked()), this, SLOT(close()));
}
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include "lcdrange.h"

LCDRange::LCDRange(QWidget * parent) : QWidget(parent)
{
	QLabel * num_display = new QLabel;
	num_display->setNum(0);
	slider = new QSlider(Qt::Horizontal);
	slider->setRange(0, 99);
	slider->setValue(0);
	connect(slider, SIGNAL(valueChanged(int)), num_display, SLOT(setNum(int)));
	connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));
	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(num_display);
	layout->addWidget(slider);
	setLayout(layout);
}

int LCDRange::value() const
{
	return slider->value();
}

void LCDRange::setValue(int v)
{
	slider->setValue(v);
}
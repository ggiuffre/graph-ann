#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class gameField : public QWidget
{
protected:
	virtual void mouseMoveEvent(QMouseEvent * event);

public:
	gameField(QWidget * parent = 0);
//	~gameField();
};

#endif
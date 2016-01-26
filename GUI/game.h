#ifndef GAME_H
#define GAME_H

#include <QWidget>

class Game : public QWidget
{
	Q_OBJECT

public:
	Game(QWidget * parent = 0);
	QSize minimumSizeHint() const Q_DECL_OVERRIDE;
	QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
	void moveEnemy();

protected:
	void resizeEvent(QResizeEvent * event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent * event) Q_DECL_OVERRIDE;
	virtual void mouseMoveEvent(QMouseEvent * event);

private:
	unsigned int contatore;
};

#endif
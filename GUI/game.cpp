#include <QPainter>
#include <QMouseEvent>
#include "game.h"

Game::Game(QWidget * parent) : QWidget(parent)
{
	setMouseTracking(true);
	positionBats();

	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);
}

QSize Game::minimumSizeHint() const
{
	return QSize(400, 300);
}

QSize Game::sizeHint() const
{
	return QSize(600, 337);
}

void Game::positionBats()
{
	bats[0] = QRectF(10, 10, 20, height() - 20);
	bats[1] = QRectF(width() - 30, 10, 20, height() - 20);
	update();
}

void Game::moveBats(const qreal y, const bat_t which)
{
	if (y)
	{
		y > 0 ? bats[which].moveTop(y) : bats[which].moveBottom(y);
		update();
	}
}

void Game::moveBall(const qreal x, const qreal y)
{
	ball.moveCenter(QPointF(x, y));
	// ...
	update();
}

void Game::resizeEvent(QResizeEvent *)
{
	positionBats();
}

void Game::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	painter.fillRect(0, 0, width(), height(), Qt::black);

	painter.setBrush(Qt::green);
	painter.setPen(Qt::green);
	painter.drawRect(bats[0]);
	painter.drawRect(bats[1]);
}

void Game::mouseMoveEvent(QMouseEvent * event)
{
	QPoint mouse_coords = event->pos();
}
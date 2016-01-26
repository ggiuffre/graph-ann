#include <QApplication>
#include <QMainWindow>
#include "game.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	QMainWindow mw;
	Game gm;
	mw.setCentralWidget(&gm);
	mw.show();

	return app.exec();
}
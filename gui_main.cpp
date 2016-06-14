#include "corn_window.h"
#include <QApplication>
#include <QMainWindow>
#include <QFile>

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	QFile qss("stylesheet.qss");
	qss.open(QFile::ReadOnly);
	app.setStyleSheet(qss.readAll());
	qss.close();

	CornWindow main_window;
	main_window.show();

	return app.exec();
}

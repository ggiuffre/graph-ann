#include "corn_window.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	CornWindow main_window;
	main_window.show();

	return app.exec();
}

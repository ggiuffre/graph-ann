#include "palestra.h"
#include <QApplication>
#include <QMainWindow>

#include <QMessageBox>	// debugging

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

//	QMessageBox msgBox;
//	msgBox.setText(QCoreApplication::applicationDirPath());
//	msgBox.exec();

	palestra main_palestra;
	main_palestra.show();

	return app.exec();
}

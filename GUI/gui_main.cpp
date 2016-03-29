#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include "dojo.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

//	QMessageBox msgBox;
//	msgBox.setText(QCoreApplication::applicationDirPath());
//	msgBox.exec();

	dojo main_dojo;
	main_dojo.show();

	return app.exec();
}

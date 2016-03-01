#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include "dojo.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	layeredTanhNet net;
	net.addLayer(2);
	net.addLayer(4);
	net.addLayer(1);
	net.save("./nets/and.net");

//	QMessageBox msgBox;
//	msgBox.setText(QCoreApplication::applicationDirPath());
//	msgBox.exec();

	dojo main_dojo;
	main_dojo.show();

	return app.exec();
}
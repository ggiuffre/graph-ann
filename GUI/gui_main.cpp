#include "dojo.h"
#include <QApplication>
#include <QMainWindow>

#include <QMessageBox>	// debugging

int main(int argc, char * argv[])
{
#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

	QApplication app(argc, argv);

//	QMessageBox msgBox;
//	msgBox.setText(QCoreApplication::applicationDirPath());
//	msgBox.exec();

	dojo main_dojo;
	main_dojo.show();

	return app.exec();
}

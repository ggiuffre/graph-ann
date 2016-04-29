#ifndef DATA_BUILDER_WIDGET_H
#define DATA_BUILDER_WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QFormLayout>
#include <QLineEdit>

class dataBuilderWidget : public QWidget
{
	Q_OBJECT

private:
	QTextEdit * data;
	QFormLayout * layout;
	QString title;

public:
	dataBuilderWidget(QWidget * parent = nullptr);
};

#endif

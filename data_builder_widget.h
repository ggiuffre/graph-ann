#ifndef DATA_BUILDER_WIDGET_H
#define DATA_BUILDER_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>

class dataBuilderWidget : public QWidget
{
	Q_OBJECT

private:
	QFormLayout * layout;
	QTextEdit * input_buffer, * target_buffer;
	QPushButton * next, * trigger;
	QString tot_data;
	unsigned int n_examples, n_in, n_out;

public slots:
	void addExample();
	void storeData();

public:
	dataBuilderWidget(QWidget * parent = nullptr);
};

#endif

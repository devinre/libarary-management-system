#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include "ui_mywidget.h"

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MyWidgetClass *ui;
};

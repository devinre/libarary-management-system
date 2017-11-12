#pragma once

#include <QtWidgets/QWidget>
#include "ui_mywidget.h"

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MyWidgetClass *ui;
public slots:
	void on_showChildButton_clicked();
private slots:
	void on_pushButton_clicked();
};


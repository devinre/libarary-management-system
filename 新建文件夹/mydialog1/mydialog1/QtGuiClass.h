#pragma once

#include <QDialog>
#include "ui_QtGuiClass.h"

class QtGuiClass : public QDialog
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

private:
	Ui::QtGuiClass ui;
};

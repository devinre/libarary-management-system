#pragma once

#include <QtWidgets/QDialog>
#include "ui_helloworld.h"

class helloworld : public QDialog
{
	Q_OBJECT

public:
	helloworld(QWidget *parent = Q_NULLPTR);

private:
	Ui::helloworldClass ui;
};

#pragma once

#include <QWidget>
#include "ui_returnbook.h"

class returnbook : public QWidget
{
	Q_OBJECT

public:
	returnbook(QWidget *parent = Q_NULLPTR);
	~returnbook();

private:
	Ui::returnbook ui;
};

#pragma once

#include <QWidget>
#include "ui_addcard.h"

class addcard : public QWidget
{
	Q_OBJECT

public:
	addcard(QWidget *parent = Q_NULLPTR);
	~addcard();

private:
	Ui::addcard *ui;
	QString cardmessage[4];
	int addcar();
	private slots:
	void on_pushButton_clicked();
};

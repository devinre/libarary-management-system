#pragma once

#include <QWidget>
#include "ui_singleadd.h"

class singleadd : public QWidget
{
	Q_OBJECT

public:
	singleadd(QWidget *parent = Q_NULLPTR);
	~singleadd();

private:
	Ui::singleadd *singleadd_ui;
	QString bookMessage[8];
	int addbook();
	private slots:
	void on_pushButton_clicked();
};

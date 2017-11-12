#pragma once

#include <QWidget>
#include "ui_multyadd.h"

class multyadd : public QWidget
{
	Q_OBJECT

public:
	multyadd(QWidget *parent = Q_NULLPTR);
	~multyadd();

private:
	Ui::multyadd *multyadd_ui;
	QString bookMessage[8];
	QVector<QString *>multiBookMessage;
	int addbook();
	private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
};

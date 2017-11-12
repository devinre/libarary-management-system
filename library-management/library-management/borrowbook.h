#pragma once

#include <QWidget>
#include "ui_borrowbook.h"

class borrowbook : public QWidget
{
	Q_OBJECT

public:
	borrowbook(QWidget *parent = Q_NULLPTR);
	~borrowbook();


private:
	Ui::borrowbook *ui;
	void loadborrowmessage();
	QVector<QString*> borrowmessage;
	private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
};

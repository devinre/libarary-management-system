#pragma once

#include <QWidget>
#include "ui_addbook.h"
#include <QSqldatabase>
#include "singleadd.h"
#include "multyadd.h"
class addbook : public QWidget
{
	Q_OBJECT

public:
	addbook(QWidget *parent = Q_NULLPTR);
	~addbook();

private:
	Ui::addbook *addbook_ui;
	int max_page;
	int current_page;
	//QSqlDatabase db;
	void updatewindow();
	QVector<QString>result;
	singleadd singleadd_ui;
	multyadd multyadd_ui;
	private slots:
	void on_pushButton_5_clicked();
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
};

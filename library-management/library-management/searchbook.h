#pragma once

#include <QWidget>
#include "ui_searchbook.h"

class searchbook : public QWidget
{
	Q_OBJECT

public:
	searchbook(QWidget *parent = Q_NULLPTR);
	~searchbook();

private:
	Ui::searchbook *ui;
	int max_page;
	int current_page;
	void updatewindow();
	QVector<QString>result;
	private slots:
	void on_pushButton_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_2_clicked();
};

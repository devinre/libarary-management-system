#pragma once

#include <QWidget>
#include "ui_card.h"
#include "addcard.h"
class card : public QWidget
{
	Q_OBJECT

public:
	card(QWidget *parent = Q_NULLPTR);
	~card();

private:
	Ui::card *ui;
	int max_page;
	int current_page;
	addcard addcard_ui;
	QVector<QString>result;
	void updatewindow();
	private slots:
	void on_pushButton_3_clicked();
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_4_clicked();
};

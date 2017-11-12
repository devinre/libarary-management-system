#pragma once

#include <QtWidgets/QWidget>
#include "ui_librarymanagement.h"
#include "addbook.h"
#include "searchbook.h"
#include "borrowbook.h"
#include "card.h"
#include <QSqldatabase>

class librarymanagement : public QWidget
{
	Q_OBJECT

public:
	librarymanagement(QWidget *parent = Q_NULLPTR);
	~librarymanagement();


private:
	Ui::librarymanagementClass *librarymanagement_ui;
	addbook addbook_ui;
	searchbook searchbook_ui;
	borrowbook borrowbook_ui;
	card card_ui;
	QSqlDatabase db;
	private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_5_clicked();
};

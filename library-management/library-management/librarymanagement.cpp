#pragma execution_character_set("utf-8")
#include "librarymanagement.h"
#include <QDatetime>
#include "ui_librarymanagement.h"
#include <QMessagebox>
#include <QSqlError>
QDateTime datetime = QDateTime::currentDateTime();
librarymanagement::librarymanagement(QWidget *parent) :
	QWidget(parent),
	librarymanagement_ui(new Ui::librarymanagementClass)
{
	librarymanagement_ui->setupUi(this);
	QString strTime = datetime.toString("yyyy-MM-dd");
	librarymanagement_ui->label_3->setText(strTime);
	db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName("exfive");
	db.setUserName("sa");
	db.setPassword("123456");
	if (!db.open())
	{
		QMessageBox::critical(this, tr("—œ÷ÿ¥ÌŒÛ"), db.lastError().text(), QMessageBox::YesAll);
	}
}
librarymanagement::~librarymanagement()
{
	delete librarymanagement_ui;
	db.close();
}
void librarymanagement::on_pushButton_clicked()
{
	addbook_ui.show();
}
void librarymanagement::on_pushButton_2_clicked()
{
	searchbook_ui.show();
}
void librarymanagement::on_pushButton_3_clicked()
{
	borrowbook_ui.show();
}
void librarymanagement::on_pushButton_5_clicked()
{
	card_ui.show();
}
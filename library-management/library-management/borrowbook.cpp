#pragma execution_character_set("utf-8")
#include "borrowbook.h"
#include "ui_borrowbook.h"
#include <QSqlQuery>
#include <QMessagebox>
#include <QSqlError>
#include <QString>
#include <QDatetime>

borrowbook::borrowbook(QWidget *parent)	: 
	QWidget(parent),
	ui(new Ui::borrowbook)
{
	ui->setupUi(this);
	for (int i = 0;i<15;i++)
		for (int j = 0;j < 5;j++)
		{
			QTableWidgetItem *item = new QTableWidgetItem("");
			ui->tableWidget->setItem(i, j, item);
		}
}

borrowbook::~borrowbook()
{
	delete ui;
}
void borrowbook::on_pushButton_clicked()
{
	loadborrowmessage();
	QStringList header;
	ui->tableWidget->clear();
	header << "卡号" << "书号" << "书名" << "借期" << "还期";
	ui->tableWidget->setHorizontalHeaderLabels(header);
	for (int i = 0;i < borrowmessage.length();i++)
		for(int j=0;j<5;j++)
	{
			QTableWidgetItem *item = new QTableWidgetItem(borrowmessage.at(i)[j]);
			ui->tableWidget->setItem(i, j, item);
	}
}
void borrowbook::loadborrowmessage()
{
	QSqlQuery query, query1;
	for (int i = 0;i < borrowmessage.length();i++)
		for (int j = 0;j < 5;j++)
			borrowmessage.at(i)[j].clear();
	borrowmessage.clear();
	query.exec("select bno,borrow_date,return_date from borrow where cno = '" + ui->lineEdit->text() + "'");
	while (query.next())
	{
		QString *ans = new QString[5];
		ans[0] = ui->lineEdit->text();
		ans[1] = query.value(0).toString();
		query1.exec("select title from book where bno = '" + ans[1] + "'");
		if (query1.next())
			ans[2] = query1.value(0).toString();
		else
		{
			QMessageBox::critical(this, tr("严重错误"), query1.lastError().text(), QMessageBox::YesAll);
			return;
		}
		ans[3]= query.value(1).toString();
		ans[4] = query.value(2).toString();
		borrowmessage.push_back(ans);
	}
}
void borrowbook::on_pushButton_2_clicked()
{
	QSqlQuery query,query1,query2,query3;
	QString str, str1;
	query.exec("select stock from book where bno = '" + ui->lineEdit_2->text() + "'");
	if (query.next())
	{
		int num = query.value(0).toInt();
		if (num == 0)
		{
			query1.exec("select min(return_date) from borrow where bno = '" + ui->lineEdit_2->text() + "'");
			if (query1.next())
				str1 = query1.value(0).toString();
				str = ui->lineEdit_2->text() + "暂无库存！最近归还时间："+str1;
			QMessageBox::critical(NULL, "错误", str);
			return;
		}
	}
	QDate currendate = QDate::currentDate();
	QDate returndate = currendate.addDays(90);
	QString borrow_date = currendate.toString("yyyy-MM-dd");
	QString return_date = returndate.toString("yyyy-MM-dd");
	query2.exec("insert into borrow values('" + ui->lineEdit->text() + "','" + ui->lineEdit_2->text() + "','"+borrow_date+"','"+return_date+"')");
	if (!query2.isActive())
	{
		QMessageBox::critical(this, tr("严重错误"), query2.lastError().text(), QMessageBox::YesAll);
	}
	if (query2.isActive())
		query3.exec("update book set stock = stock - 1 where bno = '" + ui->lineEdit_2->text() + "'");
	if (query3.isActive())
		QMessageBox::about(0, "成功", "借书成功");
}
void borrowbook::on_pushButton_3_clicked()
{
	QSqlQuery query, query1;
	query.exec("delete from borrow where cno = '" + ui->lineEdit->text()+"' and bno = '" + ui->lineEdit_2->text()+"'");
	if (query.isActive())
	{
		QMessageBox::about(NULL, "成功", "删除借书记录成功");
		query1.exec("update book set stock = stock + 1 where bno = '" + ui->lineEdit_2->text() + "'");
		if (query1.isActive())
			QMessageBox::about(NULL, "成功", "更新书库库存成功");
		else
		{
			QMessageBox::about(NULL, "成功", "更新书库库存失败");
			return;
		}
	}
	else
	{
		QMessageBox::about(NULL, "成功", "删除借书记录失败");
		return;
	}
	return;
}

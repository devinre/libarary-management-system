#pragma execution_character_set("utf-8")
#include "singleadd.h"
#include "ui_singleadd.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

singleadd::singleadd(QWidget *parent)	:
	QWidget(parent),
	singleadd_ui(new Ui::singleadd)
{
	singleadd_ui->setupUi(this);
}

singleadd::~singleadd()
{
	delete singleadd_ui;
}
void singleadd::on_pushButton_clicked()
{
	if (singleadd_ui->lineEdit_bno->text().isEmpty() ||
		singleadd_ui->lineEdit_author->text().isEmpty() ||
		singleadd_ui->lineEdit_category->text().isEmpty() ||
		singleadd_ui->lineEdit_press->text().isEmpty() ||
		singleadd_ui->lineEdit_price->text().isEmpty() ||
		singleadd_ui->lineEdit_title->text().isEmpty() ||
		singleadd_ui->lineEdit_number->text().isEmpty()||
		singleadd_ui->lineEdit_year->text().isEmpty())
	{
		QMessageBox::critical(this,tr("严重错误"), tr("输入信息不完整"), QMessageBox::YesAll);
		return;
	}
	bookMessage[0] = singleadd_ui->lineEdit_bno->text();
	bookMessage[1] = singleadd_ui->lineEdit_category->text();
	bookMessage[2] = singleadd_ui->lineEdit_title->text();
	bookMessage[3] = singleadd_ui->lineEdit_press->text();
	bookMessage[4] = singleadd_ui->lineEdit_year->text();
	bookMessage[5] = singleadd_ui->lineEdit_author->text();
	bookMessage[6] = singleadd_ui->lineEdit_price->text();
	bookMessage[7] = singleadd_ui->lineEdit_number->text();
	if (addbook())
		QMessageBox::information(this, tr("结果"), tr("插入成功"), QMessageBox::YesAll);
	else
		QMessageBox::critical(this, tr("结果"), tr("插入失败"), QMessageBox::YesAll);
	singleadd_ui->lineEdit_bno->clear();
		singleadd_ui->lineEdit_author->clear();
		singleadd_ui->lineEdit_category->clear();
		singleadd_ui->lineEdit_press->clear();
		singleadd_ui->lineEdit_price->clear();
		singleadd_ui->lineEdit_title->clear();
		singleadd_ui->lineEdit_number->clear();
		singleadd_ui->lineEdit_year->clear();
}
int singleadd::addbook()
{
	QSqlQuery query, query1, query2;
	query.exec("select bno from book where bno = '" + bookMessage[0]+"'");
	if (query.next())
	{
		QString str = "";
		for (int i = 0;i < 8;i++)
		{
			str = str + bookMessage[i] + ",";
		}
		int message = QMessageBox::question(this, tr("询问"), "图书库已有书籍与\n("+str+")\n书号相同，是否更新该书号信息？", QMessageBox::Yes, QMessageBox::No);
		if (message == QMessageBox::Yes)
		{
			query1.exec("update book set category = '" + bookMessage[1] + "',title = '" + bookMessage[2] + "',press='" + bookMessage[3] + "',year=" + bookMessage[4] + ",author='" + bookMessage[5] + "',price=" + bookMessage[6] + ",total=total+" + bookMessage[7] + ",stock=stock+" + bookMessage[7] + "where bno='" + query.value(0).toString() + "'");
			if (query1.isActive())
				return 1;
			else return 0;
		}
		else if (message == QMessageBox::No)
			return 0;
	}
	query2.exec("insert into book values('" + bookMessage[0] + "','" + bookMessage[1] + "','" + bookMessage[2] + "','" + bookMessage[3] + "'," + bookMessage[4] + ",'" + bookMessage[5] + "'," + bookMessage[6] + "," + bookMessage[7] + "," + bookMessage[7] +")");
	return 1;
}

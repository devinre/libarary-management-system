#pragma execution_character_set("utf-8")
#include "card.h"
#include "ui_card.h"
#include <QSqldatabase>
#include <QMessagebox>
#include <QSqlError>
#include <QString>
#include <QSqlQuery>

card::card(QWidget *parent)	: 
	QWidget(parent),
	ui(new Ui::card)
{
	ui->setupUi(this);
}

card::~card()
{
	delete ui;
}
void card::on_pushButton_3_clicked()
{
	addcard_ui.show();
}
void card::on_pushButton_clicked()
{
	if (current_page == 1) return;
	current_page--;
	updatewindow();
}
void card::on_pushButton_2_clicked()
{
	if (current_page == max_page) return;
	current_page++;
	updatewindow();
}
void card::updatewindow()
{
	QTableWidget * tw = ui->tableWidget;
	tw->clear();
	QStringList header;
	header << "卡号" << "姓名" << "单位" << "类比（T教师/S学生）";
	tw->setHorizontalHeaderLabels(header);
	int max;
	if (result.length() == 0) return;
	if (current_page == max_page)
	{
		max = result.length() % 60 / 4;
		if (max == 0) max = 15;
	}
	else max = 15;
	QTableWidgetItem *item[60];
	for (int i = 0;i<60;i++) {
		item[i] = NULL;
	}
	for (int i = 0;i < max;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			item[(4 * i + j)] = new QTableWidgetItem(result.at(4 * i + j + 60 * (current_page - 1)));
			tw->setItem(i, j, item[(4 * i + j)]);
		}
	}
}
void card::on_pushButton_5_clicked()
{
	QString ans = "select * from card";
	QSqlQuery query;
	query.exec(ans);
	if (!query.isActive())
	{
		QMessageBox::critical(this, tr("严重错误"), query.lastError().text(), QMessageBox::YesAll);
	}
	result.clear();
	while (query.next())
	{
		for (int i = 0;i < 4;i++)
		{
			result.push_back(query.value(i).toString());
		}
	}
	if (result.length() == 0)
	{
		QMessageBox::critical(this, tr("严重错误"), tr("卡库为空"), QMessageBox::YesAll);
		return;
	}
	current_page = 1;
	max_page = result.length() / 60 + (result.length() % 60 != 0);
	updatewindow();
}
void card::on_pushButton_4_clicked()
{
	QSqlQuery query, query1;
	query1.exec("select cno from card where cno = '" + ui->deletecno->text() + "'");
	if (!query1.next())
	{
		QMessageBox::critical(NULL, "错误", "无此卡号", QMessageBox::Yes);
		return;
	}
	query.exec("delete from card where cno = '" + ui->deletecno->text() + "'");
	/*if (!query.isActive())
	{
		QMessageBox::critical(this, tr("严重错误"), query.lastError().text(), QMessageBox::YesAll);
	}*/
	if (!query.isActive())
		QMessageBox::critical(NULL, "错误", "删除失败，此卡有书未还！", QMessageBox::Yes);
	else
		QMessageBox::about(NULL, "成功", "删除成功");
}
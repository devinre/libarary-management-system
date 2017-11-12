#pragma execution_character_set("utf-8")
#include "addbook.h"
#include "ui_addbook.h"
#include <QSqldatabase>
#include <QMessagebox>
#include <QSqlError>
#include <QString>
#include <QSqlQuery>

addbook::addbook(QWidget *parent)	: 
	QWidget(parent),
	addbook_ui(new Ui::addbook)
{
	addbook_ui->setupUi(this);
	/*QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName("exfive");
	db.setUserName("sa");
	db.setPassword("123456");
	if (!db.open())
	{
		QMessageBox::critical(this, tr("严重错误"), db.lastError().text(), QMessageBox::YesAll);
	}*/
	current_page = 1;
	max_page = 1;
}

addbook::~addbook()
{
	delete addbook_ui;
	//db.close();
}
void addbook::on_pushButton_5_clicked()
{
	QString ans = "select * from book";
	QSqlQuery query;
	query.exec(ans);
	if (!query.isActive())
	{
		QMessageBox::critical(this, tr("严重错误"), query.lastError().text(), QMessageBox::YesAll);
	}	
	result.clear();
	while (query.next())
	{
		for (int i = 0;i < 9;i++)
		{
			result.push_back(query.value(i).toString());
		}
	}
	if (result.length() == 0)
	{
		QMessageBox::critical(this, tr("严重错误"), tr("图书库为空"), QMessageBox::YesAll);
		return;
	}
	current_page = 1;
	max_page = result.length() / 135 + (result.length() % 135 != 0);
	updatewindow();	
}
void addbook::on_pushButton_clicked()
{
	if (current_page == 1) return;
	current_page--;
	updatewindow();
}
void addbook::on_pushButton_2_clicked()
{
	if (current_page == max_page) return;
	current_page++;
	updatewindow();
}
void addbook::updatewindow()
{
	QTableWidget * tw = addbook_ui->tableWidget;
	tw->clear();
	QStringList header;
	header << "书号" << "类别" << "书名" << "出版社" << "年份" << "作者" << "价格" << "总藏书量" << "库存";
	tw->setHorizontalHeaderLabels(header);
	int max;
	if (result.length() == 0) return;
	if (current_page == max_page)
	{
		max = result.length() % 135 / 9;
		if (max == 0) max = 15;
	}
	else max = 15;
	QTableWidgetItem *item[135];
	for (int i = 0;i<135;i++) {
		item[i] = NULL;
	}
	for (int i = 0;i < max;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			item[(9 * i + j)] = new QTableWidgetItem(result.at(9 * i + j + 135 * (current_page - 1)));
			tw->setItem(i, j, item[(9 * i + j)]);
		}
	}
}
void addbook::on_pushButton_3_clicked()
{
	singleadd_ui.show();
}
void addbook::on_pushButton_4_clicked()
{
	multyadd_ui.show();
}
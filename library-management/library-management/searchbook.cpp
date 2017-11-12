#pragma execution_character_set("utf-8")
#include "searchbook.h"
#include "ui_searchbook.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
searchbook::searchbook(QWidget *parent)	:
	QWidget(parent),
	ui(new Ui::searchbook)
{
	ui->setupUi(this);
}

searchbook::~searchbook()
{
	delete ui;
}
void searchbook::on_pushButton_clicked()
{
	if (ui->categoryline->text().isEmpty() &&
		ui->titleline->text().isEmpty() &&
		ui->pressline->text().isEmpty() &&
		ui->yearline1->text().isEmpty() &&
		ui->yearline2->text().isEmpty() &&
		ui->authorline->text().isEmpty() &&
		ui->priceline1->text().isEmpty() &&
		ui->priceline2->text().isEmpty())
	{
		QMessageBox::critical(0, QObject::tr("错误"), "尚未填写任何搜索信息");
		return;
	}
	QVector<QString>list;
	if (!ui->categoryline->text().isEmpty())
	{
		list.push_back("category");
		list.push_back(ui->categoryline->text());
	}
	if (!ui->titleline->text().isEmpty())
	{
		list.push_back("title");
		list.push_back(ui->titleline->text());
	}
	if (!ui->pressline->text().isEmpty())
	{
		list.push_back("press");
		list.push_back(ui->pressline->text());
	}
	if (!ui->yearline1->text().isEmpty())
	{
		list.push_back("year");
		list.push_back(ui->yearline1->text());
		list.push_back(ui->yearline2->text());
	}
	if (!ui->authorline->text().isEmpty())
	{
		list.push_back("author");
		list.push_back(ui->authorline->text());
	}
	if (!ui->priceline1->text().isEmpty())
	{
		list.push_back("price");
		list.push_back(ui->priceline1->text());
		list.push_back(ui->priceline2->text());
	}
	int len = list.length();
	int count = 0;
	QString ans = "select * from book where ";
	QSqlQuery query;
	while (count < len)
	{
		if (count != 0) ans = ans + " and ";
		QString tmp = list.front();
		list.pop_front();
		count++;
		QString tmp1, tmp2;
		if (tmp.compare("year") == 0)
		{
			tmp1 = list.front();
			list.pop_front();
			count++;
			tmp2 = list.front();
			list.pop_front();
			count++;
			ans = ans + tmp + ">=" + tmp1 + " and " + tmp + "<=" + tmp2 + "";
		}
		else if (tmp.compare("price") == 0)
		{
			tmp1 = list.front();
			list.pop_front();
			count++;
			tmp2 = list.front();
			list.pop_front();
			count++;
			ans = ans + tmp + ">=" + tmp1 + " and " + tmp + "<=" + tmp2 + "";
		}
		else
		{
			tmp1 = list.front();
			list.pop_front();
			count++;
			ans = ans + tmp + "='" + tmp1 + "'";
		}
	}
	query.exec(ans);
	if (!query.isActive())
	{
		QMessageBox::critical(0, QObject::tr("错误"), query.lastError().text());
	}
	result.clear();
	while (query.next())
		for (int i = 0;i < 9;i++)
			result.push_back(query.value(i).toString());
	if (result.length() == 0)
	{
		QMessageBox::critical(0, QObject::tr("错误"), "没有搜索到！");
		return;
	}
	current_page = 1;
	max_page = result.length() / 135 + (result.length() % 135 != 0);
	updatewindow();
}
void searchbook::updatewindow()
{
	QTableWidget * tw = ui->tableWidget;
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
void searchbook::on_pushButton_3_clicked()
{
	if (current_page == 1) return;
	current_page--;
	updatewindow();
}
void searchbook::on_pushButton_4_clicked()
{
	if (current_page == max_page) return;
	current_page++;
	updatewindow();
}
void searchbook::on_pushButton_2_clicked()
{
	ui->categoryline -> clear();
		ui->titleline->clear();
		ui->pressline->clear();
		ui->yearline1->clear();
		ui->yearline2->clear();
		ui->authorline->clear();
		ui->priceline1->clear();
		ui->priceline2->clear();
}
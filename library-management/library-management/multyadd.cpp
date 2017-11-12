#pragma execution_character_set("utf-8")
#include "multyadd.h"
#include "ui_multyadd.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
multyadd::multyadd(QWidget *parent)	:
	QWidget(parent),
	multyadd_ui(new Ui::multyadd)
{
	multyadd_ui->setupUi(this);
	for(int i=0;i<15;i++)
		for (int j = 0;j < 8;j++)
		{
			QTableWidgetItem *item = new QTableWidgetItem("");
			multyadd_ui->tableWidget->setItem(i, j, item);
		}
}

multyadd::~multyadd()
{
	delete multyadd_ui;
}
void multyadd::on_pushButton_clicked()
{
	QWidget *filewindow;
	filewindow = new QWidget;
	QFileDialog fileopen(filewindow, "添加多册图书");
	fileopen.resize(400, 300);
	fileopen.setAcceptMode(QFileDialog::AcceptOpen);
	fileopen.setNameFilter("*txt");
	if (fileopen.exec() == QDialog::Accepted)
	{
		QStringList files = fileopen.selectedFiles();
		if (!files.isEmpty())
		{
			QFile file;
			file.setFileName(files.at(0));
			file.open(QIODevice::ReadOnly);
			if (!file.atEnd())
			{
				int count = 0;
				int row = 0;
				QByteArray buff;
				buff = file.readAll();
				QString filecontent = QString::fromLocal8Bit(buff);
				QString str = "";
				for (int i = 0;i < filecontent.length();i++)
				{
					if (filecontent.at(i) == '\n' || i == filecontent.length()-1)
					{
						bookMessage[7] = str;
						if (row >= 15)
						{
							QString *tmp;
							tmp = new QString[8];
							for (int k = 0;k < 8;k++)
								tmp[k] = bookMessage[k];
							multiBookMessage.push_back(tmp);
							str = "";
							count = 0;
							row++;
						}
						else
						{
							for (int k = 0;k < 8;k++)
								multyadd_ui->tableWidget->item(row, k)->setText(bookMessage[k]);
							row++;
							count = 0;
							str = "";
						}
						if (i == filecontent.length() - 1)
							break;
					}
					else if (filecontent.at(i) == ' ')
					{
						bookMessage[count++] = str;
						str = "";
					}
					else if (filecontent.at(i).isLetter() || filecontent.at(i).isNumber()
						|| filecontent.at(i) == '.' || filecontent.at(i) == ':'
						|| filecontent.at(i) == '-' || filecontent.at(i) == '"'
						|| filecontent.at(i) == '(' || filecontent.at(i) == ')'
						|| filecontent.at(i) == ',' || filecontent.at(i) == '?')
						str = str + filecontent.at(i);
				}
			}
		}
	}
}
void multyadd::on_pushButton_2_clicked()
{
	bool flag = true;
	int count = 0;
	for (int i = 0;i < 15;i++)
	{
		bool hasvalue = false;
		bool isempty = false;
		for (int j = 0;j < 8;j++)
		{
			if (multyadd_ui->tableWidget->item(i, j)->text().compare("") == 0)
				isempty = true;
			else
				hasvalue = true;
			if (hasvalue&&isempty)
			{
				QMessageBox::critical(NULL, "错误", "信息不完整");
					return;
			}
		}
		if (!isempty)
			count++;
	}
	for (int i = 0;i < count;i++)
	{
		for (int j = 0;j < 8;j++)
			bookMessage[j] = multyadd_ui->tableWidget->item(i, j)->text();
		if (!addbook())
		{
			flag = false;
			QMessageBox::critical(NULL, "错误", "第" + QString::number(i + 1) + "本书添加失败");
		}
	}
	if (flag)
	{
		QMessageBox::about(NULL, "ok", "插入成功");
			for (int i = 0;i < 8;i++)
				bookMessage[i].clear();
	}
	for (int i = 0;i < 15;i++)
		for(int j=0;j<8;j++)
			multyadd_ui->tableWidget->item(i, j)->setText("");
	int max = multiBookMessage.length() < 15 ? multiBookMessage.length() : 15;
	for(int i=0;i<max;i++)
		for (int j = 0;j < 8;j++)
			multyadd_ui->tableWidget->item(i, j)->setText(multiBookMessage[i][j]);
	for (int i = 0;i < max;i++)
		multiBookMessage.pop_front();
}
void multyadd::on_pushButton_3_clicked()
{
	for (int i = 0;i < 15;i++)
	for(int j=0;j<8;j++)
		multyadd_ui->tableWidget->item(i, j)->setText("");
	for (int i = 0;i < multiBookMessage.length();i++)
		multiBookMessage.pop_front();
}
int multyadd::addbook()
{
	QSqlQuery query, query1, query2;
	query.exec("select bno from book where bno = '" + bookMessage[0] + "'");
	if (query.next())
	{
		QString str = "";
		for (int i = 0;i < 8;i++)
		{
			str = str + bookMessage[i] + ",";
		}
		int message = QMessageBox::question(this, tr("询问"), "图书库已有书籍与\n(" + str + ")\n书号相同，是否更新该书号信息？", QMessageBox::Yes, QMessageBox::No);
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
	query2.exec("insert into book values('" + bookMessage[0] + "','" + bookMessage[1] + "','" + bookMessage[2] + "','" + bookMessage[3] + "'," + bookMessage[4] + ",'" + bookMessage[5] + "'," + bookMessage[6] + "," + bookMessage[7] + "," + bookMessage[7] + ")");
	return 1;
}

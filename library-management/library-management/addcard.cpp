#pragma execution_character_set("utf-8")
#include "addcard.h"
#include "ui_addcard.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

addcard::addcard(QWidget *parent)	: 
	QWidget(parent),
	ui(new Ui::addcard)
{
	ui->setupUi(this);
}

addcard::~addcard()
{
	delete ui;
}
void addcard::on_pushButton_clicked()
{
	if (ui->cno->text().isEmpty() ||
		ui->name->text().isEmpty() ||
		ui->department->text().isEmpty() ||
		ui->type->text().isEmpty())
	{
		QMessageBox::critical(this, tr("���ش���"), tr("������Ϣ������"), QMessageBox::YesAll);
		return;
	}
	cardmessage[0] = ui->cno->text();
	cardmessage[1] = ui->name->text();
	cardmessage[2] = ui->department->text();
	cardmessage[3] = ui->type->text();
	if (addcar())
		QMessageBox::information(this, tr("���"), tr("����ɹ�"), QMessageBox::YesAll);
	else
		QMessageBox::critical(this, tr("���"), tr("����ʧ��"), QMessageBox::YesAll);
    ui->cno->clear();
	ui->name->clear();
	ui->department->clear();
	ui->type->clear();
}
int addcard::addcar()
{
	QSqlQuery query, query1, query2;
	query.exec("select cno from card where cno = '" + cardmessage[0] + "'");
	if (query.next())
	{
		QString str = "";
		for (int i = 0;i < 4;i++)
		{
			str = str + cardmessage[i] + ",";
		}
		int message = QMessageBox::question(this, tr("ѯ��"), "ͼ������н���֤��\n(" + str + ")\n֤������ͬ���Ƿ���¸�֤����Ϣ��", QMessageBox::Yes, QMessageBox::No);
		if (message == QMessageBox::Yes)
		{
			query1.exec("update card set name = '" + cardmessage[1] + "',department = '" + cardmessage[2] + "',type='" + cardmessage[3] + "'where cno = '"+cardmessage[0]+"'");
			if (query1.isActive())
				return 1;
			else return 0;
		}
		else if (message == QMessageBox::No)
			return 0;
	}
	query2.exec("insert into card values('" + cardmessage[0] + "','" + cardmessage[1] + "','" + cardmessage[2] + "','" + cardmessage[3] + "')");
	if (!query2.isActive())
	{
		QMessageBox::critical(0, QObject::tr("����"), query2.lastError().text());
	}
	return 1;
}
#pragma execution_character_set("utf-8")
#include "login.h"
#include "ui_login.h"
#include <QtWidgets>
#include <QMessageBox>


login::login(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::login)
{
	ui->setupUi(this);
}

login::~login()
{
	delete ui;
}

void login::on_pushButton_clicked()
{
	QString user = ui->username->text();
	QString pwd = ui->password->text();
	if (user == "sa"&&pwd == "123456")
		accept();
	else
		QMessageBox::information(this, tr("提示"),tr("登录信息错误"),QMessageBox::Ok);
}
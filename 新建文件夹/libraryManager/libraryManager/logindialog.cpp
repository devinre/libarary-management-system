#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "register.h"
#include "connection.h"
#include <QPainter>


QString helper::userid="";

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    setWindowTitle(tr("登陆"));    

    connect(ui->logPwdLE,SIGNAL(returnPressed()),this,SLOT(on_loginBtn_clicked()));

}



LoginDialog::~LoginDialog()
{
    delete ui;
}
//登录按钮
void LoginDialog::on_loginBtn_clicked()
{
    if (ui->logIdLE->text().isEmpty())
    {
        QMessageBox::information(this, tr("登录失败"),tr("请输入账号！"), QMessageBox::Ok);
        ui->logIdLE->setFocus();
    }
    else if(ui->logPwdLE->text().isEmpty())
    {
       QMessageBox::information(this,tr("登录失败"),tr("请输入密码！"),QMessageBox::Ok);
       ui->logPwdLE->setFocus();
    }
    else
    {
        QSqlDatabase db;
        if(!createConnection(db))
        {
            qDebug()<<"logindialog database not connect";
        }
        QSqlQuery query(db);
        query.prepare("select * from Tuser where id=?");
        query.addBindValue(ui->logIdLE->text());
        query.exec();
        if(query.next())
        {
            if (query.value(1).toString() == ui->logPwdLE->text())
            {
                helper::userid = ui->logIdLE->text();
                QDialog::accept();
            }
            else
            {
                QMessageBox::warning(this, tr("账号密码错误"),
                                     tr("请输入正确的账号密码再登录！"), QMessageBox::Ok);
                ui->logIdLE->clear();
                ui->logPwdLE->clear();
                ui->logIdLE->setFocus();
            }
        }
        else
            QMessageBox::information(this,tr("提示"),tr("没有此账号！"),QMessageBox::Ok);
        db.close();        
    }
}
//退出按钮
void LoginDialog::on_exitBtn_clicked()
{
    QDialog::reject();
}
//注册按钮
void LoginDialog::on_regBtn_clicked()
{
    Register regDlg;
    regDlg.exec();
}

void LoginDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/image1.jpg"));

}

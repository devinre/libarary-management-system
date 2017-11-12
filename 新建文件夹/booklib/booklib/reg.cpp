#include "reg.h"
#include "ui_reg.h"
#include "connection.h"
#include <QtGui/QApplication>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QObject>
#include <QLineEdit>
#include <QTextCodec>
#include <QTextEdit>
#include <QtDebug>
#include <QMessageBox>

reg::reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);
}

reg::~reg()
{
    delete ui;
}

void reg::on_sumBtn_clicked()
{
    QString logid,email,qq;
    int64_t pwd;
    QSqlDatabase db;
    if(!createConnection(db))
    {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                                      qApp->tr("Unable to establish a database connection."),
                                      QMessageBox::Cancel);
    }
    QSqlQuery query,query1;
    query.prepare("select * from Tuser where uid=?");
    query.addBindValue(ui->logIdLE->text().trimmed());
    query.exec();
    if(query.size()>0)
    {
        QMessageBox::warning(this,tr("failed"),tr("The id has all ready exist,please change one"),QMessageBox::Close);
        ui->logIdLE->clear();
    }
    else if(ui->logIdLE->text().trimmed()==NULL)
        {
            QMessageBox::warning(this,tr("failed"),tr("User id can not be NULL"),QMessageBox::Close);
        }
    else if(ui->logPwdLE->text().toInt()!=ui->logPwdSure->text().toInt())
    {
        QMessageBox::warning(this,tr("failed"),tr("The password is not same"),QMessageBox::Close);
        ui->logPwdLE->clear();
        ui->logPwdSure->clear();
    }
    else{
        logid=ui->logIdLE->text().trimmed();
        pwd=ui->logPwdLE->text().toInt();
        email=ui->emailLE->text().trimmed();
        qq=ui->qqLE->text().trimmed();
        query1.prepare("insert into Tuser(uid,pwd,level,qq,email)" "values(:uid,:pwd,:level,:qq,:email)");
        query1.bindValue(":uid",logid);
        query1.bindValue(":pwd",pwd);
        query1.bindValue(":level",1);
        query1.bindValue(":qq",qq);
        query1.bindValue(":email",email);
        if(!query1.exec())
            QMessageBox::warning(this,tr("failed"),tr("resiger error"),QMessageBox::Close);
        else
        {
        /*    helper::userid=ui->logIdLE->text().trimmed();
            re.show();
            re.init();*/
             QMessageBox::warning(this,tr("success"),tr("resiger success"),QMessageBox::Close);
        }
    }
    db.close();

}

void reg::on_exitBtn_clicked()
{
    reject();
}

void reg::on_clearBtn_clicked()
{
    ui->logIdLE->clear();
    ui->logPwdLE->clear();
    ui->logPwdSure->clear();
    ui->emailLE->clear();
    ui->qqLE->clear();
}

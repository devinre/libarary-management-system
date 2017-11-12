#include "readermod.h"
#include "ui_readermod.h"

#include "connection.h"

#include <QTextCodec>
#include <QtGui/QApplication>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QObject>
#include <QLineEdit>
#include <QTextEdit>
#include <QtDebug>
#include <QMessageBox>

readerMod::readerMod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::readerMod)
{
    ui->setupUi(this);
}

readerMod::~readerMod()
{
    delete ui;
}

void readerMod::on_btnCan_clicked()
{
    ui->leEmail->clear();
    ui->lepwd->clear();
    ui->lepwdSure->clear();
    ui->leqq->clear();
}

void readerMod::on_bynSum_clicked()
{
    if(ui->lepwd->text().trimmed()!=ui->lepwdSure->text().trimmed())
        {
            QMessageBox::warning(this,tr("failed"),tr("Password not same"),QMessageBox::Close);
             ui->lepwdSure->clear();
        }
    else
    {
        QString pwd=ui->lepwd->text().trimmed();
        QString email=ui->leEmail->text().trimmed();
        QString qq=ui->leqq->text().trimmed();
        QSqlDatabase db;
        createConnection(db);
        QSqlQuery query1;
        query1.prepare("update  Tuser set pwd=?,level=?,qq=?,email=? where uid=?");
        query1.addBindValue(pwd);
        query1.addBindValue(1);
        query1.addBindValue(qq);
        query1.addBindValue(email);
        query1.addBindValue(helper::userid);
        if(!query1.exec())
            QMessageBox::warning(this,tr("failed"),tr("Modify error"),QMessageBox::Close);
        else{
            QMessageBox::warning(this,tr("success"),tr("Modify success"),QMessageBox::Close);
        }
        db.close();
    }
}

void readerMod::on_btnExit_clicked()
{
    reject();
    ui->leEmail->clear();
    ui->lepwd->clear();
    ui->lepwdSure->clear();
    ui->leqq->clear();
}

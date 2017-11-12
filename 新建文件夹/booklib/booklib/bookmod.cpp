#include "bookmod.h"
#include "ui_bookmod.h"
#include "connection.h"

#include <QTextCodec>
#include <QtGui/QApplication>
#include <QSqlQuery>
#include <QObject>
#include <QLineEdit>
#include <QtDebug>
#include <QMessageBox>

bookmod::bookmod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookmod)
{
    ui->setupUi(this);

    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    if(helper::flag==1)
    {
        query.prepare("select * from Tbook where bid=?");
        query.addBindValue(helper::tran.toInt());
    }
    else
    {
        query.prepare("select * from Tbook where bname=?");
        query.addBindValue(helper::tran);
    }
    query.exec();
    if(query.next())
    {
        ui->leBname->setText(query.value(0).toString());
        ui->leWriter->setText(query.value(1).toString());
        ui->leHot->setText(query.value(2).toString());
        if(query.value(3).toInt()==0)
            ui->rbNlend->setChecked(true);
        if(query.value(3).toInt()==1)
            ui->rbLend->setChecked(true);
        ui->lberror->hide();
    }
    else
    {
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->leBname->hide();
        ui->leWriter->hide();
        ui->leHot->hide();
        ui->rbLend->hide();
        ui->rbNlend->hide();
        ui->btnCon->hide();
        ui->btnExit->hide();
        ui->btnSum->hide();
    }
}

bookmod::~bookmod()
{
    delete ui;
}

void bookmod::on_btnExit_clicked()
{
    reject();
}

void bookmod::on_btnCon_clicked()
{
    ui->leBname->clear();
    ui->leWriter->clear();
    ui->leHot->clear();
    ui->rbLend->setChecked(false);
    ui->rbNlend->setChecked(false);
}

void bookmod::on_btnSum_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    if(helper::flag==1)
    {
        if(ui->leBname->text().trimmed()=="")
        {
             QMessageBox::warning(this,tr("failed"),tr("Bookname can't be null"),QMessageBox::Close);
        }
        else
        {
            if(ui->rbLend->isChecked())
            {
                query.prepare("update Tbook set bname=?,writer=?,hot=?,state=? where bid=?");
                query.addBindValue(ui->leBname->text().trimmed());
                query.addBindValue(ui->leWriter->text().trimmed());
                query.addBindValue(ui->leHot->text().trimmed());
                query.addBindValue(1);
                query.addBindValue(helper::tran);
            }
          else  if(ui->rbNlend->isChecked())
            {
                query.prepare("update Tbook set bname=?,writer=?,hot=?,state=? where bid=?");
                query.addBindValue(ui->leBname->text().trimmed());
                query.addBindValue(ui->leWriter->text().trimmed());
                query.addBindValue(ui->leHot->text().trimmed());
                query.addBindValue(0);
                query.addBindValue(helper::tran);
            }
            else
            {
                query.prepare("update Tbook set bname=?,writer=?,hot=? where bid=?");
                query.addBindValue(ui->leBname->text().trimmed());
                query.addBindValue(ui->leWriter->text().trimmed());
                query.addBindValue(ui->leHot->text().trimmed());
                query.addBindValue(helper::tran);
            }
            if(query.exec())
                QMessageBox::warning(this,tr("success"),tr("Update success"),QMessageBox::Close);
            else
                QMessageBox::warning(this,tr("failed"),tr("Update failed"),QMessageBox::Close);
        }

    }
    if(helper::flag==2)
    {
        if(ui->leBname->text().trimmed()=="")
        {
            QMessageBox::warning(this,tr("failed"),tr("Bookname can't be null"),QMessageBox::Close);
        }
        else
        {
            if(ui->rbLend->isChecked())
            {
                query.prepare("update Tbook set bname=?,writer=?,hot=?,state=? where bname=?");
                query.addBindValue(ui->leBname->text().trimmed());
                query.addBindValue(ui->leWriter->text().trimmed());
                query.addBindValue(ui->leHot->text().trimmed());
                query.addBindValue(1);
                query.addBindValue(helper::tran);
            }
          else  if(ui->rbNlend->isChecked())
            {
                query.prepare("update Tbook set bname=?,writer=?,hot=?,state=? where bname=?");
                query.addBindValue(ui->leBname->text().trimmed());
                query.addBindValue(ui->leWriter->text().trimmed());
                query.addBindValue(ui->leHot->text().trimmed());
                query.addBindValue(0);
                query.addBindValue(helper::tran);
            }
            else
            {
                query.prepare("update Tbook set bname=?,writer=?,hot=? where bname=?");
                query.addBindValue(ui->leBname->text().trimmed());
                query.addBindValue(ui->leWriter->text().trimmed());
                query.addBindValue(ui->leHot->text().trimmed());
                query.addBindValue(helper::tran);
            }
            if(query.exec())
                QMessageBox::warning(this,tr("success"),tr("Update success"),QMessageBox::Close);
            else
                QMessageBox::warning(this,tr("failed"),tr("Update failed"),QMessageBox::Close);
        }

    }
    db.close();
}


void init()
{

}

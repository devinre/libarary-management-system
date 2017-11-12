#include "reader.h"
#include "ui_reader.h"
#include "connection.h"
#include <QtGui/QApplication>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QObject>
#include <QDate>
#include <QCheckBox>
reader::reader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reader)
{
    ui->setupUi(this);
}

reader::~reader()
{
    delete ui;
}
helper hel;
QString helper::userid="";
void reader::on_btnSubmit_clicked()
{
   QString message=ui->teMessage->toPlainText();
   QSqlDatabase db;
   if(!createConnection(db))
   {
       QMessageBox::critical(0, qApp->tr("Cannot open database"),
                                     qApp->tr("Unable to establish a database connection."),
                                     QMessageBox::Cancel);
   }
   QSqlQuery query;
   query.prepare("insert into Tmessage(uid,mtime,content)" "values(:uid,:mtime,:content)");
      query.bindValue(":uid",hel.userid);
      query.bindValue(":mtime",QDate::currentDate().toString("yyyy-MM-dd"));
      query.bindValue(":content",message);
   //   query.exec();
   if(query.exec())
   {
       QMessageBox::warning(this,tr(""),tr("message sucessful"),QMessageBox::Close);
   }
   else  {
       QMessageBox::warning(this,tr("failed"),tr("message error"),QMessageBox::Close);
   }
   db.close();
}

void reader::on_btnExit_clicked()
{
    QWidget::close();
    ui->leSearch->clear();
    ui->teMessage->clear();
    ui->twLend->clear();
}

void reader::on_btnSearch_clicked()
{
    ui->lbBook->setVisible(true);
    ui->lbWriter->setVisible(true);
    ui->lbState->setVisible(true);
    ui->pbLend->setVisible(true);
    QString str=ui->leSearch->text().trimmed();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare("select bname,writer,state,bid from Tbook where bname=?");
    query.addBindValue(str);
    query.exec();
    query.next();
    ui->lbBook->setText(query.value(0).toString());
    ui->lbWriter->setText(query.value(1).toString());
    if(query.value(2).toInt()==1)
    {
        ui->lbState->setText("can lend");

    }
    else{
        ui->lbState->setText("can not lend");
        ui->pbLend->hide();
 //        QMessageBox::warning(this,tr("failed"),tr("The book have been lent"),QMessageBox::Close);
    }
    db.close();
}
void reader::init()
{
    ui->lbUser->setText(helper::userid);
    ui->chbRet1->setVisible(true);
    ui->chbRet2->setVisible(true);
    ui->chbRet3->setVisible(true);
    int i=0;
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare("select Tlend.bid,Tbook.bname,Tlend.ltime from Tbook,Tlend where Tlend.bid=Tbook.bid and Tlend.uid=?");
    query.addBindValue(hel.userid);
    query.exec();
    QDate date=QDate::fromString(query.value(2).toString(),"yyyy-MM-dd");
    QDate date1=date.addMonths(1);
    while(query.next())
    {
        ui->twLend->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->twLend->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->twLend->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->twLend->setItem(i,3,new QTableWidgetItem(date1.toString("yyyy-MM-dd")));
        i++;
    }
    db.close();
    ui->lbBook->hide();
    ui->lbWriter->hide();
    ui->lbState->hide();
    ui->pbLend->hide();
    ui->chbRet1->setChecked(false);
    ui->chbRet2->setChecked(false);
    ui->chbRet3->setChecked(false);
    switch(query.size())
    {
    case 0:ui->chbRet1->setVisible(false);ui->chbRet2->setVisible(false);ui->chbRet3->setVisible(false);
    case 1:ui->chbRet2->setVisible(false);ui->chbRet3->setVisible(false);
    case 2:ui->chbRet3->setVisible(false);
    default : ;
    }
}

void reader::on_btnRet_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query,query1;
    if(ui->chbRet1->isChecked())
    {
        query.prepare("delete from Tlend where bid=?");
        query.addBindValue(ui->twLend->item(0,0)->text().toInt());
        query.exec();
        query1.prepare("update Tbook set state=? where bid=?");
        query1.addBindValue(1);
        query1.addBindValue(ui->twLend->item(0,0)->text().toInt());
        query1.exec();
    }
    if(ui->chbRet2->isChecked())
    {
        query.prepare("delete from Tlend where bid=?");
        query.addBindValue(ui->twLend->item(1,0)->text().toInt());
        query.exec();
        query1.prepare("update Tbook set state=? where bid=?");
        query1.addBindValue(1);
        query1.addBindValue(ui->twLend->item(1,0)->text().toInt());
        query1.exec();
    }
    if(ui->chbRet3->isChecked())
    {
        query.prepare("delete from Tlend where bid=?");
        query.addBindValue(ui->twLend->item(2,0)->text().toInt());
        query.exec();
        query1.prepare("update Tbook set state=? where bid=?");
        query1.addBindValue(1);
        query1.addBindValue(ui->twLend->item(2,0)->text().toInt());
        query1.exec();
    }
    db.close();
    if(query.exec())
        QMessageBox::warning(this,tr("success"),tr("Return success"),QMessageBox::Close);
    ui->twLend->clear();
    init();
}

void reader::on_pushButton_clicked()
{

}

void reader::on_pbLend_clicked()
{
     QString str=ui->leSearch->text().trimmed();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query,query1;
    query.prepare("select bname,writer,state,bid from Tbook where bname=?");
    query.addBindValue(str);
    query.exec();
    query.next();
    query1.prepare("select * from Tlend where uid=?");
    query1.addBindValue(hel.userid);
    query1.exec();
    if(query1.size()==3)
        QMessageBox::warning(this,tr("failed"),tr("The have lent 3 books.Error"),QMessageBox::Close);
    else{
        QSqlQuery query3,query4;
        query3.prepare("insert into Tlend(bid,uid,ltime)" "values(:bid,:uid,:ltime)");
        query3.bindValue(":bid",query.value(3).toInt());
        query3.bindValue(":uid",hel.userid);
        query3.bindValue(":ltime",QDate::currentDate().toString("yyyy-MM-dd"));
        query4.prepare("update Tbook set state=? where bid=?");
        query4.addBindValue(0);
        query4.addBindValue(query.value(3).toInt());
        query4.next();
        if(!query4.exec()||!query3.exec())
             QMessageBox::warning(this,tr("failed"),tr("Operation error"),QMessageBox::Close);
        else
             QMessageBox::warning(this,tr("success"),tr("Operation success"),QMessageBox::Close);
    }
    db.close();
    init();
}

void reader::on_btnMod_clicked()
{
    remod.show();
}

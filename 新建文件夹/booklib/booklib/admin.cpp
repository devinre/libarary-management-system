#include "admin.h"
#include "ui_admin.h"
#include "connection.h"
#include "bookmod.h"
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

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

int helper::flag;
QString helper::tran;

void admin::on_btnAddBook_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare("insert into Tbook(bname,writer,state)" "values(?,?,?)");
    query.addBindValue(ui->leBname->text().trimmed());
    query.addBindValue(ui->leWriter->text().trimmed());
    query.addBindValue(1);
    if(!query.exec())
        QMessageBox::warning(this,tr("failed"),tr("Insert error"),QMessageBox::Close);
    else
        QMessageBox::warning(this,tr("success"),tr("Insert success"),QMessageBox::Close);
    db.close();
}

void admin::on_btnUserMod_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query,query1;
    QString str=ui->leUser->text().trimmed();
    query1.prepare("select * from Tuser where uid=?");
    query1.addBindValue(str);
    query1.exec();
    if(query1.next())
    {
        int lev=query1.value(2).toInt();
        if(ui->rbAdmin->isChecked())
        {
            if(lev==1||lev==0)
            {
                query.prepare("update Tuser set level=? where uid=?");
                query.addBindValue(2);
                query.addBindValue(str);
                if(!query.exec())
                    QMessageBox::warning(this,tr("failed"),tr("Operation error"),QMessageBox::Close);
                else
                    QMessageBox::warning(this,tr("success"),tr("operation success"),QMessageBox::Close);
            }
            else QMessageBox::warning(this,tr("success"),tr("Already be admin"),QMessageBox::Close);
        }
        else if(ui->rbUser->isChecked())
        {
            if(query1.value(2).toInt()==2)
            {
                query.prepare("update Tuser set level=? where uid=?");
                query.addBindValue(1);
                query.addBindValue(str);
                if(!query.exec())
                    QMessageBox::warning(this,tr("failed"),tr("Operation error"),QMessageBox::Close);
                else
                    QMessageBox::warning(this,tr("success"),tr("operation success"),QMessageBox::Close);
            }
            else QMessageBox::warning(this,tr("success"),tr("Already be user"),QMessageBox::Close);
        }
        else if(ui->rbdelUser->isChecked())
        {
            query.prepare("delete from Tuser where uid=?");
            query.addBindValue(str);
            if(!query.exec())
                QMessageBox::warning(this,tr("failed"),tr("Delete error"),QMessageBox::Close);
            else
                QMessageBox::warning(this,tr("success"),tr("Delete success"),QMessageBox::Close);
        }
        else
            QMessageBox::warning(this,tr("warnning"),tr("Chosed nothing"),QMessageBox::Close);
    }
    else
    {
        QMessageBox::warning(this,tr("failed"),tr("User not exist"),QMessageBox::Close);
    }
    db.close();

}

void admin::on_rbAdmin_clicked()
{
    ui->rbAdmin->setChecked(true);
}

void admin::on_rbUser_clicked()
{
    ui->rbUser->setChecked(true);
}

void admin::on_rbdelUser_clicked()
{
    ui->rbdelUser->setChecked(true);
}

void admin::on_btnbookDel_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    if(ui->lebookDel->text().trimmed()!="")
    {
        if(ui->cbDel->currentText().trimmed()==QObject::trUtf8("书号"))
        {
            query.prepare("delete from Tbook where bid=?");
            query.addBindValue(ui->lebookDel->text().trimmed().toInt());
            if(query.exec())
            {
                 ui->lebookDel->clear();
                QMessageBox::warning(this,tr("success"),tr("Delete success"),QMessageBox::Close);
            }
            else
            {
                ui->lebookDel->clear();
                QMessageBox::warning(this,tr("error"),tr("Book number not exist.Error"),QMessageBox::Close);
            }
        }
        if(ui->cbDel->currentText().trimmed()==QObject::trUtf8("书名"))
        {
            query.prepare("delete from Tbook where bname=?");
            query.addBindValue(ui->lebookDel->text().trimmed());
            if(query.exec())
            {
                QMessageBox::warning(this,tr("success"),tr("Delete success"),QMessageBox::Close);
                ui->lebookDel->clear();
            }
            else
            {
                 ui->lebookDel->clear();
                QMessageBox::warning(this,tr("error"),tr("Book number not exist.Error"),QMessageBox::Close);
            }
    }
    }
    else
       QMessageBox::warning(this,tr("error"),tr("Input is null.Error"),QMessageBox::Close);
    db.close();
}

void admin::on_btnbookUpd_clicked()
{
    if(ui->lebookDel->text().trimmed()!="")
    {
        if(ui->cbDel->currentText().trimmed()==QObject::trUtf8("书号"))
        {
             helper::flag=1;
             helper::tran=ui->lebookDel->text().trimmed();

        }
        if(ui->cbDel->currentText().trimmed()==QObject::trUtf8("书名"))
        {
            helper::flag=2;
             helper::tran=ui->lebookDel->text().trimmed();
        }
    }
    else
       QMessageBox::warning(this,tr("error"),tr("Input is null.Error"),QMessageBox::Close);


    bm.show();
}
//搜索某人留言
void admin::on_btnMsgSea_clicked()
{
    QString str=ui->leMesUser->text().trimmed();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare("select * from Tmessage where uid=?");
    query.addBindValue(str);
    query.exec();
    if(query.size()<1)
         QMessageBox::warning(this,tr("error"),tr("User isn't exist or no messages"),QMessageBox::Close);
    else
    {
        static QSqlQueryModel *mode  = new QSqlQueryModel(ui->tvMes);   //建立一个Model
            mode->setQuery("select * from Tmessage where uid='"+ui->leMesUser->text()+"'",db) ;
            mode->setHeaderData(0,Qt::Horizontal,QObject::tr("mid"));
            mode->setHeaderData(1,Qt::Horizontal,QObject::tr("user"));
            mode->setHeaderData(3,Qt::Horizontal,QObject::tr("message"));
            mode->setHeaderData(2,Qt::Horizontal,QObject::tr("time"));
            ui->tvMes->setModel(mode);
            ui->tvMes->show();
    }
    db.close();
}
//显示全部留言
void admin::on_btnMsgAll_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    static QSqlQueryModel *mode  = new QSqlQueryModel(ui->tvMes);   //建立一个Model
        mode->setQuery("select * from Tmessage ",db) ;
        mode->setHeaderData(0,Qt::Horizontal,QObject::tr("mid"));
        mode->setHeaderData(1,Qt::Horizontal,QObject::tr("user"));
        mode->setHeaderData(3,Qt::Horizontal,QObject::tr("message"));
        mode->setHeaderData(2,Qt::Horizontal,QObject::tr("time"));
        ui->tvMes->setModel(mode);
        ui->tvMes->show();
        db.close();
}
//按留言号删除留言
void admin::on_btnMesdel_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare("delete from Tmessage where mid=?");
    query.addBindValue(ui->leDemid->text().trimmed().toInt());
    query.exec();
    if(!query.exec())
        QMessageBox::warning(this,tr("error"),tr("Message isn't exist"),QMessageBox::Close);
    else
        QMessageBox::warning(this,tr("success"),tr("Delete success"),QMessageBox::Close);
    db.close();

}
//删除所有留言
void admin::on_pushButton_clicked()
{
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.exec("truncate Tmessage");   //清空留言表
    if(!query.exec())
        QMessageBox::warning(this,tr("error"),tr("Delete failed"),QMessageBox::Close);
    else
        QMessageBox::warning(this,tr("success"),tr("Delete success"),QMessageBox::Close);
    db.close();
}

void admin::on_btnExit_clicked()
{
    QWidget::close();
    ui->leBname->clear();
    ui->leMesUser->clear();
    ui->leDemid->clear();
    ui->leUser->clear();
    ui->leWriter->clear();
    ui->lebookDel->clear();
    ui->rbAdmin->setChecked(false);
    ui->rbdelUser->setChecked(false);
    ui->rbUser->setChecked(false);
}

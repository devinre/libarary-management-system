#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include "connection.h"
#include "logindialog.h"
#include <QPalette>
#include <QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->myBookTable->insertRow(0);
    ui->myBookTable->insertRow(1);
    ui->myBookTable->insertRow(2);
    ui->myBookTable->insertRow(3);
    ui->myBookTable->insertRow(4);
    ui->myBookTable->insertRow(5);
    ui->myBookTable->insertRow(6);
    ui->myBookTable->insertRow(7);
    ui->myBookTable->insertRow(8);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(qtimeSlot()));
    //ui->dateLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    timer->start(1000);

}

Widget::~Widget()
{
    delete ui;
}
//不断刷新时间
void Widget::qtimeSlot()
{
    ui->dateLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

//重绘事件,添加背景
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap("image2.jpg"));
}
//切换stackedWidget页面
void Widget::on_mianPageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_myBorrowButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void Widget::on_adminButton_clicked()
{
    //QString ad="admin";
    //if(helper::userid==ad)
        ui->stackedWidget->setCurrentIndex(2);

}
void Widget::on_changePwdButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
//清空按钮
void Widget::on_clearButton_clicked()
{
    ui->oldPwdLE->clear();
    ui->newPwdLE->clear();
    ui->newPwdLESure->clear();
}

void Widget::on_exitButton_clicked()
{

}
//提交按钮，确认修改密码
void Widget::on_sumbitButton_clicked()
{
    if(ui->oldPwdLE->text()==ui->newPwdLE->text())
    {
        QMessageBox::information(this,tr("失败"),tr("新密码和旧密码不能一样！"),QMessageBox::Ok);
    }
    else if(ui->newPwdLE->text()!=ui->newPwdLESure->text())
    {
        QMessageBox::critical(this,tr("失败"),tr("新密码不一致！"),QMessageBox::Cancel);
    }
    else
    {
        QString oldPwd=ui->oldPwdLE->text();
        QString newPwd=ui->newPwdLE->text();

        QSqlDatabase db;
        if(!createConnection(db)) qDebug()<<"widget database not open";

        QSqlQuery query,query1;
        query.prepare(tr("select * from Tuser where id=?"));
        query.addBindValue(helper::userid);
        query.exec();
        while(query.next())
        {
            if(query.value(1).toString() == oldPwd)
            {
                query1.prepare(tr("update Tuser set pwd=? where id=?"));
                query1.addBindValue(newPwd);
                query1.addBindValue(helper::userid);
                if(!query1.exec())
                    QMessageBox::warning(this,tr("failed"),tr("修改失败！"),QMessageBox::Close);
                else
                    QMessageBox::warning(this,tr("success"),tr("修改成功！"),QMessageBox::Close);

             }
            else
            {
                QMessageBox::information(this,tr("失败"),tr("原密码错误！"),QMessageBox::Ok);
                qDebug()<<"id:"<<query.value(0).toString();
                qDebug()<<"pwd:"<<query.value(1).toString();
                qDebug()<<"email:"<<query.value(2).toString();
                qDebug()<<"qq:"<<query.value(3).toString();
            }
        }

        db.close();
    }
}
//注销按钮，重新登陆
void Widget::on_returnLoginButton_clicked()
{
    ui->adminUserTable->clearContents();
    ui->searchBookTable->clearContents();
    ui->searchLineEdit->clear();
    ui->myBookTable->clearContents();
    // 先关闭主界面，其实是隐藏起来了，并没有真正退出
    this->close();
    // 新建LoginDialog对象
    LoginDialog dlg;
    // 如果按下了“登陆”按钮，则再次显示主界面
    // 否则，因为现在已经没有显示的界面了，所以程序将退出
    if(dlg.exec()== QDialog::Accepted)
    {
        this->show();     
        on_mianPageButton_clicked();
        ui->userLabel->setText(helper::userid);//更新登录用户
        init();
        if(helper::userid=="admin")
            ui->adminButton->setVisible(true);
        else
            ui->adminButton->setVisible(false);
    }


}
//初始化函数
void Widget::init()
{
    on_mianPageButton_clicked();

    ui->userLabel->setText(helper::userid);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->userLabel->setPalette(pe);
    if(helper::userid=="admin")
        ui->adminButton->setVisible(true);
    else
        ui->adminButton->setVisible(false);

    int i=0;
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query,query1,query2;
    //create database tea default character set utf8 collate utf8_general_ci;
    query.exec(tr("create table if not exists Tbook (bookId varchar(10) primary key,bookName varchar(20),authorName varchar(20),"
                  "lendPeople varchar(20),state varchar(20))"));

    //query1.exec(tr("create table "+helper::userid+"Lend(bookId varchar(10) primary key,bookName varchar(20),authorName varchar(20),"
                         //"heat varchar(20),lendDate varchar(20),backDate varchar(20))"));

    bool flag = query2.exec("select * from "+helper::userid+"");
    if(flag)
        qDebug()<<"slect table "<<helper::userid<<" success!";
    while(query2.next())
    {
        ui->myBookTable->setItem(i,0,new QTableWidgetItem(query2.value(0).toString()));
        ui->myBookTable->setItem(i,1,new QTableWidgetItem(query2.value(1).toString()));
        ui->myBookTable->setItem(i,2,new QTableWidgetItem(query2.value(2).toString()));
        ui->myBookTable->setItem(i,3,new QTableWidgetItem(query2.value(3).toString()));
        ui->myBookTable->setItem(i,4,new QTableWidgetItem(query2.value(4).toString()));
        //ui->myBookTable->setItem(i,5,new QTableWidgetItem(query2.value(5).toString()));
        i++;
    }
    /*switch(query2.size())
    {
    case 0:ui->checkBox_4->setVisible(false);ui->checkBox_5->setVisible(false);ui->checkBox_6->setVisible(false);
           ui->checkBox_7->setVisible(false);ui->checkBox_8->setVisible(false);ui->checkBox_9->setVisible(false);
           ui->checkBox_10->setVisible(false);ui->checkBox_11->setVisible(false);ui->checkBox_12->setVisible(false);break;
    case 1:ui->checkBox_4->setVisible(true);ui->checkBox_5->setVisible(false);ui->checkBox_6->setVisible(false);
           ui->checkBox_7->setVisible(false);ui->checkBox_8->setVisible(false);ui->checkBox_9->setVisible(false);
           ui->checkBox_10->setVisible(false);ui->checkBox_11->setVisible(false);ui->checkBox_12->setVisible(false);break;
    case 2:ui->checkBox_4->setVisible(true);ui->checkBox_5->setVisible(true);ui->checkBox_6->setVisible(false);
           ui->checkBox_7->setVisible(false);ui->checkBox_8->setVisible(false);ui->checkBox_9->setVisible(false);
           ui->checkBox_10->setVisible(false);ui->checkBox_11->setVisible(false);ui->checkBox_12->setVisible(false);break;
    case 3:ui->checkBox_4->setVisible(true);ui->checkBox_5->setVisible(true);ui->checkBox_6->setVisible(true);
           ui->checkBox_7->setVisible(false);ui->checkBox_8->setVisible(false);ui->checkBox_9->setVisible(false);
           ui->checkBox_10->setVisible(false);ui->checkBox_11->setVisible(false);ui->checkBox_12->setVisible(false);break;
    case 4:ui->checkBox_4->setVisible(true);ui->checkBox_5->setVisible(true);ui->checkBox_6->setVisible(true);
           ui->checkBox_7->setVisible(true);ui->checkBox_8->setVisible(false);ui->checkBox_9->setVisible(false);
           ui->checkBox_10->setVisible(false);ui->checkBox_11->setVisible(false);ui->checkBox_12->setVisible(false);break;
    case 5:ui->checkBox_4->setVisible(true);ui->checkBox_5->setVisible(true);ui->checkBox_6->setVisible(true);
           ui->checkBox_7->setVisible(true);ui->checkBox_8->setVisible(true);ui->checkBox_9->setVisible(false);
           ui->checkBox_10->setVisible(false);ui->checkBox_11->setVisible(false);ui->checkBox_12->setVisible(false);break;
    default :break;
    }*/
    /*query.prepare("select * from Tbook where bookname=?");
    query.addBindValue();
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
    }*/
    db.close();
}
//搜索按钮
void Widget::on_searchButton_clicked()
{
    ui->searchBookTable->clearContents();
    int i = 0;
    QString search = ui->searchLineEdit->text();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query1;
    query1.prepare("select * from Tbook where bookName=?");
    query1.addBindValue(search);
    query1.exec();
    while(query1.next())
      {
        QTableWidgetItem *idCenter = new QTableWidgetItem(query1.value(0).toString());

        idCenter->setTextAlignment(Qt::AlignCenter);
        ui->searchBookTable->setItem(i,0,idCenter);
        ui->searchBookTable->setItem(i,1,new QTableWidgetItem(query1.value(1).toString()));
        ui->searchBookTable->setItem(i,2,new QTableWidgetItem(query1.value(2).toString()));
        ui->searchBookTable->setItem(i,3,new QTableWidgetItem(query1.value(3).toString()));
        ui->searchBookTable->setItem(i,4,new QTableWidgetItem(query1.value(4).toString()));
            //ui->searchBookTable->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
        i++;
      }
    switch(query1.size())
      {
    case 0:ui->checkBox->setVisible(false);ui->checkBox_2->setVisible(false);ui->checkBox_3->setVisible(false);break;
    case 1:ui->checkBox->setVisible(true);ui->checkBox_2->setVisible(false);ui->checkBox_3->setVisible(false);break;
    case 2:ui->checkBox->setVisible(true);ui->checkBox_2->setVisible(true);ui->checkBox_3->setVisible(false);break;
    case 3:ui->checkBox->setVisible(true);ui->checkBox_2->setVisible(true);ui->checkBox_3->setVisible(true);break;
    default :break;
      }
    if(ui->searchBookTable->item(0,4)!=NULL)
    {
        if(ui->searchBookTable->item(0,4)->text()=="Null")
            ui->checkBox->setCheckable(false);
        if(ui->searchBookTable->item(1,4)!=NULL)
        {
            if(ui->searchBookTable->item(1,4)->text()=="Null")
                ui->checkBox_2->setCheckable(false);
        }
    }

    db.close();

}
//借取按钮
void Widget::on_bookBorrowButton_clicked()
{
    //QString
    if(ui->checkBox->isChecked())
    {
        int i=0;
        QString bookId,bookName,authorName,lendPeople,lendDate,backDate;//userId;
        bookId = ui->searchBookTable->item(0,0)->text();
        bookName = ui->searchBookTable->item(0,1)->text();
        authorName = ui->searchBookTable->item(0,2)->text();
        lendPeople = helper::userid;
        lendDate = QDate::currentDate().toString("yyyy-MM-dd");

        //QDate date = QDate::fromString(lendDate,"yyyy-MM-dd").addMonths(1);
        backDate = QDate::currentDate().addMonths(1).toString("yyyy-MM-dd");
        QSqlDatabase db;
        createConnection(db);
        QSqlQuery query,query1,query2;

        query.prepare("insert into "+helper::userid+"(bookId,bookName,authorName,lendDate,backDate)"
                          "values(:bookId,:bookName,:authorName,:lendDate,:backDate)");
        //query1.prepare(tr("insert into Tborrow (bookId,bookName,authorName,heat,lendDate,backDate)"
                         //" values (bookId=?,bookName=?,authorName=?,heat=?,lendDate=?,backDate=?)"));
        //query1.addBindValue(userId);
        query.bindValue(":bookId",bookId);
        query.bindValue(":bookName",bookName);
        query.bindValue(":authorName",authorName);
        //query.bindValue(":lendPeople",lendPeople);
        query.bindValue(":lendDate",lendDate);
        query.bindValue(":backDate",backDate);
        //query.addBindValue(delaymoney);
        if(query.exec())
        {
            qDebug()<<"insert table "<<helper::userid<<" success!";
            ui->myBookTable->insertRow(0);
            query1.exec("select * from "+helper::userid+"");
            //query1.exec(tr("select * from Tborrow"));
            while(query1.next())
            {
                ui->myBookTable->setItem(i,0,new QTableWidgetItem(query1.value(0).toString()));
                ui->myBookTable->setItem(i,1,new QTableWidgetItem(query1.value(1).toString()));
                ui->myBookTable->setItem(i,2,new QTableWidgetItem(query1.value(2).toString()));
                ui->myBookTable->setItem(i,3,new QTableWidgetItem(query1.value(3).toString()));
                ui->myBookTable->setItem(i,4,new QTableWidgetItem(query1.value(4).toString()));
                //ui->myBookTable->setItem(i,5,new QTableWidgetItem(query1.value(5).toString()));
                i++;
            }
            query2.prepare(tr("update Tbook set lendPeople=?,state=? where bookId=?"));
            query2.addBindValue(lendPeople);
            query2.addBindValue("Null");
            query2.addBindValue(ui->searchBookTable->item(0,0)->text());
            query2.exec();

            QMessageBox::information(this,tr("成功"),tr("借书成功！"),QMessageBox::Ok);
        }
        else
            qDebug()<<"borrow failure:"<<query.lastError();
        //qDebug()<<ui->searchBookTable->item(0,0)->text()<<ui->searchBookTable->item(0,1)->text()<<ui->searchBookTable->item(0,2)->text()
               //<<ui->searchBookTable->item(0,3)->text()<<ui->searchBookTable->item(0,4)->text();
        db.close();
        ui->checkBox->setChecked(false);
    }
    if(ui->checkBox_2->isChecked())
    {
        int i=0;
        QString bookId,bookName,authorName,lendPeople,lendDate,backDate;//userId;
        bookId = ui->searchBookTable->item(1,0)->text();
        bookName = ui->searchBookTable->item(1,1)->text();
        authorName = ui->searchBookTable->item(1,2)->text();
        lendPeople = helper::userid;
        lendDate = QDate::currentDate().toString("yyyy-MM-dd");
        //serId = helper::userid;
        //QDate date = QDate::fromString(lendDate,"yyyy-MM-dd").addMonths(1);
        backDate = QDate::currentDate().addMonths(1).toString("yyyy-MM-dd");
        QSqlDatabase db;
        createConnection(db);
        QSqlQuery query,query1,query2;

        query.prepare("insert into "+helper::userid+"(bookId,bookName,authorName,lendDate,backDate)"
                          "values(:bookId,:bookName,:authorName,:lendDate,:backDate)");

        query.bindValue(":bookId",bookId);
        query.bindValue(":bookName",bookName);
        query.bindValue(":authorName",authorName);
        //query.bindValue(":heat",heat);
        query.bindValue(":lendDate",lendDate);
        query.bindValue(":backDate",backDate);
        //query.addBindValue(delaymoney);
        if(query.exec())
        {
            ui->myBookTable->insertRow(0);
            query1.exec("select * from "+helper::userid+"");
            while(query1.next())
            {
                ui->myBookTable->setItem(i,0,new QTableWidgetItem(query1.value(0).toString()));
                ui->myBookTable->setItem(i,1,new QTableWidgetItem(query1.value(1).toString()));
                ui->myBookTable->setItem(i,2,new QTableWidgetItem(query1.value(2).toString()));
                ui->myBookTable->setItem(i,3,new QTableWidgetItem(query1.value(3).toString()));
                ui->myBookTable->setItem(i,4,new QTableWidgetItem(query1.value(4).toString()));
                //ui->myBookTable->setItem(i,5,new QTableWidgetItem(query1.value(5).toString()));
                i++;
            }
            query2.prepare(tr("update Tbook set lendPeople=?,state=? where bookId=?"));
            query2.addBindValue(lendPeople);
            query2.addBindValue("Null");
            query2.addBindValue(ui->searchBookTable->item(1,0)->text());
            query2.exec();

            QMessageBox::information(this,tr("成功"),tr("借书成功！"),QMessageBox::Ok);
        }
        else
            qDebug()<<"borrow failure:"<<query.lastError();
        //qDebug()<<ui->searchBookTable->item(0,0)->text()<<ui->searchBookTable->item(0,1)->text()<<ui->searchBookTable->item(0,2)->text()
               //<<ui->searchBookTable->item(0,3)->text()<<ui->searchBookTable->item(0,4)->text();
        db.close();
        ui->checkBox_2->setChecked(false);
    }
}
//还书按钮
void Widget::on_bookRepayButton_clicked()
{
     int j=0;
    if(ui->checkBox_4->isChecked())
    {
        QSqlDatabase db;
        createConnection(db);
        QSqlQuery query,query1;
        query.prepare("delete from "+helper::userid+" where bookId=?");
        query.addBindValue(ui->myBookTable->item(0,0)->text());
        if(query.exec())
        {
            query1.prepare(tr("update Tbook set lendPeople=?,state=? where bookId=?"));
            query1.addBindValue("Null");
            query1.addBindValue("yes");
            query1.addBindValue(ui->myBookTable->item(0,0)->text());
            query1.exec();
        }

        db.close();
        j=1;
        //ui->myBookTable->removeRow(0);
    }
    if(ui->checkBox_5->isChecked())
    {
        QSqlDatabase db;
        createConnection(db);
        QSqlQuery query,query1;
        query.prepare("delete from "+helper::userid+" where bookId=?");
        query.addBindValue(ui->myBookTable->item(1,0)->text());
        if(query.exec())
        {
            query1.prepare(tr("update Tbook set lendPeople=?,state=? where bookId=?"));
            query1.addBindValue("Null");
            query1.addBindValue("yes");
            query1.addBindValue(ui->myBookTable->item(1,0)->text());
            query1.exec();
        }
        db.close();
        //ui->myBookTable->removeRow(1);
        j=2;
    }
    if(ui->checkBox_4->isChecked()&&ui->checkBox_5->isChecked())
            j=3;
    switch(j)
        {
            case 1:ui->myBookTable->removeRow(0);break;
            case 2:ui->myBookTable->removeRow(1);break;
            case 3:ui->myBookTable->removeRow(0);ui->myBookTable->removeRow(0);break;
            default :break;
        }
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
}

//添加
void Widget::on_adminAddButton_clicked()
{
    QString bookId,bookName,authorName,lendPeople;
    bookId = ui->adminBookNumberLE->text();
    bookName = ui->adminBookNameLE->text();
    authorName = ui->adminAuthorLE->text();
    lendPeople = ui->adminHotLE->text();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare(tr("insert into Tbook (bookId,bookName,authorName,lendPeople,state)" "values(:bookId,:bookName,:authorName,:lendPeople,:state)"));

    query.bindValue(":bookId",bookId);
    query.bindValue(":bookName",bookName);
    query.bindValue(":authorName",authorName);
    query.bindValue(":lendPeople",lendPeople);
    query.bindValue(":state","yes");
    if(query.exec())
    {
        QMessageBox::information(this,tr("成功"),tr("添加图书成功！"),QMessageBox::Ok);

        QTableWidgetItem *idCenter = new QTableWidgetItem(bookId);
        idCenter->setTextAlignment(Qt::AlignCenter);
        ui->adminTable->setItem(0,0,idCenter);
        ui->adminTable->setItem(0,1,new QTableWidgetItem(bookName));
        ui->adminTable->setItem(0,2,new QTableWidgetItem(authorName));
        ui->adminTable->setItem(0,3,new QTableWidgetItem(lendPeople));
        ui->adminTable->setItem(0,4,new QTableWidgetItem("yes"));

        ui->adminBookNumberLE->clear();
        ui->adminBookNameLE->clear();
        ui->adminAuthorLE->clear();
        //ui->adminHotLE->clear();
    }
    else
    {
        QMessageBox::critical(this,tr("失败"),tr("添加失败！"),QMessageBox::Cancel);
        qDebug()<<query.lastError();
    }

    db.close();
}
//更新
void Widget::on_adminUpdataButton_clicked()
{
    QString bookId,bookName,authorName,lendPeople;
    bookId = ui->adminBookNumberLE->text();
    bookName = ui->adminBookNameLE->text();
    authorName = ui->adminAuthorLE->text();
    lendPeople = ui->adminHotLE->text();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare(tr("update Tbook set bookName=?,authorName=?,lendPeople=? where bookId=?"));
    query.addBindValue(bookName);
    query.addBindValue(authorName);
    query.addBindValue(lendPeople);
    query.addBindValue(bookId);
    if(query.exec())
    {
        QMessageBox::information(this,tr("提示"),tr("更新成功！"),QMessageBox::Ok);

        QTableWidgetItem *idCenter = new QTableWidgetItem(bookId);
        idCenter->setTextAlignment(Qt::AlignCenter);
        ui->adminTable->setItem(0,0,idCenter);
        ui->adminTable->setItem(0,1,new QTableWidgetItem(bookName));
        ui->adminTable->setItem(0,2,new QTableWidgetItem(authorName));
        ui->adminTable->setItem(0,3,new QTableWidgetItem(lendPeople));

        ui->adminBookNumberLE->clear();
        ui->adminBookNameLE->clear();
        ui->adminAuthorLE->clear();
        ui->adminHotLE->clear();
    }
    else
        QMessageBox::information(this,tr("提示"),tr("更新失败！"),QMessageBox::Ok);

    db.close();
}
//删除
void Widget::on_adminDeleteButton_clicked()
{
    int ok;
    ok=QMessageBox::information(this,tr("提示"),tr("是否删除该书？"),QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::Yes)
    {
        QString bookId;
        bookId = ui->adminBookNumberLE->text();
        QSqlDatabase db;
        createConnection(db);
        QSqlQuery query;
        query.prepare(tr("delete from Tbook where bookId=?"));
        query.addBindValue(bookId);
        query.exec();

        db.close();

        ui->adminTable->clearContents();
    }
}
//查询
void Widget::on_adminSearchButton_clicked()
{
    QString bookId;
    bookId = ui->adminBookNumberLE->text();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare(tr("select * from Tbook where bookId=?"));
    query.addBindValue(bookId);
    query.exec();
    if(query.next())
    {
        QTableWidgetItem *idCenter = new QTableWidgetItem(query.value(0).toString());
        idCenter->setTextAlignment(Qt::AlignCenter);
        ui->adminTable->setItem(0,0,idCenter);
        ui->adminTable->setItem(0,1,new QTableWidgetItem(query.value(1).toString()));
        ui->adminTable->setItem(0,2,new QTableWidgetItem(query.value(2).toString()));
        ui->adminTable->setItem(0,3,new QTableWidgetItem(query.value(3).toString()));
        ui->adminTable->setItem(0,4,new QTableWidgetItem(query.value(4).toString()));
        //db.close();
    }
    else
        QMessageBox::information(this,tr("提示"),tr("没有这本书！"),QMessageBox::Ok);
    db.close();
}
//删除用户
void Widget::on_adminDeleteUserBt_clicked()
{
    int ok;
    ok=QMessageBox::information(this,tr("提示"),tr("是否删除该用户？"),QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::Yes)
    {
        QString user;
        user = ui->adminUserLE->text();
        QSqlDatabase db;
        createConnection(db);
        QSqlQuery query;
        query.prepare(tr("delete from Tuser where id=?"));
        query.addBindValue(user);
        query.exec();

        db.close();

        ui->adminUserTable->clearContents();
    }
}
//查询用户
void Widget::on_adminSearchUserBt_clicked()
{
    QString user;
    user = ui->adminUserLE->text();
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.prepare(tr("select * from Tuser where id=?"));
    query.addBindValue(user);
    query.exec();
    if(query.next())
    {

        ui->adminUserTable->setItem(0,0,new QTableWidgetItem(query.value(0).toString()));
        ui->adminUserTable->setItem(0,1,new QTableWidgetItem(query.value(1).toString()));
        ui->adminUserTable->setItem(0,2,new QTableWidgetItem(query.value(2).toString()));
        ui->adminUserTable->setItem(0,3,new QTableWidgetItem(query.value(3).toString()));

    }
    else
        QMessageBox::information(this,tr("提示"),tr("没有这个用户！"),QMessageBox::Ok);
    db.close();
}
//查询所有用户
void Widget::on_adminSearchAllUserBt_clicked()
{
    int i=0;
    QSqlDatabase db;
    createConnection(db);
    QSqlQuery query;
    query.exec(tr("select * from Tuser"));

    while(query.next())
    {

        ui->adminUserTable->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->adminUserTable->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->adminUserTable->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->adminUserTable->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        i++;

    }
        //QMessageBox::information(this,tr("提示"),tr("没有这个用户！"),QMessageBox::Ok);

    db.close();
}

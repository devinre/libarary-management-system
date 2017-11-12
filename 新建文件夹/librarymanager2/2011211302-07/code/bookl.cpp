#include "bookl.h"
#include "ui_bookl.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QLabel.h>
#include <stdio.h>
#include <qfile.h>
#include <QTextstream.h>
#include <qdatetime.h>


bookinfor binfor4,binfor5,binfor6;
booklend blinfor1,blinfor2;
informationforuser infor7;
int t2=0,k2=0,p2=0;

bookl::bookl(QWidget *parent):
    QDialog(parent),
    bookl_ui(new Ui::bookl)
{
    bookl_ui->setupUi(this);
    bookl_ui->table->setSelectionBehavior ( QAbstractItemView::SelectRows);//设置选择行为，以行为单位
    bookl_ui->table->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    bookl_ui->table->setEditTriggers ( QAbstractItemView::NoEditTriggers );//禁止编辑

    setWindowFlags(Qt::FramelessWindowHint);
    bookl_ui->exit->setFlat(true);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明


    QFile file("dat\\le.dat");
    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>blinfor2.book_id;
            in>>blinfor2.user_id;
            in>>blinfor2.lend_time1;
            in>>blinfor2.lend_time2;
            in>>blinfor2.lend_time3;
            in>>blinfor2.back_time1;
            in>>blinfor2.back_time2;
            in>>blinfor2.back_time3;
            t2++;
        }
        file.close();
    }
    p2=t2/10+1;
    QString page=QString::number(p2, 10);
    bookl_ui->total->setText(page);

    k2=1;
    showle(k2);


    installEventFilter(this);
    setMouseTracking(true);
    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(500);//定时器开始计时，其中1000表示1000ms即1秒
}


bookl::~bookl()
{
    delete bookl_ui;
}

void bookl::timerUpDate()
{
    QString date=QString::number(ye)+"-"+QString::number(mo)+"-"+QString::number(da);
    bookl_ui->time->setText(date);
}


bool bookl::eventFilter(QObject *obj, QEvent *event)
{
    if((event->type() == QEvent::MouseButtonPress)||
       (event->type() == QEvent::MouseButtonDblClick)||
       (event->type() == QEvent::MouseButtonRelease)||
       (event->type() == QEvent::MouseMove)||
       (event->type() == QEvent::MouseTrackingChange))
    {
       operateFlag = BUSY;
    }
    if(event->type() == QEvent::KeyPress||(event->type() == QEvent::KeyRelease)){
       operateFlag = BUSY;
    }
    return 0;
}

void bookl::showle(int begin)
{
    int i=0,j=0,l=-1;
    QFile file("dat\\le.dat");
    QString le,ba,fuhao="/";
    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>blinfor2.book_id;
            in>>blinfor2.user_id;
            in>>blinfor2.lend_time1;
            in>>blinfor2.lend_time2;
            in>>blinfor2.lend_time3;
            in>>blinfor2.back_time1;
            in>>blinfor2.back_time2;
            in>>blinfor2.back_time3;
            le=blinfor2.lend_time1+fuhao+blinfor2.lend_time2+fuhao+blinfor2.lend_time3;
            ba=blinfor2.back_time1+fuhao+blinfor2.back_time2+fuhao+blinfor2.back_time3;
            l++;
            if(l/10==(begin-1))
            {
                bookl_ui->table->setItem(i,j,new QTableWidgetItem(blinfor2.book_id));
                bookl_ui->table->setItem(i,j+1,new QTableWidgetItem(blinfor2.user_id));
                bookl_ui->table->setItem(i,j+2,new QTableWidgetItem(le));
                bookl_ui->table->setItem(i,j+3,new QTableWidgetItem(ba));
                i++;
                j=0;
            }
        }
        file.close();
        while(i<=10)
        {
            bookl_ui->table->setItem(i-1,j,new QTableWidgetItem(NULL));
            bookl_ui->table->setItem(i-1,j+1,new QTableWidgetItem(NULL));
            bookl_ui->table->setItem(i-1,j+2,new QTableWidgetItem(NULL));
            bookl_ui->table->setItem(i-1,j+3,new QTableWidgetItem(NULL));
            i++;
            j=0;
        }
    }
}

void bookl::on_okbutton_clicked()
{
    blinfor1.book_id=bookl_ui->book_id->text();
    blinfor1.user_id=bookl_ui->user_id->text();

    QDateTime timeadd;
    /*QDateTime dateTime = QDateTime::currentDateTime();
    int y=dateTime.date().year();
    int m=dateTime.date().month();
    int d=dateTime.date().day();*/
    int y=ye,m=mo,d=da;
    blinfor1.lend_time1=QString::number(y, 10);
    blinfor1.lend_time2=QString::number(m, 10);
    blinfor1.lend_time3=QString::number(d, 10);

    switch(m)
    {
    case(1):case(3):case(5):case(7):case(8):case(10):case(12):
        if((da+30)>31)
        {
            m++;
            d=d-1;
            if((m-1)==12)
            {
                y++;
                m=1;
            }
        }
        else
        {
            d=d+30;
        }
        break;
    case(4):case(6):case(9):case(11):
        m++;
        d=d;
        break;
    case(2):
        if(y%4==0&&y%100!=0||y%400==0 )
        {
            m++;
            d=d+1;
        }
        else
        {
            m++;
            d=d+2;
        }
            break;
    }
        blinfor1.back_time1=QString::number(y, 10);
        blinfor1.back_time2=QString::number(m, 10);
        blinfor1.back_time3=QString::number(d, 10);


    int b=0;
    QFile file("dat\\le.dat");
    QFile file11("dat\\le_else.dat");
    QFile file2("dat\\binfor.dat");
    QFile file22("dat\\binfor_else.dat");
    QFile file3("dat\\data.dat");


    //检查书号和用户id是否存在
    if( blinfor1.book_id==NULL&& blinfor1.user_id==NULL)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Please input the information."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file2);
        file2.open(QIODevice::ReadOnly );
        while(!in.atEnd())
        {
            in>>binfor5.book_id;
            in>>binfor5.book_name;
            in>>binfor5.book_author;
            in>>binfor5.book_press;
            in>>binfor5.book_all;
            in>>binfor5.book_rest;
            if(binfor5.book_id==blinfor1.book_id)
            {
                b=1;
                file2.close();
                break;
            }
        }
        file2.close();

        if(b==0)
        {
            QMessageBox::warning(this,tr("Warning"),tr("The id of book dosen't exists."),QMessageBox::Yes);
            bookl_ui->book_id->clear();
        }
        else if(b==1)
        {
            QTextStream in(&file3);
            file3.open(QIODevice::ReadOnly );
            while(!in.atEnd())
            {
                in>>infor7.id;
                in>>infor7.key;
                in>>infor7.email;
                in>>infor7.phone;
                in>>infor7.code;
                if(infor7.id==blinfor1.user_id)
                {
                    b=2;
                    file3.close();
                    break;
                }
            }
            file3.close();
            if(b==1)
            {
                QMessageBox::warning(this,tr("Warning"),tr("The id of user dosen't exists."),QMessageBox::Yes);
                bookl_ui->user_id->clear();
            }
        }
    }


    //存入借书信息和归还书籍
    int c=0,q=0,num=0,a=0;
    QString newrest;
    if(!file.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else if(b==2)
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>blinfor2.book_id;
            in>>blinfor2.user_id;
            in>>blinfor2.lend_time1;
            in>>blinfor2.lend_time2;
            in>>blinfor2.lend_time3;
            in>>blinfor2.back_time1;
            in>>blinfor2.back_time2;
            in>>blinfor2.back_time3;

            if(blinfor2.book_id==blinfor1.book_id&&blinfor2.user_id==blinfor1.user_id&&bookl_ui->checkBox->isChecked())
            {
                QMessageBox::warning(this,tr("Warning"),tr("The user has to borrow this book."),QMessageBox::Yes);
                a=1;
                bookl_ui->book_id->clear();
                bookl_ui->user_id->clear();
                break;
            }
            if(blinfor2.user_id==blinfor1.user_id&&bookl_ui->checkBox->isChecked())
            {
                num++;
            }
        }
        file.close();

        if(a==0)
        {
            if(bookl_ui->checkBox->isChecked())
            {
                if(!file2.open(QIODevice::ReadOnly )){
                    QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
                }
                else if(!file22.open(QIODevice::WriteOnly ))
                {
                    QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
                }
                else
                {
                    QTextStream in2(&file2);
                    QTextStream out2(&file22);
                    while(!in2.atEnd())
                    {
                        in2>>binfor5.book_id;
                        in2>>binfor5.book_name;
                        in2>>binfor5.book_author;
                        in2>>binfor5.book_press;
                        in2>>binfor5.book_all;
                        in2>>binfor5.book_rest;
                        if(binfor5.book_id==blinfor1.book_id)
                        {
                            int z=binfor5.book_rest.toInt();
                            newrest=binfor5.book_rest;

                                if(num==3)
                                {
                                    QMessageBox::warning(this,tr("Warning"),tr("This user has already lended three books."),QMessageBox::Yes);
                                    q=1;
                                }
                                else if(z==0)
                                {
                                    QMessageBox::warning(this,tr("Warning"),tr("There is no residual of this book."),QMessageBox::Yes);
                                    q=1;
                                }
                                else
                                {
                                    z--;
                                    newrest=QString::number(z,10);
                                }


                            out2<<binfor5.book_id<<" ";
                            out2<<binfor5.book_name<<" ";
                            out2<<binfor5.book_author<<" ";
                            out2<<binfor5.book_press<<" ";
                            out2<<binfor5.book_all<<" ";
                            out2<<newrest<<" ";
                        }
                        else
                        {
                            out2<<binfor5.book_id<<" ";
                            out2<<binfor5.book_name<<" ";
                            out2<<binfor5.book_author<<" ";
                            out2<<binfor5.book_press<<" ";
                            out2<<binfor5.book_all<<" ";
                            out2<<binfor5.book_rest<<" ";
                        }
                    }
                    file2.close();
                    file22.close();
                    rename("dat\\binfor.dat","dat\\binfor1.dat");
                    rename("dat\\binfor_else.dat","dat\\binfor.dat");
                    remove("dat\\binfor1.dat");


                    if(q==0)
                    {
                        if(!file.open(QIODevice::Append )){
                                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
                        }
                        else
                        {
                            QTextStream out(&file);
                            out<<blinfor1.book_id<<" ";
                            out<<blinfor1.user_id<<" ";
                            out<<blinfor1.lend_time1<<" ";
                            out<<blinfor1.lend_time2<<" ";
                            out<<blinfor1.lend_time3<<" ";
                            out<<blinfor1.back_time1<<" ";
                            out<<blinfor1.back_time2<<" ";
                            out<<blinfor1.back_time3<<" ";
                            QMessageBox::warning(this,tr("Success"),tr("The success of borrowing books."),QMessageBox::Yes);
                            file.close();
                        }
                    }
                }
            }
        }
        if(bookl_ui->checkBox_2->isChecked())
        {
            if(!file2.open(QIODevice::ReadOnly )){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
            }
            else if(!file22.open(QIODevice::WriteOnly ))
            {
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
            }
            else
            {
                QTextStream in2(&file2);
                QTextStream out2(&file22);
                while(!in2.atEnd())
                {
                    in2>>binfor5.book_id;
                    in2>>binfor5.book_name;
                    in2>>binfor5.book_author;
                    in2>>binfor5.book_press;
                    in2>>binfor5.book_all;
                    in2>>binfor5.book_rest;
                    if(binfor5.book_id==blinfor1.book_id)
                    {
                        int z=binfor5.book_rest.toInt();
                        newrest=binfor5.book_rest;
                            if(!file.open(QIODevice::ReadOnly )){
                                    QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
                            }
                            else if(!file11.open(QIODevice::WriteOnly )){
                                    QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
                            }
                            else
                            {
                                QTextStream in(&file);
                                QTextStream out(&file11);
                                while(!in.atEnd())
                                {
                                    in>>blinfor2.book_id;
                                    in>>blinfor2.user_id;
                                    in>>blinfor2.lend_time1;
                                    in>>blinfor2.lend_time2;
                                    in>>blinfor2.lend_time3;
                                    in>>blinfor2.back_time1;
                                    in>>blinfor2.back_time2;
                                    in>>blinfor2.back_time3;

                                    if(blinfor2.book_id==blinfor1.book_id&&blinfor2.user_id==blinfor1.user_id)
                                    {
                                        z++;
                                        newrest=QString::number(z,10);
                                    }
                                    else
                                    {
                                        out<<blinfor2.book_id<<" ";
                                        out<<blinfor2.user_id<<" ";
                                        out<<blinfor2.lend_time1<<" ";
                                        out<<blinfor2.lend_time2<<" ";
                                        out<<blinfor2.lend_time3<<" ";
                                        out<<blinfor2.back_time1<<" ";
                                        out<<blinfor2.back_time2<<" ";
                                        out<<blinfor2.back_time3<<" ";
                                    }
                                }
                                file.close();
                                file11.close();
                                rename("dat\\le.dat","dat\\le1.dat");
                                rename("dat\\le_else.dat","dat\\le.dat");
                                remove("dat\\le1.dat");
                                QMessageBox::warning(this,tr("Success"),tr("Return the book of success."),QMessageBox::Yes);
                            }

                        out2<<binfor5.book_id<<" ";
                        out2<<binfor5.book_name<<" ";
                        out2<<binfor5.book_author<<" ";
                        out2<<binfor5.book_press<<" ";
                        out2<<binfor5.book_all<<" ";
                        out2<<newrest<<" ";
                    }
                    else
                    {
                        out2<<binfor5.book_id<<" ";
                        out2<<binfor5.book_name<<" ";
                        out2<<binfor5.book_author<<" ";
                        out2<<binfor5.book_press<<" ";
                        out2<<binfor5.book_all<<" ";
                        out2<<binfor5.book_rest<<" ";
                    }
                }
                file2.close();
                file22.close();
                rename("dat\\binfor.dat","dat\\binfor1.dat");
                rename("dat\\binfor_else.dat","dat\\binfor.dat");
                remove("dat\\binfor1.dat");
            }
        }
    }
}

void bookl::on_checkBox_clicked()   //两个checkbox不能同时显示true
{
    if(bookl_ui->checkBox_2->isChecked())
         bookl_ui->checkBox->setChecked(false);
}

void bookl::on_checkBox_2_clicked()
{
    if(bookl_ui->checkBox->isChecked())
         bookl_ui->checkBox_2->setChecked(false);
}

void bookl::on_exit_clicked()
{
    reject();
}

void bookl::on_update_clicked()
{
    k2=1;
    QString page=QString::number(k2,10);
    bookl_ui->now->setText(page);
    showle(k2);
}

void bookl::on_lastpage_clicked()
{
    if(k2==1)
    {
         QMessageBox::warning(this,tr("Warning"),tr("There is no one on the page."),QMessageBox::Yes);
    }
    else
    {
        k2--;
        QString page=QString::number(k2,10);
        bookl_ui->now->setText(page);
        showle(k2);
    }
}

void bookl::on_nextpage_clicked()
{
    if(k2==p2)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Not the next page."),QMessageBox::Yes);
    }
    else
    {
        k2++;
        QString page=QString::number(k2,10);
        bookl_ui->now->setText(page);
        showle(k2);
    }
}

void bookl::on_begin_clicked()
{
    if(k2==1)
    {
         QMessageBox::warning(this,tr("Warning"),tr("Is the first page."),QMessageBox::Yes);
    }
    else
    {
        k2=1;
        QString page=QString::number(k2,10);
        bookl_ui->now->setText(page);
        showle(k2);
    }
}

void bookl::on_end_clicked()
{
    if(k2==p2)
    {
         QMessageBox::warning(this,tr("Warning"),tr("Is the end page."),QMessageBox::Yes);
    }
    else
    {
        k2=p2;
        QString page=QString::number(k2,10);
        bookl_ui->now->setText(page);
        showle(k2);
    }
}

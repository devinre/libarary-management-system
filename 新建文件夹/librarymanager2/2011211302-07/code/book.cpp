#include "book.h"
#include "ui_book.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QLabel.h>
#include <stdio.h>
#include <qfile.h>
#include <QTextstream.h>

bookinfor binfor1,binfor2,binfor3;
QString bookid;
int seek=0;
int t=0,k=0,p=0;

book::book(QWidget *parent):
    QDialog(parent),
    book_ui(new Ui::book)
{
    book_ui->setupUi(this);
    book_ui->table->setSelectionBehavior ( QAbstractItemView::SelectRows);//设置选择行为，以行为单位
    book_ui->table->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    book_ui->table->setEditTriggers ( QAbstractItemView::NoEditTriggers );//禁止编辑

    book_ui->bexit->setFlat(true);//无边框
    setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明


    if(book_ui->seekline->text()==NULL)
    {
        QFile f("dat\\binfor.dat");
        if(!f.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&f);
            while(!in.atEnd())
            {
                in>>binfor2.book_id;
                in>>binfor2.book_name;
                in>>binfor2.book_author;
                in>>binfor2.book_press;
                in>>binfor2.book_all;
                in>>binfor2.book_rest;
                if(binfor2.book_id!=NULL)
                {
                    t++;
                }
            }
            f.close();
        }
        p=t/10+1;
        QString page=QString::number(p, 10);
        book_ui->total->setText(page);

        k=1;
        tableshow(k);
    }
    else
    {
        seek=1;
    }



    installEventFilter(this);
    setMouseTracking(true);
    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(500);//定时器开始计时，其中1000表示1000ms即1秒
}


book::~book()
{
    delete book_ui;
}

void book::timerUpDate()
{
    QString date=QString::number(ye)+"-"+QString::number(mo)+"-"+QString::number(da);
    book_ui->time->setText(date);
}


bool book::eventFilter(QObject *obj, QEvent *event)
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

void book::on_add_clicked()
{
    int a=0;
    binfor1.book_id=book_ui->book_id->text();
    binfor1.book_name=book_ui->book_name->text();
    binfor1.book_author=book_ui->book_author->text();
    binfor1.book_press=book_ui->book_press->text();
    binfor1.book_all=book_ui->book_all->text();
    binfor1.book_rest=binfor1.book_all;
    if(binfor1.book_id==NULL||binfor1.book_name==NULL||binfor1.book_author==NULL||binfor1.book_press==NULL)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Please enter all options!"),QMessageBox::Yes);
    }
    else
    {
        QFile file("dat\\binfor.dat");
        if(!file.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&file);
            while(!in.atEnd())
            {
                in>>binfor2.book_id;
                in>>binfor2.book_name;
                in>>binfor2.book_author;
                in>>binfor2.book_press;
                in>>binfor2.book_all;
                in>>binfor2.book_rest;
                if(binfor2.book_id==binfor1.book_id)
                {
                    QMessageBox::warning(this,tr("Warning"),tr("The id of book already exists."),QMessageBox::Yes);
                    book_ui->book_id->clear();
                    file.close();
                    a=1;
                    break;
                }
            }
        }
        file.close();

        if(!file.open(QIODevice::Append )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
        }
        else if(a==0)
        {
            QTextStream out(&file);
            out<<binfor1.book_id<<" ";
            out<<binfor1.book_name<<" ";
            out<<binfor1.book_author<<" ";
            out<<binfor1.book_press<<" ";
            out<<binfor1.book_all<<" ";
            out<<binfor1.book_rest<<" ";
            QMessageBox::warning(this,tr("Success"),tr("A successful entry books information."),QMessageBox::Yes);
            file.close();
            book_ui->book_id->clear();
            book_ui->book_name->clear();
            book_ui->book_author->clear();
            book_ui->book_press->clear();
            book_ui->book_all->clear();
        }
    }


    t=0;
    QFile f("dat\\binfor.dat");
        if(!f.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&f);
            while(!in.atEnd())
            {
                in>>binfor2.book_id;
                in>>binfor2.book_name;
                in>>binfor2.book_author;
                in>>binfor2.book_press;
                in>>binfor2.book_all;
                in>>binfor2.book_rest;
                if(binfor2.book_id!=NULL)
                {
                    t++;
                }
            }
            f.close();
        }
        p=t/10+1;
        QString page=QString::number(p, 10);
        book_ui->total->setText(page);

}

void book::on_bexit_clicked()
{
    reject();
}

void book::tableshow(int begin)
{
    int i=0,j=0,l=-1;
    QFile file("dat\\binfor.dat");
    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>binfor3.book_id;
            in>>binfor3.book_name;
            in>>binfor3.book_author;
            in>>binfor3.book_press;
            in>>binfor3.book_all;
            in>>binfor3.book_rest;
            l++;
            if(l/10==(begin-1))
            {
                book_ui->table->setItem(i,j,new QTableWidgetItem(binfor3.book_id));
                book_ui->table->setItem(i,j+1,new QTableWidgetItem(binfor3.book_name));
                book_ui->table->setItem(i,j+2,new QTableWidgetItem(binfor3.book_author));
                book_ui->table->setItem(i,j+3,new QTableWidgetItem(binfor3.book_press));
                book_ui->table->setItem(i,j+4,new QTableWidgetItem(binfor3.book_all));
                book_ui->table->setItem(i,j+5,new QTableWidgetItem(binfor3.book_rest));
                i++;
                j=0;
            }
        }
        file.close();
        while(i<=9)
        {
            book_ui->table->setItem(i,j,new QTableWidgetItem(binfor3.book_id));
            book_ui->table->setItem(i,j+1,new QTableWidgetItem(binfor3.book_name));
            book_ui->table->setItem(i,j+2,new QTableWidgetItem(binfor3.book_author));
            book_ui->table->setItem(i,j+3,new QTableWidgetItem(binfor3.book_press));
            book_ui->table->setItem(i,j+4,new QTableWidgetItem(binfor3.book_all));
            book_ui->table->setItem(i,j+5,new QTableWidgetItem(binfor3.book_rest));
            i++;
            j=0;
        }
    }
}

void book::tableshow2(int begin)
{
    int i=0,j=0,l=-1;
    QFile file("dat\\temporary.dat");
    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>binfor3.book_id;
            in>>binfor3.book_name;
            in>>binfor3.book_author;
            in>>binfor3.book_press;
            in>>binfor3.book_all;
            in>>binfor3.book_rest;
            l++;
            if(l/10==(begin-1))
            {
                book_ui->table->setItem(i,j,new QTableWidgetItem(binfor3.book_id));
                book_ui->table->setItem(i,j+1,new QTableWidgetItem(binfor3.book_name));
                book_ui->table->setItem(i,j+2,new QTableWidgetItem(binfor3.book_author));
                book_ui->table->setItem(i,j+3,new QTableWidgetItem(binfor3.book_press));
                book_ui->table->setItem(i,j+4,new QTableWidgetItem(binfor3.book_all));
                book_ui->table->setItem(i,j+5,new QTableWidgetItem(binfor3.book_rest));
                i++;
                j=0;
            }
        }
        file.close();
        while(i<=9)
        {
            book_ui->table->setItem(i,j,new QTableWidgetItem(binfor3.book_id));
            book_ui->table->setItem(i,j+1,new QTableWidgetItem(binfor3.book_name));
            book_ui->table->setItem(i,j+2,new QTableWidgetItem(binfor3.book_author));
            book_ui->table->setItem(i,j+3,new QTableWidgetItem(binfor3.book_press));
            book_ui->table->setItem(i,j+4,new QTableWidgetItem(binfor3.book_all));
            book_ui->table->setItem(i,j+5,new QTableWidgetItem(binfor3.book_rest));
            i++;
            j=0;
        }
    }
}


void book::on_freshen_clicked()
{ 
    k=1;
    QString page=QString::number(k,10);
    book_ui->now->setText(page);
    if(seek==0)
        tableshow(k);
    else
        tableshow2(k);
    if(book_ui->seekline->text()==NULL)
    {
        t=0;
        QFile f("dat\\binfor.dat");
        if(!f.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&f);
            while(!in.atEnd())
            {
                in>>binfor2.book_id;
                in>>binfor2.book_name;
                in>>binfor2.book_author;
                in>>binfor2.book_press;
                in>>binfor2.book_all;
                in>>binfor2.book_rest;
                if(binfor2.book_id!=NULL)
                {
                    t++;
                }
            }
            f.close();
        }
        p=t/10+1;
        QString page=QString::number(p, 10);
        book_ui->total->setText(page);
    }
}


void book::on_delete_2_clicked()
{
    QString deleteid;
    int a=0;
    deleteid=book_ui->deleteid->text();
    QFile file("dat\\binfor.dat");
    QFile file2("dat\\binfor_else.dat");

    if(deleteid==NULL)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Please input id."),QMessageBox::Yes);
        a=3;
    }
    else if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>binfor2.book_id;
            in>>binfor2.book_name;
            in>>binfor2.book_author;
            in>>binfor2.book_press;
            in>>binfor2.book_all;
            in>>binfor2.book_rest;
            if(binfor2.book_id==deleteid)
            {
                a=1;
                if(binfor2.book_all!=binfor2.book_rest)
                {
                    a=5;
                }
                break;
            }
        }
        file.close();
    }
    if(a==0)
    {
        QMessageBox::warning(this,tr("Warning"),tr("The id of book dosen't exists."),QMessageBox::Yes);
        book_ui->deleteid->clear();
    }
    else if(a==5)
    {
        QMessageBox::warning(this,tr("Warning"),tr("This book is borrowed by someone,you can not delete or update it."),QMessageBox::Yes);
        book_ui->deleteid->clear();
    }
    else if(!file.open(QIODevice::ReadOnly )&&a!=3){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else if(!file2.open(QIODevice::WriteOnly )&&a!=3){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else if(a!=3)
    {
        QTextStream in(&file);
        QTextStream out(&file2);
        while(!in.atEnd())
        {
            in>>binfor2.book_id;
            in>>binfor2.book_name;
            in>>binfor2.book_author;
            in>>binfor2.book_press;
            in>>binfor2.book_all;
            in>>binfor2.book_rest;
            if(deleteid!=binfor2.book_id)
            {
                out<<binfor2.book_id<<" ";
                out<<binfor2.book_name<<" ";
                out<<binfor2.book_author<<" ";
                out<<binfor2.book_press<<" ";
                out<<binfor2.book_all<<" ";
                out<<binfor2.book_rest<<" ";
            }
        }
        file.close();
        file2.close();
        rename("dat\\binfor.dat","dat\\binfor1.dat");
        rename("dat\\binfor_else.dat","dat\\binfor.dat");
        remove("dat\\binfor1.dat");
        QMessageBox::warning(this,tr("Success"),tr("Successful delete."),QMessageBox::Yes);
        book_ui->deleteid->clear();
    }


        t=0;
        QFile f("dat\\binfor.dat");
        if(!f.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&f);
            while(!in.atEnd())
            {
                in>>binfor2.book_id;
                in>>binfor2.book_name;
                in>>binfor2.book_author;
                in>>binfor2.book_press;
                in>>binfor2.book_all;
                in>>binfor2.book_rest;
                if(binfor2.book_id!=NULL)
                {
                    t++;
                }
            }
            f.close();
        }
        p=t/10+1;
        QString page=QString::number(p, 10);
        book_ui->total->setText(page);
}

void book::on_pushButton_2_clicked()
{
    int a=0;
    QFile file("dat\\binfor.dat");
    QFile file2("dat\\binfor_else.dat");


    binfor1.book_id=book_ui->book_id->text();
    binfor1.book_name=book_ui->book_name->text();
    binfor1.book_author=book_ui->book_author->text();
    binfor1.book_press=book_ui->book_press->text();
    binfor1.book_all=book_ui->book_all->text();
    binfor1.book_rest=binfor1.book_all;


    if(binfor1.book_id==NULL||binfor1.book_name==NULL||binfor1.book_author==NULL||binfor1.book_press==NULL)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Please enter all options!"),QMessageBox::Yes);
    }
    else if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>binfor2.book_id;
            in>>binfor2.book_name;
            in>>binfor2.book_author;
            in>>binfor2.book_press;
            in>>binfor2.book_all;
            in>>binfor2.book_rest;
            if(binfor2.book_id==binfor1.book_id)
            {
                a=1;
                if(binfor2.book_all!=binfor2.book_rest)
                {
                    a=3;
                }
                break;
            }
        }
        file.close();
        if(a==0)
        {
            QMessageBox::warning(this,tr("Warning"),tr("The id of book dosen't exists."),QMessageBox::Yes);
            book_ui->book_id->clear();
        }
        else if(a==3)
        {
            QMessageBox::warning(this,tr("Warning"),tr("This book is borrowed by someone,you can not delete or update it."),QMessageBox::Yes);
            book_ui->book_id->clear();
        }
        else
        {
            if(!file.open(QIODevice::ReadOnly )&&a!=3){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
            }
            else if(!file2.open(QIODevice::WriteOnly )&&a!=3){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
            }
            else
            {
                QTextStream in(&file);
                QTextStream out(&file2);
                while(!in.atEnd())
                {
                    in>>binfor2.book_id;
                    in>>binfor2.book_name;
                    in>>binfor2.book_author;
                    in>>binfor2.book_press;
                    in>>binfor2.book_all;
                    in>>binfor2.book_rest;
                    if(binfor1.book_id==binfor2.book_id)
                    {
                        out<<binfor1.book_id<<" ";
                        out<<binfor1.book_name<<" ";
                        out<<binfor1.book_author<<" ";
                        out<<binfor1.book_press<<" ";
                        out<<binfor1.book_all<<" ";
                        out<<binfor1.book_rest<<" ";
                    }
                    else
                    {
                        out<<binfor2.book_id<<" ";
                        out<<binfor2.book_name<<" ";
                        out<<binfor2.book_author<<" ";
                        out<<binfor2.book_press<<" ";
                        out<<binfor2.book_all<<" ";
                        out<<binfor2.book_rest<<" ";
                    }
                }
                file.close();
                file2.close();
                rename("dat\\binfor.dat","dat\\binfor1.dat");
                rename("dat\\binfor_else.dat","dat\\binfor.dat");
                remove("dat\\binfor1.dat");
                QMessageBox::warning(this,tr("Success"),tr("Successful updata."),QMessageBox::Yes);

                book_ui->book_id->clear();
                book_ui->book_name->clear();
                book_ui->book_author->clear();
                book_ui->book_press->clear();
                book_ui->book_all->clear();
            }
        }
    }
}

void book::on_nextpage_clicked()
{
    if(k==p)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Not the next page."),QMessageBox::Yes);
    }
    else
    {
        k++;
        QString page=QString::number(k,10);
        book_ui->now->setText(page);
        if(seek==0)
            tableshow(k);
        else
            tableshow2(k);
    }
}

void book::on_lastpage_clicked()
{
    if(k==1)
    {
         QMessageBox::warning(this,tr("Warning"),tr("There is no one on the page."),QMessageBox::Yes);
    }
    else
    {
        k--;
        QString page=QString::number(k,10);
        book_ui->now->setText(page);
        if(seek==0)
            tableshow(k);
        else
            tableshow2(k);
    }
}

void book::on_end_clicked()
{
    if(k==p)
    {
         QMessageBox::warning(this,tr("Warning"),tr("Is the end page."),QMessageBox::Yes);
    }
    else
    {
        k=p;
        QString page=QString::number(k,10);
        book_ui->now->setText(page);
        if(seek==0)
            tableshow(k);
        else
            tableshow2(k);
    }

}

void book::on_begin_clicked()
{
    if(k==1)
    {
         QMessageBox::warning(this,tr("Warning"),tr("Is the first page."),QMessageBox::Yes);
    }
    else
    {
        k=1;
        QString page=QString::number(k,10);
        book_ui->now->setText(page);
        if(seek==0)
            tableshow(k);
        else
            tableshow2(k);
    }
}


void book::on_seek_clicked()
{
    if(book_ui->seekline->text()==NULL)
    {
        t=0;
        seek=0;
        QFile f("dat\\binfor.dat");
        if(!f.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&f);
            while(!in.atEnd())
            {
                in>>binfor2.book_id;
                in>>binfor2.book_name;
                in>>binfor2.book_author;
                in>>binfor2.book_press;
                in>>binfor2.book_all;
                in>>binfor2.book_rest;
                t++;
            }
            f.close();
        }
        p=t/10+1;
        QString page=QString::number(p, 10);
        book_ui->total->setText(page);

        k=1;
        tableshow(k);
    }
    else
    {
        t=0;
        QString keyword=book_ui->seekline->text();
        QFile f("dat\\binfor.dat");
        QFile f2("dat\\temporary.dat");
        if(!f.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else if(!f2.open(QIODevice::WriteOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&f);
            QTextStream out(&f2);
            while(!in.atEnd())
            {
                in>>binfor2.book_id;
                in>>binfor2.book_name;
                in>>binfor2.book_author;
                in>>binfor2.book_press;
                in>>binfor2.book_all;
                in>>binfor2.book_rest;
                if(book_ui->kind->currentText().trimmed()==QObject::trUtf8("book's id")&&keyword==binfor2.book_id)
                {
                    out<<binfor2.book_id<<" ";
                    out<<binfor2.book_name<<" ";
                    out<<binfor2.book_author<<" ";
                    out<<binfor2.book_press<<" ";
                    out<<binfor2.book_all<<" ";
                    out<<binfor2.book_rest<<" ";
                    t++;
                }
                if(book_ui->kind->currentText().trimmed()==QObject::trUtf8("name")&&keyword==binfor2.book_name)
                {
                    out<<binfor2.book_id<<" ";
                    out<<binfor2.book_name<<" ";
                    out<<binfor2.book_author<<" ";
                    out<<binfor2.book_press<<" ";
                    out<<binfor2.book_all<<" ";
                    out<<binfor2.book_rest<<" ";
                    t++;
                }
                if(book_ui->kind->currentText().trimmed()==QObject::trUtf8("author")&&keyword==binfor2.book_author)
                {
                    out<<binfor2.book_id<<" ";
                    out<<binfor2.book_name<<" ";
                    out<<binfor2.book_author<<" ";
                    out<<binfor2.book_press<<" ";
                    out<<binfor2.book_all<<" ";
                    out<<binfor2.book_rest<<" ";
                    t++;
                }
                if(book_ui->kind->currentText().trimmed()==QObject::trUtf8("book concern")&&keyword==binfor2.book_press)
                {
                    out<<binfor2.book_id<<" ";
                    out<<binfor2.book_name<<" ";
                    out<<binfor2.book_author<<" ";
                    out<<binfor2.book_press<<" ";
                    out<<binfor2.book_all<<" ";
                    out<<binfor2.book_rest<<" ";
                    t++;
                }
            }
            f.close();
            f2.close();
            if(t==0)
            {
                QMessageBox::warning(this,tr("Warning"),tr("No relevant information you're looking for."),QMessageBox::Yes);
            }
            else
            {
                seek=1;
                p=t/10+1;
                QString page=QString::number(p, 10);
                book_ui->total->setText(page);
                book_ui->now->setText("1");

                k=1;
                tableshow2(k);
            }
        }
    }

}

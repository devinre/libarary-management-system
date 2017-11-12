#include "reader.h"
#include "ui_reader.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qdatetime.h>
#include <QString>

int t4=0,k4=0,p4=0;
int t5=0,k5=0,p5=0;
int seek2=0;
bookinfor binfor7;
booklend blinfor3;
QDateTime nowtime=QDateTime::currentDateTime();

reader::reader(QWidget *parent):
    QDialog(parent),
    reader_ui(new Ui::reader)
{
    reader_ui->setupUi(this);

    installEventFilter(this);
    setMouseTracking(true);

    reader_ui->rexit->setFlat(true);//无边框
    setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明


    reader_ui->table1->setSelectionBehavior ( QAbstractItemView::SelectRows);//设置选择行为，以行为单位
    reader_ui->table1->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    reader_ui->table1->setEditTriggers ( QAbstractItemView::NoEditTriggers );//禁止编辑

    reader_ui->table2->setSelectionBehavior ( QAbstractItemView::SelectRows);//设置选择行为，以行为单位
    reader_ui->table2->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    reader_ui->table2->setEditTriggers ( QAbstractItemView::NoEditTriggers );//禁止编辑

    QFile f("dat\\binfor.dat");
    if(!f.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&f);
        while(!in.atEnd())
        {
            in>>binfor7.book_id;
            in>>binfor7.book_name;
            in>>binfor7.book_author;
            in>>binfor7.book_press;
            in>>binfor7.book_all;
            in>>binfor7.book_rest;
            t4++;
        }
        f.close();
    }
    p4=t4/10+1;
    QString page=QString::number(p4, 10);
    reader_ui->total1->setText(page);

    k4=1;
    table1show(k4);

    reader_ui->time->setText(nowtime.toString("yyyy-MM-dd"));
    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(10000);//定时器开始计时，其中1000表示1000ms即1秒
    QTimer *timer2 = new QTimer(this);   //新建定时器
    connect(timer2,SIGNAL(timeout()),this,SLOT(timerStart()));//关联定时器计满信号和相应的槽函数
    timer2->start(13000);//定时器开始计时，其中1000表示1000ms即1秒
}


reader::~reader()
{
    delete reader_ui;
}

bool reader::eventFilter(QObject *obj, QEvent *event)
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


void reader::timerUpDate()
{
    if(operateFlag==FREE)
    {
        nowtime=nowtime.addDays(1);
        reader_ui->time->setText(nowtime.toString("yyyy-MM-dd"));
    }
}
void reader::timerStart()
{
    operateFlag=FREE;
}

void reader::on_rpc_clicked()
{
    kw.show();
}

void reader::on_rexit_clicked()
{
    reject();
}

void reader::table2show()
{
    int i=0,j=0;
    QFile file("dat\\le.dat");
    QString le,ba,fuhao="/",uid;

    //QDateTime dateTime = QDateTime::currentDateTime();
    QDateTime dateTime=nowtime;
    int yy=dateTime.date().year();
    int mm=dateTime.date().month();
    int dd=dateTime.date().day();
    int num=0;

    QFile fi("dat\\x12.dat");
    if(!fi.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&fi);
        in>>uid;
        fi.close();
    }

    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>blinfor3.book_id;
            in>>blinfor3.user_id;
            in>>blinfor3.lend_time1;
            in>>blinfor3.lend_time2;
            in>>blinfor3.lend_time3;
            in>>blinfor3.back_time1;
            in>>blinfor3.back_time2;
            in>>blinfor3.back_time3;
            le=blinfor3.lend_time1+fuhao+blinfor3.lend_time2+fuhao+blinfor3.lend_time3;
            ba=blinfor3.back_time1+fuhao+blinfor3.back_time2+fuhao+blinfor3.back_time3;
            if(uid==blinfor3.user_id)
            {
                reader_ui->table2->setItem(i,j,new QTableWidgetItem(blinfor3.book_id));
                reader_ui->table2->setItem(i,j+1,new QTableWidgetItem(le));
                reader_ui->table2->setItem(i,j+2,new QTableWidgetItem(ba));
                i++;
                j=0;
                int yyy=blinfor3.back_time1.toInt();
                int mmm=blinfor3.back_time2.toInt();
                int ddd=blinfor3.back_time3.toInt();
                if(yy>yyy||(yyy==yy&&mm>mmm)||(yyy==yy&&mmm==mm&&dd>ddd))
                {
                    num++;
                }
            }
        }
        file.close();
        QString nu=QString::number(num);
        reader_ui->num->setText(nu);
    }
}


void reader::table1show(int begin)
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
            in>>binfor7.book_id;
            in>>binfor7.book_name;
            in>>binfor7.book_author;
            in>>binfor7.book_press;
            in>>binfor7.book_all;
            in>>binfor7.book_rest;
            l++;
            if(l/10==(begin-1))
            {
                reader_ui->table1->setItem(i,j,new QTableWidgetItem(binfor7.book_id));
                reader_ui->table1->setItem(i,j+1,new QTableWidgetItem(binfor7.book_name));
                reader_ui->table1->setItem(i,j+2,new QTableWidgetItem(binfor7.book_author));
                reader_ui->table1->setItem(i,j+3,new QTableWidgetItem(binfor7.book_press));
                reader_ui->table1->setItem(i,j+4,new QTableWidgetItem(binfor7.book_rest));
                i++;
                j=0;
            }
        }
        file.close();
        while(i<=9)
        {
            reader_ui->table1->setItem(i,j,new QTableWidgetItem(binfor7.book_id));
            reader_ui->table1->setItem(i,j+1,new QTableWidgetItem(binfor7.book_name));
            reader_ui->table1->setItem(i,j+2,new QTableWidgetItem(binfor7.book_author));
            reader_ui->table1->setItem(i,j+3,new QTableWidgetItem(binfor7.book_press));
            reader_ui->table1->setItem(i,j+4,new QTableWidgetItem(binfor7.book_rest));
            i++;
            j=0;
        }
    }
}

void reader::table1show2(int begin)
{
    int i=0,j=0,l=-1;
    QFile file("dat\\temporary2.dat");
    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>binfor7.book_id;
            in>>binfor7.book_name;
            in>>binfor7.book_author;
            in>>binfor7.book_press;
            in>>binfor7.book_all;
            in>>binfor7.book_rest;
            l++;
            if(l/10==(begin-1))
            {
                reader_ui->table1->setItem(i,j,new QTableWidgetItem(binfor7.book_id));
                reader_ui->table1->setItem(i,j+1,new QTableWidgetItem(binfor7.book_name));
                reader_ui->table1->setItem(i,j+2,new QTableWidgetItem(binfor7.book_author));
                reader_ui->table1->setItem(i,j+3,new QTableWidgetItem(binfor7.book_press));
                reader_ui->table1->setItem(i,j+4,new QTableWidgetItem(binfor7.book_rest));
                i++;
                j=0;
            }
        }
        file.close();
        while(i<=9)
        {
            reader_ui->table1->setItem(i,j,new QTableWidgetItem(binfor7.book_id));
            reader_ui->table1->setItem(i,j+1,new QTableWidgetItem(binfor7.book_name));
            reader_ui->table1->setItem(i,j+2,new QTableWidgetItem(binfor7.book_author));
            reader_ui->table1->setItem(i,j+3,new QTableWidgetItem(binfor7.book_press));
            reader_ui->table1->setItem(i,j+4,new QTableWidgetItem(binfor7.book_rest));
            i++;
            j=0;
        }
    }
}

void reader::on_lastpage1_clicked()
{
    if(k4==1)
    {
         QMessageBox::warning(this,tr("Warning"),tr("There is no one on the page."),QMessageBox::Yes);
    }
    else
    {
        k4--;
        QString page=QString::number(k4,10);
        reader_ui->now1->setText(page);
        if(seek2==0)
            table1show(k4);
        else
            table1show2(k4);
    }
}

void reader::on_nextpage1_clicked()
{
    if(k4==p4)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Not the next page."),QMessageBox::Yes);
    }
    else
    {
        k4++;
        QString page=QString::number(k4,10);
        reader_ui->now1->setText(page);
        if(seek2==0)
            table1show(k4);
        else
            table1show2(k4);
    }
}

void reader::on_pushButton_clicked()
{
    table2show();
}

void reader::on_seek_clicked()
{
    if(reader_ui->seekline->text()==NULL)
    {
        t4=0;
        seek2=0;
        QFile f("dat\\binfor.dat");
        if(!f.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&f);
            while(!in.atEnd())
            {
                in>>binfor7.book_id;
                in>>binfor7.book_name;
                in>>binfor7.book_author;
                in>>binfor7.book_press;
                in>>binfor7.book_all;
                in>>binfor7.book_rest;
                t4++;
            }
            f.close();
        }
        p4=t4/10+1;
        QString page=QString::number(p4, 10);
        reader_ui->total1->setText(page);

        k4=1;
        table1show(k4);
    }
    else
    {
        t4=0;
        QString keyword=reader_ui->seekline->text();
        QFile f("dat\\binfor.dat");
        QFile f2("dat\\temporary2.dat");
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
                in>>binfor7.book_id;
                in>>binfor7.book_name;
                in>>binfor7.book_author;
                in>>binfor7.book_press;
                in>>binfor7.book_all;
                in>>binfor7.book_rest;
                if(binfor7.book_name.indexOf(keyword)!=-1||binfor7.book_author.indexOf(keyword)!=-1||binfor7.book_press.indexOf(keyword)!=-1)
                {
                    out<<binfor7.book_id<<" ";
                    out<<binfor7.book_name<<" ";
                    out<<binfor7.book_author<<" ";
                    out<<binfor7.book_press<<" ";
                    out<<binfor7.book_all<<" ";
                    out<<binfor7.book_rest<<" ";
                    t4++;
                }
            }
            f.close();
            f2.close();
            if(t4==0)
            {
                QMessageBox::warning(this,tr("Warning"),tr("No relevant information you're looking for."),QMessageBox::Yes);
            }
            else
            {
                seek2=1;
                p4=t4/10+1;
                QString page=QString::number(p4, 10);
                reader_ui->total1->setText(page);
                reader_ui->now1->setText("1");

                k4=1;
                table1show2(k4);
            }
        }
    }
}

void reader::on_pushButton_2_clicked() //留言
{
    if(reader_ui->message->toPlainText()==NULL)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Input error."),QMessageBox::Yes);
    }
    else
    {
        QFile file("dat\\message.dat");
        QString message,uid;
        int a=0;

        QFile fi("dat\\x12.dat");
        if(!fi.open(QIODevice::ReadOnly )){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&fi);
            in>>uid;
            fi.close();
        }

        if(!file.open(QIODevice::ReadOnly)){
                QMessageBox::warning(this,tr("Warning"),tr("At present there is no message."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&file);
            while(!in.atEnd())
            {
                message=in.readLine();
                if(message.indexOf(uid)==0)
                {
                   a=1;
                }
            }
            file.close();
        }
        if(a==1)
        {
            QMessageBox::warning(this,tr("Warning"),tr("You have already leaved a message."),QMessageBox::Yes);
        }
        else if(!file.open(QIODevice::Append)){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
        }
        else
        {
            QTextStream out(&file);
            //QDateTime dateTime = QDateTime::currentDateTime();
            QDateTime dateTime=nowtime;
            int y=dateTime.date().year();
            int m=dateTime.date().month();
            int d=dateTime.date().day();
            QString date=QString::number(y, 10)+"/"+QString::number(m, 10)+"/"+QString::number(d, 10);
            message=reader_ui->message->toPlainText();
            out<<uid<<":"<<" "<<date<<" "<<message<<"\n";
            file.close();
            QMessageBox::warning(this,tr("Success"),tr("The message success."),QMessageBox::Yes);
            reader_ui->message->clear();
        }
    }
}

void reader::on_reinput_clicked()
{
    reader_ui->message->clear();
}

void reader::on_pushButton_4_clicked() //修改留言
{
    if(reader_ui->message->toPlainText()==NULL)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Input error."),QMessageBox::Yes);
    }
    else
    {
        QFile file("dat\\message.dat");
        QFile file2("dat\\message_else.dat");
        QString message,uid;
        int a=0;

        QFile fi("dat\\x12.dat");
        if(!fi.open(QIODevice::ReadOnly )){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
        }
        else
        {
            QTextStream in(&fi);
            in>>uid;
            fi.close();
        }

        if(!file.open(QIODevice::ReadOnly)){
                QMessageBox::warning(this,tr("Warning"),tr("At present there is no message."),QMessageBox::Yes);
        }
        else if(!file2.open(QIODevice::WriteOnly)){
            QMessageBox::warning(this,tr("Warning"),tr("Can not open the file."),QMessageBox::Yes);
    }
        else
        {
            QTextStream in(&file);
            QTextStream out(&file2);
            while(!in.atEnd())
            {
                message=in.readLine();
                if(message.indexOf(uid)!=0)
                {
                    out<<message<<"\n";
                }
                else
                {
                    a=1;
                    message=reader_ui->message->toPlainText();
                    //QDateTime dateTime = QDateTime::currentDateTime();
                    QDateTime dateTime=nowtime;
                    int y=dateTime.date().year();
                    int m=dateTime.date().month();
                    int d=dateTime.date().day();
                    QString date=QString::number(y, 10)+"/"+QString::number(m, 10)+"/"+QString::number(d, 10);

                    out<<uid<<":"<<" "<<date<<" "<<message<<"\n";
                }
            }
            file.close();
            file2.close();
            if(a==1)
            {
                rename("dat\\message.dat","dat\\message2.dat");
                rename("dat\\message_else.dat","dat\\message.dat");
                remove("dat\\message2.dat");
                QMessageBox::warning(this,tr("Success"),tr("Successful modification."),QMessageBox::Yes);
                reader_ui->message->clear();
            }
            else
            {
                remove("dat\\message_else.dat");
                QMessageBox::warning(this,tr("Warning"),tr("You doesn't leave a message."),QMessageBox::Yes);
            }
        }
    }
}

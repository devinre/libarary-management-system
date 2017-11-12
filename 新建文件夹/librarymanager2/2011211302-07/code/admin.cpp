#include "admin.h"
#include "ui_admin.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QLabel.h>
#include <qfile.h>
#include <QString>
#include <qtextstream.h>
#include <qtimer.h>

QDateTime dateTime=QDateTime::currentDateTime();

admin::admin(QWidget *parent):
    QDialog(parent),
    admin_ui(new Ui::admin)
{
    admin_ui->setupUi(this);
    //admin_ui->id->setText(infor4.id);

    setWindowFlags(Qt::FramelessWindowHint);
    admin_ui->adexit->setFlat(true);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明


    QString strTime=dateTime.toString("yyyy-MM-dd");//当前时间QString显示
    admin_ui->time->setText(strTime);
    ye=dateTime.date().year();
    mo=dateTime.date().month();
    da=dateTime.date().day();


     /*QString uid;
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
     admin_ui->ad_id->setText(userid);*/



     installEventFilter(this);
     setMouseTracking(true);

     admin_ui->time->setText(dateTime.toString("yyyy-MM-dd"));
     QTimer *timer = new QTimer(this);   //新建定时器
     connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));//关联定时器计满信号和相应的槽函数
     timer->start(10000);//定时器开始计时，其中1000表示1000ms即1秒
     QTimer *timer2 = new QTimer(this);   //新建定时器
     connect(timer2,SIGNAL(timeout()),this,SLOT(timerStart()));//关联定时器计满信号和相应的槽函数
     timer2->start(13000);//定时器开始计时，其中1000表示1000ms即1秒
}

admin::~admin()
{
    delete admin_ui;
}

bool admin::eventFilter(QObject *obj, QEvent *event)
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
void admin::timerUpDate()
{
    if(operateFlag==FREE)
    {
        dateTime=dateTime.addDays(1);
        ye=dateTime.date().year();
        mo=dateTime.date().month();
        da=dateTime.date().day();
        admin_ui->time->setText(dateTime.toString("yyyy-MM-dd"));
    }
}
void admin::timerStart()
{
    operateFlag=FREE;
}


void admin::on_adexit_clicked()
{
    reject();
}


void admin::on_adpchange_clicked()
{
    kw.show();
}

void admin::on_adbchange_clicked()
{
    bw.show();
}

void admin::on_lend_clicked()
{
    blw.show();
}

void admin::on_aduchange_clicked()
{
    adw.show();
}




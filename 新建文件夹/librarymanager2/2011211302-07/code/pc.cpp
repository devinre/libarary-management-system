#include "pc.h"
#include "ui_pc.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QLabel.h>
#include <qfile.h>
#include <QTextstream.h>

informationforuser infor5,infor6;

pc::pc(QWidget *parent):
    QDialog(parent),
    pc_ui(new Ui::pc)
{
    pc_ui->setupUi(this);
    pc_ui->pc_logkey->setEchoMode(QLineEdit::Password);
    pc_ui->pc_logkeysure->setEchoMode(QLineEdit::Password);

    setWindowFlags(Qt::FramelessWindowHint);
    pc_ui->pc_exitb->setFlat(true);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明


    installEventFilter(this);
    setMouseTracking(true);
    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(500);//定时器开始计时，其中1000表示1000ms即1秒
}

pc::~pc()
{
    delete pc_ui;
}

void pc::timerUpDate()
{
    QString date=QString::number(ye)+"-"+QString::number(mo)+"-"+QString::number(da);
    pc_ui->time->setText(date);
}

bool pc::eventFilter(QObject *obj, QEvent *event)
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

void pc::on_pc_exitb_clicked()
{
    pc_ui->pc_logkey->clear();
    pc_ui->pc_logkeysure->clear();
    pc_ui->pc_email->clear();
    pc_ui->pc_phone->clear();
    close();
}

void pc::on_pc_clearb_clicked()
{
    pc_ui->pc_logkey->clear();
    pc_ui->pc_logkeysure->clear();
    pc_ui->pc_email->clear();
    pc_ui->pc_phone->clear();
}

void pc::on_pc_regb_clicked()
{
    QString pc_keysure;
    infor5.id=infor4.id;
    infor5.key=pc_ui->pc_logkey->text();
    pc_keysure=pc_ui->pc_logkeysure->text();
    infor5.email=pc_ui->pc_email->toPlainText();
    infor5.phone=pc_ui->pc_phone->toPlainText();
    infor5.code=infor4.code;

    QFile file("dat\\data.dat");
    QFile file2("dat\\data_else.dat");
    if(infor5.key!=pc_keysure||infor5.key==NULL)
    {
        if(infor5.key==NULL)
        {
            QMessageBox::warning(this,tr("Warning"),tr("Please enter the password."),QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("The two time you enter passwords do not match, please try again."),QMessageBox::Yes);
        }
        pc_ui->pc_logkey->clear();
        pc_ui->pc_logkeysure->clear();

    }
    else if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else if(!file2.open(QIODevice::WriteOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        QTextStream out(&file2);
        while(!in.atEnd())
        {
            in>>infor6.id;
            in>>infor6.key;
            in>>infor6.email;
            in>>infor6.phone;
            in>>infor6.code;
            if(infor6.id!=infor4.id)
            {
                out<<infor6.id<<" ";
                out<<infor6.key<<" ";
                out<<infor6.email<<" ";
                out<<infor6.phone<<" ";
                out<<infor6.code<<" ";
            }
        }
        out<<infor5.id<<" ";
        out<<infor5.key<<" ";
        out<<infor5.email<<" ";
        out<<infor5.phone<<" ";
        out<<infor5.code<<" ";
        file.close();
        file2.close();
        rename("dat\\data.dat","dat\\data1.dat");
        rename("dat\\data_else.dat","dat\\data.dat");
        remove("dat\\data1.dat");
        QMessageBox::warning(this,tr("Success"),tr("Successful modification."),QMessageBox::Yes);
        reject();
    }
}

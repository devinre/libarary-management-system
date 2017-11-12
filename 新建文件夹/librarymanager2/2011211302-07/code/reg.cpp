#include "reg.h"
#include "ui_reg.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QFile.h>
#include <QTextstream.h>
#include <stdio.h>

//informationforuser infor={"","","","",0};
//informationforuser infor1,infor2;

informationforuser infor,infor2;

reg::reg(QWidget *parent):
    QDialog(parent),
    reg_ui(new Ui::reg)
{
    reg_ui->setupUi(this);
    reg_ui->logkey->setEchoMode(QLineEdit::Password);
    reg_ui->logkeysure->setEchoMode(QLineEdit::Password);


    reg_ui->exitb->setFlat(true);//无边框
    setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明
}


reg::~reg()
{
    delete reg_ui;
}



void reg::on_clearb_clicked()
{
    reg_ui->logid->clear();
    reg_ui->logkey->clear();
    reg_ui->logkeysure->clear();
    reg_ui->email->clear();
    reg_ui->phone->clear();
}


void reg::on_exitb_clicked()
{
    reg_ui->logid->clear();
    reg_ui->logkey->clear();
    reg_ui->logkeysure->clear();
    reg_ui->email->clear();
    reg_ui->phone->clear();
    close();
}

void reg::on_regb_clicked()
{

    int a=0;
    QString keysure;

    /*QByteArray ba = infor.id.toLatin1();
    const char *ckey = ba.data();
    QMessageBox::warning(this,tr("Warning"),tr(ckey,ckey),QMessageBox::Yes);*/

    QFile file("dat\\data.dat");

    infor.id=reg_ui->logid->toPlainText();
    infor.key=reg_ui->logkey->text();
    keysure=reg_ui->logkeysure->text();
    infor.email=reg_ui->email->toPlainText();
    infor.phone=reg_ui->phone->toPlainText();
    infor.code="0";

    /*QByteArray ba = infor.email.toLatin1();
        const char *ckey = ba.data();
        QMessageBox::warning(this,tr("Warning"),tr(ckey,ckey),QMessageBox::Yes);*/

    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>infor2.id;
            in>>infor2.key;
            in>>infor2.email;
            in>>infor2.phone;
            in>>infor2.code;
            if(infor2.id==infor.id)
            {
                QMessageBox::warning(this,tr("Warning"),tr("The user name already exists."),QMessageBox::Yes);
                reg_ui->logid->clear();
                a=1;
                file.close();
                break;
            }
        }

    }
    file.close();

    if(!file.open(QIODevice::Append )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else if(infor.key!=keysure||infor.key==NULL)
    {
        if(infor.key==NULL)
        {
            QMessageBox::warning(this,tr("Warning"),tr("Please enter the password."),QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("The two time you enter passwords do not match, please try again."),QMessageBox::Yes);
        }
        reg_ui->logkey->clear();
        reg_ui->logkeysure->clear();

    }
    else if(a==0)
    {
        QTextStream out(&file);
        if(infor.email==NULL)
        {
            infor.email='null';
        }
        if(infor.phone==NULL)
        {
            infor.phone='null';
        }
        out<<infor.id<<" ";
        out<<infor.key<<" ";
        out<<infor.email<<" ";
        out<<infor.phone<<" ";
        out<<infor.code<<" ";
        QMessageBox::warning(this,tr("Success"),tr("Successful registration."),QMessageBox::Yes);
        file.close();
        reject();
    }
}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox.h>
#include <QString.h>
#include <QFile.h>
#include "head.h"
#include <QTextstream.h>
#include "reg.h"

informationforuser infor3,infor4;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logkey->setEchoMode(QLineEdit::Password);
    //setStyleSheet("border:2px groove black;border-radius:10px;");
    setWindowFlags(Qt::FramelessWindowHint);
    ui->regbutton->setFlat(true);//无边框
    ui->exitButton->setFlat(true);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明


    QString rememberid;
    QFile file2("dat\\p1112.dat");
    if(!file2.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file2);
        in>>rememberid;
        ui->logid->setText(rememberid);
        file2.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_logbutton_clicked()
{
    QFile file("dat\\data.dat");
    QFile file2("dat\\p1112.dat");
    QTextStream in(&file);
    int b=0;
    infor3.id=ui->logid->text();
    infor3.key=ui->logkey->text();

    QFile fi("dat\\x12.dat");
    if(!fi.open(QIODevice::WriteOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream out(&fi);
        out<<infor3.id;
        fi.close();
    }

    if(infor3.id==NULL||infor3.key==NULL)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Please input your id or key."),QMessageBox::Yes);
        b=1;
    }
    else if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        while(!in.atEnd())
        {
            in>>infor4.id;
            in>>infor4.key;
            in>>infor4.email;
            in>>infor4.phone;
            in>>infor4.code;
            QByteArray ba = infor4.code.toLatin1();
            const char *c = ba.data();
            if(infor4.id==infor3.id&&infor4.key==infor3.key)
            {
                if(ui->remember->isChecked())
                {
                    if(!file2.open(QIODevice::WriteOnly )){
                            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
                    }
                    else
                    {
                        QTextStream out(&file2);
                        out<<infor3.id;
                        file2.close();
                    }
                }


                if(*c=='1')
                {
                    hide();
                    ad.show();
                    b=1;
                    break;
                }
                else
                {
                    hide();
                    re.show();
                    b=1;
                    break;
                }
            }
        }
    }

    if(b==0){
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        //如果不正确，弹出警告对话框
        ui->logid->clear();//清空用户名输入框

        ui->logkey->clear();//清空密码输入框

        ui->logid->setFocus();//将光标转到用户名输入框
    }

}

void MainWindow::on_regbutton_clicked()
{
    regw.show();
}

void MainWindow::on_exitButton_clicked()
{
   close();
}

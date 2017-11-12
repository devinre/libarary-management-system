#include "ad_user.h"
#include "ui_ad_user.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QLabel.h>
#include <qfile.h>
#include <qtextstream.h>


informationforuser infor8,infor9;
booklend blinfor4;
int t3=0,k3=0,p3=0,t6=0,k6=0,p6=0;


ad_user::ad_user(QWidget *parent):
    QDialog(parent),
    ad_user_ui(new Ui::ad_user)
{
    ad_user_ui->setupUi(this);

    ad_user_ui->exit->setFlat(true);//无边框
    setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);//透明

    //ad_user_ui->time->setText("123");

    ad_user_ui->table->setSelectionBehavior ( QAbstractItemView::SelectRows);//设置选择行为，以行为单位
    ad_user_ui->table->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ad_user_ui->table->setEditTriggers ( QAbstractItemView::NoEditTriggers );//禁止编辑

    ad_user_ui->message->setSelectionBehavior ( QAbstractItemView::SelectRows);//设置选择行为，以行为单位
    ad_user_ui->message->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ad_user_ui->message->setEditTriggers ( QAbstractItemView::NoEditTriggers );//禁止编辑


    QFile f("dat\\data.dat");
    if(!f.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened x."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&f);
        while(!in.atEnd())
        {
            in>>infor8.id;
            in>>infor8.key;
            in>>infor8.email;
            in>>infor8.phone;
            in>>infor8.code;
            t3++;
        }
        f.close();
    }
    p3=t3/10+1;
    QString page=QString::number(p3, 10);
    ad_user_ui->total->setText(page);

    k3=1;
    showuser(k3);



    QFile file("dat\\message.dat");
    QString message;

    if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,tr("Warning"),tr("At present there is no message."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            message=in.readLine();
            t6++;
        }
        file.close();
    }
    p6=t6/5+1;
    page=QString::number(p6, 10);
    ad_user_ui->totalm->setText(page);

    k6=1;
    showmessage(k6);


    installEventFilter(this);
    setMouseTracking(true);

    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(500);//定时器开始计时，其中1000表示1000ms即1秒
}

ad_user::~ad_user()
{
    delete ad_user_ui;
}

void ad_user::timerUpDate()
{
    QString date=QString::number(ye)+"-"+QString::number(mo)+"-"+QString::number(da);
    ad_user_ui->time->setText(date);
}


bool ad_user::eventFilter(QObject *obj, QEvent *event)
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



void ad_user::on_exit_clicked()
{
    reject();
}


int ad_user::judge(QString id)
{
    QFile file("dat\\le.dat");
    int s=0;
    if(!file.open(QIODevice::ReadOnly )){
            QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>blinfor4.book_id;
            in>>blinfor4.user_id;
            in>>blinfor4.lend_time1;
            in>>blinfor4.lend_time2;
            in>>blinfor4.lend_time3;
            in>>blinfor4.back_time1;
            in>>blinfor4.back_time2;
            in>>blinfor4.back_time3;
            if(blinfor4.user_id==id)
            {
                s=1;
                return 0;
                break;
            }
        }
        file.close();
        if(s==0)
        {
            return 1;
        }
    }
}


void ad_user::showuser(int begin)
{
    int i=0,j=0,l=-1;
    QFile file("dat\\data.dat");
    QString ad="administrator",us="user";
    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>infor8.id;
            in>>infor8.key;
            in>>infor8.email;
            in>>infor8.phone;
            in>>infor8.code;
            l++;
            if(l/10==(begin-1))
            {
                if(infor8.code=="1")
                {
                    ad_user_ui->table->setItem(i,j,new QTableWidgetItem(infor8.id));
                    ad_user_ui->table->setItem(i,j+1,new QTableWidgetItem(infor8.email));
                    ad_user_ui->table->setItem(i,j+2,new QTableWidgetItem(infor8.phone));
                    ad_user_ui->table->setItem(i,j+3,new QTableWidgetItem(ad));
                }
                if(infor8.code=="0")
                {
                    ad_user_ui->table->setItem(i,j,new QTableWidgetItem(infor8.id));
                    ad_user_ui->table->setItem(i,j+1,new QTableWidgetItem(infor8.email));
                    ad_user_ui->table->setItem(i,j+2,new QTableWidgetItem(infor8.phone));
                    ad_user_ui->table->setItem(i,j+3,new QTableWidgetItem(us));
                }
                i++;
                j=0;
            }
        }
        file.close();
    }
}


void ad_user::showmessage(int begin)
{
    QFile file("dat\\message.dat");
    QString message;
    int i=0,j=0,l=-1;
    if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,tr("Warning"),tr("At present there is no message."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        int i=0;
        while(!in.atEnd())
        {
            message=in.readLine();
            l++;
            if(l/5==(begin-1))
            {
                ad_user_ui->message->setItem(i,0,new QTableWidgetItem(message));
                i++;
            }
        }
        file.close();
    }
}


void ad_user::on_lastpage_clicked()
{
    if(k3==1)
    {
         QMessageBox::warning(this,tr("Warning"),tr("There is no one on the page."),QMessageBox::Yes);
    }
    else
    {
        k3--;
        QString page=QString::number(k3,10);
        ad_user_ui->now->setText(page);
        showuser(k3);
    }
}

void ad_user::on_nextpage_clicked()
{
    if(k3==p3)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Not the next page."),QMessageBox::Yes);
    }
    else
    {
        k3++;
        QString page=QString::number(k3,10);
        ad_user_ui->now->setText(page);
        showuser(k3);
    }
}

void ad_user::on_okButton_clicked()
{
    QString id;
    int a=0,b=0;
    id=ad_user_ui->id->text();
    QFile file("dat\\data.dat");
    if(!file.open(QIODevice::ReadOnly )){
        QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            in>>infor8.id;
            in>>infor8.key;
            in>>infor8.email;
            in>>infor8.phone;
            in>>infor8.code;
            if(infor8.id==id)
            {
                a=1;
                break;
            }
        }
        file.close();
        if(a==0)
        {
            QMessageBox::warning(this,tr("Warning"),tr("The user name does not exist."),QMessageBox::Yes);
        }
        else if(a==1&&id!=NULL)
        {
            if(ad_user_ui->checkBox->isChecked())
            {
                if(infor8.code=="1")
                {
                    QMessageBox::warning(this,tr("Warning"),tr("This user is already administrator."),QMessageBox::Yes);
                    b=2;
                    ad_user_ui->id->clear();
                }
                else
                {
                    infor8.code="1";
                    b=1;
                    if(judge(id)!=1)
                    {
                        b=2;
                        QMessageBox::warning(this,tr("Warning"),tr("The user has the book did not return, can not operate."),QMessageBox::Yes);
                        ad_user_ui->id->clear();
                    }
                }
            }
            if(ad_user_ui->checkBox_2->isChecked())
            {
                if(infor8.code=="0")
                {
                    QMessageBox::warning(this,tr("Warning"),tr("This user is already user."),QMessageBox::Yes);
                    b=2;
                    ad_user_ui->id->clear();
                }
                else
                {
                    infor8.code="0";
                    b=1;
                }
                if(infor8.id==infor4.id)
                {
                    QMessageBox::warning(this,tr("Warning"),tr("Unable to operate on your own."),QMessageBox::Yes);
                    b=2;
                    ad_user_ui->id->clear();
                }
            }
            if(ad_user_ui->checkBox_3->isChecked())
            {
                b=0;
                if(infor8.id==infor4.id)
                {
                    QMessageBox::warning(this,tr("Warning"),tr("Unable to operate on your own."),QMessageBox::Yes);
                    b=2;
                    ad_user_ui->id->clear();
                }
                if(judge(id)!=1)
                {
                    b=2;
                    QMessageBox::warning(this,tr("Warning"),tr("The user has the book did not return, can not operate."),QMessageBox::Yes);
                    ad_user_ui->id->clear();
                }
            }


            QFile file2("dat\\data_else.dat");
            if(!file.open(QIODevice::ReadOnly )){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
            }
            else if(!file2.open(QIODevice::WriteOnly )){
                QMessageBox::warning(this,tr("Warning"),tr("File can not be opened."),QMessageBox::Yes);
            }
            else if(b!=2)
            {
                QTextStream in(&file);
                QTextStream out(&file2);
                while(!in.atEnd())
                {
                    in>>infor9.id;
                    in>>infor9.key;
                    in>>infor9.email;
                    in>>infor9.phone;
                    in>>infor9.code;
                    if(infor9.id==id)
                    {
                        if(b==1)
                        {
                            out<<infor8.id<<" ";
                            out<<infor8.key<<" ";
                            out<<infor8.email<<" ";
                            out<<infor8.phone<<" ";
                            out<<infor8.code<<" ";
                        }
                    }
                    else
                    {
                        out<<infor9.id<<" ";
                        out<<infor9.key<<" ";
                        out<<infor9.email<<" ";
                        out<<infor9.phone<<" ";
                        out<<infor9.code<<" ";
                    }
                }
                file.close();
                file2.close();
                rename("dat\\data.dat","dat\\data1.dat");
                rename("dat\\data_else.dat","dat\\data.dat");
                remove("dat\\data1.dat");
                QMessageBox::warning(this,tr("Success"),tr("Successful modification."),QMessageBox::Yes);
            }
        }
    }
}

void ad_user::on_checkBox_clicked()
{
    if(ad_user_ui->checkBox_2->isChecked()||ad_user_ui->checkBox_3->isChecked())
    {
        ad_user_ui->checkBox->setChecked(false);
    }
}

void ad_user::on_checkBox_2_clicked()
{
    if(ad_user_ui->checkBox->isChecked()||ad_user_ui->checkBox_3->isChecked())
    {
        ad_user_ui->checkBox_2->setChecked(false);
    }
}

void ad_user::on_checkBox_3_clicked()
{
    if(ad_user_ui->checkBox->isChecked()||ad_user_ui->checkBox_2->isChecked())
    {
        ad_user_ui->checkBox_3->setChecked(false);
    }
}

void ad_user::on_update_clicked()
{
    k3=1;
    showuser(k3);
}


void ad_user::on_deleteall_clicked()
{
    remove("dat\\message.dat");
    QFile file("dat\\message.dat");
    file.open(QIODevice::WriteOnly);
    file.close();
    QMessageBox::warning(this,tr("Success"),tr("Successfully deleted."),QMessageBox::Yes);
    for(int i=0;i<=9;i++)
    {
        ad_user_ui->message->setItem(i,0,new QTableWidgetItem(NULL));
    }
}

void ad_user::on_deletemessage_clicked()
{
    QFile file("dat\\message.dat");
    QFile file2("dat\\message_else.dat");
    QString message,deleteid;
    int a=0;
    deleteid=ad_user_ui->deleteid->text();

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
            if(message.indexOf(deleteid)!=0)
            {
                out<<message<<"\n";
            }
            else
            {
                a=1;
            }
        }
        file.close();
        file2.close();
        rename("dat\\message.dat","dat\\message2.dat");
        rename("dat\\message_else.dat","dat\\message.dat");
        remove("dat\\message2.dat");
    }
    if(a==0)
    {
        QMessageBox::warning(this,tr("Warning"),tr("There is no this user's message."),QMessageBox::Yes);
    }
    else if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,tr("Warning"),tr("At present there is no message."),QMessageBox::Yes);
    }
    else
    {
        QTextStream in(&file);
        int i=0;
        while(!in.atEnd())
        {
            message=in.readLine();
            ad_user_ui->message->setItem(i,0,new QTableWidgetItem(message));
            i++;
        }
        file.close();
        for(;i<=9;i++)
        {
            ad_user_ui->message->setItem(i,0,new QTableWidgetItem(NULL));
        }
        ad_user_ui->deleteid->clear();
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
            t6++;
        }
        file.close();
    }
    p6=t6/5+1;
    QString page=QString::number(p6, 10);
    ad_user_ui->totalm->setText(page);
}

void ad_user::on_lsatpagem_clicked()
{
    if(k6==1)
    {
         QMessageBox::warning(this,tr("Warning"),tr("There is no one on the page."),QMessageBox::Yes);
    }
    else
    {
        k6--;
        QString page=QString::number(k6,10);
        ad_user_ui->nowm->setText(page);
        showuser(k6);
    }
}

void ad_user::on_nextpagem_clicked()
{
    if(k6==p6)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Not the next page."),QMessageBox::Yes);
    }
    else
    {
        k6++;
        QString page=QString::number(k6,10);
        ad_user_ui->now->setText(page);
        showuser(k6);
    }
}

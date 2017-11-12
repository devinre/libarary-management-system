#include "key.h"
#include "ui_key.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QLabel.h>

key::key(QWidget *parent):
    QDialog(parent),
    key_ui(new Ui::key)
{
    key_ui->setupUi(this);
    key_ui->kkey->setEchoMode(QLineEdit::Password);

    key_ui->kexit->setFlat(true);
    setWindowFlags(Qt::FramelessWindowHint);

    installEventFilter(this);
    setMouseTracking(true);
}


key::~key()
{
    delete key_ui;
}



bool key::eventFilter(QObject *obj, QEvent *event)
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

void key::on_kok_clicked()
{
    QString keykey;
    keykey=key_ui->kkey->text();
    if(keykey==infor4.key)
    {
        hide();
        pw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("The password input error."),QMessageBox::Yes);
        key_ui->kkey->clear();
    }
    key_ui->kkey->clear();
}

void key::on_kexit_clicked()
{
    key_ui->kkey->clear();
    reject();
}

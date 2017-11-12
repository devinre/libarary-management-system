#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "reg.h"
#include "connection.h"
#include <QtGui/QApplication>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QObject>
#include <QLineEdit>
#include <QTextCodec>
#include <QTextEdit>
#include <QtDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logPwdLE->setEchoMode(QLineEdit::Password);
}

helper he;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pblogin_clicked()
{

}

void MainWindow::on_regBtn_clicked()
{

    regw.show();
}

void MainWindow::on_loginBtn_clicked()
{
    QSqlDatabase db;
    if(!createConnection(db))
    {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                                      qApp->tr("Unable to establish a database connection."),
                                      QMessageBox::Cancel);
    }
    QSqlQuery query;
    query.prepare("select * from Tuser where uid=?");
    query.addBindValue(ui->logIdLE->text().trimmed());
    query.exec();
    if(query.next())
    {
        int pwd=query.value(1).toInt();
        int lev=query.value(2).toInt();
        if(pwd!=ui->logPwdLE->text().trimmed().toInt())
        {
            QMessageBox::warning(this,tr("failed"),tr("sorry! the wrong password"),QMessageBox::Close);
            ui->logPwdLE->clear();
        }
        else if(lev==2){
            ad.show();
            he.userid=ui->logIdLE->text().trimmed();
        }
        else{
            he.userid=ui->logIdLE->text().trimmed();
            re.show();
            re.init();
        }
    }
    else{
        ui->logIdLE->clear();
        ui->logPwdLE->clear();
        QMessageBox::warning(this,tr("failed"),tr("No this user"),QMessageBox::Close);
    }
    db.close();
}

void MainWindow::on_exitBtn_clicked()
{
    QApplication::exit();
}

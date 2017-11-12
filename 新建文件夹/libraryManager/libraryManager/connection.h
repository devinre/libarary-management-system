#ifndef CONNECTION
#define CONNECTION
//#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>
#include <QApplication>

static bool createConnection(QSqlDatabase &db)
{
    //QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
    {
      //db = QSqlDatabase::addDatabase("QMYSQL");
      db = QSqlDatabase::addDatabase("QSQLITE");
    }
    //db.setHostName("localhost");
    db.setDatabaseName("mydata.db");
    //db.setUserName("root");
    //db.setPassword("newpassword");
    if (!db.open())
    {
        //提示出错
        QMessageBox::critical(0,QObject::tr("Cannot open database"),QObject::tr("Unable to establish a database connection."),QMessageBox::Cancel);
        return false;
    }
    else
    {
        //qDebug()<<"open success";
        return true;
    }

    //如果数据库插入不了中文：
    /*字符编码不对 就会这样了 你在建数据库的时候 最好加上这样一句
    create database tea default character set utf8 collate utf8_general_ci;

    mysql>show databases;       显示所有表
    mysql>use mysql;            切换到表mysql
    mysql>show tables;          显示表的结构
    show columns from mydata.tuser;

    启动MYSQL服务：net start mysql
    停止MYSQL服务：net stop mysql
    移出mysql服务：mysqld -remove*/


}

class helper
{
public:
    static QString userid;
    //static int flag;
    //static QString tran;
};
#endif // CONNECTION


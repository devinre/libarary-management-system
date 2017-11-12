#ifndef BOOKSYSTEMSERVER_H
#define BOOKSYSTEMSERVER_H
#include <QtGui/QWidget>
#include "Uibooksystemserver.h"
#include <QMessageBox>
#include "server.h"
#include <QtSql>
#include "ServerTime.h"
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include <qlibrary.h>
class BookSystemServer: public QDialog, public UiBookSystemServerClass
{
Q_OBJECT
public:
	BookSystemServer(QWidget *parent = 0);
	~BookSystemServer();
private:
	void InitServer();
	void closeEvent(QCloseEvent *);//监听关闭事件
	bool MYSQLConnector(); //连接数据库
	QString GetDatabase() const;//从输入框中获取数据库
	QString GetUserName() const;//从输入框中获取数据库用户名
	QString GetPassword() const;//从输入框中获取数据库用户密码
	void SetWindowTrayIcon();
	int closeFlag;
	QString database; //数据库
	QString username; //用户名
	QString password; //密码
	QSqlDatabase db; //数据库
	QLibrary lib;
	int mysqlflag; //连接标志，已经连接置1，未连接置0
	int defaultport; //默认端口号
	Server *server; //服务器句柄
	int conn_num; //当前连接数
	ServerTime servertime; //
private slots:
	void Close();
	void SetSQLValue(); //设置数据库连接参数
	void UpdateServer(const QString &, const int &);//升级服务器
	void AddConnNum();//增加连接数
	void SubConnNum();//减少连接数
	void ShowTime(const QString &);
private:
	void CreatServer();//创建连接
};

#endif // BOOKSYSTEMSERVER_H

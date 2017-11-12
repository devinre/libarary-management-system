#ifndef BOOKSYSTEM_H
#define BOOKSYSTEM_H

#include <QtGui/QMainWindow>
#include "Uibooksystem.h"
#include <QtNetwork>
#include <QMdiSubWindow>
#include "bookmanage.h"
#include "SendMessage.h"
#include "BookLogManage.h"
#include "UserLogManage.h"
#include "UserManage.h"
#include "LendManage.h"
#include "logon.h"
#include "updatepwd.h"
class Logon;
class UpdatePwd;
class BookSystem: public QMainWindow, public UiBookSystemClass
{
Q_OBJECT

public:
	BookSystem(QWidget *parent = 0);
	void SetBookSys(BookSystem*, QString, QHostAddress*);//设置参数
	~BookSystem();
private:
	void InitSystem();
	void ConnectServer(); //连接服务器
	void closeEvent(QCloseEvent *); //监听关闭事件
	void SetSubWindow(QWidget *);
	void DealResult(MANAGEINFO &);
	bool IsLogon();
	void SetEnabled(bool);
	BookManage *bookManage;
	BookLogManage *bookLogManage;
	UserLogManage *userLogManage;
	UserManage *userManage;
	LendManage *lendManage;
	BookSystem *booksys;//
	Logon *logonDlg;//登陆窗口
	UpdatePwd *updatePwdDlg;//升级密码窗口
	QHostAddress *serverIP; //服务器IP地址
	QTcpSocket *tcpsocket; //套接字
	QString ip; //服务器IP地址
	SendMsg *sendMsg; //发送消息
	MANAGEINFO manageInfo;
	QMdiSubWindow *sub;//创建内部窗体
private slots:
	void UserLogOut();//注销用户
	void ShowLogon(); //登陆框
	void About(); //关于
	//void LogOut();//注销
	void ShowUpdatePwd(); //修改密码
	void DataReceived(); //接收数据
	void ShowBookManage();
	void ShowBookLogManage();
	void ShowUserLogManage();
	void ShowUserManage();
	void ShowLendManage();
	void GetSendData(const MANAGEINFO &);//发送数据到网络
	void ShowGPS();
signals:
	void ConnInformation(const QString &);//发送连接成功信息
};

#endif // BOOKSYSTEM_H

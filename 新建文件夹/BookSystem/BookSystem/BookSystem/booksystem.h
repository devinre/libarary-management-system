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
	void SetBookSys(BookSystem*, QString, QHostAddress*);//���ò���
	~BookSystem();
private:
	void InitSystem();
	void ConnectServer(); //���ӷ�����
	void closeEvent(QCloseEvent *); //�����ر��¼�
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
	Logon *logonDlg;//��½����
	UpdatePwd *updatePwdDlg;//�������봰��
	QHostAddress *serverIP; //������IP��ַ
	QTcpSocket *tcpsocket; //�׽���
	QString ip; //������IP��ַ
	SendMsg *sendMsg; //������Ϣ
	MANAGEINFO manageInfo;
	QMdiSubWindow *sub;//�����ڲ�����
private slots:
	void UserLogOut();//ע���û�
	void ShowLogon(); //��½��
	void About(); //����
	//void LogOut();//ע��
	void ShowUpdatePwd(); //�޸�����
	void DataReceived(); //��������
	void ShowBookManage();
	void ShowBookLogManage();
	void ShowUserLogManage();
	void ShowUserManage();
	void ShowLendManage();
	void GetSendData(const MANAGEINFO &);//�������ݵ�����
	void ShowGPS();
signals:
	void ConnInformation(const QString &);//�������ӳɹ���Ϣ
};

#endif // BOOKSYSTEM_H

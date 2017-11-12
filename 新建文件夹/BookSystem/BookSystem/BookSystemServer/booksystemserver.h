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
	void closeEvent(QCloseEvent *);//�����ر��¼�
	bool MYSQLConnector(); //�������ݿ�
	QString GetDatabase() const;//��������л�ȡ���ݿ�
	QString GetUserName() const;//��������л�ȡ���ݿ��û���
	QString GetPassword() const;//��������л�ȡ���ݿ��û�����
	void SetWindowTrayIcon();
	int closeFlag;
	QString database; //���ݿ�
	QString username; //�û���
	QString password; //����
	QSqlDatabase db; //���ݿ�
	QLibrary lib;
	int mysqlflag; //���ӱ�־���Ѿ�������1��δ������0
	int defaultport; //Ĭ�϶˿ں�
	Server *server; //���������
	int conn_num; //��ǰ������
	ServerTime servertime; //
private slots:
	void Close();
	void SetSQLValue(); //�������ݿ����Ӳ���
	void UpdateServer(const QString &, const int &);//����������
	void AddConnNum();//����������
	void SubConnNum();//����������
	void ShowTime(const QString &);
private:
	void CreatServer();//��������
};

#endif // BOOKSYSTEMSERVER_H

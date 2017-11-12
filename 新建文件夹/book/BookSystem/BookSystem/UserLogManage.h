#ifndef USERLOGMANAGE_H
#define USERLOGMANAGE_H

#include <QtGui/QMainWindow>
#include "UiUserLogManage.h"
#include "GlobalDefine.h"
#include "TableView.h"
class UserLogManage: public QMainWindow, public UiUserLogManageClass, public TableView
{
Q_OBJECT

public:
	UserLogManage(QWidget *parent = 0);
	~UserLogManage();
	void SetHorizontalHeader();
	void InsertResponseUserLogInfo(MANAGEINFO &);
	void RecvResultInfo(const USERLOGINFO &);
private:
private slots:
	void RefreshUserLog();
	void DeleteAllUserLog();
signals:
	void SendUserLogInfo(const MANAGEINFO &);
};

#endif // USERLOGMANAGE_H

#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QtGui/QMainWindow>
#include "Uiusermanage.h"
#include "TableView.h"
#include "UserDialog.h"
class UserManage : public QMainWindow, public UiUserManageClass, public TableView
{
    Q_OBJECT

public:
    UserManage(QWidget *parent = 0);
    ~UserManage();
    void SetHorizontalHeader();
    void RecvResultInfo(const USERLOGINFO &);
    void InsertResponseUserInfo(MANAGEINFO &);

private:
	MANAGEINFO manageInfo;
	UserDialog *userDlg;
	int row;
private slots:
	void SetUserTableInfo(const USERINFO &);
	void DelUserInfo();
	void UpdateUserInfo(const QModelIndex &);
	void AddUserInfo();
	/*void QueryUserInfo();*/
	void UpdateUserInfo();
	void UserList();
	void SearchUser();
signals:
	void SendUserInfo(const MANAGEINFO &);
};

#endif // USERMANAGE_H

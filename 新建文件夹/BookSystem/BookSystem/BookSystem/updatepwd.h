#ifndef UPDATEPWD_H
#define UPDATEPWD_H

#include <QtGui/QWidget>
#include "Uiupdatepwd.h"
#include "GlobalDefine.h"
class UpdatePwd: public QDialog, UiUpdatePwdClass
{
Q_OBJECT

public:
	UpdatePwd(QWidget *parent = 0);
	~UpdatePwd();
	void GetCurrentUserInfo(USERINFO);
	void RecvResultInfo(USERLOGINFO &);
private:
	USERINFO userInfo;
	void ClearInfo();
	void closeEvent(QCloseEvent *);
private slots:
	void UpdatePassword();
signals:
	void SendUpdatePassInfo(const MANAGEINFO &);
};

#endif // UPDATEPWD_H

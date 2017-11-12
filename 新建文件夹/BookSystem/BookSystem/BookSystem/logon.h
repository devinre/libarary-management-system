#ifndef LOGON_H
#define LOGON_H

#include <QtGui/QDialog>
#include "Uilogon.h"
#include <QDateTime>
#include "GlobalDefine.h"
class BookSystem;
class Logon: public QDialog, public UiLogonClass
{
Q_OBJECT

public:
	Logon(QWidget *parent = 0);
	~Logon();
	void RecvResultInfo(const USERLOGINFO &);
	USERINFO GetLogonUserInfo();
	void ClearInfo();
private slots:
	void ConfirmLogon();
signals:
	void SendLogOnInfo(const MANAGEINFO &);
private:
	USERINFO gUserInfo;
};

#endif // Logon_H

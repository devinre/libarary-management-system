#include "logon.h"
Logon::Logon(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
	ClearInfo();
	setModal(true);
	QObject::connect(logonBtn, SIGNAL(clicked()), this, SLOT(ConfirmLogon()));
	QObject::connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

Logon::~Logon()
{

}
void Logon::ConfirmLogon()
{
	QDateTime dateTime;
	MANAGEINFO tmpInfo;
	USERINFO userInfo;
	if (idEdit->text() != NULL && passEdit->text() != NULL)
	{
		userInfo.dwOnline = 1;
		userInfo.sPass = passEdit->text();
		userInfo.dwPower = comboBox->currentIndex();
		userInfo.sID = idEdit->text();
		userInfo.sLastTime = dateTime.currentDateTime().toString(DATETIME);
		tmpInfo.dwType = USER;
		tmpInfo.dwSubType = USER_LOGON;
		tmpInfo.userInfo = userInfo;
		gUserInfo = userInfo;
		emit
		SendLogOnInfo(tmpInfo);
	}
	else
		QMessageBox::warning(this, tr("Warning"), tr(
				"User name and password can not be null!"));
}
void Logon::RecvResultInfo(const USERLOGINFO &resultInfo)
{
	if (resultInfo.dwResult)
	{
		ClearInfo();
		QMessageBox::information(this, tr("Logon"), resultInfo.sDescription);
	}
	else
	{
		QMessageBox::information(this, tr("Logon"), resultInfo.sDescription);
		this->close();
	}
}
USERINFO Logon::GetLogonUserInfo()
{
	return gUserInfo;
}
void Logon::ClearInfo()
{
	gUserInfo.sID = "";
	gUserInfo.sPass = "";
	gUserInfo.sLastTime = "";
	passEdit->setText("");
}

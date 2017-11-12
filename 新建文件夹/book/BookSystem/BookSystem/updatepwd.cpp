#include "updatepwd.h"
UpdatePwd::UpdatePwd(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
	setModal(true);
	ClearInfo();
	userInfo.sPass = "";
	QObject::connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(okBtn, SIGNAL(clicked()), this, SLOT(UpdatePassword()));
}

UpdatePwd::~UpdatePwd()
{

}
void UpdatePwd::closeEvent(QCloseEvent *event)
{
	ClearInfo();
}
void UpdatePwd::UpdatePassword()
{
	USERINFO tmpInfo;
	MANAGEINFO manageInfo;
	if (oldPwdEdit->text() == userInfo.sPass)
	{
		if (newPwdEdit->text() == "")
		{
			QMessageBox::warning(this, tr("Warning"), tr(
					"Input your new password!"));
			return;
		}
		if (newPwdEdit->text() == confirmEdit->text())
		{
			tmpInfo = userInfo;
			tmpInfo.sPass = newPwdEdit->text();
			manageInfo.dwType = USER;
			manageInfo.dwSubType = USER_UPDATEPWD;
			manageInfo.userInfo = tmpInfo;
			emit
			SendUpdatePassInfo(manageInfo);
		}
		else
		{
			QMessageBox::warning(this, tr("Warning"), tr(
					"Password must be the same at two times input!"));
			return;
		}
	}
	else
	{
		QMessageBox::warning(this, tr("UpdatePass"), tr("Password is wrong!"));
		oldPwdEdit->setText("");
		return;
	}
}
inline void UpdatePwd::ClearInfo()
{
	oldPwdEdit->setText("");
	newPwdEdit->setText("");
	confirmEdit->setText("");
}
void UpdatePwd::GetCurrentUserInfo(USERINFO userInfo)
{
	if (this->userInfo.sPass == "")
	{
		this->userInfo = userInfo;
	}
}
void UpdatePwd::RecvResultInfo(USERLOGINFO &resultInfo)
{
	if (resultInfo.dwResult)
	{
		ClearInfo();
		QMessageBox::information(this, tr("Logon"), resultInfo.sDescription);
	}
	else
	{
		QMessageBox::information(this, tr("Logon"), resultInfo.sDescription);
		userInfo.sPass = newPwdEdit->text();
		ClearInfo();
		this->close();
	}
}

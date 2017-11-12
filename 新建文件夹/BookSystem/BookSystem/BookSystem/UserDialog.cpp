#include "UserDialog.h"

UserDialog::UserDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
	QObject::connect(confirmBtn, SIGNAL(clicked()), this, SLOT(SetUserInfo()));
	QObject::connect(clearBtn, SIGNAL(clicked()), this, SLOT(ClearTextInfo()));
	QObject::connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

UserDialog::~UserDialog()
{

}
void UserDialog::closeEvent(QCloseEvent *event)
{
	ClearTextInfo();
}
void UserDialog::SetUserInfo()
{
	USERINFO userInfo;
	QDateTime addDateTime;
	if (idEdit->text() == "" || passEdit->text() == "" || nameEdit->text() == "")
	{
		QMessageBox::warning(this, tr("Warning"), tr("Input information incompletely!"));
		return;
	}
	userInfo.sID = idEdit->text();
	userInfo.sPass = passEdit->text();
	userInfo.sName = nameEdit->text();
	userInfo.sBirthDay = brthBox->text();
	userInfo.sIDCard = idCardEdit->text();
	userInfo.sPhone = phoneEdit->text();
	userInfo.dwSex = sexBox->currentIndex();
	userInfo.dwStatus = statusBox->currentIndex();
	userInfo.sLoginTime = addDateTime.currentDateTime().toString(DATETIME);
	userInfo.sEmail = emailEdit->text();
	userInfo.dwPower = powerBox->currentIndex();
	userInfo.dwOnline = 0;
	emit
	GetUserInfo(userInfo);
}
void UserDialog::ClearTextInfo()
{
	idEdit->setText("");
	passEdit->setText("");
	nameEdit->setText("");
	idCardEdit->setText("");
	phoneEdit->setText("");
	emailEdit->setText("");
}

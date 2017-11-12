#include "UserManage.h"

UserManage::UserManage(QWidget *parent) :
	QMainWindow(parent), row(0)
{
	setupUi(this);
	SetUpModel(this);
	SetTableView(userTable);
	userDlg = new UserDialog(this);
	QObject::connect(addUser, SIGNAL(triggered()), this, SLOT(AddUserInfo()));
	QObject::connect(userDlg, SIGNAL(GetUserInfo(const USERINFO &)), this,
			SLOT(SetUserTableInfo(const USERINFO &)));
	QObject::connect(delUser, SIGNAL(triggered()), this, SLOT(DelUserInfo()));
	QObject::connect(userTable, SIGNAL(doubleClicked(const QModelIndex &)),
			this, SLOT(UpdateUserInfo(const QModelIndex &)));
	QObject::connect(updateUser, SIGNAL(triggered()), this,
			SLOT(UpdateUserInfo()));
	/*QObject::connect(queryUser, SIGNAL(triggered()), this,
			SLOT(QueryUserInfo()));*/
	QObject::connect(refresh, SIGNAL(triggered()), this, SLOT(UserList()));
	QObject::connect(userSearchBtn, SIGNAL(clicked()), this, SLOT(SearchUser()));
}

UserManage::~UserManage()
{

}
void UserManage::UpdateUserInfo()
{
	QModelIndex index;
	manageInfo.dwType = USER;
	manageInfo.dwSubType = USER_UPDATE;
	index = userTable->currentIndex();
	UpdateUserInfo(index);
}
void UserManage::SetHorizontalHeader()
{
	model->setRowCount(0);
	model->setColumnCount(13);
	model->setHeaderData(0, Qt::Horizontal, tr("Sex"));
	model->setHeaderData(1, Qt::Horizontal, tr("ID"));
	model->setHeaderData(2, Qt::Horizontal, tr("Name"));
	model->setHeaderData(3, Qt::Horizontal, tr("Password"));
	model->setHeaderData(4, Qt::Horizontal, tr("Power"));
	model->setHeaderData(5, Qt::Horizontal, tr("Birthday"));
	model->setHeaderData(6, Qt::Horizontal, tr("IDCard"));
	model->setHeaderData(7, Qt::Horizontal, tr("Phone"));
	model->setHeaderData(8, Qt::Horizontal, tr("Status"));
	model->setHeaderData(9, Qt::Horizontal, tr("LoginTime"));
	model->setHeaderData(10, Qt::Horizontal, tr("E-mail"));
	model->setHeaderData(11, Qt::Horizontal, tr("IsOnline"));
	model->setHeaderData(12, Qt::Horizontal, tr("LastTime"));
}
void UserManage::AddUserInfo()
{
	userDlg->idEdit->setEnabled(true);
	userDlg->setWindowTitle(tr("AddUser"));
	userDlg->show();
	manageInfo.dwType = USER;
	manageInfo.dwSubType = USER_ADD;
}
void UserManage::RecvResultInfo(const USERLOGINFO &resultInfo)
{
	userTable->clearSelection();
	if (!resultInfo.dwResult)
	{
		switch (resultInfo.dwOperation)
		{
		case USER_ADD:
			if (QMessageBox::question(this, tr("Result"),
					resultInfo.sDescription + tr("Continue?"),
					QMessageBox::Cancel, QMessageBox::Ok)
					== QMessageBox::Cancel)
			{
				userDlg->close();
			}
			else
			{
				AddUserInfo();
			}
			break;
		case USER_DELETE:
			QMessageBox::information(this, tr("Result"),
					resultInfo.sDescription);
			break;
		case USER_QUERY:
			break;
		case USER_UPDATE:
			QMessageBox::information(this, tr("Result"),
					resultInfo.sDescription);
			userDlg->close();
			break;
		case USER_RESPONSE:
			break;
		case USER_LIST:
			break;
		}
	}
	else
	{
		QMessageBox::information(this, tr("Result"), resultInfo.sDescription);
	}
}
void UserManage::SetUserTableInfo(const USERINFO &userInfo)
{
	MANAGEINFO tmpInfo = manageInfo;
	tmpInfo.userInfo = userInfo;
	switch (tmpInfo.dwSubType)
	{
	case USER_ADD:
		row = model->rowCount();
		model->insertRow(row);
		SetTableData(tmpInfo, row);
		break;
	case USER_DELETE:
		break;
	case USER_QUERY:
		model->clear();
		SetHorizontalHeader();
		break;
	case USER_UPDATE:
		SetTableData(tmpInfo, row);
		break;
	case USER_RESPONSE:
		break;
	case USER_LIST:
		break;
	}
	emit
	SendUserInfo(tmpInfo);
}
void UserManage::InsertResponseUserInfo(MANAGEINFO &tmpInfo)
{
	if (!tmpInfo.dwSubType)
	{
		return;
	}
	row = model->rowCount();
	model->insertRow(row);
	SetTableData(tmpInfo, row);
	tmpInfo.dwType = USER;
	tmpInfo.dwSubType = USER_RESPONSE;
	emit
	SendUserInfo(tmpInfo);
}

void UserManage::DelUserInfo()
{
	MANAGEINFO tmpInfo;
	QModelIndex index;
	index = userTable->currentIndex();
	if (!index.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a user!"));

		return;
	}
	tmpInfo.dwType = USER;
	tmpInfo.dwSubType = USER_DELETE;
	GetRowData(index, &tmpInfo);
	if (QMessageBox::question(this, tr("Delete User"), tr("Delete <<")
			+ tmpInfo.userInfo.sName + ">>?", QMessageBox::Cancel,
			QMessageBox::Ok) == QMessageBox::Cancel)
	{
		return;
	}emit
	SendUserInfo(tmpInfo);
	model->removeRow(index.row());
}
void UserManage::UpdateUserInfo(const QModelIndex &index)
{
	userDlg->idEdit->setEnabled(false);
	if (!index.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a user!"));

		return;
	}
	userDlg->setWindowTitle(tr("UpdateUser"));
	manageInfo.dwType = USER;
	manageInfo.dwSubType = USER_UPDATE;
	row = index.row();
	GetRowData(index, &manageInfo);
	userDlg->idEdit->setText(manageInfo.userInfo.sID);
	userDlg->passEdit->setText(manageInfo.userInfo.sPass);
	userDlg->nameEdit->setText(manageInfo.userInfo.sName);
	userDlg->brthBox->setDate(QDate::fromString(manageInfo.userInfo.sBirthDay,
			DATE));
	userDlg->idCardEdit->setText(manageInfo.userInfo.sIDCard);
	userDlg->phoneEdit->setText(manageInfo.userInfo.sPhone);
	userDlg->sexBox->setCurrentIndex(manageInfo.userInfo.dwSex);
	userDlg->statusBox->setCurrentIndex(manageInfo.userInfo.dwStatus);
	userDlg->emailEdit->setText(manageInfo.userInfo.sEmail);
	userDlg->statusBox->setCurrentIndex(manageInfo.userInfo.dwStatus);
	userDlg->powerBox->setCurrentIndex(manageInfo.userInfo.dwPower);
	userDlg->show();
}
/*void UserManage::QueryUserInfo()
{
	userDlg->idEdit->setEnabled(true);
	userDlg->setWindowTitle(tr("QueryUser"));
	manageInfo.dwType = USER;
	manageInfo.dwSubType = USER_QUERY;
	userDlg->show();
}*/
void UserManage::UserList()
{
	model->clear();
	SetHorizontalHeader();
	manageInfo.dwType = USER;
	manageInfo.dwSubType = USER_LIST;
	emit
	SendUserInfo(manageInfo);
}
void UserManage::SearchUser()
{
	model->clear();
	SetHorizontalHeader();
	manageInfo.dwType = USER;
	manageInfo.dwSubType = USER_QUERY;
	manageInfo.userInfo.sID = userIDEdit->text();
	manageInfo.userInfo.sName = userNameEdit->text();
	emit
	SendUserInfo(manageInfo);
}

#include "UserLogManage.h"

UserLogManage::UserLogManage(QWidget *parent) :
	QMainWindow(parent)
{
	setupUi(this);
	SetUpModel(this);
	SetTableView(userLogTable);
	QObject::connect(refUserLog, SIGNAL(triggered()), this,
			SLOT(RefreshUserLog()));
	QObject::connect(delUserLog, SIGNAL(triggered()), this,
			SLOT(DeleteAllUserLog()));
}

UserLogManage::~UserLogManage()
{

}
void UserLogManage::SetHorizontalHeader()
{
	model->setRowCount(0);
	model->setColumnCount(6);
	model->setHeaderData(0, Qt::Horizontal, tr("Result"));
	model->setHeaderData(1, Qt::Horizontal, tr("Operator"));
	model->setHeaderData(2, Qt::Horizontal, tr("Operation"));
	model->setHeaderData(3, Qt::Horizontal, tr("IP"));
	model->setHeaderData(4, Qt::Horizontal, tr("Description"));
	model->setHeaderData(5, Qt::Horizontal, tr("DateTime"));
}
void UserLogManage::RefreshUserLog()
{
	model->clear();
	SetHorizontalHeader();
	MANAGEINFO tmpInfo;
	tmpInfo.dwType = USERLOG;
	tmpInfo.dwSubType = USERLOG_LIST;
	emit
	SendUserLogInfo(tmpInfo);
}
void UserLogManage::DeleteAllUserLog()
{
	if (QMessageBox::warning(this, tr("Warning"),
			tr("Ensure delete user log?"), QMessageBox::Cancel, QMessageBox::Ok)
			== QMessageBox::Cancel)
	{
		return;
	}
	model->clear();
	SetHorizontalHeader();
	MANAGEINFO tmpInfo;
	tmpInfo.dwType = USERLOG;
	tmpInfo.dwSubType = USERLOG_DELETE;
	emit
	SendUserLogInfo(tmpInfo);
}
void UserLogManage::RecvResultInfo(const USERLOGINFO &resultInfo)
{
	if (!resultInfo.dwResult)
	{
		QMessageBox::information(this, tr("Result"), tr(
				"Delete book log successfully!"));
	}
	else
	{
		QMessageBox::information(this, tr("Result"), tr(
				"Delete book log failed!\n") + resultInfo.sDescription);
	}
}
void UserLogManage::InsertResponseUserLogInfo(MANAGEINFO &tmpInfo)
{
	if (!tmpInfo.dwSubType)
	{
		return;
	}
	int row = model->rowCount();
	model->insertRow(row);
	SetTableData(tmpInfo, row);
	tmpInfo.dwType = USERLOG;
	tmpInfo.dwSubType = USERLOG_RESPONSE;
	emit
	SendUserLogInfo(tmpInfo);
}

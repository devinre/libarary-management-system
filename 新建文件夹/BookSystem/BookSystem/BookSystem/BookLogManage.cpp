#include "BookLogManage.h"

BookLogManage::BookLogManage(QWidget *parent) :
	QMainWindow(parent)
{
	setupUi(this);
	SetUpModel(this);
	SetTableView(bkLogTable);
	QObject::connect(refBookLog, SIGNAL(triggered()), this,
			SLOT(RefreshBookLog()));
	QObject::connect(delBookLog, SIGNAL(triggered()), this,
			SLOT(DeleteAllBookLog()));
}

BookLogManage::~BookLogManage()
{

}
void BookLogManage::SetHorizontalHeader()
{
	model->setRowCount(0);
	model->setColumnCount(9);
	model->setHeaderData(0, Qt::Horizontal, tr("Result"));
	model->setHeaderData(1, Qt::Horizontal, tr("Operator"));
	model->setHeaderData(2, Qt::Horizontal, tr("BookID"));
	model->setHeaderData(3, Qt::Horizontal, tr("BookName"));
	model->setHeaderData(4, Qt::Horizontal, tr("Operation"));
	model->setHeaderData(5, Qt::Horizontal, tr("IP"));
	model->setHeaderData(6, Qt::Horizontal, tr("Type"));
	model->setHeaderData(7, Qt::Horizontal, tr("Description"));
	model->setHeaderData(8, Qt::Horizontal, tr("DateTime"));
}
void BookLogManage::InsertResponseBookLogInfo(MANAGEINFO &tmpInfo)
{
	if (!tmpInfo.dwSubType)
	{
		return;
	}
	int row = model->rowCount();
	model->insertRow(row);
	SetTableData(tmpInfo, row);
	tmpInfo.dwType = BOOKLOG;
	tmpInfo.dwSubType = BOOKLOG_RESPONSE;
	emit
	SendBookLogInfo(tmpInfo);
}
void BookLogManage::RefreshBookLog()
{
	model->clear();
	SetHorizontalHeader();
	MANAGEINFO tmpInfo;
	tmpInfo.dwType = BOOKLOG;
	tmpInfo.dwSubType = BOOKLOG_LIST;
	emit
	SendBookLogInfo(tmpInfo);
}
void BookLogManage::DeleteAllBookLog()
{
	if (QMessageBox::warning(this, tr("Warning"),
			tr("Ensure delete book log?"), QMessageBox::Cancel, QMessageBox::Ok)
			== QMessageBox::Cancel)
	{
		return;
	}
	model->clear();
	SetHorizontalHeader();
	MANAGEINFO tmpInfo;
	tmpInfo.dwType = BOOKLOG;
	tmpInfo.dwSubType = BOOKLOG_DELETE;
	emit
	SendBookLogInfo(tmpInfo);
}
void BookLogManage::RecvResultInfo(const BOOKLOGINFO &resultInfo)
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

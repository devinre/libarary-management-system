#include "LendManage.h"

LendManage::LendManage(QWidget *parent) :
	QMainWindow(parent)
{
	setupUi(this);
	SetUpModel(this);
	SetTableView(lendTable);
	reader = new ReaderInfo(this);
	QObject::connect(delLend, SIGNAL(triggered()), this, SLOT(DelLendInfo()));
	QObject::connect(lendList, SIGNAL(triggered()), this, SLOT(LendList()));
	QObject::connect(refresh, SIGNAL(triggered()), this, SLOT(LendList()));
	QObject::connect(srchBtn, SIGNAL(clicked()), this, SLOT(SearchLend()));
	QObject::connect(reader, SIGNAL(SetReaderInfo(LENDINFO &)), this,
			SLOT(LendRenewal(LENDINFO &)));
	QObject::connect(returnAc, SIGNAL(triggered()), this, SLOT(LendReturn()));
	QObject::connect(renewal, SIGNAL(triggered()), this, SLOT(GetRenewalInfo()));

}

LendManage::~LendManage()
{

}
void LendManage::SetHorizontalHeader()
{
	model->setRowCount(0);
	model->setColumnCount(13);
	model->setHeaderData(0, Qt::Horizontal, tr("OverDue/Days"));
	model->setHeaderData(1, Qt::Horizontal, tr("ReaderID"));
	model->setHeaderData(2, Qt::Horizontal, tr("ReaderName"));
	model->setHeaderData(3, Qt::Horizontal, tr("BookID"));
	model->setHeaderData(4, Qt::Horizontal, tr("BookName"));
	model->setHeaderData(5, Qt::Horizontal, tr("Author"));
	model->setHeaderData(6, Qt::Horizontal, tr("Type"));
	model->setHeaderData(7, Qt::Horizontal, tr("Press"));
	model->setHeaderData(8, Qt::Horizontal, tr("PublishDate"));
	model->setHeaderData(9, Qt::Horizontal, tr("PageNum"));
	model->setHeaderData(10, Qt::Horizontal, tr("Price"));
	model->setHeaderData(11, Qt::Horizontal, tr("LendDays"));
	model->setHeaderData(12, Qt::Horizontal, tr("LendDate"));
}
void LendManage::RecvResultInfo(const BOOKLOGINFO &resultInfo)
{
	lendTable->clearSelection();
	if (!resultInfo.dwResult)
	{
		switch (resultInfo.dwOperation)
		{
		case LEND_DELETE:
			break;
		case LEND_LIST:
			break;
		case LEND_OVERDUE:
			break;
		case LEND_QUERY:
			break;
		case LEND_RENEWAL:
			break;
		case LEND_RETURN:
			break;
		case LEND_STATISTIC:
			break;
		}
	}
	QMessageBox::information(this, tr("Result"), resultInfo.sDescription);
}
void LendManage::InsertResponseBookInfo(MANAGEINFO &tmpInfo)
{
	int row = 0;
	if (!tmpInfo.dwSubType)
	{
		return;
	}
	row = model->rowCount();
	model->insertRow(row);
	SetTableData(tmpInfo, row);
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_RESPONSE;
	emit
	SendLendInfo(tmpInfo);
}
void LendManage::DelLendInfo()
{
	MANAGEINFO tmpInfo;
	QModelIndex index;
	index = lendTable->currentIndex();
	if (!index.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a book!"));

		return;
	}
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_DELETE;
	GetRowData(index, &tmpInfo);
	if (QMessageBox::question(this, tr("Delete Book"), tr("Delete <<")
			+ tmpInfo.lendInfo.sName + tr(">>?"), QMessageBox::Cancel,
			QMessageBox::Ok) == QMessageBox::Cancel)
	{
		return;
	}emit
	SendLendInfo(tmpInfo);
	model->removeRow(index.row());
}
void LendManage::SearchLend()
{
	MANAGEINFO tmpInfo;
	model->clear();
	SetHorizontalHeader();
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_QUERY;
	tmpInfo.lendInfo.sReader = readerEdit->text();
	tmpInfo.lendInfo.sName = bkNameEdit->text();
	if (overBox->isChecked())
	{
		tmpInfo.lendInfo.dwTimeOut = LEND_ISOVERDUE;
	}
	else
	{
		tmpInfo.lendInfo.dwTimeOut = LEND_NOTOVERDUE;
	}
	emit
	SendLendInfo(tmpInfo);
}
void LendManage::LendList()
{
	MANAGEINFO tmpInfo;
	model->clear();
	SetHorizontalHeader();
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_LIST;
	emit
	SendLendInfo(tmpInfo);
}
void LendManage::LendReturn()
{
	MANAGEINFO tmpInfo;
	QModelIndex index;
	index = lendTable->currentIndex();
	if (!index.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a book!"));

		return;
	}
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_RETURN;
	GetRowData(index, &tmpInfo);
	if (QMessageBox::question(this, tr("Return Book"), tr("Return <<")
			+ tmpInfo.lendInfo.sName + tr(">>?"), QMessageBox::Cancel,
			QMessageBox::Ok) == QMessageBox::Cancel)
	{
		return;
	}emit
	SendLendInfo(tmpInfo);
	model->removeRow(index.row());
}
void LendManage::LendRenewal(LENDINFO &lendInfo)
{
	MANAGEINFO tmpInfo;
	QModelIndex index;
	index = lendTable->currentIndex();
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_RENEWAL;
	GetRowData(index, &tmpInfo);
	tmpInfo.lendInfo.dwLendDays += lendInfo.dwLendDays;
	//SetTableData(tmpInfo, index.row());
	emit
	SendLendInfo(tmpInfo);
}
void LendManage::GetRenewalInfo()
{
	reader->setWindowTitle(tr("Renewal"));
	MANAGEINFO tmpInfo;
	QModelIndex index;
	index = lendTable->currentIndex();
	if (!index.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a book!"));
		return;
	}
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_RENEWAL;
	GetRowData(index, &tmpInfo);
	reader->idEdit->setText(tmpInfo.lendInfo.sReaderID);
	reader->nameEdit->setText(tmpInfo.lendInfo.sReader);
	reader->idEdit->setEnabled(false);
	reader->nameEdit->setEnabled(false);
	reader->show();
}

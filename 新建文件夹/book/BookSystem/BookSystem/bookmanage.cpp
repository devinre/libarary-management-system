#include "bookmanage.h"

BookManage::BookManage(QWidget *parent) :
	QMainWindow(parent), row(0)
{
	setupUi(this);
	SetUpModel(this);
	SetTableView(bkTable);
	bkDlg = new BookDialog(this);
	reader = new ReaderInfo(this);
	QObject::connect(addBook, SIGNAL(triggered()), this, SLOT(AddBookInfo()));
	QObject::connect(bkDlg, SIGNAL(GetBookInfo(const BOOKINFO &)), this,
			SLOT(SetBookTableInfo(const BOOKINFO &)));
	QObject::connect(delBook, SIGNAL(triggered()), this, SLOT(DelBookInfo()));
	QObject::connect(bkTable, SIGNAL(doubleClicked(const QModelIndex &)), this,
			SLOT(UpdateBookInfo(const QModelIndex &)));
	QObject::connect(updateBook, SIGNAL(triggered()), this,
			SLOT(UpdateBookInfo()));
	/*QObject::connect(queryBook, SIGNAL(triggered()), this,
			SLOT(QueryBookInfo()));*/
	QObject::connect(refresh, SIGNAL(triggered()), this, SLOT(BookList()));
	QObject::connect(bkSearchBtn, SIGNAL(clicked()), this, SLOT(SearchBook()));
	QObject::connect(lendOut, SIGNAL(triggered()), this, SLOT(GetReaderInfo()));
	QObject::connect(reader, SIGNAL(SetReaderInfo(LENDINFO &)), this,
			SLOT(LendOutBookInfo(LENDINFO &)));
}

BookManage::~BookManage()
{

}
void BookManage::SetEnabled(bool ok)
{
	addBook->setEnabled(ok);
	delBook->setEnabled(ok);
	lendOut->setEnabled(ok);
	updateBook->setEnabled(ok);
	bkDlg->setEnabled(ok);
}
void BookManage::UpdateBookInfo()
{
	QModelIndex index;
	manageInfo.dwType = BOOK;
	manageInfo.dwSubType = BOOK_UPDATE;
	index = bkTable->currentIndex();
	UpdateBookInfo(index);
}
void BookManage::SetHorizontalHeader()
{
	model->setRowCount(0);
	model->setColumnCount(11);
	model->setHeaderData(0, Qt::Horizontal, tr("Status"));
	model->setHeaderData(1, Qt::Horizontal, tr("ID"));
	model->setHeaderData(2, Qt::Horizontal, tr("BookName"));
	model->setHeaderData(3, Qt::Horizontal, tr("Author"));
	model->setHeaderData(4, Qt::Horizontal, tr("Type"));
	model->setHeaderData(5, Qt::Horizontal, tr("Press"));
	model->setHeaderData(6, Qt::Horizontal, tr("PublishDate"));
	model->setHeaderData(7, Qt::Horizontal, tr("PageNum"));
	model->setHeaderData(8, Qt::Horizontal, tr("Price"));
	model->setHeaderData(9, Qt::Horizontal, tr("AddTime"));
	model->setHeaderData(10, Qt::Horizontal, tr("LendTimes"));
}
void BookManage::AddBookInfo()
{
	bkDlg->idEdit->setEnabled(true);
	bkDlg->setWindowTitle(tr("AddBook"));
	bkDlg->lendTimesEdit->setText(QString("%1").arg(0));
	bkDlg->show();
	manageInfo.dwType = BOOK;
	manageInfo.dwSubType = BOOK_ADD;
}
void BookManage::RecvResultInfo(const BOOKLOGINFO &resultInfo)
{
	bkTable->clearSelection();
	if (!resultInfo.dwResult)
	{
		switch (resultInfo.dwOperation)
		{
		case BOOK_ADD:
			if (QMessageBox::question(this, tr("Result"),
					resultInfo.sDescription + tr("Continue?"),
					QMessageBox::Cancel, QMessageBox::Ok)
					== QMessageBox::Cancel)
			{
				bkDlg->close();
			}
			else
			{
				AddBookInfo();
			}
			return;
		case BOOK_DELETE:
			break;
		case BOOK_QUERY:
			break;
		case BOOK_UPDATE:
			SetTableData(manageInfo, row);
			bkDlg->close();
			break;
		case BOOK_RESPONSE:
			break;
		case BOOK_LIST:
			break;
		case LEND_LENDOUT:
			SetTableData(manageInfo, row);
			break;
		}
	}
	QMessageBox::information(this, tr("Result"), resultInfo.sDescription);

}
void BookManage::SetBookTableInfo(const BOOKINFO &bookInfo)
{
	manageInfo.bookInfo = bookInfo;
	switch (manageInfo.dwSubType)
	{
	case BOOK_ADD:
		row = model->rowCount();
		model->insertRow(row);
		SetTableData(manageInfo, row);
		break;
	case BOOK_DELETE:
		break;
	case BOOK_QUERY:
		model->clear();
		SetHorizontalHeader();
		break;
	case BOOK_UPDATE:
		break;
	case BOOK_RESPONSE:
		break;
	case BOOK_LIST:
		break;
	}
	emit
	SendBookInfo(manageInfo);
}
void BookManage::InsertResponseBookInfo(MANAGEINFO &tmpInfo)
{
	if (!tmpInfo.dwSubType)
	{
		return;
	}
	row = model->rowCount();
	model->insertRow(row);
	SetTableData(tmpInfo, row);
	tmpInfo.dwType = BOOK;
	tmpInfo.dwSubType = BOOK_RESPONSE;
	emit
	SendBookInfo(tmpInfo);
}

void BookManage::DelBookInfo()
{
	MANAGEINFO tmpInfo;
	gIndex = bkTable->currentIndex();
	if (!gIndex.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a book!"));

		return;
	}
	tmpInfo.dwType = BOOK;
	tmpInfo.dwSubType = BOOK_DELETE;
	GetRowData(gIndex, &tmpInfo);
	if (QMessageBox::question(this, tr("Delete Book"), tr("Delete <<")
			+ tmpInfo.bookInfo.sName + tr(">>?"), QMessageBox::Cancel,
			QMessageBox::Ok) == QMessageBox::Cancel)
	{
		return;
	}emit
	SendBookInfo(tmpInfo);
	model->removeRow(gIndex.row());
}
void BookManage::UpdateBookInfo(const QModelIndex &index)
{
	bkDlg->idEdit->setEnabled(false);
	if (!index.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a book!"));

		return;
	}
	bkDlg->setWindowTitle(tr("UpdateBook"));
	manageInfo.dwType = BOOK;
	manageInfo.dwSubType = BOOK_UPDATE;
	row = index.row();
	GetRowData(index, &manageInfo);
	bkDlg->idEdit->setText(manageInfo.bookInfo.sID);
	bkDlg->nameEdit->setText(manageInfo.bookInfo.sName);
	bkDlg->authorEdit->setText(manageInfo.bookInfo.sAuthor);
	bkDlg->typeEdit->setText(manageInfo.bookInfo.sType);
	bkDlg->pressEdit->setText(manageInfo.bookInfo.sPress);
	bkDlg->pressDateBox->setDate(QDate::fromString(
			manageInfo.bookInfo.sPressDate, DATE));
	bkDlg->pageNumBox->setValue(manageInfo.bookInfo.dwPageNum);
	bkDlg->priceBox->setValue(manageInfo.bookInfo.fPrice);
	bkDlg->lendTimesEdit->setText(QString("%1").arg(
			manageInfo.bookInfo.dwLendTimes));
	bkDlg->statusBox->setCurrentIndex(manageInfo.bookInfo.dwStatus);
	bkDlg->show();
}
/*void BookManage::QueryBookInfo()
{
	bkDlg->idEdit->setEnabled(true);
	bkDlg->setWindowTitle(tr("QueryBook"));
	manageInfo.dwType = BOOK;
	manageInfo.dwSubType = BOOK_QUERY;
	bkDlg->show();
}*/
void BookManage::BookList()
{
	model->clear();
	SetHorizontalHeader();
	manageInfo.dwType = BOOK;
	manageInfo.dwSubType = BOOK_LIST;
	emit
	SendBookInfo(manageInfo);
}
void BookManage::SearchBook()
{
	model->clear();
	SetHorizontalHeader();
	manageInfo.dwType = BOOK;
	manageInfo.dwSubType = BOOK_QUERY;
	manageInfo.bookInfo.sID = bkIDEdit->text();
	manageInfo.bookInfo.sName = bkNameEdit->text();
	manageInfo.bookInfo.sType = bkTypeEdit->text();
	emit
	SendBookInfo(manageInfo);
}
void BookManage::LendOutBookInfo(LENDINFO &lendInfo)
{
	QDate lendDate;
	MANAGEINFO tmpInfo;
	/*	QModelIndex index;
	 index = bkTable->currentIndex();*/
	tmpInfo.dwType = BOOK;
	GetRowData(gIndex, &tmpInfo);//获取要借出的书籍信息
	lendInfo.dwPageNum = tmpInfo.bookInfo.dwPageNum;
	lendInfo.fPrice = tmpInfo.bookInfo.fPrice;
	lendInfo.sAuthor = tmpInfo.bookInfo.sAuthor;
	lendInfo.sID = tmpInfo.bookInfo.sID;
	lendInfo.sLendDate = lendDate.currentDate().toString(DATE);
	lendInfo.sName = tmpInfo.bookInfo.sName;
	lendInfo.sPress = tmpInfo.bookInfo.sPress;
	lendInfo.sPressDate = tmpInfo.bookInfo.sPressDate;
	lendInfo.sType = tmpInfo.bookInfo.sType;
	lendInfo.dwTimeOut = LEND_NOTOVERDUE;
	lendInfo.dwOverDays = 0;
	manageInfo = tmpInfo;
	manageInfo.bookInfo.dwStatus = BOOK_STATUS_LEND;
	tmpInfo.dwType = LEND;
	tmpInfo.dwSubType = LEND_LENDOUT;
	tmpInfo.lendInfo = lendInfo;
	emit
	SendBookInfo(tmpInfo);
}
void BookManage::GetReaderInfo()
{
	reader->setWindowTitle(tr("ReaderInformation"));
	reader->idEdit->setEnabled(true);
	reader->nameEdit->setEnabled(true);
	gIndex = bkTable->currentIndex();
	row = gIndex.row();
	if (!gIndex.isValid())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Select a book!"));
		return;
	}
	reader->show();
}

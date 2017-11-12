/*
 * TableView.cpp
 *
 *  Created on: 2010-4-18
 *      Author: Administrator
 */

#include "TableView.h"

TableView::TableView(QWidget *parent)
{
	sexMap.insert(MALE, TR("Male"));
	sexMap.insert(FEMALE, TR("Female"));

	userStatusMap.insert(USER_STATUS_NORMAL, TR("Normal"));
	userStatusMap.insert(USER_STATUS_NOUSE, TR("Non-Use"));

	onlineMap.insert(USER_ONLINE, TR("Online"));
	onlineMap.insert(USER_OFFLINE, TR("OffLine"));

	powerMap.insert(0, TR("Administrator"));
	powerMap.insert(1, TR("Operator"));

	bookStatusMap.insert(BOOK_STATUS_NOTLEND, TR("[ InLibrary ]"));
	bookStatusMap.insert(BOOK_STATUS_LEND, TR("[ LendOut ]"));
	bookStatusMap.insert(BOOK_STATUS_LOSS, TR("[ Lost ]"));

	userOpMap.insert(USER_LOGON, TR("LogonSystem"));
	userOpMap.insert(USER_ADD, TR("AddUser"));
	userOpMap.insert(USER_DELETE, TR("DeleteUser"));
	userOpMap.insert(USER_UPDATE, TR("UpdateUser"));
	userOpMap.insert(USER_UPDATEPWD, TR("ModifyPassword"));
	userOpMap.insert(USER_LOGOUT, TR("LogOut"));
	userOpMap.insert(BOOKLOG_DELETE, TR("DeleteBookLog"));
	userOpMap.insert(READER_ADD, TR("AddReader"));
	userOpMap.insert(READER_DELETE, TR("DeleteReader"));
	userOpMap.insert(READER_UPDATE, TR("UpdateReader"));

	readerTypeMap.insert(READER_NORMAL, TR("General"));
	readerTypeMap.insert(READER_VIP, TR("VIP"));

	bookOpMap.insert(BOOK_ADD, TR("AddBook"));
	bookOpMap.insert(BOOK_DELETE, TR("DeleteBook"));
	bookOpMap.insert(BOOK_UPDATE, TR("UpdateBook"));
	bookOpMap.insert(LEND_LENDOUT, TR("LendOutBook"));
	bookOpMap.insert(LEND_RETURN, TR("ReturnBook"));
	bookOpMap.insert(LEND_RENEWAL, TR("Renewal"));
	bookOpMap.insert(LEND_DELETE, TR("DeleteLendBook"));
	// TODO Auto-generated constructor stub
}

TableView::~TableView()
{
	// TODO Auto-generated destructor stub
}
void TableView::SetTableView(QTableView *tableView)
{
	tableView->setHorizontalHeader(hHeader);
	tableView->setVerticalHeader(vHeader);
	tableView->setModel(model);
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableView->setSortingEnabled(true);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->verticalHeader()->hide();
}
void TableView::SetHorizontalHeader()
{
}
void TableView::GetManageInfo(MANAGEINFO &manageInfo)
{
	SetTableData(manageInfo);
}
void TableView::SetUpModel(QWidget *parent)
{
	hHeader = new QHeaderView(Qt::Horizontal, parent);
	hHeader->setClickable(true);
	hHeader->setDefaultSectionSize(130);
	vHeader = new QHeaderView(Qt::Vertical, parent);
	vHeader->setDefaultSectionSize(25);
	model = new QStandardItemModel(parent);
	SetHorizontalHeader();
}
void TableView::SetTableData(MANAGEINFO &manageInfo, int row)
{
	switch (manageInfo.dwType)
	{
	case USER:
		SetUserTableData(manageInfo.userInfo, row);
		break;
	case BOOK:
		SetBookTableData(manageInfo.bookInfo, row);
		break;
	case LEND:
		SetLendTableData(manageInfo.lendInfo, row);
		break;
	case READER:
		SetReaderTableData(manageInfo.readerInfo, row);
		break;
	case BOOKLOG:
		SetBookLogTableData(manageInfo.bookLogInfo, row);
		break;
	case USERLOG:
		SetUserLogTableData(manageInfo.userLogInfo, row);
		break;
	default:
		return;
	}
}
////////////////////////SetUserTableData///////////////////////////
void TableView::SetUserTableData(USERINFO &userInfo, int row)
{
	QIcon icon;
	QStandardItem *item = new QStandardItem;
	if (userInfo.dwSex == MALE)
	{
		icon.addFile(QString::fromUtf8(":/icon/male.png"), QSize(),
				QIcon::Normal, QIcon::Off);
	}
	else
	{
		icon.addFile(QString::fromUtf8(":/icon/female.png"), QSize(),
				QIcon::Normal, QIcon::Off);
	}
	item->setIcon(icon);
	item->setData(sexMap.value(userInfo.dwSex), Qt::DisplayRole);
	model->setItem(row, 0, item);
	model->setData(model->index(row, 1), userInfo.sID);
	model->setData(model->index(row, 2), userInfo.sName);
	model->setData(model->index(row, 3), userInfo.sPass);
	model->setData(model->index(row, 4), powerMap.value(userInfo.dwPower));
	model->setData(model->index(row, 5), userInfo.sBirthDay);
	model->setData(model->index(row, 6), userInfo.sIDCard);
	model->setData(model->index(row, 7), userInfo.sPhone);
	model->setData(model->index(row, 8), userStatusMap.value(userInfo.dwStatus));
	model->setData(model->index(row, 9), userInfo.sLoginTime);
	model->setData(model->index(row, 10), userInfo.sEmail);
	model->setData(model->index(row, 11), onlineMap.value(userInfo.dwOnline));
	model->setData(model->index(row, 12), userInfo.sLastTime);
}
/////////////////////////SetBookTableData/////////////////////////
void TableView::SetBookTableData(BOOKINFO &bookInfo, int row)
{
	QIcon icon;
	QStandardItem *item = new QStandardItem;
	if (bookInfo.dwStatus == BOOK_STATUS_LEND)
	{
		icon.addFile(QString::fromUtf8(":/icon/lend.png"), QSize(),
				QIcon::Normal, QIcon::Off);
	}
	else if (bookInfo.dwStatus == BOOK_STATUS_NOTLEND)
	{
		icon.addFile(QString::fromUtf8(":/icon/inlibrary.png"), QSize(),
				QIcon::Normal, QIcon::Off);
	}
	else if (bookInfo.dwStatus == BOOK_STATUS_LOSS)
	{
		icon.addFile(QString::fromUtf8(":/icon/lost.png"), QSize(),
				QIcon::Normal, QIcon::Off);
	}
	item->setIcon(icon);
	item->setData(bookStatusMap.value(bookInfo.dwStatus), Qt::DisplayRole);
	model->setItem(row, 0, item);
	model->setData(model->index(row, 1), bookInfo.sID);
	model->setData(model->index(row, 2), bookInfo.sName);
	model->setData(model->index(row, 3), bookInfo.sAuthor);
	model->setData(model->index(row, 4), bookInfo.sType);
	model->setData(model->index(row, 5), bookInfo.sPress);
	model->setData(model->index(row, 6), bookInfo.sPressDate);
	model->setData(model->index(row, 7), bookInfo.dwPageNum);
	model->setData(model->index(row, 8), bookInfo.fPrice);
	model->setData(model->index(row, 9), bookInfo.sAddDate);
	model->setData(model->index(row, 10), bookInfo.dwLendTimes);
}
//////////////////////////SetLendTableData//////////////////////////
void TableView::SetLendTableData(LENDINFO &lendInfo, int row)
{
	QIcon icon;
	QString overDays;
	overDays = "[ " + QString("%1").arg(lendInfo.dwOverDays) + " ]";
	QStandardItem *item = new QStandardItem;
	if (lendInfo.dwTimeOut)
	{
		icon.addFile(QString::fromUtf8(":/icon/overdue.png"), QSize(),
				QIcon::Normal, QIcon::Off);
	}
	else
	{
		icon.addFile(QString::fromUtf8(":/icon/notoverdue.png"), QSize(),
				QIcon::Normal, QIcon::Off);
	}
	item->setIcon(icon);
	model->setItem(row, 0, item);
	model->setData(model->index(row, 0), overDays);
	model->setData(model->index(row, 1), lendInfo.sReaderID);
	model->setData(model->index(row, 2), lendInfo.sReader);
	model->setData(model->index(row, 3), lendInfo.sID);
	model->setData(model->index(row, 4), lendInfo.sName);
	model->setData(model->index(row, 5), lendInfo.sAuthor);
	model->setData(model->index(row, 6), lendInfo.sType);
	model->setData(model->index(row, 7), lendInfo.sPress);
	model->setData(model->index(row, 8), lendInfo.sPressDate);
	model->setData(model->index(row, 9), lendInfo.dwPageNum);
	model->setData(model->index(row, 10), lendInfo.fPrice);
	model->setData(model->index(row, 11), lendInfo.dwLendDays);
	model->setData(model->index(row, 12), lendInfo.sLendDate);
}
//////////////////////SetBookLogTableData/////////////////////
void TableView::SetBookLogTableData(BOOKLOGINFO &bookLogInfo, int row)
{
	QIcon icon;
	QStandardItem *item = new QStandardItem;
	if (bookLogInfo.dwResult)
	{
		icon.addFile(QString::fromUtf8(":/icon/failure.png"), QSize(),
				QIcon::Normal, QIcon::Off);
		item->setData(TR("FAILURE"), Qt::DisplayRole);
	}
	else
	{
		icon.addFile(QString::fromUtf8(":/icon/success.png"), QSize(),
				QIcon::Normal, QIcon::Off);
		item->setData(TR("SUEECSS"), Qt::DisplayRole);
	}
	item->setIcon(icon);
	model->setItem(row, 0, item);
	model->setData(model->index(row, 1), bookLogInfo.sOperator);
	model->setData(model->index(row, 2), bookLogInfo.sBookID);
	model->setData(model->index(row, 3), bookLogInfo.sBookName);
	model->setData(model->index(row, 4), bookOpMap.value(
			bookLogInfo.dwOperation));
	model->setData(model->index(row, 5), bookLogInfo.sIP);
	model->setData(model->index(row, 6), bookLogInfo.sType);
	model->setData(model->index(row, 7), bookLogInfo.sDescription);
	model->setData(model->index(row, 8), bookLogInfo.sDateTime);
}
//////////////////////SetReaderTableData///////////////////////////
void TableView::SetReaderTableData(READERINFO &readerInfo, int row)
{
	model->setData(model->index(row, 0), readerInfo.sID);
	model->setData(model->index(row, 1), readerInfo.sName);
	model->setData(model->index(row, 2), sexMap.value(readerInfo.dwSex));
	model->setData(model->index(row, 3), readerInfo.sBirthDay);
	model->setData(model->index(row, 4), readerInfo.sCardDate);
	model->setData(model->index(row, 5), readerInfo.sCardNum);
	model->setData(model->index(row, 6), readerTypeMap.value(readerInfo.dwType));
	if (readerInfo.dwStatus)
		model->setData(model->index(row, 7), "ReportLoss");
	else
		model->setData(model->index(row, 7), "Normal");
	model->setData(model->index(row, 8), readerInfo.sSchool);
	model->setData(model->index(row, 9), readerInfo.sDepartment);
	model->setData(model->index(row, 10), readerInfo.dwGrade);
	model->setData(model->index(row, 11), readerInfo.sIDCard);
	model->setData(model->index(row, 12), readerInfo.sAddress);
	model->setData(model->index(row, 13), readerInfo.sPost);
	model->setData(model->index(row, 14), readerInfo.sPhone);
	model->setData(model->index(row, 15), readerInfo.sEmail);
}
////////////////////////SetUserLogTableData///////////////////////
void TableView::SetUserLogTableData(USERLOGINFO &userLogInfo, int row)
{
	QIcon icon;
	QStandardItem *item = new QStandardItem;
	if (userLogInfo.dwResult)
	{
		icon.addFile(QString::fromUtf8(":/icon/failure.png"), QSize(),
				QIcon::Normal, QIcon::Off);
		item->setData("FAILURE", Qt::DisplayRole);
	}
	else
	{
		icon.addFile(QString::fromUtf8(":/icon/success.png"), QSize(),
				QIcon::Normal, QIcon::Off);
		item->setData("SUCCESS", Qt::DisplayRole);
	}
	item->setIcon(icon);
	model->setItem(row, 0, item);
	model->setData(model->index(row, 1), userLogInfo.sOperator);

	model->setData(model->index(row, 2), userOpMap.value(
			userLogInfo.dwOperation));
	model->setData(model->index(row, 3), userLogInfo.sIP);
	model->setData(model->index(row, 4), userLogInfo.sDescription);
	model->setData(model->index(row, 5), userLogInfo.sDateTime);
}
void TableView::GetRowData(const QModelIndex &index, MANAGEINFO *manageInfo)
{
	switch (manageInfo->dwType)
	{
	case USER:
		GetRowUserData(index, manageInfo);
		break;
	case BOOK:
		GetRowBookData(index, manageInfo);
		break;
	case LEND:
		GetRowLendData(index, manageInfo);
		break;
	case READER:
		GetRowReaderData(index, manageInfo);
		break;
	default:
		return;
	}
}
void TableView::GetRowUserData(const QModelIndex &index, MANAGEINFO *manageInfo)
{
	USERINFO userInfo;
	int row = index.row();
	userInfo.dwSex = sexMap.key(model->data(model->index(row, 0)).toString());
	userInfo.sID = model->data(model->index(row, 1)).toString();
	userInfo.sName = model->data(model->index(row, 2)).toString();
	userInfo.sPass = model->data(model->index(row, 3)).toString();
	userInfo.dwPower = powerMap.key(
			model->data(model->index(row, 4)).toString());
	userInfo.sBirthDay = model->data(model->index(row, 5)).toString();
	userInfo.sIDCard = model->data(model->index(row, 6)).toString();
	userInfo.sPhone = model->data(model->index(row, 7)).toString();
	userInfo.dwStatus = userStatusMap.key(
			model->data(model->index(row, 8)).toString());
	userInfo.sEmail = model->data(model->index(row, 10)).toString();
	manageInfo->userInfo = userInfo;
}
void TableView::GetRowBookData(const QModelIndex &index, MANAGEINFO *manageInfo)
{
	BOOKINFO bookInfo;
	bool ok;
	int row = index.row();
	bookInfo.dwStatus = bookStatusMap.key(
			model->data(model->index(row, 0)).toString());
	bookInfo.sID = model->data(model->index(row, 1)).toString();
	bookInfo.sName = model->data(model->index(row, 2)).toString();
	bookInfo.sAuthor = model->data(model->index(row, 3)).toString();
	bookInfo.sType = model->data(model->index(row, 4)).toString();
	bookInfo.sPress = model->data(model->index(row, 5)).toString();
	bookInfo.sPressDate = model->data(model->index(row, 6)).toString();
	bookInfo.dwPageNum = model->data(model->index(row, 7)).toInt(&ok);
	bookInfo.fPrice = model->data(model->index(row, 8)).toDouble(&ok);
	bookInfo.sAddDate = model->data(model->index(row, 9)).toString();
	bookInfo.dwLendTimes = model->data(model->index(row, 10)).toInt(&ok);
	manageInfo->bookInfo = bookInfo;

}
void TableView::GetRowReaderData(const QModelIndex &index,
		MANAGEINFO *manageInfo)
{

}
void TableView::GetRowLendData(const QModelIndex &index, MANAGEINFO *manageInfo)
{
	LENDINFO lendInfo;
	bool ok;
	int row = index.row();
	lendInfo.sReaderID = model->data(model->index(row, 1)).toString();
	lendInfo.sReader = model->data(model->index(row, 2)).toString();
	lendInfo.sID = model->data(model->index(row, 3)).toString();
	lendInfo.sName = model->data(model->index(row, 4)).toString();
	lendInfo.sAuthor = model->data(model->index(row, 5)).toString();
	lendInfo.sType = model->data(model->index(row, 6)).toString();
	lendInfo.sPress = model->data(model->index(row, 7)).toString();
	lendInfo.sPressDate = model->data(model->index(row, 8)).toString();
	lendInfo.dwPageNum = model->data(model->index(row, 9)).toInt(&ok);
	lendInfo.fPrice = model->data(model->index(row, 10)).toDouble(&ok);
	manageInfo->lendInfo = lendInfo;
}

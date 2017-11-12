/*
 * SqlCommand.cpp
 *
 *  Created on: 2009-8-24
 *      Author: Administrator
 */

#include "SqlCommand.h"
#include "GlobalDefine.h"
SqlCommand::SqlCommand(QObject *parent) :
	QObject(parent)
{
	qRegisterMetaType<MANAGEINFO> ("MANAGEINFO");
	// TODO Auto-generated constructor stub
}

SqlCommand::~SqlCommand()
{
	// TODO Auto-generated destructor stub
}
////////////////////////////////////////////////////////////////////
//////////////////////////////////BOOKMANAGE////////////////////////
////////////////////////////////////////////////////////////////////
void SqlCommand::RecvBookInfo(QDataStream &in, MANAGEINFO &recvInfo)
{
	BOOKINFO bookInfo;
	switch (recvInfo.dwSubType)
	{
	case BOOK_ADD:
		GetBookInfo(in, bookInfo);
		BookAddInfo(bookInfo);
		break;
	case BOOK_DELETE:
		GetBookInfo(in, bookInfo);
		BookDelInfo(bookInfo);
		break;
	case BOOK_LIST:
		BookListInfo(bookInfo);
		break;
	case BOOK_QUERY:
		GetBookInfo(in, bookInfo);
		BookQueryInfo(bookInfo);
		break;
	case BOOK_RESPONSE:
		BookResponse();
		break;
	case BOOK_UPDATE:
		GetBookInfo(in, bookInfo);
		BookUpdateInfo(bookInfo);
		break;
	default:
		return;
	}
}
void SqlCommand::GetBookInfo(QDataStream &in, BOOKINFO &bookInfo)
{
	in >> bookInfo.sID;
	in >> bookInfo.sName;
	in >> bookInfo.sAuthor;
	in >> bookInfo.sType;
	in >> bookInfo.sPress;
	in >> bookInfo.sPressDate;
	in >> bookInfo.dwPageNum;
	in >> bookInfo.fPrice;
	in >> bookInfo.sAddDate;
	in >> bookInfo.dwLendTimes;
	in >> bookInfo.dwStatus;
}
void SqlCommand::BookAddInfo(BOOKINFO &bookInfo)
{
	QString sSql;
	MANAGEINFO tmpInfo;
	BOOKLOGINFO bookLogInfo;
	sSql = "SELECT name, author, type, press, "
		"pressdate, pagenum, price, adddate, lendtimes, "
		"status, bookID FROM tbl_book WHERE bookID = '" + bookInfo.sID + "'";
	if (!IsExist(sSql))
	{
		sSql = "INSERT INTO tbl_book(name, author, type, press, "
			"pressdate, pagenum, price, adddate, lendtimes, "
			"status, bookID) VALUES('" + bookInfo.sName + "','"
				+ bookInfo.sAuthor + "','" + bookInfo.sType + "','"
				+ bookInfo.sPress + "','" + bookInfo.sPressDate + "','"
				+ QString("%1").arg(bookInfo.dwPageNum) + "','"
				+ QString("%1").arg(bookInfo.fPrice) + "','"
				+ bookInfo.sAddDate + "','" + QString("%1").arg(
				bookInfo.dwLendTimes) + "','" + QString("%1").arg(
				bookInfo.dwStatus) + "','" + bookInfo.sID + "')";
		bookLogInfo.sBookID = bookInfo.sID;
		bookLogInfo.sBookName = bookInfo.sName;
		bookLogInfo.dwOperation = BOOK_ADD;
		bookLogInfo.sType = bookInfo.sType;
		bookLogInfo.sIP = gUserLogInfo.sIP;
		bookLogInfo.sOperator = gUserLogInfo.sOperator;
		bookLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);

		if (ExcuteSqlCmd(sSql))
		{
			bookLogInfo.dwResult = SUCCESS;
			bookLogInfo.sDescription = tr("Add book<<") + bookInfo.sName + tr(
					">>successfully!");
		}
		else
		{
			bookLogInfo.dwResult = FAILURE;
			bookLogInfo.sDescription = tr("DB ERROR");
		}
	}
	else
	{
		bookLogInfo.dwResult = FAILURE;
		bookLogInfo.sDescription = tr("Book<<") + bookInfo.sID + tr(
				">>have exist");
	}

	ExcuteBookLogAdd(bookLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = BOOK;
	tmpInfo.bookLogInfo = bookLogInfo;
	Information(tmpInfo);
}
void SqlCommand::BookDelInfo(BOOKINFO &bookInfo)
{
	MANAGEINFO tmpInfo;
	BOOKLOGINFO bookLogInfo;
	QString sSql;
	bookLogInfo.sBookID = bookInfo.sID;
	bookLogInfo.sBookName = bookInfo.sName;
	bookLogInfo.dwOperation = BOOK_DELETE;
	bookLogInfo.sType = bookInfo.sType;
	bookLogInfo.sIP = gUserLogInfo.sIP;
	bookLogInfo.sOperator = gUserLogInfo.sOperator;
	bookLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	sSql = "SELECT name, author, type, press, "
		"pressdate, pagenum, price, adddate, lendtimes, "
		"status, bookID FROM tbl_book WHERE bookID = '" + bookInfo.sID + "'";
	if (IsExist(sSql))
	{
		sSql = "DELETE FROM tbl_book where bookID = '" + bookInfo.sID + "'";
		if (ExcuteSqlCmd(sSql))
		{

			bookLogInfo.dwResult = SUCCESS;
			bookLogInfo.sDescription = tr("Delete book<<") + bookInfo.sName
					+ tr(">>successfully!");

		}
		else
		{
			bookLogInfo.dwResult = FAILURE;
			bookLogInfo.sDescription = tr("DB ERROR");
		}
	}
	else
	{
		bookLogInfo.dwResult = FAILURE;
		bookLogInfo.sDescription = tr("Delete book<<") + bookInfo.sName + tr(
				">>failed,No such book!");
	}
	ExcuteBookLogAdd(bookLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = BOOK;
	tmpInfo.bookLogInfo = bookLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::BookListInfo(BOOKINFO &bookInfo)
{
	MANAGEINFO tmpInfo;
	QString sSql = "SELECT name, author, type, press, "
		"pressdate, pagenum, price, adddate, lendtimes, "
		"status, bookID FROM tbl_book";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextBook(tmpInfo.bookInfo))
		{
			tmpInfo.dwSubType = BOOK_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = BOOK;
	emit
	Information(tmpInfo);
}
void SqlCommand::BookResponse()
{
	MANAGEINFO tmpInfo;
	if (GetNextBook(tmpInfo.bookInfo))
	{
		tmpInfo.dwSubType = BOOK_RESPONSE;
	}
	else
	{
		tmpInfo.dwSubType = SUCCESS;
	}
	tmpInfo.dwType = BOOK;
	emit
	Information(tmpInfo);
}
void SqlCommand::BookQueryInfo(BOOKINFO &bookInfo)
{
	MANAGEINFO tmpInfo;
	QString sSql = "SELECT name, author, type, press, "
		"pressdate, pagenum, price, adddate, lendtimes, "
		"status, bookID FROM tbl_book WHERE name like '%" + bookInfo.sName
			+ "%'and  bookID like'%" + bookInfo.sID + "%'and  type like'%"
			+ bookInfo.sType + "%'";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextBook(tmpInfo.bookInfo))
		{
			tmpInfo.dwSubType = BOOK_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = BOOK;
	emit
	Information(tmpInfo);
}
void SqlCommand::BookUpdateInfo(BOOKINFO &bookInfo)
{
	MANAGEINFO tmpInfo;
	BOOKLOGINFO bookLogInfo;
	bookLogInfo.sBookID = bookInfo.sID;
	bookLogInfo.sBookName = bookInfo.sName;
	bookLogInfo.dwOperation = BOOK_UPDATE;
	bookLogInfo.sType = bookInfo.sType;
	bookLogInfo.sIP = gUserLogInfo.sIP;
	bookLogInfo.sOperator = gUserLogInfo.sOperator;
	bookLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	QString sSql = "UPDATE tbl_book SET name='" + bookInfo.sName
			+ "', author='" + bookInfo.sAuthor + "', type='" + bookInfo.sType
			+ "', press='" + bookInfo.sPress + "', pressdate='"
			+ bookInfo.sPressDate + "', pagenum='" + QString("%1").arg(
			bookInfo.dwPageNum) + "', price='" + QString("%1").arg(
			bookInfo.fPrice) + "', status='" + QString("%1").arg(
			bookInfo.dwStatus) + "'WHERE bookID='" + bookInfo.sID + "'";
	if (ExcuteSqlCmd(sSql))
	{
		bookLogInfo.dwResult = SUCCESS;
		bookLogInfo.sDescription = tr("Update book<<") + bookInfo.sName + tr(
				">>successfully!");
	}
	else
	{
		bookLogInfo.dwResult = FAILURE;
		bookLogInfo.sDescription = tr("DB ERROR");
	}
	ExcuteBookLogAdd(bookLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = BOOK;
	tmpInfo.bookLogInfo = bookLogInfo;
	emit
	Information(tmpInfo);
}
bool SqlCommand::GetNextBook(BOOKINFO &bookInfo)
{
	if (sqlQuery.isSelect() && sqlQuery.next())
	{
		bookInfo.sName = sqlQuery.value(0).toString();
		bookInfo.sAuthor = sqlQuery.value(1).toString();
		bookInfo.sType = sqlQuery.value(2).toString();
		bookInfo.sPress = sqlQuery.value(3).toString();
		bookInfo.sPressDate = sqlQuery.value(4).toString();
		bookInfo.dwPageNum = sqlQuery.value(5).toInt(&ok);
		bookInfo.fPrice = sqlQuery.value(6).toDouble(&ok);
		bookInfo.sAddDate = sqlQuery.value(7).toString();
		bookInfo.dwLendTimes = sqlQuery.value(8).toInt(&ok);
		bookInfo.dwStatus = sqlQuery.value(9).toInt(&ok);
		bookInfo.sID = sqlQuery.value(10).toString();
		return true;
	}
	else
	{
		sqlQuery.clear();
		return false;
	}
}
void SqlCommand::SendBookInfo(QDataStream &out, MANAGEINFO &sendInfo)
{
	BOOKINFO tmpInfo = sendInfo.bookInfo;
	out << tmpInfo.sID;
	out << tmpInfo.sName;
	out << tmpInfo.sAuthor;
	out << tmpInfo.sType;
	out << tmpInfo.sPress;
	out << tmpInfo.sPressDate;
	out << tmpInfo.dwPageNum;
	out << tmpInfo.fPrice;
	out << tmpInfo.sAddDate;
	out << tmpInfo.dwLendTimes;
	out << tmpInfo.dwStatus;
}

//////////////////////////////////////////////////////////////////////////
///////////////////////////USERMANAGE/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
void SqlCommand::RecvUserInfo(QDataStream &in, MANAGEINFO &recvInfo)
{
	USERINFO lUserLogInfo;
	switch (recvInfo.dwSubType)
	{
	case USER_ADD://USERADD
		GetUserInfo(in, lUserLogInfo);
		UserAddInfo(lUserLogInfo);
		break;
	case USER_DELETE://USERDELETE
		GetUserInfo(in, lUserLogInfo);
		UserDelInfo(lUserLogInfo);
		break;
	case USER_LIST://USERLIST
		UserListInfo(lUserLogInfo);
		break;
	case USER_UPDATE://USERDELETE
		GetUserInfo(in, lUserLogInfo);
		UserUpdateInfo(lUserLogInfo);
		break;
	case USER_RESPONSE://USERRESPONSE
		UserResponse();
		break;
	case USER_EXIT://USEREXIT
		GetUserInfo(in, lUserLogInfo);
		UserExitInfo(lUserLogInfo);
		break;
	case USER_LOGOUT://USERLOGOUT
		GetUserInfo(in, lUserLogInfo);
		UserLogOutInfo(lUserLogInfo);
		break;
	case USER_LOGON://USERLOGON
		GetUserInfo(in, lUserLogInfo);
		UserLogonInfo(lUserLogInfo);
		break;
	case USER_DISCONNECT:
		GetUserInfo(in, lUserLogInfo);
		break;
	case USER_UPDATEPWD://UPDATEPASS
		GetUserInfo(in, lUserLogInfo);
		UserModifyPass(lUserLogInfo);
		break;
	case USER_QUERY://QUERYUSER
		GetUserInfo(in, lUserLogInfo);
		UserQueryInfo(lUserLogInfo);
		break;
	default:
		return;
	}
}
void SqlCommand::UserAddInfo(USERINFO &userInfo)
{
	QString sSql;
	MANAGEINFO tmpInfo;
	USERLOGINFO userLogInfo;
	sSql = "SELECT name, sex, birthday, idcard, phone, "
		"status, power, password, online, logintime, lasttime,"
		"userID, email FROM tbl_user WHERE userID = '" + userInfo.sID + "'";
	if (!IsExist(sSql))
	{
		sSql = "INSERT INTO tbl_user(name, sex, birthday, idcard, "
			"phone, status, power, password, "
			"logintime, userID, email) VALUES('" + userInfo.sName + "','"
				+ QString("%1").arg(userInfo.dwSex) + "','"
				+ userInfo.sBirthDay + "','" + userInfo.sIDCard + "','"
				+ userInfo.sPhone + "','"
				+ QString("%1").arg(userInfo.dwStatus) + "','"
				+ QString("%1").arg(userInfo.dwPower) + "','" + userInfo.sPass
				+ "','" + userInfo.sLoginTime + "','" + userInfo.sID + "','"
				+ userInfo.sEmail + "')";
		userLogInfo.dwOperation = USER_ADD;
		userLogInfo.sIP = gUserLogInfo.sIP;
		userLogInfo.sOperator = gUserLogInfo.sOperator;
		userLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
		if (ExcuteSqlCmd(sSql))
		{
			userLogInfo.dwResult = SUCCESS;
			userLogInfo.sDescription = tr("Add user<<") + userInfo.sID + tr(
					">>successfully!");
		}
		else
		{
			userLogInfo.dwResult = FAILURE;
			userLogInfo.sDescription = tr("DB ERROR");
		}
	}
	else
	{
		userLogInfo.sDescription = tr("User<<") + userInfo.sID + tr(
				">>have exist");
	}
	ExcuteUserLogAdd(userLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = USER;
	tmpInfo.userLogInfo = userLogInfo;
	Information(tmpInfo);
}
void SqlCommand::UserDelInfo(USERINFO &userInfo)
{
	MANAGEINFO tmpInfo;
	USERLOGINFO lUserLogInfo;
	QString sSql;
	lUserLogInfo.dwOperation = USER_DELETE;
	lUserLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	lUserLogInfo.sIP = gUserLogInfo.sIP;
	lUserLogInfo.sOperator = gUserLogInfo.sOperator;
	sSql = "SELECT name, sex, birthday, idcard, phone, "
		"status, power, password, online, logintime, lasttime,"
		"userID, email FROM tbl_user WHERE userID = '" + userInfo.sID + "'";
	if (IsExist(sSql))
	{
		sSql = "DELETE FROM tbl_user where userID = '" + userInfo.sID + "'";
		if (ExcuteSqlCmd(sSql))
		{

			lUserLogInfo.dwResult = SUCCESS;
			lUserLogInfo.sDescription = tr("Delete user<<") + userInfo.sID
					+ tr(">>successfully!");

		}
		else
		{
			lUserLogInfo.dwResult = FAILURE;
			lUserLogInfo.sDescription = tr("DB ERROR");
		}
	}
	else
	{
		lUserLogInfo.dwResult = FAILURE;
		lUserLogInfo.sDescription = tr("Delete user<<") + userInfo.sID + tr(
				">>failed,No such user!");
	}
	ExcuteUserLogAdd(lUserLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = USER;
	tmpInfo.userLogInfo = lUserLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::UserUpdateInfo(USERINFO &userInfo)
{
	MANAGEINFO tmpInfo;
	USERLOGINFO lUserLogInfo;
	lUserLogInfo.dwOperation = USER_DELETE;
	lUserLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	lUserLogInfo.sIP = gUserLogInfo.sIP;
	lUserLogInfo.sOperator = gUserLogInfo.sOperator;
	QString sSql = "UPDATE tbl_user SET name='" + userInfo.sName + "', sex='"
			+ QString("%1").arg(userInfo.dwSex) + "', birthday='"
			+ userInfo.sBirthDay + "', idcard='" + userInfo.sIDCard
			+ "', phone='" + userInfo.sPhone + "', status='"
			+ QString("%1").arg(userInfo.dwStatus) + "', power='" + QString(
			"%1").arg(userInfo.dwPower) + "', password='" + userInfo.sPass
			+ "', email = '" + userInfo.sEmail + "'WHERE userID='"
			+ userInfo.sID + "'";
	if (ExcuteSqlCmd(sSql))
	{
		lUserLogInfo.dwResult = SUCCESS;
		lUserLogInfo.sDescription = tr("Update user<<") + userInfo.sID + tr(
				">>successfully!");
	}
	else
	{
		lUserLogInfo.dwResult = FAILURE;
		lUserLogInfo.sDescription = tr("DB ERROR");
	}
	ExcuteUserLogAdd(lUserLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = USER;
	tmpInfo.userLogInfo = lUserLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::UserListInfo(USERINFO &userInfo)
{
	MANAGEINFO tmpInfo;
	QString sSql = "SELECT name, sex, birthday, idcard, phone, "
		"status, power, password, online, logintime, lasttime,"
		"userID, email FROM tbl_user";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextUser(tmpInfo.userInfo))
		{
			tmpInfo.dwSubType = USER_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = USER;
	emit
	Information(tmpInfo);
}
void SqlCommand::UserQueryInfo(USERINFO &userInfo)
{
	MANAGEINFO tmpInfo;
	QString sSql = "SELECT name, sex, birthday, idcard, phone, "
		"status, power, password, online, logintime, lasttime,"
		"userID, email FROM tbl_user WHERE name like'%" + userInfo.sName
			+ "%' and userID like'%" + userInfo.sID + /* "'or power='"
	 + QString("%1").arg(userInfo.dwPower) + */"%'";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextUser(tmpInfo.userInfo))
		{
			tmpInfo.dwSubType = USER_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = USER;
	emit
	Information(tmpInfo);
}
void SqlCommand::UserResponse()
{
	MANAGEINFO tmpInfo;
	if (GetNextUser(tmpInfo.userInfo))
	{
		tmpInfo.dwSubType = USER_RESPONSE;
	}
	else
	{
		tmpInfo.dwSubType = SUCCESS;
	}
	tmpInfo.dwType = USER;
	emit
	Information(tmpInfo);
}

void SqlCommand::UserModifyPass(USERINFO &userInfo)
{
	QString sSql;
	USERLOGINFO lUserLogInfo;
	MANAGEINFO tmpInfo;
	lUserLogInfo.dwOperation = USER_UPDATEPWD;
	lUserLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	lUserLogInfo.sIP = gUserLogInfo.sIP;
	lUserLogInfo.sOperator = gUserLogInfo.sOperator;

	sSql = "UPDATE tbl_user SET password ='" + userInfo.sPass
			+ "' WHERE userID ='" + userInfo.sID + "'and power='" + QString(
			"%1").arg(userInfo.dwPower) + "'";
	if (ExcuteSqlCmd(sSql))
	{
		lUserLogInfo.dwResult = SUCCESS;
		lUserLogInfo.sDescription = tr("User<") + userInfo.sID + tr(
				">Update password successfully!");
	}
	else
	{
		lUserLogInfo.dwResult = FAILURE;
		lUserLogInfo.sDescription = tr("User<") + userInfo.sID + tr(
				">Update password failed, DB ERROR!");
	}

	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = USER_UPDATEPWD;
	tmpInfo.userLogInfo = lUserLogInfo;
	ExcuteUserLogAdd(lUserLogInfo);
	emit
	Information(tmpInfo);
}
void SqlCommand::UserExitInfo(USERINFO &userInfo)
{
	USERLOGINFO lUserLogInfo;
	QString sSql;
	lUserLogInfo.dwOperation = USER_EXIT;
	lUserLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	lUserLogInfo.sIP = gUserLogInfo.sIP;
	lUserLogInfo.sOperator = gUserLogInfo.sOperator;
	if (userInfo.sID.toInt(&ok) | userInfo.sPass.toInt(&ok)
			| userInfo.sLastTime.toInt(&ok))
	{
		sSql = "UPDATE tbl_user SET online = '0' WHERE userID ='"
				+ userInfo.sID + "'and power='" + QString("%1").arg(
				userInfo.dwPower) + "'";
		if (ExcuteSqlCmd(sSql))
		{
			lUserLogInfo.dwResult = SUCCESS;
			lUserLogInfo.sDescription = tr("User<") + userInfo.sID + tr(
					">Exit system");
		}
		else
		{
			lUserLogInfo.dwResult = FAILURE;
			lUserLogInfo.sDescription = tr("User<") + userInfo.sID + tr(
					">logOut DB ERROR");
		}
	}
	else
	{
		lUserLogInfo.dwResult = SUCCESS;
		lUserLogInfo.sDescription = tr("Exit system");
	}
	ExcuteUserLogAdd(lUserLogInfo);
	emit
	UserExitSystem();
}
void SqlCommand::UserLogOutInfo(USERINFO &userInfo)
{
	USERLOGINFO lUserLogInfo;
	QString sSql = "UPDATE tbl_user SET online = '0' WHERE userID ='"
			+ userInfo.sID + "'and power='" + QString("%1").arg(
			userInfo.dwPower) + "'";
	lUserLogInfo.dwOperation = USER_LOGOUT;
	lUserLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	lUserLogInfo.sIP = gUserLogInfo.sIP;
	lUserLogInfo.sOperator = gUserLogInfo.sOperator;
	if (ExcuteSqlCmd(sSql))
	{
		lUserLogInfo.dwResult = SUCCESS;
		lUserLogInfo.sDescription = tr("User<") + userInfo.sID + tr(
				">logOut successfully");
	}
	else
	{
		lUserLogInfo.dwResult = FAILURE;
		lUserLogInfo.sDescription = tr("User<") + userInfo.sID + tr(
				">logOut DB ERROR");
	}
	ExcuteUserLogAdd(lUserLogInfo);
}
void SqlCommand::UserLogonInfo(USERINFO &userInfo)
{
	MANAGEINFO tmpInfo;
	USERLOGINFO lUserLogInfo;
	QString sSql = "SELECT name, sex, birthday, idcard, phone, status, "
		"power, password, online, logintime, lasttime, userID FROM "
		"tbl_user WHERE userID ='" + userInfo.sID + "'and power='" + QString(
			"%1").arg(userInfo.dwPower) + "'and password='" + userInfo.sPass
			+ "'";
	lUserLogInfo.dwOperation = USER_LOGON;
	lUserLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	lUserLogInfo.sIP = gUserLogInfo.sIP;
	if (ExcuteSqlCmd(sSql))
	{

		if (GetNextUser(tmpInfo.userInfo))
		{
			if (tmpInfo.userInfo.dwOnline)
			{
				lUserLogInfo.dwResult = FAILURE;
				lUserLogInfo.sDescription = tr("User<") + userInfo.sID + tr(
						">have logon");
			}
			else
			{
				if (tmpInfo.userInfo.dwStatus == USER_STATUS_NORMAL)
				{
					sSql = "UPDATE tbl_user SET online = '1' ,lasttime = '"
							+ userInfo.sLastTime + "'WHERE userID ='"
							+ userInfo.sID + "'and power='"
							+ QString("%1").arg(userInfo.dwPower)
							+ "'and password='" + userInfo.sPass + "'";
					if (ExcuteSqlCmd(sSql))
					{
						gUserLogInfo.sOperator = tmpInfo.userInfo.sName;
						lUserLogInfo.sOperator = gUserLogInfo.sOperator;
						lUserLogInfo.dwResult = SUCCESS;
						lUserLogInfo.sDescription = tr("User<") + userInfo.sID
								+ tr(">logon successfully");
					}
					else
					{
						lUserLogInfo.dwResult = FAILURE;
						lUserLogInfo.sDescription = tr("User<") + userInfo.sID
								+ tr(">logon failed, DB error!");
					}
				}
				else
				{
					lUserLogInfo.dwResult = FAILURE;
					lUserLogInfo.sDescription = tr("User<") + userInfo.sID
							+ tr(">non-use!");
				}
			}
		}
		else
		{
			lUserLogInfo.dwResult = FAILURE;
			lUserLogInfo.sDescription
					= tr("UserID,password or power is wrong!");
		}
	}
	else
	{
		lUserLogInfo.dwResult = FAILURE;
		lUserLogInfo.sDescription = tr("DB ERROR");
	}
	ExcuteUserLogAdd(lUserLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = USER_LOGON;
	tmpInfo.userLogInfo = lUserLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::GetUserInfo(QDataStream &in, USERINFO &userInfo)
{
	in >> userInfo.sID;
	in >> userInfo.sName;
	in >> userInfo.dwSex;
	in >> userInfo.sBirthDay;
	in >> userInfo.sIDCard;
	in >> userInfo.sPhone;
	in >> userInfo.dwStatus;
	in >> userInfo.dwPower;
	in >> userInfo.sPass;
	in >> userInfo.dwOnline;
	in >> userInfo.sLoginTime;
	in >> userInfo.sLastTime;
	in >> userInfo.sEmail;
}
bool SqlCommand::GetNextUser(USERINFO &userInfo)
{
	if (sqlQuery.isSelect() && sqlQuery.next())
	{
		userInfo.sName = sqlQuery.value(0).toString();
		userInfo.dwSex = sqlQuery.value(1).toInt(&ok);
		userInfo.sBirthDay = sqlQuery.value(2).toString();
		userInfo.sIDCard = sqlQuery.value(3).toString();
		userInfo.sPhone = sqlQuery.value(4).toString();
		userInfo.dwStatus = sqlQuery.value(5).toInt(&ok);
		userInfo.dwPower = sqlQuery.value(6).toInt(&ok);
		userInfo.sPass = sqlQuery.value(7).toString();
		userInfo.dwOnline = sqlQuery.value(8).toInt(&ok);
		userInfo.sLoginTime = sqlQuery.value(9).toString();
		userInfo.sLastTime = sqlQuery.value(10).toString();
		userInfo.sID = sqlQuery.value(11).toString();
		userInfo.sEmail = sqlQuery.value(12).toString();
		return true;
	}
	else
	{
		sqlQuery.clear();
		return false;
	}
}
void SqlCommand::SendUserInfo(QDataStream &out, MANAGEINFO &sendInfo)
{
	USERINFO tmpInfo = sendInfo.userInfo;
	out << tmpInfo.sID;
	out << tmpInfo.sName;
	out << tmpInfo.dwSex;
	out << tmpInfo.sBirthDay;
	out << tmpInfo.sIDCard;
	out << tmpInfo.sPhone;
	out << tmpInfo.dwStatus;
	out << tmpInfo.dwPower;
	out << tmpInfo.sPass;
	out << tmpInfo.dwOnline;
	out << tmpInfo.sLoginTime;
	out << tmpInfo.sLastTime;
	out << tmpInfo.sEmail;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////LENDMANAGE///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void SqlCommand::RecvLendInfo(QDataStream &in, MANAGEINFO &recvInfo)
{
	LENDINFO lendInfo;
	switch (recvInfo.dwSubType)
	{
	case LEND_DELETE:///DELETE
		GetLendInfo(in, lendInfo);
		LendDelete(lendInfo);
		break;
	case LEND_LENDOUT://LENDOUT
		GetLendInfo(in, lendInfo);
		LendOutInfo(lendInfo);
		break;
	case LEND_LIST://LIST
		LendListInfo();
		break;
	case LEND_OVERDUE:
		break;
	case LEND_QUERY:
		GetLendInfo(in, lendInfo);
		LendQueryInfo(lendInfo);
		break;
	case LEND_RENEWAL://RENEWAL
		GetLendInfo(in, lendInfo);
		LendRenewal(lendInfo);
		break;
	case LEND_RESPONSE://RESPONSE
		LendResponse();
		break;
	case LEND_RETURN://RETURN
		GetLendInfo(in, lendInfo);
		LendReturn(lendInfo);
		break;
	case LEND_STATISTIC:
		break;
	default:
		return;
	}
}
void SqlCommand::LendQueryInfo(LENDINFO &lendInfo)
{
	MANAGEINFO tmpInfo;
	QString sSql;
	if (lendInfo.dwTimeOut)
	{
		sSql = "SELECT name, author, type, press, pressdate, pagenum,"
			"price, lenddate, lenddays, overdays, reader, timeout, bookID, readerID"
			" FROM tbl_lend WHERE reader like '%" + lendInfo.sReader
				+ "%' and name like'%" + lendInfo.sName
				+ "%' and timeout = '1'";
	}
	else
	{
		sSql = "SELECT name, author, type, press, pressdate, pagenum,"
			"price, lenddate, lenddays, overdays, reader, timeout, bookID, readerID"
			" FROM tbl_lend WHERE reader like '%" + lendInfo.sReader
				+ "%' and name like'%" + lendInfo.sName + "%'";
	}
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextLend(tmpInfo.lendInfo))
		{
			tmpInfo.dwSubType = LEND_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = LEND;
	emit
	Information(tmpInfo);
}
void SqlCommand::LendRenewal(LENDINFO &lendInfo)
{
	MANAGEINFO tmpInfo;
	BOOKLOGINFO bookLogInfo;
	QString sSql;
	bookLogInfo.sBookID = lendInfo.sID;
	bookLogInfo.sBookName = lendInfo.sName;
	bookLogInfo.dwOperation = LEND_RENEWAL;
	bookLogInfo.sType = lendInfo.sType;
	bookLogInfo.sIP = gUserLogInfo.sIP;
	bookLogInfo.sOperator = gUserLogInfo.sOperator;
	bookLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	sSql = "SELECT name, author, type, press, pressdate, pagenum,"
		"price, lenddate, lenddays, overdays, reader, timeout, bookID, readerID"
		" FROM tbl_lend WHERE bookID = '" + lendInfo.sID + "'";
	if (IsExist(sSql))
	{
		sSql = "UPDATE tbl_lend SET timeout='" + QString("%1").arg(
				LEND_NOTOVERDUE) + "', overdays ='0', lenddays = '" + QString(
				"%1").arg(lendInfo.dwLendDays) + "'WHERE bookID='"
				+ lendInfo.sID + "'";
		if (ExcuteSqlCmd(sSql))
		{
			bookLogInfo.dwResult = SUCCESS;
			bookLogInfo.sDescription = tr("Renewal<<") + lendInfo.sName + tr(
					">>successfully!");
		}
		else
		{
			bookLogInfo.dwResult = FAILURE;
			bookLogInfo.sDescription = tr("DB ERROR");
		}
	}
	else
	{
		bookLogInfo.dwResult = FAILURE;
		bookLogInfo.sDescription = tr("Renewal<<") + lendInfo.sName + tr(
				">>failed,No such book!");
	}
	ExcuteBookLogAdd(bookLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = LEND;
	tmpInfo.bookLogInfo = bookLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::LendReturn(LENDINFO &lendInfo)
{
	MANAGEINFO tmpInfo;
	BOOKLOGINFO bookLogInfo;
	QString sSql;
	bookLogInfo.sBookID = lendInfo.sID;
	bookLogInfo.sBookName = lendInfo.sName;
	bookLogInfo.dwOperation = LEND_RETURN;
	bookLogInfo.sType = lendInfo.sType;
	bookLogInfo.sIP = gUserLogInfo.sIP;
	bookLogInfo.sOperator = gUserLogInfo.sOperator;
	bookLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	sSql = "SELECT name, author, type, press, pressdate, pagenum,"
		"price, lenddate, lenddays, overdays, reader, timeout, bookID, readerID"
		" FROM tbl_lend WHERE bookID = '" + lendInfo.sID + "'";
	if (IsExist(sSql))
	{
		sSql = "DELETE FROM tbl_lend where bookID = '" + lendInfo.sID + "'";
		if (ExcuteSqlCmd(sSql))
		{
			sSql = "UPDATE tbl_book SET status='" + QString("%1").arg(
					BOOK_STATUS_NOTLEND) + "'WHERE bookID='" + lendInfo.sID
					+ "'";
			if (ExcuteSqlCmd(sSql))
			{
				bookLogInfo.dwResult = SUCCESS;
				bookLogInfo.sDescription = tr("Rerurn lend<<") + lendInfo.sName
						+ tr(">>successfully!");
			}
			else
			{
				bookLogInfo.dwResult = FAILURE;
				bookLogInfo.sDescription = tr("DB ERROR");
			}

		}
		else
		{
			bookLogInfo.dwResult = FAILURE;
			bookLogInfo.sDescription = tr("DB ERROR");
		}
	}
	else
	{
		bookLogInfo.dwResult = FAILURE;
		bookLogInfo.sDescription = tr("Return lend<<") + lendInfo.sName + tr(
				">>failed,No such book!");
	}
	ExcuteBookLogAdd(bookLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = LEND;
	tmpInfo.bookLogInfo = bookLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::LendDelete(LENDINFO &lendInfo)
{
	MANAGEINFO tmpInfo;
	BOOKLOGINFO bookLogInfo;
	QString sSql;
	bookLogInfo.sBookID = lendInfo.sID;
	bookLogInfo.sBookName = lendInfo.sName;
	bookLogInfo.dwOperation = LEND_DELETE;
	bookLogInfo.sType = lendInfo.sType;
	bookLogInfo.sIP = gUserLogInfo.sIP;
	bookLogInfo.sOperator = gUserLogInfo.sOperator;
	bookLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	sSql = "SELECT name, author, type, press, pressdate, pagenum,"
		"price, lenddate, lenddays, overdays, reader, timeout, bookID, readerID"
		" FROM tbl_lend WHERE bookID = '" + lendInfo.sID + "'";
	if (IsExist(sSql))
	{
		sSql = "DELETE FROM tbl_lend where bookID = '" + lendInfo.sID + "'";
		if (ExcuteSqlCmd(sSql))
		{

			bookLogInfo.dwResult = SUCCESS;
			bookLogInfo.sDescription = tr("Delete lend<<") + lendInfo.sName
					+ tr(">>successfully!");

		}
		else
		{
			bookLogInfo.dwResult = FAILURE;
			bookLogInfo.sDescription = tr("DB ERROR");
		}
	}
	else
	{
		bookLogInfo.dwResult = FAILURE;
		bookLogInfo.sDescription = tr("Delete lend<<") + lendInfo.sName + tr(
				">>failed,No such book!");
	}
	ExcuteBookLogAdd(bookLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = LEND;
	tmpInfo.bookLogInfo = bookLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::LendListInfo()
{
	MANAGEINFO tmpInfo;
	QString sSql = "SELECT name, author, type, press, pressdate, pagenum,"
		"price, lenddate, lenddays, overdays, reader, timeout, bookID, readerID"
		" FROM tbl_lend";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextLend(tmpInfo.lendInfo))
		{
			tmpInfo.dwSubType = LEND_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = LEND;
	emit
	Information(tmpInfo);
}
void SqlCommand::LendOutInfo(LENDINFO &lendInfo)
{
	MANAGEINFO tmpInfo;
	BOOKLOGINFO bookLogInfo;
	QString sSql;
	bookLogInfo.sBookID = lendInfo.sID;
	bookLogInfo.sBookName = lendInfo.sName;
	bookLogInfo.dwOperation = LEND_LENDOUT;
	bookLogInfo.sType = lendInfo.sType;
	bookLogInfo.sIP = gUserLogInfo.sIP;
	bookLogInfo.sOperator = gUserLogInfo.sOperator;
	bookLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	sSql = "SELECT name, author, type, press, "
		"pressdate, pagenum, price, adddate, lendtimes, "
		"status, bookID FROM tbl_book WHERE bookID='" + lendInfo.sID + "'";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextBook(tmpInfo.bookInfo))
		{
			if (tmpInfo.bookInfo.dwStatus == BOOK_STATUS_NOTLEND)
			{
				int lendTimes = tmpInfo.bookInfo.dwLendTimes;
				lendTimes++;
				sSql = "UPDATE tbl_book SET status='" + QString("%1").arg(
						BOOK_STATUS_LEND) + "',lendtimes='"
						+ QString("%1").arg(lendTimes) + "'WHERE bookID='"
						+ lendInfo.sID + "'";
				if (ExcuteSqlCmd(sSql))
				{
					sSql
							= "INSERT INTO tbl_lend(name, author, type, press, pressdate"
								",pagenum, price, lenddate, lenddays, overdays, reader, "
								"timeout, bookID, readerID)VALUES('"
									+ lendInfo.sName + "','" + lendInfo.sAuthor
									+ "','" + lendInfo.sType + "','"
									+ lendInfo.sPress + "','"
									+ lendInfo.sPressDate + "','" + QString(
									"%1").arg(lendInfo.dwPageNum) + "','"
									+ QString("%1").arg(lendInfo.fPrice)
									+ "','" + lendInfo.sLendDate + "','"
									+ QString("%1").arg(lendInfo.dwLendDays)
									+ "','" + QString("%1").arg(
									lendInfo.dwOverDays) + "','"
									+ lendInfo.sReader + "','"
									+ QString("%1").arg(lendInfo.dwTimeOut)
									+ "','" + lendInfo.sID + "','"
									+ lendInfo.sReaderID + "')";
					if (ExcuteSqlCmd(sSql))
					{
						bookLogInfo.dwResult = SUCCESS;
						bookLogInfo.sDescription = tr("Lend book<<")
								+ lendInfo.sName + tr(">>successfully!");
					}
					else
					{
						bookLogInfo.dwResult = FAILURE;
						bookLogInfo.sDescription = tr("DB ERROR");
					}
				}
				else
				{
					bookLogInfo.dwResult = FAILURE;
					bookLogInfo.sDescription = tr("DB ERROR");
				}

			}
			else if (tmpInfo.bookInfo.dwStatus == BOOK_STATUS_LEND)
			{
				bookLogInfo.dwResult = FAILURE;
				bookLogInfo.sDescription = tr("Book<<") + lendInfo.sName + tr(
						">>had lend out!");
			}
			else
			{
				bookLogInfo.dwResult = FAILURE;
				bookLogInfo.sDescription = tr("Book<<") + lendInfo.sName + tr(
						">>had lost!");
			}
		}
		else
		{
			bookLogInfo.dwResult = FAILURE;
			bookLogInfo.sDescription = tr("No such book");
		}
	}
	else
	{
		bookLogInfo.dwResult = FAILURE;
		bookLogInfo.sDescription = tr("DB ERROR");
	}
	ExcuteBookLogAdd(bookLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = BOOK;
	tmpInfo.bookLogInfo = bookLogInfo;
	emit
	Information(tmpInfo);
}
void SqlCommand::LendResponse()
{

	MANAGEINFO tmpInfo;
	if (GetNextLend(tmpInfo.lendInfo))
	{
		tmpInfo.dwSubType = LEND_RESPONSE;
	}
	else
	{
		tmpInfo.dwSubType = SUCCESS;
	}
	tmpInfo.dwType = LEND;
	emit
	Information(tmpInfo);

}
bool SqlCommand::GetNextLend(LENDINFO &tmpLend)
{
	if (sqlQuery.isSelect() && sqlQuery.next())
	{
		tmpLend.sName = sqlQuery.value(0).toString();
		tmpLend.sAuthor = sqlQuery.value(1).toString();
		tmpLend.sType = sqlQuery.value(2).toString();
		tmpLend.sPress = sqlQuery.value(3).toString();
		tmpLend.sPressDate = sqlQuery.value(4).toString();
		tmpLend.dwPageNum = sqlQuery.value(5).toInt(&ok);
		tmpLend.fPrice = sqlQuery.value(6).toDouble(&ok);
		tmpLend.sLendDate = sqlQuery.value(7).toString();
		tmpLend.dwLendDays = sqlQuery.value(8).toInt(&ok);
		tmpLend.dwOverDays = sqlQuery.value(9).toInt(&ok);
		tmpLend.sReader = sqlQuery.value(10).toString();
		tmpLend.dwTimeOut = sqlQuery.value(11).toInt(&ok);
		tmpLend.sID = sqlQuery.value(12).toString();
		tmpLend.sReaderID = sqlQuery.value(13).toString();
		return true;
	}
	else
	{
		sqlQuery.clear();
		return false;
	}
}
void SqlCommand::GetLendInfo(QDataStream &in, LENDINFO &lendInfo)
{
	in >> lendInfo.sID;
	in >> lendInfo.sName;
	in >> lendInfo.sAuthor;
	in >> lendInfo.sType;
	in >> lendInfo.sPress;
	in >> lendInfo.sPressDate;
	in >> lendInfo.dwPageNum;
	in >> lendInfo.fPrice;
	in >> lendInfo.sLendDate;
	in >> lendInfo.dwLendDays;
	in >> lendInfo.dwOverDays;
	in >> lendInfo.sReaderID;
	in >> lendInfo.sReader;
	in >> lendInfo.dwTimeOut;
}
void SqlCommand::SendLendInfo(QDataStream &out, MANAGEINFO &sendInfo)
{
	LENDINFO tmpInfo = sendInfo.lendInfo;
	out << tmpInfo.sID;
	out << tmpInfo.sName;
	out << tmpInfo.sAuthor;
	out << tmpInfo.sType;
	out << tmpInfo.sPress;
	out << tmpInfo.sPressDate;
	out << tmpInfo.dwPageNum;
	out << tmpInfo.fPrice;
	out << tmpInfo.sLendDate;
	out << tmpInfo.dwLendDays;
	out << tmpInfo.dwOverDays;
	out << tmpInfo.sReaderID;
	out << tmpInfo.sReader;
	out << tmpInfo.dwTimeOut;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////READERMANAGE////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void SqlCommand::RecvReaderInfo(QDataStream &in, MANAGEINFO &recvInfo)
{

}
void SqlCommand::GetReaderInfo(QDataStream &in, READERINFO &readerInfo)
{
	in >> readerInfo.sID;
	in >> readerInfo.sName;
	in >> readerInfo.dwSex;
	in >> readerInfo.sBirthDay;
	in >> readerInfo.sCardDate;
	in >> readerInfo.sCardNum;
	in >> readerInfo.dwType;
	in >> readerInfo.dwStatus;
	in >> readerInfo.sSchool;
	in >> readerInfo.sDepartment;
	in >> readerInfo.dwGrade;
	in >> readerInfo.sIDCard;
	in >> readerInfo.sAddress;
	in >> readerInfo.sPost;
	in >> readerInfo.sPhone;
	in >> readerInfo.sEmail;
}
void SqlCommand::SendReaderInfo(QDataStream &out, MANAGEINFO &sendInfo)
{
	READERINFO tmpInfo = sendInfo.readerInfo;
	out << tmpInfo.sID;
	out << tmpInfo.sName;
	out << tmpInfo.dwSex;
	out << tmpInfo.sBirthDay;
	out << tmpInfo.sCardDate;
	out << tmpInfo.sCardNum;
	out << tmpInfo.dwType;
	out << tmpInfo.dwStatus;
	out << tmpInfo.sSchool;
	out << tmpInfo.sDepartment;
	out << tmpInfo.dwGrade;
	out << tmpInfo.sIDCard;
	out << tmpInfo.sAddress;
	out << tmpInfo.sPost;
	out << tmpInfo.sPhone;
	out << tmpInfo.sEmail;
}
////////////////////////////////////////////////////////////////////////
/////////////////////////////USERLOGMANAGE//////////////////////////////
////////////////////////////////////////////////////////////////////////
void SqlCommand::RecvBookLogInfo(QDataStream &in, MANAGEINFO &recvInfo)
{
	BOOKLOGINFO lBookLogInfo;
	switch (recvInfo.dwSubType)
	{
	case BOOKLOG_LIST:
		BookLogListInfo();
		break;
	case BOOKLOG_DELETE:
		GetBookLogInfo(in, lBookLogInfo);
		BookLogDelInfo(lBookLogInfo);
		break;
	case BOOKLOG_RESPONSE:
		BookLogResponse();
		break;
	}
}
void SqlCommand::BookLogListInfo()
{
	MANAGEINFO tmpInfo;
	QString sSql = "SELECT result, bookID, bookname, operation, "
		"ip, type, description, datetime, operator, id FROM tbl_booklog";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextBookLog(tmpInfo.bookLogInfo))
		{
			tmpInfo.dwSubType = BOOKLOG_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = BOOKLOG;
	emit
	Information(tmpInfo);
}
void SqlCommand::BookLogResponse()
{
	MANAGEINFO tmpInfo;
	if (GetNextBookLog(tmpInfo.bookLogInfo))
	{
		tmpInfo.dwSubType = BOOK_RESPONSE;
	}
	else
	{
		tmpInfo.dwSubType = SUCCESS;
	}
	tmpInfo.dwType = BOOKLOG;
	emit
	Information(tmpInfo);
}

void SqlCommand::BookLogDelInfo(BOOKLOGINFO &resultInfo)
{
	MANAGEINFO tmpInfo;
	USERLOGINFO lUserLogInfo;
	QString sSql = "DELETE FROM tbl_booklog";
	lUserLogInfo.dwOperation = BOOKLOG_DELETE;
	lUserLogInfo.sDateTime = dateTime.currentDateTime().toString(DATETIME);
	lUserLogInfo.sIP = gUserLogInfo.sIP;
	lUserLogInfo.sOperator = gUserLogInfo.sOperator;
	if (ExcuteSqlCmd(sSql))
	{
		lUserLogInfo.sDescription = tr("Delete all book log successfully!");
		lUserLogInfo.dwResult = SUCCESS;
		resultInfo.sDescription = tr("Delete all book log successfully!");
		resultInfo.dwResult = SUCCESS;
	}
	else
	{
		lUserLogInfo.sDescription = tr("Delete book log failed,DB ERROR");
		lUserLogInfo.dwResult = FAILURE;
		resultInfo.sDescription = tr("DB ERROR");
		resultInfo.dwResult = FAILURE;
	}
	ExcuteUserLogAdd(lUserLogInfo);
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = BOOKLOG;
	tmpInfo.bookLogInfo = resultInfo;
	emit
	Information(tmpInfo);
}
bool SqlCommand::GetNextBookLog(BOOKLOGINFO &tmpBookLog)
{
	if (sqlQuery.isSelect() && sqlQuery.next())
	{
		tmpBookLog.dwResult = sqlQuery.value(0).toInt(&ok);
		tmpBookLog.sBookID = sqlQuery.value(1).toString();
		tmpBookLog.sBookName = sqlQuery.value(2).toString();
		tmpBookLog.dwOperation = sqlQuery.value(3).toInt(&ok);
		tmpBookLog.sIP = sqlQuery.value(4).toString();
		tmpBookLog.sType = sqlQuery.value(5).toString();
		tmpBookLog.sDescription = sqlQuery.value(6).toString();
		tmpBookLog.sDateTime = sqlQuery.value(7).toString();
		tmpBookLog.sOperator = sqlQuery.value(8).toString();
		tmpBookLog.dwID = sqlQuery.value(9).toInt(&ok);
		return true;
	}
	else
	{
		sqlQuery.clear();
		return false;
	}
}
void SqlCommand::GetBookLogInfo(QDataStream &in, BOOKLOGINFO &bookLogInfo)
{
	in >> bookLogInfo.dwResult;
	in >> bookLogInfo.sBookID;
	in >> bookLogInfo.sBookName;
	in >> bookLogInfo.dwOperation;
	in >> bookLogInfo.sIP;
	in >> bookLogInfo.sType;
	in >> bookLogInfo.sDescription;
	in >> bookLogInfo.sDateTime;
	in >> bookLogInfo.sOperator;
}
void SqlCommand::SendBookLogInfo(QDataStream &out, MANAGEINFO &sendInfo)
{
	BOOKLOGINFO tmpInfo = sendInfo.bookLogInfo;
	out << tmpInfo.dwResult;
	out << tmpInfo.sBookID;
	out << tmpInfo.sBookName;
	out << tmpInfo.dwOperation;
	out << tmpInfo.sIP;
	out << tmpInfo.sType;
	out << tmpInfo.sDescription;
	out << tmpInfo.sDateTime;
	out << tmpInfo.sOperator;

}
/////////////////////////////////////////////////////////////////////
////////////////////////USERLOGMANAGE////////////////////////////////
/////////////////////////////////////////////////////////////////////
void SqlCommand::RecvUserLogInfo(QDataStream &in, MANAGEINFO &recvInfo)
{
	USERLOGINFO lUserLogInfo;
	switch (recvInfo.dwSubType)
	{
	case USERLOG_LIST:
		UserLogListInfo();
		break;
	case USERLOG_DELETE:
		GetUserLogInfo(in, lUserLogInfo);
		UserLogDelInfo(lUserLogInfo);
		break;
	case USERLOG_RESPONSE:
		UserLogResponse();
		break;
	}
}
void SqlCommand::UserLogListInfo()
{
	MANAGEINFO tmpInfo;
	QString sSql = "SELECT operator, ip, result, description, datetime,"
		"operation FROM tbl_userlog";
	if (ExcuteSqlCmd(sSql))
	{
		if (GetNextUserLog(tmpInfo.userLogInfo))
		{
			tmpInfo.dwSubType = USERLOG_RESPONSE;
		}
		else
		{
			tmpInfo.dwSubType = SUCCESS;
		}
	}
	tmpInfo.dwType = USERLOG;
	emit
	Information(tmpInfo);
}
void SqlCommand::UserLogDelInfo(USERLOGINFO &resultInfo)
{
	MANAGEINFO tmpInfo;
	QString sSql = "DELETE FROM tbl_userlog";
	if (ExcuteSqlCmd(sSql))
	{
		resultInfo.dwResult = SUCCESS;
		resultInfo.sDescription = tr("Delete all user log successfully!");
	}
	else
	{
		resultInfo.dwResult = FAILURE;
		resultInfo.sDescription = tr("DB ERROR");
	}
	tmpInfo.dwType = RESULT;
	tmpInfo.dwSubType = USERLOG;
	tmpInfo.userLogInfo = resultInfo;
	emit
	Information(tmpInfo);
}
bool SqlCommand::GetNextUserLog(USERLOGINFO &tmpUserLog)
{
	if (sqlQuery.isSelect() && sqlQuery.next())
	{
		tmpUserLog.sOperator = sqlQuery.value(0).toString();
		tmpUserLog.sIP = sqlQuery.value(1).toString();
		tmpUserLog.dwResult = sqlQuery.value(2).toInt(&ok);
		tmpUserLog.sDescription = sqlQuery.value(3).toString();
		tmpUserLog.sDateTime = sqlQuery.value(4).toString();
		tmpUserLog.dwOperation = sqlQuery.value(5).toInt(&ok);
		return true;
	}
	else
	{
		sqlQuery.clear();
		return false;
	}
}
void SqlCommand::UserLogResponse()
{
	MANAGEINFO tmpInfo;
	if (GetNextUserLog(tmpInfo.userLogInfo))
	{
		tmpInfo.dwSubType = USERLOG_RESPONSE;
	}
	else
	{
		tmpInfo.dwSubType = SUCCESS;
	}
	tmpInfo.dwType = USERLOG;
	emit
	Information(tmpInfo);
}
void SqlCommand::GetUserLogInfo(QDataStream &in, USERLOGINFO &userLogInfo)
{
	in >> userLogInfo.sOperator;
	in >> userLogInfo.sIP;
	in >> userLogInfo.dwResult;
	in >> userLogInfo.sDescription;
	in >> userLogInfo.sDateTime;
	in >> userLogInfo.dwOperation;
}
void SqlCommand::SendUserLogInfo(QDataStream &out, MANAGEINFO &sendInfo)
{
	USERLOGINFO tmpInfo = sendInfo.userLogInfo;
	out << tmpInfo.sOperator;
	out << tmpInfo.sIP;
	out << tmpInfo.dwResult;
	out << tmpInfo.sDescription;
	out << tmpInfo.sDateTime;
	out << tmpInfo.dwOperation;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////BASE////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void SqlCommand::GetPeerIP(const QString &sIp)
{
	//this->cmd = cmd;
	gUserLogInfo.sIP = sIp;
	gUserLogInfo.sOperator = tr("Anonymous");
}
bool SqlCommand::ExcuteSqlCmd(QString sSql)
{
	if (sqlQuery.exec(sSql))
	{
		return true;
	}
	else
	{
		sqlQuery.clear();
		return false;
	}
	//qDebug() << sSql;
}
void SqlCommand::ExcuteBookLogAdd(BOOKLOGINFO &bookLogInfo)
{
	QString sSql =
			"INSERT INTO tbl_booklog(bookID, result, bookname, operation,"
				"ip, type, description, datetime, operator)VALUES('"
					+ bookLogInfo.sBookID + "','" + QString("%1").arg(
					bookLogInfo.dwResult) + "','" + bookLogInfo.sBookName
					+ "','" + QString("%1").arg(bookLogInfo.dwOperation)
					+ "','" + bookLogInfo.sIP + "','" + bookLogInfo.sType
					+ "','" + bookLogInfo.sDescription + "','"
					+ bookLogInfo.sDateTime + "','" + bookLogInfo.sOperator
					+ "')";
	if (ExcuteSqlCmd(sSql))
	{
		//qDebug() << sSql;
	}
	else
	{
	}
}
void SqlCommand::ExcuteUserLogAdd(USERLOGINFO &userLogInfo)
{
	QString sSql = "INSERT INTO tbl_userlog(operator, ip, result, "
		"description, datetime, operation)VALUES('" + userLogInfo.sOperator
			+ "','" + userLogInfo.sIP + "','" + QString("%1").arg(
			userLogInfo.dwResult) + "','" + userLogInfo.sDescription + "','"
			+ userLogInfo.sDateTime + "','" + QString("%1").arg(
			userLogInfo.dwOperation) + "')";
	if (ExcuteSqlCmd(sSql))
	{
		//qDebug() << sSql;
	}
	else
	{
		//qDebug() << "ExcuteBookLogAdd error";
	}
}
bool SqlCommand::IsExist(QString sSql)
{
	ExcuteSqlCmd(sSql);
	int rows = sqlQuery.size();
	if (rows != 0 && rows > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
 * SendMessage.cpp
 *
 *  Created on: 2009-9-15
 *      Author: Administrator
 */

#include "SendMessage.h"
SendMsg::SendMsg()
{
	// TODO Auto-generated constructor stub
}

SendMsg::~SendMsg()
{
	// TODO Auto-generated destructor stub
}
void SendMsg::SetManageInfo(const MANAGEINFO &manageInfo)
{
	this->manageInfo = manageInfo;
}
BOOKINFO SendMsg::GetBookInfo() const
{
	return manageInfo.bookInfo;
}
USERINFO SendMsg::GetUserInfo() const
{
	return manageInfo.userInfo;
}
LENDINFO SendMsg::GetLendInfo() const
{
	return manageInfo.lendInfo;
}
READERINFO SendMsg::GetReaderInfo() const
{
	return manageInfo.readerInfo;
}
BOOKLOGINFO SendMsg::GetBookLogInfo() const
{
	return manageInfo.bookLogInfo;
}
USERLOGINFO SendMsg::GetUserLogInfo() const
{
	return manageInfo.userLogInfo;
}
u32 SendMsg::GetOptionType() const
{
	return manageInfo.dwType;
}
u32 SendMsg::GetSubOptionType() const
{
	return manageInfo.dwSubType;
}
void SendMsg::SendBookInfo(QDataStream &out)
{
	out << GetBookInfo().sID;
	out << GetBookInfo().sName;
	out << GetBookInfo().sAuthor;
	out << GetBookInfo().sType;
	out << GetBookInfo().sPress;
	out << GetBookInfo().sPressDate;
	out << GetBookInfo().dwPageNum;
	out << GetBookInfo().fPrice;
	out << GetBookInfo().sAddDate;
	out << GetBookInfo().dwLendTimes;
	out << GetBookInfo().dwStatus;
}
void SendMsg::SendUserInfo(QDataStream &out)
{
	out << GetUserInfo().sID;
	out << GetUserInfo().sName;
	out << GetUserInfo().dwSex;
	out << GetUserInfo().sBirthDay;
	out << GetUserInfo().sIDCard;
	out << GetUserInfo().sPhone;
	out << GetUserInfo().dwStatus;
	out << GetUserInfo().dwPower;
	out << GetUserInfo().sPass;
	out << GetUserInfo().dwOnline;
	out << GetUserInfo().sLoginTime;
	out << GetUserInfo().sLastTime;
	out << GetUserInfo().sEmail;
}
void SendMsg::SendLendInfo(QDataStream &out)
{
	out << GetLendInfo().sID;
	out << GetLendInfo().sName;
	out << GetLendInfo().sAuthor;
	out << GetLendInfo().sType;
	out << GetLendInfo().sPress;
	out << GetLendInfo().sPressDate;
	out << GetLendInfo().dwPageNum;
	out << GetLendInfo().fPrice;
	out << GetLendInfo().sLendDate;
	out << GetLendInfo().dwLendDays;
	out << GetLendInfo().dwOverDays;
	out << GetLendInfo().sReaderID;
	out << GetLendInfo().sReader;
	out << GetLendInfo().dwTimeOut;
}
void SendMsg::SendReaderInfo(QDataStream &out)
{
	out << GetReaderInfo().sID;
	out << GetReaderInfo().sName;
	out << GetReaderInfo().dwSex;
	out << GetReaderInfo().sBirthDay;
	out << GetReaderInfo().sCardDate;
	out << GetReaderInfo().sCardNum;
	out << GetReaderInfo().dwType;
	out << GetReaderInfo().dwStatus;
	out << GetReaderInfo().sSchool;
	out << GetReaderInfo().sDepartment;
	out << GetReaderInfo().dwGrade;
	out << GetReaderInfo().sIDCard;
	out << GetReaderInfo().sAddress;
	out << GetReaderInfo().sPost;
	out << GetReaderInfo().sPhone;
	out << GetReaderInfo().sEmail;
}
void SendMsg::SendBookLogInfo(QDataStream &out)
{
	out << GetBookLogInfo().dwResult;
	out << GetBookLogInfo().sBookID;
	out << GetBookLogInfo().sBookName;
	out << GetBookLogInfo().dwOperation;
	out << GetBookLogInfo().sIP;
	out << GetBookLogInfo().sType;
	out << GetBookLogInfo().sDescription;
	out << GetBookLogInfo().sDateTime;
	out << GetBookLogInfo().sOperator;

}
void SendMsg::SendUserLogInfo(QDataStream &out)
{
	out << GetUserLogInfo().sOperator;
	out << GetUserLogInfo().sIP;
	out << GetUserLogInfo().dwResult;
	out << GetUserLogInfo().sDescription;
	out << GetUserLogInfo().sDateTime;
	out << GetUserLogInfo().dwOperation;
}
//////////////////////RECEIVE/////////////////////////////////
void SendMsg::RecvBookInfo(QDataStream &in, BOOKINFO &bookInfo)
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
void SendMsg::RecvUserInfo(QDataStream &in, USERINFO &userInfo)
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
void SendMsg::RecvLendInfo(QDataStream &in, LENDINFO &lendInfo)
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
void SendMsg::RecvReaderInfo(QDataStream &in, READERINFO &readerInfo)
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
void SendMsg::RecvBookLogInfo(QDataStream &in, BOOKLOGINFO &bookLogInfo)
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
void SendMsg::RecvUserLogInfo(QDataStream &in, USERLOGINFO &userLogInfo)
{
	in >> userLogInfo.sOperator;
	in >> userLogInfo.sIP;
	in >> userLogInfo.dwResult;
	in >> userLogInfo.sDescription;
	in >> userLogInfo.sDateTime;
	in >> userLogInfo.dwOperation;
}
///////////////////////////SendConnectionMsg//////////////////////////
bool SendMsg::DataSend(QTcpSocket *tcpsocket)
{
	int length = 0;
	QByteArray datagram;
	QDataStream out(&datagram, QIODevice::WriteOnly);
	out << GetOptionType();
	out << GetSubOptionType();
	switch (GetOptionType())
	{
	case BOOK:
		SendBookInfo(out);
		break;
	case USER:
		SendUserInfo(out);
		break;
	case LEND:
		SendLendInfo(out);
		break;
	case READER:
		SendReaderInfo(out);
		break;
	case BOOKLOG:
		SendBookLogInfo(out);
		break;
	case USERLOG:
		SendUserLogInfo(out);
		break;
	default:
		return false;
	}
	if ((length = tcpsocket->write(datagram)) != datagram.length())
	{
		return false;
	}
	else
		return true;
}

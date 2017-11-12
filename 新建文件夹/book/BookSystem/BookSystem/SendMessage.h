/*
 * SendMessage.h
 *
 *  Created on: 2009-9-15
 *      Author: Administrator
 */

#ifndef SENDMESSAGE_H_
#define SENDMESSAGE_H_
#include <QtNetwork>
#include <QByteArray>
#include "GlobalDefine.h"
class SendMsg
{
public:
	SendMsg();
	virtual ~SendMsg();
	bool DataSend(QTcpSocket *);//·¢ËÍÊý¾Ý
	void SetManageInfo(const MANAGEINFO &);
	void RecvBookInfo(QDataStream &, BOOKINFO &);
	void RecvUserInfo(QDataStream &, USERINFO &);
	void RecvLendInfo(QDataStream &, LENDINFO &);
	void RecvReaderInfo(QDataStream &, READERINFO &);
	void RecvBookLogInfo(QDataStream &, BOOKLOGINFO &);
	void RecvUserLogInfo(QDataStream &, USERLOGINFO &);
private:
	MANAGEINFO manageInfo;
	BOOKINFO GetBookInfo() const;
	USERINFO GetUserInfo() const;
	LENDINFO GetLendInfo() const;
	READERINFO GetReaderInfo() const;
	BOOKLOGINFO GetBookLogInfo() const;
	USERLOGINFO GetUserLogInfo() const;
	u32 GetOptionType()const;
	u32 GetSubOptionType()const;

	void SendBookInfo(QDataStream &);
	void SendUserInfo(QDataStream &);
	void SendLendInfo(QDataStream &);
	void SendReaderInfo(QDataStream &);
	void SendBookLogInfo(QDataStream &);
	void SendUserLogInfo(QDataStream &);
};
#endif /* SENDMESSAGE_H_ */

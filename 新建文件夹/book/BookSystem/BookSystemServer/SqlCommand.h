/*
 * SqlCommand.h
 *
 *  Created on: 2009-8-24
 *      Author: Administrator
 */

#ifndef SQLCOMMAND_H_
#define SQLCOMMAND_H_
#include <QtSql>
#include <QtNetwork>
#include <QDateTime>
#include "GlobalDefine.h"
#include <QMetaType>
class SqlCommand: public QObject
{
Q_OBJECT
public:
	SqlCommand(QObject *parent = 0);
	virtual ~SqlCommand();
	void GetPeerIP(const QString &);
	void SendBookInfo(QDataStream &, MANAGEINFO &);
	void SendUserInfo(QDataStream &, MANAGEINFO &);
	void SendLendInfo(QDataStream &, MANAGEINFO &);
	void SendReaderInfo(QDataStream &, MANAGEINFO &);
	void SendBookLogInfo(QDataStream &, MANAGEINFO &);
	void SendUserLogInfo(QDataStream &, MANAGEINFO &);

	void RecvBookInfo(QDataStream &, MANAGEINFO &);
	void RecvUserInfo(QDataStream &, MANAGEINFO &);
	void RecvLendInfo(QDataStream &, MANAGEINFO &);
	void RecvReaderInfo(QDataStream &, MANAGEINFO &);
	void RecvBookLogInfo(QDataStream &, MANAGEINFO &);
	void RecvUserLogInfo(QDataStream &, MANAGEINFO &);
private:
	void GetBookInfo(QDataStream &, BOOKINFO &);
	void GetUserInfo(QDataStream &, USERINFO &);
	void GetLendInfo(QDataStream &, LENDINFO &);
	void GetReaderInfo(QDataStream &, READERINFO &);
	void GetBookLogInfo(QDataStream &, BOOKLOGINFO &);
	void GetUserLogInfo(QDataStream &, USERLOGINFO &);
	///////////////////BOOKMANAGE///////////////////////
	void BookAddInfo(BOOKINFO &);
	void BookDelInfo(BOOKINFO &);
	void BookUpdateInfo(BOOKINFO &);
	void BookQueryInfo(BOOKINFO &);
	void BookListInfo(BOOKINFO &);
	//void BookLendOutInfo(BOOKINFO &);
	void BookResponse();
	bool GetNextBook(BOOKINFO &);//�����һ������Ϣ
	///////////////////BOOKLOGMANAGE////////////////////////
	void BookLogListInfo();
	void BookLogResponse();
	void BookLogDelInfo(BOOKLOGINFO &);
	bool GetNextBookLog(BOOKLOGINFO &);
	///////////////////USERLOGMANAGE///////////////////////
	void UserLogListInfo();
	void UserLogResponse();
	void UserLogDelInfo(USERLOGINFO &);
	bool GetNextUserLog(USERLOGINFO &);
	///////////////////////USERMANAGE///////////////////////
	void UserAddInfo(USERINFO &);
	void UserDelInfo(USERINFO &);
	void UserUpdateInfo(USERINFO &);
	void UserQueryInfo(USERINFO &);
	void UserListInfo(USERINFO &);
	void UserResponse();
	void UserModifyPass(USERINFO &);
	void UserLogonInfo(USERINFO &);
	void UserLogOutInfo(USERINFO &);
	void UserExitInfo(USERINFO &);
	bool GetNextUser(USERINFO &);//�����һ���û���Ϣ

	///////////////////LENDMANAGE/////////////////////////////
	void LendOutInfo(LENDINFO &);
	void LendListInfo();
	bool GetNextLend(LENDINFO &);//�����һ��������鼮��Ϣ
	void LendResponse();
	void LendDelete(LENDINFO &);
	void LendReturn(LENDINFO &);
	void LendRenewal(LENDINFO &);
	void LendQueryInfo(LENDINFO &);

	bool ExcuteSqlCmd(QString);
	void ExcuteBookLogAdd(BOOKLOGINFO &);
	void ExcuteUserLogAdd(USERLOGINFO &);
	bool IsExist(QString sSql);

	bool ok;
	USERLOGINFO gUserLogInfo;
	QDateTime dateTime;
	QSqlQuery sqlQuery;//���ݿ����
signals:
	void Information(const MANAGEINFO &);
	void UserExitSystem();
};
#endif /* SQLCOMMAND_H_ */

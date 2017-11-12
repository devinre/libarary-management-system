/*
 * TCPClientSocket.cpp
 *
 *  Created on: 2009-8-24
 *      Author: Administrator
 */

#include "TCPClientThread.h"
#include "GlobalDefine.h"
TCPClientThread::TCPClientThread(QTcpSocket *tcpsoket, QObject *parent) :
	QThread(parent)
{
	// TODO Auto-generated constructor stub
	this->tcpsocket = tcpsoket;
}
TCPClientThread::~TCPClientThread()
{
	// TODO Auto-generated destructor stub
}
void TCPClientThread::ReadData()
{
	MANAGEINFO tmpInfo;
	while (tcpsocket->bytesAvailable() < 0)
	{
		if (!tcpsocket->waitForReadyRead(50000))
		{
			return;
		}
	}
	while (tcpsocket->bytesAvailable() > 0)
	{
		QByteArray datagram;
		datagram.resize(tcpsocket->bytesAvailable());
		tcpsocket->read(datagram.data(), datagram.size());
		QDataStream in(&datagram, QIODevice::ReadOnly);
		in >> tmpInfo.dwType;
		in >> tmpInfo.dwSubType;
		switch (tmpInfo.dwType)
		{
		case USER:
			cmd->RecvUserInfo(in, tmpInfo);
			break;
		case BOOK:
			cmd->RecvBookInfo(in, tmpInfo);
			break;
		case LEND:
			cmd->RecvLendInfo(in, tmpInfo);
			break;
		case READER:
			cmd->RecvReaderInfo(in, tmpInfo);
			break;
		case BOOKLOG:
			cmd->RecvBookLogInfo(in, tmpInfo);
			break;
		case USERLOG:
			cmd->RecvUserLogInfo(in, tmpInfo);
			break;
		}
	}
}
void TCPClientThread::WriteData(const MANAGEINFO &sendInfo)
{
	MANAGEINFO tmpInfo = sendInfo;
	QByteArray datagram;
	QDataStream out(&datagram, QIODevice::WriteOnly);
	out << tmpInfo.dwType;
	out << tmpInfo.dwSubType;
	switch (tmpInfo.dwType)
	{
	case BOOK:
		cmd->SendBookInfo(out, tmpInfo);
		break;
	case USER:
		cmd->SendUserInfo(out, tmpInfo);
		break;
	case LEND:
		cmd->SendLendInfo(out, tmpInfo);
		break;
	case READER:
		cmd->SendReaderInfo(out, tmpInfo);
		break;
	case BOOKLOG:
		cmd->SendBookLogInfo(out, tmpInfo);
		break;
	case USERLOG:
		cmd->SendUserLogInfo(out, tmpInfo);
		break;
	case RESULT:
		if (tmpInfo.dwSubType == BOOK || tmpInfo.dwSubType == BOOKLOG
				|| tmpInfo.dwSubType == LEND)
		{
			cmd->SendBookLogInfo(out, tmpInfo);
		}
		else
		{
			cmd->SendUserLogInfo(out, tmpInfo);
		}
		break;
	default:
		return;
	}
	tcpsocket->write(datagram);
}
void TCPClientThread::CloseConnect()
{
	this->quit();
	delete tcpsocket;
	delete cmd;
}
void TCPClientThread::run()
{
	cmd = new SqlCommand();
	cmd->GetPeerIP(tcpsocket->peerAddress().toString());
	QObject::connect(cmd, SIGNAL(Information(const MANAGEINFO &)), this,
			SLOT(WriteData(const MANAGEINFO &)));
	QObject::connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(ReadData()));
	QObject::connect(cmd, SIGNAL(UserExitSystem()), this, SLOT(CloseConnect()));
	this->exec();
}

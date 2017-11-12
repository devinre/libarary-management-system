/*
 * server.cpp
 *
 *  Created on: 2009-8-24
 *      Author: Administrator
 */

#include "server.h"
#include "GlobalDefine.h"
Server::Server(QObject *parent, int port) :
	QTcpServer(parent)
{
	// TODO Auto-generated constructor stub
	listen(QHostAddress::Any, port);
}
Server::~Server()
{
	// TODO Auto-generated destructor stub
}
void Server::incomingConnection(int socketDescriptor)
{
	QTcpSocket *tcpsocket = new QTcpSocket(this);
	if (!tcpsocket->setSocketDescriptor(socketDescriptor))
	{
		emit
		updateServer(tcpsocket->errorString(),
				tcpsocket->errorString().length());
		delete tcpsocket;
		return;
	}
	TCPClientThread *tcpclientthread = new TCPClientThread(tcpsocket, this);
	QObject::connect(tcpclientthread, SIGNAL(finished()), tcpclientthread,
			SLOT(deleteLater()));
	QObject::connect(tcpclientthread, SIGNAL(finished()), this,
			SIGNAL(SubConnNum()));
	QObject::connect(tcpclientthread,
			SIGNAL(updateClients(const SqlCommand *const, const int &)), this,
			SLOT(updateClients(const SqlCommand *const, const int &)));
	tcpclientthread->start();
	emit
	AddConnNum();
}
void Server::updateClients(const SqlCommand * const cmd, const int &flag)
{
	//emit
	//updateServer(cmd->GetInformation(), cmd->GetInformation().length());
}


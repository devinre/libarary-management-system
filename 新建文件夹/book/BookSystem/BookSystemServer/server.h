/*
 * server.h
 *
 *  Created on: 2009-8-24
 *      Author: Administrator
 */

#ifndef SERVER_H_
#define SERVER_H_
#include <QtNetwork>
#include "TCPClientThread.h"
#include "SqlCommand.h"
class BKSystemServer;
class Server: public QTcpServer
{
Q_OBJECT
public:
	Server(QObject *parent = 0, int port = 0);
	virtual ~Server();
private:
	QMutex mutex;
public slots:
	void updateClients(const SqlCommand * const , const int &);
signals:
	void updateServer(const QString &, const int &);
	void SubConnNum();
	void AddConnNum();
protected:
	void incomingConnection(int socketDescriptor);
};

#endif /* SERVER_H_ */

/*
 * TCPClientThread.h
 *
 *  Created on: 2009-8-24
 *      Author: Administrator
 */

#ifndef TCPCLIENTSOCKET_H_
#define TCPCLIENTSOCKET_H_
#include <QtNetwork>
#include "SqlCommand.h"
#include <QMutex>
class TCPClientThread: public QThread
{
Q_OBJECT
public:
	TCPClientThread(QTcpSocket *, QObject *parent = 0);
	virtual ~TCPClientThread();
signals:
	void updateClients(const SqlCommand * const , const int &);
private:
	SqlCommand *cmd;
	QTcpSocket *tcpsocket;
protected:
	void run();
private slots:
	void WriteData(const MANAGEINFO &);
	void ReadData();
	void CloseConnect();
};
#endif /* TCPCLIENTSOCKET_H_ */

/*
 * ServerTime.h
 *
 *  Created on: 2009-10-8
 *      Author: Administrator
 */

#ifndef SERVERTIME_H_
#define SERVERTIME_H_
#include <QtGui>
class ServerTime: public QThread
{
Q_OBJECT
public:
	ServerTime();
	virtual ~ServerTime();
private:
	int sec;
	int min;
	int hour;
signals:
	void ShowTime(const QString &);
protected:
	void run();
};

#endif /* SERVERTIME_H_ */

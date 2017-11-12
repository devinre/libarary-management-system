/*
 * ServerTime.cpp
 *
 *  Created on: 2009-10-8
 *      Author: Administrator
 */

#include "ServerTime.h"

ServerTime::ServerTime()
{
	sec = 0;
	min = 0;
	hour = 0;
	// TODO Auto-generated constructor stub
}

ServerTime::~ServerTime()
{
	// TODO Auto-generated destructor stub
}
void ServerTime::run()
{
	while (true)
	{
		sec++;
		if (sec == 60)
		{
			min++;
			sec = 0;
			if (min == 60)
			{
				hour++;
				min = 0;
			}
		}
		emit
		ShowTime(QString("%1 : %2 : %3").arg(hour).arg(min).arg(sec));
		sleep(1);
	}
}

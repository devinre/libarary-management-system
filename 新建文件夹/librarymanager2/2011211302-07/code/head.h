#ifndef HEAD_H
#define HEAD_H

#include <QString.h>
#include <qtimer.h>
#define imitate 1
#define common 0
#define BUSY 0
#define FREE 1


struct informationforuser{
    QString id;
    QString key;
    QString email;
    QString phone;
    QString code;
};

extern informationforuser infor3,infor4;

struct bookinfor{
    QString book_id;
    QString book_name;
    QString book_author;
    QString book_press;
    QString book_all;
    QString book_rest;
};

extern bookinfor binfor;


struct booklend{
    QString book_id;
    QString user_id;
    QString lend_time1;
    QString lend_time2;
    QString lend_time3;
    QString back_time1;
    QString back_time2;
    QString back_time3;
};

extern booklend blinfor;

extern QString bookid,userid;

extern int operateFlag;

extern int ye,mo,da;



#endif // HEAD_H

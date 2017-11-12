#ifndef SERVERIP_H
#define SERVERIP_H

#include <QtGui/QDialog>
#include "Uiserverip.h"
#include "booksystem.h"
#include <QtNetwork>

class ServerIP: public QDialog, UiServerIPClass
{
Q_OBJECT

public:
	ServerIP(QWidget *parent = 0);
	~ServerIP();

private slots:
	void ShowManageWindow();
	void Information(const QString &);
private:
	BookSystem *booksystem;
	QHostAddress *serverIP;
};

#endif // SERVERIP_H

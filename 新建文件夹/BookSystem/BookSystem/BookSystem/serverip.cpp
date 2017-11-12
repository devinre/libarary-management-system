#include "serverip.h"
#include <qmessagebox.h>

ServerIP::ServerIP(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
	QObject::connect(connBtn, SIGNAL(clicked()), this,
			SLOT(ShowManageWindow()));
	QObject::connect(exitBtn, SIGNAL(clicked()), this, SLOT(close()));
	ipEdit->setInputMask("000 . 000 . 000 . 000");
	ipEdit->setText("127.0.0.1");
}
ServerIP::~ServerIP()
{

}
void ServerIP::ShowManageWindow()
{
	QString ip = ipEdit->text();
	serverIP = new QHostAddress();
	booksystem = new BookSystem();
	QObject::connect(booksystem, SIGNAL(ConnInformation(const QString &)),
			this, SLOT(Information(const QString &)));
	if (!serverIP->setAddress(ip))
	{
		QMessageBox::information(this, tr("error"), tr(
				"server ip address error!"));
		return;
	}
	booksystem->SetBookSys(booksystem, ip, serverIP);
}
void ServerIP::Information(const QString &msg)
{
	if (msg == "OK")
	{
		this->close();
		booksystem->show();
	}
	else
	{
		QMessageBox::warning(this, tr("Warning"), tr(
				"Connect to server failed, Server host can not be found!"));
		return;
	}
}

#include "booksystem.h"
BookSystem::BookSystem(QWidget *parent) :
	QMainWindow(parent)
{
	InitSystem();
}
BookSystem::~BookSystem()
{

}
void BookSystem::InitSystem()
{
	setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	logonDlg = new Logon(this);
	updatePwdDlg = new UpdatePwd(this);
	sendMsg = new SendMsg();
	bookManage = new BookManage();
	SetSubWindow(bookManage);
	bookLogManage = new BookLogManage();
	SetSubWindow(bookLogManage);
	userLogManage = new UserLogManage();
	SetSubWindow(userLogManage);
	userManage = new UserManage();
	SetSubWindow(userManage);
	lendManage = new LendManage();
	SetSubWindow(lendManage);
	toolBar->addSeparator();
	toolBar->addAction(lendBook);
	toolBar->addAction(returnBook);
	toolBar->addAction(queryBook);
	toolBar->addAction(bookList);
	toolBar->addSeparator();
	toolBar->addAction(login);
	toolBar->addAction(exit);
	toolBar->addSeparator();
	toolBar->addAction(helpDoc);
	setWindowState(Qt::WindowMaximized);
	/////////////////////////BOOKSYSTEM//////////////////////////
	QObject::connect(showGPS, SIGNAL(triggered()), this, SLOT(ShowGPS()));
	QObject::connect(exit, SIGNAL(triggered()), this, SLOT(close()));
	QObject::connect(about, SIGNAL(triggered()), this, SLOT(About()));
	//////////////////////////BOOKMANAGE//////////////////////////
	QObject::connect(bookList, SIGNAL(triggered()), this,
			SLOT(ShowBookManage()));
	QObject::connect(updateBook, SIGNAL(triggered()), this,
			SLOT(ShowBookManage()));
	QObject::connect(addBook, SIGNAL(triggered()), this, SLOT(ShowBookManage()));
	QObject::connect(queryBook, SIGNAL(triggered()), this,
			SLOT(ShowBookManage()));
	QObject::connect(delBook, SIGNAL(triggered()), this, SLOT(ShowBookManage()));
	QObject::connect(bookManage->exit, SIGNAL(triggered()),
			bookManage->parentWidget(), SLOT(close()));
	QObject::connect(bookManage, SIGNAL(SendBookInfo(const MANAGEINFO &)),
			this, SLOT(GetSendData(const MANAGEINFO &)));
	QObject::connect(bkManageBtn, SIGNAL(clicked()), this,
			SLOT(ShowBookManage()));
	QObject::connect(bkQueryBtn, SIGNAL(clicked()), this,
			SLOT(ShowBookManage()));
	QObject::connect(bkLendBtn, SIGNAL(clicked()), this, SLOT(ShowBookManage()));
	QObject::connect(lendBook, SIGNAL(triggered()), this,
			SLOT(ShowBookManage()));
	/////////////////////LENDMANAGE/////////////////////////////
	QObject::connect(lendManage->exit, SIGNAL(triggered()),
			lendManage->parentWidget(), SLOT(close()));
	QObject::connect(returnBook, SIGNAL(triggered()), this,
			SLOT(ShowLendManage()));
	QObject::connect(lendManage, SIGNAL(SendLendInfo(const MANAGEINFO &)),
			this, SLOT(GetSendData(const MANAGEINFO &)));
	QObject::connect(bkRenewalBtn, SIGNAL(clicked()), this,
			SLOT(ShowLendManage()));
	QObject::connect(bkReturnBtn, SIGNAL(clicked()), this,
			SLOT(ShowLendManage()));
	////////////////////BOOKLOGMANAGE///////////////////////////
	QObject::connect(bookLog, SIGNAL(triggered()), this,
			SLOT(ShowBookLogManage()));
	QObject::connect(bookLogManage,
			SIGNAL(SendBookLogInfo(const MANAGEINFO &)), this,
			SLOT(GetSendData(const MANAGEINFO &)));
	QObject::connect(bookLogManage->exit, SIGNAL(triggered()),
			bookLogManage->parentWidget(), SLOT(close()));
	///////////////////////USERLOGMANAGE///////////////////////////
	QObject::connect(userLog, SIGNAL(triggered()), this,
			SLOT(ShowUserLogManage()));
	QObject::connect(userLogManage,
			SIGNAL(SendUserLogInfo(const MANAGEINFO &)), this,
			SLOT(GetSendData(const MANAGEINFO &)));
	QObject::connect(userLogManage->exit, SIGNAL(triggered()),
			userLogManage->parentWidget(), SLOT(close()));
	/////////////////////USERMANAGE///////////////////////////////
	QObject::connect(userTableBtn, SIGNAL(clicked()), this,
			SLOT(ShowUserManage()));
	QObject::connect(addUser, SIGNAL(triggered()), this, SLOT(ShowUserManage()));
	QObject::connect(delUser, SIGNAL(triggered()), this, SLOT(ShowUserManage()));
	QObject::connect(updateUser, SIGNAL(triggered()), this,
			SLOT(ShowUserManage()));
	QObject::connect(userList, SIGNAL(triggered()), this,
			SLOT(ShowUserManage()));
	QObject::connect(userManageBtn, SIGNAL(clicked()), this,
			SLOT(ShowUserManage()));
	QObject::connect(logonDlg, SIGNAL(SendLogOnInfo(const MANAGEINFO &)), this,
			SLOT(GetSendData(const MANAGEINFO &)));
	QObject::connect(login, SIGNAL(triggered()), this, SLOT(ShowLogon()));
	QObject::connect(logoff, SIGNAL(triggered()), this, SLOT(UserLogOut()));
	QObject::connect(logonBtn, SIGNAL(clicked()), this, SLOT(ShowLogon()));
	QObject::connect(logoutBtn, SIGNAL(clicked()), this, SLOT(UserLogOut()));
	QObject::connect(updatePwdDlg,
			SIGNAL(SendUpdatePassInfo(const MANAGEINFO &)), this,
			SLOT(GetSendData(const MANAGEINFO &)));
	QObject::connect(pwdModify, SIGNAL(triggered()), this,
			SLOT(ShowUpdatePwd()));
	QObject::connect(pwdModifyBtn, SIGNAL(clicked()), this,
			SLOT(ShowUpdatePwd()));
	QObject::connect(userManage->exit, SIGNAL(triggered()),
			userManage->parentWidget(), SLOT(close()));
	QObject::connect(userManage, SIGNAL(SendUserInfo(const MANAGEINFO &)),
			this, SLOT(GetSendData(const MANAGEINFO &)));
	SetEnabled(false);
}
void BookSystem::SetEnabled(bool ok)
{
	userTableBtn->setEnabled(ok);
	userManageBtn->setEnabled(ok);
	addUser->setEnabled(ok);
	delUser->setEnabled(ok);
	updateUser->setEnabled(ok);
	userList->setEnabled(ok);
	updateBook->setEnabled(ok);
	addBook->setEnabled(ok);
	delBook->setEnabled(ok);
	bkManageBtn->setEnabled(ok);
	bkLendBtn->setEnabled(ok);
	lendBook->setEnabled(ok);
	returnBook->setEnabled(ok);
	bkRenewalBtn->setEnabled(ok);
	bkReturnBtn->setEnabled(ok);
	bookLog->setEnabled(ok);
	userLog->setEnabled(ok);
	readerManageBtn->setEnabled(ok);
	logManageBtn->setEnabled(ok);
	bookStatBtn->setEnabled(ok);
	lendRecordBtn->setEnabled(ok);
	overDueBtn->setEnabled(ok);
	renewal->setEnabled(ok);
	lendRecord->setEnabled(ok);
	lendSta->setEnabled(ok);
	overdueRec->setEnabled(ok);
	addReader->setEnabled(ok);
	delReader->setEnabled(ok);
	updateReader->setEnabled(ok);
	readerTable->setEnabled(ok);
	bookManage->SetEnabled(ok);
}
void BookSystem::ShowBookManage()
{
	if (bookManage->isVisible())
	{
		bookManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
	else
	{
		bookManage->show();
		bookManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
}
void BookSystem::ShowBookLogManage()
{
	if (bookLogManage->isVisible())
	{
		bookLogManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
	else
	{
		bookLogManage->show();

		bookLogManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
}
void BookSystem::ShowUserLogManage()
{
	if (userLogManage->isVisible())
	{
		userLogManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
	else
	{
		userLogManage->show();

		userLogManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
}
void BookSystem::ShowUserManage()
{
	if (userManage->isVisible())
	{
		userManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
	else
	{
		userManage->show();
		userManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
}
void BookSystem::ShowLendManage()
{
	if (lendManage->isVisible())
	{
		lendManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
	else
	{
		lendManage->show();
		lendManage->parentWidget()->setWindowState(Qt::WindowMaximized);
	}
}
void BookSystem::ShowUpdatePwd()
{
	USERINFO lUserInfo;
	if (IsLogon())
	{
		lUserInfo = logonDlg->GetLogonUserInfo();
		updatePwdDlg->GetCurrentUserInfo(lUserInfo);
		updatePwdDlg->show();
	}
	else
	{
		QMessageBox::warning(this, tr("UpdatePassword"),
				tr("You hav't log on!"));
	}
}
void BookSystem::SetSubWindow(QWidget *widget)
{
	sub = new QMdiSubWindow(this);
	sub->setWidget(widget);
	mdiArea->addSubWindow(sub);
	sub->close();
}
void BookSystem::ShowGPS()
{
	QIcon icon;
	if (toolBox->isVisible())
	{
		icon.addFile(QString::fromUtf8(":/icon/showGPS.png"), QSize(),
				QIcon::Normal, QIcon::Off);
		showGPS->setText(tr("ShowGPS"));
		toolBox->hide();
	}
	else
	{
		icon.addFile(QString::fromUtf8(":/icon/closeGPS.png"), QSize(),
				QIcon::Normal, QIcon::Off);
		showGPS->setText(tr("CloseGPS"));
		toolBox->show();
	}
	showGPS->setIcon(icon);
}
void BookSystem::closeEvent(QCloseEvent *event)
{
	USERINFO lUserInfo;
	MANAGEINFO tmpInfo;
	if (QMessageBox::question(this, tr("Close"), tr(
			"Are you sure to quit book system?"), QMessageBox::Ok,
			QMessageBox::Cancel) == QMessageBox::Ok)
	{
		tmpInfo.dwType = USER;
		tmpInfo.dwSubType = USER_EXIT;
		lUserInfo = logonDlg->GetLogonUserInfo();
		tmpInfo.userInfo = lUserInfo;
		GetSendData(tmpInfo);
		tcpsocket->disconnectFromHost();
		if (tcpsocket->waitForDisconnected())
		{
			event->accept();
		}
	}
	else
		event->ignore();
}

void BookSystem::SetBookSys(BookSystem *booksys, QString ip,
		QHostAddress *serverIP)
{
	this->ip = ip;
	this->serverIP = serverIP;
	ConnectServer();
}

/////////////////////////////// log on/////////////////////////////////
void BookSystem::ShowLogon()
{
	if (IsLogon())
	{
		QMessageBox::warning(this, tr("Logon"), tr("You have log on!"));
	}
	else
	{
		logonDlg->show();
	}
}
bool BookSystem::IsLogon()
{
	bool ok;
	USERINFO lUserInfo = logonDlg->GetLogonUserInfo();
	if (lUserInfo.sID.toInt(&ok) | lUserInfo.sPass.toInt(&ok)
			| lUserInfo.sLastTime.toInt(&ok))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void BookSystem::UserLogOut()
{
	MANAGEINFO tmpInfo;
	USERINFO lUserInfo = logonDlg->GetLogonUserInfo();
	if (IsLogon())
	{
		if (QMessageBox::question(this, tr("Close"), tr(
				"Are you sure to quit book system?"), QMessageBox::Ok,
				QMessageBox::Cancel) == QMessageBox::Cancel)
		{
			return;
		}
		tmpInfo.dwType = USER;
		tmpInfo.dwSubType = USER_LOGOUT;
		tmpInfo.userInfo = lUserInfo;
		logonDlg->ClearInfo();
		GetSendData(tmpInfo);
		SetEnabled(false);
		lendManage->parentWidget()->close();
		userManage->parentWidget()->close();
		userLogManage->parentWidget()->close();
		bookLogManage->parentWidget()->close();
		QMessageBox::warning(this, tr("Logout"), tr("Logout successfully!"));
	}
	else
	{
		QMessageBox::warning(this, tr("Logout"), tr("You have't log on!"));
	}
}
void BookSystem::About()
{
	QMessageBox::about(this, tr("About"), tr("BookSystem V1.0"
											"Maker:jiangxiaotao"
													"2010.1"));
}
//////////////////////////////data received/////////////////////////////
void BookSystem::DataReceived()
{
	MANAGEINFO recvInfo;
	while (tcpsocket->bytesAvailable() > 0)
	{
		QByteArray datagram;
		datagram.resize(tcpsocket->bytesAvailable());
		tcpsocket->read(datagram.data(), datagram.size());
		QDataStream in(&datagram, QIODevice::ReadOnly);
		in >> recvInfo.dwType;
		in >> recvInfo.dwSubType;
		switch (recvInfo.dwType)
		{
		case BOOK:
			sendMsg->RecvBookInfo(in, recvInfo.bookInfo);
			bookManage->InsertResponseBookInfo(recvInfo);
			break;
		case USER:
			sendMsg->RecvUserInfo(in, recvInfo.userInfo);
			userManage->InsertResponseUserInfo(recvInfo);
			break;
		case LEND:
			sendMsg->RecvLendInfo(in, recvInfo.lendInfo);
			lendManage->InsertResponseBookInfo(recvInfo);
			break;
		case READER:
			sendMsg->RecvReaderInfo(in, recvInfo.readerInfo);
			break;
		case BOOKLOG:
			sendMsg->RecvBookLogInfo(in, recvInfo.bookLogInfo);
			bookLogManage->InsertResponseBookLogInfo(recvInfo);
			break;
		case USERLOG:
			sendMsg->RecvUserLogInfo(in, recvInfo.userLogInfo);
			userLogManage->InsertResponseUserLogInfo(recvInfo);
			break;
		case RESULT:
			if (recvInfo.dwSubType == BOOK || recvInfo.dwSubType == BOOKLOG
					|| recvInfo.dwSubType == LEND)
			{
				sendMsg->RecvBookLogInfo(in, recvInfo.bookLogInfo);
			}
			else
			{
				sendMsg->RecvUserLogInfo(in, recvInfo.userLogInfo);
			}
			DealResult(recvInfo);
			break;
		}
	}
}
void BookSystem::DealResult(MANAGEINFO &resultInfo)
{
	switch (resultInfo.dwSubType)
	{
	case BOOK:
		bookManage->RecvResultInfo(resultInfo.bookLogInfo);
		break;
	case USER:
		userManage->RecvResultInfo(resultInfo.userLogInfo);
		break;
	case LEND:
		lendManage->RecvResultInfo(resultInfo.bookLogInfo);
		break;
	case READER:
		break;
	case BOOKLOG:
		bookLogManage->RecvResultInfo(resultInfo.bookLogInfo);
		break;
	case USERLOG:
		userLogManage->RecvResultInfo(resultInfo.userLogInfo);
		break;
	case USER_LOGON:
		logonDlg->RecvResultInfo(resultInfo.userLogInfo);
		if(!resultInfo.userLogInfo.dwResult)
		{
			SetEnabled(true);
		}
		break;
	case USER_UPDATEPWD:
		updatePwdDlg->RecvResultInfo(resultInfo.userLogInfo);
		break;
	}
}
/////////////////////////////////data send/////////////////////////////////
void BookSystem::GetSendData(const MANAGEINFO &manageInfo)
{
	qDebug() << "GetSendData()";
	sendMsg->SetManageInfo(manageInfo);
	if (!sendMsg->DataSend(tcpsocket))
	{
		return;
	}
}
///////////////////////////////connect server//////////////////////////////
inline void BookSystem::ConnectServer()
{
	serverIP->setAddress(ip);
	tcpsocket = new QTcpSocket(this);
	QObject::connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(DataReceived()));
	tcpsocket->connectToHost(*serverIP, PORT);
	if (tcpsocket->waitForConnected(20000))
	{
		emit
		ConnInformation("OK");
	}
	else
	{
		emit
		ConnInformation("NO");
	}
}

#include "booksystemserver.h"

BookSystemServer::BookSystemServer(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
	InitServer();
	SetWindowTrayIcon();
	lib.setFileName("qsqlmysql4.dll");
	if(!lib.isLoaded())
	{
		lib.load();
	}
}

BookSystemServer::~BookSystemServer()
{
	servertime.quit();
	delete server;
	if (db.isOpen())
	{
		db.close();
		QSqlDatabase::removeDatabase(db.connectionName());
	}
}
void BookSystemServer::InitServer()
{
	closeFlag = 0;
	mysqlflag = 0;
	conn_num = 0;
	listWidget->hide();
	current_conn_num->hide();
	conn_num_label->hide();
	start_label->hide();
	startuptime->hide();
	line->hide();
	line_2->hide();
	defaultport = PORT;
	server_database->setText("libbook");
	server_database->setEnabled(false);
	server_username->setText("root");
	server_password->setText("jiangtao");
	layout()->setSizeConstraint(QLayout::SetMinAndMaxSize);
	QObject::connect(server_exit_btn, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(server_conn_btn, SIGNAL(clicked()), this,
			SLOT(SetSQLValue()));
}
void BookSystemServer::SetWindowTrayIcon()
{
	QMenu *menu = new QMenu(this);
	QAction *showInDesk = menu->addAction(tr("ShowInDesk"));
	QAction *exit = menu->addAction(tr("ExitServer"));
	QObject::connect(exit, SIGNAL(triggered()), this, SLOT(Close()));
	QObject::connect(showInDesk, SIGNAL(triggered()), this, SLOT(show()));
	QIcon icon;
	icon.addFile(QString::fromUtf8(":/icon/systemserver.ico"), QSize(),
			QIcon::Normal, QIcon::Off);
	QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
	trayIcon->setIcon(icon);
	trayIcon->setVisible(true);
	trayIcon->setContextMenu(menu);
	trayIcon->setToolTip(tr("BookSystemServer"));
}
void BookSystemServer::Close()
{
	closeFlag = 1;
	this->close();
}
void BookSystemServer::closeEvent(QCloseEvent *event)
{

	if (closeFlag == 1)
	{
		event->accept();
	}
	else
	{
		hide();
		closeFlag = 0;
		event->ignore();
	}
}
bool BookSystemServer::MYSQLConnector()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setDatabaseName(database);
	db.setHostName("localhost");
	db.setUserName(username);
	db.setPassword(password);
	if (!db.open())
	{
		QMessageBox::critical(0, QObject::tr("Database Error"),
				db.lastError().text());
		return false;
	}
	mysqlflag = 1;
	return true;
}
inline QString BookSystemServer::GetDatabase() const
{
	return server_database->text();
}
inline QString BookSystemServer::GetUserName() const
{
	return server_username->text();
}
inline QString BookSystemServer::GetPassword() const
{
	return server_password->text();
}
void BookSystemServer::SetSQLValue()
{
	if (mysqlflag != 1)
	{
		database = GetDatabase();
		username = GetUserName();
		password = GetPassword();
		if (MYSQLConnector())
		{
			listWidget->addItem(tr("Connect to database successfully!"));
			listWidget->addItem(tr("Database:") + database);
			listWidget->addItem(tr("User name:") + username);
			database_label->hide();
			username_label->hide();
			password_label->hide();
			server_database->hide();
			server_username->hide();
			server_password->hide();
			listWidget->show();
			current_conn_num->show();
			conn_num_label->show();
			start_label->show();
			startuptime->show();
			line->show();
			line_2->show();
			CreatServer();
			QObject::connect(&servertime, SIGNAL(ShowTime(const QString &)),
					this, SLOT(ShowTime(const QString &)));
			servertime.start();
		}
	}
	else
	{
		QMessageBox::warning(this, tr("Warning"), tr("The DB is connected"),
				QMessageBox::Ok);
	}
}
inline void BookSystemServer::CreatServer()
{
	server = new Server(this, defaultport);
	QObject::connect(server,
			SIGNAL(updateServer(const QString &, const int &)), this,
			SLOT(UpdateServer(const QString &, const int &)));
	QObject::connect(server, SIGNAL(AddConnNum()), this, SLOT(AddConnNum()));
	QObject::connect(server, SIGNAL(SubConnNum()), this, SLOT(SubConnNum()));
}
void BookSystemServer::UpdateServer(const QString &, const int &)
{

}
void BookSystemServer::AddConnNum()
{
	conn_num++;
	conn_num_label->setText(QString("%1").arg(conn_num));
}
void BookSystemServer::SubConnNum()
{
	conn_num--;
	conn_num_label->setText(QString("%1").arg(conn_num));
}
void BookSystemServer::ShowTime(const QString &time)
{
	start_label->setText(time);
}

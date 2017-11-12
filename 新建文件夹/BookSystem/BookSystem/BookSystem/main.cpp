#include "serverip.h"
#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
	QFont font("·ÂËÎ", 10);
	QApplication::setFont(font);
	QApplication a(argc, argv);
	QTranslator translate;
	translate.load("language/BookSystem_Ch");
	a.installTranslator(&translate);
	ServerIP *w = new ServerIP();
	w->show();
	return a.exec();
}

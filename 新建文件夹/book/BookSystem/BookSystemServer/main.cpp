#include "booksystemserver.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translate;
	translate.load("language/BookSystemServer_Ch");
	a.installTranslator(&translate);
	BookSystemServer *w = new BookSystemServer();
	w->show();
	return a.exec();
}

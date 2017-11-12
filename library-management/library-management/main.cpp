#include "librarymanagement.h"
#include <QtWidgets/QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	login log;
	if (log.exec() == QDialog::Accepted)
	{
		librarymanagement w;
		w.show();
		return a.exec();
	}
	return 0;
}

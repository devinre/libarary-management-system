#include "library.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Library S;
	QFont font = a.font();
	font.setPointSize(11); //�������������С
	a.setFont(font);
    return a.exec();
}

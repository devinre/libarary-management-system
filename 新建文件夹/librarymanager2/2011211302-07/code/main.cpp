#include "mainwindow.h"
#include "head.h"
#include <QMessageBox.h>
#include <QApplication.h>
#include <QLabel.h>
#include <qfile.h>
#include <QString>
#include <qtextstream.h>
#include <qtimer.h>


int operateFlag=FREE;
int ye=0,mo=0,da=0;
QString userid="123";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

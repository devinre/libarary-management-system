#include "logindialog.h"
#include "widget.h"
#include <QApplication>
//#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QSqlDatabase db;
    //if(!createConnection(db)) return 0;

    Widget w;   
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {

        w.show();
        w.init();
        return a.exec();
    }
    else
    {
        return 0;
    }
}

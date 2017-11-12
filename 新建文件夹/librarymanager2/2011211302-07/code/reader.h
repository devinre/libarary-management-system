#ifndef READER_H
#define READER_H
#include <QDialog.h>
#include "key.h"

namespace Ui {
class reader;
}

class reader: public QDialog
{
    Q_OBJECT

public:
    explicit reader(QWidget *parent =0);
    ~reader();
    void table1show(int begin);
    void table2show();
    void table1show2(int begin);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_rpc_clicked();

    void on_rexit_clicked();

    void on_lastpage1_clicked();

    void on_nextpage1_clicked();

    void on_pushButton_clicked();

    void on_seek_clicked();

    void on_pushButton_2_clicked();

    void on_reinput_clicked();

    void on_pushButton_4_clicked();

    void timerUpDate();
    void timerStart();

private:
    Ui::reader *reader_ui;
    key kw;
};


#endif // READER_H

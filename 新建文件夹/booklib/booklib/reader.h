#ifndef READER_H
#define READER_H

#include <QWidget>
#include <readermod.h>
namespace Ui {
    class reader;
}

class reader : public QWidget
{
    Q_OBJECT

public:
    explicit reader(QWidget *parent = 0);
    ~reader();
     void init();

private slots:
    void on_btnSubmit_clicked();

    void on_btnExit_clicked();

    void on_btnSearch_clicked();

    void on_btnRet_clicked();

    void on_pushButton_clicked();

    void on_pbLend_clicked();

    void on_btnMod_clicked();

private:
    Ui::reader *ui;
    readerMod remod;
};

#endif // READER_H

#ifndef ADMIN_H
#define ADMIN_H
#include "bookmod.h"
#include <QWidget>

namespace Ui {
    class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();
    bookmod bm;

private slots:
    void on_btnAddBook_clicked();

    void on_btnUserMod_clicked();

    void on_rbAdmin_clicked();

    void on_rbUser_clicked();

    void on_rbdelUser_clicked();

    void on_btnbookDel_clicked();

    void on_btnbookUpd_clicked();

    void on_btnMsgSea_clicked();

    void on_btnMsgAll_clicked();

    void on_btnMesdel_clicked();

    void on_pushButton_clicked();

    void on_btnExit_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H

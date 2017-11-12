#ifndef ADMIN_H
#define ADMIN_H
#include <QDialog.h>
#include "key.h"
#include "book.h"
#include "bookl.h"
#include "ad_user.h"


namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent =0);
    ~admin();
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_adexit_clicked();

    void on_adpchange_clicked();

    void on_adbchange_clicked();

    void on_lend_clicked();

    void on_aduchange_clicked();

    void timerUpDate();
    void timerStart();

private:
    Ui::admin *admin_ui;
    key kw;
    book bw;
    bookl blw;
    ad_user adw;
};


#endif // ADMIN_H

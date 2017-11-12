#ifndef AD_USER_H
#define AD_USER_H

#include <QDialog.h>

namespace Ui {
class ad_user;
}

class ad_user : public QDialog
{
    Q_OBJECT

public:
    explicit ad_user(QWidget *parent =0);
    ~ad_user();
    void showuser(int begin);

    int judge(QString id);

    void showmessage(int begin);

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_exit_clicked();

    void on_lastpage_clicked();

    void on_nextpage_clicked();

    void on_okButton_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_update_clicked();


    void on_deleteall_clicked();

    void on_deletemessage_clicked();

    void on_lsatpagem_clicked();

    void on_nextpagem_clicked();

    void timerUpDate();

private:
    Ui::ad_user *ad_user_ui;

};


#endif // AD_USER_H

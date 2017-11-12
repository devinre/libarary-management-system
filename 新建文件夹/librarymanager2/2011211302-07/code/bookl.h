#ifndef bookl_H
#define bookl_H

#include <QDialog.h>

namespace Ui {
class bookl;
}

class bookl : public QDialog
{
    Q_OBJECT

public:
    explicit bookl(QWidget *parent =0);
    ~bookl();
    void showle(int begin);

    bool eventFilter(QObject *obj, QEvent *event);


private slots:
    void on_okbutton_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_exit_clicked();



    void on_update_clicked();

    void on_lastpage_clicked();

    void on_nextpage_clicked();

    void on_begin_clicked();

    void on_end_clicked();

    void timerUpDate();

private:
    Ui::bookl *bookl_ui;
};

#endif // bookl_H

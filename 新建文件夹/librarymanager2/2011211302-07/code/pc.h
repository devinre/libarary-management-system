#ifndef PC_H
#define PC_H

#include <QDialog.h>

namespace Ui {
class pc;
}

class pc: public QDialog
{
    Q_OBJECT

public:
    explicit pc(QWidget *parent =0);
    ~pc();

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pc_exitb_clicked();

    void on_pc_clearb_clicked();

    void on_pc_regb_clicked();

    void timerUpDate();

private:
    Ui::pc *pc_ui;
};

#endif // PC_H

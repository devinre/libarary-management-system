#ifndef REG_H
#define REG_H
#include <QDialog.h>

namespace Ui {
class reg;
}

class reg : public QDialog
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent =0);
    ~reg();

private slots:
    void on_clearb_clicked();
    void on_exitb_clicked();
    void on_regb_clicked();

private:
    Ui::reg *reg_ui;
};

#endif //REG_H



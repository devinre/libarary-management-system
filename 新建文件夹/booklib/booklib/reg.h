#ifndef REG_H
#define REG_H
#include "reader.h"
#include <QDialog>

namespace Ui {
    class reg;
}

class reg : public QDialog
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = 0);
    ~reg();

private slots:
    void on_sumBtn_clicked();

    void on_exitBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::reg *ui;
    reader re;
};

#endif // REG_H

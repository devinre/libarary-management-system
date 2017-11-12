#ifndef BOOKMOD_H
#define BOOKMOD_H

#include <QDialog>

namespace Ui {
    class bookmod;
}

class bookmod : public QDialog
{
    Q_OBJECT

public:
    explicit bookmod(QWidget *parent = 0);
    ~bookmod();
    void init();

private slots:
    void on_btnExit_clicked();

    void on_btnCon_clicked();

    void on_btnSum_clicked();

private:
    Ui::bookmod *ui;
};

#endif // BOOKMOD_H

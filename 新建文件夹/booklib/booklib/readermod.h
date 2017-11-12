#ifndef READERMOD_H
#define READERMOD_H

#include <QDialog>

namespace Ui {
    class readerMod;
}

class readerMod : public QDialog
{
    Q_OBJECT

public:
    explicit readerMod(QWidget *parent = 0);
    ~readerMod();

private slots:
    void on_btnCan_clicked();

    void on_bynSum_clicked();

    void on_btnExit_clicked();

private:
    Ui::readerMod *ui;
};

#endif // READERMOD_H

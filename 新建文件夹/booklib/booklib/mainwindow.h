#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reg.h"
#include "admin.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 //  extern QString userid;

private slots:
    void on_pblogin_clicked();

    void on_regBtn_clicked();

    void on_loginBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    reg regw;
    reader re;
    admin ad;
};

#endif // MAINWINDOW_H

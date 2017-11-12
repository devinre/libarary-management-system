#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow.h>
#include "reg.h"
#include "reader.h"
#include "admin.h"
#include "head.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_logbutton_clicked();
    void on_regbutton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    reg regw;
    reader re;
    admin ad;
};

#endif // MAINWINDOW_H

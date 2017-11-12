#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPalette>
#include <QPixmap>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_loginBtn_clicked();

    void on_exitBtn_clicked();

    void on_regBtn_clicked();

private:
    Ui::LoginDialog *ui;

    //QLabel *bgimage;
    //QPalette palette;
};

#endif // LOGINDIALOG_H

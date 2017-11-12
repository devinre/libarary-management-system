#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
//#include <QProcess>
//class QSqlTableModel;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void init();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_changePwdButton_clicked();

    void on_mianPageButton_clicked();

    void on_clearButton_clicked();

    void on_exitButton_clicked();

    void on_sumbitButton_clicked();

    void on_returnLoginButton_clicked();

    void on_searchButton_clicked();

    void on_myBorrowButton_clicked();

    void on_bookBorrowButton_clicked();

    void on_bookRepayButton_clicked();

    void on_adminButton_clicked();

    void on_adminAddButton_clicked();

    void on_adminUpdataButton_clicked();

    void on_adminDeleteButton_clicked();

    void on_adminSearchButton_clicked();

    void on_adminDeleteUserBt_clicked();

    void on_adminSearchUserBt_clicked();

    void on_adminSearchAllUserBt_clicked();

    void qtimeSlot();
private:
    Ui::Widget *ui;
    QTimer *timer;
    //QProcess *process;
    //QSqlTableModel *model;
};

#endif // WIDGET_H

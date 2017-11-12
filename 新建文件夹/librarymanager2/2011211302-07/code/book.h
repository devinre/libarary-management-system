#ifndef BOOK_H
#define BOOK_H
#include <QDialog.h>

namespace Ui {
class book;
}

class book : public QDialog
{
    Q_OBJECT

public:
    explicit book(QWidget *parent =0);
    ~book();
    void tableshow(int begin);
    void tableshow2(int begin);
    bool eventFilter(QObject *obj, QEvent *event);


private slots:
    void on_add_clicked();

    void on_bexit_clicked();

    void on_freshen_clicked();

    void on_delete_2_clicked();

    void on_pushButton_2_clicked();

    void on_nextpage_clicked();

    void on_lastpage_clicked();

    void on_end_clicked();

    void on_begin_clicked();

    void on_seek_clicked();

    void timerUpDate();

private:
    Ui::book *book_ui;

};


#endif // BOOK_H

#ifndef KEY_H
#define KEY_H
#include <QDialog.h>
#include "pc.h"

namespace Ui {
class key;
}

class key : public QDialog
{
    Q_OBJECT

public:
    explicit key(QWidget *parent =0);
    ~key();

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_kok_clicked();

    void on_kexit_clicked();

private:
    Ui::key *key_ui;
    pc pw;
};

#endif // KEY_H

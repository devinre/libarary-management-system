#ifndef BOOKDIALOG_H
#define BOOKDIALOG_H

#include <QtGui/QDialog>
#include "UiBookDialog.h"
#include "GlobalDefine.h"
class BookDialog : public QDialog, public  UiBookDialogClass
{
    Q_OBJECT

public:
    BookDialog(QWidget *parent = 0);
    ~BookDialog();

private:
	void closeEvent(QCloseEvent *);
private slots:
	void SetBookInfo();
	void ClearTextInfo();

signals:
	void GetBookInfo(const BOOKINFO &);
};

#endif // BOOKDIALOG_H

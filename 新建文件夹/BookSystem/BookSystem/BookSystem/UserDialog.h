#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QtGui/QDialog>
#include "UiUserDialog.h"
#include "GlobalDefine.h"
class UserDialog : public QDialog, public UiUserDialogClass
{
    Q_OBJECT

public:
    UserDialog(QWidget *parent = 0);
    ~UserDialog();
private:
	void closeEvent(QCloseEvent *);
private slots:
	void SetUserInfo();
	void ClearTextInfo();

signals:
	void GetUserInfo(const USERINFO &);
};

#endif // USERDIALOG_H

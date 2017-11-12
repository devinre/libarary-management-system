/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label_2;
    QPushButton *regBtn;
    QPushButton *exitBtn;
    QLineEdit *logPwdLE;
    QPushButton *loginBtn;
    QLabel *label;
    QLineEdit *logIdLE;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(595, 350);
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 160, 67, 17));
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        regBtn = new QPushButton(LoginDialog);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setGeometry(QRect(410, 90, 97, 27));
        exitBtn = new QPushButton(LoginDialog);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(330, 220, 97, 27));
        logPwdLE = new QLineEdit(LoginDialog);
        logPwdLE->setObjectName(QStringLiteral("logPwdLE"));
        logPwdLE->setGeometry(QRect(240, 160, 113, 27));
        logPwdLE->setEchoMode(QLineEdit::Password);
        loginBtn = new QPushButton(LoginDialog);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(130, 220, 97, 27));
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 90, 67, 21));
        label->setFont(font);
        logIdLE = new QLineEdit(LoginDialog);
        logIdLE->setObjectName(QStringLiteral("logIdLE"));
        logIdLE->setGeometry(QRect(240, 90, 113, 27));
        QWidget::setTabOrder(logIdLE, logPwdLE);
        QWidget::setTabOrder(logPwdLE, regBtn);
        QWidget::setTabOrder(regBtn, loginBtn);
        QWidget::setTabOrder(loginBtn, exitBtn);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        regBtn->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("LoginDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        logPwdLE->setText(QApplication::translate("LoginDialog", "admin", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "\345\270\220\345\217\267\357\274\232", Q_NULLPTR));
        logIdLE->setText(QApplication::translate("LoginDialog", "admin", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

#ifndef UI_UPDATEPWD_H
#define UI_UPDATEPWD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
class UiUpdatePwdClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *oldPwdEdit;
    QLabel *label_2;
    QLineEdit *newPwdEdit;
    QLabel *label_3;
    QLineEdit *confirmEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *UpdatePwdClass)
    {
        if (UpdatePwdClass->objectName().isEmpty())
            UpdatePwdClass->setObjectName(QString::fromUtf8("UpdatePwdClass"));
        UpdatePwdClass->resize(286, 191);
        UpdatePwdClass->setMinimumSize(QSize(286, 191));
        UpdatePwdClass->setMaximumSize(QSize(286, 191));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/pwdmodify.png"), QSize(), QIcon::Normal, QIcon::Off);
        UpdatePwdClass->setWindowIcon(icon);
        gridLayout = new QGridLayout(UpdatePwdClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(UpdatePwdClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        oldPwdEdit = new QLineEdit(UpdatePwdClass);
        oldPwdEdit->setObjectName(QString::fromUtf8("oldPwdEdit"));
        oldPwdEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(oldPwdEdit, 0, 1, 1, 2);

        label_2 = new QLabel(UpdatePwdClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        newPwdEdit = new QLineEdit(UpdatePwdClass);
        newPwdEdit->setObjectName(QString::fromUtf8("newPwdEdit"));
        newPwdEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newPwdEdit, 1, 1, 1, 2);

        label_3 = new QLabel(UpdatePwdClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        confirmEdit = new QLineEdit(UpdatePwdClass);
        confirmEdit->setObjectName(QString::fromUtf8("confirmEdit"));
        confirmEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(confirmEdit, 2, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        cancelBtn = new QPushButton(UpdatePwdClass);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(77, 25));
        cancelBtn->setMaximumSize(QSize(77, 25));

        gridLayout->addWidget(cancelBtn, 3, 1, 1, 1);

        okBtn = new QPushButton(UpdatePwdClass);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setMinimumSize(QSize(77, 25));
        okBtn->setMaximumSize(QSize(77, 25));

        gridLayout->addWidget(okBtn, 3, 2, 1, 1);


        retranslateUi(UpdatePwdClass);

        QMetaObject::connectSlotsByName(UpdatePwdClass);
    } // setupUi

    void retranslateUi(QDialog *UpdatePwdClass)
    {
        UpdatePwdClass->setWindowTitle(QApplication::translate("UpdatePwdClass", "UpdatePwd", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UpdatePwdClass", "OldPass:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UpdatePwdClass", "NewPass:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UpdatePwdClass", "ConfirmPass:", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("UpdatePwdClass", "&Cancel", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("UpdatePwdClass", "&OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};
#endif // UI_UPDATEPWD_H

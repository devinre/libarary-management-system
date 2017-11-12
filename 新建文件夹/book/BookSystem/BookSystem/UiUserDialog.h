
#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

class UiUserDialogClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *idCardEdit;
    QLineEdit *idEdit;
    QLineEdit *passEdit;
    QLineEdit *nameEdit;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *sexBox;
    QLabel *label_10;
    QLineEdit *emailEdit;
    QDateEdit *brthBox;
    QLabel *label_7;
    QLineEdit *phoneEdit;
    QComboBox *statusBox;
    QLabel *label_11;
    QComboBox *powerBox;
    QLabel *label_9;
    QPushButton *confirmBtn;
    QPushButton *clearBtn;
    QPushButton *cancelBtn;
    QLabel *label_8;

    void setupUi(QDialog *UserDialogClass)
    {
        if (UserDialogClass->objectName().isEmpty())
            UserDialogClass->setObjectName(QString::fromUtf8("UserDialogClass"));
        UserDialogClass->resize(554, 436);
        UserDialogClass->setMinimumSize(QSize(554, 436));
        UserDialogClass->setMaximumSize(QSize(554, 436));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/usermanage.png"), QSize(), QIcon::Normal, QIcon::Off);
        UserDialogClass->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(UserDialogClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(UserDialogClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(UserDialogClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(UserDialogClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        idCardEdit = new QLineEdit(UserDialogClass);
        idCardEdit->setObjectName(QString::fromUtf8("idCardEdit"));

        gridLayout->addWidget(idCardEdit, 4, 1, 1, 1);

        idEdit = new QLineEdit(UserDialogClass);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 3);

        passEdit = new QLineEdit(UserDialogClass);
        passEdit->setObjectName(QString::fromUtf8("passEdit"));
        passEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passEdit, 1, 1, 1, 3);

        nameEdit = new QLineEdit(UserDialogClass);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 2, 1, 1, 1);

        label_5 = new QLabel(UserDialogClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(UserDialogClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        sexBox = new QComboBox(UserDialogClass);
        sexBox->setObjectName(QString::fromUtf8("sexBox"));

        gridLayout->addWidget(sexBox, 5, 1, 1, 1);

        label_10 = new QLabel(UserDialogClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        emailEdit = new QLineEdit(UserDialogClass);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));

        gridLayout->addWidget(emailEdit, 6, 1, 1, 1);

        brthBox = new QDateEdit(UserDialogClass);
        brthBox->setObjectName(QString::fromUtf8("brthBox"));
        brthBox->setCalendarPopup(true);

        gridLayout->addWidget(brthBox, 2, 3, 1, 1);

        label_7 = new QLabel(UserDialogClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        phoneEdit = new QLineEdit(UserDialogClass);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 4, 3, 1, 1);

        statusBox = new QComboBox(UserDialogClass);
        statusBox->setObjectName(QString::fromUtf8("statusBox"));

        gridLayout->addWidget(statusBox, 5, 3, 1, 1);

        label_11 = new QLabel(UserDialogClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 5, 2, 1, 1);

        powerBox = new QComboBox(UserDialogClass);
        powerBox->setObjectName(QString::fromUtf8("powerBox"));

        gridLayout->addWidget(powerBox, 6, 3, 1, 1);

        label_9 = new QLabel(UserDialogClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 6, 2, 1, 1);

        confirmBtn = new QPushButton(UserDialogClass);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));

        gridLayout->addWidget(confirmBtn, 0, 4, 1, 1);

        clearBtn = new QPushButton(UserDialogClass);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        gridLayout->addWidget(clearBtn, 1, 4, 1, 1);

        cancelBtn = new QPushButton(UserDialogClass);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 2, 4, 1, 1);

        label_8 = new QLabel(UserDialogClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(UserDialogClass);

        QMetaObject::connectSlotsByName(UserDialogClass);
    } // setupUi

    void retranslateUi(QDialog *UserDialogClass)
    {
        UserDialogClass->setWindowTitle(QApplication::translate("UserDialogClass", "UserDialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserDialogClass", "Password:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UserDialogClass", "ID:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UserDialogClass", "IDCard:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UserDialogClass", "Name:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UserDialogClass", "Sex:", 0, QApplication::UnicodeUTF8));
        sexBox->clear();
        sexBox->insertItems(0, QStringList()
         << QApplication::translate("UserDialogClass", "Male", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserDialogClass", "Female", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("UserDialogClass", "E-Mail", 0, QApplication::UnicodeUTF8));
        brthBox->setDisplayFormat(QApplication::translate("UserDialogClass", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UserDialogClass", "Birthday:", 0, QApplication::UnicodeUTF8));
        statusBox->clear();
        statusBox->insertItems(0, QStringList()
         << QApplication::translate("UserDialogClass", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserDialogClass", "Non-Use", 0, QApplication::UnicodeUTF8)
        );
        label_11->setText(QApplication::translate("UserDialogClass", "Status:", 0, QApplication::UnicodeUTF8));
        powerBox->clear();
        powerBox->insertItems(0, QStringList()
         << QApplication::translate("UserDialogClass", "Administrator", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserDialogClass", "Operator", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("UserDialogClass", "Power:", 0, QApplication::UnicodeUTF8));
        confirmBtn->setText(QApplication::translate("UserDialogClass", "OK", 0, QApplication::UnicodeUTF8));
        clearBtn->setText(QApplication::translate("UserDialogClass", "Clear", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("UserDialogClass", "Cancel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("UserDialogClass", "Phone:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_USERDIALOG_H

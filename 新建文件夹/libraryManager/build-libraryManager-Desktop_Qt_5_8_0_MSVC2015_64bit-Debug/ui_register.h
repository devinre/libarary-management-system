/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *sumBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *logIdLE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *logPwdLE;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *logPwdSure;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *emailLE;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *qqLE;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(634, 416);
        widget = new QWidget(Register);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 290, 251, 61));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        sumBtn = new QPushButton(widget);
        sumBtn->setObjectName(QStringLiteral("sumBtn"));

        horizontalLayout_6->addWidget(sumBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        clearBtn = new QPushButton(widget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        horizontalLayout_6->addWidget(clearBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(widget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout_6->addWidget(exitBtn);

        widget1 = new QWidget(Register);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(180, 40, 181, 241));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        logIdLE = new QLineEdit(widget1);
        logIdLE->setObjectName(QStringLiteral("logIdLE"));

        horizontalLayout->addWidget(logIdLE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        logPwdLE = new QLineEdit(widget1);
        logPwdLE->setObjectName(QStringLiteral("logPwdLE"));

        horizontalLayout_2->addWidget(logPwdLE);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        logPwdSure = new QLineEdit(widget1);
        logPwdSure->setObjectName(QStringLiteral("logPwdSure"));

        horizontalLayout_3->addWidget(logPwdSure);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        emailLE = new QLineEdit(widget1);
        emailLE->setObjectName(QStringLiteral("emailLE"));

        horizontalLayout_4->addWidget(emailLE);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        qqLE = new QLineEdit(widget1);
        qqLE->setObjectName(QStringLiteral("qqLE"));

        horizontalLayout_5->addWidget(qqLE);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        sumBtn->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        clearBtn->setText(QApplication::translate("Register", "\351\207\215\345\241\253", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Register", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\345\270\220\345\217\267\357\274\232    ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201\357\274\232    ", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "Email\357\274\232   ", Q_NULLPTR));
        label_5->setText(QApplication::translate("Register", "Q Q\357\274\232     ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H

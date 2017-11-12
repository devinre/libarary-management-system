/********************************************************************************
** Form generated from reading UI file 'singleadd.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEADD_H
#define UI_SINGLEADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_singleadd
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_bno;
    QLineEdit *lineEdit_category;
    QLineEdit *lineEdit_title;
    QLineEdit *lineEdit_press;
    QLineEdit *lineEdit_year;
    QLineEdit *lineEdit_author;
    QLineEdit *lineEdit_price;
    QLineEdit *lineEdit_number;
    QPushButton *pushButton;

    void setupUi(QWidget *singleadd)
    {
        if (singleadd->objectName().isEmpty())
            singleadd->setObjectName(QStringLiteral("singleadd"));
        singleadd->resize(437, 419);
        horizontalLayoutWidget = new QWidget(singleadd);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 40, 311, 281));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_bno = new QLineEdit(horizontalLayoutWidget);
        lineEdit_bno->setObjectName(QStringLiteral("lineEdit_bno"));

        verticalLayout_2->addWidget(lineEdit_bno);

        lineEdit_category = new QLineEdit(horizontalLayoutWidget);
        lineEdit_category->setObjectName(QStringLiteral("lineEdit_category"));

        verticalLayout_2->addWidget(lineEdit_category);

        lineEdit_title = new QLineEdit(horizontalLayoutWidget);
        lineEdit_title->setObjectName(QStringLiteral("lineEdit_title"));

        verticalLayout_2->addWidget(lineEdit_title);

        lineEdit_press = new QLineEdit(horizontalLayoutWidget);
        lineEdit_press->setObjectName(QStringLiteral("lineEdit_press"));

        verticalLayout_2->addWidget(lineEdit_press);

        lineEdit_year = new QLineEdit(horizontalLayoutWidget);
        lineEdit_year->setObjectName(QStringLiteral("lineEdit_year"));

        verticalLayout_2->addWidget(lineEdit_year);

        lineEdit_author = new QLineEdit(horizontalLayoutWidget);
        lineEdit_author->setObjectName(QStringLiteral("lineEdit_author"));

        verticalLayout_2->addWidget(lineEdit_author);

        lineEdit_price = new QLineEdit(horizontalLayoutWidget);
        lineEdit_price->setObjectName(QStringLiteral("lineEdit_price"));

        verticalLayout_2->addWidget(lineEdit_price);

        lineEdit_number = new QLineEdit(horizontalLayoutWidget);
        lineEdit_number->setObjectName(QStringLiteral("lineEdit_number"));

        verticalLayout_2->addWidget(lineEdit_number);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButton = new QPushButton(singleadd);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 370, 75, 23));

        retranslateUi(singleadd);

        QMetaObject::connectSlotsByName(singleadd);
    } // setupUi

    void retranslateUi(QWidget *singleadd)
    {
        singleadd->setWindowTitle(QApplication::translate("singleadd", "singleadd", Q_NULLPTR));
        label_2->setText(QApplication::translate("singleadd", "\344\271\246\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("singleadd", "\347\261\273\345\210\253", Q_NULLPTR));
        label_3->setText(QApplication::translate("singleadd", "\344\271\246\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("singleadd", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        label_5->setText(QApplication::translate("singleadd", "\345\271\264\344\273\275", Q_NULLPTR));
        label_6->setText(QApplication::translate("singleadd", "\344\275\234\350\200\205", Q_NULLPTR));
        label_7->setText(QApplication::translate("singleadd", "\344\273\267\346\240\274", Q_NULLPTR));
        label_8->setText(QApplication::translate("singleadd", "\346\225\260\351\207\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("singleadd", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class singleadd: public Ui_singleadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEADD_H

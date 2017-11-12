/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidgetClass
{
public:
    QPushButton *showChildButton;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MyWidgetClass)
    {
        if (MyWidgetClass->objectName().isEmpty())
            MyWidgetClass->setObjectName(QStringLiteral("MyWidgetClass"));
        MyWidgetClass->resize(600, 400);
        showChildButton = new QPushButton(MyWidgetClass);
        showChildButton->setObjectName(QStringLiteral("showChildButton"));
        showChildButton->setGeometry(QRect(100, 160, 75, 23));
        label = new QLabel(MyWidgetClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 170, 71, 16));
        pushButton = new QPushButton(MyWidgetClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 230, 75, 23));
        pushButton_2 = new QPushButton(MyWidgetClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 280, 75, 23));

        retranslateUi(MyWidgetClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MyWidgetClass, SLOT(close()));

        QMetaObject::connectSlotsByName(MyWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MyWidgetClass)
    {
        MyWidgetClass->setWindowTitle(QApplication::translate("MyWidgetClass", "MyWidget", Q_NULLPTR));
        showChildButton->setText(QApplication::translate("MyWidgetClass", "\346\230\276\347\244\272\345\255\220\347\252\227\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("MyWidgetClass", "\346\210\221\346\230\257\344\270\273\347\225\214\351\235\242\357\274\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyWidgetClass", "\351\207\215\346\226\260\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MyWidgetClass", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWidgetClass: public Ui_MyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidgetClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QWidget *MyWidgetClass)
    {
        if (MyWidgetClass->objectName().isEmpty())
            MyWidgetClass->setObjectName(QStringLiteral("MyWidgetClass"));
        MyWidgetClass->resize(600, 400);
        pushButton = new QPushButton(MyWidgetClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 110, 75, 23));
        pushButton_2 = new QPushButton(MyWidgetClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 110, 75, 23));
        pushButton_3 = new QPushButton(MyWidgetClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 180, 75, 23));
        pushButton_4 = new QPushButton(MyWidgetClass);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 180, 75, 23));
        pushButton_5 = new QPushButton(MyWidgetClass);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 260, 75, 23));
        pushButton_6 = new QPushButton(MyWidgetClass);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(320, 270, 75, 23));
        pushButton_7 = new QPushButton(MyWidgetClass);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(140, 320, 75, 23));
        pushButton_8 = new QPushButton(MyWidgetClass);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(330, 330, 75, 23));

        retranslateUi(MyWidgetClass);

        QMetaObject::connectSlotsByName(MyWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MyWidgetClass)
    {
        MyWidgetClass->setWindowTitle(QApplication::translate("MyWidgetClass", "MyWidget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyWidgetClass", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MyWidgetClass", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MyWidgetClass", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MyWidgetClass", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MyWidgetClass", "\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MyWidgetClass", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MyWidgetClass", "\351\224\231\350\257\257\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MyWidgetClass", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWidgetClass: public Ui_MyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H

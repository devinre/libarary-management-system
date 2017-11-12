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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidgetClass
{
public:
    QFrame *frame;
    QLabel *label;

    void setupUi(QWidget *MyWidgetClass)
    {
        if (MyWidgetClass->objectName().isEmpty())
            MyWidgetClass->setObjectName(QStringLiteral("MyWidgetClass"));
        MyWidgetClass->resize(600, 400);
        frame = new QFrame(MyWidgetClass);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 120, 80));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(5);
        frame->setMidLineWidth(10);
        label = new QLabel(MyWidgetClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 70, 291, 311));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        retranslateUi(MyWidgetClass);

        QMetaObject::connectSlotsByName(MyWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MyWidgetClass)
    {
        MyWidgetClass->setWindowTitle(QApplication::translate("MyWidgetClass", "MyWidget", Q_NULLPTR));
        label->setText(QApplication::translate("MyWidgetClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWidgetClass: public Ui_MyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H

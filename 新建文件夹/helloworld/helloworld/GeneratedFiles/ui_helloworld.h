/********************************************************************************
** Form generated from reading UI file 'helloworld.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOWORLD_H
#define UI_HELLOWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_helloworldClass
{
public:
    QLabel *label;

    void setupUi(QDialog *helloworldClass)
    {
        if (helloworldClass->objectName().isEmpty())
            helloworldClass->setObjectName(QStringLiteral("helloworldClass"));
        helloworldClass->resize(600, 400);
        label = new QLabel(helloworldClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(103, 120, 121, 20));

        retranslateUi(helloworldClass);

        QMetaObject::connectSlotsByName(helloworldClass);
    } // setupUi

    void retranslateUi(QDialog *helloworldClass)
    {
        helloworldClass->setWindowTitle(QApplication::translate("helloworldClass", "helloworld", Q_NULLPTR));
        label->setText(QApplication::translate("helloworldClass", "Hello World!\344\275\240\345\245\275Qt!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class helloworldClass: public Ui_helloworldClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOWORLD_H

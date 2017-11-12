/********************************************************************************
** Form generated from reading UI file 'librarymanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYMANAGEMENT_H
#define UI_LIBRARYMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_librarymanagementClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QCalendarWidget *calendarWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *librarymanagementClass)
    {
        if (librarymanagementClass->objectName().isEmpty())
            librarymanagementClass->setObjectName(QStringLiteral("librarymanagementClass"));
        librarymanagementClass->resize(600, 400);
        pushButton = new QPushButton(librarymanagementClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 110, 75, 23));
        pushButton_2 = new QPushButton(librarymanagementClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 150, 75, 23));
        pushButton_3 = new QPushButton(librarymanagementClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 200, 75, 23));
        pushButton_5 = new QPushButton(librarymanagementClass);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(380, 280, 75, 23));
        calendarWidget = new QCalendarWidget(librarymanagementClass);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(50, 110, 248, 197));
        label = new QLabel(librarymanagementClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 20, 211, 31));
        label_2 = new QLabel(librarymanagementClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 50, 54, 12));
        label_3 = new QLabel(librarymanagementClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 50, 71, 16));

        retranslateUi(librarymanagementClass);

        QMetaObject::connectSlotsByName(librarymanagementClass);
    } // setupUi

    void retranslateUi(QWidget *librarymanagementClass)
    {
        librarymanagementClass->setWindowTitle(QApplication::translate("librarymanagementClass", "librarymanagement", Q_NULLPTR));
        pushButton->setText(QApplication::translate("librarymanagementClass", "\345\233\276\344\271\246\345\205\245\345\272\223", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("librarymanagementClass", "\345\233\276\344\271\246\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("librarymanagementClass", "\345\200\237/\350\277\230\344\271\246", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("librarymanagementClass", "\345\200\237\344\271\246\350\257\201\347\256\241\347\220\206", Q_NULLPTR));
        label->setText(QApplication::translate("librarymanagementClass", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\254\242\350\277\216\344\275\277\347\224\250\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("librarymanagementClass", "\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("librarymanagementClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class librarymanagementClass: public Ui_librarymanagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYMANAGEMENT_H

/********************************************************************************
** Form generated from reading UI file 'addcard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARD_H
#define UI_ADDCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addcard
{
public:
    QLineEdit *cno;
    QLineEdit *name;
    QLineEdit *department;
    QLineEdit *type;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QWidget *addcard)
    {
        if (addcard->objectName().isEmpty())
            addcard->setObjectName(QStringLiteral("addcard"));
        addcard->resize(400, 300);
        cno = new QLineEdit(addcard);
        cno->setObjectName(QStringLiteral("cno"));
        cno->setGeometry(QRect(160, 40, 113, 20));
        name = new QLineEdit(addcard);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(160, 80, 113, 20));
        department = new QLineEdit(addcard);
        department->setObjectName(QStringLiteral("department"));
        department->setGeometry(QRect(160, 120, 113, 20));
        type = new QLineEdit(addcard);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(160, 160, 113, 20));
        label = new QLabel(addcard);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 51, 21));
        label_2 = new QLabel(addcard);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 80, 51, 16));
        label_3 = new QLabel(addcard);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 120, 41, 21));
        label_4 = new QLabel(addcard);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 160, 51, 16));
        pushButton = new QPushButton(addcard);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 230, 75, 23));

        retranslateUi(addcard);

        QMetaObject::connectSlotsByName(addcard);
    } // setupUi

    void retranslateUi(QWidget *addcard)
    {
        addcard->setWindowTitle(QApplication::translate("addcard", "addcard", Q_NULLPTR));
        label->setText(QApplication::translate("addcard", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("addcard", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("addcard", "\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("addcard", "\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("addcard", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addcard: public Ui_addcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARD_H

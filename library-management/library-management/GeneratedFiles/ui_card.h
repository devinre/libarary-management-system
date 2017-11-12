/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_card
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *deletecno;
    QLabel *label;

    void setupUi(QWidget *card)
    {
        if (card->objectName().isEmpty())
            card->setObjectName(QStringLiteral("card"));
        card->resize(724, 613);
        tableWidget = new QTableWidget(card);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 641, 501));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setRowCount(15);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        pushButton = new QPushButton(card);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 540, 75, 23));
        pushButton_2 = new QPushButton(card);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 540, 75, 23));
        pushButton_3 = new QPushButton(card);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 540, 75, 23));
        pushButton_4 = new QPushButton(card);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 580, 75, 23));
        pushButton_5 = new QPushButton(card);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(400, 540, 75, 23));
        deletecno = new QLineEdit(card);
        deletecno->setObjectName(QStringLiteral("deletecno"));
        deletecno->setGeometry(QRect(160, 580, 113, 20));
        label = new QLabel(card);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 580, 51, 21));

        retranslateUi(card);

        QMetaObject::connectSlotsByName(card);
    } // setupUi

    void retranslateUi(QWidget *card)
    {
        card->setWindowTitle(QApplication::translate("card", "card", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("card", "\345\215\241\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("card", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("card", "\345\215\225\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("card", "\347\261\273\345\210\253\357\274\2101\346\225\231\345\270\210/0\345\255\246\347\224\237\357\274\211", Q_NULLPTR));
        pushButton->setText(QApplication::translate("card", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("card", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("card", "\346\267\273\345\212\240/\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("card", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("card", "\346\230\276\347\244\272", Q_NULLPTR));
        label->setText(QApplication::translate("card", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class card: public Ui_card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H

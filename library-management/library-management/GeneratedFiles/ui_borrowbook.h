/********************************************************************************
** Form generated from reading UI file 'borrowbook.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWBOOK_H
#define UI_BORROWBOOK_H

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

class Ui_borrowbook
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *borrowbook)
    {
        if (borrowbook->objectName().isEmpty())
            borrowbook->setObjectName(QStringLiteral("borrowbook"));
        borrowbook->resize(590, 600);
        label = new QLabel(borrowbook);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 31, 21));
        lineEdit = new QLineEdit(borrowbook);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 113, 20));
        label_2 = new QLabel(borrowbook);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 20, 41, 21));
        lineEdit_2 = new QLineEdit(borrowbook);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(280, 20, 113, 20));
        pushButton = new QPushButton(borrowbook);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 60, 75, 23));
        pushButton_2 = new QPushButton(borrowbook);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 60, 75, 23));
        pushButton_3 = new QPushButton(borrowbook);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 60, 75, 23));
        tableWidget = new QTableWidget(borrowbook);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(50, 100, 531, 481));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setRowCount(15);

        retranslateUi(borrowbook);

        QMetaObject::connectSlotsByName(borrowbook);
    } // setupUi

    void retranslateUi(QWidget *borrowbook)
    {
        borrowbook->setWindowTitle(QApplication::translate("borrowbook", "borrowbook", Q_NULLPTR));
        label->setText(QApplication::translate("borrowbook", "\345\215\241\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("borrowbook", "\344\271\246\345\217\267\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("borrowbook", "\345\267\262\345\200\237\345\233\276\344\271\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("borrowbook", "\345\200\237\344\271\246", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("borrowbook", "\350\277\230\344\271\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("borrowbook", "\345\215\241\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("borrowbook", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("borrowbook", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("borrowbook", "\345\200\237\346\234\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("borrowbook", "\350\277\230\346\234\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class borrowbook: public Ui_borrowbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWBOOK_H

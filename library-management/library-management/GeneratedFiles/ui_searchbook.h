/********************************************************************************
** Form generated from reading UI file 'searchbook.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBOOK_H
#define UI_SEARCHBOOK_H

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

class Ui_searchbook
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *titleline;
    QLineEdit *categoryline;
    QLineEdit *pressline;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *yearline1;
    QLabel *label_5;
    QLineEdit *yearline2;
    QLabel *label_6;
    QLineEdit *authorline;
    QLabel *label_7;
    QLineEdit *priceline1;
    QLabel *label_8;
    QLineEdit *priceline2;
    QTableWidget *tableWidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *searchbook)
    {
        if (searchbook->objectName().isEmpty())
            searchbook->setObjectName(QStringLiteral("searchbook"));
        searchbook->resize(1036, 671);
        pushButton = new QPushButton(searchbook);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 100, 75, 23));
        pushButton_2 = new QPushButton(searchbook);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 100, 75, 23));
        label = new QLabel(searchbook);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 31, 21));
        label_2 = new QLabel(searchbook);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 20, 31, 16));
        titleline = new QLineEdit(searchbook);
        titleline->setObjectName(QStringLiteral("titleline"));
        titleline->setGeometry(QRect(240, 20, 113, 20));
        categoryline = new QLineEdit(searchbook);
        categoryline->setObjectName(QStringLiteral("categoryline"));
        categoryline->setGeometry(QRect(70, 20, 113, 20));
        pressline = new QLineEdit(searchbook);
        pressline->setObjectName(QStringLiteral("pressline"));
        pressline->setGeometry(QRect(440, 20, 113, 20));
        label_3 = new QLabel(searchbook);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(390, 20, 51, 21));
        label_4 = new QLabel(searchbook);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 60, 31, 21));
        yearline1 = new QLineEdit(searchbook);
        yearline1->setObjectName(QStringLiteral("yearline1"));
        yearline1->setGeometry(QRect(70, 60, 113, 20));
        label_5 = new QLabel(searchbook);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 60, 21, 16));
        yearline2 = new QLineEdit(searchbook);
        yearline2->setObjectName(QStringLiteral("yearline2"));
        yearline2->setGeometry(QRect(240, 60, 113, 20));
        label_6 = new QLabel(searchbook);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(390, 60, 31, 21));
        authorline = new QLineEdit(searchbook);
        authorline->setObjectName(QStringLiteral("authorline"));
        authorline->setGeometry(QRect(440, 60, 113, 20));
        label_7 = new QLabel(searchbook);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 100, 31, 16));
        priceline1 = new QLineEdit(searchbook);
        priceline1->setObjectName(QStringLiteral("priceline1"));
        priceline1->setGeometry(QRect(70, 100, 113, 20));
        label_8 = new QLabel(searchbook);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 100, 21, 16));
        priceline2 = new QLineEdit(searchbook);
        priceline2->setObjectName(QStringLiteral("priceline2"));
        priceline2->setGeometry(QRect(240, 100, 113, 20));
        tableWidget = new QTableWidget(searchbook);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(60, 130, 931, 501));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setRowCount(15);
        pushButton_3 = new QPushButton(searchbook);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 640, 75, 23));
        pushButton_4 = new QPushButton(searchbook);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(170, 640, 75, 23));

        retranslateUi(searchbook);

        QMetaObject::connectSlotsByName(searchbook);
    } // setupUi

    void retranslateUi(QWidget *searchbook)
    {
        searchbook->setWindowTitle(QApplication::translate("searchbook", "searchbook", Q_NULLPTR));
        pushButton->setText(QApplication::translate("searchbook", "\346\220\234\347\264\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("searchbook", "\346\270\205\347\251\272", Q_NULLPTR));
        label->setText(QApplication::translate("searchbook", "\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("searchbook", "\344\271\246\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("searchbook", "\345\207\272\347\211\210\347\244\276\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("searchbook", "\345\271\264\344\273\275\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("searchbook", "--", Q_NULLPTR));
        label_6->setText(QApplication::translate("searchbook", "\344\275\234\350\200\205\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("searchbook", "\344\273\267\346\240\274\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("searchbook", "--", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("searchbook", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("searchbook", "\347\261\273\345\210\253", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("searchbook", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("searchbook", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("searchbook", "\345\271\264\344\273\275", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("searchbook", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("searchbook", "\344\273\267\346\240\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("searchbook", "\346\200\273\350\227\217\344\271\246\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("searchbook", "\345\272\223\345\255\230", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("searchbook", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("searchbook", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class searchbook: public Ui_searchbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBOOK_H

/********************************************************************************
** Form generated from reading UI file 'bookl.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKL_H
#define UI_BOOKL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_bookl
{
public:
    QLabel *label;
    QLineEdit *book_id;
    QLabel *label_2;
    QLineEdit *user_id;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *okbutton;
    QPushButton *update;
    QPushButton *exit;
    QPushButton *lastpage;
    QPushButton *nextpage;
    QLabel *label_3;
    QLabel *now;
    QLabel *label_5;
    QLabel *total;
    QLabel *label_7;
    QPushButton *begin;
    QPushButton *end;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *time;
    QTableWidget *table;
    QLabel *label_4;

    void setupUi(QDialog *bookl)
    {
        if (bookl->objectName().isEmpty())
            bookl->setObjectName(QStringLiteral("bookl"));
        bookl->resize(721, 471);
        bookl->setMinimumSize(QSize(721, 471));
        bookl->setMaximumSize(QSize(721, 471));
        bookl->setModal(true);
        label = new QLabel(bookl);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 54, 20));
        book_id = new QLineEdit(bookl);
        book_id->setObjectName(QStringLiteral("book_id"));
        book_id->setGeometry(QRect(80, 70, 113, 21));
        label_2 = new QLabel(bookl);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 70, 54, 21));
        user_id = new QLineEdit(bookl);
        user_id->setObjectName(QStringLiteral("user_id"));
        user_id->setGeometry(QRect(300, 70, 113, 21));
        checkBox = new QCheckBox(bookl);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(430, 70, 71, 21));
        checkBox_2 = new QCheckBox(bookl);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(490, 70, 71, 21));
        okbutton = new QPushButton(bookl);
        okbutton->setObjectName(QStringLiteral("okbutton"));
        okbutton->setGeometry(QRect(560, 70, 75, 23));
        update = new QPushButton(bookl);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(470, 180, 41, 161));
        exit = new QPushButton(bookl);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(670, 10, 20, 20));
        exit->setMinimumSize(QSize(20, 20));
        exit->setMaximumSize(QSize(20, 20));
        exit->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        lastpage = new QPushButton(bookl);
        lastpage->setObjectName(QStringLiteral("lastpage"));
        lastpage->setGeometry(QRect(580, 180, 75, 23));
        nextpage = new QPushButton(bookl);
        nextpage->setObjectName(QStringLiteral("nextpage"));
        nextpage->setGeometry(QRect(580, 260, 75, 23));
        label_3 = new QLabel(bookl);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(580, 220, 16, 21));
        now = new QLabel(bookl);
        now->setObjectName(QStringLiteral("now"));
        now->setGeometry(QRect(600, 220, 16, 21));
        label_5 = new QLabel(bookl);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(610, 220, 16, 21));
        total = new QLabel(bookl);
        total->setObjectName(QStringLiteral("total"));
        total->setGeometry(QRect(620, 220, 20, 21));
        label_7 = new QLabel(bookl);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(640, 220, 21, 21));
        begin = new QPushButton(bookl);
        begin->setObjectName(QStringLiteral("begin"));
        begin->setGeometry(QRect(580, 140, 75, 23));
        end = new QPushButton(bookl);
        end->setObjectName(QStringLiteral("end"));
        end->setGeometry(QRect(580, 310, 75, 23));
        frame = new QFrame(bookl);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 721, 471));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/bookl.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 45, 45));
        frame_2->setMinimumSize(QSize(45, 45));
        frame_2->setMaximumSize(QSize(45, 45));
        frame_2->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/lms.ico);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        time = new QLabel(bookl);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(540, 20, 81, 21));
        table = new QTableWidget(bookl);
        if (table->columnCount() < 4)
            table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (table->rowCount() < 10)
            table->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table->setVerticalHeaderItem(8, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table->setVerticalHeaderItem(9, __qtablewidgetitem13);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(20, 100, 511, 341));
        label_4 = new QLabel(bookl);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(490, 20, 54, 21));
        frame->raise();
        table->raise();
        label->raise();
        book_id->raise();
        label_2->raise();
        user_id->raise();
        checkBox->raise();
        checkBox_2->raise();
        okbutton->raise();
        update->raise();
        exit->raise();
        lastpage->raise();
        nextpage->raise();
        label_3->raise();
        now->raise();
        label_5->raise();
        total->raise();
        label_7->raise();
        begin->raise();
        end->raise();
        time->raise();
        label_4->raise();
        QWidget::setTabOrder(book_id, user_id);
        QWidget::setTabOrder(user_id, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, okbutton);
        QWidget::setTabOrder(okbutton, table);
        QWidget::setTabOrder(table, update);
        QWidget::setTabOrder(update, exit);

        retranslateUi(bookl);

        QMetaObject::connectSlotsByName(bookl);
    } // setupUi

    void retranslateUi(QDialog *bookl)
    {
        bookl->setWindowTitle(QApplication::translate("bookl", "\344\271\246\347\261\215\345\200\237\351\230\205\347\256\241\347\220\206", Q_NULLPTR));
        label->setText(QApplication::translate("bookl", "\344\271\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("bookl", "\345\200\237\351\230\205\350\200\205id", Q_NULLPTR));
        checkBox->setText(QApplication::translate("bookl", "\345\200\237\351\230\205", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("bookl", "\345\275\222\350\277\230", Q_NULLPTR));
        okbutton->setText(QApplication::translate("bookl", "\347\241\256\345\256\232", Q_NULLPTR));
        update->setText(QApplication::translate("bookl", "\345\210\267\346\226\260", Q_NULLPTR));
        exit->setText(QString());
        lastpage->setText(QApplication::translate("bookl", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        nextpage->setText(QApplication::translate("bookl", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        label_3->setText(QApplication::translate("bookl", "\345\205\261", Q_NULLPTR));
        now->setText(QApplication::translate("bookl", "1", Q_NULLPTR));
        label_5->setText(QApplication::translate("bookl", "/", Q_NULLPTR));
        total->setText(QApplication::translate("bookl", "10", Q_NULLPTR));
        label_7->setText(QApplication::translate("bookl", "\351\241\265", Q_NULLPTR));
        begin->setText(QApplication::translate("bookl", "\351\246\226\351\241\265", Q_NULLPTR));
        end->setText(QApplication::translate("bookl", "\345\260\276\351\241\265", Q_NULLPTR));
        time->setText(QApplication::translate("bookl", "TextLabel", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("bookl", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("bookl", "\345\200\237\351\230\205\350\200\205id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("bookl", "\345\200\237\351\230\205\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("bookl", "\345\200\237\351\230\205\346\210\252\346\255\242\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = table->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("bookl", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = table->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("bookl", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = table->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("bookl", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = table->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("bookl", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = table->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("bookl", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = table->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("bookl", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = table->verticalHeaderItem(6);
        ___qtablewidgetitem10->setText(QApplication::translate("bookl", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = table->verticalHeaderItem(7);
        ___qtablewidgetitem11->setText(QApplication::translate("bookl", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = table->verticalHeaderItem(8);
        ___qtablewidgetitem12->setText(QApplication::translate("bookl", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = table->verticalHeaderItem(9);
        ___qtablewidgetitem13->setText(QApplication::translate("bookl", "10", Q_NULLPTR));
        label_4->setText(QApplication::translate("bookl", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class bookl: public Ui_bookl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKL_H

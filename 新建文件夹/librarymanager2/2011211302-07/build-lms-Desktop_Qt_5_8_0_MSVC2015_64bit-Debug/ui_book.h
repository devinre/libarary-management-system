/********************************************************************************
** Form generated from reading UI file 'book.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_H
#define UI_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_book
{
public:
    QLabel *label;
    QLineEdit *book_id;
    QLabel *label_2;
    QLineEdit *book_name;
    QLineEdit *book_author;
    QLabel *label_3;
    QLineEdit *book_press;
    QLabel *label_5;
    QPushButton *add;
    QLabel *label_6;
    QSpinBox *book_all;
    QLabel *label_7;
    QLineEdit *deleteid;
    QPushButton *pushButton_2;
    QTableWidget *table;
    QPushButton *delete_2;
    QPushButton *freshen;
    QPushButton *nextpage;
    QPushButton *lastpage;
    QLabel *label_4;
    QLabel *now;
    QLabel *label_9;
    QLabel *total;
    QLabel *label_11;
    QPushButton *end;
    QPushButton *begin;
    QFrame *line;
    QFrame *line_2;
    QComboBox *kind;
    QLineEdit *seekline;
    QPushButton *seek;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *time;
    QFrame *frame;
    QPushButton *bexit;
    QFrame *frame_2;

    void setupUi(QDialog *book)
    {
        if (book->objectName().isEmpty())
            book->setObjectName(QStringLiteral("book"));
        book->resize(891, 472);
        book->setMinimumSize(QSize(891, 472));
        book->setMaximumSize(QSize(891, 472));
        book->setModal(true);
        label = new QLabel(book);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 110, 51, 16));
        book_id = new QLineEdit(book);
        book_id->setObjectName(QStringLiteral("book_id"));
        book_id->setGeometry(QRect(60, 110, 101, 21));
        label_2 = new QLabel(book);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 54, 12));
        book_name = new QLineEdit(book);
        book_name->setObjectName(QStringLiteral("book_name"));
        book_name->setGeometry(QRect(60, 150, 101, 21));
        book_author = new QLineEdit(book);
        book_author->setObjectName(QStringLiteral("book_author"));
        book_author->setGeometry(QRect(60, 190, 101, 21));
        label_3 = new QLabel(book);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 230, 54, 12));
        book_press = new QLineEdit(book);
        book_press->setObjectName(QStringLiteral("book_press"));
        book_press->setGeometry(QRect(60, 230, 101, 21));
        label_5 = new QLabel(book);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 270, 54, 12));
        add = new QPushButton(book);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(10, 310, 75, 23));
        label_6 = new QLabel(book);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 190, 54, 12));
        book_all = new QSpinBox(book);
        book_all->setObjectName(QStringLiteral("book_all"));
        book_all->setGeometry(QRect(60, 270, 101, 22));
        label_7 = new QLabel(book);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 400, 54, 21));
        deleteid = new QLineEdit(book);
        deleteid->setObjectName(QStringLiteral("deleteid"));
        deleteid->setGeometry(QRect(60, 400, 101, 21));
        pushButton_2 = new QPushButton(book);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 310, 75, 23));
        table = new QTableWidget(book);
        if (table->columnCount() < 6)
            table->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (table->rowCount() < 10)
            table->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table->setVerticalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table->setVerticalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table->setVerticalHeaderItem(8, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table->setVerticalHeaderItem(9, __qtablewidgetitem15);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(210, 80, 651, 341));
        delete_2 = new QPushButton(book);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        delete_2->setGeometry(QRect(50, 430, 81, 23));
        freshen = new QPushButton(book);
        freshen->setObjectName(QStringLiteral("freshen"));
        freshen->setGeometry(QRect(690, 430, 75, 23));
        nextpage = new QPushButton(book);
        nextpage->setObjectName(QStringLiteral("nextpage"));
        nextpage->setGeometry(QRect(480, 430, 75, 23));
        lastpage = new QPushButton(book);
        lastpage->setObjectName(QStringLiteral("lastpage"));
        lastpage->setGeometry(QRect(320, 430, 75, 23));
        label_4 = new QLabel(book);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 430, 21, 20));
        now = new QLabel(book);
        now->setObjectName(QStringLiteral("now"));
        now->setGeometry(QRect(420, 430, 16, 21));
        label_9 = new QLabel(book);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(430, 430, 21, 21));
        total = new QLabel(book);
        total->setObjectName(QStringLiteral("total"));
        total->setGeometry(QRect(440, 430, 20, 21));
        label_11 = new QLabel(book);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(460, 430, 16, 21));
        end = new QPushButton(book);
        end->setObjectName(QStringLiteral("end"));
        end->setGeometry(QRect(560, 430, 75, 23));
        begin = new QPushButton(book);
        begin->setObjectName(QStringLiteral("begin"));
        begin->setGeometry(QRect(240, 430, 75, 23));
        line = new QFrame(book);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 340, 181, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(book);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(170, 50, 31, 421));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        kind = new QComboBox(book);
        kind->setObjectName(QStringLiteral("kind"));
        kind->setGeometry(QRect(418, 50, 101, 22));
        seekline = new QLineEdit(book);
        seekline->setObjectName(QStringLiteral("seekline"));
        seekline->setGeometry(QRect(530, 49, 113, 21));
        seek = new QPushButton(book);
        seek->setObjectName(QStringLiteral("seek"));
        seek->setGeometry(QRect(660, 50, 75, 23));
        label_8 = new QLabel(book);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 60, 171, 31));
        label_10 = new QLabel(book);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 360, 121, 21));
        label_12 = new QLabel(book);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(220, 50, 151, 21));
        label_13 = new QLabel(book);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(330, 10, 54, 21));
        time = new QLabel(book);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(370, 10, 81, 21));
        frame = new QFrame(book);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 891, 471));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/book.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        bexit = new QPushButton(frame);
        bexit->setObjectName(QStringLiteral("bexit"));
        bexit->setGeometry(QRect(840, 10, 20, 20));
        bexit->setMinimumSize(QSize(20, 20));
        bexit->setMaximumSize(QSize(20, 20));
        bexit->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 45, 45));
        frame_2->setMinimumSize(QSize(45, 45));
        frame_2->setMaximumSize(QSize(45, 45));
        frame_2->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/lms.ico);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame->raise();
        label->raise();
        book_id->raise();
        label_2->raise();
        book_name->raise();
        book_author->raise();
        label_3->raise();
        book_press->raise();
        label_5->raise();
        add->raise();
        label_6->raise();
        book_all->raise();
        label_7->raise();
        deleteid->raise();
        pushButton_2->raise();
        table->raise();
        delete_2->raise();
        freshen->raise();
        nextpage->raise();
        lastpage->raise();
        label_4->raise();
        now->raise();
        label_9->raise();
        total->raise();
        label_11->raise();
        end->raise();
        begin->raise();
        line->raise();
        line_2->raise();
        kind->raise();
        seekline->raise();
        seek->raise();
        label_8->raise();
        label_10->raise();
        label_12->raise();
        label_13->raise();
        time->raise();
        QWidget::setTabOrder(book_id, book_name);
        QWidget::setTabOrder(book_name, book_author);
        QWidget::setTabOrder(book_author, book_press);
        QWidget::setTabOrder(book_press, book_all);
        QWidget::setTabOrder(book_all, deleteid);
        QWidget::setTabOrder(deleteid, add);
        QWidget::setTabOrder(add, pushButton_2);
        QWidget::setTabOrder(pushButton_2, table);
        QWidget::setTabOrder(table, delete_2);
        QWidget::setTabOrder(delete_2, freshen);
        QWidget::setTabOrder(freshen, bexit);

        retranslateUi(book);

        QMetaObject::connectSlotsByName(book);
    } // setupUi

    void retranslateUi(QDialog *book)
    {
        book->setWindowTitle(QApplication::translate("book", "\346\237\245\350\257\242\344\277\256\346\224\271\346\233\264\346\226\260\344\271\246\347\233\256", Q_NULLPTR));
        label->setText(QApplication::translate("book", "\344\271\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("book", "\344\271\246\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("book", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        label_5->setText(QApplication::translate("book", "\350\227\217\344\271\246\351\207\217", Q_NULLPTR));
        add->setText(QApplication::translate("book", "\346\267\273\345\212\240\344\271\246\347\233\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("book", "\344\275\234\350\200\205", Q_NULLPTR));
        label_7->setText(QApplication::translate("book", "\344\271\246\345\217\267", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("book", "\346\233\264\346\226\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("book", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("book", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("book", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("book", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("book", "\346\200\273\345\255\230\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("book", "\345\211\251\344\275\231\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = table->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("book", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = table->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("book", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = table->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("book", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = table->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("book", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = table->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("book", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = table->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("book", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = table->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("book", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = table->verticalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("book", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = table->verticalHeaderItem(8);
        ___qtablewidgetitem14->setText(QApplication::translate("book", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = table->verticalHeaderItem(9);
        ___qtablewidgetitem15->setText(QApplication::translate("book", "10", Q_NULLPTR));
        delete_2->setText(QApplication::translate("book", "\345\210\240\351\231\244", Q_NULLPTR));
        freshen->setText(QApplication::translate("book", "\345\210\267\346\226\260", Q_NULLPTR));
        nextpage->setText(QApplication::translate("book", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        lastpage->setText(QApplication::translate("book", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        label_4->setText(QApplication::translate("book", "\345\205\261", Q_NULLPTR));
        now->setText(QApplication::translate("book", "1", Q_NULLPTR));
        label_9->setText(QApplication::translate("book", "/", Q_NULLPTR));
        total->setText(QApplication::translate("book", "10", Q_NULLPTR));
        label_11->setText(QApplication::translate("book", "\351\241\265", Q_NULLPTR));
        end->setText(QApplication::translate("book", "\345\260\276\351\241\265", Q_NULLPTR));
        begin->setText(QApplication::translate("book", "\351\246\226\351\241\265", Q_NULLPTR));
        kind->clear();
        kind->insertItems(0, QStringList()
         << QApplication::translate("book", "book's id", Q_NULLPTR)
         << QApplication::translate("book", "name", Q_NULLPTR)
         << QApplication::translate("book", "author", Q_NULLPTR)
         << QApplication::translate("book", "book concern", Q_NULLPTR)
        );
        seek->setText(QApplication::translate("book", "\346\237\245\346\211\276", Q_NULLPTR));
        label_8->setText(QApplication::translate("book", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\267\273\345\212\240\345\222\214\346\233\264\346\224\271\344\271\246\347\233\256\344\277\241\346\201\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("book", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\210\240\351\231\244\344\271\246\347\261\215\344\277\241\346\201\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("book", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\211\200\346\234\211\344\271\246\347\261\215\344\277\241\346\201\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("book", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        time->setText(QApplication::translate("book", "TextLabel", Q_NULLPTR));
        bexit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class book: public Ui_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_H

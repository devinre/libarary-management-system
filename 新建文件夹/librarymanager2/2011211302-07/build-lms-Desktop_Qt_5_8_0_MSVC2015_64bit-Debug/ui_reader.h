/********************************************************************************
** Form generated from reading UI file 'reader.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READER_H
#define UI_READER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_reader
{
public:
    QTableWidget *table1;
    QTableWidget *table2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *now1;
    QLabel *label_6;
    QLabel *total1;
    QLabel *label_8;
    QPushButton *lastpage1;
    QPushButton *nextpage1;
    QLabel *label_5;
    QLabel *num;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_9;
    QLineEdit *seekline;
    QPushButton *seek;
    QPushButton *pushButton_2;
    QPushButton *reinput;
    QPushButton *pushButton_4;
    QTextEdit *message;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *time;
    QFrame *frame;
    QPushButton *rexit;
    QFrame *frame_2;
    QPushButton *rpc;

    void setupUi(QDialog *reader)
    {
        if (reader->objectName().isEmpty())
            reader->setObjectName(QStringLiteral("reader"));
        reader->resize(972, 476);
        reader->setMinimumSize(QSize(972, 476));
        reader->setMaximumSize(QSize(972, 476));
        table1 = new QTableWidget(reader);
        if (table1->columnCount() < 5)
            table1->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (table1->rowCount() < 10)
            table1->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(8, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table1->setVerticalHeaderItem(9, __qtablewidgetitem14);
        table1->setObjectName(QStringLiteral("table1"));
        table1->setGeometry(QRect(17, 100, 561, 331));
        table2 = new QTableWidget(reader);
        if (table2->columnCount() < 3)
            table2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        if (table2->rowCount() < 3)
            table2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table2->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table2->setVerticalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        table2->setVerticalHeaderItem(2, __qtablewidgetitem20);
        table2->setObjectName(QStringLiteral("table2"));
        table2->setGeometry(QRect(597, 100, 361, 141));
        label_2 = new QLabel(reader);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 160, 21, 201));
        label_3 = new QLabel(reader);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(707, 220, 91, 21));
        label_4 = new QLabel(reader);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 435, 21, 21));
        now1 = new QLabel(reader);
        now1->setObjectName(QStringLiteral("now1"));
        now1->setGeometry(QRect(220, 435, 20, 21));
        label_6 = new QLabel(reader);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 430, 20, 31));
        total1 = new QLabel(reader);
        total1->setObjectName(QStringLiteral("total1"));
        total1->setGeometry(QRect(240, 430, 20, 31));
        label_8 = new QLabel(reader);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(260, 440, 54, 12));
        lastpage1 = new QPushButton(reader);
        lastpage1->setObjectName(QStringLiteral("lastpage1"));
        lastpage1->setGeometry(QRect(110, 430, 75, 23));
        nextpage1 = new QPushButton(reader);
        nextpage1->setObjectName(QStringLiteral("nextpage1"));
        nextpage1->setGeometry(QRect(290, 430, 75, 23));
        label_5 = new QLabel(reader);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(607, 251, 54, 21));
        num = new QLabel(reader);
        num->setObjectName(QStringLiteral("num"));
        num->setGeometry(QRect(657, 250, 54, 20));
        label_7 = new QLabel(reader);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(607, 280, 241, 21));
        pushButton = new QPushButton(reader);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(877, 280, 75, 23));
        label_9 = new QLabel(reader);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 70, 54, 21));
        seekline = new QLineEdit(reader);
        seekline->setObjectName(QStringLiteral("seekline"));
        seekline->setGeometry(QRect(270, 70, 113, 21));
        seek = new QPushButton(reader);
        seek->setObjectName(QStringLiteral("seek"));
        seek->setGeometry(QRect(400, 70, 75, 23));
        pushButton_2 = new QPushButton(reader);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(857, 410, 101, 23));
        pushButton_2->setStyleSheet(QStringLiteral("selection-background-color: rgba(255, 255, 255, 0);"));
        reinput = new QPushButton(reader);
        reinput->setObjectName(QStringLiteral("reinput"));
        reinput->setGeometry(QRect(697, 410, 75, 23));
        pushButton_4 = new QPushButton(reader);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(777, 410, 75, 23));
        message = new QTextEdit(reader);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(597, 320, 361, 81));
        label_10 = new QLabel(reader);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(880, 380, 71, 20));
        label_11 = new QLabel(reader);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(760, 11, 54, 21));
        time = new QLabel(reader);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(800, 10, 81, 21));
        frame = new QFrame(reader);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 971, 481));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/reader.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        rexit = new QPushButton(frame);
        rexit->setObjectName(QStringLiteral("rexit"));
        rexit->setGeometry(QRect(920, 10, 20, 20));
        rexit->setMinimumSize(QSize(20, 20));
        rexit->setMaximumSize(QSize(20, 20));
        rexit->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 45, 45));
        frame_2->setMinimumSize(QSize(45, 45));
        frame_2->setMaximumSize(QSize(45, 45));
        frame_2->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/lms.ico);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        rpc = new QPushButton(reader);
        rpc->setObjectName(QStringLiteral("rpc"));
        rpc->setGeometry(QRect(20, 60, 91, 31));
        rpc->setStyleSheet(QStringLiteral(""));
        frame->raise();
        table1->raise();
        table2->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        now1->raise();
        label_6->raise();
        total1->raise();
        label_8->raise();
        lastpage1->raise();
        nextpage1->raise();
        label_5->raise();
        num->raise();
        label_7->raise();
        pushButton->raise();
        label_9->raise();
        seekline->raise();
        seek->raise();
        pushButton_2->raise();
        reinput->raise();
        pushButton_4->raise();
        message->raise();
        label_10->raise();
        label_11->raise();
        time->raise();
        rpc->raise();

        retranslateUi(reader);

        QMetaObject::connectSlotsByName(reader);
    } // setupUi

    void retranslateUi(QDialog *reader)
    {
        reader->setWindowTitle(QApplication::translate("reader", "\350\257\273\350\200\205\347\225\214\351\235\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("reader", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("reader", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("reader", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("reader", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = table1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("reader", "\345\211\251\344\275\231\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = table1->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("reader", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = table1->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("reader", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = table1->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("reader", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = table1->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("reader", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = table1->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("reader", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = table1->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("reader", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = table1->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("reader", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = table1->verticalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("reader", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = table1->verticalHeaderItem(8);
        ___qtablewidgetitem13->setText(QApplication::translate("reader", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = table1->verticalHeaderItem(9);
        ___qtablewidgetitem14->setText(QApplication::translate("reader", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = table2->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("reader", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = table2->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("reader", "\345\200\237\351\230\205\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = table2->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("reader", "\345\272\224\345\275\222\350\277\230\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = table2->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("reader", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = table2->verticalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("reader", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = table2->verticalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("reader", "3", Q_NULLPTR));
        label_2->setText(QApplication::translate("reader", "<html><head/><body><p><span style=\" font-weight:600;\">\346\211\200</span></p><p><span style=\" font-weight:600;\">\346\234\211</span></p><p><span style=\" font-weight:600;\">\344\271\246</span></p><p><span style=\" font-weight:600;\">\347\261\215</span></p><p><span style=\" font-weight:600;\">\344\277\241</span></p><p><span style=\" font-weight:600;\">\346\201\257</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("reader", "<html><head/><body><p><span style=\" font-weight:600;\">\344\271\246\347\261\215\345\200\237\351\230\205\344\277\241\346\201\257</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("reader", "\345\205\261", Q_NULLPTR));
        now1->setText(QApplication::translate("reader", "1", Q_NULLPTR));
        label_6->setText(QApplication::translate("reader", "/", Q_NULLPTR));
        total1->setText(QApplication::translate("reader", "10", Q_NULLPTR));
        label_8->setText(QApplication::translate("reader", "\351\241\265", Q_NULLPTR));
        lastpage1->setText(QApplication::translate("reader", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        nextpage1->setText(QApplication::translate("reader", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        label_5->setText(QApplication::translate("reader", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\346\202\250\346\234\211</span></p></body></html>", Q_NULLPTR));
        num->setText(QApplication::translate("reader", "<html><head/><body><p><span style=\" color:#020000;\">0</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("reader", "<html><head/><body><p><span style=\" font-weight:600;\">\346\234\254\344\271\246\347\261\215\351\234\200\350\246\201\345\275\222\350\277\230\357\274\214\350\257\267\345\260\275\345\277\253\345\210\260\347\256\241\347\220\206\345\221\230\345\244\204\345\275\222\350\277\230\357\274\201</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("reader", "\346\230\276\347\244\272", Q_NULLPTR));
        label_9->setText(QApplication::translate("reader", "<html><head/><body><p><span style=\" font-weight:600;\">\345\205\263\351\224\256\345\255\227</span></p></body></html>", Q_NULLPTR));
        seek->setText(QApplication::translate("reader", "\346\237\245\346\211\276", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("reader", "\347\273\231\347\256\241\347\220\206\345\221\230\347\225\231\350\250\200", Q_NULLPTR));
        reinput->setText(QApplication::translate("reader", "\351\207\215\346\226\260\350\276\223\345\205\245", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("reader", "\344\277\256\346\224\271\347\225\231\350\250\200", Q_NULLPTR));
        label_10->setText(QApplication::translate("reader", "\344\270\215\345\244\232\344\272\21650\345\255\227", Q_NULLPTR));
        label_11->setText(QApplication::translate("reader", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        time->setText(QApplication::translate("reader", "TextLabel", Q_NULLPTR));
        rexit->setText(QString());
        rpc->setText(QApplication::translate("reader", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class reader: public Ui_reader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READER_H

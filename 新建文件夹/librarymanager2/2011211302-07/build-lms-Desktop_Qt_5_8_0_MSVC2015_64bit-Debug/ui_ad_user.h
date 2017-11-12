/********************************************************************************
** Form generated from reading UI file 'ad_user.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AD_USER_H
#define UI_AD_USER_H

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

class Ui_ad_user
{
public:
    QLabel *label;
    QLineEdit *id;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *okButton;
    QLineEdit *deleteid;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *deletemessage;
    QPushButton *exit;
    QLabel *label_4;
    QLabel *now;
    QLabel *label_6;
    QLabel *total;
    QLabel *label_8;
    QPushButton *lastpage;
    QPushButton *nextpage;
    QPushButton *update;
    QTableWidget *message;
    QPushButton *nextpagem;
    QPushButton *lsatpagem;
    QLabel *nowm;
    QLabel *label_7;
    QLabel *totalm;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *time;
    QTableWidget *table;
    QFrame *frame;
    QFrame *frame_2;
    QPushButton *deleteall;

    void setupUi(QDialog *ad_user)
    {
        if (ad_user->objectName().isEmpty())
            ad_user->setObjectName(QStringLiteral("ad_user"));
        ad_user->resize(874, 490);
        ad_user->setMinimumSize(QSize(874, 490));
        ad_user->setMaximumSize(QSize(874, 490));
        ad_user->setModal(true);
        label = new QLabel(ad_user);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 140, 41, 16));
        id = new QLineEdit(ad_user);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(520, 140, 91, 21));
        checkBox = new QCheckBox(ad_user);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(620, 120, 111, 16));
        checkBox_2 = new QCheckBox(ad_user);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(620, 140, 111, 16));
        checkBox_3 = new QCheckBox(ad_user);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(620, 160, 71, 16));
        okButton = new QPushButton(ad_user);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(760, 140, 75, 23));
        deleteid = new QLineEdit(ad_user);
        deleteid->setObjectName(QStringLiteral("deleteid"));
        deleteid->setGeometry(QRect(530, 440, 81, 21));
        label_2 = new QLabel(ad_user);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 440, 51, 21));
        label_3 = new QLabel(ad_user);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(620, 440, 41, 21));
        deletemessage = new QPushButton(ad_user);
        deletemessage->setObjectName(QStringLiteral("deletemessage"));
        deletemessage->setGeometry(QRect(660, 440, 75, 23));
        exit = new QPushButton(ad_user);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(840, 10, 20, 20));
        exit->setMinimumSize(QSize(20, 20));
        exit->setMaximumSize(QSize(20, 20));
        exit->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        label_4 = new QLabel(ad_user);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 450, 16, 31));
        now = new QLabel(ad_user);
        now->setObjectName(QStringLiteral("now"));
        now->setGeometry(QRect(140, 455, 20, 21));
        label_6 = new QLabel(ad_user);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 450, 20, 31));
        total = new QLabel(ad_user);
        total->setObjectName(QStringLiteral("total"));
        total->setGeometry(QRect(160, 450, 20, 31));
        label_8 = new QLabel(ad_user);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 450, 16, 31));
        lastpage = new QPushButton(ad_user);
        lastpage->setObjectName(QStringLiteral("lastpage"));
        lastpage->setGeometry(QRect(30, 450, 75, 23));
        nextpage = new QPushButton(ad_user);
        nextpage->setObjectName(QStringLiteral("nextpage"));
        nextpage->setGeometry(QRect(210, 450, 75, 23));
        update = new QPushButton(ad_user);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(300, 450, 75, 23));
        message = new QTableWidget(ad_user);
        if (message->columnCount() < 1)
            message->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        message->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (message->rowCount() < 5)
            message->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        message->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        message->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        message->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        message->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        message->setVerticalHeaderItem(4, __qtablewidgetitem5);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(460, 220, 391, 181));
        message->horizontalHeader()->setCascadingSectionResizes(false);
        message->horizontalHeader()->setDefaultSectionSize(400);
        nextpagem = new QPushButton(ad_user);
        nextpagem->setObjectName(QStringLiteral("nextpagem"));
        nextpagem->setGeometry(QRect(710, 410, 75, 23));
        lsatpagem = new QPushButton(ad_user);
        lsatpagem->setObjectName(QStringLiteral("lsatpagem"));
        lsatpagem->setGeometry(QRect(550, 410, 75, 23));
        nowm = new QLabel(ad_user);
        nowm->setObjectName(QStringLiteral("nowm"));
        nowm->setGeometry(QRect(650, 410, 16, 21));
        label_7 = new QLabel(ad_user);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(660, 410, 20, 21));
        totalm = new QLabel(ad_user);
        totalm->setObjectName(QStringLiteral("totalm"));
        totalm->setGeometry(QRect(670, 410, 20, 21));
        label_5 = new QLabel(ad_user);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(460, 190, 131, 20));
        label_9 = new QLabel(ad_user);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 101, 41));
        label_10 = new QLabel(ad_user);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(460, 70, 111, 21));
        label_11 = new QLabel(ad_user);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(650, 70, 54, 21));
        time = new QLabel(ad_user);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(690, 70, 81, 21));
        table = new QTableWidget(ad_user);
        if (table->columnCount() < 4)
            table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        if (table->rowCount() < 10)
            table->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table->setVerticalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table->setVerticalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table->setVerticalHeaderItem(6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table->setVerticalHeaderItem(7, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table->setVerticalHeaderItem(8, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table->setVerticalHeaderItem(9, __qtablewidgetitem19);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(10, 110, 431, 341));
        frame = new QFrame(ad_user);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 871, 491));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/ad_user.png);"));
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
        deleteall = new QPushButton(ad_user);
        deleteall->setObjectName(QStringLiteral("deleteall"));
        deleteall->setGeometry(QRect(750, 440, 91, 23));
        frame->raise();
        label->raise();
        id->raise();
        checkBox->raise();
        checkBox_2->raise();
        checkBox_3->raise();
        okButton->raise();
        deleteid->raise();
        label_2->raise();
        label_3->raise();
        deletemessage->raise();
        exit->raise();
        label_4->raise();
        now->raise();
        label_6->raise();
        total->raise();
        label_8->raise();
        lastpage->raise();
        nextpage->raise();
        update->raise();
        message->raise();
        nextpagem->raise();
        lsatpagem->raise();
        nowm->raise();
        label_7->raise();
        totalm->raise();
        label_5->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        time->raise();
        table->raise();
        deleteall->raise();

        retranslateUi(ad_user);

        QMetaObject::connectSlotsByName(ad_user);
    } // setupUi

    void retranslateUi(QDialog *ad_user)
    {
        ad_user->setWindowTitle(QApplication::translate("ad_user", "\346\237\245\350\257\242\345\222\214\346\233\264\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("ad_user", "\347\224\250\346\210\267id", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ad_user", "\346\217\220\345\215\207\344\270\272\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("ad_user", "\351\231\215\347\272\247\344\270\272\346\231\256\351\200\232\347\224\250\346\210\267", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("ad_user", "\345\210\240\351\231\244\347\224\250\346\210\267", Q_NULLPTR));
        okButton->setText(QApplication::translate("ad_user", "\347\241\256\345\256\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ad_user", "\345\210\240\351\231\244id\344\270\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("ad_user", "\347\232\204\347\225\231\350\250\200", Q_NULLPTR));
        deletemessage->setText(QApplication::translate("ad_user", "\345\210\240\351\231\244", Q_NULLPTR));
        exit->setText(QString());
        label_4->setText(QApplication::translate("ad_user", "\345\205\261", Q_NULLPTR));
        now->setText(QApplication::translate("ad_user", "1", Q_NULLPTR));
        label_6->setText(QApplication::translate("ad_user", "/", Q_NULLPTR));
        total->setText(QApplication::translate("ad_user", "10", Q_NULLPTR));
        label_8->setText(QApplication::translate("ad_user", "\351\241\265", Q_NULLPTR));
        lastpage->setText(QApplication::translate("ad_user", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        nextpage->setText(QApplication::translate("ad_user", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        update->setText(QApplication::translate("ad_user", "\345\210\267\346\226\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = message->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ad_user", "\347\225\231\350\250\200\345\206\205\345\256\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = message->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("ad_user", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = message->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("ad_user", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = message->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("ad_user", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = message->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("ad_user", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = message->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("ad_user", "5", Q_NULLPTR));
        nextpagem->setText(QApplication::translate("ad_user", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        lsatpagem->setText(QApplication::translate("ad_user", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        nowm->setText(QApplication::translate("ad_user", "1", Q_NULLPTR));
        label_7->setText(QApplication::translate("ad_user", "/", Q_NULLPTR));
        totalm->setText(QApplication::translate("ad_user", "10", Q_NULLPTR));
        label_5->setText(QApplication::translate("ad_user", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\211\200\346\234\211\347\224\250\346\210\267\347\225\231\350\250\200\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("ad_user", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\224\250\346\210\267\344\277\241\346\201\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("ad_user", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\257\271\347\224\250\346\210\267\347\232\204\346\223\215\344\275\234\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("ad_user", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        time->setText(QApplication::translate("ad_user", "TextLabel", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("ad_user", "\347\224\250\346\210\267id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("ad_user", "email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("ad_user", "\347\224\265\350\257\235", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("ad_user", "\345\244\207\346\263\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = table->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("ad_user", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = table->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("ad_user", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = table->verticalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("ad_user", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = table->verticalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("ad_user", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = table->verticalHeaderItem(4);
        ___qtablewidgetitem14->setText(QApplication::translate("ad_user", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = table->verticalHeaderItem(5);
        ___qtablewidgetitem15->setText(QApplication::translate("ad_user", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = table->verticalHeaderItem(6);
        ___qtablewidgetitem16->setText(QApplication::translate("ad_user", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = table->verticalHeaderItem(7);
        ___qtablewidgetitem17->setText(QApplication::translate("ad_user", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = table->verticalHeaderItem(8);
        ___qtablewidgetitem18->setText(QApplication::translate("ad_user", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = table->verticalHeaderItem(9);
        ___qtablewidgetitem19->setText(QApplication::translate("ad_user", "10", Q_NULLPTR));
        deleteall->setText(QApplication::translate("ad_user", "\345\210\240\351\231\244\345\205\250\351\203\250\347\225\231\350\250\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ad_user: public Ui_ad_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AD_USER_H

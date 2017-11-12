/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QLabel *label;
    QCalendarWidget *calendarWidget;
    QPushButton *adpchange;
    QPushButton *adbchange;
    QPushButton *aduchange;
    QPushButton *lend;
    QLabel *label_2;
    QLabel *time;
    QFrame *frame;
    QPushButton *adexit;

    void setupUi(QDialog *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QStringLiteral("admin"));
        admin->resize(621, 296);
        admin->setMinimumSize(QSize(621, 296));
        admin->setMaximumSize(QSize(621, 296));
        label = new QLabel(admin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 211, 31));
        calendarWidget = new QCalendarWidget(admin);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(30, 70, 248, 169));
        adpchange = new QPushButton(admin);
        adpchange->setObjectName(QStringLiteral("adpchange"));
        adpchange->setGeometry(QRect(390, 80, 121, 31));
        adpchange->setStyleSheet(QStringLiteral("background-color: rgb(203, 203, 203);"));
        adbchange = new QPushButton(admin);
        adbchange->setObjectName(QStringLiteral("adbchange"));
        adbchange->setGeometry(QRect(390, 132, 121, 31));
        adbchange->setStyleSheet(QStringLiteral("background-color: rgb(202, 202, 202);"));
        aduchange = new QPushButton(admin);
        aduchange->setObjectName(QStringLiteral("aduchange"));
        aduchange->setGeometry(QRect(390, 180, 121, 31));
        aduchange->setStyleSheet(QStringLiteral("background-color: rgb(202, 202, 202);"));
        lend = new QPushButton(admin);
        lend->setObjectName(QStringLiteral("lend"));
        lend->setGeometry(QRect(390, 230, 121, 31));
        lend->setStyleSheet(QStringLiteral("background-color: rgb(202, 202, 202);"));
        label_2 = new QLabel(admin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 10, 81, 31));
        time = new QLabel(admin);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(310, 10, 121, 31));
        frame = new QFrame(admin);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 621, 301));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/admin.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        adexit = new QPushButton(frame);
        adexit->setObjectName(QStringLiteral("adexit"));
        adexit->setGeometry(QRect(570, 10, 20, 20));
        adexit->setMinimumSize(QSize(20, 20));
        adexit->setMaximumSize(QSize(20, 20));
        adexit->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        frame->raise();
        label->raise();
        calendarWidget->raise();
        adpchange->raise();
        adbchange->raise();
        aduchange->raise();
        lend->raise();
        label_2->raise();
        time->raise();

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QDialog *admin)
    {
        admin->setWindowTitle(QApplication::translate("admin", "\347\256\241\347\220\206\345\221\230\347\225\214\351\235\242", Q_NULLPTR));
        label->setText(QApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\346\254\242\350\277\216\347\256\241\347\220\206\345\221\230\344\275\277\347\224\250\346\234\254\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        adpchange->setText(QApplication::translate("admin", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        adbchange->setText(QApplication::translate("admin", "\346\237\245\350\257\242\344\277\256\346\224\271\346\233\264\346\226\260\344\271\246\347\233\256", Q_NULLPTR));
        aduchange->setText(QApplication::translate("admin", "\346\237\245\350\257\242\345\222\214\346\233\264\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        lend->setText(QApplication::translate("admin", "\344\271\246\347\261\215\345\200\237\351\230\205\347\256\241\347\220\206", Q_NULLPTR));
        label_2->setText(QApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\344\273\212\345\244\251\346\230\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        time->setText(QApplication::translate("admin", "TextLabel", Q_NULLPTR));
        adexit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H

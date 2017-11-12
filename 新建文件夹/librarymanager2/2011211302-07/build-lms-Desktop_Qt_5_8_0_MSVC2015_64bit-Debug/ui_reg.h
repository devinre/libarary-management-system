/********************************************************************************
** Form generated from reading UI file 'reg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_H
#define UI_REG_H

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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_reg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *logid;
    QTextEdit *email;
    QTextEdit *phone;
    QPushButton *regb;
    QPushButton *clearb;
    QLineEdit *logkey;
    QLineEdit *logkeysure;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *frame;
    QFrame *frame_2;
    QPushButton *exitb;

    void setupUi(QDialog *reg)
    {
        if (reg->objectName().isEmpty())
            reg->setObjectName(QStringLiteral("reg"));
        reg->resize(537, 377);
        reg->setMinimumSize(QSize(537, 377));
        reg->setMaximumSize(QSize(537, 377));
        reg->setModal(true);
        label = new QLabel(reg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 101, 54, 21));
        label_2 = new QLabel(reg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 141, 54, 21));
        label_3 = new QLabel(reg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 181, 71, 21));
        label_4 = new QLabel(reg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 221, 71, 21));
        label_5 = new QLabel(reg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 261, 54, 21));
        logid = new QTextEdit(reg);
        logid->setObjectName(QStringLiteral("logid"));
        logid->setGeometry(QRect(190, 100, 161, 31));
        email = new QTextEdit(reg);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(190, 220, 161, 31));
        phone = new QTextEdit(reg);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(190, 260, 161, 31));
        regb = new QPushButton(reg);
        regb->setObjectName(QStringLiteral("regb"));
        regb->setGeometry(QRect(350, 322, 91, 41));
        clearb = new QPushButton(reg);
        clearb->setObjectName(QStringLiteral("clearb"));
        clearb->setGeometry(QRect(240, 322, 91, 41));
        logkey = new QLineEdit(reg);
        logkey->setObjectName(QStringLiteral("logkey"));
        logkey->setGeometry(QRect(190, 140, 161, 31));
        logkeysure = new QLineEdit(reg);
        logkeysure->setObjectName(QStringLiteral("logkeysure"));
        logkeysure->setGeometry(QRect(190, 180, 161, 31));
        label_6 = new QLabel(reg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 150, 141, 20));
        label_7 = new QLabel(reg);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(370, 90, 131, 41));
        frame = new QFrame(reg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 541, 381));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/reg.png);"));
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
        exitb = new QPushButton(frame);
        exitb->setObjectName(QStringLiteral("exitb"));
        exitb->setGeometry(QRect(480, 20, 20, 20));
        exitb->setMinimumSize(QSize(20, 20));
        exitb->setMaximumSize(QSize(20, 20));
        exitb->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        frame->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        logid->raise();
        email->raise();
        phone->raise();
        regb->raise();
        clearb->raise();
        logkey->raise();
        logkeysure->raise();
        label_6->raise();
        label_7->raise();
        QWidget::setTabOrder(logid, logkey);
        QWidget::setTabOrder(logkey, logkeysure);
        QWidget::setTabOrder(logkeysure, email);
        QWidget::setTabOrder(email, phone);
        QWidget::setTabOrder(phone, clearb);
        QWidget::setTabOrder(clearb, regb);
        QWidget::setTabOrder(regb, exitb);

        retranslateUi(reg);

        QMetaObject::connectSlotsByName(reg);
    } // setupUi

    void retranslateUi(QDialog *reg)
    {
        reg->setWindowTitle(QApplication::translate("reg", "\346\254\242\350\277\216\346\263\250\345\206\214\346\202\272\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("reg", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("reg", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("reg", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\241\256\350\256\244\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("reg", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\224\265\345\255\220\351\202\256\344\273\266</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("reg", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\224\265\350\257\235</span></p></body></html>", Q_NULLPTR));
        logid->setHtml(QApplication::translate("reg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        regb->setText(QApplication::translate("reg", "\347\241\256\345\256\232\346\263\250\345\206\214", Q_NULLPTR));
        clearb->setText(QApplication::translate("reg", "\351\207\215\346\226\260\350\276\223\345\205\245", Q_NULLPTR));
        logkey->setText(QString());
        label_6->setText(QApplication::translate("reg", "\345\217\252\350\203\275\346\230\257\346\225\260\345\255\227\346\210\226\345\255\227\346\257\215\347\232\204\347\273\204\345\220\210", Q_NULLPTR));
        label_7->setText(QApplication::translate("reg", "<html><head/><body><p>\345\217\252\350\203\275\346\230\257\346\225\260\345\255\227\346\210\226\345\255\227\346\257\215\347\232\204\347\273\204\345\220\210</p><p>\344\270\224\347\224\250\346\210\267\345\220\215\346\263\250\345\206\214\345\220\216\344\270\215\350\203\275\344\277\256\346\224\271</p></body></html>", Q_NULLPTR));
        exitb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class reg: public Ui_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_H

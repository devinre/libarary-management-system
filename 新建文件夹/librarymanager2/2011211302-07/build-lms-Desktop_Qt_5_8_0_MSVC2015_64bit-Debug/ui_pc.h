/********************************************************************************
** Form generated from reading UI file 'pc.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PC_H
#define UI_PC_H

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

class Ui_pc
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *pc_email;
    QTextEdit *pc_phone;
    QPushButton *pc_regb;
    QPushButton *pc_clearb;
    QLineEdit *pc_logkey;
    QLineEdit *pc_logkeysure;
    QLabel *label_6;
    QLabel *label;
    QLabel *time;
    QFrame *frame;
    QPushButton *pc_exitb;
    QFrame *frame_2;

    void setupUi(QDialog *pc)
    {
        if (pc->objectName().isEmpty())
            pc->setObjectName(QStringLiteral("pc"));
        pc->resize(537, 377);
        pc->setMinimumSize(QSize(537, 377));
        pc->setMaximumSize(QSize(537, 377));
        pc->setModal(true);
        label_2 = new QLabel(pc);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 91, 54, 21));
        label_3 = new QLabel(pc);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 141, 71, 21));
        label_4 = new QLabel(pc);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 191, 71, 21));
        label_5 = new QLabel(pc);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 241, 54, 21));
        pc_email = new QTextEdit(pc);
        pc_email->setObjectName(QStringLiteral("pc_email"));
        pc_email->setGeometry(QRect(180, 190, 161, 31));
        pc_phone = new QTextEdit(pc);
        pc_phone->setObjectName(QStringLiteral("pc_phone"));
        pc_phone->setGeometry(QRect(180, 240, 161, 31));
        pc_regb = new QPushButton(pc);
        pc_regb->setObjectName(QStringLiteral("pc_regb"));
        pc_regb->setGeometry(QRect(260, 290, 81, 51));
        pc_clearb = new QPushButton(pc);
        pc_clearb->setObjectName(QStringLiteral("pc_clearb"));
        pc_clearb->setGeometry(QRect(140, 290, 81, 51));
        pc_logkey = new QLineEdit(pc);
        pc_logkey->setObjectName(QStringLiteral("pc_logkey"));
        pc_logkey->setGeometry(QRect(180, 90, 161, 31));
        pc_logkeysure = new QLineEdit(pc);
        pc_logkeysure->setObjectName(QStringLiteral("pc_logkeysure"));
        pc_logkeysure->setGeometry(QRect(180, 140, 161, 31));
        label_6 = new QLabel(pc);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(360, 100, 141, 20));
        label = new QLabel(pc);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 10, 54, 21));
        time = new QLabel(pc);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(390, 10, 71, 20));
        frame = new QFrame(pc);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 541, 381));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/pc.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pc_exitb = new QPushButton(frame);
        pc_exitb->setObjectName(QStringLiteral("pc_exitb"));
        pc_exitb->setGeometry(QRect(490, 10, 20, 20));
        pc_exitb->setMinimumSize(QSize(20, 20));
        pc_exitb->setMaximumSize(QSize(20, 20));
        pc_exitb->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 45, 45));
        frame_2->setMinimumSize(QSize(45, 45));
        frame_2->setMaximumSize(QSize(45, 45));
        frame_2->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/lms.ico);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        pc_email->raise();
        pc_phone->raise();
        pc_regb->raise();
        pc_clearb->raise();
        pc_logkey->raise();
        pc_logkeysure->raise();
        label_6->raise();
        label->raise();
        time->raise();
        QWidget::setTabOrder(pc_logkey, pc_logkeysure);
        QWidget::setTabOrder(pc_logkeysure, pc_email);
        QWidget::setTabOrder(pc_email, pc_phone);
        QWidget::setTabOrder(pc_phone, pc_clearb);
        QWidget::setTabOrder(pc_clearb, pc_regb);
        QWidget::setTabOrder(pc_regb, pc_exitb);

        retranslateUi(pc);

        QMetaObject::connectSlotsByName(pc);
    } // setupUi

    void retranslateUi(QDialog *pc)
    {
        pc->setWindowTitle(QApplication::translate("pc", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("pc", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("pc", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\241\256\350\256\244\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("pc", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\224\265\345\255\220\351\202\256\344\273\266</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("pc", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\224\265\350\257\235</span></p></body></html>", Q_NULLPTR));
        pc_regb->setText(QApplication::translate("pc", "\347\241\256\345\256\232\344\277\256\346\224\271", Q_NULLPTR));
        pc_clearb->setText(QApplication::translate("pc", "\351\207\215\346\226\260\350\276\223\345\205\245", Q_NULLPTR));
        pc_logkey->setText(QString());
        label_6->setText(QApplication::translate("pc", "\345\217\252\350\203\275\346\230\257\346\225\260\345\255\227\346\210\226\345\255\227\346\257\215\347\232\204\347\273\204\345\220\210", Q_NULLPTR));
        label->setText(QApplication::translate("pc", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        time->setText(QApplication::translate("pc", "TextLabel", Q_NULLPTR));
        pc_exitb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pc: public Ui_pc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PC_H

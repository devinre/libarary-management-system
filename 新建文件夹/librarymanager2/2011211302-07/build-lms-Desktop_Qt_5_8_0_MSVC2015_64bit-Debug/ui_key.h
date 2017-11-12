/********************************************************************************
** Form generated from reading UI file 'key.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEY_H
#define UI_KEY_H

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

QT_BEGIN_NAMESPACE

class Ui_key
{
public:
    QLabel *label;
    QLineEdit *kkey;
    QPushButton *kok;
    QFrame *frame;
    QPushButton *kexit;

    void setupUi(QDialog *key)
    {
        if (key->objectName().isEmpty())
            key->setObjectName(QStringLiteral("key"));
        key->resize(374, 191);
        key->setMinimumSize(QSize(374, 191));
        key->setMaximumSize(QSize(374, 191));
        key->setModal(true);
        label = new QLabel(key);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 101, 31));
        label->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        kkey = new QLineEdit(key);
        kkey->setObjectName(QStringLiteral("kkey"));
        kkey->setGeometry(QRect(50, 100, 261, 31));
        kok = new QPushButton(key);
        kok->setObjectName(QStringLiteral("kok"));
        kok->setGeometry(QRect(70, 140, 221, 41));
        kok->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 0));"));
        frame = new QFrame(key);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 381, 191));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/key.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        kexit = new QPushButton(frame);
        kexit->setObjectName(QStringLiteral("kexit"));
        kexit->setGeometry(QRect(330, 10, 20, 20));
        kexit->setMinimumSize(QSize(20, 20));
        kexit->setMaximumSize(QSize(20, 20));
        kexit->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/20080528160815502.gif);"));
        frame->raise();
        label->raise();
        kkey->raise();
        kok->raise();

        retranslateUi(key);

        QMetaObject::connectSlotsByName(key);
    } // setupUi

    void retranslateUi(QDialog *key)
    {
        key->setWindowTitle(QApplication::translate("key", "\350\257\267\350\276\223\345\205\245\345\216\237\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("key", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        kok->setText(QApplication::translate("key", "\347\241\256\345\256\232", Q_NULLPTR));
        kexit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class key: public Ui_key {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEY_H

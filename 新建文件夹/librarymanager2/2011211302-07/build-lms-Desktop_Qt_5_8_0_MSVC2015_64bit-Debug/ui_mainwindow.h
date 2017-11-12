/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *logbutton;
    QLineEdit *logkey;
    QLineEdit *logid;
    QCheckBox *remember;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame;
    QPushButton *exitButton;
    QPushButton *regbutton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(372, 329);
        MainWindow->setMinimumSize(QSize(372, 329));
        MainWindow->setMaximumSize(QSize(372, 329));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 90, 71, 31));
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 170, 51, 21));
        label_2->setStyleSheet(QStringLiteral(""));
        logbutton = new QPushButton(centralWidget);
        logbutton->setObjectName(QStringLiteral("logbutton"));
        logbutton->setGeometry(QRect(240, 260, 75, 23));
        logbutton->setStyleSheet(QStringLiteral("background-color: rgb(226, 226, 226);"));
        logkey = new QLineEdit(centralWidget);
        logkey->setObjectName(QStringLiteral("logkey"));
        logkey->setGeometry(QRect(30, 210, 291, 31));
        logkey->setStyleSheet(QStringLiteral(""));
        logid = new QLineEdit(centralWidget);
        logid->setObjectName(QStringLiteral("logid"));
        logid->setGeometry(QRect(30, 130, 291, 31));
        logid->setStyleSheet(QStringLiteral(""));
        remember = new QCheckBox(centralWidget);
        remember->setObjectName(QStringLiteral("remember"));
        remember->setGeometry(QRect(30, 250, 111, 21));
        remember->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Adobe \347\271\201\351\273\221\351\253\224 Std B\";"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 300, 81, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 300, 41, 21));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 371, 331));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/new/mainwindow/1234.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        exitButton = new QPushButton(frame);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(330, 10, 20, 20));
        exitButton->setMinimumSize(QSize(20, 20));
        exitButton->setMaximumSize(QSize(20, 20));
        exitButton->setStyleSheet(QLatin1String("background-image: url(:/new/mainwindow/20080528160815502.gif);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 0));"));
        regbutton = new QPushButton(centralWidget);
        regbutton->setObjectName(QStringLiteral("regbutton"));
        regbutton->setGeometry(QRect(310, 300, 41, 21));
        regbutton->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 0));\n"
"color: rgb(85, 170, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        label->raise();
        label_2->raise();
        logbutton->raise();
        logkey->raise();
        logid->raise();
        remember->raise();
        label_3->raise();
        label_4->raise();
        regbutton->raise();
        QWidget::setTabOrder(logid, logkey);
        QWidget::setTabOrder(logkey, logbutton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\"> \347\224\250\346\210\267\345\220\215</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\"> \345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        logbutton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        remember->setText(QApplication::translate("MainWindow", "Remember me", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\262\241\346\234\211\347\224\250\346\210\267\345\220\215\357\274\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\344\275\240\345\217\257\344\273\245", Q_NULLPTR));
        exitButton->setText(QString());
        regbutton->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

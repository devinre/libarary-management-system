
#ifndef UI_USERLOGMANAGE_H
#define UI_USERLOGMANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
class UiUserLogManageClass
{
public:
    QAction *delUserLog;
    QAction *refUserLog;
    QAction *srchUserLog;
    QAction *exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *userLogTable;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *UserLogManageClass)
    {
        if (UserLogManageClass->objectName().isEmpty())
            UserLogManageClass->setObjectName(QString::fromUtf8("UserLogManageClass"));
        UserLogManageClass->resize(800, 600);
        delUserLog = new QAction(UserLogManageClass);
        delUserLog->setObjectName(QString::fromUtf8("delUserLog"));
        refUserLog = new QAction(UserLogManageClass);
        refUserLog->setObjectName(QString::fromUtf8("refUserLog"));
        srchUserLog = new QAction(UserLogManageClass);
        srchUserLog->setObjectName(QString::fromUtf8("srchUserLog"));
        exit = new QAction(UserLogManageClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        centralwidget = new QWidget(UserLogManageClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        userLogTable = new QTableView(centralwidget);
        userLogTable->setObjectName(QString::fromUtf8("userLogTable"));

        gridLayout->addWidget(userLogTable, 0, 0, 1, 1);

        UserLogManageClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UserLogManageClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserLogManageClass->setStatusBar(statusbar);
        toolBar = new QToolBar(UserLogManageClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        UserLogManageClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(delUserLog);
        toolBar->addAction(srchUserLog);
        toolBar->addAction(refUserLog);
        toolBar->addAction(exit);

        retranslateUi(UserLogManageClass);

        QMetaObject::connectSlotsByName(UserLogManageClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserLogManageClass)
    {
        UserLogManageClass->setWindowTitle(QApplication::translate("UserLogManageClass", "UserLogManage", 0, QApplication::UnicodeUTF8));
        delUserLog->setText(QApplication::translate("UserLogManageClass", "Delete", 0, QApplication::UnicodeUTF8));
        refUserLog->setText(QApplication::translate("UserLogManageClass", "Refresh", 0, QApplication::UnicodeUTF8));
        srchUserLog->setText(QApplication::translate("UserLogManageClass", "Search", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("UserLogManageClass", "exit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("UserLogManageClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_USERLOGMANAGE_H

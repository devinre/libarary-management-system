
#ifndef UI_BOOKLOGMANAGE_H
#define UI_BOOKLOGMANAGE_H

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

class UiBookLogManageClass
{
public:
    QAction *delBookLog;
    QAction *refBookLog;
    QAction *srchBookLog;
    QAction *exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *bkLogTable;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *BookLogManageClass)
    {
        if (BookLogManageClass->objectName().isEmpty())
            BookLogManageClass->setObjectName(QString::fromUtf8("BookLogManageClass"));
        BookLogManageClass->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/booklog.png"), QSize(), QIcon::Normal, QIcon::Off);
        BookLogManageClass->setWindowIcon(icon);
        delBookLog = new QAction(BookLogManageClass);
        delBookLog->setObjectName(QString::fromUtf8("delBookLog"));
        refBookLog = new QAction(BookLogManageClass);
        refBookLog->setObjectName(QString::fromUtf8("refBookLog"));
        srchBookLog = new QAction(BookLogManageClass);
        srchBookLog->setObjectName(QString::fromUtf8("srchBookLog"));
        exit = new QAction(BookLogManageClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        centralwidget = new QWidget(BookLogManageClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bkLogTable = new QTableView(centralwidget);
        bkLogTable->setObjectName(QString::fromUtf8("bkLogTable"));

        gridLayout->addWidget(bkLogTable, 0, 0, 1, 1);

        BookLogManageClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(BookLogManageClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BookLogManageClass->setStatusBar(statusbar);
        toolBar = new QToolBar(BookLogManageClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        BookLogManageClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(delBookLog);
        toolBar->addAction(srchBookLog);
        toolBar->addAction(refBookLog);
        toolBar->addAction(exit);

        retranslateUi(BookLogManageClass);

        QMetaObject::connectSlotsByName(BookLogManageClass);
    } // setupUi

    void retranslateUi(QMainWindow *BookLogManageClass)
    {
        BookLogManageClass->setWindowTitle(QApplication::translate("BookLogManageClass", "BookLogManage", 0, QApplication::UnicodeUTF8));
        delBookLog->setText(QApplication::translate("BookLogManageClass", "Delete", 0, QApplication::UnicodeUTF8));
        refBookLog->setText(QApplication::translate("BookLogManageClass", "Refresh", 0, QApplication::UnicodeUTF8));
        srchBookLog->setText(QApplication::translate("BookLogManageClass", "Search", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("BookLogManageClass", "Exit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("BookLogManageClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_BOOKLOGMANAGE_H

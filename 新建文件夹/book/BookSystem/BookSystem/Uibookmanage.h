
#ifndef UI_BOOKMANAGE_H
#define UI_BOOKMANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

class UiBookManageClass
{
public:
    QAction *addBook;
    QAction *delBook;
    QAction *updateBook;
    QAction *refresh;
    QAction *exit;
    QAction *queryBook;
    QAction *lendOut;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *bkIDEdit;
    QLabel *label_2;
    QLineEdit *bkNameEdit;
    QLabel *label_3;
    QLineEdit *bkTypeEdit;
    QToolButton *bkSearchBtn;
    QSpacerItem *horizontalSpacer;
    QTableView *bkTable;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *BookManageClass)
    {
        if (BookManageClass->objectName().isEmpty())
            BookManageClass->setObjectName(QString::fromUtf8("BookManageClass"));
        BookManageClass->resize(804, 477);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/booklist.png"), QSize(), QIcon::Normal, QIcon::Off);
        BookManageClass->setWindowIcon(icon);
        addBook = new QAction(BookManageClass);
        addBook->setObjectName(QString::fromUtf8("addBook"));
        delBook = new QAction(BookManageClass);
        delBook->setObjectName(QString::fromUtf8("delBook"));
        updateBook = new QAction(BookManageClass);
        updateBook->setObjectName(QString::fromUtf8("updateBook"));
        refresh = new QAction(BookManageClass);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        exit = new QAction(BookManageClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        queryBook = new QAction(BookManageClass);
        queryBook->setObjectName(QString::fromUtf8("queryBook"));
        lendOut = new QAction(BookManageClass);
        lendOut->setObjectName(QString::fromUtf8("lendOut"));
        centralwidget = new QWidget(BookManageClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        bkIDEdit = new QLineEdit(centralwidget);
        bkIDEdit->setObjectName(QString::fromUtf8("bkIDEdit"));
        bkIDEdit->setMinimumSize(QSize(175, 20));
        bkIDEdit->setMaximumSize(QSize(175, 20));

        horizontalLayout->addWidget(bkIDEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        bkNameEdit = new QLineEdit(centralwidget);
        bkNameEdit->setObjectName(QString::fromUtf8("bkNameEdit"));
        bkNameEdit->setMinimumSize(QSize(174, 20));
        bkNameEdit->setMaximumSize(QSize(174, 20));

        horizontalLayout->addWidget(bkNameEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        bkTypeEdit = new QLineEdit(centralwidget);
        bkTypeEdit->setObjectName(QString::fromUtf8("bkTypeEdit"));
        bkTypeEdit->setMinimumSize(QSize(141, 20));
        bkTypeEdit->setMaximumSize(QSize(141, 20));

        horizontalLayout->addWidget(bkTypeEdit);

        bkSearchBtn = new QToolButton(centralwidget);
        bkSearchBtn->setObjectName(QString::fromUtf8("bkSearchBtn"));
        bkSearchBtn->setMinimumSize(QSize(0, 20));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        bkSearchBtn->setIcon(icon1);
        bkSearchBtn->setIconSize(QSize(16, 16));
        bkSearchBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(bkSearchBtn);

        horizontalSpacer = new QSpacerItem(238, 36, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        bkTable = new QTableView(centralwidget);
        bkTable->setObjectName(QString::fromUtf8("bkTable"));

        gridLayout->addWidget(bkTable, 1, 0, 1, 1);

        BookManageClass->setCentralWidget(centralwidget);
        bkTable->raise();
        statusbar = new QStatusBar(BookManageClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BookManageClass->setStatusBar(statusbar);
        toolBar = new QToolBar(BookManageClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMinimumSize(QSize(40, 30));
        BookManageClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(addBook);
        toolBar->addAction(delBook);
        toolBar->addAction(updateBook);
        toolBar->addAction(lendOut);
        toolBar->addAction(refresh);
        toolBar->addAction(exit);

        retranslateUi(BookManageClass);

        QMetaObject::connectSlotsByName(BookManageClass);
    } // setupUi

    void retranslateUi(QMainWindow *BookManageClass)
    {
        BookManageClass->setWindowTitle(QApplication::translate("BookManageClass", "BookManage", 0, QApplication::UnicodeUTF8));
        addBook->setText(QApplication::translate("BookManageClass", "AddBook", 0, QApplication::UnicodeUTF8));
        delBook->setText(QApplication::translate("BookManageClass", "DelBook", 0, QApplication::UnicodeUTF8));
        updateBook->setText(QApplication::translate("BookManageClass", "UpdateBook", 0, QApplication::UnicodeUTF8));
        refresh->setText(QApplication::translate("BookManageClass", "Refresh", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("BookManageClass", "Exit", 0, QApplication::UnicodeUTF8));
        queryBook->setText(QApplication::translate("BookManageClass", "QueryBook", 0, QApplication::UnicodeUTF8));
        lendOut->setText(QApplication::translate("BookManageClass", "LendOut", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BookManageClass", "BookID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BookManageClass", "BookNmae:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BookManageClass", "BookType:", 0, QApplication::UnicodeUTF8));
        bkSearchBtn->setText(QApplication::translate("BookManageClass", "Search", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("BookManageClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_BOOKMANAGE_H

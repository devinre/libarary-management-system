
#ifndef UI_LENDMANAGE_H
#define UI_LENDMANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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

class UiLendManageClass
{
public:
    QAction *returnAc;
    QAction *renewal;
    QAction *lendStat;
    QAction *overDue;
    QAction *delLend;
    QAction *refresh;
    QAction *lendList;
    QAction *exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *readerEdit;
    QLabel *label_2;
    QLineEdit *bkNameEdit;
    QCheckBox *overBox;
    QToolButton *srchBtn;
    QSpacerItem *horizontalSpacer;
    QTableView *lendTable;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *LendManageClass)
    {
        if (LendManageClass->objectName().isEmpty())
            LendManageClass->setObjectName(QString::fromUtf8("LendManageClass"));
        LendManageClass->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/lendlist.png"), QSize(), QIcon::Normal, QIcon::Off);
        LendManageClass->setWindowIcon(icon);
        returnAc = new QAction(LendManageClass);
        returnAc->setObjectName(QString::fromUtf8("returnAc"));
        renewal = new QAction(LendManageClass);
        renewal->setObjectName(QString::fromUtf8("renewal"));
        lendStat = new QAction(LendManageClass);
        lendStat->setObjectName(QString::fromUtf8("lendStat"));
        overDue = new QAction(LendManageClass);
        overDue->setObjectName(QString::fromUtf8("overDue"));
        delLend = new QAction(LendManageClass);
        delLend->setObjectName(QString::fromUtf8("delLend"));
        refresh = new QAction(LendManageClass);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        lendList = new QAction(LendManageClass);
        lendList->setObjectName(QString::fromUtf8("lendList"));
        exit = new QAction(LendManageClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        centralwidget = new QWidget(LendManageClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        readerEdit = new QLineEdit(centralwidget);
        readerEdit->setObjectName(QString::fromUtf8("readerEdit"));
        readerEdit->setMinimumSize(QSize(172, 20));
        readerEdit->setMaximumSize(QSize(172, 20));

        horizontalLayout->addWidget(readerEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        bkNameEdit = new QLineEdit(centralwidget);
        bkNameEdit->setObjectName(QString::fromUtf8("bkNameEdit"));
        bkNameEdit->setMinimumSize(QSize(173, 20));
        bkNameEdit->setMaximumSize(QSize(173, 20));

        horizontalLayout->addWidget(bkNameEdit);

        overBox = new QCheckBox(centralwidget);
        overBox->setObjectName(QString::fromUtf8("overBox"));

        horizontalLayout->addWidget(overBox);

        srchBtn = new QToolButton(centralwidget);
        srchBtn->setObjectName(QString::fromUtf8("srchBtn"));
        srchBtn->setMinimumSize(QSize(0, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        srchBtn->setIcon(icon1);
        srchBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(srchBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lendTable = new QTableView(centralwidget);
        lendTable->setObjectName(QString::fromUtf8("lendTable"));

        gridLayout->addWidget(lendTable, 1, 0, 1, 1);

        LendManageClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LendManageClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LendManageClass->setStatusBar(statusbar);
        toolBar = new QToolBar(LendManageClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        LendManageClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(returnAc);
        toolBar->addAction(renewal);
        toolBar->addAction(lendStat);
        toolBar->addAction(overDue);
        toolBar->addAction(delLend);
        toolBar->addAction(lendList);
        toolBar->addAction(refresh);
        toolBar->addAction(exit);

        retranslateUi(LendManageClass);

        QMetaObject::connectSlotsByName(LendManageClass);
    } // setupUi

    void retranslateUi(QMainWindow *LendManageClass)
    {
        LendManageClass->setWindowTitle(QApplication::translate("LendManageClass", "LendManage", 0, QApplication::UnicodeUTF8));
        returnAc->setText(QApplication::translate("LendManageClass", "Return", 0, QApplication::UnicodeUTF8));
        renewal->setText(QApplication::translate("LendManageClass", "Renewal", 0, QApplication::UnicodeUTF8));
        lendStat->setText(QApplication::translate("LendManageClass", "LendStatistic", 0, QApplication::UnicodeUTF8));
        overDue->setText(QApplication::translate("LendManageClass", "OverDue", 0, QApplication::UnicodeUTF8));
        delLend->setText(QApplication::translate("LendManageClass", "Delete", 0, QApplication::UnicodeUTF8));
        refresh->setText(QApplication::translate("LendManageClass", "Refresh", 0, QApplication::UnicodeUTF8));
        lendList->setText(QApplication::translate("LendManageClass", "LendList", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("LendManageClass", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LendManageClass", "Reader:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LendManageClass", "BookName:", 0, QApplication::UnicodeUTF8));
        overBox->setText(QApplication::translate("LendManageClass", "OverDue", 0, QApplication::UnicodeUTF8));
        srchBtn->setText(QApplication::translate("LendManageClass", "Search", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("LendManageClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_LENDMANAGE_H

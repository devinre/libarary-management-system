
#ifndef UI_USERMANAGE_H
#define UI_USERMANAGE_H

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

class UiUserManageClass
{
public:
    QAction *addUser;
    QAction *delUser;
    QAction *updateUser;
    QAction *queryUser;
    QAction *refresh;
    QAction *exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *userIDEdit;
    QLabel *label_2;
    QLineEdit *userNameEdit;
    QToolButton *userSearchBtn;
    QSpacerItem *horizontalSpacer;
    QTableView *userTable;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *UserManageClass)
    {
        if (UserManageClass->objectName().isEmpty())
            UserManageClass->setObjectName(QString::fromUtf8("UserManageClass"));
        UserManageClass->resize(800, 600);
        addUser = new QAction(UserManageClass);
        addUser->setObjectName(QString::fromUtf8("addUser"));
        delUser = new QAction(UserManageClass);
        delUser->setObjectName(QString::fromUtf8("delUser"));
        updateUser = new QAction(UserManageClass);
        updateUser->setObjectName(QString::fromUtf8("updateUser"));
        queryUser = new QAction(UserManageClass);
        queryUser->setObjectName(QString::fromUtf8("queryUser"));
        refresh = new QAction(UserManageClass);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        exit = new QAction(UserManageClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        centralwidget = new QWidget(UserManageClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(42, 29));
        label->setMaximumSize(QSize(42, 29));

        horizontalLayout->addWidget(label);

        userIDEdit = new QLineEdit(centralwidget);
        userIDEdit->setObjectName(QString::fromUtf8("userIDEdit"));
        userIDEdit->setMinimumSize(QSize(205, 20));
        userIDEdit->setMaximumSize(QSize(205, 20));

        horizontalLayout->addWidget(userIDEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(54, 29));
        label_2->setMaximumSize(QSize(54, 29));

        horizontalLayout->addWidget(label_2);

        userNameEdit = new QLineEdit(centralwidget);
        userNameEdit->setObjectName(QString::fromUtf8("userNameEdit"));
        userNameEdit->setMinimumSize(QSize(206, 20));
        userNameEdit->setMaximumSize(QSize(206, 20));

        horizontalLayout->addWidget(userNameEdit);

        userSearchBtn = new QToolButton(centralwidget);
        userSearchBtn->setObjectName(QString::fromUtf8("userSearchBtn"));
        userSearchBtn->setMinimumSize(QSize(55, 22));
        userSearchBtn->setMaximumSize(QSize(55, 22));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        userSearchBtn->setIcon(icon);
        userSearchBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(userSearchBtn);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        userTable = new QTableView(centralwidget);
        userTable->setObjectName(QString::fromUtf8("userTable"));

        gridLayout->addWidget(userTable, 1, 0, 1, 1);

        UserManageClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UserManageClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserManageClass->setStatusBar(statusbar);
        toolBar = new QToolBar(UserManageClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        UserManageClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(addUser);
        toolBar->addAction(delUser);
        toolBar->addAction(updateUser);
        toolBar->addAction(refresh);
        toolBar->addAction(exit);

        retranslateUi(UserManageClass);

        QMetaObject::connectSlotsByName(UserManageClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserManageClass)
    {
        UserManageClass->setWindowTitle(QApplication::translate("UserManageClass", "UserManage", 0, QApplication::UnicodeUTF8));
        addUser->setText(QApplication::translate("UserManageClass", "AddUser", 0, QApplication::UnicodeUTF8));
        delUser->setText(QApplication::translate("UserManageClass", "DeleteUser", 0, QApplication::UnicodeUTF8));
        updateUser->setText(QApplication::translate("UserManageClass", "Update", 0, QApplication::UnicodeUTF8));
        queryUser->setText(QApplication::translate("UserManageClass", "QueryUser", 0, QApplication::UnicodeUTF8));
        refresh->setText(QApplication::translate("UserManageClass", "Refresh", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("UserManageClass", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserManageClass", "UserID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UserManageClass", "UserName:", 0, QApplication::UnicodeUTF8));
        userSearchBtn->setText(QApplication::translate("UserManageClass", "Search", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("UserManageClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_USERMANAGE_H

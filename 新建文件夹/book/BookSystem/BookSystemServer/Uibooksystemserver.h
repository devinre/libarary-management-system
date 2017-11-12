#ifndef UI_BOOKSYSTEMSERVER_H
#define UI_BOOKSYSTEMSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

class UiBookSystemServerClass
{
public:
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QGridLayout *gridLayout;
    QLabel *database_label;
    QLabel *username_label;
    QLabel *password_label;
    QLineEdit *server_database;
    QLineEdit *server_username;
    QLineEdit *server_password;
    QLabel *current_conn_num;
    QLabel *startuptime;
    QLabel *conn_num_label;
    QLabel *start_label;
    QFrame *line;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *server_conn_btn;
    QPushButton *server_exit_btn;

    void setupUi(QWidget *BookSystemServerClass)
    {
        if (BookSystemServerClass->objectName().isEmpty())
            BookSystemServerClass->setObjectName(QString::fromUtf8("BookSystemServerClass"));
        BookSystemServerClass->resize(296, 321);
        gridLayout_2 = new QGridLayout(BookSystemServerClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listWidget = new QListWidget(BookSystemServerClass);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        database_label = new QLabel(BookSystemServerClass);
        database_label->setObjectName(QString::fromUtf8("database_label"));

        gridLayout->addWidget(database_label, 0, 0, 1, 1);

        username_label = new QLabel(BookSystemServerClass);
        username_label->setObjectName(QString::fromUtf8("username_label"));

        gridLayout->addWidget(username_label, 1, 0, 1, 1);

        password_label = new QLabel(BookSystemServerClass);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        gridLayout->addWidget(password_label, 2, 0, 1, 1);

        server_database = new QLineEdit(BookSystemServerClass);
        server_database->setObjectName(QString::fromUtf8("server_database"));

        gridLayout->addWidget(server_database, 0, 1, 1, 1);

        server_username = new QLineEdit(BookSystemServerClass);
        server_username->setObjectName(QString::fromUtf8("server_username"));

        gridLayout->addWidget(server_username, 1, 1, 1, 1);

        server_password = new QLineEdit(BookSystemServerClass);
        server_password->setObjectName(QString::fromUtf8("server_password"));
        server_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(server_password, 2, 1, 1, 1);

        current_conn_num = new QLabel(BookSystemServerClass);
        current_conn_num->setObjectName(QString::fromUtf8("current_conn_num"));

        gridLayout->addWidget(current_conn_num, 3, 0, 1, 1);

        startuptime = new QLabel(BookSystemServerClass);
        startuptime->setObjectName(QString::fromUtf8("startuptime"));

        gridLayout->addWidget(startuptime, 6, 0, 1, 1);

        conn_num_label = new QLabel(BookSystemServerClass);
        conn_num_label->setObjectName(QString::fromUtf8("conn_num_label"));

        gridLayout->addWidget(conn_num_label, 4, 0, 1, 1);

        start_label = new QLabel(BookSystemServerClass);
        start_label->setObjectName(QString::fromUtf8("start_label"));

        gridLayout->addWidget(start_label, 7, 0, 1, 1);

        line = new QFrame(BookSystemServerClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 0, 1, 1);

        line_2 = new QFrame(BookSystemServerClass);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 8, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(37, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        server_conn_btn = new QPushButton(BookSystemServerClass);
        server_conn_btn->setObjectName(QString::fromUtf8("server_conn_btn"));
        server_conn_btn->setMinimumSize(QSize(75, 23));
        server_conn_btn->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(server_conn_btn);

        server_exit_btn = new QPushButton(BookSystemServerClass);
        server_exit_btn->setObjectName(QString::fromUtf8("server_exit_btn"));
        server_exit_btn->setMinimumSize(QSize(81, 23));
        server_exit_btn->setMaximumSize(QSize(81, 23));

        horizontalLayout->addWidget(server_exit_btn);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(BookSystemServerClass);

        QMetaObject::connectSlotsByName(BookSystemServerClass);
    } // setupUi

    void retranslateUi(QWidget *BookSystemServerClass)
    {
        BookSystemServerClass->setWindowTitle(QApplication::translate("BookSystemServerClass", "BookSystemServer", 0, QApplication::UnicodeUTF8));
        database_label->setText(QApplication::translate("BookSystemServerClass", "DataBase:", 0, QApplication::UnicodeUTF8));
        username_label->setText(QApplication::translate("BookSystemServerClass", "UserName:", 0, QApplication::UnicodeUTF8));
        password_label->setText(QApplication::translate("BookSystemServerClass", "PassWord:", 0, QApplication::UnicodeUTF8));
        current_conn_num->setText(QApplication::translate("BookSystemServerClass", "Current connection number:", 0, QApplication::UnicodeUTF8));
        startuptime->setText(QApplication::translate("BookSystemServerClass", "Server startup time:", 0, QApplication::UnicodeUTF8));
        conn_num_label->setText(QApplication::translate("BookSystemServerClass", "0", 0, QApplication::UnicodeUTF8));
        start_label->setText(QApplication::translate("BookSystemServerClass", "", "0", QApplication::UnicodeUTF8));
        server_conn_btn->setText(QApplication::translate("BookSystemServerClass", "&Connection", 0, QApplication::UnicodeUTF8));
        server_exit_btn->setText(QApplication::translate("BookSystemServerClass", "Hide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_BOOKSYSTEMSERVER_H

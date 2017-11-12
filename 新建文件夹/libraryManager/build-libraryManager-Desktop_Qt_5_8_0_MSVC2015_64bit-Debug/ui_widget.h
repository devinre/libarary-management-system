/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QLabel *label;
    QTableWidget *searchBookTable;
    QPushButton *bookBorrowButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *userLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *searchLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QLabel *dateLabel;
    QWidget *myBorrowPage;
    QLabel *label_28;
    QTableWidget *myBookTable;
    QPushButton *bookRepayButton;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QWidget *adminPage;
    QLabel *label_29;
    QPushButton *adminAddButton;
    QPushButton *adminUpdataButton;
    QPushButton *adminDeleteButton;
    QPushButton *adminSearchButton;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *adminBookNumberLE;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *adminBookNameLE;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *adminAuthorLE;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *adminHotLE;
    QTableWidget *adminTable;
    QTableWidget *adminUserTable;
    QPushButton *adminDeleteUserBt;
    QPushButton *adminSearchUserBt;
    QPushButton *adminSearchAllUserBt;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *adminUserLE;
    QWidget *changePwdPage;
    QLabel *label_27;
    QPushButton *sumbitButton;
    QPushButton *clearButton;
    QPushButton *exitButton;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *oldPwdLE;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *newPwdLE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *newPwdLESure;
    QPushButton *changePwdButton;
    QPushButton *mianPageButton;
    QPushButton *returnLoginButton;
    QPushButton *myBorrowButton;
    QPushButton *adminButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(884, 636);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 70, 841, 551));
        mainPage = new QWidget();
        mainPage->setObjectName(QStringLiteral("mainPage"));
        label = new QLabel(mainPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 140, 141, 111));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        searchBookTable = new QTableWidget(mainPage);
        if (searchBookTable->columnCount() < 5)
            searchBookTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        searchBookTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        searchBookTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        searchBookTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        searchBookTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        searchBookTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (searchBookTable->rowCount() < 3)
            searchBookTable->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        searchBookTable->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        searchBookTable->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        searchBookTable->setVerticalHeaderItem(2, __qtablewidgetitem7);
        searchBookTable->setObjectName(QStringLiteral("searchBookTable"));
        searchBookTable->setGeometry(QRect(90, 240, 631, 192));
        bookBorrowButton = new QPushButton(mainPage);
        bookBorrowButton->setObjectName(QStringLiteral("bookBorrowButton"));
        bookBorrowButton->setGeometry(QRect(620, 360, 71, 31));
        layoutWidget1 = new QWidget(mainPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 121, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(40, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        userLabel = new QLabel(layoutWidget1);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(userLabel);

        layoutWidget2 = new QWidget(mainPage);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(210, 70, 471, 32));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        label_6->setFont(font2);

        horizontalLayout_5->addWidget(label_6);

        searchLineEdit = new QLineEdit(layoutWidget2);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));
        searchLineEdit->setMinimumSize(QSize(300, 30));

        horizontalLayout_5->addWidget(searchLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        searchButton = new QPushButton(layoutWidget2);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setMinimumSize(QSize(70, 30));

        horizontalLayout_5->addWidget(searchButton);

        checkBox_3 = new QCheckBox(mainPage);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(620, 330, 53, 16));
        checkBox_2 = new QCheckBox(mainPage);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(620, 300, 53, 16));
        checkBox = new QCheckBox(mainPage);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(620, 270, 53, 16));
        dateLabel = new QLabel(mainPage);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setGeometry(QRect(710, 20, 131, 20));
        stackedWidget->addWidget(mainPage);
        myBorrowPage = new QWidget();
        myBorrowPage->setObjectName(QStringLiteral("myBorrowPage"));
        label_28 = new QLabel(myBorrowPage);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(0, 20, 841, 20));
        QFont font3;
        font3.setPointSize(12);
        label_28->setFont(font3);
        label_28->setFrameShape(QFrame::StyledPanel);
        label_28->setAlignment(Qt::AlignCenter);
        myBookTable = new QTableWidget(myBorrowPage);
        if (myBookTable->columnCount() < 5)
            myBookTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        myBookTable->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        myBookTable->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        myBookTable->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        myBookTable->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        myBookTable->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        myBookTable->setObjectName(QStringLiteral("myBookTable"));
        myBookTable->setGeometry(QRect(0, 60, 621, 351));
        bookRepayButton = new QPushButton(myBorrowPage);
        bookRepayButton->setObjectName(QStringLiteral("bookRepayButton"));
        bookRepayButton->setGeometry(QRect(520, 370, 71, 31));
        layoutWidget4 = new QWidget(myBorrowPage);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(530, 90, 51, 271));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBox_4 = new QCheckBox(layoutWidget4);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        verticalLayout_3->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(layoutWidget4);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        verticalLayout_3->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(layoutWidget4);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        verticalLayout_3->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(layoutWidget4);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        verticalLayout_3->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(layoutWidget4);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        verticalLayout_3->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(layoutWidget4);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        verticalLayout_3->addWidget(checkBox_9);

        checkBox_10 = new QCheckBox(layoutWidget4);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        verticalLayout_3->addWidget(checkBox_10);

        checkBox_11 = new QCheckBox(layoutWidget4);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));

        verticalLayout_3->addWidget(checkBox_11);

        checkBox_12 = new QCheckBox(layoutWidget4);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));

        verticalLayout_3->addWidget(checkBox_12);

        stackedWidget->addWidget(myBorrowPage);
        adminPage = new QWidget();
        adminPage->setObjectName(QStringLiteral("adminPage"));
        label_29 = new QLabel(adminPage);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(0, 20, 841, 20));
        label_29->setFont(font3);
        label_29->setFrameShape(QFrame::StyledPanel);
        label_29->setAlignment(Qt::AlignCenter);
        adminAddButton = new QPushButton(adminPage);
        adminAddButton->setObjectName(QStringLiteral("adminAddButton"));
        adminAddButton->setGeometry(QRect(60, 300, 61, 41));
        adminUpdataButton = new QPushButton(adminPage);
        adminUpdataButton->setObjectName(QStringLiteral("adminUpdataButton"));
        adminUpdataButton->setGeometry(QRect(130, 300, 61, 41));
        adminDeleteButton = new QPushButton(adminPage);
        adminDeleteButton->setObjectName(QStringLiteral("adminDeleteButton"));
        adminDeleteButton->setGeometry(QRect(270, 300, 61, 41));
        adminSearchButton = new QPushButton(adminPage);
        adminSearchButton->setObjectName(QStringLiteral("adminSearchButton"));
        adminSearchButton->setGeometry(QRect(200, 300, 61, 41));
        layoutWidget5 = new QWidget(adminPage);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(68, 91, 181, 191));
        verticalLayout_4 = new QVBoxLayout(layoutWidget5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        adminBookNumberLE = new QLineEdit(layoutWidget5);
        adminBookNumberLE->setObjectName(QStringLiteral("adminBookNumberLE"));

        horizontalLayout_6->addWidget(adminBookNumberLE);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        adminBookNameLE = new QLineEdit(layoutWidget5);
        adminBookNameLE->setObjectName(QStringLiteral("adminBookNameLE"));

        horizontalLayout_7->addWidget(adminBookNameLE);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(layoutWidget5);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_8->addWidget(label_9);

        adminAuthorLE = new QLineEdit(layoutWidget5);
        adminAuthorLE->setObjectName(QStringLiteral("adminAuthorLE"));

        horizontalLayout_8->addWidget(adminAuthorLE);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_10 = new QLabel(layoutWidget5);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_9->addWidget(label_10);

        adminHotLE = new QLineEdit(layoutWidget5);
        adminHotLE->setObjectName(QStringLiteral("adminHotLE"));

        horizontalLayout_9->addWidget(adminHotLE);


        verticalLayout_4->addLayout(horizontalLayout_9);

        adminTable = new QTableWidget(adminPage);
        if (adminTable->columnCount() < 5)
            adminTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        adminTable->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        adminTable->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        adminTable->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        adminTable->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        adminTable->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        if (adminTable->rowCount() < 5)
            adminTable->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        adminTable->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        adminTable->setVerticalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        adminTable->setVerticalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        adminTable->setVerticalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        adminTable->setVerticalHeaderItem(4, __qtablewidgetitem22);
        adminTable->setObjectName(QStringLiteral("adminTable"));
        adminTable->setGeometry(QRect(310, 90, 521, 181));
        adminUserTable = new QTableWidget(adminPage);
        if (adminUserTable->columnCount() < 4)
            adminUserTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        adminUserTable->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        adminUserTable->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        adminUserTable->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        adminUserTable->setHorizontalHeaderItem(3, __qtablewidgetitem26);
        if (adminUserTable->rowCount() < 10)
            adminUserTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(5, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(7, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(8, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        adminUserTable->setVerticalHeaderItem(9, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        adminUserTable->setItem(1, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        adminUserTable->setItem(2, 1, __qtablewidgetitem38);
        adminUserTable->setObjectName(QStringLiteral("adminUserTable"));
        adminUserTable->setGeometry(QRect(310, 350, 421, 192));
        adminDeleteUserBt = new QPushButton(adminPage);
        adminDeleteUserBt->setObjectName(QStringLiteral("adminDeleteUserBt"));
        adminDeleteUserBt->setGeometry(QRect(60, 490, 61, 31));
        adminSearchUserBt = new QPushButton(adminPage);
        adminSearchUserBt->setObjectName(QStringLiteral("adminSearchUserBt"));
        adminSearchUserBt->setGeometry(QRect(130, 490, 61, 31));
        adminSearchAllUserBt = new QPushButton(adminPage);
        adminSearchAllUserBt->setObjectName(QStringLiteral("adminSearchAllUserBt"));
        adminSearchAllUserBt->setGeometry(QRect(200, 490, 61, 31));
        layoutWidget = new QWidget(adminPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 440, 177, 22));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_10->addWidget(label_11);

        adminUserLE = new QLineEdit(layoutWidget);
        adminUserLE->setObjectName(QStringLiteral("adminUserLE"));

        horizontalLayout_10->addWidget(adminUserLE);

        stackedWidget->addWidget(adminPage);
        changePwdPage = new QWidget();
        changePwdPage->setObjectName(QStringLiteral("changePwdPage"));
        label_27 = new QLabel(changePwdPage);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(0, 20, 841, 20));
        label_27->setFont(font3);
        label_27->setFrameShape(QFrame::StyledPanel);
        label_27->setAlignment(Qt::AlignCenter);
        sumbitButton = new QPushButton(changePwdPage);
        sumbitButton->setObjectName(QStringLiteral("sumbitButton"));
        sumbitButton->setGeometry(QRect(230, 320, 91, 31));
        clearButton = new QPushButton(changePwdPage);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(360, 320, 91, 31));
        exitButton = new QPushButton(changePwdPage);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(480, 320, 91, 31));
        layoutWidget6 = new QWidget(changePwdPage);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(281, 130, 241, 161));
        verticalLayout = new QVBoxLayout(layoutWidget6);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget6);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font4;
        font4.setFamily(QStringLiteral("Aharoni"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label_4->setFont(font4);

        horizontalLayout_3->addWidget(label_4);

        oldPwdLE = new QLineEdit(layoutWidget6);
        oldPwdLE->setObjectName(QStringLiteral("oldPwdLE"));

        horizontalLayout_3->addWidget(oldPwdLE);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font4);

        horizontalLayout->addWidget(label_2);

        newPwdLE = new QLineEdit(layoutWidget6);
        newPwdLE->setObjectName(QStringLiteral("newPwdLE"));

        horizontalLayout->addWidget(newPwdLE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font4);

        horizontalLayout_2->addWidget(label_3);

        newPwdLESure = new QLineEdit(layoutWidget6);
        newPwdLESure->setObjectName(QStringLiteral("newPwdLESure"));

        horizontalLayout_2->addWidget(newPwdLESure);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(changePwdPage);
        changePwdButton = new QPushButton(Widget);
        changePwdButton->setObjectName(QStringLiteral("changePwdButton"));
        changePwdButton->setGeometry(QRect(560, 10, 101, 41));
        mianPageButton = new QPushButton(Widget);
        mianPageButton->setObjectName(QStringLiteral("mianPageButton"));
        mianPageButton->setGeometry(QRect(220, 10, 101, 41));
        returnLoginButton = new QPushButton(Widget);
        returnLoginButton->setObjectName(QStringLiteral("returnLoginButton"));
        returnLoginButton->setGeometry(QRect(730, 10, 101, 41));
        myBorrowButton = new QPushButton(Widget);
        myBorrowButton->setObjectName(QStringLiteral("myBorrowButton"));
        myBorrowButton->setGeometry(QRect(390, 10, 101, 41));
        adminButton = new QPushButton(Widget);
        adminButton->setObjectName(QStringLiteral("adminButton"));
        adminButton->setGeometry(QRect(50, 10, 101, 41));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = searchBookTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = searchBookTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = searchBookTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = searchBookTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "\345\200\237\344\271\246\344\272\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = searchBookTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "\345\272\223\345\255\230\346\230\257\345\220\246\350\277\230\346\234\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = searchBookTable->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = searchBookTable->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = searchBookTable->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        bookBorrowButton->setText(QApplication::translate("Widget", "\345\200\237\344\271\246", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        userLabel->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\344\271\246\345\220\215\357\274\232", Q_NULLPTR));
        searchButton->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        dateLabel->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_28->setText(QApplication::translate("Widget", "\345\200\237\351\230\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = myBookTable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = myBookTable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = myBookTable->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = myBookTable->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget", "\345\200\237\344\271\246\346\227\245\346\234\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = myBookTable->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget", "\345\275\222\350\277\230\346\227\245\346\234\237", Q_NULLPTR));
        bookRepayButton->setText(QApplication::translate("Widget", "\345\275\222\350\277\230", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_9->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_10->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_11->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        checkBox_12->setText(QApplication::translate("Widget", "\351\200\211\344\270\255", Q_NULLPTR));
        label_29->setText(QApplication::translate("Widget", "\350\266\205\347\272\247\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        adminAddButton->setText(QApplication::translate("Widget", "\346\267\273\345\212\240", Q_NULLPTR));
        adminUpdataButton->setText(QApplication::translate("Widget", "\346\233\264\346\226\260", Q_NULLPTR));
        adminDeleteButton->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        adminSearchButton->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "\344\271\246\345\217\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "\344\271\246\345\220\215\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "\344\275\234\350\200\205\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "\345\200\237\344\271\246\344\272\272\357\274\232", Q_NULLPTR));
        adminHotLE->setText(QApplication::translate("Widget", "Null", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = adminTable->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget", "\344\271\246\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = adminTable->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = adminTable->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = adminTable->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("Widget", "\345\200\237\344\271\246\344\272\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = adminTable->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("Widget", "\345\272\223\345\255\230\346\230\257\345\220\246\350\277\230\346\234\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = adminTable->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = adminTable->verticalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = adminTable->verticalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = adminTable->verticalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = adminTable->verticalHeaderItem(4);
        ___qtablewidgetitem22->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = adminUserTable->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("Widget", "\350\264\246\346\210\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = adminUserTable->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("Widget", "\345\257\206\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = adminUserTable->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("Widget", "\351\202\256\347\256\261", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = adminUserTable->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QApplication::translate("Widget", "QQ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = adminUserTable->verticalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = adminUserTable->verticalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = adminUserTable->verticalHeaderItem(2);
        ___qtablewidgetitem29->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = adminUserTable->verticalHeaderItem(3);
        ___qtablewidgetitem30->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = adminUserTable->verticalHeaderItem(4);
        ___qtablewidgetitem31->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = adminUserTable->verticalHeaderItem(5);
        ___qtablewidgetitem32->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = adminUserTable->verticalHeaderItem(6);
        ___qtablewidgetitem33->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = adminUserTable->verticalHeaderItem(7);
        ___qtablewidgetitem34->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = adminUserTable->verticalHeaderItem(8);
        ___qtablewidgetitem35->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = adminUserTable->verticalHeaderItem(9);
        ___qtablewidgetitem36->setText(QApplication::translate("Widget", "10", Q_NULLPTR));

        const bool __sortingEnabled = adminUserTable->isSortingEnabled();
        adminUserTable->setSortingEnabled(false);
        adminUserTable->setSortingEnabled(__sortingEnabled);

        adminDeleteUserBt->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\350\264\246\346\210\267", Q_NULLPTR));
        adminSearchUserBt->setText(QApplication::translate("Widget", "\346\237\245\350\257\242\350\264\246\346\210\267", Q_NULLPTR));
        adminSearchAllUserBt->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\350\264\246\346\210\267", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "\350\264\246\346\210\267\357\274\232", Q_NULLPTR));
        label_27->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        sumbitButton->setText(QApplication::translate("Widget", "\344\277\256\346\224\271", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272 ", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\345\216\237\345\257\206\347\240\201\357\274\232    ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\346\226\260\345\257\206\347\240\201\357\274\232    ", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        changePwdButton->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        mianPageButton->setText(QApplication::translate("Widget", "\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        returnLoginButton->setText(QApplication::translate("Widget", "\346\263\250\351\224\200", Q_NULLPTR));
        myBorrowButton->setText(QApplication::translate("Widget", "\346\210\221\347\232\204\345\200\237\351\230\205", Q_NULLPTR));
        adminButton->setText(QApplication::translate("Widget", "\350\266\205\347\272\247\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

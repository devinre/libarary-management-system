
#ifndef UI_BOOKSYSTEM_H
#define UI_BOOKSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

class UiBookSystemClass
{
public:
    QAction *login;
    QAction *pwdModify;
    QAction *logoff;
    QAction *exit;
    QAction *addUser;
    QAction *delUser;
    QAction *updateUser;
    QAction *addBook;
    QAction *delBook;
    QAction *lendBook;
    QAction *returnBook;
    QAction *renewal;
    QAction *queryBook;
    QAction *lendRecord;
    QAction *lendSta;
    QAction *overdueRec;
    QAction *helpDoc;
    QAction *about;
    QAction *userList;
    QAction *bookList;
    QAction *showGPS;
    QAction *addReader;
    QAction *delReader;
    QAction *readerTable;
    QAction *userLog;
    QAction *bookLog;
    QAction *updateReader;
    QAction *updateBook;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *widget;
    QFormLayout *formLayout;
    QToolButton *bkLendBtn;
    QToolButton *bkReturnBtn;
    QToolButton *bkQueryBtn;
    QToolButton *bkRenewalBtn;
    QWidget *page_3;
    QFormLayout *formLayout_2;
    QToolButton *bkManageBtn;
    QToolButton *readerManageBtn;
    QToolButton *logManageBtn;
    QWidget *page_2;
    QFormLayout *formLayout_3;
    QToolButton *lendRecordBtn;
    QToolButton *userTableBtn;
    QToolButton *bookStatBtn;
    QToolButton *overDueBtn;
    QWidget *page;
    QFormLayout *formLayout_4;
    QToolButton *logonBtn;
    QToolButton *userManageBtn;
    QToolButton *logoutBtn;
    QToolButton *pwdModifyBtn;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menuReaderManage;
    QMenu *menuLogManage;
    QMenu *menuBookManage_2;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *BookSystemClass)
    {
        if (BookSystemClass->objectName().isEmpty())
            BookSystemClass->setObjectName(QString::fromUtf8("BookSystemClass"));
        BookSystemClass->setWindowModality(Qt::WindowModal);
        BookSystemClass->resize(888, 552);
        BookSystemClass->setMinimumSize(QSize(848, 535));
        BookSystemClass->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/lib.ico"), QSize(), QIcon::Normal, QIcon::Off);
        BookSystemClass->setWindowIcon(icon);
        BookSystemClass->setAutoFillBackground(true);
        BookSystemClass->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        BookSystemClass->setTabShape(QTabWidget::Rounded);
        login = new QAction(BookSystemClass);
        login->setObjectName(QString::fromUtf8("login"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setIcon(icon1);
        pwdModify = new QAction(BookSystemClass);
        pwdModify->setObjectName(QString::fromUtf8("pwdModify"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/pwdmodify.png"), QSize(), QIcon::Normal, QIcon::Off);
        pwdModify->setIcon(icon2);
        logoff = new QAction(BookSystemClass);
        logoff->setObjectName(QString::fromUtf8("logoff"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoff->setIcon(icon3);
        exit = new QAction(BookSystemClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon4);
        addUser = new QAction(BookSystemClass);
        addUser->setObjectName(QString::fromUtf8("addUser"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/adduser.png"), QSize(), QIcon::Normal, QIcon::Off);
        addUser->setIcon(icon5);
        delUser = new QAction(BookSystemClass);
        delUser->setObjectName(QString::fromUtf8("delUser"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/deluser.png"), QSize(), QIcon::Normal, QIcon::Off);
        delUser->setIcon(icon6);
        updateUser = new QAction(BookSystemClass);
        updateUser->setObjectName(QString::fromUtf8("updateUser"));
        addBook = new QAction(BookSystemClass);
        addBook->setObjectName(QString::fromUtf8("addBook"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/addbooktitle.png"), QSize(), QIcon::Normal, QIcon::Off);
        addBook->setIcon(icon7);
        delBook = new QAction(BookSystemClass);
        delBook->setObjectName(QString::fromUtf8("delBook"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/delbooktitle.png"), QSize(), QIcon::Normal, QIcon::Off);
        delBook->setIcon(icon8);
        lendBook = new QAction(BookSystemClass);
        lendBook->setObjectName(QString::fromUtf8("lendBook"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/lendbook.png"), QSize(), QIcon::Normal, QIcon::Off);
        lendBook->setIcon(icon9);
        returnBook = new QAction(BookSystemClass);
        returnBook->setObjectName(QString::fromUtf8("returnBook"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/returnbook.png"), QSize(), QIcon::Normal, QIcon::Off);
        returnBook->setIcon(icon10);
        renewal = new QAction(BookSystemClass);
        renewal->setObjectName(QString::fromUtf8("renewal"));
        queryBook = new QAction(BookSystemClass);
        queryBook->setObjectName(QString::fromUtf8("queryBook"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icon/querybook.png"), QSize(), QIcon::Normal, QIcon::Off);
        queryBook->setIcon(icon11);
        lendRecord = new QAction(BookSystemClass);
        lendRecord->setObjectName(QString::fromUtf8("lendRecord"));
        lendSta = new QAction(BookSystemClass);
        lendSta->setObjectName(QString::fromUtf8("lendSta"));
        overdueRec = new QAction(BookSystemClass);
        overdueRec->setObjectName(QString::fromUtf8("overdueRec"));
        helpDoc = new QAction(BookSystemClass);
        helpDoc->setObjectName(QString::fromUtf8("helpDoc"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icon/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpDoc->setIcon(icon12);
        about = new QAction(BookSystemClass);
        about->setObjectName(QString::fromUtf8("about"));
        userList = new QAction(BookSystemClass);
        userList->setObjectName(QString::fromUtf8("userList"));
        bookList = new QAction(BookSystemClass);
        bookList->setObjectName(QString::fromUtf8("bookList"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icon/booklist.png"), QSize(), QIcon::Normal, QIcon::Off);
        bookList->setIcon(icon13);
        showGPS = new QAction(BookSystemClass);
        showGPS->setObjectName(QString::fromUtf8("showGPS"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icon/closeGPS.png"), QSize(), QIcon::Normal, QIcon::Off);
        showGPS->setIcon(icon14);
        addReader = new QAction(BookSystemClass);
        addReader->setObjectName(QString::fromUtf8("addReader"));
        delReader = new QAction(BookSystemClass);
        delReader->setObjectName(QString::fromUtf8("delReader"));
        readerTable = new QAction(BookSystemClass);
        readerTable->setObjectName(QString::fromUtf8("readerTable"));
        userLog = new QAction(BookSystemClass);
        userLog->setObjectName(QString::fromUtf8("userLog"));
        bookLog = new QAction(BookSystemClass);
        bookLog->setObjectName(QString::fromUtf8("bookLog"));
        updateReader = new QAction(BookSystemClass);
        updateReader->setObjectName(QString::fromUtf8("updateReader"));
        updateBook = new QAction(BookSystemClass);
        updateBook->setObjectName(QString::fromUtf8("updateBook"));
        centralwidget = new QWidget(BookSystemClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setMinimumSize(QSize(125, 0));
        toolBox->setMaximumSize(QSize(125, 16777215));
        toolBox->setCursor(QCursor(Qt::ArrowCursor));
        toolBox->setMouseTracking(true);
        toolBox->setFocusPolicy(Qt::NoFocus);
        toolBox->setAutoFillBackground(false);
        toolBox->setFrameShape(QFrame::WinPanel);
        toolBox->setFrameShadow(QFrame::Sunken);
        toolBox->setLineWidth(1);
        toolBox->setMidLineWidth(0);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 104, 368));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        bkLendBtn = new QToolButton(widget);
        bkLendBtn->setObjectName(QString::fromUtf8("bkLendBtn"));
        bkLendBtn->setMinimumSize(QSize(80, 80));
        bkLendBtn->setMaximumSize(QSize(80, 80));
        bkLendBtn->setCursor(QCursor(Qt::PointingHandCursor));
        bkLendBtn->setMouseTracking(true);
        bkLendBtn->setLayoutDirection(Qt::LeftToRight);
        bkLendBtn->setIcon(icon9);
        bkLendBtn->setIconSize(QSize(48, 48));
        bkLendBtn->setCheckable(false);
        bkLendBtn->setAutoRepeat(false);
        bkLendBtn->setAutoExclusive(false);
        bkLendBtn->setPopupMode(QToolButton::DelayedPopup);
        bkLendBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        bkLendBtn->setAutoRaise(true);
        bkLendBtn->setArrowType(Qt::NoArrow);

        formLayout->setWidget(2, QFormLayout::LabelRole, bkLendBtn);

        bkReturnBtn = new QToolButton(widget);
        bkReturnBtn->setObjectName(QString::fromUtf8("bkReturnBtn"));
        bkReturnBtn->setMinimumSize(QSize(80, 80));
        bkReturnBtn->setMaximumSize(QSize(80, 80));
        bkReturnBtn->setCursor(QCursor(Qt::PointingHandCursor));
        bkReturnBtn->setIcon(icon10);
        bkReturnBtn->setIconSize(QSize(48, 48));
        bkReturnBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        bkReturnBtn->setAutoRaise(true);

        formLayout->setWidget(3, QFormLayout::LabelRole, bkReturnBtn);

        bkQueryBtn = new QToolButton(widget);
        bkQueryBtn->setObjectName(QString::fromUtf8("bkQueryBtn"));
        bkQueryBtn->setMinimumSize(QSize(80, 80));
        bkQueryBtn->setMaximumSize(QSize(80, 80));
        bkQueryBtn->setCursor(QCursor(Qt::PointingHandCursor));
        bkQueryBtn->setIcon(icon11);
        bkQueryBtn->setIconSize(QSize(48, 48));
        bkQueryBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        bkQueryBtn->setAutoRaise(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, bkQueryBtn);

        bkRenewalBtn = new QToolButton(widget);
        bkRenewalBtn->setObjectName(QString::fromUtf8("bkRenewalBtn"));
        bkRenewalBtn->setMinimumSize(QSize(80, 80));
        bkRenewalBtn->setMaximumSize(QSize(80, 80));
        bkRenewalBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icon/renewal .png"), QSize(), QIcon::Normal, QIcon::Off);
        bkRenewalBtn->setIcon(icon15);
        bkRenewalBtn->setIconSize(QSize(48, 48));
        bkRenewalBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        bkRenewalBtn->setAutoRaise(true);

        formLayout->setWidget(5, QFormLayout::LabelRole, bkRenewalBtn);

        toolBox->addItem(widget, QString::fromUtf8("GernelOperation"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 121, 359));
        formLayout_2 = new QFormLayout(page_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        bkManageBtn = new QToolButton(page_3);
        bkManageBtn->setObjectName(QString::fromUtf8("bkManageBtn"));
        bkManageBtn->setMinimumSize(QSize(80, 80));
        bkManageBtn->setMaximumSize(QSize(80, 80));
        bkManageBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icon/bookmanage.png"), QSize(), QIcon::Normal, QIcon::Off);
        bkManageBtn->setIcon(icon16);
        bkManageBtn->setIconSize(QSize(48, 48));
        bkManageBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        bkManageBtn->setAutoRaise(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, bkManageBtn);

        readerManageBtn = new QToolButton(page_3);
        readerManageBtn->setObjectName(QString::fromUtf8("readerManageBtn"));
        readerManageBtn->setMinimumSize(QSize(80, 80));
        readerManageBtn->setMaximumSize(QSize(80, 80));
        readerManageBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icon/reader.png"), QSize(), QIcon::Normal, QIcon::Off);
        readerManageBtn->setIcon(icon17);
        readerManageBtn->setIconSize(QSize(48, 48));
        readerManageBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        readerManageBtn->setAutoRaise(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, readerManageBtn);

        logManageBtn = new QToolButton(page_3);
        logManageBtn->setObjectName(QString::fromUtf8("logManageBtn"));
        logManageBtn->setMinimumSize(QSize(80, 80));
        logManageBtn->setMaximumSize(QSize(80, 80));
        logManageBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icon/logmanage.png"), QSize(), QIcon::Normal, QIcon::Off);
        logManageBtn->setIcon(icon18);
        logManageBtn->setIconSize(QSize(48, 48));
        logManageBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        logManageBtn->setAutoRaise(true);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, logManageBtn);

        toolBox->addItem(page_3, QString::fromUtf8("DataManage"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 104, 362));
        formLayout_3 = new QFormLayout(page_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        lendRecordBtn = new QToolButton(page_2);
        lendRecordBtn->setObjectName(QString::fromUtf8("lendRecordBtn"));
        lendRecordBtn->setMinimumSize(QSize(80, 80));
        lendRecordBtn->setMaximumSize(QSize(80, 80));
        lendRecordBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icon/lendrecord.png"), QSize(), QIcon::Normal, QIcon::Off);
        lendRecordBtn->setIcon(icon19);
        lendRecordBtn->setIconSize(QSize(48, 48));
        lendRecordBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        lendRecordBtn->setAutoRaise(true);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, lendRecordBtn);

        userTableBtn = new QToolButton(page_2);
        userTableBtn->setObjectName(QString::fromUtf8("userTableBtn"));
        userTableBtn->setMinimumSize(QSize(80, 80));
        userTableBtn->setMaximumSize(QSize(80, 80));
        userTableBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icon/usertable.png"), QSize(), QIcon::Normal, QIcon::Off);
        userTableBtn->setIcon(icon20);
        userTableBtn->setIconSize(QSize(48, 48));
        userTableBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        userTableBtn->setAutoRaise(true);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, userTableBtn);

        bookStatBtn = new QToolButton(page_2);
        bookStatBtn->setObjectName(QString::fromUtf8("bookStatBtn"));
        bookStatBtn->setMinimumSize(QSize(80, 80));
        bookStatBtn->setMaximumSize(QSize(80, 80));
        bookStatBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icon/bookstat.png"), QSize(), QIcon::Normal, QIcon::Off);
        bookStatBtn->setIcon(icon21);
        bookStatBtn->setIconSize(QSize(48, 48));
        bookStatBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        bookStatBtn->setAutoRaise(true);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, bookStatBtn);

        overDueBtn = new QToolButton(page_2);
        overDueBtn->setObjectName(QString::fromUtf8("overDueBtn"));
        overDueBtn->setMinimumSize(QSize(80, 80));
        overDueBtn->setMaximumSize(QSize(80, 80));
        overDueBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icon/overduerecord.png"), QSize(), QIcon::Normal, QIcon::Off);
        overDueBtn->setIcon(icon22);
        overDueBtn->setIconSize(QSize(48, 48));
        overDueBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        overDueBtn->setAutoRaise(true);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, overDueBtn);

        toolBox->addItem(page_2, QString::fromUtf8("Statistic"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 121, 359));
        formLayout_4 = new QFormLayout(page);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        logonBtn = new QToolButton(page);
        logonBtn->setObjectName(QString::fromUtf8("logonBtn"));
        logonBtn->setMinimumSize(QSize(80, 80));
        logonBtn->setMaximumSize(QSize(80, 80));
        logonBtn->setCursor(QCursor(Qt::PointingHandCursor));
        logonBtn->setIcon(icon1);
        logonBtn->setIconSize(QSize(48, 48));
        logonBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        logonBtn->setAutoRaise(true);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, logonBtn);

        userManageBtn = new QToolButton(page);
        userManageBtn->setObjectName(QString::fromUtf8("userManageBtn"));
        userManageBtn->setMinimumSize(QSize(80, 80));
        userManageBtn->setMaximumSize(QSize(80, 80));
        userManageBtn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icon/usermanage.png"), QSize(), QIcon::Normal, QIcon::Off);
        userManageBtn->setIcon(icon23);
        userManageBtn->setIconSize(QSize(48, 48));
        userManageBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        userManageBtn->setAutoRaise(true);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, userManageBtn);

        logoutBtn = new QToolButton(page);
        logoutBtn->setObjectName(QString::fromUtf8("logoutBtn"));
        logoutBtn->setMinimumSize(QSize(80, 80));
        logoutBtn->setMaximumSize(QSize(80, 80));
        logoutBtn->setCursor(QCursor(Qt::PointingHandCursor));
        logoutBtn->setIcon(icon3);
        logoutBtn->setIconSize(QSize(48, 48));
        logoutBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        logoutBtn->setAutoRaise(true);

        formLayout_4->setWidget(3, QFormLayout::LabelRole, logoutBtn);

        pwdModifyBtn = new QToolButton(page);
        pwdModifyBtn->setObjectName(QString::fromUtf8("pwdModifyBtn"));
        pwdModifyBtn->setMinimumSize(QSize(80, 80));
        pwdModifyBtn->setMaximumSize(QSize(80, 80));
        pwdModifyBtn->setCursor(QCursor(Qt::PointingHandCursor));
        pwdModifyBtn->setIcon(icon2);
        pwdModifyBtn->setIconSize(QSize(48, 48));
        pwdModifyBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pwdModifyBtn->setAutoRaise(true);

        formLayout_4->setWidget(2, QFormLayout::LabelRole, pwdModifyBtn);

        toolBox->addItem(page, QString::fromUtf8("SystemSet"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);

        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setFrameShape(QFrame::WinPanel);
        mdiArea->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(mdiArea, 0, 1, 1, 1);

        BookSystemClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BookSystemClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 888, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menuReaderManage = new QMenu(menu_3);
        menuReaderManage->setObjectName(QString::fromUtf8("menuReaderManage"));
        menuLogManage = new QMenu(menu_3);
        menuLogManage->setObjectName(QString::fromUtf8("menuLogManage"));
        menuBookManage_2 = new QMenu(menu_3);
        menuBookManage_2->setObjectName(QString::fromUtf8("menuBookManage_2"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menu_4);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName(QString::fromUtf8("menu_6"));
        BookSystemClass->setMenuBar(menubar);
        statusbar = new QStatusBar(BookSystemClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BookSystemClass->setStatusBar(statusbar);
        toolBar = new QToolBar(BookSystemClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMinimumSize(QSize(0, 0));
        BookSystemClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_6->menuAction());
        menu->addAction(login);
        menu->addSeparator();
        menu->addAction(menu_2->menuAction());
        menu->addAction(pwdModify);
        menu->addSeparator();
        menu->addAction(logoff);
        menu->addAction(exit);
        menu_2->addAction(addUser);
        menu_2->addAction(delUser);
        menu_2->addAction(updateUser);
        menu_2->addAction(userList);
        menu_3->addAction(menuBookManage_2->menuAction());
        menu_3->addAction(menuReaderManage->menuAction());
        menu_3->addAction(menuLogManage->menuAction());
        menuReaderManage->addAction(addReader);
        menuReaderManage->addAction(delReader);
        menuReaderManage->addAction(updateReader);
        menuReaderManage->addAction(readerTable);
        menuLogManage->addAction(userLog);
        menuLogManage->addAction(bookLog);
        menuBookManage_2->addAction(addBook);
        menuBookManage_2->addAction(delBook);
        menuBookManage_2->addAction(updateBook);
        menuBookManage_2->addAction(bookList);
        menu_4->addAction(lendBook);
        menu_4->addAction(returnBook);
        menu_4->addAction(renewal);
        menu_4->addSeparator();
        menu_4->addAction(menu_5->menuAction());
        menu_5->addAction(queryBook);
        menu_5->addAction(lendRecord);
        menu_5->addSeparator();
        menu_5->addAction(lendSta);
        menu_5->addAction(overdueRec);
        menu_6->addAction(helpDoc);
        menu_6->addSeparator();
        menu_6->addAction(about);
        toolBar->addSeparator();
        toolBar->addAction(showGPS);

        retranslateUi(BookSystemClass);

        toolBox->setCurrentIndex(3);
        toolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(BookSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *BookSystemClass)
    {
        BookSystemClass->setWindowTitle(QApplication::translate("BookSystemClass", "BookSystem", 0, QApplication::UnicodeUTF8));
        login->setText(QApplication::translate("BookSystemClass", "Logon", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        login->setToolTip(QApplication::translate("BookSystemClass", "Logon", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pwdModify->setText(QApplication::translate("BookSystemClass", "PwdModify", 0, QApplication::UnicodeUTF8));
        logoff->setText(QApplication::translate("BookSystemClass", "Logout", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("BookSystemClass", "&Exit", 0, QApplication::UnicodeUTF8));
        addUser->setText(QApplication::translate("BookSystemClass", "AddUser", 0, QApplication::UnicodeUTF8));
        delUser->setText(QApplication::translate("BookSystemClass", "DelUser", 0, QApplication::UnicodeUTF8));
        updateUser->setText(QApplication::translate("BookSystemClass", "UpdateUser", 0, QApplication::UnicodeUTF8));
        addBook->setText(QApplication::translate("BookSystemClass", "AddBook", 0, QApplication::UnicodeUTF8));
        delBook->setText(QApplication::translate("BookSystemClass", "DeleteBook", 0, QApplication::UnicodeUTF8));
        lendBook->setText(QApplication::translate("BookSystemClass", "Lend", 0, QApplication::UnicodeUTF8));
        returnBook->setText(QApplication::translate("BookSystemClass", "Return", 0, QApplication::UnicodeUTF8));
        renewal->setText(QApplication::translate("BookSystemClass", "Renewal", 0, QApplication::UnicodeUTF8));
        queryBook->setText(QApplication::translate("BookSystemClass", "QueryBook", 0, QApplication::UnicodeUTF8));
        lendRecord->setText(QApplication::translate("BookSystemClass", "LendRecord", 0, QApplication::UnicodeUTF8));
        lendSta->setText(QApplication::translate("BookSystemClass", "LendStatistics", 0, QApplication::UnicodeUTF8));
        overdueRec->setText(QApplication::translate("BookSystemClass", "Overdue record", 0, QApplication::UnicodeUTF8));
        helpDoc->setText(QApplication::translate("BookSystemClass", "HelpDocument", 0, QApplication::UnicodeUTF8));
        about->setText(QApplication::translate("BookSystemClass", "&About", 0, QApplication::UnicodeUTF8));
        userList->setText(QApplication::translate("BookSystemClass", "UserTable", 0, QApplication::UnicodeUTF8));
        bookList->setText(QApplication::translate("BookSystemClass", "BookTable", 0, QApplication::UnicodeUTF8));
        showGPS->setText(QApplication::translate("BookSystemClass", "CloseGPS", 0, QApplication::UnicodeUTF8));
        addReader->setText(QApplication::translate("BookSystemClass", "AddReader", 0, QApplication::UnicodeUTF8));
        delReader->setText(QApplication::translate("BookSystemClass", "DelReader", 0, QApplication::UnicodeUTF8));
        readerTable->setText(QApplication::translate("BookSystemClass", "ReaderTable", 0, QApplication::UnicodeUTF8));
        userLog->setText(QApplication::translate("BookSystemClass", "UserLog", 0, QApplication::UnicodeUTF8));
        bookLog->setText(QApplication::translate("BookSystemClass", "BookLog", 0, QApplication::UnicodeUTF8));
        updateReader->setText(QApplication::translate("BookSystemClass", "UpdateReader", 0, QApplication::UnicodeUTF8));
        updateBook->setText(QApplication::translate("BookSystemClass", "UpdateBook", 0, QApplication::UnicodeUTF8));
        bkLendBtn->setText(QApplication::translate("BookSystemClass", "LendBook", 0, QApplication::UnicodeUTF8));
        bkReturnBtn->setText(QApplication::translate("BookSystemClass", "ReturnBook", 0, QApplication::UnicodeUTF8));
        bkQueryBtn->setText(QApplication::translate("BookSystemClass", "QueryBook", 0, QApplication::UnicodeUTF8));
        bkRenewalBtn->setText(QApplication::translate("BookSystemClass", "renewal", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(widget), QApplication::translate("BookSystemClass", "GernelOperation", 0, QApplication::UnicodeUTF8));
        bkManageBtn->setText(QApplication::translate("BookSystemClass", "BookManage", 0, QApplication::UnicodeUTF8));
        readerManageBtn->setText(QApplication::translate("BookSystemClass", "ReaderManage", 0, QApplication::UnicodeUTF8));
        logManageBtn->setText(QApplication::translate("BookSystemClass", "LogManage", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("BookSystemClass", "DataManage", 0, QApplication::UnicodeUTF8));
        lendRecordBtn->setText(QApplication::translate("BookSystemClass", "LendRecord", 0, QApplication::UnicodeUTF8));
        userTableBtn->setText(QApplication::translate("BookSystemClass", "UserTable", 0, QApplication::UnicodeUTF8));
        bookStatBtn->setText(QApplication::translate("BookSystemClass", "BookStat", 0, QApplication::UnicodeUTF8));
        overDueBtn->setText(QApplication::translate("BookSystemClass", "OverDueRec", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("BookSystemClass", "Statistic", 0, QApplication::UnicodeUTF8));
        logonBtn->setText(QApplication::translate("BookSystemClass", "Logon", 0, QApplication::UnicodeUTF8));
        userManageBtn->setText(QApplication::translate("BookSystemClass", "UserManage", 0, QApplication::UnicodeUTF8));
        logoutBtn->setText(QApplication::translate("BookSystemClass", "LogOut", 0, QApplication::UnicodeUTF8));
        pwdModifyBtn->setText(QApplication::translate("BookSystemClass", "PwdModify", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("BookSystemClass", "SystemSet", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("BookSystemClass", "Manager", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("BookSystemClass", "User Manage", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("BookSystemClass", "DataManage", 0, QApplication::UnicodeUTF8));
        menuReaderManage->setTitle(QApplication::translate("BookSystemClass", "ReaderManage", 0, QApplication::UnicodeUTF8));
        menuLogManage->setTitle(QApplication::translate("BookSystemClass", "LogManage", 0, QApplication::UnicodeUTF8));
        menuBookManage_2->setTitle(QApplication::translate("BookSystemClass", "BookManage", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("BookSystemClass", "Lend/Return", 0, QApplication::UnicodeUTF8));
        menu_5->setTitle(QApplication::translate("BookSystemClass", "Query/Statistics", 0, QApplication::UnicodeUTF8));
        menu_6->setTitle(QApplication::translate("BookSystemClass", "&Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("BookSystemClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_BOOKSYSTEM_H


#ifndef UI_SERVERIP_H
#define UI_SERVERIP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
class UiServerIPClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *connBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitBtn;
    QLineEdit *ipEdit;

    void setupUi(QDialog *ServerIPClass)
    {
        if (ServerIPClass->objectName().isEmpty())
            ServerIPClass->setObjectName(QString::fromUtf8("ServerIPClass"));
        ServerIPClass->resize(252, 96);
        ServerIPClass->setMinimumSize(QSize(252, 96));
        ServerIPClass->setMaximumSize(QSize(252, 96));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/connserver.png"), QSize(), QIcon::Normal, QIcon::Off);
        ServerIPClass->setWindowIcon(icon);
        gridLayout = new QGridLayout(ServerIPClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ServerIPClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        connBtn = new QPushButton(ServerIPClass);
        connBtn->setObjectName(QString::fromUtf8("connBtn"));

        gridLayout->addWidget(connBtn, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        exitBtn = new QPushButton(ServerIPClass);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        gridLayout->addWidget(exitBtn, 1, 3, 1, 1);

        ipEdit = new QLineEdit(ServerIPClass);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));

        gridLayout->addWidget(ipEdit, 0, 1, 1, 3);


        retranslateUi(ServerIPClass);

        QMetaObject::connectSlotsByName(ServerIPClass);
    } // setupUi

    void retranslateUi(QDialog *ServerIPClass)
    {
        ServerIPClass->setWindowTitle(QApplication::translate("ServerIPClass", "ServerIP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ServerIPClass", "Server IP:", 0, QApplication::UnicodeUTF8));
        connBtn->setText(QApplication::translate("ServerIPClass", "&Connect", 0, QApplication::UnicodeUTF8));
        exitBtn->setText(QApplication::translate("ServerIPClass", "&Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_SERVERIP_H

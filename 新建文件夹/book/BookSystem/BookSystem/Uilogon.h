

#ifndef UI_LOGON_H
#define UI_LOGON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

class UiLogonClass
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *idEdit;
    QLineEdit *passEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *logonBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *LogonClass)
    {
        if (LogonClass->objectName().isEmpty())
            LogonClass->setObjectName(QString::fromUtf8("LogonClass"));
        LogonClass->resize(322, 217);
        LogonClass->setMinimumSize(QSize(322, 217));
        LogonClass->setMaximumSize(QSize(322, 217));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        LogonClass->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(LogonClass);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 20, 221, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        idEdit = new QLineEdit(gridLayoutWidget);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 1);

        passEdit = new QLineEdit(gridLayoutWidget);
        passEdit->setObjectName(QString::fromUtf8("passEdit"));
        passEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passEdit, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(91, 23));
        comboBox->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(comboBox, 3, 1, 1, 1);

        logonBtn = new QPushButton(LogonClass);
        logonBtn->setObjectName(QString::fromUtf8("logonBtn"));
        logonBtn->setGeometry(QRect(190, 160, 81, 23));
        logonBtn->setMinimumSize(QSize(81, 23));
        logonBtn->setMaximumSize(QSize(81, 23));
        cancelBtn = new QPushButton(LogonClass);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(50, 160, 81, 23));
        cancelBtn->setMinimumSize(QSize(81, 23));
        cancelBtn->setMaximumSize(QSize(81, 23));

        retranslateUi(LogonClass);

        QMetaObject::connectSlotsByName(LogonClass);
    } // setupUi

    void retranslateUi(QDialog *LogonClass)
    {
        LogonClass->setWindowTitle(QApplication::translate("LogonClass", "Logon", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        LogonClass->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("LogonClass", "UserID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LogonClass", "PassWord:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LogonClass", "Power:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LogonClass", "Administrator", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonClass", "Operator", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonClass", "Reader", 0, QApplication::UnicodeUTF8)
        );
        logonBtn->setText(QApplication::translate("LogonClass", "&Logon", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("LogonClass", "&Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_LOGON_H

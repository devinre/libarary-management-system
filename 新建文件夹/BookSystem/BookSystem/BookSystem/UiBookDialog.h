
#ifndef UI_BOOKDIALOG_H
#define UI_BOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

class UiBookDialogClass
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *confirmBtn;
    QLabel *label_3;
    QLineEdit *authorEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *pressEdit;
    QLabel *label_6;
    QDateEdit *pressDateBox;
    QLabel *label_7;
    QSpinBox *pageNumBox;
    QLabel *label_8;
    QDoubleSpinBox *priceBox;
    QLineEdit *typeEdit;
    QLineEdit *nameEdit;
    QLineEdit *idEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_10;
    QLineEdit *lendTimesEdit;
    QLabel *label_11;
    QComboBox *statusBox;
    QPushButton *cancelBtn;
    QPushButton *clearBtn;

    void setupUi(QDialog *BookDialogClass)
    {
        if (BookDialogClass->objectName().isEmpty())
            BookDialogClass->setObjectName(QString::fromUtf8("BookDialogClass"));
        BookDialogClass->resize(516, 434);
        BookDialogClass->setMinimumSize(QSize(516, 434));
        BookDialogClass->setMaximumSize(QSize(516, 434));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/booklist.png"), QSize(), QIcon::Normal, QIcon::Off);
        BookDialogClass->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(BookDialogClass);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 498, 416));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        confirmBtn = new QPushButton(gridLayoutWidget);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));

        gridLayout->addWidget(confirmBtn, 0, 5, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        authorEdit = new QLineEdit(gridLayoutWidget);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));
        authorEdit->setMaximumSize(QSize(170, 20));

        gridLayout->addWidget(authorEdit, 2, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        pressEdit = new QLineEdit(gridLayoutWidget);
        pressEdit->setObjectName(QString::fromUtf8("pressEdit"));
        pressEdit->setMaximumSize(QSize(170, 20));

        gridLayout->addWidget(pressEdit, 3, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        pressDateBox = new QDateEdit(gridLayoutWidget);
        pressDateBox->setObjectName(QString::fromUtf8("pressDateBox"));
        pressDateBox->setCalendarPopup(true);
        pressDateBox->setCurrentSectionIndex(0);
        pressDateBox->setTimeSpec(Qt::LocalTime);

        gridLayout->addWidget(pressDateBox, 3, 3, 1, 2);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        pageNumBox = new QSpinBox(gridLayoutWidget);
        pageNumBox->setObjectName(QString::fromUtf8("pageNumBox"));
        pageNumBox->setMaximumSize(QSize(170, 20));
        pageNumBox->setMaximum(999999999);

        gridLayout->addWidget(pageNumBox, 4, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 2, 1, 1);

        priceBox = new QDoubleSpinBox(gridLayoutWidget);
        priceBox->setObjectName(QString::fromUtf8("priceBox"));
        priceBox->setMaximum(1e+09);

        gridLayout->addWidget(priceBox, 4, 3, 1, 2);

        typeEdit = new QLineEdit(gridLayoutWidget);
        typeEdit->setObjectName(QString::fromUtf8("typeEdit"));

        gridLayout->addWidget(typeEdit, 2, 3, 1, 2);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 4);

        idEdit = new QLineEdit(gridLayoutWidget);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 4);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        lendTimesEdit = new QLineEdit(gridLayoutWidget);
        lendTimesEdit->setObjectName(QString::fromUtf8("lendTimesEdit"));
        lendTimesEdit->setEnabled(false);
        lendTimesEdit->setReadOnly(false);

        gridLayout->addWidget(lendTimesEdit, 5, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 5, 2, 1, 1);

        statusBox = new QComboBox(gridLayoutWidget);
        statusBox->setObjectName(QString::fromUtf8("statusBox"));

        gridLayout->addWidget(statusBox, 5, 3, 1, 1);

        cancelBtn = new QPushButton(gridLayoutWidget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 2, 5, 1, 1);

        clearBtn = new QPushButton(gridLayoutWidget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        gridLayout->addWidget(clearBtn, 1, 5, 1, 1);


        retranslateUi(BookDialogClass);

        QMetaObject::connectSlotsByName(BookDialogClass);
    } // setupUi

    void retranslateUi(QDialog *BookDialogClass)
    {
        BookDialogClass->setWindowTitle(QApplication::translate("BookDialogClass", "BookDialog", 0, QApplication::UnicodeUTF8));
        confirmBtn->setText(QApplication::translate("BookDialogClass", "&OK", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BookDialogClass", "Author:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BookDialogClass", "Type:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BookDialogClass", "Press:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BookDialogClass", "PublishDate:", 0, QApplication::UnicodeUTF8));
        pressDateBox->setDisplayFormat(QApplication::translate("BookDialogClass", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BookDialogClass", "PageNum", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BookDialogClass", "Price:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BookDialogClass", "*BookID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BookDialogClass", "*BookName:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BookDialogClass", "LendTimes:", 0, QApplication::UnicodeUTF8));
        lendTimesEdit->setText(QApplication::translate("BookDialogClass", "0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BookDialogClass", "Status:", 0, QApplication::UnicodeUTF8));
        statusBox->clear();
        statusBox->insertItems(0, QStringList()
         << QApplication::translate("BookDialogClass", "InLibrary", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BookDialogClass", "LendOut", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BookDialogClass", "Lost", 0, QApplication::UnicodeUTF8)
        );
        cancelBtn->setText(QApplication::translate("BookDialogClass", "&Cancel", 0, QApplication::UnicodeUTF8));
        clearBtn->setText(QApplication::translate("BookDialogClass", "&Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

#endif // UI_BOOKDIALOG_H

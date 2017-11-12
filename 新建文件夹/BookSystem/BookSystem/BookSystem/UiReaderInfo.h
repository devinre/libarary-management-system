
#ifndef UI_READERINFO_H
#define UI_READERINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

class UiReaderInfoClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QLabel *label_3;
    QSpinBox *lendDaysBox;

    void setupUi(QDialog *ReaderInfoClass)
    {
        if (ReaderInfoClass->objectName().isEmpty())
            ReaderInfoClass->setObjectName(QString::fromUtf8("ReaderInfoClass"));
        ReaderInfoClass->resize(314, 195);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/reader.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReaderInfoClass->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(ReaderInfoClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ReaderInfoClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idEdit = new QLineEdit(ReaderInfoClass);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 2);

        label_2 = new QLabel(ReaderInfoClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        nameEdit = new QLineEdit(ReaderInfoClass);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 2);

        cancelBtn = new QPushButton(ReaderInfoClass);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 3, 1, 1, 1);

        okBtn = new QPushButton(ReaderInfoClass);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout->addWidget(okBtn, 3, 2, 1, 1);

        label_3 = new QLabel(ReaderInfoClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lendDaysBox = new QSpinBox(ReaderInfoClass);
        lendDaysBox->setObjectName(QString::fromUtf8("lendDaysBox"));

        gridLayout->addWidget(lendDaysBox, 2, 1, 1, 2);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(ReaderInfoClass);

        QMetaObject::connectSlotsByName(ReaderInfoClass);
    } // setupUi

    void retranslateUi(QDialog *ReaderInfoClass)
    {
        ReaderInfoClass->setWindowTitle(QApplication::translate("ReaderInfoClass", "ReaderInfo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ReaderInfoClass", "ReaderID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ReaderInfoClass", "ReaderName:", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("ReaderInfoClass", "Cancel", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("ReaderInfoClass", "OK", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ReaderInfoClass", "LendDays:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};
#endif // UI_READERINFO_H

#include "BookDialog.h"

BookDialog::BookDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
	setModal(true);
	QObject::connect(confirmBtn, SIGNAL(clicked()), this, SLOT(SetBookInfo()));
	QObject::connect(clearBtn, SIGNAL(clicked()), this, SLOT(ClearTextInfo()));
	QObject::connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

BookDialog::~BookDialog()
{

}
void BookDialog::closeEvent(QCloseEvent *event)
{
	ClearTextInfo();
}
void BookDialog::SetBookInfo()
{
	BOOKINFO bookInfo;
	bool ok;
	QDate addDate;
	if (idEdit->text() == "" || nameEdit->text() == "" || typeEdit->text() == "")
	{
		QMessageBox::warning(this, tr("Warning"), tr("Input information incompletely!"));
		return;
	}
	bookInfo.sID = idEdit->text();
	bookInfo.sName = nameEdit->text();
	bookInfo.sAuthor = authorEdit->text();
	bookInfo.sType = typeEdit->text();
	bookInfo.sPress = pressEdit->text();
	bookInfo.sPressDate = pressDateBox->text();
	bookInfo.dwPageNum = pageNumBox->value();
	bookInfo.fPrice = priceBox->value();
	bookInfo.sAddDate = addDate.currentDate().toString(DATE);
	bookInfo.dwLendTimes = lendTimesEdit->text().toInt(&ok);
	bookInfo.dwStatus = statusBox->currentIndex();
	emit
	GetBookInfo(bookInfo);
}
void BookDialog::ClearTextInfo()
{
	nameEdit->setText("");
	authorEdit->setText("");
	typeEdit->setText("");
	pressEdit->setText("");
	pageNumBox->setValue(0);
	priceBox->setValue(0);
}

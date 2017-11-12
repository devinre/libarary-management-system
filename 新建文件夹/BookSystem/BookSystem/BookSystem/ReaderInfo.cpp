#include "ReaderInfo.h"

ReaderInfo::ReaderInfo(QWidget *parent)
    : QDialog(parent)
{
	setupUi(this);
	setModal(true);
	QObject::connect(okBtn, SIGNAL(clicked()), this, SLOT(GetReaderInfo()));
	QObject::connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
}

ReaderInfo::~ReaderInfo()
{

}
void ReaderInfo::GetReaderInfo()
{
	LENDINFO lendInfo;
	lendInfo.sReaderID = idEdit->text();
	lendInfo.sReader = nameEdit->text();
	lendInfo.dwLendDays = lendDaysBox->value();
	emit
	SetReaderInfo(lendInfo);
	this->close();
}

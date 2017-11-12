#ifndef READERINFO_H
#define READERINFO_H

#include <QtGui/QDialog>
#include "UiReaderInfo.h"
#include "GlobalDefine.h"
class ReaderInfo : public QDialog, public UiReaderInfoClass
{
    Q_OBJECT

public:
    ReaderInfo(QWidget *parent = 0);
    ~ReaderInfo();

private:
private slots:
	void GetReaderInfo();
signals:
	void SetReaderInfo(LENDINFO &);
};

#endif // READERINFO_H

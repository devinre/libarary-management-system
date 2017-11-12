#ifndef LENDMANAGE_H
#define LENDMANAGE_H

#include <QtGui/QMainWindow>
#include "UiLendManage.h"
#include "TableView.h"
#include "GlobalDefine.h"
#include "ReaderInfo.h"
class LendManage: public QMainWindow,
		public UiLendManageClass,
		public TableView
{
Q_OBJECT

public:
	void SetHorizontalHeader();
	LendManage(QWidget *parent = 0);
	~LendManage();
	void RecvResultInfo(const BOOKLOGINFO &);
	void InsertResponseBookInfo(MANAGEINFO &);
private:
	ReaderInfo *reader;
private slots:
	void DelLendInfo();
	void LendList();
	void SearchLend();
	void LendReturn();
	void LendRenewal(LENDINFO &);
	void GetRenewalInfo();
signals:
	void SendLendInfo(const MANAGEINFO &);
};

#endif // LENDMANAGE_H

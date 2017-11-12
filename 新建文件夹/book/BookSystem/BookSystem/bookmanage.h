#ifndef BOOKMANAGE_H
#define BOOKMANAGE_H

#include <QtGui/QMainWindow>
#include "Uibookmanage.h"
#include "TableView.h"
#include "BookDialog.h"
#include "ReaderInfo.h"
class BookManage : public QMainWindow, public UiBookManageClass, public TableView
{
    Q_OBJECT

public:
    BookManage(QWidget *parent = 0);
    ~BookManage();
    void SetHorizontalHeader();
    void RecvResultInfo(const BOOKLOGINFO &);
    void InsertResponseBookInfo(MANAGEINFO &);
    void SetEnabled(bool ok);
private:
	MANAGEINFO manageInfo;
	BookDialog *bkDlg;
	ReaderInfo *reader;
	QModelIndex gIndex;
	int row;
private slots:
	void SetBookTableInfo(const BOOKINFO &);
	void DelBookInfo();
	void UpdateBookInfo(const QModelIndex &);
	void AddBookInfo();
	/*void QueryBookInfo();*/
	void UpdateBookInfo();
	void BookList();
	void SearchBook();
	void LendOutBookInfo(LENDINFO &);
	void GetReaderInfo();
signals:
	void SendBookInfo(const MANAGEINFO &);
};

#endif // BOOKMANAGE_H

#ifndef BOOKLOGMANAGE_H
#define BOOKLOGMANAGE_H

#include <QtGui/QMainWindow>
#include "UiBookLogManage.h"
#include "TableView.h"
class BookLogManage : public QMainWindow, public UiBookLogManageClass, public TableView
{
    Q_OBJECT
public:
    BookLogManage(QWidget *parent = 0);
    ~BookLogManage();
    void SetHorizontalHeader();
    void InsertResponseBookLogInfo(MANAGEINFO &);
    void RecvResultInfo(const BOOKLOGINFO &);
private:
private slots:
	void RefreshBookLog();
	void DeleteAllBookLog();
signals:
	void SendBookLogInfo(const MANAGEINFO &);
};

#endif // BOOKLOGMANAGE_H

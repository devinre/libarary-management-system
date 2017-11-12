/*
 * TableView.h
 *
 *  Created on: 2010-4-18
 *      Author: Administrator
 */

#ifndef TABLEVIEW_H_
#define TABLEVIEW_H_
#include <QtGui/QApplication>
#include <QString>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMap>
#include <QTableView>
#include "GlobalDefine.h"
#define TR(STR) QApplication::translate("TableViewClass", STR, 0, QApplication::UnicodeUTF8)
class TableView
{
public:
	TableView(QWidget *parent = 0);
	virtual ~TableView();
	void SetTableView(QTableView *);
	virtual void SetHorizontalHeader();
	void SetUpModel(QWidget *);
	void SetTableData(MANAGEINFO &, int row = 0);//设置表格数据
	void GetRowData(const QModelIndex &, MANAGEINFO *);//获取数据表中一行数据
	QStandardItemModel *model;
	QMap<int, QString> sexMap;
	QMap<int, QString> userStatusMap;
	QMap<int, QString> bookStatusMap;
	QMap<int, QString> userOpMap;
	QMap<int, QString> bookOpMap;
	QMap<int, QString> readerTypeMap;
	QMap<int, QString> onlineMap;
	QMap<int, QString> powerMap;
private:
	////////////SetTableData/////////////////////
	void SetUserTableData(USERINFO &, int row = 0);//设置用户表数据
	void SetBookTableData(BOOKINFO &, int row = 0);//设置图书表数据
	void SetLendTableData(LENDINFO &, int row = 0);//设置借出表数据
	void SetReaderTableData(READERINFO &, int row = 0);//设置读者表数据
	void SetBookLogTableData(BOOKLOGINFO &, int row = 0);//设置书籍日志表数据
	void SetUserLogTableData(USERLOGINFO &, int row = 0);//设置用户日志表数据
	////////////GetRowData////////////////////////
	void GetRowUserData(const QModelIndex &, MANAGEINFO *);
	void GetRowBookData(const QModelIndex &, MANAGEINFO *);
	void GetRowReaderData(const QModelIndex &, MANAGEINFO *);
	void GetRowLendData(const QModelIndex &, MANAGEINFO *);
	QHeaderView *vHeader;
	QHeaderView *hHeader;
private:
	void GetManageInfo(MANAGEINFO &);
};

#endif /* TABLEVIEW_H_ */

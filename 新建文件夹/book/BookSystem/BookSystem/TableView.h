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
	void SetTableData(MANAGEINFO &, int row = 0);//���ñ������
	void GetRowData(const QModelIndex &, MANAGEINFO *);//��ȡ���ݱ���һ������
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
	void SetUserTableData(USERINFO &, int row = 0);//�����û�������
	void SetBookTableData(BOOKINFO &, int row = 0);//����ͼ�������
	void SetLendTableData(LENDINFO &, int row = 0);//���ý��������
	void SetReaderTableData(READERINFO &, int row = 0);//���ö��߱�����
	void SetBookLogTableData(BOOKLOGINFO &, int row = 0);//�����鼮��־������
	void SetUserLogTableData(USERLOGINFO &, int row = 0);//�����û���־������
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

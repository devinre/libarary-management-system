#pragma once

#include <QtWidgets/QWidget>
#include "ui_mywidget.h"
#include<QWizard>
class QErrorMessage;
class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget *parent = Q_NULLPTR);
	~MyWidget();

private:
	Ui::MyWidgetClass *ui;
	QWizardPage *createPage1();        // 新添加
	QWizardPage *createPage2();        // 新添加
	QWizardPage *createPage3();        // 新添加
	QErrorMessage *errordlg;
	private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_7_clicked();
	void on_pushButton_8_clicked();
};

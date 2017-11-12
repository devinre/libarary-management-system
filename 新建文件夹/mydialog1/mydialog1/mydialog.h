#pragma once

#include <QDialog>
#include "ui_mydialog.h"

class MyDialog : public QDialog
{
	Q_OBJECT

public:
	MyDialog(QWidget *parent = Q_NULLPTR);
	~MyDialog();

private:
	Ui::MyDialog *ui;
public slots:
	void on_pushButton_clicked();
};

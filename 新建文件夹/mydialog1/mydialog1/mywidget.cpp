#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include "mydialog.h"

MyWidget::MyWidget(QWidget *parent):
	QWidget(parent),
	ui(new Ui::MyWidgetClass)
{
	ui->setupUi(this);
	//connect(ui->showChildButton, &QPushButton::clicked, this, &MyWidget::showChildDialog);
}
void MyWidget::on_showChildButton_clicked()
{
	QDialog *dialog = new QDialog(this);
	dialog->show();
}
void MyWidget::on_pushButton_clicked()
{
	// �ȹر������棬��ʵ�������������ˣ���û�������˳���Ȼ���½�MyDialog����
	close();
	MyDialog dlg;
	// ��������ˡ����������ڡ���ť�����ٴ���ʾ������
	// ������Ϊ�����Ѿ�û����ʾ�Ľ����ˣ����Գ����˳�
	if (dlg.exec() == QDialog::Accepted) show();
}
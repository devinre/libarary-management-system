#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QMovie>
MyWidget::MyWidget(QWidget *parent)	:
	QWidget(parent),
	ui(new Ui::MyWidgetClass)
{
	ui->setupUi(this);
	QFont font;
	font.setFamily("�����п�");
	font.setPointSize(20);
	font.setBold(true);
	font.setItalic(true);
	ui->label->setFont(font);
	QString string = tr("����̫������Ҫ����ʡ�ԣ�");
	QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 180);
	ui->label->setText(str);
	ui->label->setPixmap(QPixmap("F:/libarary/logo.png"));
}

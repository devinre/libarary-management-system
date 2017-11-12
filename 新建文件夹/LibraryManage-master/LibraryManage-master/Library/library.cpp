#include "library.h"
#include "log_ctl.h"
#include "controller.h"
#include "User.h"
#include<algorithm>


Library::Library(QObject *parent)
    : QObject(parent)
{

	user_type = VISITOR;
	userName =  QString::fromLocal8Bit("�ο�");
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(updatetime()));
	timer->start(1000);
	titlelabel = new QLabel();
    LayoutWindow();

	log_ctl log("localhost", "root", "3140104431", "library");
	Island(log.log(sql));	//�жϲ���ʾ�Ƿ�
}

Library::~Library()
{
	//
	//���ܣ�ȡ�������ݿ������
	//
}

void Library::LayoutWindow()//��ʾ���崰��
{
	WholeWindow = new QWidget();
	VlayoutWhole = new QVBoxLayout();
	WholeWindow->setFixedSize(1024 * 1.2, 768 * 1.2);
	WholeWindow->setWindowTitle(QString::fromLocal8Bit("ͼ�����ϵͳ"));
	user_type = VISITOR;	//��ʼ�û����Ͷ���Ϊvisitor

	SetTitle();//���ñ������
	SetMainWidget();//����������

  
    VlayoutWhole->addWidget(Title);
	VlayoutWhole->addWidget(WholeTabwidget);

    WholeWindow->setLayout(VlayoutWhole);
    WholeWindow->show();
}

void Library::SetTitle()
{
	VLayoutTitle1 = new QVBoxLayout();
	HLayoutTitle1 = new QHBoxLayout();
	Title = new QWidget();
	
	QPalette palette;
	QDir d;
	Longon_in = new QPushButton(QString::fromLocal8Bit("��¼"));
	Longon_in->setFixedSize(120, 35);
	Longon_in->setFlat(true);
	/*���ñ���ͼƬ*/
	Title->setAutoFillBackground(true);
	palette.setBrush(QPalette::Background, QBrush(QPixmap(d.currentPath() + "/picture.jpg")));
	Title->setPalette(palette);

	HLayoutTitle1->addSpacing(750);
	HLayoutTitle1->addWidget(titlelabel);
	HLayoutTitle1->addWidget(Longon_in);
	VLayoutTitle1->addStretch();
	VLayoutTitle1->addLayout(HLayoutTitle1);
	Title->setFixedSize(WholeWindow->width()*0.98, WholeWindow->height()*0.14);
	Title->setLayout(VLayoutTitle1);

	connect(Longon_in, SIGNAL(clicked()), this, SLOT(setwindow02()));
}
void Library::Logon_out()
{
	Longon_outChangeWindow1();
	delete Longon_out;
	Longon_in = new QPushButton(QString::fromLocal8Bit("��¼"));
	Longon_in->setFixedSize(120, 35);
	Longon_in->setFlat(true);
	HLayoutTitle1->addWidget(Longon_in);
	userName = QString::fromLocal8Bit("�ο�");
	user_type = VISITOR;
	connect(Longon_in, SIGNAL(clicked()), this, SLOT(setwindow02()));
}


void Library::SetMainWidget()
{
	WholeTabwidget = new QTabWidget();
	setwindow1();
	//setwindow2();
	//setwindow3();
	//setwindow6();

	WholeTabwidget->addTab(window1, QString::fromLocal8Bit("ͼ�����"));
	//WholeTabwidget->addTab(window2, QString::fromLocal8Bit("�������"));
	//WholeTabwidget->addTab(window3, QString::fromLocal8Bit("�û�����"));
	//WholeTabwidget->addTab(window6, QString::fromLocal8Bit("�鼮����"));
}

void Library::setwindow1()
{
	const int num = 13;
	window1 = new QWidget();
	tree1 = new QTreeWidget();
	HLayout11 = new QHBoxLayout();
	tree1->setHeaderLabels(QStringList() << QString::fromLocal8Bit("�鼮����"));
	root1 = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit("����ͼ��"));
	tree1->addTopLevelItem(root1);
	QTreeWidgetItem* leaf[num];
	const char* booktype[] = {"��ѧ��","������","��Ȼ��ѧ��","�������","˼����","������","��ѧ��","������",
						"ҽѧ��","��ҵ����","������ѧ��","��ʷ��","������"};
	for (int i = 0; i < num; i++)
	{
		leaf[i] = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(booktype[i]));
		root1->addChild(leaf[i]);
	}
	HLayout11->addWidget(tree1);
	tree1->expandAll();
	tree1->setFixedWidth(200);


	/*�߼���������*/
	GLayout11 = new QGridLayout();
	VLayout13 = new QVBoxLayout();
	HLayout13 = new QHBoxLayout();
	VLayout14 = new QVBoxLayout();
	group11 = new QGroupBox();
	group12 = new QGroupBox();
	VLayout12 = new QVBoxLayout();
	Table1 = new QTableWidget();
	label1 = new QLabel[7];
	bookname = new QLineEdit(); author = new QLineEdit(); publisher = new QLineEdit();
	price1 = new QLineEdit(); price2 = new QLineEdit(); bookID = new QLineEdit();
	date1 = new QComboBox(); date2 = new QComboBox();
	check1 = new QCheckBox(QString::fromLocal8Bit("ֻѡ�����������鼮"));
	const char* str[] = {"����","����","������","��������","����","�۸�","����"};
	for (int i = 0; i < 7; i++)
		label1[i].setText(QString::fromLocal8Bit(str[i]));
	QLabel* Title = new QLabel();
	Title->setAlignment(Qt::AlignCenter);	//������ʾ
	Title->setText(QString::fromLocal8Bit("<h2>��ȷ����</h2>"));
	GLayout11->addWidget(new QLabel(QString::fromLocal8Bit("�鼮���")), 0, 0); GLayout11->addWidget(bookID, 0, 1);
	GLayout11->addWidget(&label1[0], 0, 2); GLayout11->addWidget(bookname, 0, 3);
	GLayout11->addWidget(&label1[1], 0, 4); GLayout11->addWidget(author, 0, 5);
	GLayout11->addWidget(&label1[3], 1, 0); GLayout11->addWidget(date1, 1, 1);
	GLayout11->addWidget(&label1[4], 1, 2); GLayout11->addWidget(date2, 1, 3);
	GLayout11->addWidget(&label1[2], 1, 4); GLayout11->addWidget(publisher, 1, 5);
	GLayout11->addWidget(&label1[5], 2, 0); GLayout11->addWidget(price1, 2, 1);
	GLayout11->addWidget(&label1[6], 2, 2); GLayout11->addWidget(price2, 2, 3);

	date1->addItem("    ");
	date2->addItem("    ");
	for (int i = 0; i<100; i++) {
		date1->addItem(QString::number(2016 - i));
		date2->addItem(QString::number(2016 - i));
	}
	
	VLayout13->addWidget(Title);
	VLayout13->addLayout(GLayout11);
	group11->setLayout(VLayout13);
	group11->setFixedSize(700, 140);

	Searchbutton = new QPushButton(QString::fromLocal8Bit("��ʼ����"));
	Searchbutton->setFixedHeight(35);
	VLayout14->addWidget(Searchbutton);
	VLayout14->addWidget(check1);
	group12->setLayout(VLayout14);
	HLayout13->addWidget(group11);
	HLayout13->setSpacing(50);
	HLayout13->addWidget(group12);
	
	const char* tableheader[] = {"","���","����","�۸�/Ԫ","ʣ��/��","�ѽ��/��","����","����","������","�������"};
	QStringList header;
	numitem1 = max(numitem1,20);
	/*rowcount��Ҫ���ݼ������������������������������СΪ20*/
	Table1->setRowCount(numitem1);	//���ݵó��Ľ������
	Table1->setColumnCount(10);	//�����õĻ���ʾ�������
	Table1->setEditTriggers(QAbstractItemView::NoEditTriggers);	//����Ϊֻ��ģʽ
	Table1->setSelectionMode(QAbstractItemView::NoSelection);	//����Ϊ����ѡ��
	for (int i = 0; i < 10; i++)
		header << QString::fromLocal8Bit(tableheader[i]);
	Table1->setHorizontalHeaderLabels(header);
	Table1->setColumnWidth(0, 80);
	for (int i = 1; i < 10; i++)
		Table1->setColumnWidth(i, 120);

	
	
	VLayout12->addLayout(HLayout13);
	VLayout12->addWidget(Table1);
	HLayout11->addLayout(VLayout12);
	window1->setLayout(HLayout11);
	

	connect(Searchbutton, SIGNAL(clicked()), this, SLOT(Query1()));	
	connect(tree1, SIGNAL(itemClicked(QTreeWidgetItem*, int)),this, SLOT(QueryTree1(QTreeWidgetItem*, int)));
}
void Library::Longon_inChangeWindow1()
{
	if (user_type == USER)
	{
		Borrowbutton = new QPushButton(QString::fromLocal8Bit("�����鼮"));
		Borrowbutton->setFixedSize(140, 35);
		HLayout12 = new QHBoxLayout();
		HLayout12->addStretch();
		HLayout12->addWidget(Borrowbutton);
		VLayout12->addLayout(HLayout12);

		Tablecheckitem1 = new QTableWidgetItem*[numitem1];
		for (int i = 0; i < numitem1; i++)
		{
			Tablecheckitem1[i] = new QTableWidgetItem();
			Tablecheckitem1[i]->setCheckState(Qt::Unchecked);
			Table1->setItem(i, 0, Tablecheckitem1[i]);
		}
		setwindow2();
		WholeTabwidget->addTab(window2, QString::fromLocal8Bit("�������"));
		connect(Borrowbutton, SIGNAL(clicked()), this, SLOT(Borrow_Book()));	
	}
	else if (user_type == MANAGER)
	{
		setwindow3();
		setwindow6();
		WholeTabwidget->addTab(window3, QString::fromLocal8Bit("�û�����"));
		WholeTabwidget->addTab(window6, QString::fromLocal8Bit("�鼮����"));
	}
}
void Library::Borrow_Book()
{
	string book_id;
	int num = 0;
	for (int i = 0; i < numbook1; i++)
	{
		/*�����ѡ��ѡ��*/
		if (Table1->item(i, 0)->checkState() == Qt::Checked)
		{
			if (Table1->item(i, 4)->text().toInt() > 0)
			{
				book_id = Table1->item(i, 1)->text().toStdString();
				int x = Control.borrowbook(userID.toStdString(), book_id, sql);
				if (x == 3)
				{
					num++;
					QString s4 = Table1->item(i, 4)->text();
					Table1->item(i, 4)->setText(QString::number((s4.toInt() - 1), 10));
					QString s5 = Table1->item(i, 5)->text();
					Table1->item(i, 5)->setText(QString::number((s5.toInt() + 1), 10));
				}
			}
			else continue;
		}
	}
	for (int i = 0; i < numitem1; i++)
		Table1->item(i, 0)->setCheckState(Qt::Unchecked);
	QString s = QString::number(num, 10);
	QMessageBox * message = new QMessageBox();
	if (num > 0)
	{
		message->setText(QString::fromLocal8Bit("<h3>�ɹ�����") + s + QString::fromLocal8Bit("����</h3>"));
		BookQuery querybook;
		Control.displayborrow(userID.toStdString(), querybook, sql);
		numbook2 = querybook.Catalog.size();

		if (num2 > 20)
			for (int i = 0; i < num2; i++)
				delete Table2->item(i, 0);

		num2 = max(num2,(numbook2 > 20) ? numbook2 : 20);

		Table2->setRowCount(num2);
		if (num2 > 20)
			Tablecheckitem2 = new QTableWidgetItem*[num2];
			for (int i = 0; i < num2; i++)
			{
				Tablecheckitem2[i] = new QTableWidgetItem();
				Tablecheckitem2[i]->setCheckState(Qt::Unchecked);
				Table2->setItem(i, 0, Tablecheckitem2[i]);
			}

		ShowBook2(querybook);
	}
	else message->setText(QString::fromLocal8Bit("<h3>����ʧ��</h3>"));
	message->setWindowTitle(QString::fromLocal8Bit("��ʾ"));
	message->show();
}
void Library::Longon_outChangeWindow1()
{
	if (user_type == USER)
	{
		delete Borrowbutton;
		delete HLayout12;
		for (int i = 0; i < numitem1; i++)
			delete Table1->item(i, 0);
		delete Tablecheckitem1;
		delete window2;
	}
	if (user_type == MANAGER)
	{
		delete window3;
		delete window7;
		delete window8;
		delete window9;
		delete window6;
	}
}
void Library::Query1()
{
	BookQuery query;
	query.book_id = bookID->text().toLocal8Bit();
	query.name = bookname->text().toLocal8Bit();
	query.author = author->text().toLocal8Bit();
	query.publisher = publisher->text().toLocal8Bit();
	query.low_price = price1->text().toDouble();
	query.high_price = price2->text().toDouble();
	query.begin_year = date1->currentText().toInt();
	query.end_year = date2->currentText().toInt();
	query.have_stock = (check1->checkState() == Qt::Checked);
	query.type = "";
	
	/*�����ݿ��еõ�����*/
	Control.select(query, sql);
	
	/*��ձ��*/
	for (int i = 0; i<numitem1; i++)
		for (int j = 0; j < 10; j++)
			delete Table1->item(i, j);

	if (query.Catalog.size() > 20)
		numitem1 = max(numitem1,query.Catalog.size());
	else numitem1 = max(numitem1,20);
	numbook1 = query.Catalog.size();
	Table1->setRowCount(numitem1);	
	if (user_type == USER)
	{
		Tablecheckitem1 = new QTableWidgetItem*[numitem1];
		for (int i = 0; i < numitem1; i++)
		{
			Tablecheckitem1[i] = new QTableWidgetItem();
			Tablecheckitem1[i]->setCheckState(Qt::Unchecked);
			Table1->setItem(i, 0, Tablecheckitem1[i]);
		}
	}

	for (int i = 0; i < query.Catalog.size();i++)
	{
		Table1->setItem(i, 1 , new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].book_id.c_str())));
		Table1->setItem(i, 2, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].name.c_str())));
		Table1->setItem(i, 3, new QTableWidgetItem(QString::number(query.Catalog[i].price,10,2)));
		Table1->setItem(i, 4, new QTableWidgetItem(QString::number(query.Catalog[i].stock,10)));
		Table1->setItem(i, 5, new QTableWidgetItem(QString::number(query.Catalog[i].num - query.Catalog[i].stock, 10)));
		Table1->setItem(i, 6, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].type.c_str())));
		Table1->setItem(i, 7, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].author.c_str())));
		Table1->setItem(i, 8, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].publisher.c_str())));
		Table1->setItem(i, 9, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].publish_date.c_str())));
	}
}
void Library::QueryTree1(QTreeWidgetItem* tree, int num)
{
	BookQuery query;
	query.type = tree->text(0).toLocal8Bit();
	const char* booktype[] = { "��ѧ��","������","��Ȼ��ѧ��","�������","˼����","������","��ѧ��","������",
		"ҽѧ��","��ҵ����","������ѧ��","��ʷ��","������" };
	query.book_id = bookID->text().toLocal8Bit();
	query.name = bookname->text().toLocal8Bit();
	query.author = author->text().toLocal8Bit();
	query.publisher = publisher->text().toLocal8Bit();
	query.low_price = price1->text().toDouble();
	query.high_price = price2->text().toDouble();
	query.begin_year = date1->currentText().toInt();
	query.end_year = date2->currentText().toInt();
	query.have_stock = (check1->checkState() == Qt::Checked);
	int  n = root1->childCount();
	
	/*�����ݿ��еõ�����*/
	Control.select(query, sql);

	/*��ձ��*/
	for (int i = 0; i<numitem1; i++)
		for (int j = 0; j < 10; j++)
			delete Table1->item(i, j);

	if (query.Catalog.size() > 20)
		numitem1 = max(numitem1,query.Catalog.size());
	else numitem1 = max(numitem1,20);
	numbook1 = query.Catalog.size();
	Table1->setRowCount(numitem1);

	if (user_type == USER)
	{
		Tablecheckitem1 = new QTableWidgetItem*[numitem1];
		for (int i = 0; i < numitem1; i++)
		{
			Tablecheckitem1[i] = new QTableWidgetItem();
			Tablecheckitem1[i]->setCheckState(Qt::Unchecked);
			Table1->setItem(i, 0, Tablecheckitem1[i]);
		}
	}

	for (int i = 0; i < query.Catalog.size(); i++)
	{
		Table1->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].book_id.c_str())));
		Table1->setItem(i, 2, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].name.c_str())));
		Table1->setItem(i, 3, new QTableWidgetItem(QString::number(query.Catalog[i].price, 10, 2)));
		Table1->setItem(i, 4, new QTableWidgetItem(QString::number(query.Catalog[i].stock, 10)));
		Table1->setItem(i, 5, new QTableWidgetItem(QString::number(query.Catalog[i].num - query.Catalog[i].stock, 10)));
		Table1->setItem(i, 6, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].type.c_str())));
		Table1->setItem(i, 7, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].author.c_str())));
		Table1->setItem(i, 8, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].publisher.c_str())));
		Table1->setItem(i, 9, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].publish_date.c_str())));
	}
}

void Library::setwindow2()
{
	window2 = new QWidget();
	Table2 = new QTableWidget();
	VLayout21 = new QVBoxLayout();
	HLayout21 = new QHBoxLayout();
	ReturnButton = new QPushButton(QString::fromLocal8Bit("�黹�鼮"));
	Button21 = new QPushButton(QString::fromLocal8Bit("ȫѡ"));
	ReturnButton->setFixedSize(150, 35); Button21->setFixedSize(150, 35);
	const char* tableheader[] = { " ","���","����","����","�۸�","��������","�黹����","ʣ������"};
	QStringList header;

	/*rowcount��Ҫ���ݼ������������������������������СΪ20*/
	BookQuery querybook;
	Control.displayborrow(userID.toStdString(), querybook, sql);
	numbook2 = querybook.Catalog.size();
	num2 = max(num2,(numbook2 > 20) ? numbook2 : 20);

	Table2->setRowCount(num2);	//���ݵó��Ľ������
	Table2->setColumnCount(8);	//�����õĻ���ʾ�������
	Table2->setEditTriggers(QAbstractItemView::NoEditTriggers);	//����Ϊֻ��ģʽ
	Table2->setSelectionMode(QAbstractItemView::NoSelection);	//����Ϊ����ѡ��
	for (int i = 0; i < 8; i++)
		header << QString::fromLocal8Bit(tableheader[i]);
	Table2->setHorizontalHeaderLabels(header);

	/*��������ʱ�ǵ�delete������ĸ����ɺ����ķ���ֵȷ������СΪ20*/
	Tablecheckitem2 = new QTableWidgetItem*[num2];
	for (int i = 0; i < num2; i++)
	{
		Tablecheckitem2[i] = new QTableWidgetItem();
		Tablecheckitem2[i]->setCheckState(Qt::Unchecked);
		Table2->setItem(i, 0, Tablecheckitem2[i]);
	}

	Table2->setColumnWidth(0, 100);
	for (int i = 1; i < 8; i++)
		Table2->setColumnWidth(i, 150);

	HLayout21->addStretch();
	HLayout21->addWidget(Button21);
	HLayout21->addWidget(ReturnButton);
	VLayout21->addWidget(Table2);
	VLayout21->addLayout(HLayout21);
	window2->setLayout(VLayout21);

	ShowBook2(querybook);
	connect(Button21, SIGNAL(clicked()), this, SLOT(setbutton21()));	//ȫѡ����2�еĹ�ѡ��
	connect(ReturnButton, SIGNAL(clicked()), this, SLOT(Return_Book()));
}
void Library::ShowBook2(BookQuery& querybook)
{
	Borrow borrow;
	for (int i = 0; i < num2; i++)
		for (int j = 1; j < 8; j++)
			delete Table2->item(i, j);

	for (int i = 0; i < numbook2; i++)
	{
		Table2->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(querybook.Catalog[i].book_id.c_str())));
		Table2->setItem(i, 2, new QTableWidgetItem(QString::fromLocal8Bit(querybook.Catalog[i].name.c_str())));
		Table2->setItem(i, 3, new QTableWidgetItem(QString::fromLocal8Bit(querybook.Catalog[i].type.c_str())));
		Table2->setItem(i, 4, new QTableWidgetItem(QString::QString::number(querybook.Catalog[i].price, 10, 2)));
		borrow.book_id = querybook.Catalog[i].book_id;
		borrow.user_id = userID.toStdString();
		Control.SelectBorrow(borrow, sql);
		QDateTime current_date_time = QDateTime::currentDateTime();
		int year = QString::fromStdString(borrow.return_date.substr(0, 4)).toInt();
		int month = QString::fromStdString(borrow.return_date.substr(5, 2)).toInt();
		int day = QString::fromStdString(borrow.return_date.substr(8, 2)).toInt();
		QDateTime return_date(QDate(year, month, day), QTime(23, 59));
		int t = current_date_time.daysTo(return_date);
		Table2->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(borrow.borrow_date)));
		Table2->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(borrow.return_date)));
		Table2->setItem(i, 7, new QTableWidgetItem(QString::number(t,10)));
	}
}
void Library::Return_Book()
{
	string book_id;
	int num = 0;
	for (int i = 0; i < numbook2; i++)
	{
		/*�����ѡ��ѡ��*/
		if (Table2->item(i, 0)->checkState() == Qt::Checked)
		{
			book_id = Table2->item(i, 1)->text().toStdString();
			int x = Control.returnbook(userID.toStdString(), book_id, sql);
			if (x == 1)
				num++;
		}
	}
	QString s = QString::number(num, 10);
	QMessageBox * message = new QMessageBox();
	if (num > 0)
	{
		message->setText(QString::fromLocal8Bit("<h3>�ɹ��黹") + s + QString::fromLocal8Bit("����</h3>"));
		BookQuery querybook;
		Control.displayborrow(userID.toStdString(), querybook, sql);
		numbook2 = querybook.Catalog.size();
		num2 = max(num2,(numbook2 > 20) ? numbook2 : 20);
		ShowBook2(querybook);
	}
	else message->setText(QString::fromLocal8Bit("<h3>����ʧ��</h3>"));
	message->setWindowTitle(QString::fromLocal8Bit("��ʾ"));
	message->show();
}


void Library::setwindow3()
{
	window3 = new QWidget();
	Table3 = new QTableWidget();
	VLayout31 = new QVBoxLayout();
	VLayout32 = new QVBoxLayout();
	VLayout33 = new QVBoxLayout();
	VLayout34 = new QVBoxLayout();
	HLayout31 = new QHBoxLayout();
	HLayout32 = new QHBoxLayout();
	HLayout33 = new QHBoxLayout();
	HLayout34 = new QHBoxLayout();
	HLayout35 = new QHBoxLayout();
	group31 = new QGroupBox();
	group32 = new QGroupBox();
	GLayout31 = new QGridLayout();
	Line31 = new QLineEdit();
	Search31 = new QPushButton(QString::fromLocal8Bit("��ѯ"));
	DeleteButton1 = new QPushButton(QString::fromLocal8Bit("�����û�Ȩ��"));
	DeleteButton2 = new QPushButton(QString::fromLocal8Bit("ɾ���û�"));
	Adduser = new QPushButton(QString::fromLocal8Bit("������û�"));

	const char* tableheader[] = {" ","�û�ID","�û���","����","����Ȩ��","������Ŀ"};
	QStringList header;

	UserQuery queryuser;
	Control.displayUser(queryuser, sql);
	numuser3 = queryuser.Users.size();
	num3 = max(num3,(numuser3 > 20) ? numuser3 : 20);

	/*rowcount��Ҫ���ݼ������������������������������СΪ20*/
	Table3->setRowCount(num3);	//���ݵó��Ľ������
	Table3->setColumnCount(6);	//�����õĻ���ʾ�������
	Table3->setEditTriggers(QAbstractItemView::NoEditTriggers);	//����Ϊֻ��ģʽ
	Table3->setSelectionMode(QAbstractItemView::NoSelection);	//����Ϊ����ѡ��
	for (int i = 0; i < 6; i++)
		header << QString::fromLocal8Bit(tableheader[i]);
	Table3->setHorizontalHeaderLabels(header);

	Table3->setColumnWidth(0, 100);
	for (int i = 1; i < 6; i++)
		Table3->setColumnWidth(i, 150);
	/*��������ʱ�ǵ�delete������ĸ����ɺ����ķ���ֵȷ������СΪ20*/
	Tablecheckitem3 = new QTableWidgetItem*[num3];
	for (int i = 0; i < num3; i++)
	{
		Tablecheckitem3[i] = new QTableWidgetItem();
		Tablecheckitem3[i]->setCheckState(Qt::Unchecked);
		Table3->setItem(i, 0, Tablecheckitem3[i]);
	}

	/*�Ҳ�ģ������*/
	QLabel* label31 = new QLabel(QString::fromLocal8Bit("<h2>�û���ϸ��Ϣ��ѯ</h2>"));
	label31->setAlignment(Qt::AlignCenter);	//������ʾ
	QLabel* label32 = new QLabel(QString::fromLocal8Bit("�����û�ID:"));
	Search31->setFixedSize(150, 35);
	HLayout32->addStretch();
	HLayout32->addWidget(Search31);
	HLayout32->addStretch();
	GLayout31->addWidget(label32,0,0);
	GLayout31->addWidget(Line31, 0, 1);
	VLayout32->addWidget(label31);
	VLayout32->addLayout(GLayout31);
	VLayout32->addSpacing(25);
	VLayout32->addLayout(HLayout32);
	//VLayout32->addSpacing(520);
	group31->setLayout(VLayout32);

	DeleteButton1->setFixedSize(150, 35);;
	DeleteButton2->setFixedSize(150, 35);
	Adduser->setFixedSize(150, 35);
	HLayout33->addStretch(); HLayout33->addWidget(DeleteButton1); HLayout33->addStretch();
	HLayout34->addStretch(); HLayout34->addWidget(DeleteButton2); HLayout34->addStretch();
	HLayout35->addStretch(); HLayout35->addWidget(Adduser); HLayout35->addStretch();
	VLayout33->addLayout(HLayout33); 
	VLayout33->addLayout(HLayout34);
	VLayout33->addLayout(HLayout35);
	group32->setLayout(VLayout33);

	group31->setFixedWidth(300);
	group32->setFixedWidth(300);
	QLabel* label33 = new QLabel(QString::fromLocal8Bit("<h1>�û���Ϣ�б�</h1>"));
	label33->setAlignment(Qt::AlignCenter);
	VLayout34->addWidget(label33);
	VLayout34->addWidget(Table3);
	HLayout31->addLayout(VLayout34);
	HLayout31->addLayout(VLayout31);
	VLayout31->addWidget(group31);
	VLayout31->addWidget(group32);
	VLayout31->addSpacing(300);
	window3->setLayout(HLayout31);


	ShowUser3(queryuser);

	connect(Search31, SIGNAL(clicked()), this, SLOT(setwindow4()));

	connect(Adduser, SIGNAL(clicked()), this, SLOT(setwindow5()));
	connect(DeleteButton2, SIGNAL(clicked()), this, SLOT(DeleteUser3()));
}
void Library::ShowUser3(UserQuery& userquery)
{
	Borrow borrow;
	for (int i = 0; i < num3; i++)
		for (int j = 0; j < 8; j++)
			delete Table3->item(i, j);

	Tablecheckitem3 = new QTableWidgetItem*[num3];
	for (int i = 0; i < num3; i++)
	{
		Tablecheckitem3[i] = new QTableWidgetItem();
		Tablecheckitem3[i]->setCheckState(Qt::Unchecked);
		Table3->setItem(i, 0, Tablecheckitem3[i]);
	}
	for (int i = 0; i < num3; i++)
	{
		Table3->item(i, 0)->setCheckState(Qt::Unchecked);
	}
	for (int i = 0; i < numuser3; i++)
	{
		Table3->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(userquery.Users[i].id.c_str())));
		Table3->setItem(i, 2, new QTableWidgetItem(QString::fromLocal8Bit(userquery.Users[i].name.c_str())));
		Table3->setItem(i, 3, new QTableWidgetItem(QString::fromLocal8Bit(userquery.Users[i].password.c_str())));
		Table3->setItem(i, 4, new QTableWidgetItem(QString::fromLocal8Bit("ӵ�н���Ȩ��")));
		Table3->setItem(i, 5, new QTableWidgetItem(QString::number(userquery.Users[i].booknum)));
	}
}
void Library::DeleteUser3()
{
	User user;
	int num = 0;
	for (int i = 0; i < numuser3; i++)
	{
		/*�����ѡ��ѡ��*/
		if (Table3->item(i, 0)->checkState() == Qt::Checked)
		{
			user.id = Table3->item(i, 1)->text().toStdString();
			num += Control.deleteuser(user, sql);
		}
	}
	QMessageBox * message = new QMessageBox();
	if (num == 0)
	{
		message->setText(QString::fromLocal8Bit("<h3>�û�ɾ��ʧ��</h3>"));
	}
	else
	{
		QString s = QString::number(num, 10);
		message->setText(QString::fromLocal8Bit("<h3>�ɹ�ɾ��") + s + QString::fromLocal8Bit("���û�</h3>"));
		UserQuery queryuser;
		Control.displayUser(queryuser, sql);
		numuser3 = queryuser.Users.size();
		for (int i = 0; i < num3; i++)
			delete Table3->item(i, 0);
		num3 = max(num3, (numuser3 > 20) ? numuser3 : 20);

		Table3->setRowCount(num3);
		Tablecheckitem3 = new QTableWidgetItem*[num3];
		for (int i = 0; i < num3; i++)
		{
			Tablecheckitem3[i] = new QTableWidgetItem();
			Tablecheckitem3[i]->setCheckState(Qt::Unchecked);
			Table3->setItem(i, 0, Tablecheckitem3[i]);
		}
		ShowUser3(queryuser);

	}
	message->setWindowTitle(QString::fromLocal8Bit("��ʾ"));
	message->show();
}

void Library::setwindow4()
{
	if (!Line31->text().isEmpty())
	{
		User user;
		user.id = Line31->text().toStdString();
		bool is = Control.selectUser(user, sql);
		QMessageBox * message = new QMessageBox();
		if (!is)
		{
			message->setText(QString::fromLocal8Bit("<h3>�û�������</h3>"));
			Line31->clear();
			message->setWindowTitle(QString::fromLocal8Bit("��ʾ"));
			message->show();
		}
		else 
		{
			window4 = new QWidget();
			group41 = new QGroupBox();
			Table4 = new QTableWidget();
			line41 = new QLineEdit(); line41->setReadOnly(true);//����Ϊֻ��
			line42 = new QLineEdit(); line42->setReadOnly(true);
			line43 = new QLineEdit(); line43->setReadOnly(true);
			line44 = new QLineEdit(); line44->setReadOnly(true);
			line45 = new QLineEdit(); line45->setReadOnly(true);
			VLayout41 = new QVBoxLayout();
			GLayout41 = new QGridLayout();
			HLayout41 = new QHBoxLayout();
			DeleteButton4 = new QPushButton(QString::fromLocal8Bit("ɾ���û�"));
			DeleteButton4->setFixedSize(150, 35);
			QLabel* label41 = new QLabel(QString::fromLocal8Bit("<h2>�û���ϸ��Ϣ��ѯ</h2>"));
			label41->setAlignment(Qt::AlignCenter);
			QLabel* label42 = new QLabel(QString::fromLocal8Bit("�û���:"));
			QLabel* label43 = new QLabel(QString::fromLocal8Bit("�û�ID:"));
			QLabel* label44 = new QLabel(QString::fromLocal8Bit("����:"));
			QLabel* label45 = new QLabel(QString::fromLocal8Bit("����Ȩ��:"));
			QLabel* label46 = new QLabel(QString::fromLocal8Bit("������Ŀ:"));
			QLabel* label47 = new QLabel(QString::fromLocal8Bit("<h3>�û���������б�</h3>"));
			label47->setAlignment(Qt::AlignCenter);

			GLayout41->addWidget(label42, 0, 0); GLayout41->addWidget(line41, 0, 1);
			GLayout41->addWidget(label43, 0, 2); GLayout41->addWidget(line42, 0, 3);
			GLayout41->addWidget(label44, 1, 0); GLayout41->addWidget(line43, 1, 1);
			GLayout41->addWidget(label45, 2, 0); GLayout41->addWidget(line44, 2, 1);
			GLayout41->addWidget(label46, 2, 2); GLayout41->addWidget(line45, 2, 3);



			group41->setLayout(GLayout41);
			group41->setFixedWidth(600);
			group41->setAlignment(Qt::AlignCenter);
			HLayout41->setSpacing(650);
			HLayout41->addWidget(DeleteButton4);
			VLayout41->addWidget(label41);
			VLayout41->addWidget(group41);
			VLayout41->addWidget(label47);
			VLayout41->addWidget(Table4);
			VLayout41->addLayout(HLayout41);
			window4->setLayout(VLayout41);

			window4->setFixedSize(820, 750);

			ShowUser4(Line31->text().toStdString());
			window4->show();
		}
	}
}
void Library::ShowUser4(string user_id)
{
	User user;
	user.id = user_id;
	Control.selectUser(user, sql);
	line41->setText(QString::fromLocal8Bit(user.name.c_str()));
	line42->setText(QString::fromStdString(user_id));
	line43->setText(QString::fromLocal8Bit(user.password.c_str()));
	line44->setText(QString::fromLocal8Bit("��������鼮"));
	line45->setText(QString::number(user.booknum, 10));

	BookQuery querybook;
	Control.displayborrow(user_id, querybook, sql);
	numbook4 = querybook.Catalog.size();
	num4 = max(num4,(numbook4 > 20) ? numbook4 : 20);

	const char* tableheader[] = { "�鱾���","�鼮����","��������","�黹����","ʣ��黹����" };
	QStringList header;

	Table4->setRowCount(num4);	//���ݵó��Ľ������
	Table4->setColumnCount(5);	//�����õĻ���ʾ�������
	Table4->setEditTriggers(QAbstractItemView::NoEditTriggers);	//����Ϊֻ��ģʽ
	Table4->setSelectionMode(QAbstractItemView::NoSelection);	//����Ϊ����ѡ��
	for (int i = 0; i < 5; i++)
		header << QString::fromLocal8Bit(tableheader[i]);
	Table4->setHorizontalHeaderLabels(header);
	for (int i = 0; i < 5; i++)
		Table4->setColumnWidth(i, 150);	//����ÿ�еĿ��

	Borrow borrow;
	for (int i = 0; i < numbook4; i++)
	{
		Table4->setItem(i, 0, new QTableWidgetItem(QString::fromLocal8Bit(querybook.Catalog[i].book_id.c_str())));
		Table4->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(querybook.Catalog[i].name.c_str())));
		borrow.book_id = querybook.Catalog[i].book_id;
		borrow.user_id = user_id;
		Control.SelectBorrow(borrow, sql);
		QDateTime current_date_time = QDateTime::currentDateTime();
		int year = QString::fromStdString(borrow.return_date.substr(0, 4)).toInt();
		int month = QString::fromStdString(borrow.return_date.substr(5, 2)).toInt();
		int day = QString::fromStdString(borrow.return_date.substr(8, 2)).toInt();
		QDateTime return_date(QDate(year, month, day), QTime(23, 59));
		int t = current_date_time.daysTo(return_date);
		Table4->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(borrow.borrow_date)));
		Table4->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(borrow.return_date)));
		Table4->setItem(i, 4, new QTableWidgetItem(QString::number(t,10)));
	}
}

void Library::setwindow5()
{
	window5 = new QWidget();
	line51 = new QLineEdit(); line51->setFixedWidth(200);
	line52 = new QLineEdit(); line52->setFixedWidth(200);
	line53 = new QLineEdit(); line53->setFixedWidth(200);
	Adduser5 = new QPushButton(QString::fromLocal8Bit("ȷ�����"));
	Adduser5->setFixedSize(150,35);
	RButton51 = new QRadioButton(QString::fromLocal8Bit("��"));
	RButton52 = new QRadioButton(QString::fromLocal8Bit("��"));
	VLayout51 = new QVBoxLayout();
	HLayout51 = new QHBoxLayout();
	HLayout52 = new QHBoxLayout();
	HLayout53 = new QHBoxLayout();
	HLayout54 = new QHBoxLayout();
	HLayout55 = new QHBoxLayout();
	QLabel* labeltitle = new QLabel(QString::fromLocal8Bit("<h2>�����û�</h2>"));
	labeltitle->setAlignment(Qt::AlignCenter);	//������ʾ
	QLabel* label1 = new QLabel(QString::fromLocal8Bit("�û�ID:"));
	QLabel* label2 = new QLabel(QString::fromLocal8Bit("�û���:"));
	QLabel* label3 = new QLabel(QString::fromLocal8Bit("����:"));
	QLabel* label4 = new QLabel(QString::fromLocal8Bit("�Ƿ����û�����Ȩ��:"));
	
	HLayout51->addWidget(label1); HLayout51->addWidget(line51); HLayout51->addSpacing(60);
	HLayout52->addWidget(label2); HLayout52->addWidget(line52); HLayout52->addSpacing(60);
	HLayout53->addWidget(label3); HLayout53->addWidget(line53); HLayout53->addSpacing(60);
	HLayout54->addWidget(label4); HLayout54->addSpacing(20); HLayout54->addWidget(RButton51); HLayout54->addWidget(RButton52);
	HLayout55->addStretch(); HLayout55->addWidget(Adduser5); HLayout55->addStretch();

	VLayout51->addWidget(labeltitle);
	VLayout51->addLayout(HLayout51);
	VLayout51->addSpacing(15);
	VLayout51->addLayout(HLayout52);
	VLayout51->addSpacing(15);
	VLayout51->addLayout(HLayout53);
	VLayout51->addSpacing(15);
	VLayout51->addLayout(HLayout54);
	VLayout51->addSpacing(15);
	VLayout51->addLayout(HLayout55);
	window5->setLayout(VLayout51);
	window5->setFixedSize(400,300);
	window5->show();

	connect(Adduser5, SIGNAL(clicked()), this, SLOT(AddUser5()));
}
void Library::AddUser5()
{
	User user;
	user.id = line51->text().toStdString();
	user.name = line52->text().toLocal8Bit();
	user.password = line53->text().toStdString();
	if (user.id.empty() || user.name.empty() || user.password.empty())
	{
		if (user.id.empty() && user.name.empty() && user.password.empty())
			return;
		QMessageBox * message = new QMessageBox();
		if (user.id.empty())
			message->setText(QString::fromLocal8Bit("<h3>δ�����û�ID</h3>"));
		else if (user.name.empty())
			message->setText(QString::fromLocal8Bit("<h3>δ�����û���</h3>"));
		else if (user.password.empty())
			message->setText(QString::fromLocal8Bit("<h3>δ��������</h3>"));
		message->show();
	}
	else
	{
		bool is = Control.insertuser(user, sql);

		QMessageBox * message = new QMessageBox();
		const char tip1[] = "<h3>����û��ɹ�</h3>";
		const char tip2[] = "<h3>δ�ܳɹ�����û�</h3>";
		if (is)
		{
			message->setText(QString::fromLocal8Bit(tip1));

			UserQuery queryuser;
			Control.displayUser(queryuser, sql);
			numuser3 = queryuser.Users.size();
			for (int i = 0; i < num3; i++)
				delete Table3->item(i, 0);
			num3 = max(num3, (numuser3 > 20) ? numuser3 : 20);

			Table3->setRowCount(num3);
			Tablecheckitem3 = new QTableWidgetItem*[num3];
			for (int i = 0; i < num3; i++)
			{
				Tablecheckitem3[i] = new QTableWidgetItem();
				Tablecheckitem3[i]->setCheckState(Qt::Unchecked);
				Table3->setItem(i, 0, Tablecheckitem3[i]);
			}
			ShowUser3(queryuser);
		}
		else message->setText(QString::fromLocal8Bit(tip2));
		message->setWindowTitle(QString::fromLocal8Bit("������"));

		message->show();
		delete window5;
	}
}

void Library::setwindow6()
{
	window6 = new QWidget();
	TWidget6 = new QTabWidget();
	VLayout6 = new QVBoxLayout();

	setwindow7();
	setwindow8();
	setwindow9();

	TWidget6->addTab(window7,QString::fromLocal8Bit("����/��ӵ����鼮"));
	TWidget6->addTab(window8, QString::fromLocal8Bit("��Ӷ���鼮"));
	TWidget6->addTab(window9, QString::fromLocal8Bit("ɾ���鼮"));

	VLayout6->addWidget(TWidget6);
	window6->setLayout(VLayout6);
}

void Library::setwindow7()
{
	window7 = new QWidget();
	line71 = new QLineEdit();
	line72 = new QLineEdit();
	line73 = new QLineEdit();
	line74 = new QLineEdit();
	line75 = new QLineEdit();
	line76 = new QLineEdit();
	Button71 = new QPushButton(QString::fromLocal8Bit("ȷ�����"));
	Button72 = new QPushButton(QString::fromLocal8Bit("���"));
	//Button73 = new QPushButton(QString::fromLocal8Bit("�����鼮"));
	Button71->setFixedSize(150, 35);
	Button72->setFixedSize(150, 35);
	//Button73->setFixedSize(150, 35);
	date71 = new QComboBox();
	type7 = new QComboBox();
	GLayout71 = new QGridLayout();
	HLayout71 = new QHBoxLayout();
	HLayout72 = new QHBoxLayout();
	VLayout71 = new QVBoxLayout();
	VLayout72 = new QVBoxLayout();
	group71 = new QGroupBox();
	QLabel* title = new QLabel(QString::fromLocal8Bit("<h2>�����鼮��Ϣ</h2>"));
	title->setAlignment(Qt::AlignCenter);	//������ʾ
	QLabel* label1 = new QLabel(QString::fromLocal8Bit("�鼮���"));
	QLabel* label2 = new QLabel(QString::fromLocal8Bit("����"));
	QLabel* label3 = new QLabel(QString::fromLocal8Bit("����"));
	QLabel* label4 = new QLabel(QString::fromLocal8Bit("������"));
	QLabel* label5 = new QLabel(QString::fromLocal8Bit("�۸�"));
	QLabel* label6 = new QLabel(QString::fromLocal8Bit("����"));
	QLabel* label7 = new QLabel(QString::fromLocal8Bit("��������"));
	QLabel* label8 = new QLabel(QString::fromLocal8Bit("����"));
	QLabel* tip = new QLabel(QString::fromLocal8Bit("����ж�����ߣ����ÿո����"));
	QLabel* tip2 = new QLabel(QString::fromLocal8Bit("ע�⣺����Ѿ����ڵ��鼮��ID����ѡ������鼮��Ϣ"));
	const char* booktype[] = { "��ѧ��","������","��Ȼ��ѧ��","�������","˼����","������","��ѧ��","������",
		"ҽѧ��","��ҵ����","������ѧ��","��ʷ��","������" };
	for (int i = 0; i < 13; i++)
		type7->addItem(QString::fromLocal8Bit(booktype[i]));
	for (int i = 0; i<100; i++)
		date71->addItem(QString::number(2016 - i));
	type7->setFixedWidth(200);
	date71->setFixedWidth(200);

	GLayout71->setVerticalSpacing(20);
	GLayout71->addWidget(label1, 0, 0); GLayout71->addWidget(line71, 0, 1);
	GLayout71->addWidget(label2, 0, 2); GLayout71->addWidget(line72, 0, 3);
	GLayout71->addWidget(label3, 1, 0); GLayout71->addWidget(line73, 1, 1);
	GLayout71->addWidget(new QLabel(QString::fromLocal8Bit("ע��:"))); 
	GLayout71->addWidget(tip, 1, 3);
	GLayout71->addWidget(label4, 2, 0); GLayout71->addWidget(line74, 2, 1);
	GLayout71->addWidget(label5, 3, 0); GLayout71->addWidget(line75, 3, 1);
	GLayout71->addWidget(label6, 3, 2); GLayout71->addWidget(line76, 3, 3);
	GLayout71->addWidget(label7, 4, 0); GLayout71->addWidget(date71, 4, 1);
	GLayout71->addWidget(label8, 4, 2); GLayout71->addWidget(type7, 4, 3);

	HLayout71->addStretch(); HLayout71->addWidget(Button71); HLayout71->addStretch(); 
	//HLayout71->addWidget(Button73); HLayout71->addStretch();
	HLayout71->addWidget(Button72); HLayout71->addStretch();
	VLayout71->addWidget(title);
	VLayout71->addLayout(GLayout71);
	VLayout71->addSpacing(25);
	VLayout71->addLayout(HLayout71);
	VLayout71->addSpacing(10);
	VLayout71->addWidget(tip2);
	VLayout71->addSpacing(30);
	group71->setLayout(VLayout71);
	group71->setFixedSize(600, 450);

	VLayout72->addWidget(group71);
	VLayout72->addSpacing(150);
	HLayout72->addLayout(VLayout72);
	window7->setLayout(HLayout72);
	
	connect(Button72, SIGNAL(clicked()), this, SLOT(setbutton72()));
	connect(Button71, SIGNAL(clicked()), this, SLOT(AddBook7()));
}
void Library::AddBook7()
{
	
	Book book;
	book.book_id = line71->text().toStdString();
	book.name = line72->text().toLocal8Bit();
	book.author = line73->text().toLocal8Bit();
	book.publisher = line74->text().toLocal8Bit();
	book.price = line75->text().toDouble();
	book.num = line76->text().toInt();
	book.publish_date = date71->currentText().toStdString();
	book.type = type7->currentText().toLocal8Bit();
	book.stock = book.num;
	int x;
	if(!book.book_id.empty())
		x = Control.insert(book, sql);
	else x = 1;
	
	line71->clear();
	line72->clear();
	line73->clear();
	line74->clear();
	line75->clear();
	line76->clear();

	QMessageBox * message = new QMessageBox();
	const char tip1[] = "<h3>����/�������ݳɹ�</h3>";
	const char tip2[] = "<h3>δ�ܳɹ�����/��������</h3>";
	if (x == 0)
		message->setText(QString::fromLocal8Bit(tip1));
	else message->setText(QString::fromLocal8Bit(tip2));
	message->setWindowTitle(QString::fromLocal8Bit("������"));

	message->show();
}

void Library::setwindow8()
{
	/*�鼮����Ǽ���Ƿ��Ѿ���������ͬ���鼮��������ڣ���ϲ������飨������ӣ�*/
	window8 = new QWidget();
	Table8 = new QTableWidget();
	Button81 = new QPushButton(QString::fromLocal8Bit("�����ļ�")); 
	Button81->setFixedSize(150,35);
	Button82 = new QPushButton(QString::fromLocal8Bit("ȷ�����")); 
	Button82->setFixedSize(150, 35);
	Button83 = new QPushButton(QString::fromLocal8Bit("���")); 
	Button83->setFixedSize(150, 35);
	VLayout81 = new QVBoxLayout();
	HLayout81 = new QHBoxLayout();
	HLayout82 = new QHBoxLayout();
	QTextEdit* tip = new QTextEdit(QString::fromLocal8Bit("ע�⣺����ֱ���ڱ������д��Ӧ����Ϣ������ͨ���ı����ء�ͨ���ı�����ʱ������ж�����ߣ����ÿո���ֿ�����д˳���밴�ձ��˳����д����ͬ�鼮��Ϣ��Ҫ���и�����"));
	tip->setFixedSize(800, 50); tip->setReadOnly(true);
	const char* tableheader[] = { "���","����","�۸�/Ԫ","����/��","����","������","�������","����" };
	QStringList header;
	for (int i = 0; i < 8; i++)
		header << QString::fromLocal8Bit(tableheader[i]);

	/*rowcount��Ҫ���ݼ������������������������������СΪ20*/
	Table8->setEditTriggers(QAbstractItemView::NoEditTriggers);	//����Ϊֻ��ģʽ
	Table8->setSelectionMode(QAbstractItemView::NoSelection);	//����Ϊ����ѡ��
	num8 = 30;
	Table8->setRowCount(num8);	//���ݵó��Ľ������
	Table8->setColumnCount(8);	//�����õĻ���ʾ�������
	for (int i = 0; i < 8; i++)
		Table8->setColumnWidth(i, 140);
	Table8->setHorizontalHeaderLabels(header);

	TableComItem81 = new QComboBox*[num8];
	TableComItem82 = new QComboBox*[num8];
	const char* booktype[] = { "��ѧ��","������","��Ȼ��ѧ��","�������","˼����","������","��ѧ��","������",
		"ҽѧ��","��ҵ����","������ѧ��","��ʷ��","������" };
	for (int i = 0; i < num8; i++)
	{
		TableComItem81[i] = new QComboBox();
		TableComItem82[i] = new QComboBox();
		for (int j = 0; j < 13; j++)
			TableComItem81[i]->addItem(QString::fromLocal8Bit(booktype[j]));
		for (int j = 2016; j >= 1917; j--)
			TableComItem82[i]->addItem(QString::number(j));
		Table8->setCellWidget(i, 4, TableComItem81[i]);
		Table8->setCellWidget(i, 6, TableComItem82[i]);
	}
	HLayout81->addWidget(tip);
	HLayout81->addWidget(Button81);
	VLayout81->addLayout(HLayout81);
	VLayout81->addWidget(Table8);
	HLayout82->addStretch(); HLayout82->addStretch(); 
	HLayout82->addStretch();
	HLayout82->addWidget(Button82); 
	HLayout82->addWidget(Button83);
	VLayout81->addLayout(HLayout82);

	window8->setLayout(VLayout81);

	connect(Button83, SIGNAL(clicked()), this, SLOT(setbutton83()));
	connect(Button82, SIGNAL(clicked()), this, SLOT(AddBook8()));
	connect(Button81, SIGNAL(clicked()), this, SLOT(OpenFile()));
}
void Library::AddBook8()
{
	if (numitem8 > 0)
	{
		Book book;
		int num = 0;
		for (int i = 0; i < numitem8; i++)
		{
			book.book_id = Table8->item(i, 0)->text().toStdString();
			book.name = Table8->item(i, 1)->text().toLocal8Bit();
			book.price = Table8->item(i, 2)->text().toDouble();
			book.num = Table8->item(i, 3)->text().toInt();
			book.stock = book.num;
			book.type = TableComItem81[i]->currentText().toLocal8Bit();
			book.publisher = Table8->item(i, 5)->text().toLocal8Bit();
			book.publish_date = TableComItem82[i]->currentText().toLocal8Bit();
			book.author = Table8->item(i, 7)->text().toLocal8Bit();
			if (0 == Control.insert(book, sql))
				num++;
		}
		QMessageBox * message = new QMessageBox();
		QString s = QString::number(num, 10);
		if (num > 0){
			message->setText(QString::fromLocal8Bit("<h3>�ɹ�����") + s + QString::fromLocal8Bit("����</h3>"));
			for (int i = 0; i<numitem8; i++)
				for (int j = 0; j < 8; j++)
					if (j != 4 && j != 6)
						delete Table8->item(i, j);
			numitem8 = 0;
		}
		else {
			message->setText(QString::fromLocal8Bit("<h3>����ʧ��</h3>"));
		}
		message->show();
	}
}
void Library::OpenFile()
{
	QString path = QFileDialog::getOpenFileName(window8, tr("Open File"), ".", tr("Files(*.txt)"));
	if (!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			return;
		}
		QTextStream in(&file);
		std::string path1 = path.toStdString();

		QString s = in.readAll();
		string ss = s.toLocal8Bit();
		file.close();

		vector<Book> BookCatalog;
		Control.AddFile(ss, BookCatalog, sql);

		int N = BookCatalog.size();
		numitem8 = N;
		num8 = max(num8, max(numitem8, 30));
		Table8->setRowCount(num8);

		QMessageBox * message = new QMessageBox();

		if (N == 0)
		{
			message->setText(QString::fromLocal8Bit("<h3>����ʧ��</h3>"));
		}
		else
		{
			ShowBook8(BookCatalog);
			QString s = QString::number(N, 10);
			message->setText(QString::fromLocal8Bit("<h3>�ɹ�����</h3>") + s + QString::fromLocal8Bit("<h3>����</h3>"));
		}
		message->show();
	}
}
void Library::ShowBook8(vector<Book>& BOOK)
{
	for (int i = 0; i < num8; i++)
		for (int j = 0; j < 8; j++)
			delete Table8->item(i, j);

	const char* booktype[] = { "��ѧ��","������","��Ȼ��ѧ��","�������","˼����","������","��ѧ��","������",
		"ҽѧ��","��ҵ����","������ѧ��","��ʷ��","������" };
	for (int i = 0; i < num8; i++)
	{
		TableComItem81[i] = new QComboBox();
		TableComItem82[i] = new QComboBox();
		for (int j = 0; j < 13; j++)
			TableComItem81[i]->addItem(QString::fromLocal8Bit(booktype[j]));
		for (int j = 2016; j >= 1917; j--)
			TableComItem82[i]->addItem(QString::number(j));
		if (i < numitem8)
		{
			int j;
			for ( j = 0; j < 13; j++)
				if (BOOK[i].type == booktype[j])
					break;

			TableComItem81[i]->setCurrentIndex(j);
			TableComItem82[i]->setCurrentIndex(2016-QString::fromStdString(BOOK[i].publish_date).toInt());
		}
		Table8->setCellWidget(i, 4, TableComItem81[i]);
		Table8->setCellWidget(i, 6, TableComItem82[i]);
	}
	for (int i = 0; i < numitem8; i++)
	{
		Table8->setItem(i, 0, new QTableWidgetItem(QString::fromLocal8Bit(BOOK[i].book_id.c_str())));
		Table8->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(BOOK[i].name.c_str())));
		Table8->setItem(i, 2, new QTableWidgetItem(QString::number(BOOK[i].price,10,2)));
		Table8->setItem(i, 3, new QTableWidgetItem(QString::number(BOOK[i].num, 10)));
		Table8->setItem(i, 5, new QTableWidgetItem(QString::fromLocal8Bit(BOOK[i].publisher.c_str())));
		Table8->setItem(i, 7, new QTableWidgetItem(QString::fromLocal8Bit(BOOK[i].author.c_str())));
	}
}

void Library::setwindow9()
{
	window9 = new QWidget();
	line91 = new QLineEdit();
	line92 = new QLineEdit();
	line93 = new QLineEdit();
	line94 = new QLineEdit();
	line95 = new QLineEdit();
	line96 = new QLineEdit();
	Button91 = new QPushButton(QString::fromLocal8Bit("�鿴"));
	Button92 = new QPushButton(QString::fromLocal8Bit("���"));
	Button91->setFixedSize(150, 35);
	Button92->setFixedSize(150, 35);
	date91 = new QComboBox();
	type9 = new QComboBox();
	date92 = new QComboBox();
	GLayout91 = new QGridLayout();
	HLayout91 = new QHBoxLayout();
	HLayout92 = new QHBoxLayout();
	VLayout91 = new QVBoxLayout();
	VLayout92 = new QVBoxLayout();
	group91 = new QGroupBox();
	QLabel* title = new QLabel(QString::fromLocal8Bit("<h2>�����鼮��Ϣ</h2>"));
	title->setAlignment(Qt::AlignCenter);	//������ʾ
	QLabel* label1 = new QLabel(QString::fromLocal8Bit("�鼮���"));
	QLabel* label2 = new QLabel(QString::fromLocal8Bit("����"));
	QLabel* label3 = new QLabel(QString::fromLocal8Bit("����"));
	QLabel* label4 = new QLabel(QString::fromLocal8Bit("������"));
	QLabel* label5 = new QLabel(QString::fromLocal8Bit("�۸�"));
	QLabel* label6 = new QLabel(QString::fromLocal8Bit("������"));
	QLabel* label7 = new QLabel(QString::fromLocal8Bit("��������"));
	QLabel* label8 = new QLabel(QString::fromLocal8Bit("������"));
	QLabel* label9 = new QLabel(QString::fromLocal8Bit("����"));
	QTextEdit* tip2 = new QTextEdit(QString::fromLocal8Bit("��ʾ�������鼮��Ϣɾ����Ӧ���Ե��鼮��\n������鿴�������ѡ�鼮�б�\n�����ɾ����ִ��ɾ��������\n���鼮���������ɾ����������ִ�С�"));
	tip2->setReadOnly(true); tip2->setFixedHeight(50);
	const char* booktype[] = { "��ѧ��","������","��Ȼ��ѧ��","�������","˼����","������","��ѧ��","������",
		"ҽѧ��","��ҵ����","������ѧ��","��ʷ��","������" };
	type9->addItem(" ");
	for (int i = 0; i < 13; i++)
		type9->addItem(QString::fromLocal8Bit(booktype[i]));
	date91->addItem(" "); date92->addItem(" ");
	for (int i = 0; i < 100; i++)
	{
		date91->addItem(QString::number(2016 - i));
		date92->addItem(QString::number(2016 - i));
	}

	GLayout91->setVerticalSpacing(20);
	GLayout91->addWidget(label1, 0, 0); GLayout91->addWidget(line91, 0, 1);
	GLayout91->addWidget(label2, 0, 2); GLayout91->addWidget(line92, 0, 3);
	GLayout91->addWidget(label3, 1, 0); GLayout91->addWidget(line93, 1, 1);
	GLayout91->addWidget(label4, 1, 2); GLayout91->addWidget(line94, 1, 3);
	GLayout91->addWidget(label5, 2, 0); GLayout91->addWidget(line95, 2, 1);
	GLayout91->addWidget(label6, 2, 2); GLayout91->addWidget(line96, 2, 3);
	GLayout91->addWidget(label7, 3, 0); GLayout91->addWidget(date91, 3, 1);
	GLayout91->addWidget(label8, 3, 2); GLayout91->addWidget(date92, 3, 3);
	GLayout91->addWidget(label9, 4, 0); GLayout91->addWidget(type9, 4, 1);

	HLayout91->addStretch(); HLayout91->addWidget(Button91); HLayout91->addStretch();
	HLayout91->addWidget(Button92); HLayout91->addStretch();
	VLayout91->addWidget(title);
	VLayout91->addLayout(GLayout91);
	VLayout91->addSpacing(20);
	VLayout91->addLayout(HLayout91);
	VLayout91->addSpacing(10);
	VLayout91->addWidget(tip2);
	VLayout91->addSpacing(20);
	group91->setLayout(VLayout91);
	group91->setFixedSize(600, 420);

	VLayout92->addWidget(group91);
	VLayout92->addSpacing(150);
	HLayout92->addLayout(VLayout92);
	window9->setLayout(HLayout92);

	connect(Button91, SIGNAL(clicked()), this, SLOT(setwindow01()));	//�鿴ɾ�����鼮
	connect(Button92, SIGNAL(clicked()), this, SLOT(setbutton92()));	//����������Ϣ
}

void Library::setwindow01()
{
	window01 = new QWidget();
	Table01 = new QTableWidget();
	Button011 = new QPushButton(QString::fromLocal8Bit("ȫѡ"));
	Button012 = new QPushButton(QString::fromLocal8Bit("ɾ��"));
	Button011->setFixedSize(150, 35);
	Button012->setFixedSize(150, 35);
	VLayout011 = new QVBoxLayout();
	HLayout011 = new QHBoxLayout();
	QLabel* Title = new QLabel(QString::fromLocal8Bit("<h1>ɾ���鼮�б�</h1>"));
	Title->setAlignment(Qt::AlignCenter);

	const char* tableheader[] = { " ","���","����","�۸�/Ԫ","ʣ��/��","�ѽ��/��","����","����","������","�������" };
	QStringList header;
	BookQuery query;
	Query9(query);
	if (query.Catalog.size() == 0) return;
	/*rowcount��Ҫ���ݼ������������������������������СΪ20*/
	numitem01 = query.Catalog.size();
	num01 = max(num01, max(numitem01, 20));

	Table01->setRowCount(num01);	//���ݵó��Ľ������
	Table01->setColumnCount(10);	//�����õĻ���ʾ�������
	Table01->setEditTriggers(QAbstractItemView::NoEditTriggers);	//����Ϊֻ��ģʽ
	Table01->setSelectionMode(QAbstractItemView::NoSelection);	//����Ϊ����ѡ��
	for (int i = 0; i < 10; i++)
		header << QString::fromLocal8Bit(tableheader[i]);
	Table01->setHorizontalHeaderLabels(header);
	Table01->setColumnWidth(0, 50);
	for (int i = 1; i < 10; i++)
		Table01->setColumnWidth(i, 120);
	Tablecheckitem01 = new QTableWidgetItem*[num01];
	
	for (int i = 0; i < num01; i++)
	{
		Tablecheckitem01[i] = new QTableWidgetItem();
		Tablecheckitem01[i]->setCheckState(Qt::Checked);
		Table01->setItem(i, 0, Tablecheckitem01[i]);
	}

	HLayout011->addStretch(); HLayout011->addStretch(); HLayout011->addStretch();
	HLayout011->addWidget(Button011); HLayout011->addWidget(Button012);
	VLayout011->addWidget(Title);
	VLayout011->addWidget(Table01);
	VLayout011->addLayout(HLayout011);

	window01->setLayout(VLayout011);
	window01->setFixedSize(1180, 800);


	for (int i = 0; i < query.Catalog.size(); i++)
	{
		Table01->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].book_id.c_str())));
		Table01->setItem(i, 2, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].name.c_str())));
		Table01->setItem(i, 3, new QTableWidgetItem(QString::number(query.Catalog[i].price, 10, 2)));
		Table01->setItem(i, 4, new QTableWidgetItem(QString::number(query.Catalog[i].stock, 10)));
		Table01->setItem(i, 5, new QTableWidgetItem(QString::number(query.Catalog[i].num - query.Catalog[i].stock, 10)));
		Table01->setItem(i, 6, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].type.c_str())));
		Table01->setItem(i, 7, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].author.c_str())));
		Table01->setItem(i, 8, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].publisher.c_str())));
		Table01->setItem(i, 9, new QTableWidgetItem(QString::fromLocal8Bit(query.Catalog[i].publish_date.c_str())));
	}

	window01->show();
	connect(Button011, SIGNAL(clicked()), this, SLOT(setbutton011()));	//�źźͲ۵Ĳ�����������һ��
	connect(Button012, SIGNAL(clicked()), this, SLOT(DeleteBook01()));
}
void Library::Query9(BookQuery& query)
{
	query.book_id = line91->text().toLocal8Bit();
	query.name = line92->text().toLocal8Bit();
	query.author = line93->text().toLocal8Bit();
	query.publisher = line94->text().toLocal8Bit();
	query.low_price = line95->text().isEmpty() ? -1 : line95->text().toDouble();
	query.high_price = line96->text().isEmpty() ? -1 : line96->text().toDouble();
	query.begin_year = date91->currentText().toInt();
	query.end_year = date92->currentText().toInt();
	query.have_stock = false;
	query.type = type9->currentText().toLocal8Bit();

	/*�����ݿ��еõ�����*/
	Control.select9(query, sql);

}
void Library::DeleteBook01()
{
	int num = 0;
	for (int i = 0; i < numitem01; i++)
	{
		if (Table01->item(i, 0)->checkState() == Qt::Checked)
		{
			string book_id = Table01->item(i, 1)->text().toStdString();
			num += Control.deletebook(book_id, sql);
		}
	}
	QMessageBox * message = new QMessageBox();

	if (num > 0)
	{
		QString s = QString::number(num, 10);
		message->setText(QString::fromLocal8Bit("<h3>�ɹ�ɾ��")+ s + QString::fromLocal8Bit("����</h3>"));
		line91->clear();
		line92->clear();
		line93->clear();
		line94->clear();
		line95->clear();
		line96->clear();
		delete window01;
	}
	else message->setText(QString::fromLocal8Bit("<h3>ɾ��ʧ��</h3>"));
	message->setWindowTitle(QString::fromLocal8Bit("��ʾ"));
	message->show();
}

void Library::setwindow02()
{
	window02 = new QWidget();
	GLayout02 = new QGridLayout();
	HLayout021 = new QHBoxLayout();
	VLayout021 = new QVBoxLayout();
	line021 = new QLineEdit(); line021->setFixedWidth(250);
	line022 = new QLineEdit(); line022->setFixedWidth(250);
	Button021 = new QPushButton(QString::fromLocal8Bit("��¼"));
	Button021->setFixedSize(150,35);
	QLabel* title = new QLabel(QString::fromLocal8Bit("<h2>�û���¼</h2>"));
	title->setAlignment(Qt::AlignCenter);
	GLayout02->addWidget(new QLabel(QString::fromLocal8Bit("ID��")), 0, 0);
	GLayout02->addWidget(line021, 0, 1);
	GLayout02->addWidget(new QLabel(QString::fromLocal8Bit("���룺")), 1, 0);
	GLayout02->addWidget(line022, 1, 1);
	GLayout02->setVerticalSpacing(30);
	HLayout021->addStretch(); HLayout021->addWidget(Button021); HLayout021->addStretch();
	VLayout021->addWidget(title);
	VLayout021->addLayout(GLayout02);
	VLayout021->addSpacing(30);
	VLayout021->addLayout(HLayout021);
	VLayout021->addSpacing(50);
	window02->setLayout(VLayout021);
	window02->setFixedSize(350, 300);
	window02->show();

	connect(Button021, SIGNAL(clicked()), this, SLOT(Logon()));	//�źźͲ۵Ĳ�����������һ��
}
void Library::Logon()
{
	User user;
	Manager manager;
	int x1,x2; bool is1, is2;
	std::string password;
	user.id = line021->text().toStdString();
	password = line022->text().toStdString();
	manager.id = line021->text().toStdString();
	if (user.id.empty())
	{
		QMessageBox * message = new QMessageBox();
		const char tip[] = "<h3>δ�����û�ID</h3>";
		message->setText(QString::fromLocal8Bit(tip));
		message->setWindowTitle(QString::fromLocal8Bit("����"));
		message->show();
		line021->clear();
		line022->clear();
	}
	else if (password.empty())
	{
		QMessageBox * message = new QMessageBox();
		const char tip[] = "<h3>δ��������</h3>";
		message->setText(QString::fromLocal8Bit(tip));
		message->setWindowTitle(QString::fromLocal8Bit("����"));
		message->show();
		line021->clear();
		line022->clear();
	}
	else
	{
		is1 = Control.selectUser(user, sql);
		is2 = Control.selectManager(manager, sql);
		if (is1 == 0 ) x1 = 0;	//�û�������
		else if (user.password != password) x1 = 1;	//�������
		else x1 = 2;
		if (is2 == 0) x2 = 0;	//�û�������
		else if (manager.password != password) x2 = 1;	//�������
		else x2 = 2;
		QMessageBox * message = new QMessageBox();
		if (x1 == 2)/*�û���½�ɹ�����ʾע����ť*/
		{
			delete Longon_in;
			Longon_out = new QPushButton(QString::fromLocal8Bit("ע��"));
			Longon_out->setFixedSize(120, 35);
			Longon_out->setFlat(true);
			HLayoutTitle1->addWidget(Longon_out);
			userName = QString::fromLocal8Bit(user.name.c_str());
			user_type = USER;
			userID = QString::fromStdString(user.id);
			userPassword = QString::fromStdString(user.password);

			message->setText(QString::fromLocal8Bit("<h3>��½�ɹ�</h3>"));

			Longon_inChangeWindow1();
			connect(Longon_out, SIGNAL(clicked()), this, SLOT(Logon_out()));
		}
		else if (x2 == 2)/*����Ա��½�ɹ���*/
		{
			delete Longon_in;
			Longon_out = new QPushButton(QString::fromLocal8Bit("ע��"));
			Longon_out->setFixedSize(120, 35);
			Longon_out->setFlat(true);
			HLayoutTitle1->addWidget(Longon_out);
			userName = QString::fromLocal8Bit(manager.name.c_str());
			user_type = MANAGER;
			userID = QString::fromStdString(manager.id);
			userPassword = QString::fromStdString(password);

			connect(Longon_out, SIGNAL(clicked()), this, SLOT(Logon_out()));
			Longon_inChangeWindow1();
			message->setText(QString::fromLocal8Bit("<h3>��½�ɹ�</h3>"));
		}
		else
		{
			if(x1 == 0 && x2 == 0)
				message->setText(QString::fromLocal8Bit("<h3>�û�������</h3>"));
			else message->setText(QString::fromLocal8Bit("<h3>�������</h3>"));
		}
		message->setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		delete window02;
		message->show();
	}
}

void Library::updatetime()
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd  hh:mm:ss  ddd");
	QString text = QString::fromLocal8Bit("��ǰ�û�: ") + userName + QString::fromLocal8Bit("     ��ǰʱ��: ") + current_date + "  ";
	titlelabel->setText(text);
}

bool Library::Isselectall01()
{
	for (int i = 0; i < num01; i++)
		if (Table01->item(i, 0)->checkState() != Qt::Checked)
			return false;
	return true;
}
bool Library::Isselectall2()
{
	for (int i = 0; i < num2; i++)
		if (Tablecheckitem2[i]->checkState() != Qt::Checked)
			return false;
	return true;
}
void Library::setbutton011()	//ȫѡ����01�еĹ�ѡ��
{
	if (Isselectall01())
	{
		for (int i = 0; i < num01; i++)
			Table01->item(i,0)->setCheckState(Qt::Unchecked);
	}
	else 
		for (int i = 0; i < num01; i++)
			Table01->item(i, 0)->setCheckState(Qt::Checked);
}
void Library::setbutton21()	//ȫѡ���ڶ��еĹ�ѡ��
{
	if (Isselectall2())
	{
		for (int i = 0; i < num2; i++)
			Tablecheckitem2[i]->setCheckState(Qt::Unchecked);
	}
	else
		for (int i = 0; i < num2; i++)
			Tablecheckitem2[i]->setCheckState(Qt::Checked);
}
void Library::setbutton72()	//����������Ϣ
{
	line71->clear();
	line72->clear();
	line73->clear();
	line74->clear();
	line75->clear();
	line76->clear();
}
void Library::setbutton83()	//��մ���8�����������Ϣ
{
	for(int i=0;i<numitem8;i++)
		for (int j = 0; j < 8; j++)
			if (j != 4 && j != 6)
				delete Table8->item(i, j);
	numitem8 = 0;
}
void Library::setbutton92()	//��մ���9���������Ϣ
{
	line91->clear();
	line92->clear();
	line93->clear();
	line94->clear();
	line95->clear();
	line91->clear();
}

void Library::Island(bool is)
{
	QMessageBox * message = new QMessageBox();
	const char tip1[] = "<h3>�ѳɹ����������ݿ�</h3>";
	const char tip2[] = "<h3>δ�ܳɹ����������ݿ�</h3>";
	if (is)
		message->setText(QString::fromLocal8Bit(tip1));
	else message->setText(QString::fromLocal8Bit(tip2));
	message->setWindowTitle(QString::fromLocal8Bit("��ʾ"));
	message->show();
}





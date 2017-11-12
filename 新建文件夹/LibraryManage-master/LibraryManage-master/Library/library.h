#ifndef LIBRARY_H
#define LIBRARY_H
#include <QObject>
#include <QString>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTextEdit>
#include <QPalette>
#include <QDir>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QTextCodec>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include <QTextStream>
#include "mysql.h"
#include "controller.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")


class Library : public QObject
{
    Q_OBJECT

public:
	Library(QObject* parent = 0);
	~Library();

/*
����Ȩ�ޣ�
0 manager ���Բ�ѯ���黹�飬������
1 user ���Բ�ѯ�����黹��
2 visitor ���Բ�ѯ
*/
private:
	enum { MANAGER, USER, VISITOR};
	QString userName;
	QString userID;
	QString userPassword;
	int user_type;//��Ա������: user, visitor, manager
	MYSQL sql;
	controller Control;


	QWidget *WholeWindow;
	QVBoxLayout* VlayoutWhole;
	QTabWidget* WholeTabwidget;	//�·��Ĺ�����

	QWidget *Title;
	QVBoxLayout* VLayoutTitle1;
	QHBoxLayout* HLayoutTitle1;
	QPushButton* Longon_in;
	QPushButton* Longon_out;
	QTimer* timer;
	QLabel* titlelabel;
	
	/*����1�Ŀؼ�*/
    QWidget *window1;	//��ѯ���ڣ�ͼ������
	int numitem1 = 0;
	int numbook1 = 0;
	QTreeWidget* tree1;
	QTreeWidgetItem* root1;
	QTableWidgetItem** Tablecheckitem1;
	QHBoxLayout* HLayout11;
	QHBoxLayout* HLayout12;
	QVBoxLayout* VLayout12;
	QVBoxLayout* VLayout13;
	QVBoxLayout* VLayout14;
	QHBoxLayout* HLayout13;
	QTableWidget* Table1;
	QGridLayout* GLayout11;
	QLabel* label1;
	QLineEdit* bookname;
	QLineEdit* author;
	QLineEdit* publisher;
	QLineEdit* bookID;
	QLineEdit* price1;
	QLineEdit* price2;
	QComboBox* date1;
	QComboBox* date2;
	QPushButton* Searchbutton;
	QPushButton* Borrowbutton;
	QGroupBox* group11;
	QGroupBox* group12;
	QCheckBox* check1;

	/*���ڶ��еĿؼ�*/
    QWidget *window2;	//�û��������
	int num2 = 0;
	int numbook2 = 0;
	QVBoxLayout* VLayout21;
	QHBoxLayout* HLayout21;
	QTableWidget* Table2;
	QTableWidgetItem** Tablecheckitem2;	//��ѡ��
	QPushButton* ReturnButton;
	QPushButton* Button21;

	/*�������еĿؼ�*/
	QWidget *window3;	//�û�����
	int num3 = 0;
	int numuser3 = 0;
	QTableWidget* Table3;
	QTableWidgetItem** Tablecheckitem3;	//��ѡ��
	QPushButton* DeleteButton2;	//ɾ���û���Ϣ
	QPushButton* DeleteButton1;	//ɾ���û�Ȩ��
	QPushButton* Adduser;
	QPushButton* Search31;
	QVBoxLayout* VLayout31;
	QVBoxLayout* VLayout32;
	QVBoxLayout* VLayout33;
	QVBoxLayout* VLayout34;
	QHBoxLayout* HLayout31;
	QHBoxLayout* HLayout32;
	QHBoxLayout* HLayout33;
	QHBoxLayout* HLayout34;
	QHBoxLayout* HLayout35;
	QGroupBox* group31;
	QGroupBox* group32;
	QGridLayout* GLayout31;
	QLineEdit* Line31;

	/*����4�еĿؼ�*/
	QWidget* window4;	//�û���ϸ��Ϣ
	int num4 = 0;
	int numbook4 = 0;
	QGroupBox* group41;
	QTableWidget* Table4;
	QLineEdit* line41;
	QLineEdit* line42;
	QLineEdit* line43;
	QLineEdit* line44;
	QLineEdit* line45;
	QVBoxLayout* VLayout41;
	QGridLayout* GLayout41;
	QHBoxLayout* HLayout41;
	QPushButton* DeleteButton4;

	/*����5�еĿؼ�*/
	QWidget* window5;	//������û�
	QLineEdit* line51;
	QLineEdit* line52;
	QLineEdit* line53;
	QRadioButton* RButton51;
	QRadioButton* RButton52;
	QVBoxLayout* VLayout51;
	QHBoxLayout* HLayout51;
	QHBoxLayout* HLayout52;
	QHBoxLayout* HLayout53;
	QHBoxLayout* HLayout54;
	QHBoxLayout* HLayout55;
	QPushButton* Adduser5;

	/*����6�Ŀؼ�*/
	QWidget *window6;	//�鼮����
	QTabWidget* TWidget6;
	QVBoxLayout* VLayout6;

	/*����7�Ŀؼ�*/
	QWidget* window7;	//�������
	QLineEdit* line71;
	QLineEdit* line72;
	QLineEdit* line73;
	QLineEdit* line74;
	QLineEdit* line75;
	QLineEdit* line76;
	QComboBox* date71;
	QComboBox* type7;
	QPushButton* Button71;
	QPushButton* Button72;
	QPushButton* Button73;
	QGridLayout* GLayout71;
	QVBoxLayout* VLayout71;
	QVBoxLayout* VLayout72;
	QHBoxLayout* HLayout71;
	QHBoxLayout* HLayout72;
	QGroupBox* group71;

	/*����8�Ŀؼ�*/
	QWidget* window8;	//������
	int num8 = 0;
	int numitem8;
	QTableWidget* Table8;
	QComboBox** TableComItem81;	//����
	QComboBox** TableComItem82;	//�鼮����
	QPushButton* Button81;
	QPushButton* Button82;
	QPushButton* Button83;
	QVBoxLayout* VLayout81;
	QHBoxLayout* HLayout81;
	QHBoxLayout* HLayout82;

	/*����9�Ŀؼ�*/
	QWidget* window9;	//ɾ���鼮
	QLineEdit* line91;
	QLineEdit* line92;
	QLineEdit* line93;
	QLineEdit* line94;
	QLineEdit* line95;
	QLineEdit* line96;
	QComboBox* date91;
	QComboBox* date92;
	QComboBox* type9;
	QPushButton* Button91;
	QPushButton* Button92;
	//QPushButton* Button93;
	QGridLayout* GLayout91;
	QVBoxLayout* VLayout91;
	QVBoxLayout* VLayout92;
	QHBoxLayout* HLayout91;
	QHBoxLayout* HLayout92;
	QGroupBox* group91;
	
	/*����01�Ŀؼ�*/
	QWidget* window01;
	int num01 = 0;
	int numitem01;
	QTableWidget* Table01;
	QPushButton* Button011;
	QPushButton* Button012;
	QTableWidgetItem** Tablecheckitem01;	//��ѡ��
	QVBoxLayout* VLayout011;
	QHBoxLayout* HLayout011;

	/*����02�Ŀؼ�*/
	QWidget* window02;
	QGridLayout* GLayout02;
	QHBoxLayout* HLayout021;
	QVBoxLayout* VLayout021;
	QLineEdit* line021;
	QLineEdit* line022;
	QPushButton* Button021;

private:
    void LayoutWindow();
	void SetTitle();
	void SetMainWidget();
	/*���ò�ͬ�Ĵ��ڸ�ʽ*/
	void setwindow1();	//��ѯ���ڣ�ͼ������
	void setwindow2();	//�û��������
	void setwindow3();	//�û�����
	void setwindow6();	//�鼮����
	void setwindow7();	//�������
	void setwindow8();	//������
	void setwindow9();	//ɾ���鼮

	

private:
	bool Isselectall01();	//�жϱ��Table01�еĹ�ѡ���Ƿ�ȫѡ
	bool Isselectall2();	//�жϱ��Table2�еĹ�ѡ���Ƿ�ȫѡ
	void Island(bool);
	void Longon_inChangeWindow1();
	void Longon_outChangeWindow1();
	void ShowBook2(BookQuery&);
	void ShowUser3(UserQuery&);
	void ShowUser4(string);
	void Query9(BookQuery&);
	void ShowBook8(vector<Book>&);


private slots://�źŲ�
	void updatetime();
	void setwindow4();	//�㿪�û���ϸ��Ϣ��������
	void setwindow5();	//������û���������
	void setwindow01(); //�鿴Ҫɾ�����鼮
	void setwindow02(); //�û���¼
	void setbutton011();//ȫѡ���Table01�еĹ�ѡ��
	void setbutton21(); //ȫѡ���Table2�еĹ�ѡ��
	void setbutton72();	//����������Ϣ
	void setbutton83();	//����������Ϣ
	void setbutton92();	//���������Ϣ
	void Query1();		//����1�еĲ�ѯ
	void QueryTree1(QTreeWidgetItem*, int);	//����1���QTreeWidget
	void AddBook7();	//����7����鼮
	void AddUser5();	//����5����û�
	void Logon();		//��¼
	void Logon_out();	//ע��
	void Borrow_Book();	//����ѡ�е���
	void Return_Book();	//�黹ѡ�е���
	void DeleteUser3();	//ɾ��ѡ�е��û�
	void OpenFile();
	void DeleteBook01();
	void AddBook8();
};


#endif // LIBRARY_H

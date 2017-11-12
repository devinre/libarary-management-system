/*
 * GlobalDefine.h
 *
 *  Created on: 2010-4-16
 *      Author: Administrator
 */

#ifndef GLOBALDEFINE_H_
#define GLOBALDEFINE_H_
#include <QMessageBox>
#include <QCloseEvent>
//GLOBALDEFINE
#define CONNECT 1//���ӷ�����
#define FAILURE 1
#define SUCCESS 0
#define RESULT 1000
#define DATETIME "yyyy-MM-ddThh:mm:ss"
#define DATE "yyyy-MM-dd"
#define PORT 8010
//USERMANAGE
#define USER 100
#define	USER_LOGON USER+1//��½
#define USER_ADD USER+2//����û�
#define USER_DELETE USER+3//ɾ���û�
#define USER_UPDATE USER+4//�����û�
#define USER_LIST USER+5//�����û���Ϣ
#define USER_UPDATEPWD USER+6//��������
#define USER_RESPONSE USER+7//�Ѿ���ʾ��һ���û���Ϣ��¼����Ӧ��������׼����ȡ��һ��
#define USER_DISCONNECT USER+8//ȡ������
#define USER_LOGOUT USER+9//ע��
#define USER_EXIT USER+10//�˳�
#define USER_QUERY USER+11
//BOOKMANAGE
#define BOOK 200
#define	BOOK_ADD BOOK+1 //����鼮
#define	BOOK_DELETE BOOK+2//ɾ���鼮
#define	BOOK_UPDATE BOOK+3//�����鼮
#define BOOK_QUERY BOOK+4//��ѯͼ��
#define	BOOK_LIST BOOK+5//��ʾ�鼮�б�
#define BOOK_RESPONSE BOOK+6//�Ѿ���ʾ��һ���鼮��¼����Ӧ��������׼����ȡ��һ��
//LENDMANAGE
#define	LEND 300//����
#define	LEND_RETURN LEND+1//����
#define	LEND_RENEWAL LEND+2//����
#define	LEND_QUERY LEND+3//��ѯ�鼮
#define	LEND_LIST LEND+4//�����¼
#define	LEND_STATISTIC LEND+5//�������ͼ
#define	LEND_OVERDUE LEND+6//���ڽ���
#define LEND_DELETE LEND+7//ɾ����¼
#define LEND_RESPONSE LEND+8//�Ѿ���ʾ��һ�������¼����Ӧ��������׼����ȡ��һ��
#define LEND_LENDOUT LEND+9
//READERMANAGE
#define READER 400//
#define READER_ADD READER+1
#define READER_DELETE READER+2
#define READER_UPDATE READER+3
#define READER_QUERY READER+4
#define READER_LIST READER+5
#define READER_RESPONSE READER+6
//BOOKLOGMANAGE
#define BOOKLOG 500
#define BOOKLOG_LIST BOOKLOG+1
#define BOOKLOG_DELETE BOOKLOG+2
#define BOOKLOG_RESPONSE BOOKLOG+3
//USERLOGMANAGE
#define	USERLOG 600
#define USERLOG_LIST USERLOG+1
#define USERLOG_DELETE USERLOG+2
#define USERLOG_RESPONSE USERLOG+3
typedef unsigned int u32;
////////////////////////ATTRIBUTENUM////////////////////////////////
#define USERINFOATTRNUM 13//�û���Ϣ���Ը���
#define BOOKINFOATTRNUM 11//�鼮��Ϣ���Ը���
#define LENDINFOATTRNUM 13//����鼮��Ϣ���Ը���
#define BOOKLOGINFOATTRNUM 9//�鼮��־��Ϣ���Ը���
#define READERINFOATTRNUM 16//������Ϣ���Ը���
#define USERLOGINFOATTRNUM 6//�û���־��Ϣ���Ը���
///////////////////////////////////////////////////////////////////
#define MALE 0
#define FEMALE 1

#define USER_STATUS_NORMAL 0
#define USER_STATUS_NOUSE 1

#define USER_OFFLINE 0
#define USER_ONLINE 1

#define READER_NORMAL 0
#define READER_VIP 1

#define BOOK_STATUS_NOTLEND 0
#define BOOK_STATUS_LEND 1
#define BOOK_STATUS_LOSS 2

#define LEND_NOTOVERDUE 0
#define LEND_ISOVERDUE 1
typedef struct _userinfo_tag
{
	QString sID;//�����û�ID
	QString sName;//�����û���
	u32 dwSex;//�Ա�0:��,1:Ů
	QString sPass;//�����û�����
	u32 dwPower;//�����û�Ȩ��
	QString sBirthDay;//��������
	QString sPhone;//�绰����
	QString sIDCard;//���֤��
	u32 dwStatus;//״̬0:���� 1:����
	QString sLoginTime;//ע��ʱ��
	u32 dwOnline;//��½��Ϣ��־0:δ��¼ 1:����
	QString sEmail;
	QString sLastTime;//����¼ʱ��
}USERINFO, *PUSERINFO;
typedef struct _bookinfo_tag
{
	QString sID;//�鼮ID
	QString sName;//�鼮����
	QString sAuthor;//����
	QString sType;//ͼ������
	QString sPress;//������
	QString sPressDate;//��������
	u32 dwPageNum;//ҳ��
	double fPrice;//�۸�
	QString sAddDate;//�������
	u32 dwLendTimes;//�������
	u32 dwStatus;//ͼ��״̬0:δ��� 1:��� 2:��ʧ
}BOOKINFO, *PBOOKINFO;
typedef struct _lendinfo_tag
{
	QString sID;//ͼ��ID
	QString sName;//ͼ������
	QString sAuthor;//����
	QString sType;//ͼ������
	QString sPress;//������
	QString sPressDate;//��������
	u32 dwPageNum;//ҳ��
	double fPrice;//ͼ��۸�
	QString sLendDate;//�������
	u32 dwLendDays;//�������
	u32 dwTimeOut;//�Ƿ�����0:δ����,1:����
	u32 dwOverDays;//��������
	QString sReaderID;//����
	QString sReader;
}LENDINFO, *PLENDINFO;
typedef struct bookloginfo_tag
{
	u32 dwID;//����ID
	u32 dwResult;//�������0:�ɹ� 1:ʧ��
	QString sOperator;//����Ա
	QString sBookID;//����ͼ��ID
	QString sBookName;//����ͼ������
	u32 dwOperation;//����1:���ͼ�飬2:ɾ��ͼ��,3:����ͼ�� 4:��� 5:�黹 6:����
	QString sIP;//����ԱIP��ַ
	QString sType;//�鼮����
	QString sDescription;//����
	QString sDateTime;//����ʱ��
}BOOKLOGINFO, *PBOOKLOGINFO;
typedef struct _readerinfo_tag
{
	QString sID;//����ID
	QString sName;//��������
	u32 dwSex;//�����Ա�0:male 1:female
	QString sBirthDay;//���߳�������
	QString sCardDate;//���߷�������
	QString sCardNum;//���߿���
	u32 dwType;//���߼���(����)0:general 1:VIP
	u32 dwStatus;//����״̬ 0:normal 1:ReportLoss
	QString sSchool;//��������ѧУ
	QString sDepartment;//����ϵ��
	u32 dwGrade;//�����꼶
	QString sIDCard;//�������֤��
	QString sAddress;//�������ڵ�
	QString sPost;//�����ʱ�
	QString sPhone;//���ߵ绰
	QString sEmail;//����Email
}READERINFO, *PREADERINFO;
typedef struct _userloginfo_tag
{
	u32 dwID;//����ID
	u32 dwResult;//�������0:�ɹ� 1:ʧ��
	QString sOperator;//����Ա
	u32 dwOperation;//����1:logon 2:adduser 3:deleteuser 4:updateuser 5:�޸����� 6:�ǳ�
	QString sIP;//������IP
	QString sDescription;//����
	QString sDateTime;//����ʱ��

}USERLOGINFO, *PUSERLOGINFO;
typedef struct _manageinfo_tag
{
	u32 dwType;	//��Ϣ����
	u32 dwSubType;//������
	BOOKINFO bookInfo;//�鼮��Ϣ
	USERINFO userInfo;//�û���Ϣ
	LENDINFO lendInfo;//����鼮��Ϣ
	BOOKLOGINFO bookLogInfo;//�鼮��־��Ϣ
	READERINFO readerInfo;//������Ϣ
	USERLOGINFO userLogInfo;//�û���־��Ϣ
}MANAGEINFO, *PMANAGEINFO;
#endif /* GLOBALDEFINE_H_ */

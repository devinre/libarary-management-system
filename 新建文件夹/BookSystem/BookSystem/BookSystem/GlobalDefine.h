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
#define CONNECT 1//连接服务器
#define FAILURE 1
#define SUCCESS 0
#define RESULT 1000
#define DATETIME "yyyy-MM-ddThh:mm:ss"
#define DATE "yyyy-MM-dd"
#define PORT 8010
//USERMANAGE
#define USER 100
#define	USER_LOGON USER+1//登陆
#define USER_ADD USER+2//添加用户
#define USER_DELETE USER+3//删除用户
#define USER_UPDATE USER+4//更新用户
#define USER_LIST USER+5//单个用户信息
#define USER_UPDATEPWD USER+6//更新密码
#define USER_RESPONSE USER+7//已经显示了一条用户信息记录，回应服务器，准备获取下一条
#define USER_DISCONNECT USER+8//取消连接
#define USER_LOGOUT USER+9//注销
#define USER_EXIT USER+10//退出
#define USER_QUERY USER+11
//BOOKMANAGE
#define BOOK 200
#define	BOOK_ADD BOOK+1 //添加书籍
#define	BOOK_DELETE BOOK+2//删除书籍
#define	BOOK_UPDATE BOOK+3//更新书籍
#define BOOK_QUERY BOOK+4//查询图书
#define	BOOK_LIST BOOK+5//显示书籍列表
#define BOOK_RESPONSE BOOK+6//已经显示了一条书籍记录，回应服务器，准备获取下一条
//LENDMANAGE
#define	LEND 300//借书
#define	LEND_RETURN LEND+1//还书
#define	LEND_RENEWAL LEND+2//续借
#define	LEND_QUERY LEND+3//查询书籍
#define	LEND_LIST LEND+4//借出记录
#define	LEND_STATISTIC LEND+5//借出波形图
#define	LEND_OVERDUE LEND+6//逾期借阅
#define LEND_DELETE LEND+7//删除记录
#define LEND_RESPONSE LEND+8//已经显示了一条借出记录，回应服务器，准备获取下一条
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
#define USERINFOATTRNUM 13//用户信息属性个数
#define BOOKINFOATTRNUM 11//书籍信息属性个数
#define LENDINFOATTRNUM 13//借出书籍信息属性个数
#define BOOKLOGINFOATTRNUM 9//书籍日志信息属性个数
#define READERINFOATTRNUM 16//读者信息属性个数
#define USERLOGINFOATTRNUM 6//用户日志信息属性个数
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
	QString sID;//保存用户ID
	QString sName;//保存用户名
	u32 dwSex;//性别0:男,1:女
	QString sPass;//保存用户密码
	u32 dwPower;//保存用户权限
	QString sBirthDay;//出生日期
	QString sPhone;//电话号码
	QString sIDCard;//身份证号
	u32 dwStatus;//状态0:正常 1:禁用
	QString sLoginTime;//注册时间
	u32 dwOnline;//登陆信息标志0:未登录 1:在线
	QString sEmail;
	QString sLastTime;//最后登录时间
}USERINFO, *PUSERINFO;
typedef struct _bookinfo_tag
{
	QString sID;//书籍ID
	QString sName;//书籍名字
	QString sAuthor;//作者
	QString sType;//图书类型
	QString sPress;//出版社
	QString sPressDate;//出版日期
	u32 dwPageNum;//页数
	double fPrice;//价格
	QString sAddDate;//入库日期
	u32 dwLendTimes;//借出次数
	u32 dwStatus;//图书状态0:未借出 1:借出 2:遗失
}BOOKINFO, *PBOOKINFO;
typedef struct _lendinfo_tag
{
	QString sID;//图书ID
	QString sName;//图书名字
	QString sAuthor;//作者
	QString sType;//图书类型
	QString sPress;//出版社
	QString sPressDate;//出版日期
	u32 dwPageNum;//页数
	double fPrice;//图书价格
	QString sLendDate;//借出日期
	u32 dwLendDays;//借出天数
	u32 dwTimeOut;//是否逾期0:未逾期,1:逾期
	u32 dwOverDays;//超期天数
	QString sReaderID;//读者
	QString sReader;
}LENDINFO, *PLENDINFO;
typedef struct bookloginfo_tag
{
	u32 dwID;//操作ID
	u32 dwResult;//操作结果0:成功 1:失败
	QString sOperator;//操作员
	QString sBookID;//操作图书ID
	QString sBookName;//操作图书名字
	u32 dwOperation;//操作1:添加图书，2:删除图书,3:更新图书 4:借出 5:归还 6:续借
	QString sIP;//操作员IP地址
	QString sType;//书籍类型
	QString sDescription;//描述
	QString sDateTime;//操作时间
}BOOKLOGINFO, *PBOOKLOGINFO;
typedef struct _readerinfo_tag
{
	QString sID;//读者ID
	QString sName;//读者名字
	u32 dwSex;//读者性别0:male 1:female
	QString sBirthDay;//读者出生日期
	QString sCardDate;//读者发卡日期
	QString sCardNum;//读者卡号
	u32 dwType;//读者级别(类型)0:general 1:VIP
	u32 dwStatus;//读者状态 0:normal 1:ReportLoss
	QString sSchool;//读者所属学校
	QString sDepartment;//读者系别
	u32 dwGrade;//读者年级
	QString sIDCard;//读者身份证号
	QString sAddress;//读者所在地
	QString sPost;//读者邮编
	QString sPhone;//读者电话
	QString sEmail;//读者Email
}READERINFO, *PREADERINFO;
typedef struct _userloginfo_tag
{
	u32 dwID;//操作ID
	u32 dwResult;//操作结果0:成功 1:失败
	QString sOperator;//操作员
	u32 dwOperation;//操作1:logon 2:adduser 3:deleteuser 4:updateuser 5:修改密码 6:登出
	QString sIP;//操作者IP
	QString sDescription;//描述
	QString sDateTime;//操作时间

}USERLOGINFO, *PUSERLOGINFO;
typedef struct _manageinfo_tag
{
	u32 dwType;	//消息类型
	u32 dwSubType;//子类型
	BOOKINFO bookInfo;//书籍信息
	USERINFO userInfo;//用户信息
	LENDINFO lendInfo;//借出书籍信息
	BOOKLOGINFO bookLogInfo;//书籍日志信息
	READERINFO readerInfo;//读者信息
	USERLOGINFO userLogInfo;//用户日志信息
}MANAGEINFO, *PMANAGEINFO;
#endif /* GLOBALDEFINE_H_ */

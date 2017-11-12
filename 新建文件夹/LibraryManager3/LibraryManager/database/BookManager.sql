use master
go
--�������ݿ�
if exists(select * from sysdatabases where name = 'BookManager')
	drop database BookManager
go
create database BookManager
go
use BookManager
go

--ͼ�����ͱ�
if exists(select * from sysobjects where name = 'BookType')
	drop table BookType
go
create table BookType
(
	TypeID int identity(1,1) not null,--ͼ�����ͱ��
	TypeName varchar(50) not null--ͼ������
)
alter table BookType
add constraint PK_TypeID primary key(TypeID)
go

--ͼ���Ƿ���
if exists(select * from sysobjects where name = 'BookState')
	drop table BookState
go
create table BookState
(
	StateID int identity(1,1) not null,--ͼ��״̬���
	State varchar(10) not null--ͼ��״̬
)
alter table BookState
add constraint PK_StateID primary key(StateID)
go

--ͼ���Ǯ��
if exists(select * from sysobjects where name = 'BookPrice')
	drop table BookPrice
go
create table BookPrice
(
	BookPriceID int identity(1,1) not null,--ͼ��۱��
	BookUpPrice int not null,--ͼ����ʼ�۸�Χ
	BookDownPrice int not null,--ͼ����߼۸�Χ
	BookPrice numeric(6,1) not null,--���
	BackDate int not null--����涨ʱ��
)
alter table BookPrice
add constraint PK_BookPriceID primary key(BookPriceID)
go

--�������ͱ�
if exists(select * from sysobjects where name = 'CardType')
	drop table CardType
go
create table CardType
(
	CardTypeID int identity(1,1) not null,--�������ͱ��
	CardName varchar(50) not null,--������������
	CardAgio numeric(6,1) not null--�������Ͷ�Ӧ���ۿ�
)
alter table CardType
add constraint PK_CardTypeID primary key(CardTypeID)
go

--��Ա��
if exists(select * from sysobjects where name = 'UserTable')
	drop table UserTable
go
create table UserTable
(
	UserID int identity(10000,1) not null,--��Ա����
	UserName varchar(50) not null,--��Ա����
	UserSex char(2) not null,--��Ա�Ա�
	UserTel varchar(11) not null,--��Ա��ϵ�绰
	UserBrith datetime not null,--��Ա��������
	UserMoney money not null,--�������
	UserDate datetime not null,--���Ŵ���ʱ��
	CardTypeID int not null--��������
)
alter table UserTable
add constraint PK_UserID primary key(UserID)
--���
alter table UserTable
add constraint FK_UserTable_CardType foreign key(CardTypeID) references CardType(CardTypeID)
go

--ͼ���
if exists(select * from sysobjects where name = 'Book')
	drop table Book
go
create table Book
(
	BookID int identity(1000,1) not null,--ͼ����
	BookName varchar(50) not null,--ͼ����
	TypeID int not null,--ͼ������
	Price numeric(6,1) not null,--ͼ��۸�(��������۸�)
	Publish varchar(50) not null,--������(��Ȩ)
	StateID int not null--ͼ���Ƿ����
)
alter table Book
add constraint PK_Book primary key(BookID)
--���
alter table Book
add constraint FK_Book_BookState foreign key(StateID) references BookState(StateID)
alter table Book
add constraint FK_Book_BookType foreign key(TypeID) references BookType(TypeID)
go

--ͼ�齻�ױ�
if exists(select * from sysobjects where name = 'BookDeal')
	drop table BookDeal
go
create table BookDeal
(
	DealID int identity(1,1) not null,--����ID
	UserID int not null,--����ID
	BookID int not null,--ͼ��ID
	DealDate datetime not null,--������ʼʱ��
	DetailBackDate datetime not null,--��������ʱ��
	PriceID int not null,--�۸�ID
	BookLendPrice numeric(6,1) not null,--�����������ڷ���
	DealFlag varchar(50) not null,--���׼�¼
	BackDate datetime not null,--�û�����ʱ��
	YaJin int not null,
	ZuJin numeric(6,1) not null
)
alter table BookDeal
add constraint PK_DealID primary key(DealID)
go
--���
alter table BookDeal
add constraint FK_BookDeal_UserTable foreign key(UserID) references UserTable(UserID)
alter table BookDeal
add constraint FK_BookDeal_Book foreign key(BookID) references Book(BookID)
alter table BookDeal
add constraint FK_BookDeal_BookPrice foreign key(PriceID) references BookPrice(BookPriceID)
go

--�����������

--�������ͱ�
insert into CardType values('���ǻ�Ա',1)
insert into CardType values('��ͨ��Ա',0.9)
insert into CardType values('�׽��Ա',0.8)
insert into CardType values('��ʯ��Ա',0.7)

--ͼ���Ǯ��
insert into BookPrice values(0,6,0.5,2)
insert into BookPrice values(7,15,1,2)
insert into BookPrice values(16,25,1.5,3)
insert into BookPrice values(26,9999,2,4)

--ͼ���Ƿ�����
insert into BookState values('����')
insert into BookState values('���')

--ͼ�����ͱ�
insert into BookType values('C#')
insert into BookType values('Java')
insert into BookType values('���ݿ�')
insert into BookType values('���ģʽ')
insert into BookType values('HTML')

--ͼ���
insert into Book values('C#���ž���',1,5,'��Ƥ��',1)
insert into Book values('C#�߼������',1,10,'��Ƥ��',1)
insert into Book values('C#�߼������',1,15,'��Ƥ��',1)
insert into Book values('C#�߼������',1,30,'��Ƥ��',1)
insert into Book values('C#�߼������',1,158,'��Ƥ��',1)
insert into Book values('Java�߼����һ',2,20,'��Ƥ��',1)
insert into Book values('Java�߼���̶�',2,10,'��Ƥ��',1)
insert into Book values('Sql Server',3,6,'�廪',1)
insert into Book values('Access',3,8,'�廪',1)
insert into Book values('My Sql',3,17,'����',1)
insert into Book values('23�����ģʽGOF',4,4,'GOF',1)
insert into Book values('�����ģʽ',4,18,'С��',1)
insert into Book values('HTML��ҳ����',5,20,'����',1)
insert into Book values('һ��ͨHTML',5,35,'��ͨ',1)

--��Ա��
insert into UserTable values('','','','',0,'2008-10-09',1)
insert into UserTable values('����','��','13352557346','1989-02-28',200,'2003-12-10',2)
insert into UserTable values('����','��','13352557346','1989-02-28',50,'2003-12-10',2)
insert into UserTable values('С��','Ů','87935731','1989-11-20',150,'2005-04-20',4)
insert into UserTable values('����','��','53874631','1990-10-03',100,'2006-07-15',3)
insert into UserTable values('С��','��','13853257346','1992-11-21',80,'2009-02-10',4)

----------------------------------------�����洢����

--��ѯ���л�Ա��Ϣ
if exists(select * from sysobjects where name = 'proc_AllSelectUserTable')
	drop proc proc_AllSelectUserTable
go
create proc proc_AllSelectUserTable
as
	select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = Convert(varchar(10),u.UserBrith,111),
			u.UserMoney,UserDate = Convert(varchar(10),u.UserDate,111),
			u.CardTypeID,c.CardName
	from UserTable as u
	inner join CardType as c
	on u.CardTypeID = c.CardTypeID
	where c.CarDName <> '���ǻ�Ա'
go
--��ȡ���л�Ա����
if exists(select * from sysobjects where name = 'proc_AllSelectCardType')
	drop proc proc_AllSelectCardType
go
create proc proc_AllSelectCardType
as
	select * from CardType where CardTypeID <> (select CardTypeID from CardType where CardName = '���ǻ�Ա')
go
--������Ա�û�
if exists(select * from sysobjects where name = 'proc_InsertUserTable')
	drop proc proc_InsertUserTable
go
create proc proc_InsertUserTable
@UserName varchar(50),@UserSex char(2),@UserTel varchar(11),@UserBrith datetime,
@UserMoney money,@UserDate datetime,@CardTypeID int
as
	insert into UserTable values(@UserName,@UserSex,@UserTel,@UserBrith,@UserMoney,@UserDate,@CardTypeID)	
go
--�޸Ļ�Ա
if exists(select * from sysobjects where name = 'proc_UpdateUserTable')
	drop proc proc_UpdateUserTable
go
create proc proc_UpdateUserTable
@UserName varchar(50),@UserSex char(2),@UserTel varchar(11),@UserBrith datetime,
@UserMoney money,@UserDate datetime,@CardTypeID int,@UserID int
as
	update UserTable set UserName=@UserName,UserSex=@UserSex,UserTel=@UserTel,UserBrith=@UserBrith,
						UserMoney=@UserMoney,UserDate=@UserDate,CardTypeID=@CardTypeID
	where UserID = @UserID	
go
--����Ա��ֵ
if exists(select * from sysobjects where name = 'proc_AddUserTableMoney')
	drop proc proc_AddUserTableMoney
go
create proc proc_AddUserTableMoney
@UserID int,@UserMoney money
as
	update UserTable set UserMoney = UserMoney + @UserMoney where UserID = @UserID
go
--ɾ��һ����Ա��Ϣ
if exists(select * from sysobjects where name = 'proc_DeleteUserTable')
	drop proc proc_DeleteUserTable
go
create proc proc_DeleteUserTable
@UserID int
as
	delete UserTable where UserID = @UserID
go
--ģ����ѯUserTable
if exists(select * from sysobjects where name = 'proc_MohuSelectUserTable')
	drop proc proc_MohuSelectUserTable
go
create proc proc_MohuSelectUserTable
@type varchar(50),@tiaojian varchar(50)
as
	if(@type = 'ȫ��')
	begin
		select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = Convert(varchar(10),u.UserBrith,111),
		u.UserMoney,UserDate = Convert(varchar(10),u.UserDate,111),u.CardTypeID,c.CardName
		from UserTable as u inner join CardType as c on u.CardTypeID = c.CardTypeID
		where c.CardTypeID <> (select CardTypeID from CardType where CardName = '���ǻ�Ա')
	end
	else if(@type = '��Ա��')
	begin
		select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = Convert(varchar(10),u.UserBrith,111),
		u.UserMoney,UserDate = Convert(varchar(10),u.UserDate,111),u.CardTypeID,c.CardName
		from UserTable as u inner join CardType as c on u.CardTypeID = c.CardTypeID
		where u.UserID = convert(int,@tiaojian) and c.CardTypeID <> (select CardTypeID from CardType where CardName = '���ǻ�Ա')
	end
	else if(@type = '��Ա����')
	begin
		select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = Convert(varchar(10),u.UserBrith,111),
		u.UserMoney,UserDate = Convert(varchar(10),u.UserDate,111),u.CardTypeID,c.CardName
		from UserTable as u inner join CardType as c on u.CardTypeID = c.CardTypeID
		where u.UserName like '%'+@tiaojian+'%' and c.CardTypeID <> (select CardTypeID from CardType where CardName = '���ǻ�Ա')
	end
go
--��ȡ���е�ͼ������
if exists(select * from sysobjects where name = 'proc_AllSelectBookType')
	drop proc proc_AllSelectBookType
go
create proc proc_AllSelectBookType
as
	select * from BookType
go
--��ȡָ������ͼ��
if exists(select * from sysobjects where name = 'proc_SelectBook')
	drop proc proc_SelectBook
go
create proc proc_SelectBook
@TypeID int
as
	select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
	from Book as b
	inner join BookType as t on b.TypeID = t.TypeID
	inner join BookState as s on b.StateID = s.StateID
	where b.TypeID = @TypeID
go
--ģ����ѯͼ����Ϣ
if exists(select * from sysobjects where name = 'proc_MoHuSelectBook')
	drop proc proc_MoHuSelectBook
go
create proc proc_MoHuSelectBook
@TypeID int,@BookName varchar(50)
as
	select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
	from Book as b
	inner join BookType as t on b.TypeID = t.TypeID
	inner join BookState as s on b.StateID = s.StateID
	where b.TypeID = @TypeID and b.BookName like '%'+@BookName+'%'
go
--��ȡ���е�ͼ��״̬
if exists(select * from sysobjects where name = 'proc_AllSelectBookState')
	drop proc proc_AllSelectBookState
go
create proc proc_AllSelectBookState
as
	select * from BookState
go
--����һ��ͼ��
if exists(select * from sysobjects where name = 'proc_InsertBook')
	drop proc proc_InsertBook
go
create proc proc_InsertBook
@BookName varchar(50),@TypeID int,@Price numeric(6,1),@Publish varchar(50),@StateID int
as
	insert into Book values(@BookName,@TypeID,@Price,@Publish,@StateID)	
go
--ɾ��һ��ͼ��
if exists(select * from sysobjects where name = 'proc_DeleteBook')
	drop proc proc_DeleteBook
go
create proc proc_DeleteBook
@BookID int
as
	delete Book where BookID = @BookID
go
--��ѯͼ�������Ƿ����
if exists(select * from sysobjects where name = 'proc_SelectBookTypeName')
	drop proc proc_SelectBookTypeName
go
create proc proc_SelectBookTypeName
@TypeName varchar(50)
as
	select count(*) from BookType where TypeName = @TypeName
go
--����һ��ͼ��������Ϣ
if exists(select * from sysobjects where name = 'proc_InsertBookType')
	drop proc proc_InsertBookType
go
create proc proc_InsertBookType
@TypeName varchar(50)
as
	insert into BookType values(@TypeName)
go
--��ȡ����ͼ��
if exists(select * from sysobjects where name = 'proc_AllSelectBook')
	drop proc proc_AllSelectBook
go
create proc proc_AllSelectBook
as
	select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
	from Book as b
	inner join BookType as t on b.TypeID = t.TypeID
	inner join BookState as s on b.StateID = s.StateID
go
--��ѯ������ͼ���Ƿ����
if exists(select * from sysobjects where name = 'proc_SelectBookCunZai')
	drop proc proc_SelectBookCunZai
go
create proc proc_SelectBookCunZai
@BookName varchar(50),@TypeID int
as
	select count(*) from Book where BookName = @BookName and TypeID = @TypeID
go
--ģ����ѯͼ����Ϣ2
if exists(select * from sysobjects where name = 'proc_MoHuSelectBook2')
	drop proc proc_MoHuSelectBook2
go
create proc proc_MoHuSelectBook2
@Type varchar(50),@TiaoJian varchar(50)
as
	if(@Type = 'ȫ��ͼ��')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
	end
	else if(@Type = 'ͼ������')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where b.BookName like '%'+@TiaoJian+'%'
	end
	else if(@Type = 'ͼ������')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where b.TypeID = Convert(int,@TiaoJian)
	end
	else if(@Type = '���')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where s.StateID = (Select StateID from BookState where State = '���')
	end
	else if(@Type = '����')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where s.StateID = (Select StateID from BookState where State = '����')
	end
go
--�ж������Ա�Ƿ����
if exists(select * from sysobjects where name = 'proc_SelectUserID')
	drop proc proc_SelectUserID
go
create proc proc_SelectUserID
@UserID int
as
	select count(*) from UserTable where UserID = @UserID and @UserID <> 10000
go
--�õ�����۸�ID
if exists(select * from sysobjects where name = 'proc_SelectBookPriceID')
	drop proc proc_SelectBookPriceID
go
create proc proc_SelectBookPriceID
@Price int
as
	select BookPriceID from BookPrice where @Price>=BookUpPrice and @Price<=BookDownPrice
go
--���һ����
if exists(select * from sysobjects where name = 'proc_InsertBookDeal')
	drop proc proc_InsertBookDeal
go
create proc proc_InsertBookDeal
@UserID int,@BookID int,@DealDate datetime,@PriceID int,
@Price int,@BackDate datetime,@YaJin int
as
	declare @QiXian int,@DetailBackDate datetime,@BookLendPrice numeric(6,1),@ZuJin numeric(6,1),
			@ZheKou numeric(6,1),@ChaoChuTianShu int,@JieShuTianShu int,@QiXianTianShu int
	select @QiXian = BackDate from BookPrice where BookPriceID = @PriceID--�õ��ü�λ�Ľ�������
	set @DetailBackDate = dateadd(dd,@QiXian,@DealDate)--�õ����������
	set @BookLendPrice = @Price*0.05*datediff(dd,@DetailBackDate,@BackDate)--�õ��������޵ķ���
	if(@BookLendPrice < 0)
	begin
		set @BookLendPrice = 0
	end
	select @ZuJin = BookPrice from BookPrice where BookPriceID = @PriceID--�õ����
	select @ZheKou = CardAgio from CardType where CardTypeID = (select CardTypeID from UserTable where UserID = @UserID)--�õ��ۿ�
	set @ChaoChuTianShu = datediff(dd,@DetailBackDate,@BackDate)--�õ�����������
	set @JieShuTianShu = datediff(dd,@DealDate,@BackDate)--�õ������������
	select @QiXianTianShu = BackDate from BookPrice where BookPriceID = @PriceID--�õ���������
	if(@JieShuTianShu = 1 or @JieShuTianShu = 0)
	begin
		set @ZuJin = @ZuJin*@ZheKou*0.7
	end
	else
	begin
		if((@JieShuTianShu - @QiXianTianShu) <= 0)
		begin
			set @ZuJin = @ZuJin*@ZheKou*@JieShuTianShu
		end
		else
		begin
			set @ZuJin = @ZuJin*@ZheKou*@QiXianTianShu+@BookLendPrice
		end
	end

	insert into BookDeal values(@UserID,@BookID,@DealDate,@DetailBackDate,@PriceID,@BookLendPrice,'���',@BackDate,@YaJin,@ZuJin)
go
--exec proc_InsertBookDeal 10001,1011,'2009-04-10',1,100,'2009-04-20',100
--BookDeal������
--insert������
create trigger tri_BookDeal
on BookDeal
for insert
as
	declare @BookID int
	--�õ�����������
	select @BookID = BookID from inserted
	update Book set StateID = (select StateID from BookState where State = '���')
	where @BookID = BookID
go
--��ѯ���е����ȥ��ͼ����Ϣ
if exists(select * from sysobjects where name = 'proc_AllSelectZuChuBook')
	drop proc proc_AllSelectZuChuBook
go
create proc proc_AllSelectZuChuBook
as
	select b.BookID,b.BookName,d.YaJin,d.ZuJin,b.Price,DealDate=convert(varchar(10),d.DealDate,111),d.BookLendPrice,u.UserID
	from BookDeal as d
	inner join Book b on d.BookID = b.BookID
	inner join UserTable as u on d.UserID = u.UserID
	where b.StateID = (select StateID from BookState where State = '���') and d.DealFlag = '���'
go
--ģ����ѯָ�����ȥ��ͼ����Ϣ
if exists(select * from sysobjects where name = 'proc_MoHuAllSelectZuChuBook')
	drop proc proc_MoHuAllSelectZuChuBook
go
create proc proc_MoHuAllSelectZuChuBook
@BookName varchar(50)
as
	select b.BookID,b.BookName,d.YaJin,d.ZuJin,b.Price,DealDate=convert(varchar(10),d.DealDate,111),d.BookLendPrice,u.UserID
	from BookDeal as d
	inner join Book b on d.BookID = b.BookID
	inner join UserTable as u on d.UserID = u.UserID
	where b.StateID = (select StateID from BookState where State = '���') and b.BookName like '%'+@BookName+'%' and d.DealFlag = '���'
go
--����
if exists(select * from sysobjects where name = 'proc_UpdateBookState')
	drop proc proc_UpdateBookState
go
create proc proc_UpdateBookState
@BookID int,@UserID int,@ZuJin money
as
	update Book set StateID = (select StateID from BookState where State = '����')
	where BookID = @BookID
	update UserTable set UserMoney = UserMoney - @ZuJin
	where UserID = @UserID
	update BookDeal set DealFlag = '�ѻ�' where BookID = @BookID
go
--�޸Ļ�Ա������
if exists(select * from sysobjects where name = 'proc_UpdateCardType')
	drop proc proc_UpdateCardType
go
create proc proc_UpdateCardType
@CardTypeID int,@CardName varchar(50),@CardAgio numeric(6,1)
as
	update CardType set CardName = @CardName,CardAgio = @CardAgio
	where CardTypeID = @CardTypeID
go
--������Ա������
if exists(select * from sysobjects where name = 'proc_InsertCardType')
	drop proc proc_InsertCardType
go
create proc proc_InsertCardType
@CardName varchar(50),@CardAgio numeric(6,1)
as
	insert into CardType values(@CardName,@CardAgio)
go
--�жϻ�Ա�������Ƿ����
if exists(select * from sysobjects where name = 'proc_SelectCardType')
	drop proc proc_SelectCardType
go
create proc proc_SelectCardType
@CardName varchar(50)
as
	select count(*) from CardType where CardName = @CardName
go
--��ȡ��������۸�
if exists(select * from sysobjects where name = 'proc_AllSelectBookPrice')
	drop proc proc_AllSelectBookPrice
go
create proc proc_AllSelectBookPrice
as
	select * from BookPrice
go
--�޸������趨
if exists(select * from sysobjects where name = 'proc_UpdateBookPrice')
	drop proc proc_UpdateBookPrice
go
create proc proc_UpdateBookPrice
@BookPriceID int,@BookUpPrice int,@BookDownPrice int,@BookPrice numeric(6,1),@BackDate int
as
	update BookPrice set BookUpPrice = @BookUpPrice,@BookDownPrice = BookDownPrice,
			BookPrice = @BookPrice,BackDate = @BackDate
	where BookPriceID = @BookPriceID
go
--�ж�һ����Ա����û��
if exists(select * from sysobjects where name = 'proc_SelectDealUserID')
	drop proc proc_SelectDealUserID
go
create proc proc_SelectDealUserID
@UserID int
as
	select count(*) from BookDeal where UserID = @UserID
go

--select * from dbo.Book
--select * from dbo.BookDeal
--select * from dbo.UserTable
--select * from dbo.BookPrice
--select * from dbo.BookState
--select * from dbo.BookType
--select * from dbo.CardType
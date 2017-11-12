use master
go
--创建数据库
if exists(select * from sysdatabases where name = 'BookManager')
	drop database BookManager
go
create database BookManager
go
use BookManager
go

--图书类型表
if exists(select * from sysobjects where name = 'BookType')
	drop table BookType
go
create table BookType
(
	TypeID int identity(1,1) not null,--图书类型编号
	TypeName varchar(50) not null--图书类型
)
alter table BookType
add constraint PK_TypeID primary key(TypeID)
go

--图书是否借出
if exists(select * from sysobjects where name = 'BookState')
	drop table BookState
go
create table BookState
(
	StateID int identity(1,1) not null,--图书状态编号
	State varchar(10) not null--图书状态
)
alter table BookState
add constraint PK_StateID primary key(StateID)
go

--图书价钱表
if exists(select * from sysobjects where name = 'BookPrice')
	drop table BookPrice
go
create table BookPrice
(
	BookPriceID int identity(1,1) not null,--图书价编号
	BookUpPrice int not null,--图书起始价格范围
	BookDownPrice int not null,--图书最高价格范围
	BookPrice numeric(6,1) not null,--租金
	BackDate int not null--借出规定时间
)
alter table BookPrice
add constraint PK_BookPriceID primary key(BookPriceID)
go

--卡的类型表
if exists(select * from sysobjects where name = 'CardType')
	drop table CardType
go
create table CardType
(
	CardTypeID int identity(1,1) not null,--卡的类型编号
	CardName varchar(50) not null,--卡的类型名称
	CardAgio numeric(6,1) not null--卡的类型对应的折扣
)
alter table CardType
add constraint PK_CardTypeID primary key(CardTypeID)
go

--会员表
if exists(select * from sysobjects where name = 'UserTable')
	drop table UserTable
go
create table UserTable
(
	UserID int identity(10000,1) not null,--会员卡号
	UserName varchar(50) not null,--会员姓名
	UserSex char(2) not null,--会员性别
	UserTel varchar(11) not null,--会员联系电话
	UserBrith datetime not null,--会员出生年月
	UserMoney money not null,--卡号余额
	UserDate datetime not null,--卡号创建时间
	CardTypeID int not null--卡号类型
)
alter table UserTable
add constraint PK_UserID primary key(UserID)
--外键
alter table UserTable
add constraint FK_UserTable_CardType foreign key(CardTypeID) references CardType(CardTypeID)
go

--图书表
if exists(select * from sysobjects where name = 'Book')
	drop table Book
go
create table Book
(
	BookID int identity(1000,1) not null,--图书编号
	BookName varchar(50) not null,--图书名
	TypeID int not null,--图书类型
	Price numeric(6,1) not null,--图书价格(不是租书价格)
	Publish varchar(50) not null,--出版社(版权)
	StateID int not null--图书是否租出
)
alter table Book
add constraint PK_Book primary key(BookID)
--外键
alter table Book
add constraint FK_Book_BookState foreign key(StateID) references BookState(StateID)
alter table Book
add constraint FK_Book_BookType foreign key(TypeID) references BookType(TypeID)
go

--图书交易表
if exists(select * from sysobjects where name = 'BookDeal')
	drop table BookDeal
go
create table BookDeal
(
	DealID int identity(1,1) not null,--租书ID
	UserID int not null,--卡号ID
	BookID int not null,--图书ID
	DealDate datetime not null,--借书起始时间
	DetailBackDate datetime not null,--借书期限时间
	PriceID int not null,--价格ID
	BookLendPrice numeric(6,1) not null,--超过借书日期罚金
	DealFlag varchar(50) not null,--交易记录
	BackDate datetime not null,--用户还书时间
	YaJin int not null,
	ZuJin numeric(6,1) not null
)
alter table BookDeal
add constraint PK_DealID primary key(DealID)
go
--外键
alter table BookDeal
add constraint FK_BookDeal_UserTable foreign key(UserID) references UserTable(UserID)
alter table BookDeal
add constraint FK_BookDeal_Book foreign key(BookID) references Book(BookID)
alter table BookDeal
add constraint FK_BookDeal_BookPrice foreign key(PriceID) references BookPrice(BookPriceID)
go

--插入测试数据

--卡的类型表
insert into CardType values('不是会员',1)
insert into CardType values('普通会员',0.9)
insert into CardType values('白金会员',0.8)
insert into CardType values('钻石会员',0.7)

--图书价钱表
insert into BookPrice values(0,6,0.5,2)
insert into BookPrice values(7,15,1,2)
insert into BookPrice values(16,25,1.5,3)
insert into BookPrice values(26,9999,2,4)

--图书是否借出表
insert into BookState values('正常')
insert into BookState values('借出')

--图书类型表
insert into BookType values('C#')
insert into BookType values('Java')
insert into BookType values('数据库')
insert into BookType values('设计模式')
insert into BookType values('HTML')

--图书表
insert into Book values('C#入门经典',1,5,'红皮书',1)
insert into Book values('C#高级编程三',1,10,'红皮书',1)
insert into Book values('C#高级编程四',1,15,'红皮书',1)
insert into Book values('C#高级编程五',1,30,'红皮书',1)
insert into Book values('C#高级编程六',1,158,'红皮书',1)
insert into Book values('Java高级编程一',2,20,'黑皮书',1)
insert into Book values('Java高级编程二',2,10,'黑皮书',1)
insert into Book values('Sql Server',3,6,'清华',1)
insert into Book values('Access',3,8,'清华',1)
insert into Book values('My Sql',3,17,'北大',1)
insert into Book values('23种设计模式GOF',4,4,'GOF',1)
insert into Book values('大话设计模式',4,18,'小菜',1)
insert into Book values('HTML网页制作',5,20,'大良',1)
insert into Book values('一点通HTML',5,35,'九通',1)

--会员表
insert into UserTable values('','','','',0,'2008-10-09',1)
insert into UserTable values('六子','男','13352557346','1989-02-28',200,'2003-12-10',2)
insert into UserTable values('阿黄','男','13352557346','1989-02-28',50,'2003-12-10',2)
insert into UserTable values('小冰','女','87935731','1989-11-20',150,'2005-04-20',4)
insert into UserTable values('锋子','男','53874631','1990-10-03',100,'2006-07-15',3)
insert into UserTable values('小黄','男','13853257346','1992-11-21',80,'2009-02-10',4)

----------------------------------------创建存储过程

--查询所有会员信息
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
	where c.CarDName <> '不是会员'
go
--获取所有会员类型
if exists(select * from sysobjects where name = 'proc_AllSelectCardType')
	drop proc proc_AllSelectCardType
go
create proc proc_AllSelectCardType
as
	select * from CardType where CardTypeID <> (select CardTypeID from CardType where CardName = '不是会员')
go
--新增会员用户
if exists(select * from sysobjects where name = 'proc_InsertUserTable')
	drop proc proc_InsertUserTable
go
create proc proc_InsertUserTable
@UserName varchar(50),@UserSex char(2),@UserTel varchar(11),@UserBrith datetime,
@UserMoney money,@UserDate datetime,@CardTypeID int
as
	insert into UserTable values(@UserName,@UserSex,@UserTel,@UserBrith,@UserMoney,@UserDate,@CardTypeID)	
go
--修改会员
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
--给会员充值
if exists(select * from sysobjects where name = 'proc_AddUserTableMoney')
	drop proc proc_AddUserTableMoney
go
create proc proc_AddUserTableMoney
@UserID int,@UserMoney money
as
	update UserTable set UserMoney = UserMoney + @UserMoney where UserID = @UserID
go
--删除一条会员信息
if exists(select * from sysobjects where name = 'proc_DeleteUserTable')
	drop proc proc_DeleteUserTable
go
create proc proc_DeleteUserTable
@UserID int
as
	delete UserTable where UserID = @UserID
go
--模糊查询UserTable
if exists(select * from sysobjects where name = 'proc_MohuSelectUserTable')
	drop proc proc_MohuSelectUserTable
go
create proc proc_MohuSelectUserTable
@type varchar(50),@tiaojian varchar(50)
as
	if(@type = '全部')
	begin
		select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = Convert(varchar(10),u.UserBrith,111),
		u.UserMoney,UserDate = Convert(varchar(10),u.UserDate,111),u.CardTypeID,c.CardName
		from UserTable as u inner join CardType as c on u.CardTypeID = c.CardTypeID
		where c.CardTypeID <> (select CardTypeID from CardType where CardName = '不是会员')
	end
	else if(@type = '会员号')
	begin
		select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = Convert(varchar(10),u.UserBrith,111),
		u.UserMoney,UserDate = Convert(varchar(10),u.UserDate,111),u.CardTypeID,c.CardName
		from UserTable as u inner join CardType as c on u.CardTypeID = c.CardTypeID
		where u.UserID = convert(int,@tiaojian) and c.CardTypeID <> (select CardTypeID from CardType where CardName = '不是会员')
	end
	else if(@type = '会员姓名')
	begin
		select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = Convert(varchar(10),u.UserBrith,111),
		u.UserMoney,UserDate = Convert(varchar(10),u.UserDate,111),u.CardTypeID,c.CardName
		from UserTable as u inner join CardType as c on u.CardTypeID = c.CardTypeID
		where u.UserName like '%'+@tiaojian+'%' and c.CardTypeID <> (select CardTypeID from CardType where CardName = '不是会员')
	end
go
--获取所有的图书类型
if exists(select * from sysobjects where name = 'proc_AllSelectBookType')
	drop proc proc_AllSelectBookType
go
create proc proc_AllSelectBookType
as
	select * from BookType
go
--获取指定类型图书
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
--模糊查询图书信息
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
--获取所有的图书状态
if exists(select * from sysobjects where name = 'proc_AllSelectBookState')
	drop proc proc_AllSelectBookState
go
create proc proc_AllSelectBookState
as
	select * from BookState
go
--新增一本图书
if exists(select * from sysobjects where name = 'proc_InsertBook')
	drop proc proc_InsertBook
go
create proc proc_InsertBook
@BookName varchar(50),@TypeID int,@Price numeric(6,1),@Publish varchar(50),@StateID int
as
	insert into Book values(@BookName,@TypeID,@Price,@Publish,@StateID)	
go
--删除一本图书
if exists(select * from sysobjects where name = 'proc_DeleteBook')
	drop proc proc_DeleteBook
go
create proc proc_DeleteBook
@BookID int
as
	delete Book where BookID = @BookID
go
--查询图书类型是否存在
if exists(select * from sysobjects where name = 'proc_SelectBookTypeName')
	drop proc proc_SelectBookTypeName
go
create proc proc_SelectBookTypeName
@TypeName varchar(50)
as
	select count(*) from BookType where TypeName = @TypeName
go
--新增一条图书类型信息
if exists(select * from sysobjects where name = 'proc_InsertBookType')
	drop proc proc_InsertBookType
go
create proc proc_InsertBookType
@TypeName varchar(50)
as
	insert into BookType values(@TypeName)
go
--获取所有图书
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
--查询新增的图书是否存在
if exists(select * from sysobjects where name = 'proc_SelectBookCunZai')
	drop proc proc_SelectBookCunZai
go
create proc proc_SelectBookCunZai
@BookName varchar(50),@TypeID int
as
	select count(*) from Book where BookName = @BookName and TypeID = @TypeID
go
--模糊查询图书信息2
if exists(select * from sysobjects where name = 'proc_MoHuSelectBook2')
	drop proc proc_MoHuSelectBook2
go
create proc proc_MoHuSelectBook2
@Type varchar(50),@TiaoJian varchar(50)
as
	if(@Type = '全部图书')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
	end
	else if(@Type = '图书名称')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where b.BookName like '%'+@TiaoJian+'%'
	end
	else if(@Type = '图书类型')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where b.TypeID = Convert(int,@TiaoJian)
	end
	else if(@Type = '借出')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where s.StateID = (Select StateID from BookState where State = '借出')
	end
	else if(@Type = '正常')
	begin
		select b.BookID,b.BookName,t.TypeName,B.Price,b.Publish,s.State,b.StateID,t.TypeID
		from Book as b
		inner join BookType as t on b.TypeID = t.TypeID
		inner join BookState as s on b.StateID = s.StateID
		where s.StateID = (Select StateID from BookState where State = '正常')
	end
go
--判断租书会员是否存在
if exists(select * from sysobjects where name = 'proc_SelectUserID')
	drop proc proc_SelectUserID
go
create proc proc_SelectUserID
@UserID int
as
	select count(*) from UserTable where UserID = @UserID and @UserID <> 10000
go
--得到租书价格ID
if exists(select * from sysobjects where name = 'proc_SelectBookPriceID')
	drop proc proc_SelectBookPriceID
go
create proc proc_SelectBookPriceID
@Price int
as
	select BookPriceID from BookPrice where @Price>=BookUpPrice and @Price<=BookDownPrice
go
--租出一本书
if exists(select * from sysobjects where name = 'proc_InsertBookDeal')
	drop proc proc_InsertBookDeal
go
create proc proc_InsertBookDeal
@UserID int,@BookID int,@DealDate datetime,@PriceID int,
@Price int,@BackDate datetime,@YaJin int
as
	declare @QiXian int,@DetailBackDate datetime,@BookLendPrice numeric(6,1),@ZuJin numeric(6,1),
			@ZheKou numeric(6,1),@ChaoChuTianShu int,@JieShuTianShu int,@QiXianTianShu int
	select @QiXian = BackDate from BookPrice where BookPriceID = @PriceID--得到该价位的借书期限
	set @DetailBackDate = dateadd(dd,@QiXian,@DealDate)--得到借书的期限
	set @BookLendPrice = @Price*0.05*datediff(dd,@DetailBackDate,@BackDate)--得到超过期限的罚金
	if(@BookLendPrice < 0)
	begin
		set @BookLendPrice = 0
	end
	select @ZuJin = BookPrice from BookPrice where BookPriceID = @PriceID--得到租金
	select @ZheKou = CardAgio from CardType where CardTypeID = (select CardTypeID from UserTable where UserID = @UserID)--得到折扣
	set @ChaoChuTianShu = datediff(dd,@DetailBackDate,@BackDate)--得到超出的天数
	set @JieShuTianShu = datediff(dd,@DealDate,@BackDate)--得到借书的总天数
	select @QiXianTianShu = BackDate from BookPrice where BookPriceID = @PriceID--得到期限天数
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

	insert into BookDeal values(@UserID,@BookID,@DealDate,@DetailBackDate,@PriceID,@BookLendPrice,'借出',@BackDate,@YaJin,@ZuJin)
go
--exec proc_InsertBookDeal 10001,1011,'2009-04-10',1,100,'2009-04-20',100
--BookDeal触发器
--insert触发器
create trigger tri_BookDeal
on BookDeal
for insert
as
	declare @BookID int
	--得到插入后的数据
	select @BookID = BookID from inserted
	update Book set StateID = (select StateID from BookState where State = '借出')
	where @BookID = BookID
go
--查询所有的租出去的图书信息
if exists(select * from sysobjects where name = 'proc_AllSelectZuChuBook')
	drop proc proc_AllSelectZuChuBook
go
create proc proc_AllSelectZuChuBook
as
	select b.BookID,b.BookName,d.YaJin,d.ZuJin,b.Price,DealDate=convert(varchar(10),d.DealDate,111),d.BookLendPrice,u.UserID
	from BookDeal as d
	inner join Book b on d.BookID = b.BookID
	inner join UserTable as u on d.UserID = u.UserID
	where b.StateID = (select StateID from BookState where State = '借出') and d.DealFlag = '借出'
go
--模糊查询指定租出去的图书信息
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
	where b.StateID = (select StateID from BookState where State = '借出') and b.BookName like '%'+@BookName+'%' and d.DealFlag = '借出'
go
--还书
if exists(select * from sysobjects where name = 'proc_UpdateBookState')
	drop proc proc_UpdateBookState
go
create proc proc_UpdateBookState
@BookID int,@UserID int,@ZuJin money
as
	update Book set StateID = (select StateID from BookState where State = '正常')
	where BookID = @BookID
	update UserTable set UserMoney = UserMoney - @ZuJin
	where UserID = @UserID
	update BookDeal set DealFlag = '已还' where BookID = @BookID
go
--修改会员卡类型
if exists(select * from sysobjects where name = 'proc_UpdateCardType')
	drop proc proc_UpdateCardType
go
create proc proc_UpdateCardType
@CardTypeID int,@CardName varchar(50),@CardAgio numeric(6,1)
as
	update CardType set CardName = @CardName,CardAgio = @CardAgio
	where CardTypeID = @CardTypeID
go
--新增会员卡类型
if exists(select * from sysobjects where name = 'proc_InsertCardType')
	drop proc proc_InsertCardType
go
create proc proc_InsertCardType
@CardName varchar(50),@CardAgio numeric(6,1)
as
	insert into CardType values(@CardName,@CardAgio)
go
--判断会员卡类型是否存在
if exists(select * from sysobjects where name = 'proc_SelectCardType')
	drop proc proc_SelectCardType
go
create proc proc_SelectCardType
@CardName varchar(50)
as
	select count(*) from CardType where CardName = @CardName
go
--获取所有租书价格
if exists(select * from sysobjects where name = 'proc_AllSelectBookPrice')
	drop proc proc_AllSelectBookPrice
go
create proc proc_AllSelectBookPrice
as
	select * from BookPrice
go
--修改租书设定
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
--判断一个会员借书没有
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
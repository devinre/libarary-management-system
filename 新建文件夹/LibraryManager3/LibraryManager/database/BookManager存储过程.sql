--查询所有会员的信息(不包括不是会员这一列)
if exists(select * from sysobjects where name='proc_SelectAllUser')
drop proc proc_SelectAllUser
go
create proc proc_SelectAllUser
as
	select u.UserID,u.UserName,u.UserSex,u.UserTel,UserBrith = convert(varchar(10),u.UserBrith,111),
	u.UserMoney,UserDate=convert(varchar(10),u.UserDate,111),u.CardTypeID,c.CardName
	from UserTable u
	inner join
	CardType c
	on u.CardTypeID=c.CardTypeID
	where c.CardName<>'不是会员'
go

--获取会员卡类型
if exists(select * from sysobjects where name='proc_GetCardType')
drop proc proc_GetCardType
go
create proc proc_GetCardType
as
	select CardTypeID,CardName,CardAgio from CardType where CardName<>'不是会员'
go

--添加新会员
if exists(select * from sysobjects where name='proc_AddNewUser')
drop proc proc_AddNewUser
go
create proc proc_AddNewUser
@name varchar(10),@sex char(2),@tel varchar(20) ,@brith datetime,
@money money,@date datetime,@id int
as
	insert into UserTable(UserName,UserSex,UserTel,UserBrith,UserMoney,UserDate,CardTypeID)
	values(@name,@sex,@tel,@brith,@money,@date,@id)
go

--判断会员号是否存在
if exists(select * from sysobjects where name='proc_JudgeUser')
drop proc proc_JudgeUser
go
create proc proc_JudgeUser
@id int
as
	select count(*) from UserTable where UserID=@id
go

--修改会员信息
if exists(select * from sysobjects where name='proc_UpdateUser')
drop proc proc_UpdateUser
go
create proc proc_UpdateUser
@name varchar(10),@sex char(2),@tel varchar(20) ,@brith datetime,
@money money,@date datetime,@id int,@userID int
as
	update UserTable set UserName=@name,UserSex=@sex,UserTel=@tel,UserBrith=@brith,
	UserMoney=@money,UserDate=@date,CardTypeID=@id
	where UserID=@userID
go

--删除会员信息
if exists(select * from sysobjects where name='proc_DeleteUser')
drop proc proc_DeleteUser
go
create proc proc_DeleteUser
@userID int
as
	delete UserTable where UserID=@userID
go

--会员充值
if exists(select * from sysobjects where name='proc_UpdateUserMoney')
drop proc proc_UpdateUserMoney
go
create proc proc_UpdateUserMoney
@money money,@id int
as
	update UserTable set UserMoney=UserMoney+@money where UserID=@id
go


--获取图书类型
if exists(select * from sysobjects where name='proc_GetBookType')
drop proc proc_GetBookType
go
create proc proc_GetBookType
as
	select TypeID,TypeName from BookType
go

--获取各类型的图书信息
if exists (select * from sysobjects where name='proc_GetBookMess')
drop proc proc_GetBookMess
go
create proc proc_GetBookMess
@id int
as
	select BookID,BookName,b.TypeID,TypeName =(select TypeName from BookType a where a.TypeID=b.TypeID),Price,Publish,
	b.StateID,State =(select State from BookState c where c.StateID=b.StateID) from Book b where b.TypeID=@id
go

--增加图书类型
if exists (select * from sysobjects where name='proc_AddNewBookType')
drop proc proc_AddNewBookType
go
create proc proc_AddNewBookType
@name varchar(50)
as
	insert BookType (TypeName)
	values(@name)
go


--判断图书类型是否存在
if exists (select * from sysobjects where name='proc_JudgeType')
drop proc proc_JudgeType
go
create proc proc_JudgeType
@name varchar(50)
as
	select count(*) from BookType where TypeName=@name
go


--获取图书状态
if exists (select * from sysobjects where name='proc_GetBookState')
drop proc proc_GetBookState
go
create proc proc_GetBookState
as
	select StateID,State from BookState
go

--通过图书名称判断图书是否存在
if exists(select * from sysobjects where name='proc_JudgeBook')
drop proc proc_JudgeBook
go
create proc proc_JudgeBook
@name varchar(50)
as
	select count(*) from Book where BookName=@name
go

--通过图书ID判断图书是否已借出
if exists(select * from sysobjects where name='proc_JudgeBookDeal')
drop proc proc_JudgeBookDeal
go
create proc proc_JudgeBookDeal
@name varchar(50)
as
	declare @id int
	select @id=bookid from book where bookname=@name
	select count(*) from BookDeal where BookID=@id and DealFlag='借出'
go

--添加新图书
if exists(select * from sysobjects where name='proc_AddNewBook')
drop proc proc_AddNewBook
go
create proc proc_AddNewBook
@name varchar(20),@typeID int,@price money,@publish varchar(50),@stateID int
as
	insert Book (BookName,TypeID,Price,Publish,StateID)
	values(@name,@typeID,@price,@publish,@stateID)
go

--修改图书
if exists(select * from sysobjects where name='proc_UpdateBook')
drop proc proc_UpdateBook
go
create proc proc_UpdateBook
@name varchar(20),@typeID int,@price money,@publish varchar(50),@stateID int,@bookID int
as
	update Book set BookName=@name,TypeID=@typeID,Price=@price,Publish=@publish,StateID=@stateID
	where BookID=@bookID
go

--删除图书信息
if exists(select * from sysobjects where name='proc_DeleteBook')
drop proc proc_DeleteBook
go
create proc proc_DeleteBook
@id int
as
	delete Book where BookID=@id
go

--通过图书名称和ID查找图书信息(支持模糊查找)
if exists (select * from sysobjects where name='proc_SearchBookByBookName')
drop proc proc_SearchBookByBookName
go
create proc proc_SearchBookByBookName
@id int,@name varchar(50)
as
	select BookID,BookName,b.TypeID,TypeName =(select TypeName from BookType a where a.TypeID=b.TypeID),Price,Publish,
	b.StateID,State =(select State from BookState c where c.StateID=b.StateID) from Book b 
	where b.TypeID=@id and BookName like '%'+@name+'%'
go

--查询所有图书
if exists(select * from sysobjects where name='pro_GetAllBook')
drop proc pro_GetAllBook
go
create proc pro_GetAllBook
as
	select BookID,BookName,b.TypeID,TypeName =(select TypeName from BookType a where a.TypeID=b.TypeID),Price,Publish,
	b.StateID,State =(select State from BookState c where c.StateID=b.StateID) from Book b
go

--通过图书名称查找图书信息(支持模糊查找)
if exists(select * from sysobjects where name='proc_GetBookMessByName')
drop proc proc_GetBookMessByName
go
create proc proc_GetBookMessByName
@name varchar(50)
as
	select BookID,BookName,b.TypeID,TypeName =(select TypeName from BookType a where a.TypeID=b.TypeID),Price,Publish,
	b.StateID,State =(select State from BookState c where c.StateID=b.StateID) from Book b 
	where BookName like '%'+@name+'%'
go

--通过图书状态和图书名称查找图书信息（支持模糊查找）
if exists(select * from sysobjects where name='proc_GetBookMessByState')
drop proc proc_GetBookMessByState
go
create proc proc_GetBookMessByState
@stateid int,@name varchar(50)
as
	select BookID,BookName,b.TypeID,TypeName =(select TypeName from BookType a where a.TypeID=b.TypeID),Price,Publish,
	b.StateID,State =(select State from BookState c where c.StateID=b.StateID) from Book b 
	where StateID=@stateid and BookName like '%'+@name+'%'
go

--添加租书纪录
if exists(select * from sysobjects where name='proc_AddBookDeal')
drop proc proc_AddBookDeal
go
create proc proc_AddBookDeal
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

--通过图书名称查询图书ID
if exists(select * from sysobjects where name='proc_GetBookIDByName')
drop proc proc_GetBookIDByName
go
create proc proc_GetBookIDByName
@name varchar(50)
as
	select BookID from Book where BookName=@name
go

--通过图书名称判断价格类型
if exists(select * from sysobjects where name='proc_GetPriceTypeByPrice')
drop proc proc_GetPriceTypeByPrice
go 
create proc proc_GetPriceTypeByPrice
@name varchar(50)
as
	declare @price money 
	select @price=price from book where bookname=@name
	select BookPriceID from BookPrice where @price between BookUpPrice and BookDownPrice
go

--通过书名查询图书价格
if exists(select * from sysobjects where name='proc_GetBookPriceByName')
drop proc proc_GetBookPriceByName
go
create proc proc_GetBookPriceByName
@name varchar(50)
as
	select price from book where bookname=@name
go

--查询已出租的图书相关信息
if exists(select *from sysobjects where name='proc_GetBookedMess')
drop proc proc_GetBookedMess
go
create proc proc_GetBookedMess
as
	select BookName,YaJin,ZuJin,Price,DealDate from Book a
	inner join BookDeal b
	on a.BookID=b.BookID
	where b.DealFlag='借出'
go

--通过图书名称查询已出租的图书相关信息
if exists(select *from sysobjects where name='proc_GetBookedMessByName')
drop proc proc_GetBookedMessByName
go
create proc proc_GetBookedMessByName
@name varchar(50)
as
	select BookName,YaJin,ZuJin,Price,DealDate from Book a
	inner join BookDeal b
	on a.BookID=b.BookID
	where b.DealFlag='借出' and BookName like '%'+@name+'%'
go

--修改图书状态
if exists(select * from sysobjects where name='proc_UpdateBooksState')
drop proc proc_UpdateBooksState
go
create proc proc_UpdateBooksState
@BookName varchar(50)
as
	declare @ZuJin money,@BookID int,@UserID int
	select @BookID=BookID from Book where BookName=@BookName
	select @ZuJin=ZuJin from BookDeal where BookID=@BookID
	select @UserID=UserID from BookDeal where BookID=@BookID and DealFlag='借出'
	update Book set StateID = (select StateID from BookState where State = '正常')
	where BookID = @BookID
	update UserTable set UserMoney = UserMoney - @ZuJin
	where UserID = @UserID
	update BookDeal set DealFlag = '已还' where BookID = @BookID
go

--通过图书ID获取租金
if exists(select * from sysobjects where name='proc_GetZuJin')
drop proc proc_GetZuJin
go
create proc proc_GetZuJin
@id int
as
	select ZuJin from BookDeal where BookID=@id and DealFlag='借出'
go

--通过图书ID获取附加费用
if exists(select * from sysobjects where name='proc_GetLendPrice')
drop proc proc_GetLendPrice
go
create proc proc_GetLendPrice
@id int
as
	select BookLendPrice from BookDeal where BookID=@id and DealFlag='借出'
go

--判断会员卡类型是否存在
if exists(select * from sysobjects where name='proc_JudgeCardType')
drop proc proc_JudgeCardType
go
create proc proc_JudgeCardType
@name varchar(50)
as
	select count(*) from CardType where CardName=@name
go

--添加新会员类型
if exists(select * from sysobjects where name='proc_AddCarDType')
drop proc proc_AddCarDType
go
create proc proc_AddCarDType
@name varchar(20),@agio numeric(2,1)
as
	insert CardType(CardName,CardAgio) values(@name,@agio)
go

--修改会员类型
if exists(select * from sysobjects where name='proc_UpdateCarDType')
drop proc proc_UpdateCarDType
go
create proc proc_UpdateCarDType
@name varchar(20),@agio numeric(2,1),@id int
as
	update CardType set CardName=@name,CardAgio=@agio where CardTypeID=@id
go

--获取图书价格信息
if exists(select * from sysobjects where name='proc_GetBookPrice')
drop proc proc_GetBookPrice
go
create proc proc_GetBookPrice
as
	select BookPriceID,BookUpPrice,BookDownPrice,BookPrice,BackDate from bookprice
go

--修改图书价格信息
if exists(select * from sysobjects where name='proc_UpdateBookPrice')
drop proc proc_UpdateBookPrice
go
create proc proc_UpdateBookPrice
@BookPriceID int,@UpPrice money,@DownPrice money,@Price money,@BackDate int
as
	update BookPrice set BookUpPrice=@UpPrice,BookDownPrice=@DownPrice,
	BookPrice=@Price,BackDate=@BackDate
	where BookPriceID=@BookPriceID
go

--获取员工信息
if exists(select * from sysobjects where name='proc_GetAllUsers')
drop proc proc_GetAllUsers
go
create proc proc_GetAllUsers
as
	select UserID,UserUID,UserPWD,UserName,RolesName =(select RolesName from Roles b where b.RolesID=a.RoleID),UserSex
	from Users a
go

--修改员工信息
if exists(select * from sysobjects where name='proc_UpdateUsers')
drop proc proc_UpdateUsers
go
create proc proc_UpdateUsers
@uid varchar(20),@pwd int,@name varchar(20),@rid int,@sex char(2),@id int
as
	update Users set UserUID=@uid,UserPWD=@pwd,UserName=@name,RoleID=@rid,UserSex=@sex
	where UserID=@id
go

--获取角色信息
if exists(select * from sysobjects where name='GetRolesMess')
drop proc GetRolesMess
go
create proc GetRolesMess
as
	select RolesID,RolesName from Roles
go

--添加员工信息
if exists(select * from sysobjects where name='proc_AddUsersMess')
drop proc proc_AddUsersMess
go
create proc proc_AddUsersMess
@uid varchar(20),@pwd varchar(20),@name varchar(20),@rid int,@sex char(2)
as
	insert into Users(UserUID,UserPWD,UserName,RoleID,UserSex)
	values(@uid,@pwd,@name,@rid,@sex)
go

--删除员工信息
if exists(select * from sysobjects where name='proc_DeleteUsersMess')
drop proc proc_DeleteUsersMess
go
create proc proc_DeleteUsersMess
@id int
as
	delete from Users where UserID=@id
go

--检测员工账号是否存在
if exists(select * from sysobjects where name='proc_JudgeUser')
drop proc proc_JudgeUser
go
create proc proc_JudgeUser
@id varchar(20)
as
	select count(*) from Users where UserUID=@id
go

--检测员工账户的账号和密码
if exists(select * from sysobjects where name='proc_JudgeUserLogin')
drop proc proc_JudgeUserLogin
go
create proc proc_JudgeUserLogin
@uid varchar(20),@pwd varchar(20),@rid int
as
	select count(*) from Users where UserUID=@uid and UserPWD=@pwd and RoleID=@rid
go

--通过员工账号查询员工姓名
if exists(select * from sysobjects where name='proc_GetUserNameByUID')
drop proc proc_GetUserNameByUID
go
create proc proc_GetUserNameByUID
@uid varchar(20)
as
	select UserName from Users where UserUID=@uid
go

--修改员工密码
if exists(select * from sysobjects where name='proc_UpdateUserPWD')
drop proc proc_UpdateUserPWD
go
create proc proc_UpdateUserPWD
@pwd varchar(20),@id varchar(20)
as
	update Users set UserPWD=@pwd where UserUID=@id
go

--获取权限ID
if exists(select * from Sysobjects where name='proc_GetFunctionID')
drop proc proc_GetFunctionID
go
create proc proc_GetFunctionID
@UserUID varchar(20)
as
select FunctionID from RoleFuntion where RoleID =(select RoleID from dbo.Users where UserUID=@UserUID)
go
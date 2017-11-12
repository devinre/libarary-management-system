# libarary-management-system
1. 一、 **实验目的和要求**

1. 掌握数据库应用开发程序设计方法。

1. 二、 **实验内容和原理**

2.1实验内容

1. 设计简单的图书管理数据库概念模式。

2. 设计相应的关系模式。

3. 基于ODBS或JDBC 实现一个图书管理程序，实现图书、借书证及图书借阅的管理的基本功能。

2.2实验原理

###### **（1）基本数据对象**

| 对象名称 | 包含属性 |
| --- | --- |
| 书 | 书号, 类别, 书名, 出版社, 年份, 作者, 价格, 总藏书量, 库存 |
| 借书证 | 卡号, 姓名, 单位, 类别 (教师 学生等) |
| 借书记录 | 卡号, 借书证号 ,借期, 还期 |

###### **（2）基本功能模块**

| 模块名称 | 功能描述 |
| --- | --- |
| 图书入库 |
1. 单本入库
2. 批量入库 (方便最后测试)
图书信息存放在文件中, 每条图书信息为一行. 一行中的内容如下( 书号, 类别, 书名, 出版社, 年份, 作者, 价格, 数量 ) Note: 其中 年份、数量是整数类型； 价格是两位小数类型； 其余为字符串类型Sample：(  book\_no\_1, Computer Science, Computer Architecture, xxx, 2004, xxx, 90.00, 2 ) |
| 图书查询 | 要求可以对书的 类别, 书名, 出版社, 年份(年份区间), 作者, 价格(区间) 进行查询. 每条图书信息包括以下内容:( 书号, 类别, 书名, 出版社, 年份, 作者, 价格, 总藏书量, 库存 ) |
| 借书 | 1.输入借书证卡号显示该借书证所有已借书籍 (返回, 格式同查询模块)2.输入书号        如果该书还有库存，则借书成功，同时库存数减一。        否则输出该书无库存，且输出最近归还的时间。 |
| 还书 | 1.输入借书证卡号 显示该借书证所有已借书籍 (返回, 格式同查询模块)2.输入书号        如果该书在已借书籍列表内, 则还书成功, 同时库存加一.        否则输出出错信息. |
| 借书证管理 | 增加或删除一个借书证. |

###### **（3）用户界面**

                QT 5.8.0。

2.3数据库设计

###### **（1）实体之间的关系E-R图**



###### **（2）数据库逻辑结构设计**

   create  table book

   (bno char(10),

   category         varchar(10),

   title         varchar(20),

   press        varchar(20),

   year int,

   author varchar(10),

   price        decimal(7,2),

   total        int,

   stock        int,

   primary key(bno));

  create table card

  (cno char(7),

  name varchar(10),

  department varchar(40),

  type char(1),

  primary key(cno),

  check(type in(&#39;T&#39;,&#39;S&#39;)));

  create table borrow

  (cno char(7),

  bno  char(10),

  borrow\_date date,

  return\_date date,

  primary key(cno,bno),

  foreign key (cno) references card(cno),

             foreign key (bno) references book(bno));

1. 三、 **实验平台**

1. 数据库管理系统：SQL Server
2. 开发平台： Windows 10
3. 开发工具： Visual Studio 2015 /Qt Creater
4. 开发语言： C++
5. 数据库操控技术：ODBC

**四、运行环境配置**

4.1数据库建立

使用账户：sa密码：123456登录SQL Server服务器，建立名为library的数据库，并在其中建立book、borrow、card三个表，属性名及等信息如上文所述。

4.2配置ODBC数据源：

打开 控制面板\系统和安全\管理工具\ODBC数据源管理器

添加（D）…

起一个DSN名字，本实验使用的名字为exfive；配置SQLSERVER服务器名，我使用的为DESKTOP-QMU12OU，为一个本地服务器。

设置登录ID和密码。本实验使用的ID为sa，密码为123456。



测试一下，看是否能够连上。

4.3编译环境配置

本实验使用的vs2015+Qt 5.8.0进行图形界面编程，需将Qt嵌入到vs中，并配置好系统Qt环境变量。

**五、系统各模块详细设计**

本实验使用Qt 设计师进行图形界面ui设计，共设计9个模块

5.1 登录模块

5.1.1登录界面 login.ui

5.1.2 登录模块login.h

| class login : public QDialog{        Q\_OBJECTpublic:        login(QWidget \*parent = Q\_NULLPTR);        ~login();private:        Ui::login \*ui;        private slots:        void on\_pushButton\_clicked();}; |
| --- |
| login(QWidget \*parent = Q\_NULLPTR); | 初始化登录界面 |
| ~login(); | 释放内存 |
| void on\_pushButton\_clicked(); | 点击登录按钮，与内置帐号密码确认是否相符合，符合显示下一个界面 |

1.
  1. 2功能选择模块

5.2.1 功能选择界面 librarymanagement.ui

5.2.2 功能选择模块librarymanagement.h

| class librarymanagement : public QWidget{        Q\_OBJECTpublic:        librarymanagement(QWidget \*parent = Q\_NULLPTR);        ~librarymanagement();private:        Ui::librarymanagementClass \*librarymanagement\_ui;        addbook addbook\_ui;        searchbook searchbook\_ui;        borrowbook borrowbook\_ui;        card card\_ui;        QSqlDatabase db;        private slots:        void on\_pushButton\_clicked();        void on\_pushButton\_2\_clicked();        void on\_pushButton\_3\_clicked();        void on\_pushButton\_5\_clicked();}; |
| --- |
| librarymanagement(QWidget \*parent = Q\_NULLPTR); | 功能选择界面，并连接数据库 |
| void on\_pushButton\_clicked(); | 点击图书入库，显示添加图书界面 |
| void on\_pushButton\_2\_clicked(); | 点击图书查询，显示图书搜索界面 |
| void on\_pushButton\_3\_clicked(); | 点击&quot;借/还书&quot;，显示图书借还界面 |
| void on\_pushButton\_5\_clicked(); | 点击借书证管理，显示借书证界面 |

1.
  1. 3库存管理模块

5.3.1 库存显示界面 addbook.ui

5.3.2 库存显示addbook.h

| class addbook : public QWidget{        Q\_OBJECT public:        addbook(QWidget \*parent = Q\_NULLPTR);        ~addbook(); private:        Ui::addbook \*addbook\_ui;        int max\_page;        int current\_page;        //QSqlDatabase db;        void updatewindow();        QVector&lt;QString&gt;result;        singleadd singleadd\_ui;        multyadd multyadd\_ui;        private slots:        void on\_pushButton\_5\_clicked();        void on\_pushButton\_clicked();        void on\_pushButton\_2\_clicked();        void on\_pushButton\_3\_clicked();        void on\_pushButton\_4\_clicked();}; |
| --- |
| void on\_pushButton\_5\_clicked(); | 点击&quot;显示库存&quot;，显示当前数据库存有的图书 |
| void on\_pushButton\_clicked(); | 点击&quot;上一页&quot;，进行翻页操作 |
| void on\_pushButton\_2\_clicked(); | 点击&quot;下一页&quot;，进行翻页操作 |
| void on\_pushButton\_3\_clicked(); | 点击&quot;单本入库&quot;，进入单本图书数据录入界面 |
| void on\_pushButton\_4\_clicked(); | 点击&quot;多册入库&quot;，进入批量入库界面 |

1.
  1. 4单册图书添加模块

5.4.1 单册书籍添加界面singleadd.ui

5.4.2 单册书籍singleadd.h

| class singleadd : public QWidget{        Q\_OBJECT public:        singleadd(QWidget \*parent = Q\_NULLPTR);        ~singleadd(); private:        Ui::singleadd \*singleadd\_ui;        QString bookMessage[8];        int addbook();        private slots:        void on\_pushButton\_clicked();}; |
| --- |
| void on\_pushButton\_clicked(); | 点击显示&quot;OK&quot;，确认将文本框的内容输入到数据库 |
| int addbook(); | 添加图书的Sql语句函数，对数据库进行添加、更新操作 |

1.
  1. 5多册书籍添加模块

5.5.1 多册书籍添加界面multyadd.ui

5.5.2 多册书籍添加multyadd.h

| class multyadd : public QWidget{        Q\_OBJECT public:        multyadd(QWidget \*parent = Q\_NULLPTR);        ~multyadd(); private:        Ui::multyadd \*multyadd\_ui;        QString bookMessage[8];        QVector&lt;QString \*&gt;multiBookMessage;        int addbook();        private slots:        void on\_pushButton\_clicked();        void on\_pushButton\_2\_clicked();        void on\_pushButton\_3\_clicked();}; |
| --- |
| multyadd(QWidget \*parent = Q\_NULLPTR); | 初始化窗口界面与表格 |
| void on\_pushButton\_clicked(); | 点击&quot;加载文件&quot;，打开文件加载窗口界面，选择相应的txt文件进行导入 |
| void on\_pushButton\_2\_clicked(); | 点击&quot;添加进书库&quot;，将当前表格显示内容添加进数据库 |
| void on\_pushButton\_3\_clicked(); | 点击&quot;清空列表&quot;，会清空当前表格内容 |
| int addbook(); | 同上一个模块的addbook，对数据库进行sql语句操作 |

1.
  1. 6借还书模块

5.6.1借还书界面borrowbook.ui

5.6.2借还书头文件borrowbook.h

| class borrowbook : public QWidget{        Q\_OBJECT public:        borrowbook(QWidget \*parent = Q\_NULLPTR);        ~borrowbook();  private:        Ui::borrowbook \*ui;        void loadborrowmessage();        QVector&lt;QString\*&gt; borrowmessage;        private slots:        void on\_pushButton\_clicked();        void on\_pushButton\_2\_clicked();        void on\_pushButton\_3\_clicked();}; |
| --- |
| void on\_pushButton\_clicked(); | 点击&quot;已借图书&quot;，依据卡号文本框从数据库查询该卡号对应图书信息 |
| void on\_pushButton\_2\_clicked(); | 点击&quot;借书&quot;，根据卡号和书号借取该书 |
| void on\_pushButton\_3\_clicked(); | 点击&quot;还书&quot;，会根据卡号和书号还取该书 |
| void loadborrowmessage(); | 加载借阅信息函数 |

1.
  1. 7借书证管理模块

5.7.1 借书证管理界面card.ui

5.7.2 借书证管理card.h

| class card : public QWidget{        Q\_OBJECT public:        card(QWidget \*parent = Q\_NULLPTR);        ~card(); private:        Ui::card \*ui;        int max\_page;        int current\_page;        addcard addcard\_ui;        QVector&lt;QString&gt;result;        void updatewindow();        private slots:        void on\_pushButton\_3\_clicked();        void on\_pushButton\_clicked();        void on\_pushButton\_2\_clicked();        void on\_pushButton\_5\_clicked();        void on\_pushButton\_4\_clicked();}; |
| --- |
| void on\_pushButton\_3\_clicked(); | 点击&quot;添加/修改&quot;，打开借书证录入界面进行输入 |
| void on\_pushButton\_clicked(); | 点击&quot;上一页&quot;，翻到上一页 |
| void on\_pushButton\_2\_clicked(); | 点击&quot;下一页&quot;，翻到下一页 |
| void updatewindow(); | 更新窗口显示信息，调用sql语句查询数据库内容 |
| void on\_pushButton\_5\_clicked(); | 点击&quot;显示&quot;，显示当前数据库内所有借书证相关内容 |
| void on\_pushButton\_4\_clicked(); | 点击&quot;删除&quot;，删除指定借书证，根据输入的卡号 |

1.
  1. 8添加借书证模块

5.8.1 添加借书证界面addcard.ui

5.8.2 添加借书证addcard.h

| class addcard : public QWidget{        Q\_OBJECT public:        addcard(QWidget \*parent = Q\_NULLPTR);        ~addcard(); private:        Ui::addcard \*ui;        QString cardmessage[4];        int addcar();        private slots:        void on\_pushButton\_clicked();}; |
| --- |
| void on\_pushButton\_clicked(); | 点击&quot;确认&quot;将会将表单中的内容提交给addcar（）函数执行添加操作 |
| int addcar(); | Sql语句设计逻辑添加借书证信息 |

1.
  1. 9图书搜索模块

5.9.1图书搜索界面searchbook.ui

5.9.2 图书搜索 searchbook.h

| class searchbook : public QWidget{        Q\_OBJECT public:        searchbook(QWidget \*parent = Q\_NULLPTR);        ~searchbook(); private:        Ui::searchbook \*ui;        int max\_page;        int current\_page;        void updatewindow();        QVector&lt;QString&gt;result;        private slots:        void on\_pushButton\_clicked();        void on\_pushButton\_3\_clicked();        void on\_pushButton\_4\_clicked();        void on\_pushButton\_2\_clicked();}; |
| --- |
| void on\_pushButton\_clicked(); | 点击&quot;搜索&quot;，将进行Sql语句查询操作 |
| void updatewindow(); | 用于更新窗口显示信息，将搜索结果打印在表格中 |
| void on\_pushButton\_3\_clicked(); | 点击&quot;上一页&quot;翻至上一页表格显示 |
| void on\_pushButton\_4\_clicked(); | 点击&quot;下一页&quot;翻至下一页表格显示 |
| void on\_pushButton\_2\_clicked(); | 点击&quot;清空&quot;，清楚表单输入内容 |

1.
  1. 六、 **操作方法与实验步骤及结果**

6.1登录界面

在用户名中输入sa，密码中输入123456，点击登录按钮进入图书管理系统

6.2功能选择界面

在程序标题下方会根据系统当前时间显示日期，左侧是日历，右侧共有四个功能入口按钮供用户选择。

6.3图书入库和修改

设计目标：输入bno, category, title, press, year, author, price, total, stock。根据书号，如果书号在book中已经存在，则修改信息（比如已有书号为12312344的书，然后修改价格）或添加总量及库存，若book中没有相同的书号，则添加新书。入库或修改前后数据库表的对比。

批量入库功能：

输入导入文件的地址，导入前后数据库表的对比。

设计演示：

我们点击&quot;显示库存&quot;，可以看到当前书库已经存入一些图书。

点击上一页、下一页可以进行翻页

点击&quot;单本入库&quot;，如图示例输入想要添加的一本书的信息，再从&quot;显示库存&quot;中可以看到这本书已经被添加



如果输入相同的书，可以由用户选择是否对该书进行更新操作，如我们对刚刚那本书进行修改更新



6.4批量入库功能

目标：输入导入文件的地址，导入前后数据库表的对比。

实现演示：

点击&quot;多册入库&quot;，进行批量导入，这里我们选择已经准备好的一个txt用于测试。

文本信息会在表格中显示，用户可以核对信息是否正确，并可以直接在表格中点击修改，确认无误后点击&quot;添加进书库&quot;便可实现添加

如果遇到书号相同，会询问是否更新该书籍

从显示库存中可以看到已经加入这些图书



6.5借书证管理

目标：根据借书证号cno，可添加可修改可删除。

演示：

点击&quot;显示&quot;，可以看出当前已添加的借书证

点击&quot;添加/修改&quot;进行借书证的添加修改，如图

点击&quot;显示&quot;可以看到已经添加进去，如果输入卡号与已经存在的相同，会更新该卡号信息。

正在删除卡号中输入5，可以删除该借书证

如果删除的借书证有书本未还，会无法删除

6.6借还书

目标：

借书记录查询：

输入cno，查询已借书籍，输入错误的cno时打印错误信息。

借书：

输入cno和bno，借出书籍成功（增加一条借书记录，库存减一），若库存为空则借出失败。

还书：

输入cno和bno，归还书籍成功（减少一条借书记录，库存加一），输入错误的cno或bno时打印记录出错信息。

演示：

输入卡号1可以看到借了书号为1的书籍

我们想借这本书

输入卡号1.与书号01111，借期会从系统时间获取，还期会从借期90天后算起



同时可以发现01111这本书库存减1

如果想借的书没有库存，会进行提示，并给出该书最近的归还日期

输入卡号1，书号1，点击&quot;还书&quot;可以还书，同时库存+1



6.7图书查询

除了year和price是区间查询，其他都是相等查询（比如作者查询）。

比如我们在类别中输入&quot;悬疑&quot;点击&quot;搜索&quot;

若未输入任何条件，会进行提示

价格、年份为区间查询，如：

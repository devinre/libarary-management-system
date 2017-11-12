-- MySQL Administrator dump 1.4
--
-- ------------------------------------------------------
-- Server version	5.0.18


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


--
-- Create schema libbook
--

CREATE DATABASE IF NOT EXISTS libbook;
USE libbook;

--
-- Definition of table `tbl_book`
--

DROP TABLE IF EXISTS `tbl_book`;
CREATE TABLE `tbl_book` (
  `id` int(10) unsigned zerofill NOT NULL auto_increment,
  `name` varchar(45) NOT NULL,
  `author` varchar(45) default NULL,
  `type` varchar(45) NOT NULL,
  `press` varchar(45) default NULL,
  `pressdate` date default NULL,
  `pagenum` int(10) unsigned default NULL,
  `price` double default NULL,
  `adddate` date NOT NULL,
  `lendtimes` int(10) unsigned NOT NULL,
  `status` int(10) unsigned NOT NULL,
  `bookID` varchar(20) NOT NULL,
  PRIMARY KEY  USING BTREE (`id`,`bookID`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

--
-- Dumping data for table `tbl_book`
--

/*!40000 ALTER TABLE `tbl_book` DISABLE KEYS */;
INSERT INTO `tbl_book` (`id`,`name`,`author`,`type`,`press`,`pressdate`,`pagenum`,`price`,`adddate`,`lendtimes`,`status`,`bookID`) VALUES 
 (0000000013,'数学','无','理科','中国人名教育出版社','2008-01-24',123,44,'2010-05-03',7,1,'123456'),
 (0000000014,'危机原理与汇编语言','方立友','信息科学','清华大学出版社','2000-01-01',222,33,'2010-05-03',0,0,'2123131'),
 (0000000015,'用TCP/IP进行网际互联','Douglas E Comer','信息科学','电子工业出版社','2000-01-01',321,44,'2010-05-03',1,1,'123423'),
 (0000000016,'J2ME程序设计实例教程','杨光','信息','清华大学出版社','2000-01-01',333,67,'2010-05-03',1,1,'432456'),
 (0000000017,'面向对象分析与设计','马志毅','面向对象','机械工业出版社','2000-01-01',233,23,'2010-05-03',0,0,'532312'),
 (0000000018,'软件测试方法与技术','朱少明','软件工程','清华大学出版社','2000-01-01',223,34,'2010-05-03',1,1,'232342'),
 (0000000019,'软件测试','朱少明','软件工程','清华大学出版社','2007-01-17',142,44,'2010-05-03',0,0,'235523');
/*!40000 ALTER TABLE `tbl_book` ENABLE KEYS */;


--
-- Definition of table `tbl_booklog`
--

DROP TABLE IF EXISTS `tbl_booklog`;
CREATE TABLE `tbl_booklog` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `result` int(10) unsigned NOT NULL,
  `bookID` varchar(20) NOT NULL,
  `bookname` varchar(45) NOT NULL,
  `operation` int(10) unsigned NOT NULL,
  `ip` varchar(20) NOT NULL,
  `type` varchar(45) default NULL,
  `description` varchar(45) default NULL,
  `datetime` datetime NOT NULL,
  `operator` varchar(20) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

--
-- Dumping data for table `tbl_booklog`
--

/*!40000 ALTER TABLE `tbl_booklog` DISABLE KEYS */;
INSERT INTO `tbl_booklog` (`id`,`result`,`bookID`,`bookname`,`operation`,`ip`,`type`,`description`,`datetime`,`operator`) VALUES 
 (706,0,'qweqwe222','asdasdasd',202,'127.0.0.1','asdasdasd','Delete book<<asdasdasd>>successfully!','2010-05-03 17:21:12','keqin'),
 (707,0,'asasd','asdasd',309,'127.0.0.1','asdasdad','Lend book<<asdasd>>successfully!','2010-05-03 17:57:37','Anonymous'),
 (708,0,'aaaaaaaaa','aaaaaaaaa',202,'127.0.0.1','aaaaaaaaaaaa','Delete book<<aaaaaaaaa>>successfully!','2010-05-03 17:57:45','Anonymous'),
 (709,0,'123456','啊哈哈',203,'127.0.0.1','yishu','Update book<<啊哈哈>>successfully!','2010-05-03 19:58:09','Anonymous'),
 (710,0,'qwdasd','山东省 ',203,'127.0.0.1','asdasd','Update book<<山东省 >>successfully!','2010-05-03 19:58:22','Anonymous'),
 (711,0,'123456','啊哈哈',202,'127.0.0.1','yishu','Delete book<<啊哈哈>>successfully!','2010-05-03 20:05:55','Anonymous'),
 (712,0,'qwdasd','山东省 ',202,'127.0.0.1','asdasd','Delete book<<山东省 >>successfully!','2010-05-03 20:05:59','Anonymous'),
 (713,0,'111111','111111111111111',202,'127.0.0.1','11111111111111','Delete book<<111111111111111>>successfully!','2010-05-03 20:06:02','Anonymous'),
 (714,0,'qweqwe','qweqwe',202,'127.0.0.1','qweq','Delete book<<qweqwe>>successfully!','2010-05-03 20:06:04','Anonymous'),
 (715,0,'sdfdsf','sdfsd',202,'127.0.0.1','fsdf','Delete book<<sdfsd>>successfully!','2010-05-03 20:06:06','Anonymous'),
 (716,0,'asasd','asdasd',202,'127.0.0.1','asdasdad','Delete book<<asdasd>>successfully!','2010-05-03 20:06:09','Anonymous'),
 (717,0,'123456','数学',201,'127.0.0.1','理科','Add book<<数学>>successfully!','2010-05-03 20:07:35','Anonymous'),
 (718,0,'2123131','危机原理与汇编语言',201,'127.0.0.1','信息科学','Add book<<危机原理与汇编语言>>successfully!','2010-05-03 20:15:29','Anonymous'),
 (719,0,'123423','用TCP/IP进行网际互联',201,'127.0.0.1','信息科学','Add book<<用TCP/IP进行网际互联>>successfully!','2010-05-03 20:17:26','Anonymous'),
 (720,0,'432456','J2ME程序设计实例教程',201,'127.0.0.1','信息','Add book<<J2ME程序设计实例教程>>successfully!','2010-05-03 20:19:18','Anonymous'),
 (721,0,'532312','面向对象分析与设计',201,'127.0.0.1','面向对象','Add book<<面向对象分析与设计>>successfully!','2010-05-03 20:20:35','Anonymous'),
 (722,0,'232342','软件测试方法与技术',201,'127.0.0.1','软件工程','Add book<<软件测试方法与技术>>successfully!','2010-05-03 20:21:32','Anonymous'),
 (723,0,'235523','软件测试',201,'127.0.0.1','软件工程','Add book<<软件测试>>successfully!','2010-05-03 20:24:39','Anonymous'),
 (724,0,'123456','数学',309,'127.0.0.1','理科','Lend book<<数学>>successfully!','2010-05-03 20:26:11','Anonymous'),
 (725,0,'123456','数学',203,'127.0.0.1','理科','Update book<<数学>>successfully!','2010-05-03 20:26:51','Anonymous'),
 (726,0,'123456','数学',203,'127.0.0.1','理科','Update book<<数学>>successfully!','2010-05-03 20:27:13','Anonymous'),
 (727,0,'asasd','asdasd',307,'127.0.0.1','asdasdad','Delete lend<<asdasd>>successfully!','2010-05-03 20:50:47','江涛'),
 (728,0,'123456','数学',302,'127.0.0.1','理科','Renewal<<数学>>successfully!','2010-05-03 20:50:57','江涛'),
 (729,0,'123423','用TCP/IP进行网际互联',309,'127.0.0.1','信息科学','Lend book<<用TCP/IP进行网际互联>>successfully!','2010-05-03 21:09:26','Anonymous'),
 (730,0,'232342','软件测试方法与技术',309,'127.0.0.1','软件工程','Lend book<<软件测试方法与技术>>successfully!','2010-05-03 21:09:36','Anonymous'),
 (731,0,'432456','J2ME程序设计实例教程',309,'127.0.0.1','信息','Lend book<<J2ME程序设计实例教程>>successfully!','2010-05-03 21:09:49','Anonymous');
/*!40000 ALTER TABLE `tbl_booklog` ENABLE KEYS */;


--
-- Definition of table `tbl_lend`
--

DROP TABLE IF EXISTS `tbl_lend`;
CREATE TABLE `tbl_lend` (
  `id` int(10) unsigned zerofill NOT NULL auto_increment,
  `name` varchar(45) NOT NULL,
  `author` varchar(20) NOT NULL,
  `type` varchar(45) NOT NULL,
  `press` varchar(45) default NULL,
  `pressdate` datetime default NULL,
  `pagenum` int(10) unsigned default NULL,
  `price` float unsigned default NULL,
  `lenddate` datetime NOT NULL,
  `lenddays` int(10) unsigned NOT NULL,
  `overdays` int(10) unsigned NOT NULL,
  `reader` varchar(20) NOT NULL,
  `timeout` int(10) unsigned NOT NULL,
  `bookID` varchar(20) NOT NULL,
  `readerID` varchar(20) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

--
-- Dumping data for table `tbl_lend`
--

/*!40000 ALTER TABLE `tbl_lend` DISABLE KEYS */;
INSERT INTO `tbl_lend` (`id`,`name`,`author`,`type`,`press`,`pressdate`,`pagenum`,`price`,`lenddate`,`lenddays`,`overdays`,`reader`,`timeout`,`bookID`,`readerID`) VALUES 
 (0000000013,'数学','无','理科','中国人名教育出版社','2000-01-18 00:00:00',123,44,'2010-05-03 00:00:00',45,0,'江涛',1,'123456','200620201124'),
 (0000000014,'用TCP/IP进行网际互联','Douglas E Comer','信息科学','电子工业出版社','2000-01-01 00:00:00',321,44,'2010-05-03 00:00:00',33,4,'柯琴',1,'123423','12312312'),
 (0000000015,'软件测试方法与技术','朱少明','软件工程','清华大学出版社','2000-01-01 00:00:00',223,34,'2010-05-03 00:00:00',33,0,'柯琴',0,'232342','12312312'),
 (0000000016,'J2ME程序设计实例教程','杨光','信息','清华大学出版社','2000-01-01 00:00:00',333,67,'2010-05-03 00:00:00',33,0,'江涛',0,'432456','1231231');
/*!40000 ALTER TABLE `tbl_lend` ENABLE KEYS */;


--
-- Definition of table `tbl_reader`
--

DROP TABLE IF EXISTS `tbl_reader`;
CREATE TABLE `tbl_reader` (
  `id` int(10) unsigned zerofill NOT NULL auto_increment,
  `name` varchar(20) NOT NULL,
  `sex` int(10) unsigned NOT NULL,
  `birthday` date NOT NULL,
  `carddate` date NOT NULL,
  `cardnum` varchar(20) NOT NULL,
  `type` int(10) unsigned NOT NULL,
  `status` int(10) unsigned NOT NULL,
  `school` varchar(45) default NULL,
  `department` varchar(45) default NULL,
  `grade` int(10) unsigned default NULL,
  `idcard` varchar(20) default NULL,
  `address` varchar(45) default NULL,
  `post` varchar(10) default NULL,
  `phone` varchar(20) default NULL,
  `email` varchar(40) default NULL,
  `readerID` varchar(20) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

--
-- Dumping data for table `tbl_reader`
--

/*!40000 ALTER TABLE `tbl_reader` DISABLE KEYS */;
/*!40000 ALTER TABLE `tbl_reader` ENABLE KEYS */;


--
-- Definition of table `tbl_user`
--

DROP TABLE IF EXISTS `tbl_user`;
CREATE TABLE `tbl_user` (
  `id` int(10) unsigned zerofill NOT NULL auto_increment,
  `name` varchar(20) default NULL,
  `sex` int(10) unsigned default NULL,
  `birthday` date default NULL,
  `idcard` varchar(20) default NULL,
  `phone` varchar(20) default NULL,
  `status` int(10) unsigned default NULL,
  `power` int(10) unsigned default NULL,
  `password` varchar(20) NOT NULL,
  `online` int(10) unsigned default '0',
  `logintime` datetime default NULL,
  `lasttime` datetime default NULL,
  `userID` varchar(20) NOT NULL,
  `email` varchar(45) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

--
-- Dumping data for table `tbl_user`
--

/*!40000 ALTER TABLE `tbl_user` DISABLE KEYS */;
INSERT INTO `tbl_user` (`id`,`name`,`sex`,`birthday`,`idcard`,`phone`,`status`,`power`,`password`,`online`,`logintime`,`lasttime`,`userID`,`email`) VALUES 
 (0000000008,'江涛',0,'1986-09-07','51060319860901972','13688308537',0,0,'1234',0,'2010-05-03 20:30:07','2010-05-05 22:36:44','jiangtao','janxtao@163.com'),
 (0000000009,'柯琴',1,'1991-03-18','51060219860901972','13688308537',0,1,'1234',0,'2010-05-03 20:31:22','2010-05-05 19:06:06','keqin','janxtao@163.com');
/*!40000 ALTER TABLE `tbl_user` ENABLE KEYS */;


--
-- Definition of table `tbl_userlog`
--

DROP TABLE IF EXISTS `tbl_userlog`;
CREATE TABLE `tbl_userlog` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `operator` varchar(20) NOT NULL,
  `ip` varchar(20) NOT NULL,
  `result` int(10) unsigned NOT NULL,
  `description` varchar(45) default NULL,
  `datetime` datetime NOT NULL,
  `operation` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

--
-- Dumping data for table `tbl_userlog`
--

/*!40000 ALTER TABLE `tbl_userlog` DISABLE KEYS */;
INSERT INTO `tbl_userlog` (`id`,`operator`,`ip`,`result`,`description`,`datetime`,`operation`) VALUES 
 (393,'Anonymous','127.0.0.1',0,'User<keqin>logon successfully','2010-05-03 17:20:36',101),
 (394,'keqin','127.0.0.1',0,'Delete all book log successfully!','2010-05-03 17:21:06',502),
 (395,'keqin','127.0.0.1',0,'User<keqin>logOut successfully','2010-05-03 17:21:32',109),
 (396,'keqin','127.0.0.1',0,'User<keqin>logon successfully','2010-05-03 17:21:37',101),
 (397,'keqin','127.0.0.1',0,'Add user<<sdasd>>successfully!','2010-05-03 17:21:47',102),
 (398,'keqin','127.0.0.1',0,'Add user<<sdasdasd>>successfully!','2010-05-03 17:21:58',102),
 (399,'keqin','127.0.0.1',0,'Update user<<sdasdasd>>successfully!','2010-05-03 17:22:10',103),
 (400,'keqin','127.0.0.1',0,'Delete user<<sdasdasd>>successfully!','2010-05-03 17:23:05',103),
 (401,'keqin','127.0.0.1',0,'User<keqin>Exit system','2010-05-03 17:23:28',110),
 (402,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 17:57:19',110),
 (403,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 17:57:55',110),
 (404,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 18:10:56',110),
 (405,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 18:11:58',110),
 (406,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 18:17:30',110),
 (407,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 18:20:42',110),
 (408,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 18:24:06',110),
 (409,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 20:11:35',110),
 (410,'Anonymous','127.0.0.1',0,'Delete user<<sdasd>>successfully!','2010-05-03 20:28:25',103),
 (411,'Anonymous','127.0.0.1',0,'Delete user<<jiangtao>>successfully!','2010-05-03 20:28:35',103),
 (412,'Anonymous','127.0.0.1',0,'Delete user<<keqin>>successfully!','2010-05-03 20:28:38',103),
 (413,'Anonymous','127.0.0.1',0,'Add user<<jiangtao>>successfully!','2010-05-03 20:30:07',102),
 (414,'Anonymous','127.0.0.1',0,'Add user<<keqin>>successfully!','2010-05-03 20:31:22',102),
 (415,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 20:33:10',110),
 (416,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 20:37:32',110),
 (417,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 20:41:09',110),
 (418,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-03 20:49:30',101),
 (419,'江涛','127.0.0.1',0,'User<jiangtao>Exit system','2010-05-03 20:52:19',110),
 (420,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 21:07:00',110),
 (421,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 21:11:47',110),
 (422,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 21:33:42',110),
 (423,'Anonymous','127.0.0.1',0,'Exit system','2010-05-03 21:55:21',110),
 (424,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-03 21:58:52',101),
 (425,'江涛','127.0.0.1',0,'User<jiangtao>logOut successfully','2010-05-03 21:59:31',109),
 (426,'江涛','127.0.0.1',0,'Exit system','2010-05-03 22:00:10',110),
 (427,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-03 22:04:05',101),
 (428,'江涛','127.0.0.1',0,'User<jiangtao>logOut successfully','2010-05-03 22:04:54',109),
 (429,'江涛','127.0.0.1',0,'Exit system','2010-05-03 22:05:02',110),
 (430,'','127.0.0.1',1,'UserID,password or power is wrong!','2010-05-03 22:06:29',101),
 (431,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-03 22:06:33',101),
 (432,'江涛','127.0.0.1',0,'User<jiangtao>logOut successfully','2010-05-03 22:07:11',109),
 (433,'江涛','127.0.0.1',0,'Exit system','2010-05-03 22:08:13',110),
 (434,'','127.0.0.1',1,'UserID,password or power is wrong!','2010-05-03 22:09:38',101),
 (435,'','127.0.0.1',1,'UserID,password or power is wrong!','2010-05-03 22:09:44',101),
 (436,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-03 22:09:49',101),
 (437,'江涛','127.0.0.1',0,'User<jiangtao>Exit system','2010-05-03 22:10:12',110),
 (438,'Anonymous','127.0.0.1',0,'Exit system','2010-05-04 00:07:40',110),
 (439,'Anonymous','127.0.0.1',0,'Exit system','2010-05-04 00:09:37',110),
 (440,'Anonymous','127.0.0.1',0,'Exit system','2010-05-04 00:10:24',110),
 (441,'Anonymous','127.0.0.1',0,'Exit system','2010-05-04 00:11:26',110),
 (442,'Anonymous','127.0.0.1',0,'Exit system','2010-05-04 00:11:55',110),
 (443,'Anonymous','127.0.0.1',0,'Exit system','2010-05-04 00:12:19',110),
 (444,'Anonymous','127.0.0.1',0,'Exit system','2010-05-04 00:13:07',110),
 (445,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-04 00:13:47',101),
 (446,'江涛','127.0.0.1',0,'User<jiangtao>logOut successfully','2010-05-04 00:15:41',109),
 (447,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-04 00:15:50',101),
 (448,'江涛','127.0.0.1',0,'User<jiangtao>Exit system','2010-05-04 00:18:14',110),
 (449,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-04 20:39:17',101),
 (450,'江涛','127.0.0.1',0,'User<jiangtao>Exit system','2010-05-04 20:41:17',110),
 (451,'Anonymous','127.0.0.1',0,'Exit system','2010-05-05 18:52:21',110),
 (452,'','127.0.0.1',1,'UserID,password or power is wrong!','2010-05-05 18:59:31',101),
 (453,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-05 18:59:37',101),
 (454,'江涛','127.0.0.1',0,'Update user<<jiangtao>>successfully!','2010-05-05 19:00:03',103),
 (455,'江涛','127.0.0.1',0,'Update user<<keqin>>successfully!','2010-05-05 19:00:29',103),
 (456,'江涛','127.0.0.1',0,'User<jiangtao>Exit system','2010-05-05 19:01:05',110),
 (457,'','127.0.0.1',1,'User<jiangtao>non-use!','2010-05-05 19:05:35',101),
 (458,'','127.0.0.1',1,'UserID,password or power is wrong!','2010-05-05 19:05:56',101),
 (459,'','127.0.0.1',1,'UserID,password or power is wrong!','2010-05-05 19:06:00',101),
 (460,'柯琴','127.0.0.1',0,'User<keqin>logon successfully','2010-05-05 19:06:06',101),
 (461,'柯琴','127.0.0.1',0,'Update user<<jiangtao>>successfully!','2010-05-05 19:06:27',103),
 (462,'柯琴','127.0.0.1',0,'Update user<<keqin>>successfully!','2010-05-05 19:06:33',103),
 (463,'柯琴','127.0.0.1',0,'Update user<<jiangtao>>successfully!','2010-05-05 19:06:45',103),
 (464,'柯琴','127.0.0.1',0,'Update user<<jiangtao>>successfully!','2010-05-05 19:07:01',103),
 (465,'柯琴','127.0.0.1',0,'Update user<<jiangtao>>successfully!','2010-05-05 19:07:32',103),
 (466,'柯琴','127.0.0.1',0,'Update user<<keqin>>successfully!','2010-05-05 19:07:40',103),
 (467,'柯琴','127.0.0.1',0,'Update user<<jiangtao>>successfully!','2010-05-05 19:07:45',103),
 (468,'柯琴','127.0.0.1',0,'User<keqin>Exit system','2010-05-05 19:09:17',110),
 (469,'Anonymous','127.0.0.1',0,'Exit system','2010-05-05 19:14:32',110),
 (470,'Anonymous','127.0.0.1',0,'Exit system','2010-05-05 19:43:27',110),
 (471,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-05 19:43:54',101),
 (472,'江涛','127.0.0.1',0,'User<jiangtao>Exit system','2010-05-05 19:45:06',110),
 (473,'','127.0.0.1',1,'UserID,password or power is wrong!','2010-05-05 19:48:09',101),
 (474,'江涛','127.0.0.1',0,'User<jiangtao>logon successfully','2010-05-05 19:48:13',101),
 (475,'江涛','127.0.0.1',0,'User<jiangtao>Exit system','2010-05-05 19:48:45',110),
 (476,'匿名用户','127.0.0.1',0,'退出系统！','2010-05-05 21:08:47',110),
 (477,'匿名用户','127.0.0.1',0,'退出系统！','2010-05-05 21:18:37',110),
 (478,'江涛','127.0.0.1',0,'用户<jiangtao>登录系统成功！','2010-05-05 21:20:22',101),
 (479,'江涛','127.0.0.1',0,'更新用户《jiangtao》成功！','2010-05-05 21:21:21',103),
 (480,'江涛','127.0.0.1',0,'更新用户《jiangtao》成功！','2010-05-05 21:21:34',103),
 (481,'江涛','127.0.0.1',0,'用户<jiangtao>退出系统！','2010-05-05 21:21:55',110),
 (482,'江涛','127.0.0.1',0,'用户<jiangtao>登录系统成功！','2010-05-05 21:22:15',101),
 (483,'江涛','127.0.0.1',0,'用户<jiangtao>退出系统！','2010-05-05 21:22:49',110),
 (484,'江涛','127.0.0.1',0,'用户<jiangtao>登录系统成功！','2010-05-05 21:47:05',101),
 (485,'江涛','127.0.0.1',0,'用户<jiangtao>退出系统！','2010-05-05 21:47:45',110),
 (486,'','127.0.0.1',1,'账号或者密码错误！','2010-05-05 21:49:47',101),
 (487,'江涛','127.0.0.1',0,'用户<jiangtao>登录系统成功！','2010-05-05 21:49:53',101),
 (488,'江涛','127.0.0.1',0,'用户<jiangtao>退出系统！','2010-05-05 22:34:06',110),
 (489,'江涛','127.0.0.1',0,'用户<jiangtao>登录系统成功！','2010-05-05 22:36:44',101),
 (490,'江涛','127.0.0.1',0,'用户<jiangtao>退出系统！','2010-05-05 22:40:55',110),
 (491,'匿名用户','127.0.0.1',0,'退出系统！','2010-05-06 00:09:57',110);
/*!40000 ALTER TABLE `tbl_userlog` ENABLE KEYS */;




/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;

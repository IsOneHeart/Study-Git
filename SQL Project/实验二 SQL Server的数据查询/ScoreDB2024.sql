set nocount    on
set dateformat mdy
go
use master
go


if exists (select * from sysdatabases where name='ScoreDB')
  drop database ScoreDB
go

create database ScoreDB
on 
  ( name='ScoreDB',
    filename='E:\DataBase\ScoreDB2024\DB\ScoreDB.mdf',
    size=5,
    maxsize=10,
    filegrowth= 5)
log on
 ( name='ScoreLog',
   filename='E:\DataBase\ScoreDB2024\LOG\ScoreLog.ldf',
   size=2,
   maxsize=5,
   filegrowth=1)
go

use ScoreDB
go
  
print 'create Course'
go

CREATE TABLE Course (
  courseNo	  char(3) 	        NOT NULL ,  --课程号
  courseName	  varchar(30) unique    NOT NULL,   --课程名
  creditHour      numeric(1)  default 0 NOT NULL,   --学分
  courseHour      tinyint     default 0 NOT NULL,   --课时数
  priorCourse     char(3)		NULL,       --先修课程        
  constraint CoursePK primary key (courseNo),
  FOREIGN KEY (PriorCourse) REFERENCES  Course(courseNo)  
) 
go

insert into Course values('001','大学语文',2,32,null)
insert into Course values('002','体育',    2,32,null)
insert into Course values('003','大学英语',3,48,null)
insert into Course values('004','高等数学',6,96,null)

insert into Course values('005','C语言程序设计',4,80,'004')
insert into Course values('006','计算机原理',4,64,'005')
insert into Course values('007','数据结构',5,96,'005')
insert into Course values('008','操作系统',4,64,'007')
insert into Course values('009','数据库系统原理',4,80,'008')

insert into Course values('010','会计学原理',4,64,'004')
insert into Course values('011','中级财务会计',5,80,'010')

go


------------------------------------------------------------------
------------------------------------------------------------------
print 'create Class'
go

CREATE TABLE Class (
  classNo	  char(6) 	          NOT NULL ,  --班级号
  className	  varchar(30)  unique     NOT NULL,   --班级名
  institute       varchar(30)             NOT NULL,   --所属学院
  grade           smallint     default 0  NOT NULL,   --年级
  classNum        tinyint		  NULL,       --班级人数        
  constraint ClassPK primary key (ClassNo) 
) 
go

insert into Class values('CS1501','计算机科学与技术15-01班','信息管理学院',2015,null)
insert into Class values('CS1502','计算机科学与技术15-02班','信息管理学院',2015,null)
insert into Class values('IS1501','信息管理与信息系统15-01班','信息管理学院',2015,null)
insert into Class values('IS1601','信息管理与信息系统16-01班','信息管理学院',2016,null)
insert into Class values('CP1601','注册会计16_01班','会计学院',2016,null)
insert into Class values('CP1602','注册会计16_02班','会计学院',2016,null)
insert into Class values('CP1603','注册会计16_03班','会计学院',2016,null)
insert into Class values('ER1501','金融管理15-01班','金融学院',2015,null)
insert into Class values('CS1601','计算机科学与技术16-01班','信息管理学院',2016,null)

go

------------------------------------------------------------------
------------------------------------------------------------------
print 'Student'
go
CREATE TABLE Student (
  studentNo	char(7) 		  NOT NULL 
    check ( StudentNo like '[0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),  --学号
  studentName	varchar(20) 		  NOT NULL ,          --姓名
  sex 	        char(2) 		      NULL ,          --性别
  birthday	datetime 		      NULL ,          --出生日期
  native        varchar(20)                   NULL ,          --籍贯                
  nation	varchar(30) default '汉族'    NULL,           --民族
  classNo	char(6) 	              NULL            --所属班级	
  constraint StudentPK primary key (studentNo),
  constraint StudentFK foreign key(classNo) references Class(classNo)
) 
go

insert into Student values('1600001','李勇',   '男','1998-12-21 00:00','南昌','汉族',   'CS1601')
insert into Student values('1600002','刘晨',   '女','1998-11-11 00:00','九江','汉族',   'IS1601')
insert into Student values('1600003','王敏',   '女','1998-10-01 00:00','上海','汉族',   'IS1601')
insert into Student values('1600004','张立',   '男','1999-05-20 00:00','南昌','蒙古族', 'CS1601')
insert into Student values('1600005','王红',   '男','1999-04-26 00:00','南昌','蒙古族', 'CP1602')
insert into Student values('1600006','李志强', '男','1999-12-21 00:00','北京','汉族',   'CP1602')
insert into Student values('1600007','李立',   '女','1999-08-21 00:00','福建','畲族',   'IS1601')
insert into Student values('1600008','黄小红', '女','1999-08-09 00:00','云南','傣族',   'CS1601')
insert into Student values('1600009','黄勇',   '男','1999-11-21 00:00','九江','汉族',   'CP1602')
insert into Student values('1600010','李宏冰', '女','1998-03-09 00:00','上海','汉族',   'CP1602')
insert into Student values('1600011','江宏吕', '男','1998-12-20 00:00','上海','汉族',   'CP1602')
insert into Student values('1600012','王立红', '男','1998-11-18 00:00','北京','汉族',   'CS1601')
insert into Student values('1600013','刘小华', '女','1999-07-16 00:00','云南','哈呢族', 'IS1601')
insert into Student values('1600014','刘宏昊', '男','1999-09-16 00:00','福建','汉族',   'IS1601')
insert into Student values('1600015','吴敏',   '女','1997-01-20 00:00','福建','畲族',   'CP1602')
insert into Student values('1500001','李小勇',   '男','1998-12-21 00:00','南昌','汉族',   'CS1501')
insert into Student values('1500002','刘方晨',   '女','1998-11-11 00:00','九江','汉族',   'IS1501')
insert into Student values('1500003','王红敏',   '女','1997-10-01 00:00','上海','汉族',   'IS1501')
insert into Student values('1500004','张可立',   '男','1999-05-20 00:00','南昌','蒙古族', 'CS1501')
insert into Student values('1500005','王红',   '男','2000-04-26 00:00','南昌','蒙古族',   'CS1502')
go
------------------------------------------------------------------------------------
------------------------------------------------------------------------------------
print 'Term'
go
CREATE TABLE Term (
  termNo	char(3) 	     NOT NULL ,      --学期号
  termName	varchar(30)          NOT NULL,       --学期名
  remarks       varchar(10)          NULL,           --备注       
  constraint termPK primary key (termNo) 
) 
go
insert into  Term values('151','2015-2016学年第一学期',null)
insert into  Term values('152','2015-2016学年第二学期',null)
insert into  Term values('153','2015-2016学年第三学期','小学期')
insert into  Term values('161','2016-2017学年第一学期',null)
insert into  Term values('162','2016-2017学年第二学期',null)
insert into  Term values('163','2016-2017学年第三学期','小学期')
go

------------------------------------------------------------------------------------
------------------------------------------------------------------------------------
print 'Score'
go
CREATE TABLE Score (
  studentNo       char(7) 	 	  NOT NULL ,      --学号
  courseNo        char(3) 		  NOT NULL ,      --课程号
  termNo	  char(3) 	          NOT NULL ,      --学期号
  score	numeric(5,1) default 0	NOT NULL 
           check( Score between 0.0 and 100.0)   --成绩
  /* 元组级完整性约束条件，主码由三个属性构成*/
  constraint ScorePK primary key (studentNo,courseNo,termNo),
  /* 表级完整性约束条件，studentNo是外码，被参照表是Student */
  constraint ScoreFK1 foreign key(studentNo) references student(studentNo),
  /* 表级完整性约束条件，courseNo是外码，被参照表是Course*/
  constraint ScoreFK2 foreign key(termNo) references Term(termNo),
  /* 表级完整性约束条件，termNo是外码，被参照表是Term*/
  constraint ScoreFK3 foreign key(courseNo) references course(courseNo)
) 
go
insert into Score values('1500001','001','151',98)
insert into Score values('1500001','002','151',82)
insert into Score values('1500001','010','151',86)
insert into Score values('1500001','004','151',56)
insert into Score values('1500001','005','152',77)
insert into Score values('1500001','006','152',76)
insert into Score values('1500001','007','152',77)
insert into Score values('1500001','004','161',86)
insert into Score values('1500001','003','161',82)
insert into Score values('1500001','008','161',82)
insert into Score values('1500001','009','162',77)


insert into Score values('1500005','002','151',80)
insert into Score values('1500005','003','151',69)
insert into Score values('1500005','004','151',87)
insert into Score values('1500005','005','151',77)
insert into Score values('1500005','001','152',79)
insert into Score values('1500005','006','152',69)
insert into Score values('1500005','010','152',69)
insert into Score values('1500005','007','161',90)
insert into Score values('1500005','008','161',87)
insert into Score values('1500005','009','162',90)
insert into Score values('1500005','011','162',68)

insert into Score values('1500003','005','151',60)
insert into Score values('1500003','001','151',46)
insert into Score values('1500003','002','151',38)
insert into Score values('1500003','007','152',50)
insert into Score values('1500003','002','152',58)
insert into Score values('1500003','006','161',70)
insert into Score values('1500003','010','161',90)
insert into Score values('1500003','007','162',66)
insert into Score values('1500003','008','162',82)
insert into Score values('1500003','009','162',78)

insert into Score values('1500004','001','151',48)
insert into Score values('1500004','004','151',58)
insert into Score values('1500004','003','152',70)
insert into Score values('1500004','002','161',68)
insert into Score values('1500004','007','161',71)
insert into Score values('1500004','008','161',80)
insert into Score values('1500004','001','162',70)
insert into Score values('1500004','005','162',88)
insert into Score values('1500004','006','162',72)

insert into Score values('1600002','001','161',98)
insert into Score values('1600002','004','161',60)
insert into Score values('1600002','002','161',46)
insert into Score values('1600002','003','162',98)
insert into Score values('1600002','010','162',70)
insert into Score values('1600002','005','162',86)

insert into Score values('1600003','001','161',70)
insert into Score values('1600003','002','161',60)
insert into Score values('1600003','004','161',77)
insert into Score values('1600003','005','162',87)

insert into Score values('1600004','001','161',50)
insert into Score values('1600004','002','161',70)
insert into Score values('1600004','004','161',78)
insert into Score values('1600004','010','161',89)
insert into Score values('1600004','011','162',90)
insert into Score values('1600004','003','162',88)
insert into Score values('1600004','001','162',68)

insert into Score values('1600005','001','161',82)
insert into Score values('1600005','002','161',80)
insert into Score values('1600005','010','161',90)
insert into Score values('1600005','004','161',47)
insert into Score values('1600005','003','162',82)
insert into Score values('1600005','011','162',82)

insert into Score values('1600014','001','161',60)
insert into Score values('1600014','003','161',87)
insert into Score values('1600014','004','161',45)
insert into Score values('1600014','010','161',90)
insert into Score values('1600014','004','162',88)
insert into Score values('1600014','011','162',70)
insert into Score values('1600014','002','162',69)
insert into Score values('1600014','005','162',56)

insert into Score values('1600012','001','161',68)
insert into Score values('1600012','003','161',76)
insert into Score values('1600012','004','161',70)
insert into Score values('1600012','005','161',88)
insert into Score values('1600012','002','162',78)
insert into Score values('1600012','006','162',82)
insert into Score values('1600012','007','162',90)
insert into Score values('1600012','010','162',84)


go






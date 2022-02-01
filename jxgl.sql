CREATE TABLE Student
(
  Sno CHAR(5) primary key,
  Sname VARCHAR2(12) NOT NULL,
  Sdept CHAR(2) NOT NULL,
  Sclass CHAR(2) NOT NULL,
  Ssex CHAR(3),
  Sage NUMBER(2,0)
);

CREATE TABLE Course
(
  Cno CHAR(3) primary KEY,
  Cname VARCHAR2(20),
  Ctime NUMBER(2,0)
);

CREATE TABLE Teach
(
  Tname VARCHAR2(12),
  Tsex CHAR(3),
  Cno CHAR(3),
  Tdate DATE,
  Tdept CHAR(2),
  PRIMARY KEY(Tname,Cno,Tdept),
  CONSTRAINT FK_Cno FOREIGN KEY(Cno) REFERENCES Course(Cno)
);
CREATE TABLE Score
(
  Sno CHAR(5),
  Cno CHAR(3),
  Score NUMBER(4,1),
  PRIMARY KEY (Sno,Cno),
  CONSTRAINT FK_Sno FOREIGN KEY(Sno) REFERENCES Student(Sno),
  CONSTRAINT FK_Cno FOREIGN KEY(Cno) REFERENCES Course(Cno)
);

CREATE TABLESPACE JXGL
DATAFILE 'D:\oraclexe\app\oracle\oradata\XE JXGL_DATA.DBF' SIZE 100M;


insert into Student values('96001','马小燕','CS','01','女',21);
insert into Student values('96002','黎明','CS','01','男',18);
insert into Student values('96003','刘东明','MA','01','男',18);
insert into Student values('96004','赵志勇','IS','02','男',20);
insert into Student values('97001','马蓉','MA','02','女',19);
insert into Student values('97002','李成功','CS','01','男',20);
insert into Student values('97003','黎明','IS','03','女',19);
insert into Student values('97004','李丽','CS','02','女',19);
insert into Student values('96005','司马志明','CS','02','男',18);

insert into COURSE values('001','数学分析',144);
insert into COURSE values('002','普通物理',144);
insert into COURSE values('003','微机原理',80);
insert into COURSE values('004','数据结构',72);
insert into COURSE values('005','操作系统',80);
insert into COURSE values('006','数据库原理',80);
insert into COURSE values('007','编译原理',60);
insert into COURSE values('008','程序设计',40);

insert into TEACH values('王成刚','男','004','9-5月-99','CS');
insert into TEACH values('李正科','男','003','09-5月-99','CS');
insert into TEACH values('严敏','女','001','09-5月-99','MA');
insert into TEACH values('赵高','男','004','09-5月-99','MA');
insert into TEACH values('刘玉兰','女','006','23/2月/00','CS');
insert into TEACH values('王成刚','男','004','23/2月/00','IS');
insert into TEACH values('马悦','女','008','6/9月/00','CS');

insert into Score values('96001','001',77.5);
insert into Score values('96001','003',89); 
insert into Score values('96001','004',86); 
insert into Score values('96001','005',82); 
insert into Score values('96002','001',88);
insert into Score values('96002','003',92.5);
insert into Score values('96002','006',90); 
insert into Score values('96005','004',92);
insert into Score values('96005','005',90); 
insert into Score values('96005','006',89);
insert into Score values('96005','007',78); 
insert into Score values('96003','001',69);
insert into Score values('97001','001',96); 
insert into Score values('97001','008',95); 
insert into Score values('96004','001',87);
insert into Score values('96003','003',91);
insert into Score values('97002','003',91);
insert into Score values('97002','004',null); 
insert into Score values('97002','006',92);
insert into Score values('97004','005',90);
insert into Score values('97004','006',85);
commit;










create or replace PROCEDURE student_list
AS
cursor mycur is SELECT * FROM Student;
s_info  Student%rowtype;
num1 number(2);
i number(2);
begin
student_count(num1);
for i in 1 .. num1 loop
dbms_output.put_line('学生编号:'||s_info.sno);
dbms_output.put_line('学生姓名:'||s_info.sname);
dbms_output.put_line('学生年龄:'||s_info.sage);
dbms_output.put_line('学生性别:'||s_info.ssex);
dbms_output.put_line('学生系:'||s_info.sdept);
dbms_output.put_line('学生班级:'||s_info.sclass);
dbms_output.put_line('---------------------------------------');
end loop;
end;


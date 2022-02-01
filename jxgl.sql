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


insert into Student values('96001','��С��','CS','01','Ů',21);
insert into Student values('96002','����','CS','01','��',18);
insert into Student values('96003','������','MA','01','��',18);
insert into Student values('96004','��־��','IS','02','��',20);
insert into Student values('97001','����','MA','02','Ů',19);
insert into Student values('97002','��ɹ�','CS','01','��',20);
insert into Student values('97003','����','IS','03','Ů',19);
insert into Student values('97004','����','CS','02','Ů',19);
insert into Student values('96005','˾��־��','CS','02','��',18);

insert into COURSE values('001','��ѧ����',144);
insert into COURSE values('002','��ͨ����',144);
insert into COURSE values('003','΢��ԭ��',80);
insert into COURSE values('004','���ݽṹ',72);
insert into COURSE values('005','����ϵͳ',80);
insert into COURSE values('006','���ݿ�ԭ��',80);
insert into COURSE values('007','����ԭ��',60);
insert into COURSE values('008','�������',40);

insert into TEACH values('���ɸ�','��','004','9-5��-99','CS');
insert into TEACH values('������','��','003','09-5��-99','CS');
insert into TEACH values('����','Ů','001','09-5��-99','MA');
insert into TEACH values('�Ը�','��','004','09-5��-99','MA');
insert into TEACH values('������','Ů','006','23/2��/00','CS');
insert into TEACH values('���ɸ�','��','004','23/2��/00','IS');
insert into TEACH values('����','Ů','008','6/9��/00','CS');

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
dbms_output.put_line('ѧ�����:'||s_info.sno);
dbms_output.put_line('ѧ������:'||s_info.sname);
dbms_output.put_line('ѧ������:'||s_info.sage);
dbms_output.put_line('ѧ���Ա�:'||s_info.ssex);
dbms_output.put_line('ѧ��ϵ:'||s_info.sdept);
dbms_output.put_line('ѧ���༶:'||s_info.sclass);
dbms_output.put_line('---------------------------------------');
end loop;
end;


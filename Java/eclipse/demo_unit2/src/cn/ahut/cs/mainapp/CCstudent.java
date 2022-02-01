package cn.ahut.cs.mainapp;
import cn.ahut.cs.userdefinelib.*;
//定义一个接口，只有常量和方法头
interface Cpeople {		//人员接口
	final String nationality="中国"; 	//定义常量
	String getSno();
	void setSno(String sno);
	String getName();
	void setName(String name);
	CDate getDate();
	void setDate(CDate date);
	double getGrade();
	
}

class CCstudent implements Cpeople{	//学生
	String sno;		//学号
	String sname;	//姓名
	CDate sdate;	//出生日期
	double smark;	//考试分数
	public CCstudent(String sno,String sname,CDate sdate,double smark) {
		this.sno=sno;
		this.sname=sname;
		this.sdate=sdate;
		this.smark=smark;
	}
	public String getSno() {return sno;}
	public void setSno(String sno) {this.sno=sno;}
	public String getName() {return sname;}
	public void setName(String name) {this.sname=name;}
	public CDate getDate() {return this.sdate;}
	public void setDate(CDate date) {this.sdate=date;}
	public double getGrade() {return smark;}
	public String toString() {
		return "学号："+sno+"\t姓名"+sname+"\t出生日期："+sdate+"\n国籍："+this.nationality+"\n";
	}
}

class CUniversityStudent extends CCstudent{//大学生类
	int roomNo;			//宿舍号
	double usualGrade;	//平时成绩
	public CUniversityStudent(int roomNo,String sno,String sname,CDate sdate,double smark,double usualGrade){
		super(sno,sname,sdate,smark);
		this.roomNo=roomNo;
		this.usualGrade=usualGrade;
	}	
	public double getGrade(){return smark+this.usualGrade;}		//大学生有平时成绩和考试成绩
	public String toString(){
		return "宿舍号："+roomNo+"\n"+super.toString();
	}
}

class CGraduteStudent extends CCstudent{		//研究生类
	int roomNo;		//宿舍号
	String advisor;	//导师
	double advisorGrade;	//导师成绩
	public CGraduteStudent(int roomNo,String advisor,String sno,String sname,CDate sdate,double smark,double advisorGrade){
		super(sno,sname,sdate,smark);
		this.roomNo=roomNo;
		this.advisor=advisor;
		this.advisorGrade=advisorGrade;
	}	
	public double getGrade(){return smark+this.advisorGrade;}	//研究生成绩有考试成绩和导师成绩
	public String toString(){
		return "宿舍号："+roomNo+"\n导师："+advisor+"\n"+super.toString();
	}
}





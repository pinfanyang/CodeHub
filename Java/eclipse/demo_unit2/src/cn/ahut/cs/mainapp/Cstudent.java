package cn.ahut.cs.mainapp;
import cn.ahut.cs.userdefinelib.*;//引用该包中的日期类
public class Cstudent {
	private String sno;	//学号
	String sname;		//姓名
	public CDate sdate;	//出生日期,此处为组合对象
	private static int count; //统计学生对象个数的类变量
	
	public Cstudent() {		//无参构造函数
		this.sno="199084184";
		this.sname="杨玄风";
		this.sdate=new CDate();
		count++;
	}
	public Cstudent(String no,String name,CDate date) {	//带参构造函数
		this.sno=no;
		this.sname=name;
		this.sdate=date;
		count++;
	}
	
	public String getSno() {
		return this.sno;
	}
	public void setSno(String no) {
		this.sno=no;
	}
	public static int getCount() {
		return count;
	}
	public String toString() {
		return "学生："+sname+"\t学号："+sno+"\t出生日期："+sdate.toString();
	}

	
	
}

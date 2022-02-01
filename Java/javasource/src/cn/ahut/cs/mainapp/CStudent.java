package cn.ahut.cs.mainapp;
//引用自定义cn.ahut.cs.userdefinelib包中的日期类
import cn.ahut.cs.userdefinelib.CDate;
public class CStudent {
    //私有成员变量和默认成员变量
    private String sno;//学号
    String sname;//姓名
    public CDate sdate;//出生日期
    private static int count;//统计学生对象个数类变量

    public CStudent(){//无参构造方法，给成员变量一个固定初值
        this.sno="199084184";
        this.sname="杨玄风";
        this.sdate=new CDate();
        count++;
    }
    public CStudent(String no,String name,CDate date){
        //三参构造方法，给成员变量一个初值，初值有用户给出
        this.sno=no;
        this.sname=name;
        this.sdate =date;
        count++;
    }

    public String getSno(){
        return this.sno;
    }
    public void setSno(String no){
        this.sno=no;
    }
    public static int getCount(){//类方法，获取类变量count的值
        return count;
    }
    public String toString(){//toStirng()方法重写
        return "学生："+sname+ "\n学号："+sno+"\n出生日期："+sdate.toString();
    }

}

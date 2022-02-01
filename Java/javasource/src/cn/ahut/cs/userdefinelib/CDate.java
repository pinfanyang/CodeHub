package cn.ahut.cs.userdefinelib;
//日期类
public class CDate {
    //私有成员变量和默认（友好）成员变量
    private int year;//年
    private int month;//月
    int day;//日
    public CDate(){//无参构造方法
        year=2014;
        month=1;
        day=1;
    }
    public CDate(int y,int m,int d){//有参构造方法
        year=y;
        month=m;
        day=d;
    }
    //下面6个方法是成员变量对外接口，实现成员变量的读写操作
    public int getYear(){
        return this.year;
    }
    public int getMonth(){
        return this.month;
    }
    public int getDay(){
        return this.day;
    }
    public void setYear(int y){
        this.year=y;
    }
    public void setMoneth(int m){
        this.month=m;
    }
    public void setDay(int d){
        this.day=d;
    }
    //Object类具有一个toString()方法，你创建的每个类都会继承该方法。它返回对象的一个String表示，并且对于调试非常有帮助。然而对于默认的toString()方法往往不能满足需求，需要覆盖这个方法。
    public String toString(){
        return year+"年"+month+"月"+day+"日";
    }
}

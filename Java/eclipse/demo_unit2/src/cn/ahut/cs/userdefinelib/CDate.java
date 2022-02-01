package cn.ahut.cs.userdefinelib;
//日期类
public class CDate {
	//私有成员变量和默认成员变量
	private int year;
	private int month;
	int day;
	
	public CDate() {	//无参构造方法
		this.day=4;
		this.month=11;
		this.year=2021;
	}
	public CDate(int y,int m,int d) { //有参构造方法
		this.day=d;
		this.month=m;
		this.year=y;
	}
	
	//下面方法为成员变量对外接口，实现成员变量的读写操作
	public int getYear() {
		return this.year;
	}
	public int getMonth() {
		return this.month;
	}
	public int getDay() {
		return this.day;
	}
	public void setYear(int y) {
		this.year=day;
	}
	public void setMonth(int m) {
		this.month=m;
	}
	public void setDay(int d) {
		this.day=d;
	}
	
	public String toString() {			//覆盖OBject类的toString()方法
		return year+"年"+month+"月"+day+"日";
	}

}

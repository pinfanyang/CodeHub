package cn.ahut.cs.userdefinelib;
//������
public class CDate {
	//˽�г�Ա������Ĭ�ϳ�Ա����
	private int year;
	private int month;
	int day;
	
	public CDate() {	//�޲ι��췽��
		this.day=4;
		this.month=11;
		this.year=2021;
	}
	public CDate(int y,int m,int d) { //�вι��췽��
		this.day=d;
		this.month=m;
		this.year=y;
	}
	
	//���淽��Ϊ��Ա��������ӿڣ�ʵ�ֳ�Ա�����Ķ�д����
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
	
	public String toString() {			//����OBject���toString()����
		return year+"��"+month+"��"+day+"��";
	}

}

package cn.ahut.cs.mainapp;
import cn.ahut.cs.userdefinelib.*;//���øð��е�������
public class Cstudent {
	private String sno;	//ѧ��
	String sname;		//����
	public CDate sdate;	//��������,�˴�Ϊ��϶���
	private static int count; //ͳ��ѧ����������������
	
	public Cstudent() {		//�޲ι��캯��
		this.sno="199084184";
		this.sname="������";
		this.sdate=new CDate();
		count++;
	}
	public Cstudent(String no,String name,CDate date) {	//���ι��캯��
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
		return "ѧ����"+sname+"\tѧ�ţ�"+sno+"\t�������ڣ�"+sdate.toString();
	}

	
	
}

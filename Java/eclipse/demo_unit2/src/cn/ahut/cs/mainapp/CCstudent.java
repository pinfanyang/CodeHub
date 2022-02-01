package cn.ahut.cs.mainapp;
import cn.ahut.cs.userdefinelib.*;
//����һ���ӿڣ�ֻ�г����ͷ���ͷ
interface Cpeople {		//��Ա�ӿ�
	final String nationality="�й�"; 	//���峣��
	String getSno();
	void setSno(String sno);
	String getName();
	void setName(String name);
	CDate getDate();
	void setDate(CDate date);
	double getGrade();
	
}

class CCstudent implements Cpeople{	//ѧ��
	String sno;		//ѧ��
	String sname;	//����
	CDate sdate;	//��������
	double smark;	//���Է���
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
		return "ѧ�ţ�"+sno+"\t����"+sname+"\t�������ڣ�"+sdate+"\n������"+this.nationality+"\n";
	}
}

class CUniversityStudent extends CCstudent{//��ѧ����
	int roomNo;			//�����
	double usualGrade;	//ƽʱ�ɼ�
	public CUniversityStudent(int roomNo,String sno,String sname,CDate sdate,double smark,double usualGrade){
		super(sno,sname,sdate,smark);
		this.roomNo=roomNo;
		this.usualGrade=usualGrade;
	}	
	public double getGrade(){return smark+this.usualGrade;}		//��ѧ����ƽʱ�ɼ��Ϳ��Գɼ�
	public String toString(){
		return "����ţ�"+roomNo+"\n"+super.toString();
	}
}

class CGraduteStudent extends CCstudent{		//�о�����
	int roomNo;		//�����
	String advisor;	//��ʦ
	double advisorGrade;	//��ʦ�ɼ�
	public CGraduteStudent(int roomNo,String advisor,String sno,String sname,CDate sdate,double smark,double advisorGrade){
		super(sno,sname,sdate,smark);
		this.roomNo=roomNo;
		this.advisor=advisor;
		this.advisorGrade=advisorGrade;
	}	
	public double getGrade(){return smark+this.advisorGrade;}	//�о����ɼ��п��Գɼ��͵�ʦ�ɼ�
	public String toString(){
		return "����ţ�"+roomNo+"\n��ʦ��"+advisor+"\n"+super.toString();
	}
}





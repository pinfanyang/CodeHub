package ���Գ�����;
abstract class Shape{		//�������ʵ��
	String shapeName;
	Shape(String s){
		shapeName=s;
	}
	abstract void calArea();		//�����
	abstract void calGirth();		//���ܳ�
}

class Rect extends Shape{		//��������
	double W,L;
	Rect(String s){super(s);}
	Rect(String s,double a,double b){
		super(s);
		this.W=a;
		this.L=b;
	}
	void calArea() {			//��д����
		System.out.println(Rect.super.shapeName+"�����:"+W*L);
	}
	void calGirth() {
		System.out.println(Rect.super.shapeName+"���ܳ�:"+2*(W+L));
	}
}

class Tixing extends Rect{
	double height;	//��
	Rect Rt;		//���γ���ֱ�䵱�������ϵ�
	Tixing(String s,Rect r,double h){	
		super(s);		//ͨ��Rectʵ�ֳ�����
		this.Rt=r;
		this.height=h;
	}
	void calArea() {
		System.out.println(Tixing.super.shapeName+"�����:"+ (Rt.L+Rt.W)*height/2 );
	}
	void calGirth() {
		double temp=Math.sqrt(Math.pow(Math.abs(Rt.L-Rt.W)/2,2)+height*height);	//б��
		System.out.println(Tixing.super.shapeName+"���ܳ�:"+(Rt.W+Rt.L+2*temp));//�ϵ�+�µ�+б��*2
	}
	
}

public class ����{
	public static void main(String[] args) {
		Rect Rt=new Rect("����",6,14);
		Tixing Ti=new Tixing("����",Rt,3);
		Rt.calArea();
		Rt.calGirth();
		Ti.calArea();
		Ti.calGirth();
	}
}


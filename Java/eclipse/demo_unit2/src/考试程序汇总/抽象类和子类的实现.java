package ���Գ������;

abstract class Shape{
	//�������ʵ��
	String shapeName;
	Shape(String s){
		shapeName=s;
	}
	abstract double calArea();		//ֻ�ܶ���ͷ������ʵ�֣�����̳�ʵ��
}
class Rect extends Shape{	//��������
	int W,L;
	Rect(String s,int W,int L){
		super(s);
		this.W=W;
		this.L=L;
	}
	double calArea() {		//��д����
		return W*L;
	}
}

class Circle extends Shape{	//Բ��
	int r;
	final double PI=3.1415;
	Circle(String s,int r){
		super(s);
		this.r=r;
	}
	double calArea() {
		return PI*r*r;
	}
}

class Cylinder{		//������
	Shape s;	//û��ֱ�Ӽ̳�
	double height;
	Cylinder(Shape s,double height){
		this.s=s;
		this.height=height;
	}
	void calVolume() {
		System.out.println(s.shapeName+"�����:"+(s.calArea()*height));
	}
}

public class ������������ʵ�� {
	public static void main(String[] args) {
		Shape s;
		Cylinder c;
		//���㳤�������
		s=new Rect("������",20,40);
		c=new Cylinder(s,30.5);
		c.calVolume();
		
		//����Բ�������
		s=new Circle("Բ����",20);
		c=new Cylinder(s,30);
		c.calVolume();
	}
	
}

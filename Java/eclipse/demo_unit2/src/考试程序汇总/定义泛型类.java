package ���Գ������;

class Circle1{
	double radius;
	Circle1(double radius){
		this.radius=radius;
	}
	public String toString() {
		return 3.14*this.radius*this.radius+"";	//ת���ַ���
	}
}
class Rect1{
	double W,L;
	Rect1(double W,double L){
		this.L=L;
		this.W=W;
	}
	public String toString() {
		return W*L+"";
	}
}
class Cylinder1<T>{
	T bottom;
	double height;
	Cylinder1(T bottom,double height){
		this.bottom=bottom;
		this.height=height;
	}
	public double calVolume() {
		double area=Double.parseDouble(bottom.toString());
		return area*height;
	}
}
public class ���巺���� {
	public static void main(String[] args) {
		//Բ����
		Circle1 c=new Circle1(12.5);
		Cylinder1<Circle1> cl=new Cylinder1<Circle1>(c,120);
		System.out.println("Բ��������Ϊ��"+cl.calVolume());
		//������
		Rect1 r=new Rect1(12,36);
		Cylinder1<Rect1> c2=new Cylinder1<Rect1>(r,110);
		System.out.println("����������Ϊ��"+c2.calVolume());
	}
}

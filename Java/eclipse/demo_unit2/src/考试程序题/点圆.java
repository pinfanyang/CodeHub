package ���Գ�����;
class Point{		//����
	double x,y;	//x����Circle���ɼ�������Ϊ��ֹ���Գ�����������������
	Point(){}
	Point(double xx,double yy){
		this.x=xx;
		this.y=yy;
	}
	double getX() {return x;}
	double getY() {return y;}
	void setX(double xx) {this.x=xx;}
	void setY(double yy) {this.y=yy;}
	double getLen(Point pa) {return Math.sqrt( Math.pow(this.x-pa.x,2) + Math.pow(this.y-pa.y,2) );	//������֮��ľ��룬ע��x�Ĵ��� 
	}
}

class Circle extends Point{		//Բ��̳е���
	private double r;
	Point Yuanxing;
	Circle(Point pa,Point pb){	//������������Բ
		this.Yuanxing=new Point( Math.abs(pa.x+pb.x)/2 , Math.abs(pa.y+pb.y)/2 );	//����Բ��;
		this.r=pa.getLen(pb)/2;
	}
	double getR() {return r;}
	Point getPoint() {return Yuanxing;}
	double getArea() {return 3.14*r*r;}
	double getZhouchang() {return 2*3.14*r;}
}

public class ��Բ {
	public static void main(String[] args) {
		Point pa=new Point(10,10);
		Point pb=new Point(20,20);
		Circle cc=new Circle(pa,pb);
		System.out.println("������2����:("+ pa.x +","+ pa.y +"),("+ pb.x +","+ pb.y +")");
		System.out.println("����֮��ľ���Ϊ:"+pa.getLen(pb));
		System.out.println("Բ��Ϊ:("+cc.getPoint().x+","+cc.getPoint().y+")");
		System.out.println("Բ�İ뾶Ϊ:"+cc.getR());
		System.out.println("Բ�����Ϊ:"+cc.getArea());
		System.out.println("Բ���ܳ�Ϊ:"+cc.getZhouchang());
	}
}
 
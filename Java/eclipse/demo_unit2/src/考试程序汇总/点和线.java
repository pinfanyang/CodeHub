package ���Գ������;
import java.util.*;
class Point{
	private int x;
	int y;
	void setX(int x) {this.x=x;}
	int getX() {return x;}
	void print() {
		System.out.println("("+x+","+y+")");
	}
}
class Line extends Point{
	//�̳�Point����x���ɼ���y�ǿɼ��ģ��������ǿɼ���
	Point pa,pb;
	Line(Point aa,Point bb){
		this.pa=aa;
		this.pb=bb;
	}
	double getLen() {
		double Len=Math.sqrt( Math.pow(pa.getX()-pb.getX(),2) + Math.pow(pa.y-pb.y,2) );
		return Len;
	}
}
public class ����� {
	public static void main(String[] args) {
		//Point��Ķ԰������ͷ���
		Point p=new Point();
		p.setX(10);p.y=20;
		p.print();
		//Line��Ķ��󴴽��ͳ�Ա����
		Point p1=new Point();
		p1.setX(20);p1.y=20;
		p1.print();
		Line line=new Line(p,p1);
		System.out.println("���룺"+line.getLen());
		
	}

}

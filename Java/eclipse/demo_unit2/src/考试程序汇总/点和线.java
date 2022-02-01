package 考试程序汇总;
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
	//继承Point类中x不可见，y是可见的；方法都是可见的
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
public class 点和线 {
	public static void main(String[] args) {
		//Point类的对岸创建和访问
		Point p=new Point();
		p.setX(10);p.y=20;
		p.print();
		//Line类的对象创建和成员访问
		Point p1=new Point();
		p1.setX(20);p1.y=20;
		p1.print();
		Line line=new Line(p,p1);
		System.out.println("距离："+line.getLen());
		
	}

}

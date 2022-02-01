package 考试程序汇总;

abstract class Shape{
	//抽象类的实现
	String shapeName;
	Shape(String s){
		shapeName=s;
	}
	abstract double calArea();		//只能定义头，不能实现，子类继承实现
}
class Rect extends Shape{	//长方形类
	int W,L;
	Rect(String s,int W,int L){
		super(s);
		this.W=W;
		this.L=L;
	}
	double calArea() {		//重写方法
		return W*L;
	}
}

class Circle extends Shape{	//圆类
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

class Cylinder{		//柱体类
	Shape s;	//没有直接继承
	double height;
	Cylinder(Shape s,double height){
		this.s=s;
		this.height=height;
	}
	void calVolume() {
		System.out.println(s.shapeName+"的体积:"+(s.calArea()*height));
	}
}

public class 抽象类和子类的实现 {
	public static void main(String[] args) {
		Shape s;
		Cylinder c;
		//计算长方体体积
		s=new Rect("长方体",20,40);
		c=new Cylinder(s,30.5);
		c.calVolume();
		
		//计算圆柱体体积
		s=new Circle("圆柱体",20);
		c=new Cylinder(s,30);
		c.calVolume();
	}
	
}

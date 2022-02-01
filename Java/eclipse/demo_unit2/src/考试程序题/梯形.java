package 考试程序题;
abstract class Shape{		//抽象类的实现
	String shapeName;
	Shape(String s){
		shapeName=s;
	}
	abstract void calArea();		//求面积
	abstract void calGirth();		//求周长
}

class Rect extends Shape{		//长方形类
	double W,L;
	Rect(String s){super(s);}
	Rect(String s,double a,double b){
		super(s);
		this.W=a;
		this.L=b;
	}
	void calArea() {			//重写方法
		System.out.println(Rect.super.shapeName+"的面积:"+W*L);
	}
	void calGirth() {
		System.out.println(Rect.super.shapeName+"的周长:"+2*(W+L));
	}
}

class Tixing extends Rect{
	double height;	//高
	Rect Rt;		//矩形长宽分别充当梯形下上底
	Tixing(String s,Rect r,double h){	
		super(s);		//通过Rect实现抽象类
		this.Rt=r;
		this.height=h;
	}
	void calArea() {
		System.out.println(Tixing.super.shapeName+"的面积:"+ (Rt.L+Rt.W)*height/2 );
	}
	void calGirth() {
		double temp=Math.sqrt(Math.pow(Math.abs(Rt.L-Rt.W)/2,2)+height*height);	//斜边
		System.out.println(Tixing.super.shapeName+"的周长:"+(Rt.W+Rt.L+2*temp));//上底+下底+斜边*2
	}
	
}

public class 梯形{
	public static void main(String[] args) {
		Rect Rt=new Rect("矩形",6,14);
		Tixing Ti=new Tixing("梯形",Rt,3);
		Rt.calArea();
		Rt.calGirth();
		Ti.calArea();
		Ti.calGirth();
	}
}


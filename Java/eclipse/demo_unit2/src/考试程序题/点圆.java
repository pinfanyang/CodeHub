package 考试程序题;
class Point{		//点类
	double x,y;	//x对于Circle不可见，这里为防止考试出现这种限制做区分
	Point(){}
	Point(double xx,double yy){
		this.x=xx;
		this.y=yy;
	}
	double getX() {return x;}
	double getY() {return y;}
	void setX(double xx) {this.x=xx;}
	void setY(double yy) {this.y=yy;}
	double getLen(Point pa) {return Math.sqrt( Math.pow(this.x-pa.x,2) + Math.pow(this.y-pa.y,2) );	//求两点之间的距离，注意x的处理 
	}
}

class Circle extends Point{		//圆类继承点类
	private double r;
	Point Yuanxing;
	Circle(Point pa,Point pb){	//由两点来构造圆
		this.Yuanxing=new Point( Math.abs(pa.x+pb.x)/2 , Math.abs(pa.y+pb.y)/2 );	//构造圆心;
		this.r=pa.getLen(pb)/2;
	}
	double getR() {return r;}
	Point getPoint() {return Yuanxing;}
	double getArea() {return 3.14*r*r;}
	double getZhouchang() {return 2*3.14*r;}
}

public class 点圆 {
	public static void main(String[] args) {
		Point pa=new Point(10,10);
		Point pb=new Point(20,20);
		Circle cc=new Circle(pa,pb);
		System.out.println("构造了2个点:("+ pa.x +","+ pa.y +"),("+ pb.x +","+ pb.y +")");
		System.out.println("两点之间的距离为:"+pa.getLen(pb));
		System.out.println("圆心为:("+cc.getPoint().x+","+cc.getPoint().y+")");
		System.out.println("圆的半径为:"+cc.getR());
		System.out.println("圆的面积为:"+cc.getArea());
		System.out.println("圆的周长为:"+cc.getZhouchang());
	}
}
 
package 考试程序汇总;

class CRect{	//长方形类
	int width,length;
	double getArea() {
		return width*length;
	}
}
class CSquare extends CRect{	//正方形类，继承于长方形类
	double width;
	double getArea() {
		return width*width;
	}
}

public class 面积 {
	public static void main(String[] args) {
		CRect r=new CRect();
		r.length=20;
		r.width=10;
		System.out.println("长方形的面积为："+r.getArea());
		
		CSquare s=new CSquare();
		s.width=20.4;
		System.out.println("正方形的面积为："+s.getArea());

	}

}

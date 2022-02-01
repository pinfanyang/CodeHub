package 考试程序汇总;

interface interfaceA{	//定义一个接口
	public static final double PI=3.14;		//定义常量，public static final可省略，系统默认会加上的
	public abstract void calArea();			//定义抽象方法，public abstract可省略，同上
}
interface interfaceB{
	public abstract void calPerimeter();		//抽象方法
}
interface interfaceC extends interfaceA,interfaceB{} //接口的多继承
class Circle11 implements interfaceC{
	int r;
	Circle11(int r){
		this.r=r;
	}
	public void calArea() {		//public不能省略，因为接口中默认为public，权限不能省略，省略权限就改成了友好（默认）
		System.out.println("圆的面积："+(PI*r*r));
	}
	public void calPerimeter() {
		System.out.println("圆的周长："+(2*PI*r));
	}
}

public class 接口的实现类 {
	public static void main(String[] args) {
		Circle11 c=new Circle11(14);
		c.calArea();
		c.calPerimeter();
	}
}

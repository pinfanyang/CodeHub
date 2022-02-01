package 考试程序题;
import java.util.*;
class Zdgys{
	int a,b;
	Zdgys(int aa,int bb){
		this.a=aa;
		this.b=bb;
	}
	int f() {		//辗转相处法
		int temp=a%b;
		while(temp!=0) {
			a=b;
			b=temp;
			temp=a%b;
		}
		return b;
	}
}
public class 最大公约数 {
	public static void main(String[] args) {
		System.out.print("请输入待求解的数字:");
		Scanner in=new Scanner(System.in);
		int a,b;
		a=in.nextInt();
		b=in.nextInt();
		Zdgys gys=new Zdgys(a,b);
		System.out.println("这2个数字的最大公约数为："+gys.f());
		in.close();
		
	}
}

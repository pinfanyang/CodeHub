package 考试程序题;
import java.util.*;
class Zxgbs{
	int a,b;
	Zxgbs(int aa,int bb){
		this.a=aa;
		this.b=bb;
	}
	int f_gcd() {		//辗转相处法
		int temp=a%b;
		while(temp!=0) {
			a=b;
			b=temp;
			temp=a%b;
		}
		return b;
	}
	int f() {
		return a*b/f_gcd();
	}
}
public class 最小公倍数{
public static void main(String[] args) {
	System.out.print("请输入待求解的数字:");
	Scanner in=new Scanner(System.in);
	int a,b;
	a=in.nextInt();
	b=in.nextInt();
	Zxgbs z=new Zxgbs(a,b);
	System.out.println("这2个数字的最小公倍数为："+z.f());
	in.close();
	
}
}



//class Zxgbs{
//BigInteger a,b;
//Zxgbs( BigInteger aa, BigInteger bb){
//	 this.a=aa;
//	 this.b=bb;
//}
//BigInteger Qiujie() {
//	 return a.multiply(b).divide(a.gcd(b));		//	a*b/(a和b的最大公约数）
//}
//
//
//}
//public class 最小公倍数{
//public static void main(String[] args) {
//	System.out.print("请输入待求解的数字:");
//	Scanner in=new Scanner(System.in);
//	BigInteger a,b;
//	a=in.nextBigInteger();
//	b=in.nextBigInteger();
//	Zxgbs z=new Zxgbs(a,b);
//	System.out.println("这2个数字的最小公倍数为："+z.Qiujie());
//	in.close();
//	
//}
//}
package ���Գ�����;
import java.util.*;
class Zxgbs{
	int a,b;
	Zxgbs(int aa,int bb){
		this.a=aa;
		this.b=bb;
	}
	int f_gcd() {		//շת�ദ��
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
public class ��С������{
public static void main(String[] args) {
	System.out.print("���������������:");
	Scanner in=new Scanner(System.in);
	int a,b;
	a=in.nextInt();
	b=in.nextInt();
	Zxgbs z=new Zxgbs(a,b);
	System.out.println("��2�����ֵ���С������Ϊ��"+z.f());
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
//	 return a.multiply(b).divide(a.gcd(b));		//	a*b/(a��b�����Լ����
//}
//
//
//}
//public class ��С������{
//public static void main(String[] args) {
//	System.out.print("���������������:");
//	Scanner in=new Scanner(System.in);
//	BigInteger a,b;
//	a=in.nextBigInteger();
//	b=in.nextBigInteger();
//	Zxgbs z=new Zxgbs(a,b);
//	System.out.println("��2�����ֵ���С������Ϊ��"+z.Qiujie());
//	in.close();
//	
//}
//}
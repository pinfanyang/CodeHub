package ���Գ�����;
import java.util.*;
class Zdgys{
	int a,b;
	Zdgys(int aa,int bb){
		this.a=aa;
		this.b=bb;
	}
	int f() {		//շת�ദ��
		int temp=a%b;
		while(temp!=0) {
			a=b;
			b=temp;
			temp=a%b;
		}
		return b;
	}
}
public class ���Լ�� {
	public static void main(String[] args) {
		System.out.print("���������������:");
		Scanner in=new Scanner(System.in);
		int a,b;
		a=in.nextInt();
		b=in.nextInt();
		Zdgys gys=new Zdgys(a,b);
		System.out.println("��2�����ֵ����Լ��Ϊ��"+gys.f());
		in.close();
		
	}
}

package ���Գ������;
import java.util.*;

public class �쳣���� {
	public static void main(String[] args) {
		int[] a=new int[10];
		int m,n;
		Scanner scan=new Scanner(System.in);
		try {
			a[10]=123;
			m=scan.nextInt();
		}catch(IndexOutOfBoundsException iobe) {
			System.out.println("����Խ���쳣��"+iobe.toString());
		}catch(InputMismatchException ime) {
			System.out.println("�����ʽ�쳣��"+ime.toString());
		}catch(Exception e) {
			System.out.println(e.toString());
		}finally {
				System.out.println("finally�鱻ִ�У�");
		}
		System.out.println("���������н�����");
	}

}

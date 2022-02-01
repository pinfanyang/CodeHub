package 考试程序汇总;
import java.util.*;

public class 异常处理 {
	public static void main(String[] args) {
		int[] a=new int[10];
		int m,n;
		Scanner scan=new Scanner(System.in);
		try {
			a[10]=123;
			m=scan.nextInt();
		}catch(IndexOutOfBoundsException iobe) {
			System.out.println("数组越界异常："+iobe.toString());
		}catch(InputMismatchException ime) {
			System.out.println("输入格式异常："+ime.toString());
		}catch(Exception e) {
			System.out.println(e.toString());
		}finally {
				System.out.println("finally块被执行！");
		}
		System.out.println("主方法运行结束！");
	}

}

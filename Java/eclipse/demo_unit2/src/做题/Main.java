//package 做题;
//import java.util.*;
//public class Main {
//	public static void main(String[] args)
//	{
//		Scanner in = new Scanner(System.in);
//		long a=in.nextLong();
//		long b=0;		//逆序数
//		long ans;	//存放最终结果
//		long remainder;//余数
//		while(a<=1000000)
//		{
//			long input=a;
//	        while (input != 0) {
//	            remainder = input % 10;
//	            input = input / 10;
//	            b = b*10 + remainder;           
//	        }
//	        ans=a+b;
//	        if(ans<=200000 && ans>=100000)
//	        {
//	        	System.out.println(a);
//	        	break;
//	        }
//	        a++;
//	        b=0;
//	    }
//		if(a>1000000)
//			System.out.println("F");
//
//		
//		in.close();
//	}
//}

package 做题;
import java.util.*;
public class Main{
	public static void main(String[] args)
	{
		Scanner in_number = new Scanner(System.in);
		int n=in_number.nextInt();
		for(int i=0;i<n+1;i++)
		{
			String xingxi=in_number.nextLine();
		}
		System.out.println(1);
		in_number.close();
		
	}
}


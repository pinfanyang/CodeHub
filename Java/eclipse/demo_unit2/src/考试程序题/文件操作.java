package 考试程序题;
import java.io.*;
public class 文件操作{
public static void main(String[] args) {
	try {
		FileReader in_a=new FileReader("D:\\\\a.txt");	//读a
		BufferedReader in_ba=new BufferedReader(in_a);
		FileWriter to_b=new FileWriter("D:\\\\b.txt");	//写b
		BufferedWriter out_bb=new BufferedWriter(to_b);
		
		String s=null;
	//	int i=0;
		while((s=in_ba.readLine())!=null) {
		//	i++;
			String[] strs=s.split(" ");
			out_bb.write(Integer.parseInt(strs[0])+"+"+Integer.parseInt(strs[1])+"="+(Integer.parseInt(strs[0])+Integer.parseInt(strs[1])));
			out_bb.newLine();	//换行
		}
		out_bb.flush();		//刷新缓冲区
		in_ba.close();
		out_bb.close();
		in_a.close();
		to_b.close();
	}catch(Exception e)
	{
		System.out.println(e);
	}
}
}


//public class 文件操作{
//public static void main(String[] args) {
//	try {
//		FileReader in_a=new FileReader("D:\\\\a.txt");	//读a
//		BufferedReader in_ba=new BufferedReader(in_a);
//		FileWriter to_b=new FileWriter("D:\\\\b.txt");	//写b
//		BufferedWriter out_bb=new BufferedWriter(to_b);
//		
//		String s=null;
//		while((s=in_ba.readLine())!=null) {
//			String[] strs=s.split("[+=]{1}");
//			//out_bb.write(i+"."+s+(Integer.parseInt(strs[0])+Integer.parseInt(strs[1])));
//			out_bb.write(Integer.parseInt(strs[0])+" "+Integer.parseInt(strs[1])+" "+(Integer.parseInt(strs[0])+Integer.parseInt(strs[1])));
//			out_bb.newLine();	//换行
//		}
//		out_bb.flush();		//刷新缓冲区
//		in_ba.close();
//		out_bb.close();
//		in_a.close();
//		to_b.close();
//	}catch(Exception e)
//	{
//		System.out.println(e);
//	}
//}
//}
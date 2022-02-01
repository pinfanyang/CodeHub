package 做题;
import java.io.*;
public class 文件的复制{
	public static void main(String[] args) {
		File fa=new File("D:\\\\a.txt");
		File fb=new File("D:\\\\b.txt");
		char wd[]="这是文件a.txt中的内容:allmakemean@*1".toCharArray();
		try {
			FileWriter out_a=new FileWriter(fa);	//在a.txt中写入
			out_a.write(wd);
			out_a.write("|再次附加:a.txt");
			out_a.close();
			
			FileReader in_a=new FileReader(fa);		//读a.txt
			FileWriter out_b=new FileWriter(fb);	//写b.txt
			int n=0;
			while((n=in_a.read(wd,0,1))!=-1)		//wd字符数组复用，每次从in_a的0位开始读1字符
			{
				String str=new String(wd,0,1);
				out_b.write(str);
				System.out.print(str);
			}
			in_a.close();
			out_b.close();
		}catch(IOException e)
		{
			System.out.println(e);
		}
	}
}
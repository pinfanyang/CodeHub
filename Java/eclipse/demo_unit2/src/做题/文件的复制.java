package ����;
import java.io.*;
public class �ļ��ĸ���{
	public static void main(String[] args) {
		File fa=new File("D:\\\\a.txt");
		File fb=new File("D:\\\\b.txt");
		char wd[]="�����ļ�a.txt�е�����:allmakemean@*1".toCharArray();
		try {
			FileWriter out_a=new FileWriter(fa);	//��a.txt��д��
			out_a.write(wd);
			out_a.write("|�ٴθ���:a.txt");
			out_a.close();
			
			FileReader in_a=new FileReader(fa);		//��a.txt
			FileWriter out_b=new FileWriter(fb);	//дb.txt
			int n=0;
			while((n=in_a.read(wd,0,1))!=-1)		//wd�ַ����鸴�ã�ÿ�δ�in_a��0λ��ʼ��1�ַ�
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
package 文件输入输出;
import java.io.*;
//这种以字节的输入输出存在bug，当字符串中有不一样的字符类型时候，按字节读取会乱码。
public class 文件的读写 {
	public static void main(String[] args) {
		//先打开a.txt文件进行编辑
		File fa=new File("D:\\\\a.txt");
		byte[] wd="这是文件a.txt中的内容。".getBytes();
		try {
			FileOutputStream out=new FileOutputStream(fa);	//写入编辑的内容
			out.write(wd);
			out.close();
			
			FileInputStream in=new FileInputStream(fa);
			int n=0;
			while((n=in.read(wd,0,2))!=-1)
			{
				String str=new String(wd,0,2);
				System.out.print(str);
			}
			in.close();
		}catch(IOException e)
		{
			System.out.println(e);
		}
	}
}


package �ļ��������;
import java.io.*;
//�������ֽڵ������������bug�����ַ������в�һ�����ַ�����ʱ�򣬰��ֽڶ�ȡ�����롣
public class �ļ��Ķ�д {
	public static void main(String[] args) {
		//�ȴ�a.txt�ļ����б༭
		File fa=new File("D:\\\\a.txt");
		byte[] wd="�����ļ�a.txt�е����ݡ�".getBytes();
		try {
			FileOutputStream out=new FileOutputStream(fa);	//д��༭������
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


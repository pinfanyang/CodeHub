package �ļ��������;
import java.io.*;

public class �����ļ� {
	public static void main(String[] args) {
		String filePath="d:\\\\temp\\test.txt";
		File file=new File("d:\\\\temp");
		if(!file.exists()) {
			System.out.println("d:\\\\tempĿ¼�����ڣ�������Ŀ¼��");
			file.mkdir();
		}	
		file=new File(filePath);
		if(!file.exists()) {
			try {
				if(file.createNewFile())
					System.out.println(file.getName()+"�ļ������ɹ���");
			}catch(IOException e) {
				System.out.println("�ļ�����ʧ�ܣ�");
			}
		}
	}
}

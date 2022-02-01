package 文件输入输出;
import java.io.*;

public class 创建文件 {
	public static void main(String[] args) {
		String filePath="d:\\\\temp\\test.txt";
		File file=new File("d:\\\\temp");
		if(!file.exists()) {
			System.out.println("d:\\\\temp目录不存在，创建该目录。");
			file.mkdir();
		}	
		file=new File(filePath);
		if(!file.exists()) {
			try {
				if(file.createNewFile())
					System.out.println(file.getName()+"文件创建成功！");
			}catch(IOException e) {
				System.out.println("文件创建失败！");
			}
		}
	}
}

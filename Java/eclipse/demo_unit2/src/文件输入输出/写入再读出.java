package 文件输入输出;
import java.io.*;
public class 写入再读出 {
	   public static void main(String args[ ])
	   { 
	      File file=new File("hello.txt");
	      char b[]="这是文件a.txt中的内容".toCharArray();
	      try{
	           FileWriter  out=new  FileWriter(file);//writing
	           out.write(b);
	           out.write("来到北京!");
	           out.close();
	           
	           FileReader  in=new FileReader(file);//reading
	           int n=0;
	           while((n=in.read(b,0,2))!=-1)
	           {
	               String str=new String(b,0,2);
	               System.out.print(str);
	           }
	           in.close();
	         }
	      catch(IOException e)
	         {
	           System.out.println(e);
	         }  
	   }
}


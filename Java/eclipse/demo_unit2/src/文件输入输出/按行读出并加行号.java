package 文件输入输出;
import java.io.*;
//重点看下这个 和 考试的比较相似
public class 按行读出并加行号 {
	   public static void main(String args[ ])
	   { 
	      File readFile=new File("Student.txt"),
	      		
	           writeFile=new File("Hello.txt");
	           
	      try{
	      		readFile.createNewFile();
	      		writeFile.createNewFile();
	           FileReader  inOne=new FileReader("Student.txt");//reading from student
	           BufferedReader inTwo= new BufferedReader(inOne);
	           
	           FileWriter  tofile=new FileWriter("hello.txt");//writing to hellos
	           BufferedWriter out= new BufferedWriter(tofile);
	           
	           //writing to hello  and reading from student
	           String s=null;
	           int i=0;
	           while((s=inTwo.readLine())!=null)
	           {
	               i++;
	               out.write(i+" "+s);
	               out.newLine();//换行
	           }
	           out.flush();//刷新缓冲区
	           out.close();
	           tofile.close();//close output file
	           
	           //reading from hello
	           inOne=new FileReader("hello.txt");
	           inTwo= new BufferedReader(inOne);
	           while((s=inTwo.readLine())!=null)
	           {
	             System.out.println(s);
	           } 
	           inOne.close();
	           inTwo.close();
	      }
	      catch(IOException e)
	         {
	           System.out.println(e);
	         }  
	   }
}


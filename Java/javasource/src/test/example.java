package test;
import java.util.*;

public class example {
    public static void main(String args[ ])
    {
        System.out.println("输入文本");
        Scanner s=new Scanner(System.in);
        String str=s.nextLine();
        String regex="[\\s\\d]+";
        String words[]=str.split(regex);
        for(int i=0;i<words.length;i++){

            int m=i+1;
            System.out.println(""+m+": "+words[i]);
        }
    }
}

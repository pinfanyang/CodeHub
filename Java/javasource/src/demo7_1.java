import java.text.NumberFormat;
import java.util.*;
public class demo7_1
{
    public static void main(String args[ ])
    {
        double a=Math.sqrt(5);
        System.out.println("格式化前："+a);
        NumberFormat f=NumberFormat.getInstance();
        f.setMaximumFractionDigits(5);
        f.setMinimumIntegerDigits(3);
        String s=f.format(a);
        System.out.println("格式化后："+s);
        System.out.println("得到的随机数：");
        int number=8;
        for(int i=1;i<=20;i++)
        {
            int randomNumber=(int)(Math.random()*number)+1;//产生1到8之间的随机数。
            System.out.print(" "+randomNumber);
            if(i%10==0)
                System.out.println("");
        }
    }
}
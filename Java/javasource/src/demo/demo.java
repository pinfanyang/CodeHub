package demo;

import java.math.BigInteger;

public class demo {
    public static void main(String args[])
    {
        BigInteger n1=new BigInteger("987654321987654321987654321"),
                   n2=new BigInteger("123456789123456789123456789"),
                   result=null;
        System.out.println("n1的二进制表示:"+n1.toString(2));
        System.out.println("n2的八进制表示:"+n2.toString(8));
        result=n1.add(n2);
        System.out.println("和:"+result.toString());
        result=n1.subtract(n2);
        System.out.println("差:"+result.toString());
        result=n1.multiply(n2);
        System.out.println("积:"+result.toString());
        result=n1.divide(n2);
        System.out.println("商:"+result.toString());

        /*BigInteger m=new BigInteger("778899"),
                COUNT=new BigInteger("0"),
                ONE=new BigInteger("1"),
                TWO=new BigInteger("2");
       for(BigInteger i=TWO;i.compareTo(m)<0;i=i.add(ONE))
        {
            if((n1.remainder(i).compareTo(BigInteger.ZERO))==0)
            {
                COUNT=COUNT.add(ONE);
                System.out.println("因子:"+i.toString());
            }
        }
        System.out.println(m.toString()+"一共有"+COUNT.toString()+"个因子");
    }

  */
        BigInteger m=new BigInteger("20"),
                COUNT=new BigInteger("1"),
                ONE=new BigInteger("1"),
                TWO=new BigInteger("2");
       for(BigInteger i=TWO;i.compareTo(m)<0;i=i.add(ONE))
        {
           // if((n1.remainder(i).compareTo(BigInteger.ZERO))==0)
            {
                COUNT=COUNT.multiply(i);
           //     System.out.println("因子:"+i.toString());
            }
        }
        System.out.println(m.toString()+"的阶乘为:"+COUNT.toString());
    }
//bug? 正确性验证？
}



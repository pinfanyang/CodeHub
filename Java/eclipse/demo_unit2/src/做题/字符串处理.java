package 做题;
class 字符串处理{
	public static void main(String[] args) {
		String STR="this is a test of java";
		String str_a="a";
        int i=STR.length()-(STR.replace(str_a,"")).length();
        char[] str=STR.toCharArray();	//通过toCharArray()方法
        char[] str1=new char[STR.length()];
        for(int j=0;j<STR.length();j++) {	//通过charAt方法
        	str1[j]=STR.charAt(j);
        }
        char[] str2=new char[STR.length()];
        STR.getChars(0, STR.length(), str2, 0);//通过getChars方法
        String[] split=STR.split(" ");//按空格分隔成数组
        System.out.println("1.该字符串中字母s出现的次数为："+i);
        System.out.println("2.取出字字符串\"test\":"+STR.substring(9,14));
        System.out.println("3.下面是复制字符串的方法：");
        String temp=new String(str);
        System.out.println("第一种：通过toCharArray()方法复制："+temp);
        String temp1=new String(str1);
        System.out.println("第二种：通过charAt()方法复制："+temp1);
        String temp2=new String(str2);
        System.out.println("第三种：通过getChars()方法复制："+temp2);
        System.out.print("4.将字符串中每个单词的第一个字母变成大写输出：");
        for(int k=0;k<split.length;k++) {
        	String str3=split[k].substring(0,1).toUpperCase()+split[k].substring(1);
        	System.out.print(str3+" ");
        }
        System.out.print("\n5.用StringBuffered方法实现该字符串的逆序输出：");
        StringBuffer b=new StringBuffer(STR);
        b=b.reverse();
        System.out.println(b);
        System.out.print("用for实现该字符串的逆序输出：");
        for(int m=STR.length()-1;m>=0;m--)
        	System.out.print(STR.charAt(m));
        System.out.print("\n6.用字符串转换成一个字符串数组：");
        String[] sp=STR.split(" +");
        for(int n=0;n<sp.length;n++) {
        	System.out.print(sp[n]+" ");
        }
	}
}


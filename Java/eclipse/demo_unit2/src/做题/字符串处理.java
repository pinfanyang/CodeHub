package ����;
class �ַ�������{
	public static void main(String[] args) {
		String STR="this is a test of java";
		String str_a="a";
        int i=STR.length()-(STR.replace(str_a,"")).length();
        char[] str=STR.toCharArray();	//ͨ��toCharArray()����
        char[] str1=new char[STR.length()];
        for(int j=0;j<STR.length();j++) {	//ͨ��charAt����
        	str1[j]=STR.charAt(j);
        }
        char[] str2=new char[STR.length()];
        STR.getChars(0, STR.length(), str2, 0);//ͨ��getChars����
        String[] split=STR.split(" ");//���ո�ָ�������
        System.out.println("1.���ַ�������ĸs���ֵĴ���Ϊ��"+i);
        System.out.println("2.ȡ�����ַ���\"test\":"+STR.substring(9,14));
        System.out.println("3.�����Ǹ����ַ����ķ�����");
        String temp=new String(str);
        System.out.println("��һ�֣�ͨ��toCharArray()�������ƣ�"+temp);
        String temp1=new String(str1);
        System.out.println("�ڶ��֣�ͨ��charAt()�������ƣ�"+temp1);
        String temp2=new String(str2);
        System.out.println("�����֣�ͨ��getChars()�������ƣ�"+temp2);
        System.out.print("4.���ַ�����ÿ�����ʵĵ�һ����ĸ��ɴ�д�����");
        for(int k=0;k<split.length;k++) {
        	String str3=split[k].substring(0,1).toUpperCase()+split[k].substring(1);
        	System.out.print(str3+" ");
        }
        System.out.print("\n5.��StringBuffered����ʵ�ָ��ַ��������������");
        StringBuffer b=new StringBuffer(STR);
        b=b.reverse();
        System.out.println(b);
        System.out.print("��forʵ�ָ��ַ��������������");
        for(int m=STR.length()-1;m>=0;m--)
        	System.out.print(STR.charAt(m));
        System.out.print("\n6.���ַ���ת����һ���ַ������飺");
        String[] sp=STR.split(" +");
        for(int n=0;n<sp.length;n++) {
        	System.out.print(sp[n]+" ");
        }
	}
}


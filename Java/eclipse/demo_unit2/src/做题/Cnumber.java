package ����;

public class Cnumber {
	int value;//��ֵ
	int index;//�ڼ�����
	private static int count;//ͳ�Ƹ���
	public Cnumber(){
		this.value=0;	//Ĭ�Ϲ��캯������Ϊ0
		this.index=1;
	}
	public Cnumber(int a,int b) {
		this.index=a;
		this.value=b;
		count++;
	}
	
	public void setValue(int x)
	{
		//value=new Integer(x); JDK�����汾��֧��
		value=Integer.valueOf(x);	//װ��
	}
	public int getValue()
	{
		return value;	//����
	}
	public String toString() {
		return "��"+index+"������ֵΪ:"+value;
	}
	public static void setCount() {
		count--;
	}
	public int getCount() {
		return count;
	}
	public static int get_s_Count() {
		return count;
	}
	
	
	
}

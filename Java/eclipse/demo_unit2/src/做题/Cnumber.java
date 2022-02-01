package 做题;

public class Cnumber {
	int value;//数值
	int index;//第几个数
	private static int count;//统计个数
	public Cnumber(){
		this.value=0;	//默认构造函数设置为0
		this.index=1;
	}
	public Cnumber(int a,int b) {
		this.index=a;
		this.value=b;
		count++;
	}
	
	public void setValue(int x)
	{
		//value=new Integer(x); JDK后续版本不支持
		value=Integer.valueOf(x);	//装箱
	}
	public int getValue()
	{
		return value;	//拆箱
	}
	public String toString() {
		return "第"+index+"个数，值为:"+value;
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

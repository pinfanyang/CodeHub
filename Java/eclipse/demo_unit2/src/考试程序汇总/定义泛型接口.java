package 考试程序汇总;

interface GenInter<T>{
	public void show(T t);
}
class InterImplGenericClass<Q> implements GenInter<Q>{
	public void show(Q q) {
		System.out.println("显示："+q);
	}
}
public class 定义泛型接口 {
	public static void main(String[] args) {
		GenInter<String> gi=new InterImplGenericClass<String>();
		gi.show("这是一个字符串！");
	}
}

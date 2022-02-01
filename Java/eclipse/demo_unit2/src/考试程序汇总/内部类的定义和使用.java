package 考试程序汇总;

class outer{
	private int ox=10;
	public String oy="外部类";
	
	class inner{
		private int ix=15;
		public String iy="内部类";
		void g() {
			ox+=110;		//访问外部类的私有成员
		}
	}
	
	void f() {
		inner in=new inner();		//创建内部类对象
		in.ix=115;	//不能直接访问内部类的私有成员，ix=115错误
		System.out.println("内部类的成员变量ix的值被修改为："+in.ix);
		in.g();
		System.out.println("外部类的私有成员ox的值被修改为："+ox);
		//创建局部内部类
		class localInner{
			void k() {
				ox=215;
				System.out.println("外部类的私有成员ox被局部内部类的方法修改为："+ox);
			}
		}
		localInner ain=new localInner();
		ain.k();
	}
}

public class 内部类的定义和使用 {
	public static void main(String[] args) {
		outer ter=new outer();
		ter.f();
		//在主方法中访问内部类
		outer.inner inn=new outer().new inner();
		inn.g();
		ter.f();
	}

}

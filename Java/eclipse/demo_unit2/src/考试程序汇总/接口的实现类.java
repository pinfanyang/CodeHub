package ���Գ������;

interface interfaceA{	//����һ���ӿ�
	public static final double PI=3.14;		//���峣����public static final��ʡ�ԣ�ϵͳĬ�ϻ���ϵ�
	public abstract void calArea();			//������󷽷���public abstract��ʡ�ԣ�ͬ��
}
interface interfaceB{
	public abstract void calPerimeter();		//���󷽷�
}
interface interfaceC extends interfaceA,interfaceB{} //�ӿڵĶ�̳�
class Circle11 implements interfaceC{
	int r;
	Circle11(int r){
		this.r=r;
	}
	public void calArea() {		//public����ʡ�ԣ���Ϊ�ӿ���Ĭ��Ϊpublic��Ȩ�޲���ʡ�ԣ�ʡ��Ȩ�޾͸ĳ����Ѻã�Ĭ�ϣ�
		System.out.println("Բ�������"+(PI*r*r));
	}
	public void calPerimeter() {
		System.out.println("Բ���ܳ���"+(2*PI*r));
	}
}

public class �ӿڵ�ʵ���� {
	public static void main(String[] args) {
		Circle11 c=new Circle11(14);
		c.calArea();
		c.calPerimeter();
	}
}

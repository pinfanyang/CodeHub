package ���Գ������;

interface GenInter<T>{
	public void show(T t);
}
class InterImplGenericClass<Q> implements GenInter<Q>{
	public void show(Q q) {
		System.out.println("��ʾ��"+q);
	}
}
public class ���巺�ͽӿ� {
	public static void main(String[] args) {
		GenInter<String> gi=new InterImplGenericClass<String>();
		gi.show("����һ���ַ�����");
	}
}

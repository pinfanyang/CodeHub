package ���Գ������;

class outer{
	private int ox=10;
	public String oy="�ⲿ��";
	
	class inner{
		private int ix=15;
		public String iy="�ڲ���";
		void g() {
			ox+=110;		//�����ⲿ���˽�г�Ա
		}
	}
	
	void f() {
		inner in=new inner();		//�����ڲ������
		in.ix=115;	//����ֱ�ӷ����ڲ����˽�г�Ա��ix=115����
		System.out.println("�ڲ���ĳ�Ա����ix��ֵ���޸�Ϊ��"+in.ix);
		in.g();
		System.out.println("�ⲿ���˽�г�Աox��ֵ���޸�Ϊ��"+ox);
		//�����ֲ��ڲ���
		class localInner{
			void k() {
				ox=215;
				System.out.println("�ⲿ���˽�г�Աox���ֲ��ڲ���ķ����޸�Ϊ��"+ox);
			}
		}
		localInner ain=new localInner();
		ain.k();
	}
}

public class �ڲ���Ķ����ʹ�� {
	public static void main(String[] args) {
		outer ter=new outer();
		ter.f();
		//���������з����ڲ���
		outer.inner inn=new outer().new inner();
		inn.g();
		ter.f();
	}

}

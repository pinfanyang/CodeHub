package ���Գ������;

class CRect{	//��������
	int width,length;
	double getArea() {
		return width*length;
	}
}
class CSquare extends CRect{	//�������࣬�̳��ڳ�������
	double width;
	double getArea() {
		return width*width;
	}
}

public class ��� {
	public static void main(String[] args) {
		CRect r=new CRect();
		r.length=20;
		r.width=10;
		System.out.println("�����ε����Ϊ��"+r.getArea());
		
		CSquare s=new CSquare();
		s.width=20.4;
		System.out.println("�����ε����Ϊ��"+s.getArea());

	}

}

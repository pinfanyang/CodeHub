package cn.ahut.cs.mainapp;
import cn.ahut.cs.userdefinelib.*;//�����Զ�����е�������
//public class main {
//	public static void main(String[] args) {
//		//����һ������
//		CDate date=new CDate(1999,1,1);
//		Cstudent stu=new Cstudent("199084180","����",date);
//		System.out.println(stu.toString());
//		
//		//����CDate���еĹ��з���setDay()
//		stu.sdate.setDay(29);
//		System.out.println("�޸ĺ�ĳ�������Ϊ��"+stu.sdate.toString());
//		
//		//�����
//		System.out.println("������"+Cstudent.getCount()+"��ѧ����");
//		stu=new Cstudent("199084181","����",new CDate());
//		System.out.println(stu.toString());
//		System.out.println("������"+Cstudent.getCount()+"��ѧ����");
//		
//		//��������
//		System.out.println("\n�����������£�");
//		Cstudent[] stus=new Cstudent[2];
//		stus[0]=new Cstudent("199080180","����",new CDate(2001,1,1));
//		stus[1]=new Cstudent("199080181","������",new CDate(2001,1,2));
//		System.out.println(stus[0].toString());
//		System.out.println(stus[1].toString());
//		System.out.println("������"+Cstudent.getCount()+"��ѧ����");
//	}
//}

public class main {
	public static void main(String[] args) {
		//��ת�Ͷ���Ͷ�̬
		CCstudent csu=new CUniversityStudent(211,"159074111","����",new CDate(1997,1,10),98.5,85.0);		
		System.out.println("��ĩ������"+csu.getGrade());
		System.out.println(csu.toString());
		csu=new CGraduteStudent(301,"����ǿ","156111","����",new CDate(1993,11,23),89.0,90.0);
		System.out.println("��ĩ������"+csu.getGrade());
		System.out.println(csu.toString());
		
		//�ӿںͽӿڻص�
		Cpeople cpu=new CUniversityStudent(511,"139074123","�����",new CDate(1996,11,11),94.5,95.0);		
		System.out.println("��ĩ������"+cpu.getGrade());
		System.out.println(cpu.toString());
		cpu=new CGraduteStudent(301,"�����","156111","����",new CDate(1994,11,21),85.0,95.0);
		System.out.println("��ĩ������"+cpu.getGrade());
		System.out.println(cpu.toString());		
	}
}
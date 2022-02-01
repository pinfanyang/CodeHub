package cn.ahut.cs.mainapp;
import cn.ahut.cs.userdefinelib.*;//引用自定义包中的日期类
//public class main {
//	public static void main(String[] args) {
//		//创建一个对象
//		CDate date=new CDate(1999,1,1);
//		Cstudent stu=new Cstudent("199084180","张三",date);
//		System.out.println(stu.toString());
//		
//		//调用CDate类中的公有方法setDay()
//		stu.sdate.setDay(29);
//		System.out.println("修改后的出生日期为："+stu.sdate.toString());
//		
//		//类变量
//		System.out.println("现在有"+Cstudent.getCount()+"个学生。");
//		stu=new Cstudent("199084181","李四",new CDate());
//		System.out.println(stu.toString());
//		System.out.println("现在有"+Cstudent.getCount()+"个学生。");
//		
//		//对象数组
//		System.out.println("\n对象数组如下：");
//		Cstudent[] stus=new Cstudent[2];
//		stus[0]=new Cstudent("199080180","赵四",new CDate(2001,1,1));
//		stus[1]=new Cstudent("199080181","赵六七",new CDate(2001,1,2));
//		System.out.println(stus[0].toString());
//		System.out.println(stus[1].toString());
//		System.out.println("现在有"+Cstudent.getCount()+"个学生。");
//	}
//}

public class main {
	public static void main(String[] args) {
		//上转型对象和多态
		CCstudent csu=new CUniversityStudent(211,"159074111","李四",new CDate(1997,1,10),98.5,85.0);		
		System.out.println("期末总评："+csu.getGrade());
		System.out.println(csu.toString());
		csu=new CGraduteStudent(301,"王三强","156111","王五",new CDate(1993,11,23),89.0,90.0);
		System.out.println("期末总评："+csu.getGrade());
		System.out.println(csu.toString());
		
		//接口和接口回调
		Cpeople cpu=new CUniversityStudent(511,"139074123","李大有",new CDate(1996,11,11),94.5,95.0);		
		System.out.println("期末总评："+cpu.getGrade());
		System.out.println(cpu.toString());
		cpu=new CGraduteStudent(301,"孙大四","156111","丁巳",new CDate(1994,11,21),85.0,95.0);
		System.out.println("期末总评："+cpu.getGrade());
		System.out.println(cpu.toString());		
	}
}
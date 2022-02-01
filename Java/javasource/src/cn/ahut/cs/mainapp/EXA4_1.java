package cn.ahut.cs.mainapp;
//测试主类
import cn.ahut.cs.userdefinelib.*;
public class EXA4_1 {
    public static void main(String[] args) {
        //创建对象
        CDate date=new CDate(2001,7,4);
        CStudent stu=new CStudent("199084184","杨玄风",date);
        System.out.println(stu.toString());

        //调用CDate类中公有方法setDay(int),
        //stu.sdate.dayr=2000;//错误：不同包之间访问时，只有公有权限才可以访问,默认权限不行，私有更不行
        stu.sdate.setDay(20);
        System.out.println(stu.toString());

        //类变量
        System.out.println("现在有 "+CStudent.getCount()+ " 个学生");
        stu=new CStudent("149074100","李三",new CDate());
        System.out.println(stu.toString());
        System.out.println("现在有 "+CStudent.getCount()+ " 个学生");

        //对象数组
        System.out.println("\n对象数组:");
        CStudent[] stus=new CStudent[2];
        stus[0]=new CStudent("149074211","赵四",new CDate(2014,11,11));
        stus[1]=new CStudent("149074212","赵六奇",new CDate(2014,12,12));
        System.out.println(stus[0].toString());
        System.out.println(stus[1].toString());
        System.out.println("现在有 "+CStudent.getCount()+ " 个学生");
    }
}

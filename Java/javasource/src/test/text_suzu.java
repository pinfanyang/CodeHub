package test;

import java.util.Scanner;

//数组的综合实例：P61
public class text_suzu {
    public static void main(String[] args)
    {
        int total;
        int N=3;
        int[][] salary=new int[N][4];
        int[] t=new int[4];
        Scanner reader=new Scanner(System.in);
        for (int i=0; i<N; i++) {
            total=0;
            System.out.println("请输入第"+(i+1)+"个基本员工的基本工资，奖金，提成：");
            for (int j=0; j<3;j++)
            {
                salary[i][j]=reader.nextInt();
                total+=salary[i][j];
            }
            salary[i][3]=total;
        }
        for(int i=0; i<N; i++) {
            for(int j=i+1; j<N;j++)
            {
                if(salary[i][3]<salary[j][3])
                {
                    t=salary[i];
                    salary[i]=salary[j];
                    salary[j]=t;
                }
            }
        }
        System.out.println("按总和排序后的工资为：");
        for(int i=0;i<N;i++)
        {
            System.out.println(salary[i][0]+" "+salary[i][1]+" "+salary[i][2]+" "+salary[i][3]);
        }

    }
}

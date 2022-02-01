#include<bits/stdc++.h>
using namespace std;
//暴力法
int MaxSubseqSum(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j;
    for(i=0;i<N;i++)        //i为子列左端位置
    {
        ThisSum=0;          //ThisSum为从A[i]到A[j]的子列和
        for(j=i;j<N;j++)    //j为子列右端位置
        {
            ThisSum+=A[j];  //对于同一个i，不同j，只在j-1次循环基础上累加1项即可
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }                   //j循环结束
    }                       //i循环结束
    return MaxSum;
}

//分治法
/* 返回3个整数中的最大值 */
int Max3( int A, int B, int C )
{ 
    return A > B ? A > C ? A : C : B > C ? B : C;
}
/* 分治法求List[left]到List[right]的最大子列和 */
int DivideAndConquer( int List[], int left, int right )
{ 
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/
    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )   /* 递归的终止条件，子列只有1个数字 */
    {
        if( List[left] > 0 )  
            return List[left];
        else 
            return 0;
    }

    /* 下面是"分"的过程 */

    center = ( left + right ) / 2;  /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; 
    LeftBorderSum = 0;
    for( i=center; i>=left; i-- )       /* 从中线向左扫描 */
    { 
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for( i=center+1; i<=right; i++ )    /* 从中线向右扫描 */
    { 
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    }

    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum1( int List[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}

//累积遍历算法
int MaxSubseqSum2(int A[],int N)
{
    int ThisSum,MaxSum;
    ThisSum=MaxSum=0;
    for(int i=0;i<N;i++)
    {
        ThisSum+=A[i];      //向右累加
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;     //发现更大和则更新当前结果
        else
            if(ThisSum<0)
                ThisSum=0;      //后续都比前面小，忽略
    }
    return MaxSum;
}



int main()
{
    int a[9]={-2,1,-3,4,-1,2,1,-5,4};
    cout<<MaxSubseqSum(a,9)<<endl;
    cout<<MaxSubseqSum1(a,9)<<endl;
    cout<<MaxSubseqSum2(a,9)<<endl;
    return 0;
}
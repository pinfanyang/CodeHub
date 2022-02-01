#include<bits/stdc++.h>
using namespace std;
//������
int MaxSubseqSum(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j;
    for(i=0;i<N;i++)        //iΪ�������λ��
    {
        ThisSum=0;          //ThisSumΪ��A[i]��A[j]�����к�
        for(j=i;j<N;j++)    //jΪ�����Ҷ�λ��
        {
            ThisSum+=A[j];  //����ͬһ��i����ͬj��ֻ��j-1��ѭ���������ۼ�1���
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }                   //jѭ������
    }                       //iѭ������
    return MaxSum;
}

//���η�
/* ����3�������е����ֵ */
int Max3( int A, int B, int C )
{ 
    return A > B ? A > C ? A : C : B > C ? B : C;
}
/* ���η���List[left]��List[right]��������к� */
int DivideAndConquer( int List[], int left, int right )
{ 
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/
    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )   /* �ݹ����ֹ����������ֻ��1������ */
    {
        if( List[left] > 0 )  
            return List[left];
        else 
            return 0;
    }

    /* ������"��"�Ĺ��� */

    center = ( left + right ) / 2;  /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; 
    LeftBorderSum = 0;
    for( i=center; i>=left; i-- )       /* ����������ɨ�� */
    { 
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for( i=center+1; i<=right; i++ )    /* ����������ɨ�� */
    { 
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    }

    /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum1( int List[], int N )
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
    return DivideAndConquer( List, 0, N-1 );
}

//�ۻ������㷨
int MaxSubseqSum2(int A[],int N)
{
    int ThisSum,MaxSum;
    ThisSum=MaxSum=0;
    for(int i=0;i<N;i++)
    {
        ThisSum+=A[i];      //�����ۼ�
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;     //���ָ��������µ�ǰ���
        else
            if(ThisSum<0)
                ThisSum=0;      //��������ǰ��С������
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
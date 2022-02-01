#include<bits/stdc++.h>
using namespace std;
#define N 10
//�ϲ�����
void Merge(int A[],int low,int mid,int high)
{
    int i=low,j=mid+1,T[N],k=0;
    while(i<=mid && j<=high)            //���߷ֱ�Ƚ�
    {
        if(A[i]<=A[j])
            T[k++]=A[i++];
        else
            T[k++]=A[j++];
    }
    if(i==mid+1)                       //��߸պ�ȫ����������õ����飬����������������
    {
        while(j<=high)
            T[k++]=A[j++];
    }
    else
    {
        while(i<=mid)                 //i�ǲ����ܴ���mid�ģ����Ƚ�n/2��
            T[k++]=A[i++];
    }
    for(i=low,k=0;i<=high;i++,k++)
        A[i]=T[k];
}

//�ݹ�������
int  MergeSort(int  A[],int left,int right)
{
    if(left>=right)
        return 0;               //��ֹ������ֻ��һ����
    int mid=floor((left+right)/2);
    MergeSort(A,left,mid);
    MergeSort(A,mid+1,right);
    Merge(A,left,mid,right);
}


int main()
{
    int A[10]={1,4,3,2,5,9,8,7,6,10};
    MergeSort(A,0,9);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    return 0;

}
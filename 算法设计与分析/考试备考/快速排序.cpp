#include<bits/stdc++.h>
using namespace std;

int Partition(int A[],int l,int r)
{
    int i=l,j=r;
    int x=A[l];
    while(i<j && A[j]>=x)   j--;        //����x������ֱ�ӷ�x�ұ߲���
    if(i<j)
    {
        A[i]=A[j];
        i++;
    }
    while(i<j && A[i]<x)    i++;       //С��x������ֱ�ӷ�x��߲���
    if(i<j)
    {
        A[j]=A[i];
        
        j--;
    }
    A[i]=x;     //����i=j������x
    return i;
}

int Quicksort(int A[],int l,int r)
{
    if(l<r)
        {
            int i=Partition(A,l,r);
            Quicksort(A,l,i-1);
            Quicksort(A,i+1,r);
        }
}

int main()
{
    int A[10]={1,4,3,2,5,9,8,7,6,10};
    Quicksort(A,0,9);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    return 0;
}

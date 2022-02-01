#include<bits/stdc++.h>
using namespace std;
int Insertion_Sort(int A[],int length)
{
    if(length==0)
        return 0;
    for(int k=1;k<length;k++)
    {
        int x=A[k];
        int j=k-1;
        while(j>=0 && A[j]>=x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }   
}

int main()
{
    int a[10]={5,4,3,1,6,8,7,9,10,2};
    Insertion_Sort(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int Binary_search(int A[],int p,int r,int x)
//输入：待查找数组，序列初始位置，序列末尾位置，待查找元素
//输出：返回查找元素位置
{
    if(p>r)
        return -1;      
    int midpoint=floor((p+r)/2); 
    if(A[midpoint]==x)
        return midpoint;
    else 
    {
        if(x<A[midpoint])
            Binary_search(A,p,midpoint-1,x);      //x在midpoint的左边
        else
            Binary_search(A,midpoint+1,r,x);
    }            
}

int main()
{
    int a[9]={1,2,3,4,5,6,7,8,9};
    cout<<Binary_search(a,0,9,4)<<endl;
    cout<<Binary_search(a,4,9,1)<<endl;
    return 0;
}
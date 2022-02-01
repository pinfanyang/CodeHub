#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char A,char B,char C)
{
    if(1==n)    cout<<A<<"-->"<<C<<endl;        //直接A到C柱
    else
    {
        hanoi(n-1,A,C,B);           //把上面n-1个移动到B柱
        cout<<A<<"-->"<<C<<endl;    //输出
        hanoi(n-1,B,A,C);           //把剩下n-1个从B柱移动到C柱
    }

}

int main()
{
    int n;
    cout<<"please input the number:";
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;   
}
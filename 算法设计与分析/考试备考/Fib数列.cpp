#include<bits/stdc++.h>
using namespace std;
//�ݹ����
int FibR(int n)
{
    if(n<=1)    return n;
    return FibR(n-1)+FibR(n-2);
}

//��̬�滮
int Fib_DP(int n)
{
    if(n<=1)    return n;
    int cur,prev1=0,prev2=1;
    for(int i=2;i<=n;i++)
    {
        cur=prev1+prev2;
        prev1=prev2;
        prev2=cur;
    }
    return cur;
}

int main()
{
    cout<<"�ݹ����"<<endl;
    for(int i=0;i<10;i++)
        cout<<FibR(i)<<" ";
    cout<<endl<<"��̬�滮"<<endl;
    for(int i=0;i<10;i++)
        cout<<Fib_DP(i)<<" ";
    return 0;
}
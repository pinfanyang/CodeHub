#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int D[MAX][MAX],num;

int MaxSum(int num)
{
    int i,j;
    for(i=num-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
            D[i][j]=max(D[i+1][j],D[i+1][j+1])+D[i][j];
    }
    return D[1][1];
}

int main()
{
    int i,j;
    cin>>num;           //输入三角形的行数
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
            cin>>D[i][j];
    }
    cout<<MaxSum(num)<<endl;
    return 0;
}
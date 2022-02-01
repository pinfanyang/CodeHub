#include<bits/stdc++.h>
using namespace std;
//GREEDY-KNAPSACK算法
void KNAPSACK(int n,float c,float v[],float w[],float x[])
//v,w分别含有按v[i]/w[i] >= v[i+1]/w[i+1] 排序的n件物品的价值和重量
//c为背包容量，x为解向量
{
    int i;
    for(i=1;i<=n;i++)   x[i]=0;     //解向量初始化为0
    float cu=c;         //背包剩余容量
    for(i=1;i<=n;i++)
    {
        if(w[i]>cu) break;
        x[i]=1;
        cu=cu-w[i];
    }
    if(i<=n)   x[i]=cu/w[i];
}
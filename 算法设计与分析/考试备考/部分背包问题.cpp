#include<bits/stdc++.h>
using namespace std;
//GREEDY-KNAPSACK�㷨
void KNAPSACK(int n,float c,float v[],float w[],float x[])
//v,w�ֱ��а�v[i]/w[i] >= v[i+1]/w[i+1] �����n����Ʒ�ļ�ֵ������
//cΪ����������xΪ������
{
    int i;
    for(i=1;i<=n;i++)   x[i]=0;     //��������ʼ��Ϊ0
    float cu=c;         //����ʣ������
    for(i=1;i<=n;i++)
    {
        if(w[i]>cu) break;
        x[i]=1;
        cu=cu-w[i];
    }
    if(i<=n)   x[i]=cu/w[i];
}
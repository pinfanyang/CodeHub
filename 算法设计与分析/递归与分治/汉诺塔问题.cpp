#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char A,char B,char C)
{
    if(1==n)    cout<<A<<"-->"<<C<<endl;        //ֱ��A��C��
    else
    {
        hanoi(n-1,A,C,B);           //������n-1���ƶ���B��
        cout<<A<<"-->"<<C<<endl;    //���
        hanoi(n-1,B,A,C);           //��ʣ��n-1����B���ƶ���C��
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
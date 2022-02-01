#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if(0==n)
        return 1;
    return n*factorial(n-1);
}

int fibonacci(int n)
{
    if(n<=1)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    cout<<"Please input the number:";
    cin>>n;
    cout<<"the answer is:"<<factorial(n)<<endl<<"the Fibonacci list is:"<<endl;
    for(int i=0;i<n;i++)
    {
        if((i+1)%11==0)     cout<<endl;
        printf("%-5d",fibonacci(i));
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
  int currVal=0,val=0;  //分别为正在统计的数字，将要读入的新值
  if(cin>> currVal)
  {
    int cnt=1;  //当前数字个数
    while(cin>> val)
    {
      if(val==currVal)
        ++cnt;
      else
      {
        cout<<currVal<<"\toccurs\t"<<cnt<<"\ttimes"<<endl;
        currVal=val;  //记录新值
        cnt=1;
      }
    }
    cout<<currVal<<"\toccurs\t"<<cnt<<"\ttimes"<<endl;  //最后一个数字
  }
  return 0;
}
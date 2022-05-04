//顺序栈的实现
#include<bits/stdc++.h>

#define MaxSize 50
typedef int ElemType;
//栈定义
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;     //初始化栈指针，指向-1
}

//判断栈空
bool StackEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}

//进栈
bool Push(SqStack &S,ElemType x)
{
    if(S.top == MaxSize-1)
        return false;   //栈满，报错
    S.data[++S.top] = x;    //指针+1，新数据入栈
    return true;
}

//出栈
bool Pop(SqStack &S,ElemType &x)        //x带回
{
    if(S.top == -1)     //栈空，报错
        return  false;
    x = S.data[S.top--];    //待回值，指针再-1
    return true;
}

//读栈顶元素
bool GetTop(SqStack S,ElemType &x)      //x带回
{
    if(S.top == -1) 
        return false;
    x = S.data[S.top];
    return true;
}

ElemType x = 0;
int main()
{
    SqStack S;
    InitStack(S);
    printf("栈空判断：%d\n", StackEmpty(S));
    //cout << "栈空判断：" << StackEmpty(S) << endl;
    for(int i = 0;i < 10; i++)
    {
        Push(S,i);
        GetTop(S,x);
        printf("入栈操作，当前入栈元素：%d\n",x);
        //cout << "入栈操作，当前入栈元素：" << x << endl;
    }
    printf("栈空判断：%d\n", StackEmpty(S));
    //cout << "栈空判断：" << StackEmpty(S) << endl;
    for(int i = 0;i < 10; i++)
    {
        Pop(S,x);
        printf("出栈操作，当前出栈元素：%d\n",x);
        //cout << "出栈操作，当前出栈元素：" << x << endl;
    }   
    printf("栈空判断：%d\n", StackEmpty(S));
    //cout << "栈空判断：" << StackEmpty(S) << endl;
    return 0;
}
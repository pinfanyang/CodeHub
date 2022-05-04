//链栈的实现
#include<bits/stdc++.h>
typedef int ElemType;

//栈定义
typedef struct Stacknode
{
    ElemType data;              //数据域
    struct Stacknode *next;      //指针域
}Stacknode,*LinkStack;


//链栈初始化：不带头结点
bool Stack_Init(LinkStack &S)
{
    S = NULL;
    return true;
}

//进栈
bool Push(LinkStack &S,ElemType e)
{
    Stacknode *p = (Stacknode *)malloc(sizeof(Stacknode));   //生成新结点
    p->data = e;
    p->next = S;    //反着指向链表的top
    S = p;  //修改栈顶指针

    return true;
}

//出栈
bool Pop(LinkStack &S,ElemType &e)  //e带回
{
    if(S == NULL)   return false;
    e = S->data;
    Stacknode *tp = (Stacknode *)malloc(sizeof(Stacknode)); //临时结点
    tp = S;  //保存栈顶元素空间
    S = S->next;    //修改栈顶指针
    free(tp);       //释放原栈顶元素的空间

    return true;
}

//获取栈顶元素
ElemType GetTop(LinkStack S)
{
    if(S != NULL)
        return S->data;
}

//判断栈空
bool StackEmpty(LinkStack S)
{
    if(S != NULL)
        return false;
    else
        return true;
}

ElemType x = 0;
int main()
{
    LinkStack S;
    Stack_Init(S);
    printf("栈空判断：%d\n", StackEmpty(S));
    //cout << "栈空判断：" << StackEmpty(S) << endl;
    for(int i = 0;i < 10; i++)
    {
        Push(S,i);
        x = GetTop(S);
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




//链式队列的实现

#include "bits/stdc++.h"

typedef int ElemType;

//结点定义
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

//队列定义
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//初始化队列-带头结点
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));    //初始头、尾指针都指向头结点，头结点用来存储长度
    Q.front->next = NULL;
    Q.front->data = 0;
}

//判断队列空
bool IsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return  true;
    else    
        return false;
}

//判断队列满
//链栈不存在

//求队长
int QueueLength(LinkQueue Q)
{
    return Q.front->data;
}

//入队列
void EnQueue(LinkQueue &Q,ElemType x)
{
    LinkNode *s =  (LinkNode *)malloc(sizeof(LinkNode)); 
    s->data = x;
    s->next = NULL; //插尾部，最后一个结点，必为NULL
    Q.rear->next = s;   //新结点插入到rear之后
    Q.rear = s; //修改表尾指针
    Q.front->data++;
}

//出队列
bool DeQueue(LinkQueue &Q,ElemType &x)
{
    if(IsEmpty(Q))
        return false;

    LinkNode *p = Q.front->next;
    x = p->data;    //x带回
    Q.front->next = p->next;//修改头指针的next指针
    if(Q.rear == p) //最后一个结点
        Q.rear = Q.front;   //修改尾指针
    free(p);
    Q.front->data--;

    return true;
}

//获取队列头
bool GetHead(LinkQueue Q,ElemType &x)
{
    if(!IsEmpty(Q))
    {
        x = Q.front->next->data;
        return true;
    }
    else
        return  false;
}


ElemType x;
int main()
{
    LinkQueue Q;
    InitQueue(Q);
    printf("队列空：%d\n",IsEmpty(Q));
    for(int i = 0;i < 10;i++)
    {
      EnQueue(Q,i);
      printf("入队列：%d--当前队列长度：%d--",i,QueueLength(Q));
      if(GetHead(Q,x))      
        printf("当前队列头：%d\n",x);            
    }
    printf("队列空：%d\n",IsEmpty(Q));
    for(int i = 0;i < 10;i++)
    {
      if(GetHead(Q,x))      
        printf("当前队列头：%d--当前队列长度：%d--",x,QueueLength(Q));
      if(DeQueue(Q,x))
        printf("出队列：%d\n",x);   
    }
    printf("队列空：%d\n",IsEmpty(Q));

    return 0;
}










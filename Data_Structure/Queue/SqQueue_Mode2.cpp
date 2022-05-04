//顺序队列：循环队列
//Mode2：在队列中增加统计元素的结构体成员

#include<bits/stdc++.h>
#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front,rear; //头指针、尾指针
    int size;   //队列长度
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
    Q.size = 0;
}

//判断队空
bool QueueEmpty(SqQueue Q)
{
    if(Q.size == 0)
        return true;
    else
        return false;
}

//判断队满
bool QueueFull(SqQueue Q)
{
    if(Q.size == MaxSize)  
        return true;
    else
        return false;
}
//队列长度
int QueueLength(SqQueue Q)
{
    return Q.size;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if(Q.size == MaxSize)   //队满：Mode1
        return false;
    Q.size++;
    Q.data[Q.rear] = x; //将x插入队尾
    Q.rear = (Q.rear + 1) % MaxSize;    //队尾指针后移
    return true;
}

//出队
//删除队头元素，x带回
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.size == 0)
        return false;
    Q.size--;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//获取队头元素的值
bool GetHead(SqQueue Q,ElemType &x)
{
    if(Q.size == 0)
        return false;
    x = Q.data[Q.front];
    return true;
}

ElemType x;
int main()
{
    SqQueue Q;
    InitQueue(Q);
    printf("队列空：%d",QueueEmpty(Q));
    printf("队列满：%d\n",QueueFull(Q));
    for(int i = 0;i < 10;i++)
    {
      if(EnQueue(Q,i))
        printf("入队列：%d--当前队列长度：%d--",i,QueueLength(Q));
      if(GetHead(Q,x))      
        printf("当前队列头：%d\n",x);            
    }
    printf("队列空：%d",QueueEmpty(Q));
    printf("队列满：%d\n",QueueFull(Q));
    for(int i = 0;i < 10;i++)
    {
      if(GetHead(Q,x))      
        printf("当前队列头：%d--当前队列长度：%d--",x,QueueLength(Q));
      if(DeQueue(Q,x))
        printf("出队列：%d\n",x);   
    }
    printf("队列空：%d",QueueEmpty(Q));
    printf("队列满：%d\n",QueueFull(Q));

    return 0;
}






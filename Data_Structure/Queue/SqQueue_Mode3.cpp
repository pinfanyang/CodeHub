//顺序队列：循环队列
//Mode3：在队列结构体中增加tag标志位

#include<bits/stdc++.h>
#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front,rear; //头指针、尾指针
    bool tag;   //出入队列标志位 出0 入1  用于判断队列空满的情况 这样不会浪费最后一个数据元素
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}

//判断队空
bool QueueEmpty(SqQueue Q)
{
    if((Q.rear == Q.front) && (Q.tag == false))
        return true;
    else
        return false;
}

//判断队满
bool QueueFull(SqQueue Q)
{
    if((Q.front == Q.rear) && (Q.tag == true))
        return true;
    else
        return false;
}
//队列长度
int QueueLength(SqQueue Q)
{
    if(QueueFull(Q))
        return MaxSize;
    else   
        return (Q.rear + MaxSize - Q.front) % MaxSize;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.front == Q.rear) && (Q.tag == true))
        return false;
    Q.tag = true;
    Q.data[Q.rear] = x; //将x插入队尾
    Q.rear = (Q.rear + 1) % MaxSize;    //队尾指针后移 取模运算 使数据变成环状（映射范围：0-maxsize-1）
    return true;
}

//出队
//删除队头元素，x带回
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if((Q.rear == Q.front) && (Q.tag == false))
        return true;
    Q.tag = false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//获取队头元素的值
bool GetHead(SqQueue Q,ElemType &x)
{
    if((Q.front == Q.rear) && (Q.tag == true))
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






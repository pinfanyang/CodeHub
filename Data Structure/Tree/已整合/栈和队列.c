#include"consts.h"
#include"二叉树.c"
#define MAX 100
#define MAXLEN 100
#define NLAYER 4
#define MAXSIZE 100

//栈
typedef struct stack             
{
	BTree Data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;
//队列
typedef struct                  
{
    BTree Data[MAXSIZE];
    int Front,Rear;
}SeqQuene,*PSeqQuene;

/***********************************************************************************************************/

/***************************************栈和队列的功能实现***************************************************/
//1_1.初始化栈
PSeqStack SeqStack_Init()
{
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(S)
	{
		S->top=-1;
	}
	return S;
}
//1_2.判断栈空
int SeqStack_Empty(PSeqStack S)
{
	return (S->top==-1);
}
//1_3.入栈
int SeqStack_Push(PSeqStack S,BTree x)
{
    if(S->top==MAXSIZE-1)
        return 0;                           //栈满
    else
    {
        S->top++;
        S->Data[S->top]=x;
        return 1;
    }
}
//1_4.出栈
int SeqStack_Pop(PSeqStack S,BTree *x)
{
	if(SeqStack_Empty(S))
    {
        return 0;
    }
    else
    {
        *x=S->Data[S->top];
        S->top--;
        return 1;
    }
}

//2_1.队列初始化
PSeqQuene Quene_Init()
{
    PSeqQuene Q;
    Q=(PSeqQuene)malloc(sizeof(SeqQuene));
    if(Q)
    {
        Q->Front=0;
        Q->Rear=0;
    }
    return Q;
}
//2_2.判断队列空
int Quene_Empty(PSeqQuene Q)
{
    if(Q&&Q->Front==Q->Rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
//2_3.入队列
int Quene_In(PSeqQuene Q,BTree x)
{
    if((Q->Rear+1)%MAXSIZE==Q->Front)
    {
        printf("队列已满");
        return -1;
    }
    else
    {
        Q->Rear=(Q->Rear+1)%MAXSIZE;
        Q->Data[Q->Rear]=x;
        return 1;
    }
}
//2_4.出队列
int Quene_Out(PSeqQuene Q,BTree *t)
{
    if(Quene_Empty(Q))
    {
        printf("队列已空");
        return -1;
    }
    else
    {
	 	Q->Front=(Q->Front+1)%MAXSIZE;
		*t=Q->Data[Q->Front];
		return 1;
        
    }
}
/*******************************************************************************************************/
#include"consts.h"
#include"������.c"
#define MAX 100
#define MAXLEN 100
#define NLAYER 4
#define MAXSIZE 100

//ջ
typedef struct stack             
{
	BTree Data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;
//����
typedef struct                  
{
    BTree Data[MAXSIZE];
    int Front,Rear;
}SeqQuene,*PSeqQuene;

/***********************************************************************************************************/

/***************************************ջ�Ͷ��еĹ���ʵ��***************************************************/
//1_1.��ʼ��ջ
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
//1_2.�ж�ջ��
int SeqStack_Empty(PSeqStack S)
{
	return (S->top==-1);
}
//1_3.��ջ
int SeqStack_Push(PSeqStack S,BTree x)
{
    if(S->top==MAXSIZE-1)
        return 0;                           //ջ��
    else
    {
        S->top++;
        S->Data[S->top]=x;
        return 1;
    }
}
//1_4.��ջ
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

//2_1.���г�ʼ��
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
//2_2.�ж϶��п�
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
//2_3.�����
int Quene_In(PSeqQuene Q,BTree x)
{
    if((Q->Rear+1)%MAXSIZE==Q->Front)
    {
        printf("��������");
        return -1;
    }
    else
    {
        Q->Rear=(Q->Rear+1)%MAXSIZE;
        Q->Data[Q->Rear]=x;
        return 1;
    }
}
//2_4.������
int Quene_Out(PSeqQuene Q,BTree *t)
{
    if(Quene_Empty(Q))
    {
        printf("�����ѿ�");
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
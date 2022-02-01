#include"consts.h"
#define MAX 100
#define MAXLEN 100
#define NLAYER 4
#define MAXSIZE 100
/**********************************************������������ṹ��********************************************/
//��ʽ�ṹ
typedef struct  bnode {
    char data;
    struct bnode *lchild,*rchild;
}Bnode, *BTree;

//˳��ṹ

//˫����ṹ


typedef struct stack             //ջ
{
	BTree Data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;

typedef struct                  //����
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

/**********************************************����������********************************************/
//�Զ�������洢		
//printf("����������������һ�����������ս����#���룬����Ҷ�ӽ��ĺ��ӣ���AB##C##��ʾһ����������abc��\n");
BTree CreateBinTree0()       //�Լ���ս��������������룬�����������	 ���ַ���Ҫ��Ҫ�Ѷ������Ľ��ȫ�������������һ��Ҷ�ӽ�㣬�亢�Ӿ�Ҫ��#����
{
	
	BTree t;
    char ch;
	scanf("%c",&ch);
	if (ch == '#')								//��#��ʾ�ս��
		t = NULL;
	else
	{
		t = (Bnode*)malloc(sizeof(Bnode));        //���ɽ��ռ�
		t->data = ch;
		t->lchild = CreateBinTree0();
		t->rchild = CreateBinTree0();
	}
    return t;
}

//�ǵݹ鷽������������		����bug������ 2020.11.23
BTree CreateBinTree1()
{
	BTree Q[MAXLEN];
	char ch;
	int front, rear;
	BTree s,root;
	root = NULL;
	front = 1; rear = 0;  /* ���г�ʼ�� */

	printf("\t�밴 ���˳�� ��������������(��ABCEDFG@)��\n\t(ע���ս����'#'��ʾ������������'@'������\n");
	ch = getchar();
	while (ch != '@')
	{
		s = NULL;
		if (ch != '#')
		{
			s = (Bnode*)malloc(sizeof(Bnode));	/* �����½�� */
			s->data	= ch;
			s->lchild = NULL;
			s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;				/* �ս����½�㶼��� */
		if (rear == 1)
			root = s;				/* rear��1���Ǹ���㣬��rootָ���� */
		else
		{
			if (s && Q[front])		/* ��ǰ����˫�׽�㶼�ǿ� */
		
				if (rear % 2 == 0)	/* rear��ż�����½��Ϊ˫�׵����� */
					Q[front]->lchild = s;
				else				/* rear���������½��Ϊ˫�׵��Һ��� */
					Q[front]->rchild = s;
			if (rear % 2 == 1)
				front++;			/* rear��������ͷָ��frontָ����һ��˫��*/
		}
		ch = getchar();
	}
	return root;
}

//�Թ�������ʽ����������		
void CreateBinTree2(Bnode * &b, char *str)	//����������
{
	Bnode *St[MAXLEN], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;					//�����Ķ�������ʼʱΪ��
	ch = str[j];		
	while (ch != '\0')			//strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;			//Ϊ���ӽڵ�
		case ')':top--; break;
		case ',':k = 2; break;                      		//Ϊ�Һ��ӽڵ�
		default:p = (Bnode*)malloc(sizeof(Bnode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 			//*pΪ�������ĸ��ڵ�
				b = p;
			else  											//�ѽ������������ڵ�
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

/**************************************************************************************************/

/**********************************************�ݹ�����㷨********************************************/
void Visit(char ch)
{
    printf("%c", ch);
}

/*�ȡ��С�������˳��ݹ�����㷨*/
void PreOrder(BTree t)             //��������ݹ��㷨
{
    if (t)
    {
        Visit(t->data);        //���ʽ������
        PreOrder(t->lchild);    //����������
        PreOrder(t->rchild);    //����������
    }
}

void InOrder(BTree t)               //��������ݹ��㷨
{
    if (t)
    {
        InOrder(t->lchild);
        Visit(t->data);
        InOrder(t->rchild);
    }
}

void PostOrder(BTree t)            //��������ݹ��㷨
{
    if (t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        Visit(t->data);
    }
}

/**************************************************************************************************/

/**********************************************�ǵݹ�����㷨********************************************/
//��������ǵݹ�
void EnPreOrder(BTree t)
{
	PSeqStack S;
	BTree p=t;
	S=SeqStack_Init();
	while (p||!SeqStack_Empty(S))
	{
		if(p)
		{
			Visit(p->data);
			SeqStack_Push(S,p);
			p=p->lchild;
		}
		else
		{
			SeqStack_Pop(S,&p);
			p=p->rchild;
		}
	}
}

//��������ǵݹ�
void EnInOrder(BTree t)
{
	PSeqStack S;
	BTree p=t;
	S=SeqStack_Init();
	while (p||!SeqStack_Empty(S))
	{
		if(p)
		{
			SeqStack_Push(S,p);
			p=p->lchild;
		}
		else
		{
			SeqStack_Pop(S,&p);
			Visit(p->data);
			p=p->rchild;
		}
	}
}

//��������ǵݹ�
void EnPostOrder(BTree t)
{
	PSeqStack S1;
	PSeqStack S2;
	BTree p=t;
	S1=SeqStack_Init();
	S2=SeqStack_Init();
	while (p||!SeqStack_Empty(S2))
	{
		if(p)
		{
			SeqStack_Push(S1,p);
			SeqStack_Push(S2,p);
			p=p->rchild;
		}
		else
		{
			SeqStack_Pop(S2,&p);
			p=p->lchild;
		}
	}
	while(!SeqStack_Empty(S1))
	{
		SeqStack_Pop(S1,&p);
		Visit(p->data);
	}
}

//��α���			
void LevelOrder(BTree t)
{
	PSeqQuene S;
	S=Quene_Init();
	if(t)
	{
		Quene_In(S,t);
	}
	while(!Quene_Empty(S))
	{
		Quene_Out(S,&t);
		Visit(t->data);
		if(t->lchild!=NULL)
		{
			Quene_In(S,t->lchild);
		}
		if(t->rchild!=NULL)
		{
			Quene_In(S,t->rchild);
		}
	}
}


/*******************************************************************************************************/


/**********************************************���ܲ��ֵ��㷨ʵ��********************************************/
//0.�ͷŶ������ڴ�
void Destroy(BTree T)
{
    if(T)
    {
        Destroy(T->lchild);
        Destroy(T->rchild);
        free(T);
    }
}
//1.�ݹ��㷨�������������������
int BTreeDepthPost(BTree t) 
{
	int hl, hr, max;
	if (t)
	{
		hl = BTreeDepthPost(t->lchild);  /* ������������� */
		hr = BTreeDepthPost(t->rchild);  /* ������������� */
		max = hl > hr ? hl : hr;          /* �õ�����������Ƚϴ���*/
		return max + 1;					  /* ����������� */
	}
	else
		return 0;						 /* ����ǿ������򷵻�0 */
}

//2.�Թ�������ʽ�����ӡ������
void DispBTree(Bnode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");						//�к��ӽڵ�ʱ�����(
			DispBTree(b->lchild);				//�ݹ鴦��������
			if (b->rchild != NULL) printf(",");	//���Һ��ӽڵ�ʱ�����,
			DispBTree(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽڵ�ʱ�����)
		}
	}
}

//3.��Ҷ�ӽ�����
int leafs(Bnode *b)
{
       int num1,num2;
       if(b==NULL)  
	   		return (0);
       else if(b->lchild==NULL && b->rchild==NULL) 
	   		return (1);
       else
        {
	        num1=leafs(b->lchild);
            num2=leafs(b->rchild);
            return(num1+num2);
        }

}

//4.���������������н�����������
BTree swap(BTree p)
{
       BTree stack[MAX];
       int k=0;
       stack[k]=NULL;
       if(p!=NULL)
       {
              stack[++k]=p->lchild;
              p->lchild=p->rchild;
              p->rchild=stack[k];
              p->lchild=swap(p->lchild);
              p->rchild=swap(p->rchild);
       }
       return p;
}

//5.���������
int Count(BTree t)
{
	int lcount,rcount;
	if(t==NULL)	return 0;
	lcount=Count(t->lchild);
	rcount=Count(t->rchild);
	return lcount+rcount+1;
}
/*
//6.����˳��洢�ṹ��Ҷ�ӽ������		//����֤
int LeftNode(BTree T,int i)		
{
	int num1,num2,num3=0;
	if(i<MAXLEN)
	{
		if (T[i]!='#')
		{
			if (T[2*i]=='#' && T[2*i+1]=='#')
			{
				num3++;			//Ҷ�ӽ�����+1
			}
			else
			{
				num1=LeftNode(T,2*i);
				num2=LeftNode(T,2*i+1);
				num3+=num1+num2;
			}
			return num3;
		}
		else 
			return 0;
	}
	else
	{
		return 0;
	}
	
}
*/
//7.��������״��ӡ�Ķ�����	�����ӡ
void TranslevelPrint(BTree t)
{
	struct node
	{
		BTree vec[MAXSIZE];			//��������
		int layer[MAXSIZE];			//������ڵĲ���
		int locate[MAXSIZE];		//��ӡ���λ��
		int front,rear;
	}q;								//�������q
	int i,j,k;
	int nLocate;
	j=1;
	k=0;
	q.front=0;					
	q.rear=0;						//��ʼ������q��ͷ����β
	q.vec[q.rear] = t;				//������������������
	q.layer[q.rear] = 1;
	q.locate[q.rear] = 20;
	q.rear = q.rear + 1;
	while(q.front < q.rear)
	{
		t = q.vec[q.front];
		i = q.layer[q.front];        
		nLocate = q.locate[q.front];
		if(j < i)					//�����ӡʱ����
		{
			printf("\n");
			printf("\n");
			j = j + 1;			
			k = 0;
			while(k < nLocate)
			{
				printf(" ");
				k++;
			}
		}
		while(k < (nLocate-1))		//���ý����ȿ��ƺ���λ��
		{
			printf(" ");
			k++;
		}
		printf("%c",t->data);
		q.front = q.front + 1;
		if(t->lchild != NULL)		// �����������������������ڵ������
		{		
			q.vec[q.rear] = t->lchild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate - pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
		if(t->rchild != NULL)		// �����������������������ڵ������
		{		
			q.vec[q.rear] = t->rchild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate + pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
	}
}

//8.���Ҷ�ӽ��,������������������Ҷ�ӽ��, rootΪָ�������������ָ��
void  PreOrderLeaf(BTree root) 
{
	if (root!=NULL)
	{
		if (root->lchild==NULL && root->rchild==NULL)
			Visit(root->data);   		  // ���Ҷ�ӽ��
		PreOrderLeaf(root->lchild);      // �������������
		PreOrderLeaf(root->rchild);      // �������������
	}
}

/**********************************************************************************************************/

#include"consts.h"
#define MAX 100
#define MAXLEN 100
#define NLAYER 4
#define MAXSIZE 100
/**********************************************定义二叉树结点结构体********************************************/
//链式结构
typedef struct  bnode {
    char data;
    struct bnode *lchild,*rchild;
}Bnode, *BTree;

//顺序结构

//双链表结构


typedef struct stack             //栈
{
	BTree Data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;

typedef struct                  //队列
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

/**********************************************创建二叉树********************************************/
//以二叉链表存储		
//printf("请以先序序列输入一个二叉树，空结点以#输入，包括叶子结点的孩子，如AB##C##表示一个满二叉树abc：\n");
BTree CreateBinTree0()       //以加入空结点的先序序列输入，构造二叉链表	 该种方法要求，要把二叉树的结点全输满，包括最后一排叶子结点，其孩子均要用#输入
{
	
	BTree t;
    char ch;
	scanf("%c",&ch);
	if (ch == '#')								//以#表示空结点
		t = NULL;
	else
	{
		t = (Bnode*)malloc(sizeof(Bnode));        //生成结点空间
		t->data = ch;
		t->lchild = CreateBinTree0();
		t->rchild = CreateBinTree0();
	}
    return t;
}

//非递归方法建立二叉树		存在bug，待修 2020.11.23
BTree CreateBinTree1()
{
	BTree Q[MAXLEN];
	char ch;
	int front, rear;
	BTree s,root;
	root = NULL;
	front = 1; rear = 0;  /* 队列初始化 */

	printf("\t请按 逐层顺序 依次输入结点序列(如ABCEDFG@)：\n\t(注：空结点用'#'表示，输入序列以'@'结束）\n");
	ch = getchar();
	while (ch != '@')
	{
		s = NULL;
		if (ch != '#')
		{
			s = (Bnode*)malloc(sizeof(Bnode));	/* 申请新结点 */
			s->data	= ch;
			s->lchild = NULL;
			s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;				/* 空结点和新结点都入队 */
		if (rear == 1)
			root = s;				/* rear是1，是根结点，用root指向它 */
		else
		{
			if (s && Q[front])		/* 当前结点和双亲结点都非空 */
		
				if (rear % 2 == 0)	/* rear是偶数，新结点为双亲的左孩子 */
					Q[front]->lchild = s;
				else				/* rear是奇数，新结点为双亲的右孩子 */
					Q[front]->rchild = s;
			if (rear % 2 == 1)
				front++;			/* rear是奇数，头指针front指向下一个双亲*/
		}
		ch = getchar();
	}
	return root;
}

//以广义表的形式建立二叉树		
void CreateBinTree2(Bnode * &b, char *str)	//创建二叉树
{
	Bnode *St[MAXLEN], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;					//建立的二叉树初始时为空
	ch = str[j];		
	while (ch != '\0')			//str未扫描完时循环
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;			//为左孩子节点
		case ')':top--; break;
		case ',':k = 2; break;                      		//为右孩子节点
		default:p = (Bnode*)malloc(sizeof(Bnode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 			//*p为二叉树的根节点
				b = p;
			else  											//已建立二叉树根节点
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

/**********************************************递归遍历算法********************************************/
void Visit(char ch)
{
    printf("%c", ch);
}

/*先、中、后三种顺序递归遍历算法*/
void PreOrder(BTree t)             //先序遍历递归算法
{
    if (t)
    {
        Visit(t->data);        //访问结点内容
        PreOrder(t->lchild);    //遍历左子树
        PreOrder(t->rchild);    //遍历右子树
    }
}

void InOrder(BTree t)               //中序遍历递归算法
{
    if (t)
    {
        InOrder(t->lchild);
        Visit(t->data);
        InOrder(t->rchild);
    }
}

void PostOrder(BTree t)            //后序遍历递归算法
{
    if (t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        Visit(t->data);
    }
}

/**************************************************************************************************/

/**********************************************非递归遍历算法********************************************/
//先序遍历非递归
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

//中序遍历非递归
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

//后序遍历非递归
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

//层次遍历			
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


/**********************************************功能部分的算法实现********************************************/
//0.释放二叉树内存
void Destroy(BTree T)
{
    if(T)
    {
        Destroy(T->lchild);
        Destroy(T->rchild);
        free(T);
    }
}
//1.递归算法后序遍历求二叉树的深度
int BTreeDepthPost(BTree t) 
{
	int hl, hr, max;
	if (t)
	{
		hl = BTreeDepthPost(t->lchild);  /* 求左子树的深度 */
		hr = BTreeDepthPost(t->rchild);  /* 求右子树的深度 */
		max = hl > hr ? hl : hr;          /* 得到左、右子树深度较大者*/
		return max + 1;					  /* 返回树的深度 */
	}
	else
		return 0;						 /* 如果是空树，则返回0 */
}

//2.以广义表的形式输出打印二叉树
void DispBTree(Bnode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");						//有孩子节点时才输出(
			DispBTree(b->lchild);				//递归处理左子树
			if (b->rchild != NULL) printf(",");	//有右孩子节点时才输出,
			DispBTree(b->rchild);				//递归处理右子树
			printf(")");						//有孩子节点时才输出)
		}
	}
}

//3.求叶子结点个数
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

//4.交换二叉树的所有结点的左右子树
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

//5.计算结点个数
int Count(BTree t)
{
	int lcount,rcount;
	if(t==NULL)	return 0;
	lcount=Count(t->lchild);
	rcount=Count(t->rchild);
	return lcount+rcount+1;
}
/*
//6.对于顺序存储结构的叶子结点数求法		//待验证
int LeftNode(BTree T,int i)		
{
	int num1,num2,num3=0;
	if(i<MAXLEN)
	{
		if (T[i]!='#')
		{
			if (T[2*i]=='#' && T[2*i+1]=='#')
			{
				num3++;			//叶子结点个数+1
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
//7.按竖向树状打印的二叉树	按层打印
void TranslevelPrint(BTree t)
{
	struct node
	{
		BTree vec[MAXSIZE];			//存放树结点
		int layer[MAXSIZE];			//结点所在的层数
		int locate[MAXSIZE];		//打印结点位置
		int front,rear;
	}q;								//定义队列q
	int i,j,k;
	int nLocate;
	j=1;
	k=0;
	q.front=0;					
	q.rear=0;						//初始化队列q队头，队尾
	q.vec[q.rear] = t;				//将二叉树根结点入队列
	q.layer[q.rear] = 1;
	q.locate[q.rear] = 20;
	q.rear = q.rear + 1;
	while(q.front < q.rear)
	{
		t = q.vec[q.front];
		i = q.layer[q.front];        
		nLocate = q.locate[q.front];
		if(j < i)					//进层打印时换行
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
		while(k < (nLocate-1))		//利用结点深度控制横向位置
		{
			printf(" ");
			k++;
		}
		printf("%c",t->data);
		q.front = q.front + 1;
		if(t->lchild != NULL)		// 存在左子树，将左子树根节点入队列
		{		
			q.vec[q.rear] = t->lchild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate - pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
		if(t->rchild != NULL)		// 存在右子树，将右子树根节点入队列
		{		
			q.vec[q.rear] = t->rchild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate + pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
	}
}

//8.输出叶子结点,先序遍历二叉树并输出叶子结点, root为指向二叉树根结点的指针
void  PreOrderLeaf(BTree root) 
{
	if (root!=NULL)
	{
		if (root->lchild==NULL && root->rchild==NULL)
			Visit(root->data);   		  // 输出叶子结点
		PreOrderLeaf(root->lchild);      // 先序遍历左子树
		PreOrderLeaf(root->rchild);      // 先序遍历右子树
	}
}

/**********************************************************************************************************/

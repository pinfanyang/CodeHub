#include "consts.h"
typedef char DataType;
typedef struct BiThrNode/* 二叉树的二叉线索链表的存储结构 */
{
	DataType data;
	struct BiThrNode *lchild,*rchild;/* 左右孩子指针 */
	int lflag,rflag;     /* 左右标志，值为0表示指针，值为1表示线索 */
}BiThrTree;
BiThrTree *current=NULL; /* 全局变量,始终指向刚刚访问过的结点 */

BiThrTree *CreateBiThrTree()/* 按先序输入二叉线索树中结点的值,构造二叉线索树 */
{ 
	BiThrTree *t;
	DataType ch;
	scanf("%c",&ch);
	if(ch=='#')                    /* 输入结束标志 */
		exit(0);
	if(ch=='@')                    /* 空结点标志 */
		t=NULL;
	else
	{
		t=(BiThrTree *)malloc(sizeof(BiThrTree));
		if(!t)                      /* 申请空间失败就退出 */
			exit(ERROR);
		t->data=ch;                 /* 按先序序列生成根结点 */
		t->lflag=0;                 /* 初始化时指针标志均为0 */
		t->rflag=0;
		t->lchild=CreateBiThrTree();/* 递归构造左子树 */
		t->rchild=CreateBiThrTree();/* 递归构造右子树 */
	}
	return t;
}

 
void InThreading(BiThrTree *t)/* 中序遍历进行中序线索化，使用递归方法 */
{
	if(t!=NULL)
	{
		InThreading(t->lchild);   /* 递归左子树线索化 */
		if(t->lchild==NULL)
			t->lflag=1;           /* 前驱为线索 */
		if(t->rchild==NULL)
			t->rflag=1;           /* 后继为线索 */
		if(current!=NULL)         /* 前驱不空 */
		{
			if(current->rflag==1)
				current->rchild=t;/* 前驱右孩子指针指向后继，即当前结点t */
			if(t->lflag==1)
				t->lchild=current;/* 左孩子指针指向前驱 */
		}
		current=t;                /* 保持current指向t的前驱 */
		InThreading(t->rchild);   /* 递归右子树线索化 */
	}
}

void InVisitThrTree(BiThrTree *t)/* 中序遍历线索二叉树的非递归算法 */
{ 
	while(t!=NULL)                 /* 初始不为空树 */
	{ 
		while(t->lflag==0)
			t=t->lchild;
		if(t==NULL)                /* 空结点退出 */
			exit(ERROR);  
		printf("%c  ",t->data);    /* 访问前驱结点 */
		while(t->rflag==1&&t->rchild!=NULL) 
		{
			t=t->rchild;
			printf("%c  ",t->data);/* 访问后继结点 */
		}
		t=t->rchild;
	}
	printf("\n\t\t");
}

int main(int argc,char* argv[])
{
	BiThrTree *tree;
	printf("\t\t请按先序序列输入二叉树(如:ABC@@DE@G@@F@@@#)\n\t\t");
	tree=CreateBiThrTree(); /* 按先序产生二叉树 */
	InThreading(tree);      /* 中序线索化二叉树 */
	printf("\t\t按中序遍历输出线索二叉树:\n\t\t");
	InVisitThrTree(tree);   /* 中序遍历(输出)二叉线索树 */
    return 0;
}

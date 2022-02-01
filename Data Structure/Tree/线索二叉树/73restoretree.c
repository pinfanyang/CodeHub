/*利用遍历序列还原二叉树*/
#include "consts.h"
typedef char DataType;
#define MAXNUM 50 
#include "bitree.h"  /* 建立二叉树存储结构 */
#include "bitree.c"  /* 先序、中序、后序遍历二叉树 */

int Search(DataType c,DataType *order) /* 找出根结点的位置 */
{
	int i,n=strlen(order);
	for(i=0;i<n;i++)
		if(c==*(order+i)) 
			return i;   /* 查找成功返回在数组中的下标 */
    return ERROR;       /* 查找不到，返回错误 */
}

BiTree *Restore(DataType *pre,DataType *inor,int n)/* 由先序和中序恢复树 */
{ 
	int i,k;
	BiTree *p;
	DataType *r;
	if(n<=0)
		return NULL;
	p=(BiTree *)malloc(sizeof(BiTree));  /* 初始化, 申请结点 */
	p->data=*pre;
	p->lchild=NULL;
	p->rchild=NULL;
	i=Search(*pre,inor);                 /* 找到树的元素c在中序序列中的位置 */
	r=inor+i;
	k=r-inor;
	p->lchild=Restore(pre+1,inor,k);     /* 递归创建BiTree的左子树 */
	p->rchild=Restore(pre+1+k,r+1,n-1-k);/* 递归创建 BiTree的右子树 */
	return p;
}

int main(int argc,char* argv[])
{
	 BiTree *tree;
     DataType s1[MAXNUM],s2[MAXNUM];
	 printf("\t\t请输入先序序列，如：ABDCEFG\n\t\t");
     scanf("%s",s1);
     printf("\t\t请输入中序序列，如：BDAFEGC\n\t\t");
     scanf("%s",s2);    /* 输入先序序列和后中序序列二叉树 */
     tree=Restore(s1,s2,strlen(s1));
     printf("\n\t\t输出先序序列:     ");
     BiTreePreTra(tree);
     printf("\n\t\t输出中序序列:     ");
     BiTreeInTra(tree);
	 printf("\n\t\t输出后序序列:     ");
     BiTreePostTra(tree);      /* 输出先序、中序、后序三种遍历结果 */
	 printf("\n\t\t");
	 return 0;
}

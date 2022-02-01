/*���ñ������л�ԭ������*/
#include "consts.h"
typedef char DataType;
#define MAXNUM 50 
#include "bitree.h"  /* �����������洢�ṹ */
#include "bitree.c"  /* �������򡢺������������ */

int Search(DataType c,DataType *order) /* �ҳ�������λ�� */
{
	int i,n=strlen(order);
	for(i=0;i<n;i++)
		if(c==*(order+i)) 
			return i;   /* ���ҳɹ������������е��±� */
    return ERROR;       /* ���Ҳ��������ش��� */
}

BiTree *Restore(DataType *pre,DataType *inor,int n)/* �����������ָ��� */
{ 
	int i,k;
	BiTree *p;
	DataType *r;
	if(n<=0)
		return NULL;
	p=(BiTree *)malloc(sizeof(BiTree));  /* ��ʼ��, ������ */
	p->data=*pre;
	p->lchild=NULL;
	p->rchild=NULL;
	i=Search(*pre,inor);                 /* �ҵ�����Ԫ��c�����������е�λ�� */
	r=inor+i;
	k=r-inor;
	p->lchild=Restore(pre+1,inor,k);     /* �ݹ鴴��BiTree�������� */
	p->rchild=Restore(pre+1+k,r+1,n-1-k);/* �ݹ鴴�� BiTree�������� */
	return p;
}

int main(int argc,char* argv[])
{
	 BiTree *tree;
     DataType s1[MAXNUM],s2[MAXNUM];
	 printf("\t\t�������������У��磺ABDCEFG\n\t\t");
     scanf("%s",s1);
     printf("\t\t�������������У��磺BDAFEGC\n\t\t");
     scanf("%s",s2);    /* �����������кͺ��������ж����� */
     tree=Restore(s1,s2,strlen(s1));
     printf("\n\t\t�����������:     ");
     BiTreePreTra(tree);
     printf("\n\t\t�����������:     ");
     BiTreeInTra(tree);
	 printf("\n\t\t�����������:     ");
     BiTreePostTra(tree);      /* ����������򡢺������ֱ������ */
	 printf("\n\t\t");
	 return 0;
}

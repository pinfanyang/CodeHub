#include "consts.h"
typedef char DataType;
typedef struct BiThrNode/* �������Ķ�����������Ĵ洢�ṹ */
{
	DataType data;
	struct BiThrNode *lchild,*rchild;/* ���Һ���ָ�� */
	int lflag,rflag;     /* ���ұ�־��ֵΪ0��ʾָ�룬ֵΪ1��ʾ���� */
}BiThrTree;
BiThrTree *current=NULL; /* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */

BiThrTree *CreateBiThrTree()/* ��������������������н���ֵ,������������� */
{ 
	BiThrTree *t;
	DataType ch;
	scanf("%c",&ch);
	if(ch=='#')                    /* ���������־ */
		exit(0);
	if(ch=='@')                    /* �ս���־ */
		t=NULL;
	else
	{
		t=(BiThrTree *)malloc(sizeof(BiThrTree));
		if(!t)                      /* ����ռ�ʧ�ܾ��˳� */
			exit(ERROR);
		t->data=ch;                 /* �������������ɸ���� */
		t->lflag=0;                 /* ��ʼ��ʱָ���־��Ϊ0 */
		t->rflag=0;
		t->lchild=CreateBiThrTree();/* �ݹ鹹�������� */
		t->rchild=CreateBiThrTree();/* �ݹ鹹�������� */
	}
	return t;
}

 
void InThreading(BiThrTree *t)/* �����������������������ʹ�õݹ鷽�� */
{
	if(t!=NULL)
	{
		InThreading(t->lchild);   /* �ݹ������������� */
		if(t->lchild==NULL)
			t->lflag=1;           /* ǰ��Ϊ���� */
		if(t->rchild==NULL)
			t->rflag=1;           /* ���Ϊ���� */
		if(current!=NULL)         /* ǰ������ */
		{
			if(current->rflag==1)
				current->rchild=t;/* ǰ���Һ���ָ��ָ���̣�����ǰ���t */
			if(t->lflag==1)
				t->lchild=current;/* ����ָ��ָ��ǰ�� */
		}
		current=t;                /* ����currentָ��t��ǰ�� */
		InThreading(t->rchild);   /* �ݹ������������� */
	}
}

void InVisitThrTree(BiThrTree *t)/* ������������������ķǵݹ��㷨 */
{ 
	while(t!=NULL)                 /* ��ʼ��Ϊ���� */
	{ 
		while(t->lflag==0)
			t=t->lchild;
		if(t==NULL)                /* �ս���˳� */
			exit(ERROR);  
		printf("%c  ",t->data);    /* ����ǰ����� */
		while(t->rflag==1&&t->rchild!=NULL) 
		{
			t=t->rchild;
			printf("%c  ",t->data);/* ���ʺ�̽�� */
		}
		t=t->rchild;
	}
	printf("\n\t\t");
}

int main(int argc,char* argv[])
{
	BiThrTree *tree;
	printf("\t\t�밴�����������������(��:ABC@@DE@G@@F@@@#)\n\t\t");
	tree=CreateBiThrTree(); /* ��������������� */
	InThreading(tree);      /* ���������������� */
	printf("\t\t����������������������:\n\t\t");
	InVisitThrTree(tree);   /* �������(���)���������� */
    return 0;
}

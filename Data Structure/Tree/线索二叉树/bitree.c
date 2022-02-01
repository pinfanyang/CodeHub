BiTree *BiTreeCreate()/*�ǵݹ鷽��������������*/
{
	BiTree *Q[MAXNUM];
	DataType ch;
	int front,rear;
	BiTree *s,*root; 
	root=NULL;
	front=1; rear=0;  /* ���г�ʼ�� */
	printf("\t\t�밴��ȫ�������ı��˳����������������\n");
	printf("\t\tע���ս����'@'��ʾ������������'#'����\n\t\t");
	ch=getchar();
	while(ch!='#')
	{
		s=NULL;   
		if(ch!='@')
  		{  
			s=(BiTree *)malloc(sizeof(BiTree));/* �����½�� */ 
			s->data=ch; 
			s->lchild=NULL; 
			s->rchild=NULL; 
		}
		rear++;
		Q[rear]=s;           /* �ս����½�㶼��� */
		if(rear==1)  
			root=s;          /* rear��1���Ǹ���㣬��rootָ���� */
		else
		{
			if(s&&Q[front])  /* ��ǰ����˫�׽�㶼�ǿ� */
				if(rear%2==0)/* rear��ż�����½��Ϊ˫�׵����� */
					Q[front]->lchild=s;
				else         /* rear���������½��Ϊ˫�׵��Һ��� */
					Q[front]->rchild=s;
			if(rear%2==1) 
				front++;     /* rear��������ͷָ��frontָ����һ��˫��*/
		}
		ch=getchar(); 
	} 
	return root; 
} 
void BiTreePreTra(BiTree *t) /*�ݹ��㷨�������������*/
{
	if(t)                     /* ��ʼ���������������� */
	{
		printf("%c",t->data); /* ���ʽ�� */
		BiTreePreTra(t->lchild); /* ������������� */
		BiTreePreTra(t->rchild); /* ������������� */
	}
}   

void BiTreeInTra(BiTree *t)/*�ݹ��㷨�������������*/
{
	if(t)
	{
		BiTreeInTra(t->lchild);  /* ������������� */
		printf("%c",t->data); /* ���ʸ���� */
		BiTreeInTra(t->rchild);  /* ������������� */
	}
}   

void BiTreePostTra(BiTree *t)/*�ݹ��㷨�������������*/
{
	if(t)
	{
		BiTreePostTra(t->lchild); /* ������������� */
		BiTreePostTra(t->rchild); /* ������������� */
		printf("%c",t->data);  /* ���ʸ���� */
	}
}

int BiTreeDepthPost(BiTree *t) /*�ݹ��㷨���������������ĸ߶�*/
{
	int hl,hr,max;
	if(t)
	{
		hl=BiTreeDepthPost(t->lchild);  /* ������������� */
		hr=BiTreeDepthPost(t->rchild);  /* ������������� */
		max=hl>hr?hl:hr;              /* �õ�����������Ƚϴ���*/
		return max+1;                /* ����������� */
	}
	else
		return ERROR;                   /* ����ǿ������򷵻�0 */
} 

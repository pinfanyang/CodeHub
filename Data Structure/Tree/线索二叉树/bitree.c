BiTree *BiTreeCreate()/*非递归方法建立二叉链表*/
{
	BiTree *Q[MAXNUM];
	DataType ch;
	int front,rear;
	BiTree *s,*root; 
	root=NULL;
	front=1; rear=0;  /* 队列初始化 */
	printf("\t\t请按完全二叉树的编号顺序依次输入结点序列\n");
	printf("\t\t注：空结点用'@'表示，输入序列以'#'结束\n\t\t");
	ch=getchar();
	while(ch!='#')
	{
		s=NULL;   
		if(ch!='@')
  		{  
			s=(BiTree *)malloc(sizeof(BiTree));/* 申请新结点 */ 
			s->data=ch; 
			s->lchild=NULL; 
			s->rchild=NULL; 
		}
		rear++;
		Q[rear]=s;           /* 空结点和新结点都入队 */
		if(rear==1)  
			root=s;          /* rear是1，是根结点，用root指向它 */
		else
		{
			if(s&&Q[front])  /* 当前结点和双亲结点都非空 */
				if(rear%2==0)/* rear是偶数，新结点为双亲的左孩子 */
					Q[front]->lchild=s;
				else         /* rear是奇数，新结点为双亲的右孩子 */
					Q[front]->rchild=s;
			if(rear%2==1) 
				front++;     /* rear是奇数，头指针front指向下一个双亲*/
		}
		ch=getchar(); 
	} 
	return root; 
} 
void BiTreePreTra(BiTree *t) /*递归算法先序遍历二叉树*/
{
	if(t)                     /* 初始条件：二叉树存在 */
	{
		printf("%c",t->data); /* 访问结点 */
		BiTreePreTra(t->lchild); /* 先序遍历左子树 */
		BiTreePreTra(t->rchild); /* 先序遍历右子树 */
	}
}   

void BiTreeInTra(BiTree *t)/*递归算法中序遍历二叉树*/
{
	if(t)
	{
		BiTreeInTra(t->lchild);  /* 中序遍历左子树 */
		printf("%c",t->data); /* 访问根结点 */
		BiTreeInTra(t->rchild);  /* 中序遍历右子树 */
	}
}   

void BiTreePostTra(BiTree *t)/*递归算法后序遍历二叉树*/
{
	if(t)
	{
		BiTreePostTra(t->lchild); /* 后序遍历左子树 */
		BiTreePostTra(t->rchild); /* 后序遍历右子树 */
		printf("%c",t->data);  /* 访问根结点 */
	}
}

int BiTreeDepthPost(BiTree *t) /*递归算法后序遍历求二叉树的高度*/
{
	int hl,hr,max;
	if(t)
	{
		hl=BiTreeDepthPost(t->lchild);  /* 求左子树的深度 */
		hr=BiTreeDepthPost(t->rchild);  /* 求右子树的深度 */
		max=hl>hr?hl:hr;              /* 得到左、右子树深度较大者*/
		return max+1;                /* 返回树的深度 */
	}
	else
		return ERROR;                   /* 如果是空树，则返回0 */
} 

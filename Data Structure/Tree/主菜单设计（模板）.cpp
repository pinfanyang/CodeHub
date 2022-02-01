#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define NLAYER  4

typedef struct BiTNode               // 定义二叉树节点结构
{
	char data;                       // 数据域
    struct BiTNode *LChild,*RChild;  // 左右孩子指针域
}BiTNode,*BiTree;
BiTree T;

//(1) 建立二叉树
void CreateBiTree(BiTree *bt)
{ // 按照先序序列建立二叉树的二叉链表的过程
	char ch;
    scanf("%c",&ch);  
    if(ch=='#')  *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); // 生成一个新结点
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild));      // 生成左子树
        CreateBiTree(&((*bt)->RChild));      // 生成右子树
	}
}

//(2) 树型打印二叉树
void TranslevelPrint(BiTree bt)
{  //本算法实现二叉树的按层打印
	struct node
	{
		BiTree vec[MAXLEN];           // 存放树结点
		int layer[MAXLEN];            // 结点所在的层
		int locate[MAXLEN];           // 打印结点的位置
		int front,rear;
	}q;                               // 定义队列q
	int i,j,k;
	int nLocate;
	j = 1;
	k = 0;
	q.front = 0;                      // 初始化队列q队头，队尾
	q.rear = 0;
    printf(" ");
	q.vec[q.rear] = bt;               // 将二叉树根节点入队列
	q.layer[q.rear] = 1;
	q.locate[q.rear] = 20;
	q.rear = q.rear + 1;
	while(q.front < q.rear)
	{
		bt = q.vec[q.front];
		i = q.layer[q.front];        
		nLocate = q.locate[q.front];
		if(j < i)                      // 进层打印时换行
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
		while(k < (nLocate-1))          // 利用结点深度控制横向位置
		{
			printf(" ");
			k++;
		}
		printf("%c",bt->data);
		q.front = q.front + 1;
		if(bt->LChild != NULL)          // 存在左子树，将左子树根节点入队列
		{		
			q.vec[q.rear] = bt->LChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate - pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
		if(bt->RChild != NULL)         // 存在右子树，将右子树根节点入队列
		{		
			q.vec[q.rear] = bt->RChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] =(int)(nLocate + pow(2, NLAYER-i-1));
			q.rear = q.rear +1;
		}
	}
}

//(3) 输出结点
void Visit(char ch)
{
	printf("%c  ",ch);
}

//(4) 先序遍历二叉树
void  PreOrder(BiTree root) 
{// 先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针
	if (root!=NULL)
	{
		Visit(root ->data);       // 访问根结点
		PreOrder(root ->LChild);  // 先序遍历左子树
		PreOrder(root ->RChild);  // 先序遍历右子树
	}
}

//(5) 中序遍历二叉树
void  InOrder(BiTree root)  
{// 中序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针
	if (root!=NULL)
	{
		InOrder(root ->LChild);    // 中序遍历左子树
		Visit(root ->data);        // 访问根结点
		InOrder(root ->RChild);    // 中序遍历右子树
	}
}

//(6) 后序遍历二叉树
void  PostOrder(BiTree root)  
{//后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针
	if(root!=NULL)
	{
		PostOrder(root ->LChild);  // 后序遍历左子树
		PostOrder(root ->RChild);  // 后序遍历右子树
		Visit(root ->data);        // 访问根结点
	}
}

//(7) 输出叶子结点
void  PreOrderLeaf(BiTree root) 
{//先序遍历二叉树并输出叶子结点, root为指向二叉树根结点的指针
	if (root!=NULL)
	{
		if (root ->LChild==NULL && root ->RChild==NULL)
			printf("%c  ",root ->data);   // 输出叶子结点
		PreOrderLeaf(root ->LChild);      // 先序遍历左子树
		PreOrderLeaf(root ->RChild);      // 先序遍历右子树
	}
}

//(8) 输出叶子结点的个数
int LeafCount(BiTree root)
{
	int LeafNum;
	if(root==NULL)	
		LeafNum=0;
	else 
		if((root->LChild==NULL)&&(root->RChild==NULL))
			LeafNum=1;
		else 
			LeafNum=LeafCount(root->LChild)+LeafCount(root->RChild);	// 叶子数为左右子树的叶子数目之和
 
	return LeafNum;
}

//(9) 输出二叉树的深度
int PostTreeDepth(BiTree root)   // 后序遍历求二叉树的深度递归算法 
{
	int hl,hr,max;
	if(root!=NULL)
	{
		hl=PostTreeDepth(root->LChild);  // 求左子树的深度
		hr=PostTreeDepth(root->RChild);  // 求右子树的深度 
		max=hl>hr?hl:hr;                 // 得到左、右子树深度较大者
		return(max+1);                   // 返回树的深度 
	}
	else return(0);                      // 如果是空树，则返回0 
}

//(10) 主要工作函数。操作区用户界面
void mainwork()
{
	int yourchoice;
      
	printf("\n------------------------欢迎使用二叉树基本操作程序---------------------------\n");
	printf("\n                               菜 单 选 择                                 \n\n");
	printf("        1. 树状输出二叉树                        2. 先序遍历二叉树             \n");
	printf("        3. 中序遍历二叉树                        4. 后序遍历二叉树             \n");
	printf("        5. 输出叶子结点                          6. 输出叶子结点个数           \n");
	printf("        7. 输出二叉树的深度                      8. 退出                       \n");
	printf("\n-----------------------------------------------------------------------------\n");
    printf("请输入你的选择：");
	scanf("%d",&yourchoice);
	while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
		  ||yourchoice==7||yourchoice==8))
	{
		printf("输入选择不明确，请重输\n");
		scanf("%d",&yourchoice);
	}
	while(1)
	{
		switch(yourchoice)
		{
			case 1:	printf("树的形状为:\n");TranslevelPrint(T);  getch();		break;
			case 2:	printf("先序遍历序列为:"); PreOrder(T);	break;
			case 3:	printf("\n中序遍历序列为:");InOrder(T); break;
			case 4:	printf("\n后序遍历序列为:");PostOrder(T);	break;
			case 5:	printf("叶子结点为:"); PreOrderLeaf(T); 	break;
			case 6:	printf("叶子结点个数为:%d",LeafCount(T));	        break;
		    case 7: printf("二叉树的深度为:%d",PostTreeDepth(T));   break;
			case 8: system("cls");	exit(0); 			break;
			default:  break;
		}
	
	    	printf("\n------------------------欢迎使用二叉树基本操作程序---------------------------\n");
	        printf("\n                               菜 单 选 择                                 \n\n");
	        printf("        1. 树状输出二叉树                        2. 先序遍历二叉树             \n");
	        printf("        3. 中序遍历二叉树                        4. 后序遍历二叉树             \n");
	        printf("        5. 输出叶子结点                          6. 输出叶子结点个数           \n");
	        printf("        7. 输出二叉树的深度                      8. 退出                       \n");
	        printf("\n-----------------------------------------------------------------------------\n");

	    printf("\n请输入你的选择：");
	    scanf("%d",&yourchoice);
	}//endwhile(1)

}//mainwork

//(11) 主函数。创建二叉树，调用工作区模块函数
int main()
{
	    BiTree T; 
	    printf("首先请输入二叉树的结点序列：\n");
		CreateBiTree(&T);
        printf("请按菜单提示操作：\n");
        mainwork();
	
}

 /* main6-2.c 检验bo6-2.c的主程序,利用条件编译选择数据类型(另一种方法) */
 #define CHAR /* 字符型 */
 //#define INT /* 整型（二者选一） */
 #include"c1.h"
 #ifdef CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* 字符型以空格符为空 */
 #endif
 #ifdef INT
   typedef int TElemType;
   TElemType Nil=0; /* 整型以0为空 */
 #endif
 #include"c6-2.h"
 #include"bo6-2.c"

 Status visitT(TElemType e)
 {
 #ifdef CHAR
   printf("%c ",e);
 #endif
 #ifdef INT
   printf("%d ",e);
 #endif
   return OK;
 }

 void main()
 {
   int i;
   BiTree T,p,c;
   TElemType e1,e2;
   InitBiTree(&T);
   printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
 #ifdef CHAR
     printf("二叉树的根为: %c\n",e1);
 #endif
 #ifdef INT
     printf("二叉树的根为: %d\n",e1);
 #endif
   else
     printf("树空，无根\n");
 #ifdef CHAR
   printf("请先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)\n");
 #endif
 #ifdef INT
   printf("请先序输入二叉树(如:1 2 0 0 0表示1为根结点,2为左子树的二叉树)\n");
 #endif
   CreateBiTree(&T);
   printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
 #ifdef CHAR
     printf("二叉树的根为: %c\n",e1);
 #endif
 #ifdef INT
     printf("二叉树的根为: %d\n",e1);
 #endif
   else
     printf("树空，无根\n");
   printf("中序递归遍历二叉树:\n");
   InOrderTraverse(T,visitT);
   printf("\n中序非递归遍历二叉树:\n");
   InOrderTraverse1(T,visitT);
   printf("中序非递归遍历二叉树(另一种方法):\n");
   InOrderTraverse2(T,visitT);
   printf("后序递归遍历二叉树:\n");
   PostOrderTraverse(T,visitT);
   printf("\n层序遍历二叉树:\n");
   LevelOrderTraverse(T,visitT);
   
   DestroyBiTree(&T);
 }

 /* main6-2.c ����bo6-2.c��������,������������ѡ����������(��һ�ַ���) */
 #define CHAR /* �ַ��� */
 //#define INT /* ���ͣ�����ѡһ�� */
 #include"c1.h"
 #ifdef CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */
 #endif
 #ifdef INT
   typedef int TElemType;
   TElemType Nil=0; /* ������0Ϊ�� */
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
   printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
 #ifdef CHAR
     printf("�������ĸ�Ϊ: %c\n",e1);
 #endif
 #ifdef INT
     printf("�������ĸ�Ϊ: %d\n",e1);
 #endif
   else
     printf("���գ��޸�\n");
 #ifdef CHAR
   printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #endif
 #ifdef INT
   printf("���������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
   CreateBiTree(&T);
   printf("������������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
 #ifdef CHAR
     printf("�������ĸ�Ϊ: %c\n",e1);
 #endif
 #ifdef INT
     printf("�������ĸ�Ϊ: %d\n",e1);
 #endif
   else
     printf("���գ��޸�\n");
   printf("����ݹ����������:\n");
   InOrderTraverse(T,visitT);
   printf("\n����ǵݹ����������:\n");
   InOrderTraverse1(T,visitT);
   printf("����ǵݹ����������(��һ�ַ���):\n");
   InOrderTraverse2(T,visitT);
   printf("����ݹ����������:\n");
   PostOrderTraverse(T,visitT);
   printf("\n�������������:\n");
   LevelOrderTraverse(T,visitT);
   
   DestroyBiTree(&T);
 }

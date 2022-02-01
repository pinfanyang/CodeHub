#include"StatusTable.h"
using namespace  std;
/*****************************************单链表***************************************************/
/*链式存储结构体定义*/
typedef int ElemType;           //项目元素类型，自适应定义
typedef struct LNode
{
    ElemType data;               //结点数据域
    struct LNode *next;          //结点指针域
}LNode,*LinkList;

/*链表初始化*/
//入口：待初始化的单链表        出口：初始化完成的单链表
Status InitList(LinkList &L)
{
    L= new LNode;               //生成新结点作为头结点，用指针L指向头结点
    L->next=NULL;               //头结点的指针域置空
    return OK;
}



/*********************************基本操作********************************************/
/*1.单链表的取值*/
//入口：单链表，待取元素序号，存放返回的取值        出口：函数状态值
Status GetElem(LinkList L,int i,ElemType &e)
{
    LinkList p;
    p=L->next;
    int j=1;                        //初始化：p指向首元结点，计数器j赋予初值1
    while(p && j<i)             //顺链域向后扫描，直到p为空或p指向第i个元素
    {
        p=p->next;              //p指向下一个结点
        ++j;                    //计数器j相应加1
    }
    if(!p || )
}   
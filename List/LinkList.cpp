#include"StatusTable.h"
using namespace  std;
/*****************************************������***************************************************/
/*��ʽ�洢�ṹ�嶨��*/
typedef int ElemType;           //��ĿԪ�����ͣ�����Ӧ����
typedef struct LNode
{
    ElemType data;               //���������
    struct LNode *next;          //���ָ����
}LNode,*LinkList;

/*�����ʼ��*/
//��ڣ�����ʼ���ĵ�����        ���ڣ���ʼ����ɵĵ�����
Status InitList(LinkList &L)
{
    L= new LNode;               //�����½����Ϊͷ��㣬��ָ��Lָ��ͷ���
    L->next=NULL;               //ͷ����ָ�����ÿ�
    return OK;
}



/*********************************��������********************************************/
/*1.�������ȡֵ*/
//��ڣ���������ȡԪ����ţ���ŷ��ص�ȡֵ        ���ڣ�����״ֵ̬
Status GetElem(LinkList L,int i,ElemType &e)
{
    LinkList p;
    p=L->next;
    int j=1;                        //��ʼ����pָ����Ԫ��㣬������j�����ֵ1
    while(p && j<i)             //˳�������ɨ�裬ֱ��pΪ�ջ�pָ���i��Ԫ��
    {
        p=p->next;              //pָ����һ�����
        ++j;                    //������j��Ӧ��1
    }
    if(!p || )
}   
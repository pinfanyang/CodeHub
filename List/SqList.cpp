#include"StatusTable.h"
using namespace std;
/********************˳���*****************************************/
/*˳��洢�ṹ�嶨��*/
#define MAXSIZE 100      //�洢�ռ��ʼ��������
typedef int ElemType;   //ELemTypeΪ��Ŀ���ͣ�����Ӧ����
typedef struct List
{
    ElemType *data;     //�洢�ռ�Ļ���ַ��dataΪһ���Ȳ�ȷ���Ķ�̬���飬��������ͨ��ָ�롣
    int length;         //˳���ǰ����
    int size;           //˳������Ĵ洢����
}SqList,*PSqList;

/*˳����ʼ��*/
//��ڣ�����ʼ��˳���      ���ڣ���ʼ����ɵ�˳���
Status InitList(SqList &L)
{
    //L.data=(PSqList)malloc(MAXSIZE * sizeof(SqList));  //��̬����洢��
    L.data = new ElemType[MAXSIZE];     //Ϊ˳������һ����СΪMAXSIZE������ռ�
    if(!L.data)
    {   
        cout<<"˳����ʼ��ʧ��!"<<endl;
        return ERROR;
        exit(0);        //�˳�����
    }
    L.length=0;
    L.size=MAXSIZE;     //�ձ��ʼ�洢�ռ�
    cout<<"˳����ʼ���ɹ�!"<<endl;
    return OK;
}



/*********************************˳���Ļ�������*************************************/
/*1.�ж�˳����Ƿ�Ϊ��*/
//��ڣ���Ҫ�жϵ�˳���    ���ڣ�����״ֵ̬
Status ListEmpty(SqList &L)
{
    if(L.length == 0)
        return FALSE;
    else
        return TRUE;
}

/*2.���˳�����Ԫ��*/
//��ڣ�˳���      ���ڣ�����״ֵ̬
Status DisplayList(SqList L)
{
    int i;
    if (ListEmpty(L))
    {
        cout<<"��ǰ˳���Ԫ��Ϊ:"<<endl;
        for(i=0;i<L.length;i++)
        {
            cout<<setw(6)<<L.data[i];
            if((i+1)%10 == 0)
                cout<<endl;
        }
        cout<<endl<<"����Ԫ�ظ���:"<<L.length;
        return OK;
    }
    else
        {
            cout<<"˳���Ϊ��!";
            return ERROR;
        }
}

/*3.˳������Ԫ��*/
//��ڣ�˳�������Ԫ�أ�����λ��(�߼�λ�ã����ڴ�����λ��)      ���ڣ�����״ֵ̬
Status ListInsert(SqList &L,ElemType elem,int loc)
{
    int i;
    if(loc > L.length+1 || loc < 0)     //�ж�λ�úϷ���
    {
        cout<<"����λ�ô���!"<<endl;
        return ERROR;
    }
    if(L.length >= L.size)              //�ж�˳����Ƿ��ж���洢�ռ������Ԫ�أ�û��������ռ�
    {
        L.data=new ElemType[MAXSIZE+1];
        if(!L.data)
        {
            cout<<"�洢�ռ����ʧ��!"<<endl;
            return ERROR;
        }
        L.size+=1;
    }
    for(i=L.length-1;i>=loc-1;i--)      //������������Ӳ���λ�ÿ�ʼ�ĺ���Ԫ���������
    {
        L.data[i+1] = L.data[i];        //ǰ���ѿ��ǵ��˿ռ��������
    }  
    L.data[loc-1] = elem;               //�ճ�����λ��ֱ�Ӹ�����Ԫ��
    L.length+=1;                
    return OK;
}

/*4.˳���ɾ��Ԫ��*/
//��ڣ�˳���ɾ��Ԫ��λ�ã��߼�λ�ã����ڴ�����λ�ã�        ���ڣ�����״ֵ̬
Status ListDelete(SqList &L,int loc)
{
    int i;
    if(loc > L.length || loc <1)        //�ж�λ�õĺϷ���
    {
        cout<<"ɾ��λ������!"<<endl;
        return ERROR;
    }
    for(i = loc;i<L.length;i++)         //ɾ��������ֱ�Ӹ���
    {
        L.data[i-1]=L.data[i];
    }
    L.length-=1;
    return OK;
}

/*5.˳������Ԫ�أ�˳����ң�*/
//��ڣ�˳�������Ԫ��        ����:Ԫ���߼�λ��
int LocateElem(SqList L,ElemType elem)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i] == elem)
        {
            cout<<"���ҵ���Ԫ�أ���λ��Ϊ��"<<i+1<<"��."<<endl;
            return i+1;
        }
    }
    cout<<"δ���ҵ���Ԫ��!"<<endl;
    return ERROR;
    
}

/*6.˳����޸�Ԫ��*/
//��ڣ�˳�����Ԫ�أ���Ԫ��      ���ڣ�����״ֵ̬
Status ChangeList(SqList &L,ElemType elem,ElemType newelem)
{
    int loc=LocateElem(L,elem);       //�ҵ���Ԫ�ص�ַ
    L.data[loc-1]=newelem;        
    return OK;
}


void InitList_num(SqList &L)
{
    for(int i=0;i<10;i++)
    {
        L.data[i]=i+1;
        L.length+=1;
    }
}


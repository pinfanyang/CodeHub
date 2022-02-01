#include"StatusTable.h"
using namespace std;
/********************顺序表*****************************************/
/*顺序存储结构体定义*/
#define MAXSIZE 100      //存储空间初始化分配量
typedef int ElemType;   //ELemType为项目类型，自适应定义
typedef struct List
{
    ElemType *data;     //存储空间的基地址，data为一长度不确定的动态数组，不看做普通的指针。
    int length;         //顺序表当前长度
    int size;           //顺序表分配的存储容量
}SqList,*PSqList;

/*顺序表初始化*/
//入口：待初始化顺序表      出口：初始化完成的顺序表
Status InitList(SqList &L)
{
    //L.data=(PSqList)malloc(MAXSIZE * sizeof(SqList));  //动态申请存储空
    L.data = new ElemType[MAXSIZE];     //为顺序表分配一个大小为MAXSIZE的数组空间
    if(!L.data)
    {   
        cout<<"顺序表初始化失败!"<<endl;
        return ERROR;
        exit(0);        //退出程序
    }
    L.length=0;
    L.size=MAXSIZE;     //空表初始存储空间
    cout<<"顺序表初始化成功!"<<endl;
    return OK;
}



/*********************************顺序表的基本操作*************************************/
/*1.判断顺序表是否为空*/
//入口：所要判断的顺序表    出口：函数状态值
Status ListEmpty(SqList &L)
{
    if(L.length == 0)
        return FALSE;
    else
        return TRUE;
}

/*2.输出顺序表中元素*/
//入口：顺序表      出口：函数状态值
Status DisplayList(SqList L)
{
    int i;
    if (ListEmpty(L))
    {
        cout<<"当前顺序表元素为:"<<endl;
        for(i=0;i<L.length;i++)
        {
            cout<<setw(6)<<L.data[i];
            if((i+1)%10 == 0)
                cout<<endl;
        }
        cout<<endl<<"共计元素个数:"<<L.length;
        return OK;
    }
    else
        {
            cout<<"顺序表为空!";
            return ERROR;
        }
}

/*3.顺序表插入元素*/
//入口：顺序表，插入元素，插入位置(逻辑位置，非内存物理位置)      出口：函数状态值
Status ListInsert(SqList &L,ElemType elem,int loc)
{
    int i;
    if(loc > L.length+1 || loc < 0)     //判断位置合法性
    {
        cout<<"插入位置错误!"<<endl;
        return ERROR;
    }
    if(L.length >= L.size)              //判断顺序表是否有多余存储空间给插入元素，没有则申请空间
    {
        L.data=new ElemType[MAXSIZE+1];
        if(!L.data)
        {
            cout<<"存储空间分配失败!"<<endl;
            return ERROR;
        }
        L.size+=1;
    }
    for(i=L.length-1;i>=loc-1;i--)      //插入操作，将从插入位置开始的后续元素逐个后移
    {
        L.data[i+1] = L.data[i];        //前面已考虑到了空间满的情况
    }  
    L.data[loc-1] = elem;               //空出来的位置直接给插入元素
    L.length+=1;                
    return OK;
}

/*4.顺序表删除元素*/
//入口：顺序表，删除元素位置（逻辑位置，非内存物理位置）        出口：函数状态值
Status ListDelete(SqList &L,int loc)
{
    int i;
    if(loc > L.length || loc <1)        //判断位置的合法性
    {
        cout<<"删除位置有误!"<<endl;
        return ERROR;
    }
    for(i = loc;i<L.length;i++)         //删除操作，直接覆盖
    {
        L.data[i-1]=L.data[i];
    }
    L.length-=1;
    return OK;
}

/*5.顺序表查找元素（顺序查找）*/
//入口：顺序表，查找元素        出口:元素逻辑位置
int LocateElem(SqList L,ElemType elem)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i] == elem)
        {
            cout<<"查找到该元素，其位置为第"<<i+1<<"个."<<endl;
            return i+1;
        }
    }
    cout<<"未查找到该元素!"<<endl;
    return ERROR;
    
}

/*6.顺序表修改元素*/
//入口：顺序表，旧元素，新元素      出口：函数状态值
Status ChangeList(SqList &L,ElemType elem,ElemType newelem)
{
    int loc=LocateElem(L,elem);       //找到该元素地址
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


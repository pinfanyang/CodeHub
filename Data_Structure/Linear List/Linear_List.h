#ifndef __LINEAR_LIST_H
#define __LINEAR_LIST_H

#include<bits/stdc++.h>
/*---- 全局设置 ----*/

//-- 顺序表 --//
//变量声明
#define InitSize 100    //初始化顺序表大小为100个数据元素
typedef int ElemType;   //顺序表类型为int 4字节
//初始定义
typedef struct {    
    ElemType *data; //动态分配数组大小
    int Maxsize;    //数组最大容量
    int length;     //顺序表当前数据元素个数
}SeqList;

//函数声明

//函数：初始化顺序表
//入口：待初始化的顺序表
//返回：无
void InitList(SeqList &L);

//函数：手动增加顺序表的元素
//入口：要增加长度的顺序表，增加元素个数
//出口：无
void IncreaseSize(SeqList &L,int len);

//函数：插入操作
//入口：插入的顺序表，插入位序，插入元素值
//出口：函数状态值，0错1正
bool ListInsert(SeqList &L,int i,ElemType e);

//函数：删除操作
//入口：待删除顺序表 删除位序 存放删除的数据值
//出口：函数状态值，0错1正
bool ListDelete(SeqList &L,int i,ElemType &e);

//函数：按值查找操作
//入口：待查找的顺序表，查找元素
//出口：0错 ！0为元素次序
int LocateElem(SeqList L,ElemType e);

//函数：按位查找操作
//入口：顺序表，查找位序
//出口：元素值
int GetElem(SeqList L,int i);

//显示当前顺序表中的元素
void Show(SeqList L);
//----------//

/*--------------*/
#endif


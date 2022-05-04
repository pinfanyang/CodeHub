#include "Linear_List.h"

/*------------------- 顺序表 -------------------*/
//函数：初始化顺序表
//入口：待初始化的顺序表
//返回：无
void InitList(SeqList &L)
{
    L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));   //100*4 = 400字节
    L.Maxsize = InitSize;   //初始化顺序表元素个数最多100个
    L.length = 0;   //初始化顺序表个数为0
}

//函数：手动增加顺序表的元素
//入口：要增加长度的顺序表，增加元素个数
//出口：无
void IncreaseSize(SeqList &L,int len)
{
    int *p = L.data;    //指针指向表L的data部分
    L.data = (ElemType *)malloc((L.Maxsize+len) * sizeof(ElemType) );   //申请增加空间
    for(int i = 0;i < L.length;i++)
    {
        L.data[i] = p[i];   //上一步申请了新的空间之后，数组重置，需要将原来数据复制进来
    }
    L.Maxsize += len;   //顺序表长度增加
    free(p);    //释放指针p
}

//函数：插入操作
//入口：插入的顺序表，插入位序，插入元素值
//出口：函数状态值，0错1正
bool ListInsert(SeqList &L,int i,ElemType e)   
{
    //合法性判断
    if((i < 1) || (i > L.length+1) ) //判断i的位置
        return false;
    if(L.length >= L.Maxsize)   //是否有空余位置
        return false;
    //移动数据操作
    for(int j = L.length;j >= i;j--)    //从后面往前面移动
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;    //第i个位置插入新值，数组存储位置为i-1
    L.length++;
    return true;
}

//函数：删除操作（元素向前移动最后一个值未进行处理）
//入口：待删除顺序表 删除位序 存放删除的数据值
//出口：函数状态值，0错1正
bool ListDelete(SeqList &L,int i,ElemType &e)   
{
    //合法性判断
    if((i < 1)||(i > L.length)) //判断i
        return false;
    e = L.data[i-1];    //存放删除的数据值
    for(int j = i;j < L.length;j++)     //数据往前面提
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

//函数：按值查找操作
//入口：待查找的顺序表，查找元素
//出口：0错 ！0为元素次序
int LocateElem(SeqList L,ElemType e)
{
    int i;
    for(i = 0;i < L.length;i++)
    {
        if(L.data[i] == e)  return i+1; //返回次序
    }
    return false;
    
}

//函数：按位查找操作
//入口：顺序表，查找位序
//出口：元素值
int GetElem(SeqList L,int i)
{
    if((i < 1) || (i >= L.length))
        return false;
    else
        return L.data[i-1];     //返回元素值
}

//显示当前顺序表中的元素
void Show(SeqList L)
{
    printf("当前顺序表中元素为：");
    for(int i = 0;i < L.length - 1; i++)
        printf("%d ",L.data[i]);
    printf("%d\n",L.data[L.length - 1]);
    
}

/*---------------------------------------------*/

//显示菜单函数
void Show_Menu()
{
    printf("=================================================\n");
    printf("||---------- 线性表功能选择菜单 ----------||\n");
    printf("|----- 顺序表部分 -----|\n");
    printf("|1.创建并初始化顺序表.\n");
    printf("|2.增加顺序表长度.\n");
    printf("|3.插入顺序表元素.\n");
    printf("|4.删除顺序表元素.\n");
    printf("|5.按值查找顺序表元素.\n");
    printf("|6.按位查找顺序表元素.\n");
    printf("|---------------------|\n");
    printf("||--------------------------------------||\n");
    printf("=================================================\n");
}



int choose_number;      //存放操作符
int len_input = 0;      //要增加的顺序表长度
int weizhi_temp = 0;   //临时变量
int value_temp = 0;    //临时变量
int main()
{
    Show_Menu(); 
    while(1)
    {
        printf("请输入操作序号:");
        scanf("%d",&choose_number);
        switch (choose_number)
        {
        case 1:
            SeqList L;
            InitList(L);
            for(int i = 1;i <= 10;i++)   ListInsert(L,i,i);
            Show(L);
            printf("初始化完成！当前顺序表个数为：%d,该表最大可存放：%d个元素.\n",L.length,L.Maxsize);
            break;
        case 2:
            printf("请输入要增加的顺序表长度:");
            scanf("%d",&len_input);
            IncreaseSize(L,len_input);
            printf("当前顺序表个数为：%d,该表最大可存放：%d个元素.\n",L.length,L.Maxsize);
            break;
        case 3:
            printf("请输入要插入的数据元素位序（1开始）和值，空格分隔：");
            scanf("%d %d",&weizhi_temp,&value_temp);
            if( ListInsert(L,weizhi_temp,value_temp) )
                printf("插入成功！");
            else
                printf("插入失败！");
            Show(L);
            break;
        case 4:
            printf("请输入要删除的数据元素位序：");
            scanf("%d",&weizhi_temp);
            if( ListDelete(L,weizhi_temp,value_temp) )
                printf("删除成功！删除的元素值为：%d.",value_temp);
            else
                printf("删除失败！");
            Show(L);           
            break;
        case 5:
            printf("请输入要查找的数据元素值：");
            scanf("%d",&value_temp);
            if( int temp = LocateElem(L,value_temp) )
                printf("查找成功！该元素的位序为：%d\n",temp);
            else
                printf("查找失败！\n");            
            break;
        case 6:
            printf("请输入要查找的数据元素位序：");
            scanf("%d",&weizhi_temp);
            if( int temp = GetElem(L,weizhi_temp) )
                printf("查找成功！该元素的值为：%d\n",temp);
            else
                printf("查找失败！\n");            
            break;
        default:
            printf("输入错误，请重新输入！\n");
            break;
        }
    }


}








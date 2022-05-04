//该文件为 单链表实现
#include<bits/stdc++.h>
typedef int ElemType;   //顺序表类型为int 4字节

//-- 单链表 --//
//结点定义
typedef struct LNode{
    ElemType data;  //数据域
    struct LNode *next; //指针域
}LNode,*LinkList;
//此处typedef作用相当于：
//typedef struct LNode LNode;
//typedef struct LNode *LinkList;

/*------------------- 单链表 -------------------*/
//对于函数中指针的使用，LiskList和*LNode的作用相同，但是前者更加强调当前变量为链表，后者强调当前变量为结点，注意函数中调用的区别。


//函数：带头结点的链表建立(采用头插法)
//入口：待初始化链表
//出口：初始化完成的链表
LinkList List_HeadInsert(LinkList &L)   //逆向建立单链表
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));    //创建头结点
    L->next = NULL;     //初始化为空表，头结点指向null
    printf("\n请输入要建立的单链表结点个数：");
    scanf("%d",&x);
    while(x)
    {
        s = (LNode *)malloc(sizeof(LNode)); //创建新结点，注意这里使用的是LNode *，和上面LinkList作用是相同的，意义不同而已。
        s->data = x;    //默认为逆序顺序值
        s->next = L->next;
        L->next = s;    //将新结点插入表中，L为头指针
        x--;
    }
    return L;
}

//函数：带头结点的链表建立（采用尾插法）
//入口：待初始化链表
//出口：初始化完成的链表
LinkList List_TailInsert(LinkList &L)   //正向建立单链表
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r = L;    //r为表尾指针
    printf("\n请输入要建立的单链表结点个数：");
    scanf("%d",&x);
    while(x)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        x--;
    }
    r->next = NULL;
    return L;
}


//函数：按位序前插入（带头结点）
//入口：单链表，位序，值
//出口：函数状态值 0错1正
bool  ListInsert_WithHead(LinkList &L,int i,ElemType e)
{
    //合法性判断
    if(i < 1)   return false;
    //开始找第i-1个结点
    LNode *p;   //指向当前扫描结点
    int j = 0;  //记录当前指向的是第几个结点
    p = L;      //初始指向头结点，为第0个
    while((p != NULL) && (j < i-1)) //循环找到第i-1个结点，即插入的结点前一个
    {
        p = p->next;
        j++;
    }
    if(p == NULL)   //p指向了null，表明第i-1个元素不存在，即i不合法
        return false;
    //开始插入新结点
    LNode *s = (LNode *)malloc(sizeof(LNode));  //申请新结点
    s->data = e;
    s->next = p->next;  //这一步和下一步不能换顺序，否则就变成2个互相指向，造成后面结点丢失
    p->next = s;    //p接在s前面

    return true;

}

//函数：按位序前插入（不带头结点）
//入口：单链表，位序，值
//出口：函数状态值 0错1正
bool  ListInsert_WithoutHead(LinkList &L,int i,ElemType e)
{
    //合法性判断
    if(i < 1)   return false;

    //与带头结点的区别，这里要对插入第1个头结点做特殊处理
    if(i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;      //头指针指向新结点
        return true;
    }

    //开始找第i-1个结点
    LNode *p;   //指向当前扫描结点
    int j = 0;  //记录当前指向的是第几个结点
    p = L;      //初始指向头结点，为第0个
    while((p != NULL) && (j < i-1)) //循环找到第i-1个结点，即插入的结点前一个
    {
        p = p->next;
        j++;
    }
    if(p == NULL)   //p指向了null，表明第i-1个元素不存在，即i不合法
        return false;
    //开始插入新结点
    LNode *s = (LNode *)malloc(sizeof(LNode));  //申请新结点
    s->data = e;
    s->next = p->next;  //这一步和下一步不能换顺序，否则就变成2个互相指向，造成后面结点丢失
    p->next = s;    //p接在s前面

    return true;
}

//函数:指定结点的后插操作    时间复杂度为O(1)
//入口：插入结点，插入的新结点值
//出口：函数状态值 0错1正
bool InsertNextNode(LNode *p,ElemType e)
{
    if(p == NULL)   return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)   return false;

    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return true;
}

//函数：指定结点的前插操作   时间复杂度为O(1)
//入口：插入结点，插入的新结点值
//出口：函数状态值 0错1正
bool InsertPriorNode(LNode *p,LNode *s)
{
    if((p == NULL) || (s == NULL))  return false;
    s->next = p->next;  //s和p后面的结点连接
    p->next = s;    //p的后继结点改为s
    ElemType tp = p->data;  //暂存p结点的data
    p->data = s->data;  //把p结点的data赋值给p保存，然后把s结点的data改为p结点的，就相当于进行了p结点的前插操作
    s->data = tp;
    return true;
}

//函数：按位序删除（带头结点） 最坏和平均复杂度为：O(n)  最好复杂度为：O(1)
//入口：单链表，位序，存放删除结点的数据（带回）
//出口：函数状态值 0错1正
bool ListDelete(LinkList &L,int i,ElemType &e)
{
    if( i < 1)  return false;
    LNode *p;       //当前扫描结点
    int j = 0;      //当前p指向的结点个数
    p = L;          //指向头结点，第0个结点
    while((p != NULL) && (j < i-1)) //找到第i-1个结点
    {
        p = p->next;
        j++;
    }
    if((p == NULL) || (p->next == NULL))    //i值不合法|第i-1个结点后面无结点
        return false;
    LNode *q = p->next; //q指向被删除的结点
    e = q->data;    //带回被删除结点的值
    p->next = q->next;  //越过p后面的结点，让p指向p+1 +1 的结点，中间那个删除
    free(q);
    return true;
}

//函数：指定结点的删除  
//入口：待删除的结点
//出口：函数状态值 0错1正
//注：这是一个原理bug，正常情况下时间复杂度为O(1)
//但是，如果要删除最后一个结点，那么这个函数就会错误，因为最后一个结点删不掉（按着下面这个原理）
//体现了单链表的局限性：无法逆向检索，要解决就要使用双向链表或者修改算法（对最后一个结点做单独特殊处理）
//如果是最后一个结点，那么只能从表头开始依次寻找p的前驱，时间复杂度为O(n) 
bool DeleteNode(LNode *p)
{
    if(p == NULL)   return false;
    LNode *q = p->next; //让q指向*p的后继结点
    p->data = p->next->data;    //p和p后面的结点交换数据
    p->next = q->next;  //p的后继指向删除结点后面的那个结点
    free(q);    //释放p的后继结点

    return true;
}

//函数：按位查找（带头结点）    平均时间复杂度：O(n)
//入口：单链表，结点位序
//出口：查找的结点
//注：已经考虑的0结点的情况
LNode * GetElem(LinkList L,int i)
{
    if(i < 0)   return NULL;
    LNode *p;   //记录当前扫描结点
    int j = 0;  //当前p指向的结点
    p = L;  //指向头结点，头结点为第0个结点
    while(p != NULL && j < i)   //找到第i个结点，注意这里从0开始的，所有不用i-1
    {
        p = p->next;
        j++;
    }
    return p;   //直接返回查找的结点，包含0结点的情况
}

//函数：按值查找       平均时间复杂度：O(n)
//入口：单链表，结点值
//出口：查找结点
LNode * LocateElem(LinkList L,ElemType e)
{
    LNode *p = L->next;
    //从第一个结点开始查找
    while(p != NULL && p->data != e)    p = p->next;
    return p;
}

//函数：修改数据
//入口：单链表 结点位序 修改值
//出口：函数状态值 0错1正
bool ChangeNodeValue(LinkList &L,int i,ElemType e)
{
    if( LNode *p = GetElem(L,i) )
    {
        p->data = e;
        return true;
    }
    else
        return false;
}

//函数：求表的长度
//入口：单链表
//出口：表长
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//函数：显示当前链表所有值
//入口：单链表
//出口：无
void Show_LinkList(LinkList L)
{
    LNode *p = L;
    printf("当前单链表中数据为：");
    while(p->next != NULL)
    {
        p = p->next;
        printf("%-6d",p->data);
    }
    printf("\n");
}
/*---------------------------------------------*/


//显示菜单函数
void Show_Menu()
{
    printf("=================================================\n");
    printf("||---------- 线性表功能选择菜单 ----------||\n");
    printf("|----- 单链表部分 -----|\n");
    printf("|11.采用头插法建立链表.\n");
    printf("|12.采用尾插法建立链表.\n");
    printf("|13.按位序前插入.\n");
    printf("|14.指定结点前插(略).\n");
    printf("|15.指定结点后插(略).\n");
    printf("|16.按位序删除.\n");
    printf("|17.指定结点的删除(略).\n");
    printf("|18.按位查找.\n");
    printf("|19.按值查找.\n");
    printf("|20.修改数据.\n");
    printf("|---------------------|\n");
    printf("||--------------------------------------||\n");
    printf("=================================================\n");
}



int choose_number;      //存放操作符
//int len_input = 0;      //要增加的顺序表长度
int weizhi_temp = 0;   //临时变量
int value_temp = 0;    //临时变量
LinkList List;
int main()
{
    Show_Menu(); 
    while(1)
    {
        printf("请输入操作序号:");
        scanf("%d",&choose_number);
        switch (choose_number)
        {
        case 11:
            List = List_HeadInsert(List);
            Show_LinkList(List);
            break;
        case 12:
            List = List_TailInsert(List);
            Show_LinkList(List);
            break;
        case 13:
            Show_LinkList(List);
            printf("请输入插入位序和值，空格分离：");
            scanf("%d %d",&weizhi_temp,&value_temp);
            if( ListInsert_WithHead(List,weizhi_temp,value_temp) )  printf("插入成功！\n");
            else    printf("插入失败！\n");
            Show_LinkList(List);
            break;
        case 14:
            Show_LinkList(List);
            printf("输不进来，手动测试.\n");
            LNode *tp;
            tp->data = 123;
            InsertPriorNode(List+3,tp);
            Show_LinkList(List);
            break;
        case 16:
            Show_LinkList(List);
            printf("请输入删除的位序：");
            scanf("%d",&weizhi_temp);
            if( ListDelete(List,weizhi_temp,value_temp) )  printf("删除成功！删除值为：%d\n",value_temp);
            else    printf("删除失败！\n");
            Show_LinkList(List);
            break;
        case 18:
            Show_LinkList(List);
            printf("请输入查找的位序：");
            scanf("%d",&weizhi_temp);
            if( LNode * tp = GetElem(List,weizhi_temp) )  printf("查找成功！该数据值为：%d\n",tp->data);
            else    printf("查找失败！\n");
            break;
        case 19:
            Show_LinkList(List);
            printf("请输入查找的值：");
            scanf("%d",&value_temp);
            if( LNode * tp = LocateElem(List,value_temp) )  printf("查找成功！\n");
            else    printf("查找失败！\n");
            break;
        case 20:
            Show_LinkList(List);
            printf("请输入修改数据的位序和修改值，空格分割：");
            scanf("%d %d",&weizhi_temp,&value_temp);
            if( ChangeNodeValue(List,weizhi_temp,value_temp) )  printf("修改成功！\n");
            else    printf("修改失败！\n");
            Show_LinkList(List);
            break;

        default:
            printf("输入错误，请重新输入！\n");
            break;
        }
    }


}

#include "SqList.cpp"

/****************************功能函数声明************************/
Status InitList(SqList &L);                                                     //顺序表初始化
Status ListEmpty(SqList &L);                                                    //判断顺序表是否为空
Status DisplayList(SqList L);                                                   //输出顺序表中元素
Status ListInsert(SqList &L,ElemType elem,int loc);                             //顺序表插入元素
Status ListDelete(SqList &L,int loc);                                           //顺序表删除元素
int LocateElem(SqList L,ElemType elem);                                         //顺序表查找元素
Status ChangeList(SqList &L,ElemType elem,ElemType newelem);                    //顺序表替换元素
void InitList_num(SqList &L);                                                   //小初始化，1——10
void Menu();                                                                    //菜单函数
int main()
{
    Menu();
    return 0;
}


void Menu()
{
    printf("\t\t\t\t|********************************顺序表基本操作***************************|\n");
    printf("\t\t\t\t|**********  1.顺序表初始化(默认)*****||**********  2.插入元素  **********|\n");
    printf("\t\t\t\t|**********  3.判断表是否为空  *******||**********  4.删除元素  **********|\n");
    printf("\t\t\t\t|**********  5.输出表中元素  *********||**********  6.查找元素  **********|\n");
    printf("\t\t\t\t|**********  7.替换表中元素  *********||**********  8.退出程序  **********|\n");
    printf("\t\t\t\t|*************************************************************************|\n");
    printf("\t\t\t\t注:默认元素类型为int整型.\n");
    int flag=0;

        int select;
        SqList List;
        int e,e1,l;
        InitList(List);
        InitList_num(List);
        DisplayList(List);
    while (1)
    {
        printf("\n请输入操作序号:");
        scanf("%d",&select);
        switch (select)
        {
            case 1:
                printf("已自动运行.\n");
                break;

            case 2:
                printf("请输入所要插入的元素：");
                scanf("%d",&e);
                printf("请输入所要插入元素的逻辑位置：");
                scanf("%d",&l);
                if(ListInsert(List,e,l))
                {
                    printf("插入成功！\n");
                    DisplayList(List);
                }
                else    
                    printf("插入失败！\n");
                break;

            case 3:
                if(ListEmpty(List))
                    printf("当前顺序表非空!\n");
                else   
                    printf("当前顺序表为空表!\n");
                break;

            case 4:
                DisplayList(List);
                printf("\n请输入删除元素所在逻辑位置：");
                scanf("%d",&l);
                if(ListDelete(List,l))
                {
                    printf("删除成功！\n");
                    DisplayList(List);
                }
                else
                    printf("删除失败！\n");
                break;

            case 5:
                DisplayList(List);
                break;

            case 6:
                printf("请输入所要查找的元素：");
                scanf("%d",&e);
                LocateElem(List,e);
                break;

            case 7:
                printf("请输入所要替换的旧元素和新元素(空格分离)：");
                scanf("%d %d",&e,&e1);
                if(ChangeList(List,e,e1))
                    printf("替换成功！\n");
                else
                    printf("替换失败！\n");
                break;
            case 8:

                printf("感谢您的使用，我们下次再见！\n");
                exit(0);
                break;
            default:
                printf("非法操作，请重新输入！\n");
                break;
    
        }
    }

}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct stud_node            /*结构体定义*/
{
    int num;
    char name[10];
    int score;
    struct stud_node *next;
}Node;

/*单链表建立*/
struct stud_node *create()
{
    struct stud_node *head=NULL,*tail=NULL,*p;
    int num;
    char name[10];
    int score;
    printf("请输入学生学号，姓名，成绩(以0 0 0终止)：");
    scanf("%d%s%d",&num,name,&score);
    if(num==0)  return NULL;
    while(num!=0)
    {
        p=(struct stud_node*)malloc(sizeof(struct stud_node));
        p->num=num;
        strcpy(p->name,name);
        p->score=score;
        p->next=NULL;
        if(head==NULL)  head=tail=p;    //当前申请为第一个结点
        else 
        {
            tail->next=p;
            tail=p;
        }
        printf("请输入学生学号，姓名，成绩(以0 0 0终止)：");
        scanf("%d%s%d",&num,name,&score);
    }
    return head;
}

/*单链表输出*/
void print(Node *head)
{
    Node *p;
    printf("单链表当前数据如下：\n");
    printf("学号\t\t姓名\t\t成绩\n");
    while(p)
    { 
        printf("%d\t%s\t\t%d\n",p->num,p->name,p->score);
        p=p->next;
    }
}

/*单链表插入*/
/*在没有头结点单链表h第i个结点前插入结点f*/
Node *insert(Node *h,int i,Node *f)
{
    Node *p;
    int j;
    p=h;
    f=(struct stud_node *)malloc(sizeof(struct stud_node));
    printf("请输入要插入的学生学号，姓名，成绩：");
    scanf("%d%s%d",&f->num,f->name,&f->score);
    j=1;
    while(j<i && p)
    {
        p=p->next;
        j++;
    }
    if(i==1)    //在第一个结点插入
    {
        h=f;
        f->next=p;
    }
    else 
    {
        f->next=p->next;
        p->next=f;
    }
    return h;
}

/*单链表删除*/
/*在没有头结点单链表h删除第i个结点*/
Node *dele(Node *h,int i)
{
    Node *p=h,*q;
    int j=1;
    if(h==NULL)
        return h;
    while(j<i && p)
    {
        q=p;
        p=p->next;
        j++;
    }
    if(i==1)    h=h->next;      //如找到被删结点，且为第一结点，则使h指向第二个结点
    else    q->next=p->next;
    free(p);
    return h;
}

int main()
{
    Node *head,*f;
    head=create();
    print(head);
    printf("\n");
    printf("在第二个结点前插入新结点：\n");
    insert(head,2,f);
    print(head);
    printf("\n");
    printf("删除第一个结点：\n");
    dele(head,1);
    print(head);
    return 0;

}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct stud_node            /*�ṹ�嶨��*/
{
    int num;
    char name[10];
    int score;
    struct stud_node *next;
}Node;

/*��������*/
struct stud_node *create()
{
    struct stud_node *head=NULL,*tail=NULL,*p;
    int num;
    char name[10];
    int score;
    printf("������ѧ��ѧ�ţ��������ɼ�(��0 0 0��ֹ)��");
    scanf("%d%s%d",&num,name,&score);
    if(num==0)  return NULL;
    while(num!=0)
    {
        p=(struct stud_node*)malloc(sizeof(struct stud_node));
        p->num=num;
        strcpy(p->name,name);
        p->score=score;
        p->next=NULL;
        if(head==NULL)  head=tail=p;    //��ǰ����Ϊ��һ�����
        else 
        {
            tail->next=p;
            tail=p;
        }
        printf("������ѧ��ѧ�ţ��������ɼ�(��0 0 0��ֹ)��");
        scanf("%d%s%d",&num,name,&score);
    }
    return head;
}

/*���������*/
void print(Node *head)
{
    Node *p;
    printf("������ǰ�������£�\n");
    printf("ѧ��\t\t����\t\t�ɼ�\n");
    while(p)
    { 
        printf("%d\t%s\t\t%d\n",p->num,p->name,p->score);
        p=p->next;
    }
}

/*���������*/
/*��û��ͷ��㵥����h��i�����ǰ������f*/
Node *insert(Node *h,int i,Node *f)
{
    Node *p;
    int j;
    p=h;
    f=(struct stud_node *)malloc(sizeof(struct stud_node));
    printf("������Ҫ�����ѧ��ѧ�ţ��������ɼ���");
    scanf("%d%s%d",&f->num,f->name,&f->score);
    j=1;
    while(j<i && p)
    {
        p=p->next;
        j++;
    }
    if(i==1)    //�ڵ�һ��������
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

/*������ɾ��*/
/*��û��ͷ��㵥����hɾ����i�����*/
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
    if(i==1)    h=h->next;      //���ҵ���ɾ��㣬��Ϊ��һ��㣬��ʹhָ��ڶ������
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
    printf("�ڵڶ������ǰ�����½�㣺\n");
    insert(head,2,f);
    print(head);
    printf("\n");
    printf("ɾ����һ����㣺\n");
    dele(head,1);
    print(head);
    return 0;

}
#include "SqList.cpp"

/****************************���ܺ�������************************/
Status InitList(SqList &L);                                                     //˳����ʼ��
Status ListEmpty(SqList &L);                                                    //�ж�˳����Ƿ�Ϊ��
Status DisplayList(SqList L);                                                   //���˳�����Ԫ��
Status ListInsert(SqList &L,ElemType elem,int loc);                             //˳������Ԫ��
Status ListDelete(SqList &L,int loc);                                           //˳���ɾ��Ԫ��
int LocateElem(SqList L,ElemType elem);                                         //˳������Ԫ��
Status ChangeList(SqList &L,ElemType elem,ElemType newelem);                    //˳����滻Ԫ��
void InitList_num(SqList &L);                                                   //С��ʼ����1����10
void Menu();                                                                    //�˵�����
int main()
{
    Menu();
    return 0;
}


void Menu()
{
    printf("\t\t\t\t|********************************˳����������***************************|\n");
    printf("\t\t\t\t|**********  1.˳����ʼ��(Ĭ��)*****||**********  2.����Ԫ��  **********|\n");
    printf("\t\t\t\t|**********  3.�жϱ��Ƿ�Ϊ��  *******||**********  4.ɾ��Ԫ��  **********|\n");
    printf("\t\t\t\t|**********  5.�������Ԫ��  *********||**********  6.����Ԫ��  **********|\n");
    printf("\t\t\t\t|**********  7.�滻����Ԫ��  *********||**********  8.�˳�����  **********|\n");
    printf("\t\t\t\t|*************************************************************************|\n");
    printf("\t\t\t\tע:Ĭ��Ԫ������Ϊint����.\n");
    int flag=0;

        int select;
        SqList List;
        int e,e1,l;
        InitList(List);
        InitList_num(List);
        DisplayList(List);
    while (1)
    {
        printf("\n������������:");
        scanf("%d",&select);
        switch (select)
        {
            case 1:
                printf("���Զ�����.\n");
                break;

            case 2:
                printf("��������Ҫ�����Ԫ�أ�");
                scanf("%d",&e);
                printf("��������Ҫ����Ԫ�ص��߼�λ�ã�");
                scanf("%d",&l);
                if(ListInsert(List,e,l))
                {
                    printf("����ɹ���\n");
                    DisplayList(List);
                }
                else    
                    printf("����ʧ�ܣ�\n");
                break;

            case 3:
                if(ListEmpty(List))
                    printf("��ǰ˳���ǿ�!\n");
                else   
                    printf("��ǰ˳���Ϊ�ձ�!\n");
                break;

            case 4:
                DisplayList(List);
                printf("\n������ɾ��Ԫ�������߼�λ�ã�");
                scanf("%d",&l);
                if(ListDelete(List,l))
                {
                    printf("ɾ���ɹ���\n");
                    DisplayList(List);
                }
                else
                    printf("ɾ��ʧ�ܣ�\n");
                break;

            case 5:
                DisplayList(List);
                break;

            case 6:
                printf("��������Ҫ���ҵ�Ԫ�أ�");
                scanf("%d",&e);
                LocateElem(List,e);
                break;

            case 7:
                printf("��������Ҫ�滻�ľ�Ԫ�غ���Ԫ��(�ո����)��");
                scanf("%d %d",&e,&e1);
                if(ChangeList(List,e,e1))
                    printf("�滻�ɹ���\n");
                else
                    printf("�滻ʧ�ܣ�\n");
                break;
            case 8:

                printf("��л����ʹ�ã������´��ټ���\n");
                exit(0);
                break;
            default:
                printf("�Ƿ����������������룡\n");
                break;
    
        }
    }

}

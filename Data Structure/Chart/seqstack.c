void SStackSetNull(SeqStack *s)   /*置空栈*/
{
    s->top =-1;
}

int SStackIsEmpty(SeqStack *s)    /*判断栈S为空栈时返回值为真，反之为假*/
{
    return(s->top<0?TRUE:FALSE);
}

int SStackIsFull(SeqStack *s)        /*判断栈S为满栈时返回值为真，反之为假*/
{
    return(s->top==MAXNUM-1?TRUE:FALSE);
}


int SStackPush(SeqStack *s, DataType x)
{
    if (s->top==MAXNUM-1)
    {
        printf("栈上溢出!\n");
        return FALSE;
    }
    else
    {
        s->top = s->top + 1;
        s->data[s->top]=x;
        return TRUE;
    }
}


int SStackPop(SeqStack *s, DataType *x)
{
    if (s->top==-1)
    {
        printf("栈下溢出!\n");
        return FALSE;
    }
    else
    {
        *x=s->data[s->top];
        s->top--;
        return TRUE;
    }
}

DataType SStackGetTop(SeqStack *s)
{
    if (s->top ==-1)
    {
        printf("栈下溢出!\n");
        return FALSE;
    }
    else
        return (s->data[s->top]);
}
void SStackPrint(SeqStack  *s)
{
    int p;
    if(SStackIsEmpty(s)==TRUE)
        printf("        栈空!\n\n");   
    else
    {
        printf("          栈数据元素如下:\n\n");
        p=s->top;
        while(p>=0)
        {
            printf(" %d\n",s->data[p]);
            p--;

        }
        printf("\n\n");
    }
}

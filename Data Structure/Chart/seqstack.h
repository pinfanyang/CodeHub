typedef struct/*顺序栈定义*/ 
{ 
    DataType data[MAXNUM];    /*  存放栈的数据元素  */
    int top;              /*  栈顶指针，用来存放栈顶元素在数组中的下标  */
}SeqStack;
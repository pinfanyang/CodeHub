/* ① 置空队 */
SeqQueue *SQueueCreate()	/*创建一个空队列*/
{  
    SeqQueue *sq = (SeqQueue*)malloc(sizeof(SeqQueue));
    if (sq==NULL)
        printf("溢出!! \n");
    else
        sq->front = sq->rear = 0;
    return sq;
}

/* ② 判队空函数 */
int  SQueueIsEmpty( SeqQueue *sq )        /*判队列是否为空队列*/ 
{
    if(sq->front == sq->rear)
return TRUE;
else 
return FALSE;
}

/* ③ 进队 */
void  SQueueEnQueue( SeqQueue *sq, DataType x )      	    /* 循环队列的进队操作，x进队 */ 
{
    if( (sq->rear + 1) % MAXNUM == sq->front  )                	      /*  修改队尾指针  */
        printf( "队列满!\n" );
    else 	
{
sq->rear = (sq->rear + 1) % MAXNUM;
sq->data[sq->rear] = x;
    }
}

/* ④ 出队 */
int  SQueueDeQueue( SeqQueue *sq ,DataType *e)      	/* 循环队列的出队操作，出队元素存入e中 */ 
 {
    if( sq->front == sq->rear )
    {
printf( "队空!\n" );
return ERROR;
}
    else
{ 
         sq->front = (sq->front + 1) % MAXNUM;       	              /*  修改队头指针  */
*e=sq->data[sq->front];
return OK;
}

}
/* ⑤ 读对头元素 */
DataType  SQueueFront(SeqQueue *sq) 	  /*  读出队头元素，但队头指针保持不变 */
{
if (sq->front == sq->rear)
{
  printf("队空下溢\n");
          return ERROR;     	     /*  队列为空  */
}
else
return(sq->data[(sq->front+1)%MAXNUM]);
}

/* ⑥ 输出循环队列 */
void SQueuePrint(SeqQueue *sq)   	                        /* 输出循环队列中所有元素 */ 
{
int i=(sq->front+1)%MAXNUM;
while(i!=sq->rear)
{
printf("\t%d ",sq->data[i]);
i=(i+1) % MAXNUM;
}
}

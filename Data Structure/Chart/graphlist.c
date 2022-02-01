void LUDGCreate(GraphList *g)/*创建无向网邻接表*/
{
	int i,j,k;
	EdgeNode *s;
	float w;/*权值*/
	printf("\n请输入无向网的顶点的个数(不超过%d个)\n",MAXVEX);
	scanf("%d",&g->vexNum);
	printf("\n请输入网中各个顶点的数据信息(如v1)!\n");
	getchar();/*去掉回车符*/
	for(i=0;i<g->vexNum;i++)/*初始化*/
	{
		gets(g->vexs[i].vertex);
		g->vexs[i].edgelist=NULL;
	}
	printf("\n请输入该网中边的数目(不超过%d条)\n",g->vexNum*(g->vexNum-1)/2);
	scanf("%d",&g->edgeNum);/*读入边的数目*/
	for(k=0;k<g->edgeNum;k++)
	{
		printf("\n请输入第%d条边的相关信息(起始顶点(序号从0开始) 终止顶点 权值,如0 3 10.5)\n",k+1);
		scanf("%d%d%f",&i,&j,&w);/*读入边的起止点及权值*/
		s=(EdgeNode *)malloc(sizeof(EdgeNode));/*生成边结点*/
		s->endvex = j;
		s->nextedge=g->vexs[i].edgelist;
		s->weight=w;
		g->vexs[i].edgelist=s;
		s=(EdgeNode *)malloc(sizeof(EdgeNode));/*无向网,边对称*/
		s->endvex = i;
		s->nextedge=g->vexs[j].edgelist;
		s->weight=w;
		g->vexs[j].edgelist=s;
	}
}
int LUDGLocateVex(GraphList *g, VexType u)/*若g中存在顶点u,则返回该顶点在图中位置;否则返回ERROR*/
 { 
   int i;
   for(i=0;i<g->vexNum;++i)
     if(strcmp(u,g->vexs[i].vertex)==0)
       return i;
   return ERROR;
 }
int LUDGFirstVertex(GraphList* pgraph) /*查找图的第一个顶点*/
{    
    return pgraph->vexNum == 0 ? ERROR : 0;
}
int LUDGNextVertex(GraphList* pgraph,int i) /*查找相对于顶点i的下一个顶点*/
{    
    return i == pgraph->vexNum-1 ? ERROR : i+1;
}
int LUDGFirstAdjacent(GraphList* pgraph, int i)/*查找顶点i的第一个邻接顶点*/ 
{
    if (pgraph->vexs[i].edgelist != NULL)
        return pgraph->vexs[i].edgelist->endvex;
    else return ERROR; 
}  
int LUDGNextAdjacent(GraphList* pgraph, int i, int j) /*图中顶点i相对于顶点j的下一个邻接顶点*/
{
    EdgeNode *p;
    for (p = pgraph->vexs[i].edgelist; p != NULL; p = p->nextedge)
        if (p->endvex == j) {
            if (p->nextedge != NULL)
                return p->nextedge->endvex;
            else 
                return ERROR;
        }
    return ERROR; 
}   
void LUDGbfs( GraphList* g , DataType v ,int visited[]) /*连通图的邻接表存储广度优先遍历,需要使用队列*/
{	/*visited数组变量,用于标记访问过的顶点*/
    DataType v1 , v2;
    SeqQueue *q = SQueueCreate( ) ;   /* 队列元素的类型为DataType* */
    SQueueEnQueue( q ,v ) ;/*初始顶点入队*/
    printf("%d ",v);
    visited[v] = TRUE ;/*置访问标志*/
    while ( !SQueueIsEmpty(q) ) /*队列不空情况下循环*/
	{
        SQueueDeQueue( q,&v1 );/*队头元素出队*/
        v2 = LUDGFirstAdjacent ( g ,v1 );/*找到v1的第一个邻接顶点*/
        while ( v2 != ERROR )/*当v1的邻接顶点存在*/
		{
            if ( visited[v2] == FALSE )/*未访问过,则置访问标志,同时入队*/
			{
   	            SQueueEnQueue( q,  v2 );
                visited[v2] = TRUE ;
                printf("%d ",v2);
            }
            v2 = LUDGNextAdjacent ( g , v1 , v2 ) ;/*再取下一个邻接顶点*/
        }
    }
}
void LUDGbft( GraphList* g,int visited[])/*非连通图的邻接表存储广度优先遍历*/
{
    DataType v ;
    for ( v = LUDGFirstVertex ( g ) ; v != ERROR ; v = LUDGNextVertex ( g , v ) )
        if ( visited[v] == FALSE ) LUDGbfs ( g , v,visited ) ;/*对图中每一个未访问过的顶点,递归遍历*/
} 

void LUDGdfs(GraphList* g , DataType v,int visited[])/*连通图的邻接表表示深度优先遍历*/
{
	EdgeNode *p;
	printf("%d",v);/*输出顶点信息,置访问标志*/
	visited[v]=TRUE;
	p=g->vexs[v].edgelist;/*取出邻接顶点链表头*/
	while(p!=NULL)/*邻接顶点存在*/
	{
		if(!visited[p->endvex])/*未访问过则递归访问*/
			LUDGdfs(g,p->endvex,visited);
		p=p->nextedge;/*取下一邻接顶点*/
	}
}
void LUDGdft( GraphList* g,int visited[] )/*非连通图的邻接表表示深度优先遍历*/
{
    DataType v ;
    for ( v=0 ; v<g->vexNum ; v++ )/*对图中每一个未访问过的顶点,递归遍历*/
        if ( visited[v] == FALSE ) LUDGdfs ( g , v,visited ) ;
} 


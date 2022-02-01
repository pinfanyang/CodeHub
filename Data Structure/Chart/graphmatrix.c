/*建立无向图,有向图,有向网与建立无向网的方法类似。无向图仅需将权值改为1
有向图仅需将权值为1(不再需要输入权值)且边不对称,即g->arcs[i][j]=1;有向网仅是边不对称*/
void MUDGCreate(GraphMatrix *g)/*建立无向网*/
{
	int i,j,k,t;
	float w;/*权值*/
	printf("\n请输入无向网的顶点的个数(不超过%d个)\n",MAXVEX);
	scanf("%d",&g->vexNum);
	printf("\n请输入图的各个顶点的数据信息(如v1)!\n");
	getchar(); /*去掉回车*/
	for(i=0;i<g->vexNum;i++)/*输入各顶点信息*/
		gets(g->vexs[i]);
	for(i=0;i<g->vexNum;i++)/*初始化邻接矩阵*/
		for(j=0;j<g->vexNum;j++)
			g->arcs[i][j]=0;/*以0表示两顶点间没有路径,且假定某顶点间无指向自己的环*/
	printf("\n请输入该网中边的数目(不超过%d条)\n",g->vexNum*(g->vexNum-1)/2);
	scanf("%d",&k);/*读入边的数目*/
	for(t=0;t<k;t++)
	{
		printf("\n请输入第%d条边的相关信息(起始顶点(序号从0开始) 终止顶点 权值,如0 3 10.5)\n",t+1);
		scanf("%d%d%f",&i,&j,&w);
		g->arcs[i][j]=w;/*无向网对称*/
		g->arcs[j][i]=w;
	}
}
int MUDGFirstVertex(GraphMatrix* pgraph) /*求图的第一个顶点*/
{    
    return pgraph->vexNum == 0 ? ERROR : 0;
}
int MUDGNextVertex(GraphMatrix* pgraph,int i)/*求图中相对于顶点i的下一个顶点*/
{    
    return i == pgraph->vexNum-1 ? ERROR : i+1;
}
int MUDGFirstAdjacent(GraphMatrix* pgraph, int i)/*求图中与i邻接的第一个顶点*/
{
    int k;
    for (k = 0; k < pgraph->vexNum; k++)
        if(pgraph->arcs[i][k] != 0) return k;
    return ERROR; 
} 
int  MUDGNextAdjacent(GraphMatrix* pgraph, int i, int j)/*求图中顶点i相对于顶点j的下一个邻接顶点*/
{
    int k;
    for (k = j+1; k < pgraph->vexNum; k++)
        if (pgraph->arcs[i][k] != 0) return k;
    return ERROR; 
}   
int MUDGLocateVex(GraphMatrix *g, VexType u)/*操作结果: 若g中存在顶点u,则返回该顶点在图中位置;否则返回-1*/
 {
   int i;
   for(i=0;i<g->vexNum;++i)
     if(strcmp(u,g->vexs[i])==0)
       return i;
   return ERROR;
 }
/*******************以下是图深度优先遍历函数部分,需要配合队列使用**********************/

void MUDGbfs( GraphMatrix* g , DataType v ,int visited[])/*连通图的邻接矩阵表示的广度优先遍历*/
{	/*vistied数组，用于图的遍历标志顶点是否被访问过*/
    DataType v1 , v2;
    SeqQueue *q = SQueueCreate();       /*顺序队列元素的类型为DataType*/
    SQueueEnQueue( q, v ) ;/*初始顶点入队*/
    printf("%d ", v);
    visited[v] = TRUE ;/*初始顶点被访问过*/
    while ( !SQueueIsEmpty(q) )
	{
        SQueueDeQueue(q,&v1);/*队头元素出队,并将队头元素保存 到V1中*/
        v2 = MUDGFirstAdjacent ( g, v1 );
        while ( v2!= ERROR )/*邻接顶点存在时循环*/
		{
            if ( visited[v2] == FALSE )/*若邻接顶点未被访问则入队，置标志*/
			{
                SQueueEnQueue( q,  v2 );
                visited[v2] = TRUE ;
                printf("%d ", v2);
            }
            v2 = MUDGNextAdjacent( g, v1 , v2 ) ;/*取下一顶点*/
        }
    }
}
void MUDGbft(GraphMatrix* g,int visited[] )/*非连通图的广度优先遍历*/
{
    DataType v ;
    for ( v =MUDGFirstVertex ( g ) ; v != ERROR ; v = MUDGNextVertex ( g , v ) )
        if ( visited[v] == FALSE ) MUDGbfs( g , v,visited) ;/*对于v的每一个未访问邻接点递归访问*/ 
} 
/********************************************************************/
/*************以下是图的深度优先遍历函数部分,需要配合队列使用****************/
void MUDGdfs( GraphMatrix* g , DataType v,int visited[] )/*连通图的深度优先遍历*/ 
{
    DataType v1;
    visited[v] = TRUE ;/*置访问标志*/ 
    printf("%d ",v);
    for ( v1 = MUDGFirstAdjacent(g , v); v1 != ERROR ; v1=MUDGNextAdjacent(g ,v, v1) )
        if(visited[v1]==FALSE) MUDGdfs( g ,v1,visited );/*对于v的每一个未访问邻接点递归访问*/
}
void MUDGdft( GraphMatrix* g ,int visited[]) /*非连通图的深度优先遍历*/
{
    DataType v ;
    for ( v =MUDGFirstVertex ( g ) ; v != ERROR ; v = MUDGNextVertex ( g , v ) )
        if ( visited[v] == FALSE ) MUDGdfs( g , v,visited ) ;/*对图中每一个未访问顶点递归访问*/
}
/********************************************************************/

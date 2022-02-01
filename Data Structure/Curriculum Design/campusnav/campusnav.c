/* 顶点对最短路径迪杰斯特拉算法 */
#include "consts.h"
#define MAXVEX  30                        
#define MAXNAME 20

typedef char VexType[MAXNAME];
typedef int AdjType;

typedef struct
{
    int n;                                           /* 图的顶点个数 */
    VexType vexs[MAXVEX];                   /* 顶点信息 */
    AdjType arcs[MAXVEX][MAXVEX];           /* 边信息 */
} GraphMatrix;

typedef struct/* 保存最短路径的结构体 */
{
    AdjType len;/* 最短路径长度 */
    int pre;/* 前一顶点 */
}Path;

int LocateVex(GraphMatrix *g, VexType u)/*在图g中查找顶点u的编号*/
 {    
   int i;
   for(i=0;i<g->n;++i)
     if(strcmp(u,g->vexs[i])==0)
       return i;
   return ERROR;
 }

void Init(GraphMatrix *g)/* 初始化有向网,读入校园地图文件 */
{
	int i,j,k,w;
	int edgeNums;/*网中边的条数*/
	VexType va,vb;/*定位边的两个顶点*/
	FILE *graphlist;
	graphlist=fopen("campusnav.txt","r");/*打开数据文件,并以graphlist表示*/
	fscanf(graphlist,"%d",&g->n);/*读入网的顶点个数*/
	fscanf(graphlist,"%d",&edgeNums);
	for(i=0;i<g->n;++i) /*构造顶点向量*/
		fscanf(graphlist,"%s",g->vexs[i]);
	for(i=0;i<g->n;++i) /*初始化邻接矩阵*/
		for(j=0;j<g->n;++j)
			g->arcs[i][j]=INT_MAX; /*有权值的网，无路径则置路径为无穷*/
	for(k=0;k<edgeNums;++k)
	{
		fscanf(graphlist,"%s%s%d",va,vb,&w);
		i=LocateVex(g,va);
		j=LocateVex(g,vb);
		if(i!=ERROR && j!=ERROR)/*两个城市在网中存在*/
			g->arcs[i][j]=w; /*有向网*/
		else 
		{
			printf("%s<->%s读取错误,请您仔细检查!!",va,vb);
			exit(0);
		}
	}
	for(i=0;i<g->n;i++)/* 顶点到自身的权值为0 */
		g->arcs[i][i]=0;
   fclose(graphlist); /*关闭数据文件*/
}

void Dijkstra(GraphMatrix *pgraph, Path dist[],int start)
{
    int i, j, min;
 	AdjType minw;
	dist[start].len=0;
	dist[start].pre=0; 
	pgraph->arcs[start][start]=1;/* 表示顶点start在集合U中 */
	
	for(i=0; i<pgraph->n; i++)/* 初始化集合V-U中顶点的距离值 */
	{		
		dist[i].len=pgraph->arcs[start][i];/* 初始距离为给定起始点到各顶点的边的权值 */ 
		if(dist[i].len!=INT_MAX)/* 若边存在则顶点i的前趋顶点为start,否则不存在置为-1 */
			dist[i].pre=start;
		else
			dist[i].pre= -1;
	}
	dist[start].pre = -1;/* 出发点的前趋置为-1 */
	for(i=0; i<pgraph->n; i++)
	{
		minw=INT_MAX;
		min=start;
		for(j=0; j<pgraph->n; j++)
		if( (pgraph->arcs[j][j]==0) && (dist[j].len<minw) ) /*在V-U中选出距离值最小顶点*/
		{
			minw=dist[j].len; 
			min=j;  
		}
		if(min==0) /* 没有路径可以通往集合V-U中的顶点 */
			break;			
		pgraph->arcs[min][min]=1;	/* 集合V-U中路径最小的顶点为min,置访问标志 */
		for(j=0; j<pgraph->n; j++)/* 调整集合V-U中的顶点的最短路径 */
		{			
			if(pgraph->arcs[j][j]==1)/* 该顶点已经并入,不用再考虑 */
				continue;
			if(dist[j].len>dist[min].len+pgraph->arcs[min][j] && dist[min].len+pgraph->arcs[min][j]>0)
			{
				dist[j].len=dist[min].len+pgraph->arcs[min][j];
				dist[j].pre=min;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	GraphMatrix graph;
	Path path[MAXVEX];
	int tmp,cnt=0,pre=-1;
	int temppath[MAXVEX];
	int m,n;
	VexType va,vb;/* 待查询的两个地点 */
	long totallen=0;/*总路径长度*/
	long curlen=0;/*当前路径长度*/
    Init(&graph);

	printf("\n  请输入您要查询的起点和终点\n  ");
	scanf("%s%s",va,vb);
	m=LocateVex(&graph,va);/*查找图中的两个顶点*/
	n=LocateVex(&graph,vb);
	if(m!=ERROR && n!=ERROR)/*两个顶点都在图中，则找出二者间最短路径输出*/
	{	
		Dijkstra(&graph, path,m);
		/* 因为求得的路径上顶点是从终点推到起点,现在将之逆置 */
		for(tmp=0;tmp<MAXVEX;tmp++)
			temppath[tmp]=-1;
		pre=n;
		while(path[pre].pre!=-1)
		{
			temppath[cnt]=pre;/* 保存逆序顶点序列 */
			pre=path[pre].pre;
			cnt++;
		}
		temppath[cnt]=m;

		if(cnt<=0)/* 没有路径 */
			if(m!=n)
				printf("%s->%s无路可走\n!",graph.vexs[m],graph.vexs[n]);
			else
				printf("您输入的顶点重合!\n");
		else
		{
			tmp=cnt;
			printf("%s->",graph.vexs[temppath[tmp]]);
			for(;tmp>0;tmp--)
			{
				printf("%s(%d)->",graph.vexs[temppath[tmp-1]],graph.arcs[temppath[tmp]][temppath[tmp-1]]);
				totallen+=graph.arcs[temppath[tmp]][temppath[tmp-1]];
			}
			printf("共:%d\n",totallen);
		}
	}
	else
		printf("(%s<->%s)中有不存在的城市,请您仔细检查!!",va,vb);
    return 0;
}


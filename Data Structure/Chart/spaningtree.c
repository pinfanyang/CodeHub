/* 最小生成树.c */
#include "consts.h"
#define MAXVEX 30
#define MAXNAME 20/*顶点信息长度最大值*/
#define MAX 32767/*若顶点间无路径则以此最大值表示不通*/
typedef char VexType[MAXNAME];/*顶点信息*/
typedef float AdjType;/*两顶点间的权值信息*/
typedef struct/*边结构体*/
{
    int start_vex, stop_vex;        /* 边的起点和终点 */
    AdjType weight;                 /* 边的权 */
} Edge;
typedef struct/*图结构*/
{
    int vexNum;                     /* 图的顶点个数 */
	int edgeNum;					/*图中边的数目*/
	Edge mst[MAXVEX-1];				/*用于保存最小生成树的边数组,只用到 顶点数-1 条*/

    VexType vexs[MAXVEX];			/*顶点信息 */
    AdjType arcs[MAXVEX][MAXVEX];   /* 边的邻接矩阵 */
} GraphMatrix;
int LocateVex(GraphMatrix *g, VexType u)/*操作结果: 若g中存在顶点u,则返回该顶点在图中位置;否则返回-1*/
 {
   int i;
   for(i=0;i<g->vexNum;++i)
     if(strcmp(u,g->vexs[i])==0)
       return i;
   return ERROR;
 }
void GraphInit(GraphMatrix *g)/*用包含图的信息的文件初始化图*/
{
	int i,j,t;
	float w;/*边的权值*/
	VexType va,vb;/*用于定位图的顶点(字符串)在邻接矩阵中的下标*/
	FILE *fp;
    fp=fopen("spaningtree.txt","r");
	fscanf(fp,"%d",&g->vexNum);/*读入图的顶点数和边数*/
	fscanf(fp,"%d",&g->edgeNum);
	for(i=0;i<g->vexNum;i++)/*初始化邻接矩阵*/
		for(j=0;j<=i;j++)
			g->arcs[i][j]=g->arcs[j][i]=MAX;
	for(i=0;i<g->vexNum;i++)/*从文件读入顶点信息*/
		fscanf(fp,"%s",g->vexs[i]);
	for(t=0;t<g->edgeNum;t++)/*定位各边并赋权值*/
	{
		fscanf(fp,"%s%s%f",va,vb,&w);
		i=LocateVex(g,va);
		j=LocateVex(g,vb);
		g->arcs[i][j]=g->arcs[j][i]=w;
	}
	fclose(fp);
}
void Prim(GraphMatrix * pgraph)/* 用邻接矩阵求图的最小生成树-普里姆算法*/
{
    int i, j, min;
	int vx, vy; /*起始,终止点*/
    float weight, minweight; 
	Edge edge;/*用于交换边*/
    for (i = 0; i < pgraph->vexNum-1; i++)/*初始化最小生成树边的信息*/
	{
        pgraph->mst[i].start_vex = 0;/*起始点为0号顶点*/
        pgraph->mst[i].stop_vex = i+1;/*终止点为其他各顶点*/
        pgraph->mst[i].weight = pgraph->arcs[0][i+1];/*权值为0号顶点到其他各顶点的路径权值,无路径则为MAX*/
    }
    for (i = 0; i < pgraph->vexNum-1; i++)/* 共n-1条边 */
	{
        minweight = MAX;  min = i;
        for (j = i; j < pgraph->vexNum-1; j++)/* 从所有边(vx,vy)(vx∈U,vy∈V-U)中选出最短的边 */
            if(pgraph->mst[j].weight < minweight)
			{
                minweight = pgraph->mst[j].weight; 
                min = j;
            }
        /* mst[min]是最短的边(vx,vy)(vx∈U, vy∈V-U)，将mst[min]加入最小生成树 */
        edge = pgraph->mst[min];  
        pgraph->mst[min] = pgraph->mst[i];   
        pgraph->mst[i] = edge;
        vx = pgraph->mst[i].stop_vex;            /* vx为刚加入最小生成树的顶点的下标 */
        for(j = i+1; j < pgraph->vexNum-1; j++) /* 调整mst[i+1]到mst[n-1] */
		{ 
            vy=pgraph->mst[j].stop_vex;
			weight = pgraph->arcs[vx][vy];
            if (weight < pgraph->mst[j].weight) 
			{
                pgraph->mst[j].weight = weight;  
                pgraph->mst[j].start_vex = vx;
            }
        }
    }
}
int main(int argc, char* argv[])
{
    int i;
	float totallen=0;
	GraphMatrix graph;
	GraphInit(&graph);/*用图信息文件初始化图*/
    Prim(&graph);/*用普里姆算法求出该图的最小生成树*/
	printf("\n  应建设以下地铁路线!!\n\n");
    for (i = 0; i < graph.vexNum-1; i++)/*打印生成树信息*/
	{
		printf("  %s<->%s段,%.2f公里)\n", graph.vexs[graph.mst[i].start_vex],graph.vexs[graph.mst[i].stop_vex], graph.mst[i].weight);
		totallen+=graph.mst[i].weight;
	}
	printf("\n  总路线长%f公里\n",totallen);
	getchar();
	return 0;
}

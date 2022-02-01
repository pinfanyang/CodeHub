/* 拓扑排序邻接表.c */
#include "consts.h"
typedef int DataType;
#define MAXNUM 30/*顺序栈元素个数最大值*/
#include "seqstack.h"
#include "seqstack.c"
#define MAXVEX 30/*图中顶点个数最大值*/ 
#define MAXNAME 20/*图中顶点名称最大值*/ 
#include "sequeue.h"/*图的基本操作中遍历函数使用这两个文件*/ 
#include "sequeue.c" 
typedef char VexType[MAXNAME];/*顶点信息*/
typedef float AdjType;/*权值*/ 
#include "graphlist.h"
#include "graphlist.c" 

void LDGCreate(GraphList *g)/*建立有向图的邻接表*/
{
	int i,j,t;
	VexType va ,vb; 
	EdgeNode *s;
	FILE *fp;
    fp=fopen("topologysort.txt","r");
	fscanf(fp,"%d",&g->vexNum);/*读入课程门数和先行后继关系数*/
	fscanf(fp,"%d",&g->edgeNum);
	for(i=0;i<g->vexNum;i++)
	{
		fscanf(fp,"%s",g->vexs[i].vertex);
		g->vexs[i].edgelist=NULL;
	}
	for(t=0;t<g->edgeNum;t++)/*读入各门课程的先行后继关系边*/
	{
		fscanf(fp,"%s%s",va,vb);
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		i=LUDGLocateVex(g,va);
		j=LUDGLocateVex(g,vb);
		s->endvex = j;
		s->nextedge=g->vexs[i].edgelist;
		g->vexs[i].edgelist=s;
	}
	fclose(fp);
}
void FindInDegree(GraphList g,int inDegree[])/*求出图的各个顶点的入度，结果保存到数组中*/
{
	int i;
	EdgeNode *p;
	for(i=0;i<g.vexNum;i++)/*初始化*/
		inDegree[i]=0;
	for(i=0;i<g.vexNum;i++)
	{
		p=g.vexs[i].edgelist;/*取出第i个顶点，将由该顶点所发出的弧所对应的弧尾结点的入度加1*/
		while(p)
		{
			inDegree[p->endvex]++;
			p=p->nextedge;/*取下一个以该顶点为弧为的边*/
		}
	}
}
int TopologicalSort(GraphList g,int *res)
{
	int i,k,count=0;
	int inDegree[MAXVEX];/*保存各顶点入度的数组*/
	SeqStack s;/*顺序栈保存各入度为0的顶点序号*/
	EdgeNode *p;
	FindInDegree(g,inDegree);/*拓扑排序前求出各顶点的入度信息*/
	SStackSetNull(&s);
	for(i=0;i<g.vexNum;i++)/*先将入度为0的顶点入栈*/
		if(!inDegree[i])
			SStackPush(&s,i);
	while(!SStackIsEmpty(&s))/*栈不空时，进行拓扑排序*/
	{
		SStackPop(&s,&i);/*栈顶元素出栈，该出栈序列即为拓扑排序的序列*/
		*res++=i;/*保存出栈顶点的序号*/
		count++;/*出栈顶点个数加1*/
		for(p=g.vexs[i].edgelist;p;p=p->nextedge)/*对以该顶点为弧尾的边的弧头顶点入度减1*/
		{
			k=p->endvex;
			if(!(--inDegree[k]))/*若处理后顶点入度为0则入栈*/
				SStackPush(&s,k);
		}
	}
	if(count<g.vexNum)/*有回路*/ 
		return ERROR;
	else
		return OK;
}

int main(int argc, char* argv[])
{
	int i,res[MAXVEX];/*用于保存拓扑排序顶点序列的数组*/
	GraphList g;
	GraphList *pg=&g;
	LDGCreate(pg);
	for(i=0;i<MAXVEX;i++) res[i]=-1; 
	if(TopologicalSort(g,res))
	{
		printf("\n  可以按以下顺序安排课程!\n");
		printf("  "); 
		for(i=0;i<g.vexNum-1;i++)
		{   
			if(i%5==0)
			{
				printf("\n" );
				printf("  " );
			} 
			printf("%s->",g.vexs[res[i]].vertex);/*输出顶点信息*/

		} 
		printf("%s\n",g.vexs[res[i]].vertex);
	}
	else
		printf("\n  您输入的课程先行后继关系有错误(存在环)!!\n");
		getchar();
	return 0;
}


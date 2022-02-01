#include "consts.h" 
#define MAXNUM 30 /*队列元素最大值为30*/
#define MAXVEX 30/*邻接表中顶点个数最大值*/ 
#define MAXNAME 20/*邻接表中顶点名称最大值*/
typedef int DataType;/*队列元素类型为整型*/
#include "sequeue.h"
#include "sequeue.c"
typedef char VexType[MAXNAME];/*顶点的信息域*/
typedef float AdjType;/*边的信息,一般为权值*/
#include "graphlist.h"
#include "graphlist.c"
 
int main(int argc, char* argv[])
{
	int i=0;
	int res;
	GraphList g;
	GraphList *pg=&g;
	int visited[MAXVEX];/*遍历标志数组*/
	for(;i<MAXVEX;i++)
		visited[i]=FALSE;
	printf("\n创建无向网的邻接表,并对其进行遍历!\n");
	LUDGCreate(pg);
	res=LUDGFirstVertex(pg);
	res=LUDGFirstAdjacent(pg,0);
	res=LUDGNextVertex(pg,0);
	res=LUDGNextAdjacent(pg,0,1);
	printf("\n遍历结果为:\n");
	LUDGdft(pg,visited);
	return 0;
}

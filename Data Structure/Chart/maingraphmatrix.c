#include "consts.h"
#define MAXNAME 20/*顶点信息最大长度*/
#define MAXVEX 30/*顶点个数最大值*/
#define MAXNUM 30  /* 队列中最大元素个数 */
typedef int DataType;/*队列元素类型*/
typedef char VexType[MAXNAME];/*顶点信息*/
typedef float AdjType;/*权值*/ 
#include "sequeue.h"		//队列结构体定义
#include "sequeue.c"		//队列功能实现
#include "graphmatrix.h"	//图的结构体定义
#include "graphmatrix.c"	//图的功能实现
int main()
{
	int i=0;
	int res;
	GraphMatrix g;
	GraphMatrix *pg=&g;
	int visited[MAXVEX];/*遍历标志数组*/
	for(;i<MAXVEX;i++)
		visited[i]=FALSE;
	printf("\n创建无向网的邻接矩阵,并对其进行遍历!\n");
	MUDGCreate(pg);
	res=MUDGFirstVertex(pg);
	res=MUDGFirstAdjacent(pg,0);
	res=MUDGNextVertex(pg,0);
	res=MUDGNextAdjacent(pg,0,1);
	printf("\n遍历结果为:\n");
	MUDGdft(pg,visited);/*深度优先遍历*/
	return 0;
}


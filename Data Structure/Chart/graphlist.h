typedef struct EdgeNode/*图的边结构定义*/
{
    int endvex;			/* 相邻顶点字段 */
    AdjType weight;		/* 边的权，非带权图可以省略 */
    struct EdgeNode *nextedge;	/* 链字段 */
}EdgeNode;	                    /* 边表中的结点 */
typedef struct /*图的顶点结构定义*/
{
    VexType vertex;		/* 顶点信息 */
    EdgeNode *edgelist;	/* 边表头指针 */
} VexNode;               /* 顶点表中的结点 */
typedef struct /*图的数据结构定义*/
{
	int vexNum;				/* 图的顶点个数 */
	int edgeNum;			/* 图的边的条数 */
	VexNode vexs[MAXVEX];
} GraphList;/*图的邻接表存储结构*/

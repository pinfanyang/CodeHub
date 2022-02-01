typedef struct/*图的邻接矩阵数据结构*/ 
{
    int vexNum;                                 /* 图的顶点个数 */
    VexType vexs[MAXVEX];                 /* 顶点信息 */
    AdjType arcs[MAXVEX][MAXVEX];           /* 边信息 */
}GraphMatrix;

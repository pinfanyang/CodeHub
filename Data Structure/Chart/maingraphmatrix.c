#include "consts.h"
#define MAXNAME 20/*������Ϣ��󳤶�*/
#define MAXVEX 30/*����������ֵ*/
#define MAXNUM 30  /* ���������Ԫ�ظ��� */
typedef int DataType;/*����Ԫ������*/
typedef char VexType[MAXNAME];/*������Ϣ*/
typedef float AdjType;/*Ȩֵ*/ 
#include "sequeue.h"		//���нṹ�嶨��
#include "sequeue.c"		//���й���ʵ��
#include "graphmatrix.h"	//ͼ�Ľṹ�嶨��
#include "graphmatrix.c"	//ͼ�Ĺ���ʵ��
int main()
{
	int i=0;
	int res;
	GraphMatrix g;
	GraphMatrix *pg=&g;
	int visited[MAXVEX];/*������־����*/
	for(;i<MAXVEX;i++)
		visited[i]=FALSE;
	printf("\n�������������ڽӾ���,��������б���!\n");
	MUDGCreate(pg);
	res=MUDGFirstVertex(pg);
	res=MUDGFirstAdjacent(pg,0);
	res=MUDGNextVertex(pg,0);
	res=MUDGNextAdjacent(pg,0,1);
	printf("\n�������Ϊ:\n");
	MUDGdft(pg,visited);/*������ȱ���*/
	return 0;
}


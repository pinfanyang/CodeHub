#include"consts.h"
#include"������.c"

int main()
{
	BTree tree,a;
	int deep;
	tree = CreateBinTree0();
	/*deep = BTreeDepthPost(tree);*/
	printf("\n�����������:     ");
	EnPreOrder(tree);
	printf("\n�����������:     ");
	EnInOrder(tree);
	printf("\n�����������:     ");
	EnPostOrder(tree);
	printf("\n");
	printf("\n���������У�	");
	LevelOrder(tree);
	printf("\n");
  	DispBTree(tree);
	printf("\n");
	printf("%d",Count(tree));
	/*printf("\n�������������ȣ�%d\n", deep);

	printf("%d",leafs(tree));

	a=swap(tree);*/

	TranslevelPrint(tree);
	PreOrderLeaf(tree);
	return 0;
}
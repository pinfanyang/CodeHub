#include"consts.h"
#include"二叉树.c"

int main()
{
	BTree tree,a;
	int deep;
	tree = CreateBinTree0();
	/*deep = BTreeDepthPost(tree);*/
	printf("\n输出先序序列:     ");
	EnPreOrder(tree);
	printf("\n输出中序序列:     ");
	EnInOrder(tree);
	printf("\n输出后序序列:     ");
	EnPostOrder(tree);
	printf("\n");
	printf("\n输出逐层序列：	");
	LevelOrder(tree);
	printf("\n");
  	DispBTree(tree);
	printf("\n");
	printf("%d",Count(tree));
	/*printf("\n输出二叉树的深度：%d\n", deep);

	printf("%d",leafs(tree));

	a=swap(tree);*/

	TranslevelPrint(tree);
	PreOrderLeaf(tree);
	return 0;
}
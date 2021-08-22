#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/


void test01()
{
	TreeNode* node1 =new TreeNode(1);
	TreeNode* node2l = new TreeNode(2);
	TreeNode* node2r = new TreeNode(7);
	TreeNode* node31l = new TreeNode(8);
	TreeNode* node31r= new TreeNode(9);
	TreeNode* node32l = new TreeNode(4);
	TreeNode* node32r= new TreeNode(3);

	node1->left = node2l;
	node1->right = node2r;

	node2l->left = node31l;
	node2l->right = node31r;

	node2r->left = node32l;
	node2r->right = node32r;

	recursionTree(node1);
	cout << endl;

	levelOrder(node1);
	levelOrder2(node1);
	levelOrder3(node1);

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
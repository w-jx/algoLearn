#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
void test01()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node6 = new TreeNode(6);

	node1->left = node3;
	node1->right = node4;
	node3->left = node7;
	node3->right = node8;
	node4->left = node9;
	node4->right = node6;

	levelOrder4(node1);

	

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
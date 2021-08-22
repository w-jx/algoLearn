#if 0
#include "../headers/wjxHeaders.h"
/*
找到二叉树根结点到指定结点的路径


*/
vector<int> path;
void  getpath(TreeNode* root, TreeNode* node, vector<int> temp) {
	if (!root)
		return;
	temp.push_back(root->val);
	if (root == node) {
		path = temp;
		return;
	}
	
	if (root->left)
		getpath(root->left, node, temp);
	if (root->right)
		getpath(root->right, node, temp);
	temp.pop_back();
}
void test01()
{
	TreeNode* root = new TreeNode(3, 5, 1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2, 7, 4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	getpath(root, root->left->right, {});

	printVector(path);

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
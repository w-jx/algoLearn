#if 0
#include "../headers/wjxHeaders.h"
/*

*/
//为了解决这道题,我们看看同样子结构的子树==返回什么
bool isequal(TreeNode* node1, TreeNode* node2) {
	if (!node1 && !node2)
		return true;
	if ((node1 && !node2) || (!node1 && node2)|| (node1->val !=node2->val))
		return false;

	bool isleftok = isequal(node1->left, node2->left);
	bool isrightok = isequal(node1->right, node2->right);

	return isleftok && isrightok;
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	if (!subRoot || !root)
		return false;
	if (isequal(root,subRoot))
		return true;
	bool isleftOk = isSubtree(root->left, subRoot);
	bool isRightOk = isSubtree(root->right, subRoot);

	return isleftOk || isRightOk;
}
void test01()
{
	TreeNode* root1 = new TreeNode(4, 1, 2);
	TreeNode* root2 = new TreeNode(4, 1, 2);

	cout << isequal(root1, root2) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
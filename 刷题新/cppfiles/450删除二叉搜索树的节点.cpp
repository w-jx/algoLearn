#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

如果目标节点大于当前节点值，则去右子树中删除；
如果目标节点小于当前节点值，则去左子树中删除；
如果目标节点就是当前节点，分为以下三种情况：
其无左子：其右子顶替其位置，删除了该节点；
其无右子：其左子顶替其位置，删除了该节点；
其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置，由此删除了该节点。


*/
//O(H)--->
TreeNode* deleteNode(TreeNode* root, int key)
{
	if (!root)//空二叉树，直接返回
		return root;
	if (key > root->val) root->right = deleteNode(root->right, key);//去右子树删除
	else if (key < root->val) root->left = deleteNode(root->left, key);//去左子树删除
	else {//当前节点就是待删除的节点
		if (!root->left) return root->right;//没有左子树，用右子树顶替
		if (!root->right) return root->left;//没有右子树 用左子树代替
		
		TreeNode* node = root->right;//首先获得右子树
		while (node->left)//要找右子树的最左节点
			node = node->left;

		node->left = root->left;
		root = root->right;//根节点改成右孩子
	}
	return root;
}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif
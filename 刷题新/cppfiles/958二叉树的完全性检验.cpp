#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
二叉树的完全性检验

除了叶子结点,所有结点都同时有左子树和右子树


*/
//这个不行
bool isCompleteTree(TreeNode* root) {
	if (!root)
		return true;
	deque<TreeNode*> que;
	que.push_back(root);

	//判断是否出现了有左边,没有右边
	//没有左子树,也没有右子树的情况
	bool occur = false;
	
	while (!que.empty()) {

		auto node = que.front();
		que.pop_front();
		if (occur && (node->left || node->right))
			return false;
		if (node->left && node->right) {
			que.push_back(node->left);
			que.push_back(node->right);
		}
		else if (!node->left && !node->right) {
			occur = true;
		}
		else if (!node->left && node->right)
			return false;
		else {//node->left !node->right
			occur = true;
			que.push_back(node->left);
		}
	}
	return true;
	

}

void test01()
{
	TreeNode* node = new TreeNode(1, new TreeNode(2, 4, 5), new TreeNode(3, 6, 7));
	node->left->left->left = new TreeNode(8);
	node->left->left->right = new TreeNode(9);
	node->left->right->left = new TreeNode(10);
	node->left->right->right = new TreeNode(11);
	node->left->left->left->left = new TreeNode(15);

	node->right->left->left = new TreeNode(12);
	node->right->left->right = new TreeNode(13);

	cout << isCompleteTree(node) << endl;
}
void test02()
{
	TreeNode* node = new TreeNode(1, 2,3);
	node->left->left = new TreeNode(4);
	node->left->right = new TreeNode(5);
	
	node->right->left = new TreeNode(6);
	cout << isCompleteTree(node) << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
#endif
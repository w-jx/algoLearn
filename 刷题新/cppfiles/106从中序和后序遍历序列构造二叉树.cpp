#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
int post_idx;
unordered_map<int, int> idx_map;

//因为后序遍历是左 右  根,所以反过来应该先根,再右,再左
TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder)
{
	//如果这时候没有结点构造二叉树，结束
	if (in_left > in_right)
		return nullptr;
	//选择post_idx位置的元素，作为当前子树的 根结点
	int root_val = postorder[post_idx];
	TreeNode* root = new TreeNode(root_val);

	//根据root所在位置分成左右两颗子树
	int index = idx_map[root_val];

	//下标减1
	post_idx--;

	//构造右子树
	root->right = helper(index + 1, in_right, inorder, postorder);
	//构造左子树
	root->left = helper(in_left, index - 1, inorder, postorder);
	return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	post_idx = postorder.size() - 1;
	//建立元素 和下标对应的哈希表
	int idx = 0;
	for (auto& val : inorder)
		idx_map[val] = idx++;
	return helper(0, post_idx, inorder, postorder);
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
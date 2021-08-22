#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

从根结点  到 叶子结点的 距离
*/
//递归：时间复杂度 对每个结点访问一次
//空间复杂度：0(H),H是数的高度
bool hasPathSum(TreeNode* root, int targetSum) {
	if (!root)
		return false;
	if (!root->left && !root->right)
		return root->val == targetSum;
	return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

bool hasPathSum(TreeNode* root, int targetSum) {
	if (!root)
		return false;
	stack<std::pair<TreeNode*, int> >  mystack;

	mystack.push({ root,root->val });

	while (!mystack.empty()) {
		auto node = mystack.top();
		mystack.pop();

		if (!node.first->left && !node.first->right) {
			if (node.second == targetSum)
				return true;
		}
		else {
			if (node.first->left)
				mystack.push({ node.first->left, node.second + node.first->left->val });
			if (node.first->right)
				mystack.push({ node.first->right, node.second + node.first->right->val });
		}
	}//while
	return false;
}
void preorder(TreeNode* node,
	int& path_val, int targetSum, vector<int>& path,
	vector<vector<int> > res) {

	if (!node)
		return;
	//遍历一个节点 更新一次路径值
	path_val += node->val;
	path.emplace_back(node->val);

	if (path_val == targetSum && !node->left && !node->right)
		res.push_back(path);
	preorder(node->left, path_val, targetSum, path, res);
	preorder(node->right, path_val, targetSum, path, res);

	path_val -= node->val;
	path.pop_back();


}
//用什么数据结构，栈
bool hasPathSum2(TreeNode* root, int targetSum)
{
	vector < vector<int> > res;//存储满足条件的数组
	vector<int> path;//路径栈，用vector模拟
	int path_val = 0;

	preorder(root,path_val,targetSum,path,res);
	return res.empty();


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
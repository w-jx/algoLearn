#if 0
#include "../headers/wjxHeaders.h"

//每三个结点一个组合输出一次
vector<vector<int>> res;
void helper(TreeNode* root) {
	if (!root)
		return;
	if (root && root->left && root->right) {
		res.push_back({ root->val,root->left->val,root->right->val });
	}
	helper(root->left);
	helper(root->right);
}
vector<vector<int>> getthreepath(TreeNode* root) {
	helper(root);
	return res;
}
/// <summary>
/// 返回当前节点为父节点提供的共享
/// </summary>
/// <param name="root"></param>
/// <param name="maxval"></param>
/// <returns></returns>
int dfs(TreeNode* root,int &maxval) {
	if (!root)
		return 0;
	//最大路径和不一定包括根结点
	//我们求左右子树的最大路径和也可以不包括左右子树
	int leftval = dfs(root->left, maxval);//求左子树的最大路径和
	int rightval = dfs(root->right, maxval);//右子树的最大路径和

	//innermax代表当前子树内部的最大路径和,需要包括当前子树
	//是左子树的和+当前子树根的值+右子树的和,内部路径和
	int innermax = leftval + root->val + rightval;
	
	maxval = std::max(maxval, innermax);//挑战最大记录
	//计算当前节点能为父节点提供的最大贡献
	int outputval = root->val + std::max(leftval, rightval);

	return std::max(outputval, 0);//如果贡献为负值,直接贡献值改成0
}
int maxPathSum(TreeNode* root) {
	if (!root)
		return 0;
	int maxval = root->val;//初始值不能是0,万一只有一个结点为[-3]就会出错
	int ret = dfs(root, maxval);
	cout << "ret = " << ret << endl;//输出结果为17
	return maxval;//返回结果为26
}
void test01()
{

	TreeNode* root = new TreeNode(3, 5, 1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2, 7, 4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	
	//printvectorvector(getthreepath(root));
	cout << maxPathSum(root) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
//不会写,看的题解 测试用例[1,2]
//求root的最小深度,求出左右子树的最小叶子结点深度,然后再加上1即可
//
int minDepth(TreeNode* root) {
	if (!root)
		return 0;
	//这个是必须要有的,没有会报错
	if (!root->left && !root->right)
		return 1;
	int res = INT_MAX;//每一次递归都需要初始化成这个,返回当前子树的最小叶子结点深度
	if (!root->left)
		res = std::min(res, minDepth(root->left));
	if (!root->right)
		res = std::min(res, minDepth(root->right));

	return res + 1;

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
#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
[1,n]做根结点

例如当前i作根结点
[1..i-1]左子树,[i+1,n]右子树,左右子树分别是二叉搜索树
[start,end]代表值的集合,枚举[start,end]中的所有值i作为当前二叉树的根
[start,i-1][i+1,end]获得可行的左右子树
最后从左右子树中选出一颗,拼接到根上,得到其中一个答案数组

start>end 代表数组为空,返回空结点

*/


vector<TreeNode*> helper(int start,int end) {
	if (start > end)
		return { nullptr };
	vector<TreeNode*> alltrees;//最终的返回结果
	//枚举区间里的所有可行根结点
	for (int i = start; i <= end; ++i) {
		auto lefttrees = helper(start, i - 1);
		auto righttrees = helper(i+1,end);

		//分别从左右子树中拿出一个结点,拼一下
		for (auto leftroot : lefttrees) {
			for (auto rightroot : righttrees) {
				//细节,跟节点要在循环内部构造
				TreeNode* node = new TreeNode(i);//根结点,细节,这个是i,不是left
				node->left = leftroot;
				node->right = rightroot;
				alltrees.emplace_back(node);//其中的一个结果
			}
		}

	}
	return alltrees;
}

//leetcode 题解
vector<TreeNode*> generateTrees(int n) {
	if (n < 1)
		return {};
	return helper(1, n);
	
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
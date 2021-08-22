#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

若root是p,q的最近公共祖先，只能是下面的情况之1
1.p,q在root的子树中，且分别在root的异侧（即分别在左子树，右子树）
2.p=root,且q在root的左子树或右子树中
3.q=root,且p在root的左子树或右子树中

具体思路：
（1） 如果当前结点 rootroot 等于 NULL，则直接返回 NULL
（2） 如果 rootroot 等于 pp 或者 qq ，那这棵树一定返回 pp 或者 qq
（3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 leftleft 和 rightright 表示
（4） 此时若leftleft为空，那最终结果只要看 rightright；若 rightright 为空，那最终结果只要看 leftleft
（5） 如果 leftleft 和 rightright 都非空，因为只给了 pp 和 qq 两个结点，都非空，说明一边一个，因此 rootroot 是他们的最近公共祖先
（6） 如果 leftleft 和 rightright 都为空，则返回空（其实已经包含在前面的情况中了）

*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if (!root)
		return root;
	if (root == p || root == q)//如果root是p或者q,那么一定返回p或者q
		return root;
	/*
	递归左右子树，因为是递归，可以认为左右子树已经算出结果,分别是left,right
	*/
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	//进行筛选，得到最后的结果
	if (!left)
		return right;
	if (!right)
		return left;
	if (left && right)//p,q在两侧
		return root;
	return nullptr;


}
/// <summary>
/// 
/// </summary>
/// <param name="node">正遍历的结点</param>
/// <param name="search">待搜索结点</param>
/// <param name="path">结点的路径栈，用vec模拟</param>
/// <param name="res">结点的搜索结果 集合</param>
/// <param name="isFind">记录是否已经找到</param>
void preorder(TreeNode* node,TreeNode *search,
	 vector<TreeNode*>& path, vector<TreeNode*> & res
	,bool& isFind
	) {
	//结点为空，或者已经找到，返回
	if (!node || isFind)
		return;
	//将结点压入path栈
	path.emplace_back(node);
	//找到search结点，标记变量为真
	if (node == search) {
		isFind = true;
		res = path;
	}

	preorder(node->left, search,path,res,isFind);
	preorder(node->right, search, path, res, isFind);

	path.pop_back();//结束遍历node，将node结点弹出path


}
//刷题教程的 方法
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {

	vector<TreeNode*> pathp, resp, pathq, resq;
	bool findp, findq;
	preorder(root, p, pathp, resp, findp);
	preorder(root, p, pathq, resq, findq);

	int n = resp.size() < resq.size() ? resp.size() : resq.size();

	TreeNode* last = nullptr;
	for (int i = 0; i < n; ++i) {
		if (resp[i] != resq[i])
			return last;
		last = resp[i];
	}
	return nullptr;
}
vector<TreeNode*> res;
void dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& path)
{
	path.push_back(root);
	if (root == node)
	{
		res = path;//要保存结果,之前的112路径总和有res.push_back(path)来保存结果
		return ;
	}
	else
	{
		if (root->left)
		{
			dfs(root->left, node, path);
			path.pop_back();
		}
		if (root->right)
		{
			dfs(root->right, node, path);
			path.pop_back();
		}
	}
}
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
{
	vector<TreeNode*> pathp, pathq,resp,resq;
	dfs(root, p, pathp);
	resp = res;
	res.clear();
	dfs(root, q, pathq);
	resq = res;

	//for (auto iter : pathp)
	//	cout << iter->val << " ";
	//cout << "----------------------\n";

	//for (auto iter : pathq)
	//	cout << iter->val << " ";
	//cout << endl;

	TreeNode* ancestor = nullptr;
	for (int i = 0; i < resp.size() && i < resq.size(); i++)
	{
		if (resp[i] == resq[i])
			ancestor = resp[i];
	}
	return ancestor;
}
//2021年5月15日复习
void getpath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
	path.push_back(root);
	if (root->val == node->val)
		return;
	else {
		if (root->left) {
			getpath(root->left, node, path);
			path.pop_back();
		}
		if (root->right) {
			getpath(root->right, node, path);
			path.pop_back();
		}
	}//

}
TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {

	vector<TreeNode*> pathp, pathq;
	getpath(root, p, pathp);
	getpath(root, q, pathq);
	int n = std::min(pathp.size(), pathq.size());

	TreeNode* ances=nullptr;
	for (int i = 0; i < n; ++i) {
		if (pathp[i] != pathq[i])
			return ances;
		ances = pathp[i];
	}
	return ances;
}
void test01()
{
	TreeNode* root = new TreeNode(3, 5, 1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2, 7, 4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	//auto ret =
	//	lowestCommonAncestor2(root, root->left, root->left->right->right);

	//cout << ret->val << endl;


	vector<TreeNode*> resp;
	getpath(root, root->right->left, resp);
	for (int i = 0; i < resp.size(); ++i) {
		cout << resp[i]->val << " ";
	}
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
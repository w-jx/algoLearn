#if 0
#include "../headers/wjxHeaders.h"

vector<int> item;
vector<vector<int> > res;
//输出所有路径
void getallpath(TreeNode* root) {
	if (!root)
		return;
	item.push_back(root->val);
	if (!root->left && !root->right) {
		res.push_back(item);
		return;
	}//到叶子结点了
	if (root->left) {
		getallpath(root->left);
		item.pop_back();
	}
	if (root->right) {
		getallpath(root->right);
		item.pop_back();
	}

}
vector<vector<int>> leftres;
vector<vector<int> > rightres;
//尝试按照左右子树,分别输出路径
void helper(TreeNode* root, vector<int>& temp, vector<vector<int>>& myres) {
	if (!root)
		return;
	temp.push_back(root->val);
	if (!root->left && !root->right) {
		myres.push_back(temp);
		return;
	}//到叶子结点了
	if (root->left) {
		helper(root->left,temp,myres);
		temp.pop_back();
	}
	if (root->right) {
		helper(root->right,temp,myres);
		temp.pop_back();
	}
}
void getLeftRightPath(TreeNode* root) {
	vector<int> templeft;
	vector<int> tempright;
	templeft.push_back(root->val);
	tempright.push_back(root->val);
	if (root->left)
		helper(root->left, templeft, leftres);
	if (root->right)
		helper(root->right, tempright, rightres);
}
int ans = 0;
int helper(TreeNode* root) {
	if (!root)
		return 0;
	int leftdepth = helper(root->left);
	int rightdepth = helper(root->right);
	return std::max(leftdepth, rightdepth) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
	if (!root)
		return 0;
	int leftdepth = helper(root->left);
	int rightdepth = helper(root->right);
	ans = std::max(ans, leftdepth + rightdepth + 1);
	
	return ans - 1;
}

void test01()
{
	TreeNode* root = new TreeNode(3, 5, 1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2, 7, 4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	//getallpath(root);
	//printvectorvector(res);

	getLeftRightPath(root);
	printvectorvector(leftres);
	printvectorvector(rightres);
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
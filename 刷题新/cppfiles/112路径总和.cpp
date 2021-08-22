#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

�Ӹ����  �� Ҷ�ӽ��� ����
*/
//�ݹ飺ʱ�临�Ӷ� ��ÿ��������һ��
//�ռ临�Ӷȣ�0(H),H�����ĸ߶�
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
	//����һ���ڵ� ����һ��·��ֵ
	path_val += node->val;
	path.emplace_back(node->val);

	if (path_val == targetSum && !node->left && !node->right)
		res.push_back(path);
	preorder(node->left, path_val, targetSum, path, res);
	preorder(node->right, path_val, targetSum, path, res);

	path_val -= node->val;
	path.pop_back();


}
//��ʲô���ݽṹ��ջ
bool hasPathSum2(TreeNode* root, int targetSum)
{
	vector < vector<int> > res;//�洢��������������
	vector<int> path;//·��ջ����vectorģ��
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
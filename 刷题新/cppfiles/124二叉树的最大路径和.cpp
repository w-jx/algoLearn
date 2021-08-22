#if 0
#include "../headers/wjxHeaders.h"

//ÿ�������һ��������һ��
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
/// ���ص�ǰ�ڵ�Ϊ���ڵ��ṩ�Ĺ���
/// </summary>
/// <param name="root"></param>
/// <param name="maxval"></param>
/// <returns></returns>
int dfs(TreeNode* root,int &maxval) {
	if (!root)
		return 0;
	//���·���Ͳ�һ�����������
	//�������������������·����Ҳ���Բ�������������
	int leftval = dfs(root->left, maxval);//�������������·����
	int rightval = dfs(root->right, maxval);//�����������·����

	//innermax����ǰ�����ڲ������·����,��Ҫ������ǰ����
	//���������ĺ�+��ǰ��������ֵ+�������ĺ�,�ڲ�·����
	int innermax = leftval + root->val + rightval;
	
	maxval = std::max(maxval, innermax);//��ս����¼
	//���㵱ǰ�ڵ���Ϊ���ڵ��ṩ�������
	int outputval = root->val + std::max(leftval, rightval);

	return std::max(outputval, 0);//�������Ϊ��ֵ,ֱ�ӹ���ֵ�ĳ�0
}
int maxPathSum(TreeNode* root) {
	if (!root)
		return 0;
	int maxval = root->val;//��ʼֵ������0,��һֻ��һ�����Ϊ[-3]�ͻ����
	int ret = dfs(root, maxval);
	cout << "ret = " << ret << endl;//������Ϊ17
	return maxval;//���ؽ��Ϊ26
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
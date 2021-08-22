#if 0
#include "../headers/wjxHeaders.h"

/*
ע��������  ����  ���ڵ� ��ľ���ֵ

ע�������������

		 100
	 50
30	    90
      93   99

�����100,��99�Ĳ�ֵ��С,Ϊ1
*/

//�뵽�ķ���1,�ù�ϣ��洢���ڵ�,Ȼ��Ƚ�
int minval = INT_MAX;
void preorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& rootMp)
{
	if (!root)
		return;
	if (root->left) {
		rootMp[root->left] = root;
		preorder(root->left, rootMp);
	}
	auto temp = root;
	while (rootMp.find(temp)!=rootMp.end() && rootMp[temp]) {//����㲻Ϊ��
		minval = std::min(minval, abs(root->val-rootMp[temp]->val));
		temp = rootMp[temp];
	}
	if (root->right) {
		rootMp[root->right] = root;
		preorder(root->right, rootMp);
	}
}
int getMinimumDifference(TreeNode* root) {
	//key->���,��Ӧ�����丸���
	unordered_map<TreeNode*, TreeNode*> rootMp;
	rootMp[root] = nullptr;
	preorder(root, rootMp);

	return minval;

}
//�����Ż�,����ʱ�临�Ӷ�,û�еõ����ʵ��Ż�
void preorder2(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& rootMp)
{
	if (root->left) {
		rootMp[root->left] = root;
		preorder(root->left, rootMp);
	}
	auto temp = root;
	while (rootMp[temp]) {//����㲻Ϊ��
		minval = std::min(minval, abs(root->val - rootMp[temp]->val));
		temp = rootMp[temp];
	}
	if (root->right) {
		rootMp[root->right] = root;
		preorder(root->right, rootMp);
	}
}
int getMinimumDifference2(TreeNode* root) {
	//key->���,��Ӧ�����丸���
	unordered_map<TreeNode*, TreeNode*> rootMp;
	rootMp[root] = nullptr;
	preorder2(root, rootMp);

	return minval;

}

//����3,��������Ƚ�,ʱ�临�Ӷȴ�����
int pre;
bool first;
void preorder3(TreeNode* root)
{
	if (!root)
		return;
	preorder3(root->left);
	if (first) {
		first = false;
	}
	else {
		minval = std::min(minval, abs(root->val - pre));
	}
	pre = root->val;
	preorder3(root->right);
}
int getMinimumDifference3(TreeNode* root) {
	first = true;
	minval = INT_MAX;
	preorder3(root);
	return minval;
}
//��һ���Ż�
bool hasfind;
void preorder4(TreeNode* root)
{
	if (hasfind)
		return;
	if (!root)
		return;
	preorder3(root->left);
	if (first) {
		first = false;
	}
	else {
		minval = std::min(minval, abs(root->val - pre));
		if (minval == 0) {
			hasfind = true;
			return;
		}
	}
	pre = root->val;
	preorder3(root->right);
}
int getMinimumDifference4(TreeNode* root) {
	first = true;
	hasfind = false;
	minval = INT_MAX;
	preorder3(root);
	return minval;
}
void test01()
{

}
int main()
{
	test01();
}
#endif
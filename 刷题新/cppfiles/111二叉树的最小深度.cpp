#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
//����д,������� ��������[1,2]
//��root����С���,���������������СҶ�ӽ�����,Ȼ���ټ���1����
//
int minDepth(TreeNode* root) {
	if (!root)
		return 0;
	//����Ǳ���Ҫ�е�,û�лᱨ��
	if (!root->left && !root->right)
		return 1;
	int res = INT_MAX;//ÿһ�εݹ鶼��Ҫ��ʼ�������,���ص�ǰ��������СҶ�ӽ�����
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
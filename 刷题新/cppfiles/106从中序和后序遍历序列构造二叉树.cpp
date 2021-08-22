#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
int post_idx;
unordered_map<int, int> idx_map;

//��Ϊ����������� ��  ��,���Է�����Ӧ���ȸ�,����,����
TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder)
{
	//�����ʱ��û�н�㹹�������������
	if (in_left > in_right)
		return nullptr;
	//ѡ��post_idxλ�õ�Ԫ�أ���Ϊ��ǰ������ �����
	int root_val = postorder[post_idx];
	TreeNode* root = new TreeNode(root_val);

	//����root����λ�÷ֳ�������������
	int index = idx_map[root_val];

	//�±��1
	post_idx--;

	//����������
	root->right = helper(index + 1, in_right, inorder, postorder);
	//����������
	root->left = helper(in_left, index - 1, inorder, postorder);
	return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	post_idx = postorder.size() - 1;
	//����Ԫ�� ���±��Ӧ�Ĺ�ϣ��
	int idx = 0;
	for (auto& val : inorder)
		idx_map[val] = idx++;
	return helper(0, post_idx, inorder, postorder);
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
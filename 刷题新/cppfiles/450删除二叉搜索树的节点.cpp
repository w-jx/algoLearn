#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

���Ŀ��ڵ���ڵ�ǰ�ڵ�ֵ����ȥ��������ɾ����
���Ŀ��ڵ�С�ڵ�ǰ�ڵ�ֵ����ȥ��������ɾ����
���Ŀ��ڵ���ǵ�ǰ�ڵ㣬��Ϊ�������������
�������ӣ������Ӷ�����λ�ã�ɾ���˸ýڵ㣻
�������ӣ������Ӷ�����λ�ã�ɾ���˸ýڵ㣻
�������ӽڵ㶼�У���������ת�Ƶ���������������ڵ���������ϣ�Ȼ��������������λ�ã��ɴ�ɾ���˸ýڵ㡣


*/
//O(H)--->
TreeNode* deleteNode(TreeNode* root, int key)
{
	if (!root)//�ն�������ֱ�ӷ���
		return root;
	if (key > root->val) root->right = deleteNode(root->right, key);//ȥ������ɾ��
	else if (key < root->val) root->left = deleteNode(root->left, key);//ȥ������ɾ��
	else {//��ǰ�ڵ���Ǵ�ɾ���Ľڵ�
		if (!root->left) return root->right;//û����������������������
		if (!root->right) return root->left;//û�������� ������������
		
		TreeNode* node = root->right;//���Ȼ��������
		while (node->left)//Ҫ��������������ڵ�
			node = node->left;

		node->left = root->left;
		root = root->right;//���ڵ�ĳ��Һ���
	}
	return root;
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
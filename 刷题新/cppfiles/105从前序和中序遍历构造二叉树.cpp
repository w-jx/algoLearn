#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/



int pre_idx = 0;//ǰ�����������±�
unordered_map<int, int> hashmap;//������������ڵ���±�ӳ���ϵ
////��Ϊǰ������Ǹ� �� ��  ,�����ȸ�,����,����
TreeNode* build(int left, int right, vector<int>& preorder, vector<int>& inorder) {
    if (left > right)
        return nullptr;
    //if (pre_idx==preorder.size())
      //  return nullptr;
    //��һ�� ��ȡֵ
    int node_val = preorder[pre_idx];
    TreeNode* root = new TreeNode(node_val);

    //��ȡ��ǰ�ڵ����������������±�
    int index = hashmap[node_val];//������������������,�Ҳ���������
    pre_idx++;//�´ι���Ľڵ���ǰ���������һ����
    //������������
    root->left = build(left, index - 1, preorder, inorder);
    root->right = build(index + 1, right, preorder, inorder);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    int idx = 0;
    for (auto& iter : inorder)
        hashmap[iter] = idx++;
    return buildTree(0, preorder.size() - 1, preorder, inorder);
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
#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
/*
along the path, record all prefix sums in a hash table. 
For current prefix sum x, check if (x - target) appears in the hash table.
�ڹ�ϣ���м�¼���е�ǰ׺��,���ڵ�ǰ��ǰ׺��X,���X-target�Ƿ��Ѿ��ڹ�ϣ����

*/
int ans = 0;
void dfs(TreeNode* root, int targetSum, int prefix, map<int, int>& m) {
    if (!root)
        return;
    prefix += root->val;//��ǰ��ǰ׺������
    if (m.find(prefix - targetSum) != m.end())
        ans += m[prefix - targetSum];//��������10,��ǰǰ׺��3,����ϣ�����Ѿ���7��
   
    m[prefix]++;//��ǰǰ׺�͵���������
    dfs(root->left, targetSum, prefix, m);//�ֱ������������б���
    dfs(root->right, targetSum, prefix, m);
    //�����õ���ǰ�����,������ɺ�������,��ǰ��㲻������һ��·����ǰ׺����,��Ҫ��ȥ
    m[prefix]--;//��ǰǰ׺�͵�������1
}
int pathSum(TreeNode* root, int targetSum) {
    map<int, int> m;
    m[0] = 1;

}
void test01()
{
    TreeNode* root = new TreeNode(10, 5, -3);

    root->left->left = new TreeNode(3,3,-2);
    root->left->right = new TreeNode(2, 7, 4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif
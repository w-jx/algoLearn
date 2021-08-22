#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
/*
along the path, record all prefix sums in a hash table. 
For current prefix sum x, check if (x - target) appears in the hash table.
在哈希表中记录所有的前缀和,对于当前的前缀和X,检查X-target是否已经在哈希表中

*/
int ans = 0;
void dfs(TreeNode* root, int targetSum, int prefix, map<int, int>& m) {
    if (!root)
        return;
    prefix += root->val;//当前的前缀和增加
    if (m.find(prefix - targetSum) != m.end())
        ans += m[prefix - targetSum];//例如代求的10,当前前缀和3,而哈希表中已经有7了
   
    m[prefix]++;//当前前缀和的数量增加
    dfs(root->left, targetSum, prefix, m);//分别在左右子树中遍历
    dfs(root->right, targetSum, prefix, m);
    //我们用的是前序遍历,左右完成后向上退,当前结点不是另外一条路径的前缀和了,需要减去
    m[prefix]--;//当前前缀和的数量减1
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
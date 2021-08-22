#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/



int pre_idx = 0;//前序遍历里面的下标
unordered_map<int, int> hashmap;//保存中序遍历节点和下标映射关系
////因为前序遍历是根 左 右  ,构造先根,再左,再右
TreeNode* build(int left, int right, vector<int>& preorder, vector<int>& inorder) {
    if (left > right)
        return nullptr;
    //if (pre_idx==preorder.size())
      //  return nullptr;
    //第一步 获取值
    int node_val = preorder[pre_idx];
    TreeNode* root = new TreeNode(node_val);

    //获取当前节点在中序遍历里面的下标
    int index = hashmap[node_val];//中序遍历左侧是左子树,右侧是右子树
    pre_idx++;//下次构造的节点是前序遍历的下一个了
    //构造左右子树
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
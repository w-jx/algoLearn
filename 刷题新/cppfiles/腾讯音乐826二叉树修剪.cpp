#if true
#include "../headers/wjxHeaders.h"

/*
删除一个二叉树的所有叶子结点，但是不能直接删除，必须通过
叶子结点的父节点去删除
*/


//这个函数是判断二叉树的左右子树 的子树 是否有叶子结点，如果有返回true
//如果没有，返回false
bool isnull(TreeNode *node)
{
    if (!node) {
        return false;
    }
    if (node->left) {
        if (!node->left->left || !node->left ->right) {
            return true;
        }
    }
    if (node->right) {
        if (!node->right->left || !node->right->right) {
            return true;
        }
    }
    return false;
    
}

TreeNode* level(TreeNode *root) 
{
    if (!root || isnull(root)) { //最开始就判断，防止出现只有根节点，然后左右子树有为空的情况
        return nullptr;
    }
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        auto node = que.front();
        que.pop();
        //相当于改变了层序遍历的 条件
        if (isnull(node->left)) {
            node->left = nullptr;
        }
        else {
            que.push(node->left);
        }
        if (isnull(node->right)) {
            node->right= nullptr;
        }
        else {
            que.push(node->right);
        }
    }
    return root;
}

void test01()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    
    
    root->left->left->left  = new TreeNode(5);
    auto ret = level(root);
    levelOrder2(ret);
}



int main()
{
    test01();
}

#endif
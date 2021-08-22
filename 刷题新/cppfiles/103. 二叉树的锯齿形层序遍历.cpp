#if 0
#include "../headers/wjxHeaders.h"

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return {};
    queue<TreeNode*> que;
    vector<int> item;
    vector<vector<int> > res;
    que.push(root);
    bool reverse = false;
    while (!que.empty()) {
        int n = que.size();
        item.resize(n);
        int idx = 0;
        if (reverse)
            idx = n - 1;

        for (int i = 0; i < n; ++i) {
            auto node = que.front();
            que.pop();
            if (reverse)
                item[idx--] = node->val;
            else
                item[idx++] = node->val;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        reverse = !reverse;
        res.push_back(item);
        item.clear();
    }
    return res;
}
void test01()
{
    TreeNode* root = new TreeNode(3, 9, 20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    auto res = zigzagLevelOrder(root);
    printvectorvector(res);
}
int main()
{
	test01();
}
#endif
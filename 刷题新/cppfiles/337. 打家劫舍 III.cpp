#if 0
#include "../headers/wjxHeaders.h"


/*
[2,1,3,null,4]无法适用
        2
    1       3
  N   4   N    N
 偷3,4,最大是7,按照下面的算法来看,只能偷2+4=6

*/
int rob(TreeNode* root) {
    if (!root)
        return 0;
    deque<TreeNode*> que;
    que.push_back(root);
    vector<int> levelMax;
    while (!que.empty()) {
        int n = que.size();
        int curMax =0;
        for (int i = 0; i < n; ++i) {
            auto node = que.front();
            que.pop_front();
            curMax += node->val;
            if (node->left)
                que.push_back(node->left);
            if (node->right)
                que.push_back(node->right);
        }
        levelMax.push_back(curMax);
    }
    int n = static_cast<int>(levelMax.size());
    if (n == 1)
        return levelMax[0];
    else if (n == 2)
        return std::max(levelMax[0], levelMax[1]);
    vector<int> dp(n);
    dp[0] = levelMax[0];
    dp[1] = std::max(levelMax[0], levelMax[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = std::max(levelMax[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n-1];
}
/*
简化问题：
一颗二叉树：
    每个点都有对应的权（数字），每个点有两种状态（选中和不选中）
不能同时选有父子关系的结点，最大选中的权值和

f(o)代表选择o结点，o结点子树上被选择的结点的最大权值和
g(o) 代表不选择o结点，o结点的字数上被选择的结点的最大权值和

利用l和r表示o的左右孩子

o被选中的时候，o的左右孩子都不能被选中
所以，是左子树和右子树都不被选中的最大权值和相加
f(o) = g(l)+g(r)


o不被选中的时候，o的左右孩子，可以被选中，也可以不被选中
对于o的某个孩子x，它对o的贡献是x 被选中和不被选中情况下，权值和的较大值
g(o) = max{f(l),g(l)} + max{f(r),g(r) }

可以用哈希表存f,g的函数值，用后序遍历二叉树，得到每个结点的f,g，根结点的f和g的最大值就是
答案


*/
//withcur代表选中当前结点，其子树上被选择的结点的最大权值和
//discur代表不选中当前结点，其字数上被选择的结点的最大权值和
unordered_map<TreeNode*, int> withcur, discur;
void dfs(TreeNode* node)
{
    if (!node)
        return;
    dfs(node->left);
    dfs(node->right);
    withcur[node] = node->val + discur[node->left] + discur[node->right];
    discur[node] = std::max(withcur[node->left], discur[node->left]) +
        std::max(withcur[node->right], discur[node->right]);
}
int rob2(TreeNode* root) {
    if (!root)
        return 0;
    dfs(root);
    return std::max(withcur[root], discur[root]);
}
/*
优化：
    withcur[node] = node->val + discur[node->left] + discur[node->right];
    discur[node] = std::max(withcur[node->left], discur[node->left]) +
        std::max(withcur[node->right], discur[node->right]);

发现不管是withcur,还是discur，
withcur[node]和discur[node]都是和node->left,node->right有关
所以可以舍弃哈希表来进行状态压缩
*/
std::pair<int,int> dfs2(TreeNode* node)
{
    if (!node)
        return make_pair(0,0);
    auto pairleft = dfs2(node->left);
    auto pairright = dfs2(node->right);
    int withcur = node->val + pairleft.second + pairright.second;
    int discur = std::max(pairleft.first, pairleft.second) +
        std::max(pairright.first, pairright.second);
    return { withcur,discur };
}
int rob3(TreeNode* root) {
    if (!root)
        return 0;
    auto pair = dfs2(root);
    return std::max(pair.first, pair.second);

}
void test01()
{

}
int main()
{
	test01();
}
#endif
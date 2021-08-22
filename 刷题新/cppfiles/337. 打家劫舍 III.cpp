#if 0
#include "../headers/wjxHeaders.h"


/*
[2,1,3,null,4]�޷�����
        2
    1       3
  N   4   N    N
 ͵3,4,�����7,����������㷨����,ֻ��͵2+4=6

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
�����⣺
һ�Ŷ�������
    ÿ���㶼�ж�Ӧ��Ȩ�����֣���ÿ����������״̬��ѡ�кͲ�ѡ�У�
����ͬʱѡ�и��ӹ�ϵ�Ľ�㣬���ѡ�е�Ȩֵ��

f(o)����ѡ��o��㣬o��������ϱ�ѡ��Ľ������Ȩֵ��
g(o) ����ѡ��o��㣬o���������ϱ�ѡ��Ľ������Ȩֵ��

����l��r��ʾo�����Һ���

o��ѡ�е�ʱ��o�����Һ��Ӷ����ܱ�ѡ��
���ԣ�����������������������ѡ�е����Ȩֵ�����
f(o) = g(l)+g(r)


o����ѡ�е�ʱ��o�����Һ��ӣ����Ա�ѡ�У�Ҳ���Բ���ѡ��
����o��ĳ������x������o�Ĺ�����x ��ѡ�кͲ���ѡ������£�Ȩֵ�͵Ľϴ�ֵ
g(o) = max{f(l),g(l)} + max{f(r),g(r) }

�����ù�ϣ���f,g�ĺ���ֵ���ú���������������õ�ÿ������f,g��������f��g�����ֵ����
��


*/
//withcur����ѡ�е�ǰ��㣬�������ϱ�ѡ��Ľ������Ȩֵ��
//discur����ѡ�е�ǰ��㣬�������ϱ�ѡ��Ľ������Ȩֵ��
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
�Ż���
    withcur[node] = node->val + discur[node->left] + discur[node->right];
    discur[node] = std::max(withcur[node->left], discur[node->left]) +
        std::max(withcur[node->right], discur[node->right]);

���ֲ�����withcur,����discur��
withcur[node]��discur[node]���Ǻ�node->left,node->right�й�
���Կ���������ϣ��������״̬ѹ��
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
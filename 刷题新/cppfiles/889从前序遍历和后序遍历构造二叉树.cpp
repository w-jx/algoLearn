#if 0
#include "../headers/wjxHeaders.h"

TreeNode* buildtree(vector<int>& pre, vector<int>& post, int pre_start, int
    pre_end, int post_start, int post_end);

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int len = pre.size();
    return buildtree(pre, post, 0, len - 1, 0, len - 1);
}
/*
下面解法的依据:
前序遍历:根 左子树 右子树
后序遍历 左子树 右子树  根
需要找到能把根 左子树 右子树 区分开的界限

例如:
       1
     2   3
    4 5 6 7
前序:[1 2 4 5 3 6 7]
后续:[4 5 2 6 7 3 1]
可以看到左子树 [2,4,5],右子树[3,6,7]根是1
前序的第二个结点为2,也就是左子树的根,而在后序中2的左边全是左子树,2的右边除了最后都是右子树
而且我们发现后序中可以直到左子树的结点数量是3
后序最后一个是根,因此可以结算右子树的结点数量,
再利用左右子树数量计算前序中左右子树的范围,分别构造


*/
TreeNode* buildtree(vector<int>& pre, vector<int>& post, int pre_start, int
    pre_end, int post_start, int post_end) {
    if (pre_start > pre_end || post_start > post_end)
        return nullptr;
    TreeNode* root = new TreeNode(pre[pre_start]);//
    if (pre_start == pre_end)//只有一个结点，直接返回即可
        return root;
    int index = post_start;
    while (pre[pre_start + 1] != post[index])//首先找到前序遍历的第二个元素在后序遍历中的位置
        index++;//这一步也可以用哈希表来做
    //假如index,那么左子树的数量就是index-post_start+1 ,用leftcount代替
    /*
  后序遍历中，我们知道 左子树：[post_start,index], 右子树：[index+1, post_end-1]
在前序遍历中，左子树起始位置为pre_start+1,左子树个数一共有(index - post_start+1)个，但是
我们要的是范围因此左子树从起始位置加index-post_start即可

因此左子树的范围是：[pre_start+1, pre_start+1 + (index - post_start)] 
右子树起始位置为左子树终止位置+1，终止位置为pre_end，
因此右子树范围是：[ pre_start+1 + (index - post_start) + 1, pre_end]

举例：
pre = [1,2,4,5,3,6,7]    前序遍历的第二个元素2，在后序遍历的下标为2
这样在后序遍历我们可以看到左子树 [4,5,2] 所以范围是[0,2] ,右子树[6,7,3]，范围是[3,5]
而在前序遍历中左子树[2,4,5]范围是[1，3],右子树[3,6,7]，范围是[4,6]
post = [4,5,2,6,7,3,1]

    */

    root->left = buildtree(pre, post, pre_start + 1, pre_start + 1 + index - post_start, post_start, index);
    
    root->right = buildtree(pre, post, pre_start + 1 + 1 + index - post_start, pre_end, index + 1, post_end - 1);

 
    return root;
}
unordered_map<int, int>  post_map;//保存后序遍历值的哈希表
//再给定区间构造二叉树的结点
TreeNode* bd(vector<int>& pre, vector<int>& post, int pre_s, int pre_e, int post_s, int post_e) {
    if (pre_s > pre_e || post_s > post_e)
        return nullptr;
    TreeNode* root = new TreeNode(pre[pre_s]);//
    if (pre_s == pre_e)
        return root;
    int idx = post_map[pre[pre_s + 1]];

    root->left = bd(pre, post, pre_s + 1, pre_s + 1 + idx-post_s, post_s, idx);
    root->right = bd(pre, post, pre_s + 1 + idx - post_s+1, pre_e, idx + 1, post_e - 1);
    return root;
}
//2021年5月20日复习,有错误
TreeNode* constructFromPrePost2(vector<int>& pre, vector<int>& post) {
    int n = pre.size();
    for (int i = 0; i < n; ++i) {
        post_map[post[i]] = i;
    }
    return bd(pre, post, 0, n - 1, 0, n - 1);
}
void test01()
{
    vector<int> pre{ 1,2,4,5,3,6,7 };
    vector<int> post{ 4,5,2,6,7,3,1 };
    TreeNode* root = constructFromPrePost2(pre, post);

    recursionTree(root);
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif
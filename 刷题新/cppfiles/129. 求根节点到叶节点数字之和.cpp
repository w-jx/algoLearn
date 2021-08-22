#if 0
#include "../headers/wjxHeaders.h"


vector<int> pathsum;
int sum;

//出现错误,这个helper得到的是路径和
//例如路径是4-9-1,得到的是4+9+1=15
//应该需要的是400+90+1=491
void helper(TreeNode* root) {
    if (!root->left && !root->right) {
        sum = sum * 10 + root->val;
        pathsum.push_back(sum);
        sum -=root->val;
        sum /= 10;
        return;
    }
    sum = sum * 10 + root->val;
    if (root->left) {
        helper(root->left);
    }
    if (root->right) {
        helper(root->right);
    }
    sum -= root->val;
    sum /= 10;

}

int sumNumbers(TreeNode* root) {
    if (!root)
        return 0;
    sum = 0;
    helper(root);
    int res = accumulate(pathsum.begin(), pathsum.end(), 0);
    return res;

}
void test01()
{
    TreeNode* root = new TreeNode(4, 9, 0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    helper(root);
    printVector(pathsum);
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif
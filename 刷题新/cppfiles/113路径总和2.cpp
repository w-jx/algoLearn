#if 0
#include "../headers/wjxHeaders.h"

//从根结点开始,不一定到叶子结点
vector<int> path;
vector<vector<int> > res;
void helper(TreeNode* root, int targetSum, int cur) {
    if (!root)
        return;
    path.push_back(root->val);
    cur += root->val;
    if (!root->left && !root->right ) {
        cout << cur << endl;
        res.push_back(path);
        return;
    }

    if (root->left) {
        helper(root->left, targetSum, cur);  //在函数里面cur加了root->left->val
        path.pop_back();//但是执行到这因为是临时变量就没了,所以不用减
    }
    if (root->right) {
        helper(root->right, targetSum, cur); 
        path.pop_back();
    }
    cur -= root->val;
       
}
void helper2(TreeNode* root, int targetSum, int &cur) {
    if (!root)
        return;
    path.push_back(root->val);
    cur += root->val;
    if (!root->left && !root->right) {
        cout << cur << endl;
        res.push_back(path);
        return;
    }

    if (root->left) {
        helper2(root->left, targetSum, cur);  //在函数里面cur加了root->left->val
        path.pop_back();//但是执行到这因为是临时变量就没了,所以不用减
        cur -= root->left->val;
    }
    if (root->right) {
        helper2(root->right, targetSum, cur);
        path.pop_back();
        cur -= root->right->val;
    }
   

}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    helper2(root, targetSum, sum);
    return res;
}

void test01()
{
    TreeNode* root = new TreeNode(3, 5, 1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2, 7, 4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    printvectorvector(pathSum(root, 10));

}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif
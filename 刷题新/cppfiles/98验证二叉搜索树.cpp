#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
/*
[5,4,6,null,null,3,7]这个测试用例
     5
   4    6
       3  7
在每个结点都满足左<根<右,但是因为3<5,所以不是二叉搜索树
递归没有考虑到这种情况


考虑这两个测试用例
[-2147483648]
[-2147483648,null,2147483647]


*/
bool isValidBST(TreeNode* root) {
    if (!root || (!root->left && !root->right))
        return true;
    if (root->left && root->val < root->left->val)
        return false;
    if (root->right && root->val > root->right->val)
    return false;

    bool left = isValidBST(root->left);
    bool right = isValidBST(root->right);
    cout << "left=" << left << endl;
    cout << "right=" << right << endl;

    if (left && right)
        return true;
    return false;

}
TreeNode* pre = nullptr;
bool isValidBST2(TreeNode* root) {
    if (!root || (!root->left && !root->right))
        return true;
    stack<std::pair<TreeNode*, bool> > myque;
    myque.push({ root,false });
    while (!myque.empty()) {
        auto node = myque.top();
        myque.pop();
        if (node.second) {
          
            if (pre) {
                if (pre->val > node.first->val)
                    return false;
                pre = node.first;
            }
            else
                pre = node.first;
        }
        else {
            if (node.first->right)
                myque.push({ node.first->right,false });
            node.second = true;
            myque.push(node);
            if (node.first->left)
                myque.push({ node.first->left,false });
        }
    }
    return true;
}
int pre2;
bool isValid(TreeNode* root) {
    if (!root)
        return true;
    bool leftres = isValid(root->left);
       
    if (pre2 >= root->val)
        return false;
    pre2 = root->val;
    bool rightres = isValid(root->right);
      
    return leftres&& rightres;

}
bool isValidBST3(TreeNode* root) {
    if (!root || (!root->left && !root->right))
        return true;
    pre2 = INT_MIN;
    return isValid(root);

}
void test01()
{
    TreeNode* root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);


    bool flag = isValidBST2(root);

    cout << "flag=" << flag << endl;
}
void test02()
{
    //TreeNode* root = new TreeNode(5, 1, 4);
    //root->right->left = new TreeNode(3);
    //root->right->right = new TreeNode(6);

    TreeNode* root = new TreeNode(5, new TreeNode(4), new TreeNode(6, 3, 7));

    cout << isValidBST3(root) << endl;
}
int main()
{
    test02();
	system("pause");
	return 0;
}
#endif
#if 0
#include "../headers/wjxHeaders.h"

int getHeight(TreeNode* root) {
    if (!root)
        return 0;
    int leftheight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return std::max(leftheight, rightHeight) + 1;
}
bool helper(TreeNode* left, TreeNode* right) {
    int leftheight = getHeight(left);
    int rightHeight = getHeight(right);
    return abs(leftheight - rightHeight) < 2;
}
bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
    return helper(root->left,root->right) && isBalanced(root->left) && isBalanced(root->right);
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
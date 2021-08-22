#if 0
#include <iostream>
#include <stack>
using namespace std;
/*
leecode题目介绍:
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
		4
	2      7
1      3   6  9

		4
	7      2
9      6  3    1
		
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
void recursion(TreeNode* node) {
	if (node == nullptr)
		return ;
	cout << node->val << " ";
	recursion(node->left);
	recursion(node->right);
}
TreeNode* mirrorTree(TreeNode* root) {

	
	if (root == nullptr)
		return nullptr;
	
	TreeNode* left = mirrorTree(root->left);
	TreeNode* right = mirrorTree(root->right);
	TreeNode* newNode = new TreeNode(root->val);
	newNode->right = left;
	newNode->left = right;

	return newNode;

}
void test01()
{
	TreeNode node1(4);
	TreeNode node2(2);
	TreeNode node3(1);
	TreeNode node4(3);
	TreeNode node5(7);
	TreeNode node6(6);
	TreeNode node7(9);

	node1.left = &node2;
	node1.right = &node5;
	
	node2.left = &node3;
	node2.right = &node4;

	node5.left = &node6;
	node5.right = &node7;

	recursion(&node1);
	cout << endl;
	TreeNode* nodeTEMP = mirrorTree(&node1);
	
	recursion(nodeTEMP);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
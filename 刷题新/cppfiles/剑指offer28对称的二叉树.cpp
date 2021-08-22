#if 0
#include "../headers/wjxHeaders.h"
/*还没有做出来
leecode题目介绍:
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
，二叉树 [1,2,2,3,4,4,3] 是对称的。
[1,2,2,null,3,null,3]

*/
bool isSame(TreeNode* left, TreeNode* right)//给一个根,判断左右两节点是否对称
{
	
	if (left == nullptr && right == nullptr)
		return true;
	if (left == nullptr && right != nullptr)
		return false;
	if (left != nullptr && right == nullptr)
		return true;
	return left->val == right->val && isSame(left->left, right->right) && isSame(left->right, right->left);

}

bool isSymmetric(TreeNode* root) {//方法1,用递归做

	if (root == nullptr)
		return true;
	return isSame(root->left, root->right);
}
void test01()
{
	TreeNode* node1 =new TreeNode(1);
	TreeNode* node2l = new TreeNode(2);
	TreeNode* node2r = new TreeNode(2);
	TreeNode* node31l = new TreeNode(3);
	TreeNode* node31r= new TreeNode(4);
	TreeNode* node32l = new TreeNode(4);
	TreeNode* node32r= new TreeNode(3);

	node1->left = node2l;
	node1->right = node2r;

	node2l->left = node31l;
	node2l->right = node31r;

	node2r->left = node32l;
	node2r->right = node32r;

	//cout << isSymmetric(node1) << endl;


	//TreeNode* node1 = new TreeNode(1);
	//TreeNode* node2l = new TreeNode(2);
	//TreeNode* node2r = new TreeNode(2);
	//TreeNode* node31l = new TreeNode(3);

	//TreeNode* node32r = new TreeNode(3);

	//node1->left = node2l;
	//node1->right = node2r;


	//node2l->right = node31l;

	//node2r->left = node32r;

	//cout << isSymmetric(node1) << endl;;

	

	
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
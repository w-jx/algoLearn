#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
int getLargest(TreeNode* root) {//给出有序二叉树的最大的节点

	if (root == nullptr)
		return 0;
	while (root->right != nullptr)
		root = root->right;
	return root->val;

}
int getSmallest(TreeNode* root) {
	if (root == nullptr)
		return 0;
	if (root->left == nullptr)
		return root->val;
	return getSmallest(root->left);
}
int kthLargest(TreeNode* root, int k) {
	if (!root)
		return -1;
	stack<std::pair<TreeNode*, bool> > mystack;
	mystack.push({ root,false });
	vector<int> nums;
	while (!mystack.empty()) {
		auto node = mystack.top();
		mystack.pop();

		if (!node.first)
			continue;
		if (node.second) {
			nums.push_back(node.first->val);
		}
		else {
			//if (root->left)
			mystack.push({ node.first->right,false });
			node.second = true;
			mystack.push(node);
			//if (root->right)
			mystack.push({ node.first->left,false });
		}
	}
	for (auto iter : nums)
		cout << iter << " ";
	cout << endl;
	return nums[nums.size() - k];
}
void test01()
{
	TreeNode* node1 = new TreeNode(11);
	TreeNode* node2 = new TreeNode(1314);
	TreeNode* node3 = new TreeNode(90);
	TreeNode* node4 = new TreeNode(25);
	TreeNode* node5 = new TreeNode(521);
	TreeNode* node6 = new TreeNode(520);
	TreeNode* node7 = new TreeNode(8384);
	TreeNode* node8 = new TreeNode(23468);

	/*
				11一
					  1314二
					90三	      8384七
				25四	521五            23468八
					520六

	*/
	node1->right = node2;
	node2->left = node3;
	node2->right = node7;

	node3->left = node4;
	node3->right = node5;

	node5->left = node6;

	node7->right = node8;

	//cout << getLargest(node1) << endl;
	//cout << getSmallest(node1) << endl;

	cout << kthLargest(node1, 1) << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
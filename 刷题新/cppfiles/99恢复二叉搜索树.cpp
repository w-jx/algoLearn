#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/


//有序数组交换两个元素{ 1,6,3,4,5,2,7 };
void recoverArray(vector<int>& vec_node) {
	bool first = true;
	int idx_arr[2] = { 0 };
	int idx = 0;
	for (int i = 0; i < vec_node.size(); ++i) {
		if (i + 1 < vec_node.size() && vec_node[i] > vec_node[i + 1]) {
			if (first)
				idx_arr[idx++] = i;
			else
				idx_arr[idx++] = i + 1;
			first = !first;
		}

		if (idx == 2) {
			swap(vec_node[idx_arr[0]], vec_node[idx_arr[1]]);
			break;
		}
	}
}
//写不出来,看的题解
//中序遍历,把二叉搜索树的结点添加到数组中
void _inorder(TreeNode* root,vector<int>&nums) {
	if (!root)
		return;
	_inorder(root->left, nums);
	nums.push_back(root->val);
	_inorder(root->right, nums);
}
std::pair<int,int> findswaped(vector<int>& nums) {
	bool first = true;
	int idx_arr[2] = { 0 };
	int idx = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (i + 1 < nums.size() && nums[i] > nums[i + 1]) {
			if (first)
				idx_arr[idx++] = i;
			else
				idx_arr[idx++] = i + 1;
			first = !first;
		}

		if (idx == 2) {
			break;
		}
	}
	return make_pair(idx_arr[0], idx_arr[1]);
}
void recover(TreeNode* root, int cnt, int x, int y) {
	if (!root)
		return;
	if (root->val == x || root->val == y) {
		root->val = root->val == x ? y : x;
		if (--cnt == 0)
			return;
	}
	recover(root->left, cnt, x, y);
	recover(root->right, cnt, x, y);
}
void recoverTree(TreeNode* root) {
	vector<int> nums;
	_inorder(root, nums);
	auto swaped = findswaped(nums);


}
int num;

TreeNode* p1, * p2, * pre;
void _inorder2(TreeNode* root) {
	if (!root)
		return;
	if (num == 2)
		return;
	_inorder2(root->left);
	if (pre && pre->val > root->val) {
		if (!p1)//出现第二对的时候,p1不再赋值
			p1 = pre;
		p2 = root;
		++num;
	}
	pre = root;
	_inorder2(root->right);
}
void recoverTree2(TreeNode* root) {
	num = 0;
	_inorder2(root);
	swap(p1->val, p2->val);

}
void test01()
{
	TreeNode* root = new TreeNode(3, new TreeNode(1), new TreeNode(4));
	root->right->left = new TreeNode(2);
	recoverTree2(root);

	

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
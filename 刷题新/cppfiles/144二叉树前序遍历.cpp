#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/*
leecode题目介绍:
递归方法很简单,尝试用迭代做

*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
vector<int>v;
vector<int> preorderTraversal(TreeNode* root) {
	
	if (root == nullptr) {
		return v;
	}
	
	v.push_back(root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	return v;
}

vector<int> preorderTraversal1(TreeNode* root) {
	
	stack<pair<TreeNode*, bool>> s;
	s.push(make_pair(root, false));
	while (s.size() > 0) {
		pair<TreeNode*, bool> p = s.top();
		s.pop();
		if (p.first == NULL)
			continue;
		if (p.second == true)
			v.push_back(p.first->val);
		else {
			s.push(make_pair(p.first->right, false));
			s.push(make_pair(p.first->left, false));
			p.second = true;
			s.push(p);
		}
	}
	return v;
}
	

void  printelem(int val) {
	cout << val << " ";
}
void test01()
{
	TreeNode node1 = TreeNode(1);
	TreeNode node2 = TreeNode(2);
	TreeNode node3 = TreeNode(3);
	node1.right = &node2;
	node2.left = &node3;

	

	vector<int> v = preorderTraversal1(&node1);

	for_each(v.begin(), v.end(), printelem);
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
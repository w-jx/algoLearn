#if 0
#include "../headers/wjxHeaders.h"

//方法1 使用额外空间的方法
vector<TreeNode*> preorder(TreeNode* root)
{
	if (!root)
		return {};
	stack<std::pair<TreeNode*, bool>> mystack;
	mystack.push({ root,false });
	vector<TreeNode*> pre_vec;

	while (!mystack.empty()) {
		auto node = mystack.top();
		mystack.pop();

		if (node.second) {
			pre_vec.push_back(node.first);
		}
		else {
			if (node.first->right)
				mystack.push({ node.first->right,false });
			if (node.first->left)
				mystack.push({ node.first->left,false });
			node.second = true;
			mystack.push(node);
		}
	}
	return pre_vec;
}
void flatten(TreeNode* root) {
	
	auto pre_vec = preorder(root);
	pre_vec.push_back(nullptr);
	for (int i = 0; i < pre_vec.size()-1; ++i) {
		pre_vec[i]->left = nullptr;
		pre_vec[i]->right = pre_vec[i + 1];
	}
}
//进行先序遍历  这个代码是教程里面的，但是无法通过leetcode 
//用先序遍历 会丢失 右孩子 原因是我函数的参数2 忘了加引用
void preorder(TreeNode* root,TreeNode* &last)
{
	if (!root)//当前结点为空 直接返回
		return;
	if (!root->left && !root->right) {//没有左右子树
		last = root;
		return;
	}
	TreeNode* left_tmp = root->left;
	TreeNode* right_tmp = root->right;//备份左右指针
	TreeNode* left_last = nullptr, * right_last = nullptr;
	//有左子树  
	if (left_tmp) {
		preorder(left_tmp, left_last);
		//对左子树的遍历调用过后left_last仍然是nullptr，因此丢失左子树了
		root->left = nullptr;
		root->right = left_tmp;
		last = left_last;
	}
	if (right_tmp) {
		preorder(right_tmp, right_last);//把右子树拉直
		//有左子树的情况
		if (left_last) {
			left_last->right = right_tmp;
		}
		last = right_last;
	}
}
void flatten2(TreeNode* root) {
	TreeNode* last = nullptr;
	preorder(root, last);

}
//leetcode 官方题解
void flatten3(TreeNode* root) {
	TreeNode* curr = root;
	while (curr != nullptr) {
		if (curr->left != nullptr) {
			auto next = curr->left;
			auto predecessor = next;
			while (predecessor->right != nullptr) {
				predecessor = predecessor->right;
			}
			predecessor->right = curr->right;
			curr->left = nullptr;
			curr->right = next;
		}
		curr = curr->right;
	}
}
//leetcode 别人的题解 感觉很好理解
void flatten4(TreeNode* root) {
	if (!root) return;

	flatten4(root->left);
	flatten4(root->right);

	/**** 后序遍历位置 ****/
	// 1、左右子树已经被拉平成一条链表
	auto left = root->left;
	auto right = root->right;
	// 2、将左子树作为右子树
	root->left = NULL;
	root->right = left;
	// 3、将原先的右子树接到当前右子树的末端
	auto p = root;
	while (p->right) {//像遍历链表一样
		p = p->right;
	}
	p->right = right;
}


//刷题班代码测试
void test01()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);

	//root->left->left = new TreeNode(3);
	//root->left->right = new TreeNode(4);

	//root->right->right = new TreeNode(6);

	flatten2(root);//结果只有123
	while (root) {
		if (root->left) {
			cout << "error\n";
		}
		cout << root->val;
		root = root->right;
	}
	

}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
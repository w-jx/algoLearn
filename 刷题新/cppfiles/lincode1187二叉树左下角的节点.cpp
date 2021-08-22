#if 0
#include "../headers/wjxHeaders.h"

//通过层序遍历的方式来得到结果
int findBottomLeftValue(TreeNode* root) {
	queue<TreeNode*> myque;
	myque.push(root);
	int first = 0, last = 0;
	while (!myque.empty()) {	
		int len = myque.size();		
		for (int i = 0; i < len; ++i) {
			auto node = myque.front();
			myque.pop();
			if (i == 0) {
				first = node->val;			
			}
			if (i == len - 1) {
				last = node->val;
			}
			if (node->left)
				myque.push(node->left);
			if (node->right)
				myque.push(node->right);
		}
	}
	return first;

}
//找最深的一层
int maxidx = -1;
int value = 0;
void dfs(TreeNode* root,int idx) {
	if (!root)
		return;
	//第一次大于就是每层的最左边的节点
	if (idx > maxidx) {
		maxidx = idx;
		value = root->val;
	}
	dfs(root->left, idx + 1);
	dfs(root->right, idx + 1);
}
int findBottomLeftValue2(TreeNode* root) {
	dfs(root, 0);
	return value;
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
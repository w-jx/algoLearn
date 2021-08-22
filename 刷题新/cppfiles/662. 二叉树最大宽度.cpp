#if 0
#include "../headers/wjxHeaders.h"

//错误的解法:宽度定义为每一层最左边何最右边的非空结点的长度,包括
int widthOfBinaryTree(TreeNode* root) {
	if (!root)
		return 0;
	deque<TreeNode*> que;
	que.push_back(root);
	int maxLevel = 1;


	while (!que.empty()) {
		int len = static_cast<int>(que.size());

		maxLevel = std::max(maxLevel, len);

		for (size_t i = 0; i < len; ++i) {
			auto node = que.front();
			que.pop_front();
			if (node->left)
				que.push_back(node->left);
			if (node->right)
				que.push_back(node->right);
		}
	}
	return maxLevel;

}
/*
每个结点一个pos值
如果走向左子树,pos=pos*2
如果走向右子树,pos = pos*2+1
看同一层深度的时候,宽度是r-l+1

bfs:
记录结点的pos信息,对于每一个深度
第一个结点是最左边的节点
最后一个节点是是最右边的节点

*/
struct Qnode
{
	Qnode(TreeNode* curnode, int _depth, int _pos) :nd(curnode)
		, depth(_depth), pos(_pos) {}
	TreeNode* nd;
	int depth;
	int pos;
};
//这个pos *2会出现越界的情况
int widthOfBinaryTree2(TreeNode* root) {
	if (!root)
		return 0;
	deque<Qnode> que;
	que.push_back(Qnode(root, 0, 0));
	int curdepth = 0, left = 0, ans = 1;

	while (!que.empty()) {
		auto node = que.front();
		que.pop_front();
		if (node.nd) {
			que.push_back(Qnode(node.nd->left, node.depth + 1, node.pos * 2));
			que.push_back(Qnode(node.nd->right, node.depth + 1, node.pos * 2 + 1));
			if (curdepth != node.depth) {
				curdepth = node.depth;
				left = node.pos;
			}
			ans = std::max(ans, node.pos - left + 1);
		}
	}
	return ans;
}
//答案别人的题解
int widthOfBinaryTree3(TreeNode* root) {
	if (!root)
		return 0;
	int res = 0;
	queue<TreeNode*> que;
	root->val = 0;
	que.push(root);
	int offset = 0;//为了防止越界,offset等于每一层第一个元素的编号
	while (!que.empty()) {
		res = std::max(que.back()->val - que.front()->val + 1, res);
		offset = que.front()->val;
		int len = que.size();
		for (int i = 0; i < len; ++i) {
			auto cur = que.front();
			que.pop();
			cur->val -= offset;//缩小差值
			if (cur->left) {
				cur->left->val = cur->val * 2;
				que.push(cur->left);
			}
			if (cur->right) {
				cur->right->val = cur->val * 2 + 1;
				que.push(cur->right);
			}
		}
	}
	return res;
	
}
void test01()
{
	//TreeNode* node = new TreeNode(1, new TreeNode(3, 5, 3), nullptr);
	TreeNode* node = new TreeNode(1, new TreeNode(3, 5, 3), new TreeNode(2, nullptr, 9));
	cout << widthOfBinaryTree(node) << endl;
}
int main()
{
	test01();
}
#endif
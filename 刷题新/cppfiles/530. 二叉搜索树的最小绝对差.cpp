#if 0
#include "../headers/wjxHeaders.h"

/*
注意问题是  任意  两节点 差的绝对值

注意这个测试用例

		 100
	 50
30	    90
      93   99

结果是100,和99的差值最小,为1
*/

//想到的方法1,用哈希表存储父节点,然后比较
int minval = INT_MAX;
void preorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& rootMp)
{
	if (!root)
		return;
	if (root->left) {
		rootMp[root->left] = root;
		preorder(root->left, rootMp);
	}
	auto temp = root;
	while (rootMp.find(temp)!=rootMp.end() && rootMp[temp]) {//父结点不为空
		minval = std::min(minval, abs(root->val-rootMp[temp]->val));
		temp = rootMp[temp];
	}
	if (root->right) {
		rootMp[root->right] = root;
		preorder(root->right, rootMp);
	}
}
int getMinimumDifference(TreeNode* root) {
	//key->结点,对应的是其父结点
	unordered_map<TreeNode*, TreeNode*> rootMp;
	rootMp[root] = nullptr;
	preorder(root, rootMp);

	return minval;

}
//尝试优化,降低时间复杂度,没有得到本质的优化
void preorder2(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& rootMp)
{
	if (root->left) {
		rootMp[root->left] = root;
		preorder(root->left, rootMp);
	}
	auto temp = root;
	while (rootMp[temp]) {//父结点不为空
		minval = std::min(minval, abs(root->val - rootMp[temp]->val));
		temp = rootMp[temp];
	}
	if (root->right) {
		rootMp[root->right] = root;
		preorder(root->right, rootMp);
	}
}
int getMinimumDifference2(TreeNode* root) {
	//key->结点,对应的是其父结点
	unordered_map<TreeNode*, TreeNode*> rootMp;
	rootMp[root] = nullptr;
	preorder2(root, rootMp);

	return minval;

}

//方法3,中序遍历比较,时间复杂度大大减少
int pre;
bool first;
void preorder3(TreeNode* root)
{
	if (!root)
		return;
	preorder3(root->left);
	if (first) {
		first = false;
	}
	else {
		minval = std::min(minval, abs(root->val - pre));
	}
	pre = root->val;
	preorder3(root->right);
}
int getMinimumDifference3(TreeNode* root) {
	first = true;
	minval = INT_MAX;
	preorder3(root);
	return minval;
}
//进一步优化
bool hasfind;
void preorder4(TreeNode* root)
{
	if (hasfind)
		return;
	if (!root)
		return;
	preorder3(root->left);
	if (first) {
		first = false;
	}
	else {
		minval = std::min(minval, abs(root->val - pre));
		if (minval == 0) {
			hasfind = true;
			return;
		}
	}
	pre = root->val;
	preorder3(root->right);
}
int getMinimumDifference4(TreeNode* root) {
	first = true;
	hasfind = false;
	minval = INT_MAX;
	preorder3(root);
	return minval;
}
void test01()
{

}
int main()
{
	test01();
}
#endif
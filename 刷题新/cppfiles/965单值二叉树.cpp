#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
bool isUnivalTree(TreeNode* root) {
	if (root == nullptr)
		return true;
	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty()) {
		
		auto p = s.top();
		s.pop();

		if (p->left) {
			if (p->val != p->left->val)
				return false;
			s.push(p->left);
		}
		if (p->right) {
			if (p->val != p->right->val)
				return false;
			s.push(p->right);
		}

	}
	return true;




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
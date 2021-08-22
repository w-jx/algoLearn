#if 0
#include "../headers/wjxHeaders.h"
/*



*/
bool isequal(TreeNode* node1, TreeNode* node2) {
	if (!node2)
		return true;
	if (!node1 && node2  ||(node1->val !=node2->val))
		return false;
	bool isleftok = isequal(node1->left, node2->left);
	bool isrightok = isequal(node1->right, node2->right);

	return isleftok && isrightok;
}
bool isSubStructure(TreeNode* A, TreeNode* B) {

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
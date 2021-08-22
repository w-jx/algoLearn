#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/

TreeNode*  mergeTrees(TreeNode* t1, TreeNode* t2)
{
		if (t1 == nullptr && t2 == nullptr)
			return nullptr;
		int val = 0;
		TreeNode* t1left = nullptr;
		TreeNode* t1right = nullptr;
		TreeNode* t2left = nullptr;
		TreeNode* t2right = nullptr;
		if (t1 == nullptr && t2 != nullptr) {
			val = t2->val;	
			t2left = t2->left;
			t2right = t2->right;
		}
			
		if (t1 != nullptr && t2 == nullptr) {
			val = t1->val;
			t1left = t1->left;
			t1right = t1->right;
		}
			
		if (t1 != nullptr && t2 != nullptr) {
			val = t1->val+t2->val;	
			t1left = t1->left;
			t1right = t1->right;
			t2left = t2->left;
			t2right = t2->right;
		}
			
		TreeNode* pRet = new TreeNode(val);
		pRet->left = mergeTrees(t1left, t2left);
		pRet->right = mergeTrees(t1right, t2right);
		return pRet;
	
		
	
		

}
void test01()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(5);


	node1->left = node2;
	node1->right = node3;
	node2->left = node4;





	TreeNode* node12 = new TreeNode(2);
	TreeNode* node22 = new TreeNode(1);
	TreeNode* node32 = new TreeNode(3);
	TreeNode* node42 = new TreeNode(4);
	TreeNode* node52 = new TreeNode(7);


	node12->left = node22;
	node12->right = node32;

	node22->right = node42;
	node32->right = node52;


	recursionTree(mergeTrees(node1, node12));
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
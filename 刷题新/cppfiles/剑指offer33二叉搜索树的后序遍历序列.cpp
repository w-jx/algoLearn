#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

对于后序遍历序列，又是二叉搜索树，可以知道
左子树都比根小，右子树都比根大
*/
bool generate(vector<int>& post, int left, int right) {
	if (left >= right)
		return true;
	int rootval = post[right];
	int ptr = left;
	while (post[ptr] < rootval)
		++ptr;//可能加到一个比根节点大的位置,或者直接加到根节点的位置
	int leftend = ptr - 1;
	while (post[ptr] > rootval)
		++ptr;//按道理从这个位置的所有元素都应该大于根节点,直到根节点位置

	//ptr==right右子树这边都比根结点大
	return ptr == right && generate(post, left, leftend) && generate(post, leftend + 1, right-1);

}
bool verifyPostorder(vector<int>& postorder) {
	int n = postorder.size();
	return generate(postorder, 0, n-1);
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
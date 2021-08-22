#if 0
#include "../headers/wjxHeaders.h"

/*
* 
* 
二叉搜索树:
左结点 < 根节点 < 右结点,当然了对于每个子树也是这样的
综合起来就是:左子树<根<右子树

先序遍历:根->左->右
对于子树也是这样的,因此遍历左子树的时候,会越来越小
反映到单调栈上,是栈顶元素>当前元素

			5
		3		7
	2	 4	  6    8

[5,3,2...]
一旦出现栈顶元素小于当前元素
[5,3,2,4],2<4  说明已经要进入右子树了
不断弹出,直到更新到栈中只有5,栈顶的上一个元素3就是当前子树的根
此时的min_val=3,是子树的根,遍历右子树都要比根大,否则就是非法的

[5,4]

继续遍历,7 我们发现栈顶元素4<当前元素7
不断弹出,直到更新为min_val=5,也就是根结点
[7]
继续遍历6,进栈
[7,6]
继续遍历8
我们发现栈顶元素6<当前元素8
不断弹出,直到更新min_val = 7,也就是根结点

完成,确认是合法的前序遍历


*/
bool verifyPreorder(vector<int>& preorder) {
    int n = preorder.size();
	vector<int> stk;
	stk.reserve(n);
	int min_val = INT_MIN;
	for (const auto& nodeval : preorder) {
		//我们在遇到栈顶元素<当前元素之前
		//栈中的元素都是递减的
		//遇到栈顶元素<当前元素,说明开始进入右子树了,我们更新min_val为栈顶元素
		//合法的序列,后面遍历的所有结点都应该大于min_val才对
		if (nodeval < min_val)
			return false;
		//min_val是根结点的值,右子树应该都要大于它才对
		while (!stk.empty() && nodeval > stk.back()) {
			min_val = stk.back();
			stk.pop_back();
		}
		stk.push_back(nodeval);
	}
	return true;
}
void test01()
{

}
int main()
{
	test01();
}
#endif
#if 0
#include "../headers/wjxHeaders.h"

/*
前序遍历:根->左->右
1.判断左子树是否是有效的
2.判断右子树是否是有效的
3.判断根->左->右 是否是有效的

叶子结点:
	左右两个孩子都是空'#'的时候
非叶子结点:有两种情况
	1.左右都非空
	2.左右两个其中一个非空

为了兼容两种情况,对于叶子结点,可以进行压缩
	x,#,#---># 



*/
/*
评论里面的方法
逆序是:右->左->父
合法的情况下,最开始一定是有两个#,因为树的最右边的叶子节点
叶子结点,左右两个子树必定是"#"
在遇到一个数字后,只要大于两个'#',说明必然有两个叶子结点
说明就可以去除当前的数字结点,当成一个叶子结点,当成'#'看待

最后应该剩下的只有1个'#'



*/
bool isValidSerialization(string preorder) {
	int n = preorder.size();
	int cnt = 0;//利用cnt来计算

	for (int i = n - 1; i >= 0; --i) {
		if (preorder[i] == '.')
			continue;
		if (preorder[i] == '#')
			++cnt;
		else {
			//结点的数字可能不止1位
			while (i >= 0 && preorder[i] != ',')
				--i;
			//x,#,#->#,所以# 的数量减1个
			if (cnt >= 2)
				--cnt;
			else // # 的数量不足2个
				return false;
		}
	}
	return cnt == 1;//最后 # 的个数是1
}
void test01()
{

}
int main()
{
	test01();
}
#endif
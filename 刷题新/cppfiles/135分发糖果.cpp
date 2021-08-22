#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

贪心算法

1.所有孩子的 糖果数 初始化为1
2.从左向右遍历
	如果右边孩子的评分比左边的高，右边孩子的糖果数更新为左边孩子的糖果数+1
3.再 从右往左遍历
	如果左边孩子的评分比右边的高，且左边孩子当前的糖果数 不大于 右边孩子的糖果数
	左孩子糖果数更新为右边孩子的糖果数+1

	例如输入为[1,0,2]  输出为5
一开始需要的糖果为【1，1，1】,第一次遍历[1,1,2],第二次遍历[2,1,2],一共要5颗糖

*/
int candy(vector<int>& ratings) {
	int size = ratings.size();
	if (size < 2)
		return size;//只有一个孩子或者没有孩子

	vector<int> candys(size, 1);//初始的时候，每个孩子分一个糖
	for (int i = 1; i < size; ++i) {
		if (ratings[i] > ratings[i - 1]) {//右边孩子的评分比左边高
			candys[i] = candys[i - 1] + 1;
		}
	}
	for (int i = size - 1; i > 0; --i) {
		if (ratings[i] <ratings[i-1]) {//ratings[i-1]是左边
			//左边孩子的评分 比右边孩子评分高
			//左边孩子的糖果 不大于 右边孩子的糖果数量
			candys[i - 1] = max(candys[i - 1], candys[i] + 1);
		}
	}
	int num = accumulate(candys.begin(), candys.end(), 0);


	return num;
	
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
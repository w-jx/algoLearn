#if 0
#include "../headers/wjxHeaders.h"

/*
原理就是一次遍历过程,找
1.当前最小的买入价格
2.不断维护最大利润

*/
int maxProfit(vector<int>& prices) {
	int profit = 0;
	int minprice = prices[0];//初始的时候最低价设置为第0天的
	int n = prices.size();
	for (int i = 1; i < n; ++i) {
		//不断更新最低买入价格
		minprice = std::min(prices[i], minprice);
		//不断更新利润
		profit = std::max(prices[i] - minprice, profit);
	}
	return profit;
}
void test01()
{

}
int main()
{
	test01();
}
#endif
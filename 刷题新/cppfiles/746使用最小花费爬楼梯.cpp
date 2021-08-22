#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

输入数组cost 长度为n，n个阶梯就是0,n-1，楼层顶就是n
问题等价于到达下标n的最小花费

dp[0]=dp[1]=0

2<=i<=n
dp[i]可以从i-1花费cos[i-1]到达,也可以通过i-2花费cos[i-2]到达
dp[i]=min(dp[i-1]+cos[i-1],dp[i-2]+cos[i-2])

return dp[n]即可
*/
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];

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
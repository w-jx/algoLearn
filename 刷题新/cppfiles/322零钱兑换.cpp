#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
例题1

*/

/// <summary>
/// 计算凑成金额amount需要的最小硬币数
/// </summary>
/// <param name="coins">不同面额的硬币</param>
/// <param name="amount">要凑成的金额</param>
/// <returns>能凑成，返回最小硬币数，否则返回-1</returns>
int coinChange(vector<int>& coins, int amount)
{
	/*为了便于理解，假设硬币有2，5，7三种，要凑的金额为27
	第一步:确定状态  k枚硬币 a1+a2+...ak=27
		1.最后一步  最后一枚硬币是ak
		也就是前面的硬币是27-ak
		为了整体是最小的，那么27-ak也需要硬币数最小
		2.子问题：27-ak最少用多少枚硬币组成
		f(x)代表凑成x需要的最小硬币数
	第二步：转移方程
	假如最后一枚是2  那么f(27)=f(27-2)+1
		最后一枚是5  那么f(27)=f(27-5)+1
		最后一枚是7	 那么f(27)=f(27-7)+1
	所以 f(27) = min{f(27-2)+1,f(27-5)+1,f(27-7)+1}

	f(x) = min(f(x-2)+1,f(x-5)+1,f(x-7)+1)

	第三步：初始条件 和 边界情况
	不能拼出Y，f(Y)=正无穷
	F[0]=0
	如果x-2 ,x-5,x-7小于0，应该舍弃处理
	第四步：确定计算顺序
	f(0)=0
	然后依次计算，因为后一个的结果依赖前一个的结果
	*/
	vector<int> dp(amount + 1, 0);
	int len = coins.size();
	for (int i = 1; i <= amount; ++i) {
		dp[i] = INT_MAX;
		for (int j = 0; j < len; ++j) {
			if (i>=coins[j] && dp[i-coins[j]]!=INT_MAX)
				dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}
//leetcode 刷题班的方法
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1,-1);//组成amount面额最小的硬币数
	dp[0] = 0;
	
	for (int i = 1; i <= amount; ++i) {

	}


	for (int i = 1; i <= amount; ++i) {//循环各个面值
		for (int j = 0; j < coins.size(); ++j) {
			if (i - coins[j] >= 0 && dp[i - coins[j] != -1]) {
				if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
					dp[i] = dp[i - coins[j]] + 1;
				}
			}
		}
	}//for

	return dp[amount];
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
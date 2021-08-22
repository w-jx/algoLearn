#if 0
#include "../headers/wjxHeaders.h"

/*
动态规划

*/
//爬到第i个台阶,要么从第i-1个台阶再爬一个
//要么从第i-2个台阶再爬2个,所以可以知道
//爬到第i个台阶的方法数是爬到第i-1个台阶的方法数和爬到第i-2个台阶的方法数之和
int climbStairs(int n) {
	//dp[i]代表爬到第i个台阶的方法数
	vector<int> dp(n + 3, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
		dp[n] = dp[n - 1] + dp[n - 2];
	return dp[n];
}
int climbStairs2(int n) {
	//dp[i]代表爬到第i个台阶的方法数
	int first = 1;//爬到第一个台阶
	int second = 2;//爬到第二个台阶
	int solus = 0;//方法数
	for (int i = 3; i <= n; ++i) {
		solus = first + second;
		first = second;
		second = solus;
	}
	return solus;
}
//假如现在可以爬的台阶数不再是1,2.而是1,2,5,是给定的数组,应该怎么写
int climbStairs3(int n,vector<int>&steps) {
	vector<int> dp(n + 1);
	dp[0] = 1;
	int len = steps.size();
	for (int i = 1; i <= n; ++i) {
		for (const int& step : steps) {
			if (i < step)continue;//跨越的步数小于台阶数
			dp[i] += dp[i - step];
		}
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
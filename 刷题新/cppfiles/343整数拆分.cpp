#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
剑指OFFER14:割绳子


假如 dp[i]代表整数i拆分后的最大乘积
dp[0]=0,dp[1]=1,
dp[2]=1,
dp[3]=2,
dp[4]=4
dp[5]=2*3=6
dp[6]=3*3=9
dp[7]=3*4=12
dp[8]=3*3*2=18,而不是4*4=16
dp[9]=3*3*3=27
dp[10]=3*3*4=36


*/

int cuttingRope(int n) {
	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 4;
	vector<int> dp(n + 1);
	for (int i = 0; i < 5; ++i)
		dp[i] = i;
	
	for (int i = 5; i <= n; ++i) {
		for (int j = 0; j < i-1; ++j) {
			dp[i] = std::max(dp[i - j] * j, dp[i]);
		}
	}
	return dp[n];
}
//对于122出现错误,这道题根本就不能用动态规划来做
int cuttingRope2(int n) {
	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 4;
	vector<unsigned long long > dp(n + 1);
	for (unsigned long long i = 0; i < 5; ++i)
		dp[i] = i;
	 
	int mod = 1e9 + 7;
	for (unsigned long long i = 5; i <= n; ++i) {
		for (unsigned long long j = 1; j < i - 1; ++j) {
			unsigned long long first = (dp[i - j] * j) % mod;
			unsigned long long second = dp[i] % mod;
			//dp[i] = std::max(dp[i - j] * j, dp[i]);
			dp[i] = std::max(first, second);
		}
	}

	
	return static_cast<int>(dp[n]% mod);
}

void test01()
{
	/*\
122:
604361582错误  906542373正确
121:
604361582 
	*/
	cout << cuttingRope2(122) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
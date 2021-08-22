#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个正整数，问这个正整数最少可以用几个完全平方数相加

属于分割类问题，动态规划的状态转移方程通常不依赖相邻的位置
而是按照满足分割条件的位置

dp[i]只依赖i-k^2的位置
*/

int numSquares(int n) {
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	return dp[n];
}
bool issqrt(int n) {
    int k = sqrt(n);
    return k * k == n;
}
//2021年6月9日复习做的,拉跨的方法
int numSquares2(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    unordered_set<int> squ;
    squ.insert(1);
    for (int i = 2; i <= n; ++i) {
        if (issqrt(i)) {
            dp[i] = 1;
            squ.insert(i);
        }
        else {
            dp[i] = INT_MAX;
            for (auto iter : squ) {
                dp[i] = std::min(dp[i], dp[iter] + dp[i - iter]);
            }
        }
    }//for
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
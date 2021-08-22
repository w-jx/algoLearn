#if 0
#include "../headers/wjxHeaders.h"

//dp[i][j]代表从word1[0:i]到word2[0:j]需要的步数
/*
	返回值:dp[n1-1][n2-1]
	初始化条件:
	dp[0][j] = j;从word1啥都不取,到word2的[:j]需要j步
	dp[i][0] = i;从word2啥都不取,word1需要删除i个,所以是i步
	转移方程呢:
	if word1[i]==word2[j]
	dp[i][j] = dp[i-1][j-1]
	else
						替换                增加         删除
		dp[i][j] =std::min( dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1)
*/
int minDistance(string word1, string word2) {
	int n1 = word1.size();
	int n2 = word2.size();

	if (n1 == 0)
		return n2;
	if (n2 == 0)
		return n1;
	//dp[i][j]代表word1的第i个到word2第j个,需要的步数
	vector<vector<int> > dp(n1+1, vector<int>(n2+1));
	for (int j = 0; j <= n2; ++j)
		dp[0][j] = j;
	for (int i = 0; i <= n1; ++i) {
		dp[i][0] = i;
	}

	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = std::min({ dp[i - 1][j - 1] + 1,dp[i][j - 1] + 1,dp[i - 1][j] + 1 });
		}
	}
	return dp[n1][n2];

}
void test01()
{

}
int main()
{
	test01();
}
#endif
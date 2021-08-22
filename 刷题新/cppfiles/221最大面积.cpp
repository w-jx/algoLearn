#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个二维的0，1矩阵，求全由1构成的最大正方形面积


*/

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.empty() && matrix.front().empty())
		return 0;
	int m = matrix.size(), n = matrix[0].size(), max_side = 0;
	vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));
	//这个dp[i][j]代表以[i][j]为右下角能组成的最大正方形面积的边长
	//假如是k^2，那么dp[i-1][j],dp[i][j-1],d[i-1][j-1]至少是(k-1)^2
	//因此我们从下标1开始遍历
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (matrix[i - 1][j - 1] == '1') {
				dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
			}

			max_side = max(max_side, dp[i][j]);
		}
	}
	return max_side * max_side;
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
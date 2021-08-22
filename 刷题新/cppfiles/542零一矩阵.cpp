#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。



*/
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
	int m = matrix.size(), n = matrix[0].size();
	//初始化动态规划数组，初始的距离值很大
	vector<vector<int> >dp(m, vector<int>(n, INT_MAX / 2));

	for (int i = 0; i < m; ++i) {//先从左上到右下进行一次搜索
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == 0)
				dp[i][j] = 0;
			else {
				if (j > 0)
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);//左边
				if (i > 0)
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);//上边
			}
		}
	}

	for (int i = m - 1; i>= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (matrix[i][j] != 0) {
				if (j < n - 1)
					dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
				if (i < m - 1)
					dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
			}
		}
	}

	return dp;
}
void test01()
{
	vector<vector<int> >v{
		{0,0,0},
		{0,1,0},
		{1,1,1}
	};
	printvectorvector(updateMatrix(v));
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
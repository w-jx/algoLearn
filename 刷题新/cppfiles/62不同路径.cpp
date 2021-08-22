#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
	
例题2
*/

/// <summary>
/// 机器人从0，0出发到m*n网络的右下角，总共有多少条不同路径
/// </summary>
/// <param name="m">m行</param>
/// <param name="n">n列</param>
/// <returns>总共的路径数</returns>
int uniquePaths(int m, int n) {
	/*
	第一步：确定状态
	最后到达的是[m-1,n-1]，上一步要么是[m-2,n-1],要么是[m-1,n-2]
		最后要么是向右走，要么向下走
	子问题：到达[m-2,n-1]有多少种路径，假设为X，到达[m-1,n-2]有多少种路径，假设为Y
	则总路径有X+Y  从（0，0）---》[m-1,n-1]

	第二步:确定转移方程
		f[i][j] = f[i-1][j]+f[i][j-1]

	第三步：初始条件和边界条件
	首先f[0][0]=1，注意是1，不是0
	边界的话如果i=0，只能向右走
	如果j=0，只能向下走

	最后一步：确定计算顺序
	可以从第0行到第m-1行
	*/
	vector<vector<int> > dp(m, vector<int>(n, 1));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || j == 0)
				dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[m - 1][n - 1];
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
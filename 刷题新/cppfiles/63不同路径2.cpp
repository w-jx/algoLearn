#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int> > dp(m, vector<int>(n));
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    //第一行的
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] != 1)
            dp[0][j] = dp[0][j - 1];
        else
            dp[0][j] = 0;
    }
    //第一列的
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] != 1)
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = 0;
    }



    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] != 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            else
                dp[i][j] = 0;
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
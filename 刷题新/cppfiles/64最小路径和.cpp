#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
//想办法输出具体路径,失败了
vector<int> path;
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int> > dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int j = 1; j < m; ++j) {
        dp[j][0] = dp[j - 1][0] + grid[j][0];
    }
    path.push_back(grid[0][0]);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {  
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}
void test01()
{
    vector<vector<int> > grid{ {1,3,1},{1,5,1},{4,2,1} };
    cout << minPathSum(grid) << endl;
    for (auto iter : path)
        cout << iter << " ";
    cout << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif
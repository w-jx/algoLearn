#if 0
#include "../headers/wjxHeaders.h"

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    int cnt = 0;

    //dp[i][j]是以单元格[i][j]为右下角得到的最大的正方形边长
    //同时,也是以[i][j]为右下角的所有小正方形数目之和
    /*
    [
        1 1
        1 1
    ]
    dp[0][0]=1
    dp[0][1]=1
    dp[1][0]=1
    最后我们固定[1][1],可以发现组成的最大正方形边长为2
    同时也说明能组成2个小正方形,一个是右下角的边长为1的,另外
    是边长为2的,因为我们固定右下脚,所以所有的dp[i][j]都不会重复
    最后累加就行了
    
    */
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (matrix[i - 1][j - 1] == 1) {
                dp[i][j] = std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1; 
            }
            cnt += dp[i][j];
        }
    }
    return  cnt;
}
void test01()
{
    vector<vector<int> > matrix
    {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    cout << countSquares(matrix) << endl;

}
int main()
{
	test01();
}
#endif
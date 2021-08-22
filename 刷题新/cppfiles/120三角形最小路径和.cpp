#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/

/// <summary>
/// 从下网上找路径
/// </summary>
/// <param name="triangle"></param>
/// <returns></returns>
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.empty())
		return 0;
	/*
	1 <= triangle.length <= 200
	triangle[0].length == 1
	triangle[i].length == triangle[i - 1].length + 1
	假如我们的triangle有200行(最大),那么每一行的元素个数最大也就是200
	因此,我们直接给dp数组初始化 triangle.size()大小是稳妥的
	*/
	vector < vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));

	for (int i = 0; i < triangle.size(); ++i) {
		dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
	} //从下往上面找路径,所以最下面的路径就是三角形的最下面一行的大小

	//从后一排已经确定了,现在确定从倒数第二排到第1排
	for (int i = dp.size() - 2; i >= 0; --i) {
		for (int j = 0; j < triangle[i].size(); ++j) {
			dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return dp[0][0];//dp[0][0]
}
//2021年5月16日复习
int minimumTotal2(vector<vector<int>>& triangle) {
	int n = triangle.size();
	vector<vector<int> > dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		dp[n - 1][i] = triangle[n - 1][i];
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return dp[0][0];
	}
void test01()
{
	vector<vector<int>>v{ {2}, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 }};
	cout << minimumTotal2(v) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif       
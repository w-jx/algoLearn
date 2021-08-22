#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/

/// <summary>
/// ����������·��
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
	�������ǵ�triangle��200��(���),��ôÿһ�е�Ԫ�ظ������Ҳ����200
	���,����ֱ�Ӹ�dp�����ʼ�� triangle.size()��С�����׵�
	*/
	vector < vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));

	for (int i = 0; i < triangle.size(); ++i) {
		dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
	} //������������·��,�����������·�����������ε�������һ�еĴ�С

	//�Ӻ�һ���Ѿ�ȷ����,����ȷ���ӵ����ڶ��ŵ���1��
	for (int i = dp.size() - 2; i >= 0; --i) {
		for (int j = 0; j < triangle[i].size(); ++j) {
			dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return dp[0][0];//dp[0][0]
}
//2021��5��16�ո�ϰ
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
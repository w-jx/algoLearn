#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
vector<vector<int> > dp;
vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if (m == 0 || n == 0)return {};
	if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		return {};
	//vector<vector<int> > dp(m, vector<int>(n));
	dp.resize(m);
	for (int i = 0; i < m; ++i)
		dp[i].resize(n);
	dp[0][0] = 1;
	//��һ�е�
	for (int j = 1; j < n; ++j) {
		if (obstacleGrid[0][j] != 1)
			dp[0][j] = dp[0][j - 1];
		else
			dp[0][j] = 0;
	}
	//��һ�е�
	for (int i = 1; i < m; ++i) {
		if (obstacleGrid[i][0] != 1)
			dp[i][0] = dp[i - 1][0];
		else
			dp[i][0] = 0;
	}



	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (obstacleGrid[i][j] != 1) {//
				//dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				//��ΪֻҪ��һ��·��,�������ǿ��Բ������
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
			else
				dp[i][j] = 0;
		}
	}
	//���յ��·��������0
	if (dp[m - 1][n - 1] == 0)
		return {};
	int row = m - 1, col = n - 1;
	vector<vector<int> > res;
	//�����һ��λ������,�����ƽ������
	while (row != 0 || col != 0) {
		res.push_back({ row,col });
		int up = 0, left = 0;
		if (row > 0)
			up = dp[row - 1][col];
		if (col > 0)
			left = dp[row][col - 1];
		//�Ƚ�up��left �Ĵ�С,����ǰһ��·�����ĸ�
		if (up > left)
			--row;
		else
			--col;
	}
	res.push_back({ 0,0 });//��������
	reverse(res.begin(), res.end());
	return res;

}

//2021��5��20�ո�ϰ
vector<vector<int>> pathWithObstacles2(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	
	if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		return {};
	vector<vector<int> > dp(m, vector<int>(n));
	dp[0][0] = 1;
	for (int j = 1; j < n; ++j) {
		if (obstacleGrid[0][j] == 1)
			dp[0][j] = 0;
		else
			dp[0][j] = dp[0][j - 1];
	}
	for (int i = 1; i < m; ++i) {
		if (obstacleGrid[i][0] == 1) {
			dp[i][0] = 0;
		}
		else {
			dp[i][0] = dp[i - 1][0];
		}
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (obstacleGrid[i][j] == 1)
				dp[i][j] = 0;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	if (dp[m - 1][n - 1] == 0)
		return {};

	vector<vector<int> > res;//���ս��

	int i = m - 1, j = n - 1;
	while (i != 0 || j != 0) {
		res.push_back({ i,j });
		int up = 0, left = 0;
		if (i > 0)
			up = dp[i - 1][j];
		if (j > 0)
			left = dp[i][j - 1];

		if (up >= left)
			--i;
		else
			--j;
	}
	res.push_back({ 0,0 });

	return res;

}

void test01()
{
	//vector<vector<int>>grid{ {0,0,0},{0,1,0},{0,0,0} };
	vector<vector<int>>grid{ {0,1},{1,0} };
	auto res = pathWithObstacles2(grid);

	printvectorvector(res);

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
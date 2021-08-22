#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ���� 0 �� 1 ��ɵľ����ҳ�ÿ��Ԫ�ص������ 0 �ľ��롣

��������Ԫ�ؼ�ľ���Ϊ 1 ��



*/
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
	int m = matrix.size(), n = matrix[0].size();
	//��ʼ����̬�滮���飬��ʼ�ľ���ֵ�ܴ�
	vector<vector<int> >dp(m, vector<int>(n, INT_MAX / 2));

	for (int i = 0; i < m; ++i) {//�ȴ����ϵ����½���һ������
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == 0)
				dp[i][j] = 0;
			else {
				if (j > 0)
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);//���
				if (i > 0)
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);//�ϱ�
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
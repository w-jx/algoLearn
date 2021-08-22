#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ����ά��0��1������ȫ��1���ɵ�������������


*/

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.empty() && matrix.front().empty())
		return 0;
	int m = matrix.size(), n = matrix[0].size(), max_side = 0;
	vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));
	//���dp[i][j]������[i][j]Ϊ���½�����ɵ��������������ı߳�
	//������k^2����ôdp[i-1][j],dp[i][j-1],d[i-1][j-1]������(k-1)^2
	//������Ǵ��±�1��ʼ����
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
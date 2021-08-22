#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
	
����2
*/

/// <summary>
/// �����˴�0��0������m*n��������½ǣ��ܹ��ж�������ͬ·��
/// </summary>
/// <param name="m">m��</param>
/// <param name="n">n��</param>
/// <returns>�ܹ���·����</returns>
int uniquePaths(int m, int n) {
	/*
	��һ����ȷ��״̬
	��󵽴����[m-1,n-1]����һ��Ҫô��[m-2,n-1],Ҫô��[m-1,n-2]
		���Ҫô�������ߣ�Ҫô������
	�����⣺����[m-2,n-1]�ж�����·��������ΪX������[m-1,n-2]�ж�����·��������ΪY
	����·����X+Y  �ӣ�0��0��---��[m-1,n-1]

	�ڶ���:ȷ��ת�Ʒ���
		f[i][j] = f[i-1][j]+f[i][j-1]

	����������ʼ�����ͱ߽�����
	����f[0][0]=1��ע����1������0
	�߽�Ļ����i=0��ֻ��������
	���j=0��ֻ��������

	���һ����ȷ������˳��
	���Դӵ�0�е���m-1��
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
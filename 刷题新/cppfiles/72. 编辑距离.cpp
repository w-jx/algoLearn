#if 0
#include "../headers/wjxHeaders.h"

//dp[i][j]�����word1[0:i]��word2[0:j]��Ҫ�Ĳ���
/*
	����ֵ:dp[n1-1][n2-1]
	��ʼ������:
	dp[0][j] = j;��word1ɶ����ȡ,��word2��[:j]��Ҫj��
	dp[i][0] = i;��word2ɶ����ȡ,word1��Ҫɾ��i��,������i��
	ת�Ʒ�����:
	if word1[i]==word2[j]
	dp[i][j] = dp[i-1][j-1]
	else
						�滻                ����         ɾ��
		dp[i][j] =std::min( dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1)
*/
int minDistance(string word1, string word2) {
	int n1 = word1.size();
	int n2 = word2.size();

	if (n1 == 0)
		return n2;
	if (n2 == 0)
		return n1;
	//dp[i][j]����word1�ĵ�i����word2��j��,��Ҫ�Ĳ���
	vector<vector<int> > dp(n1+1, vector<int>(n2+1));
	for (int j = 0; j <= n2; ++j)
		dp[0][j] = j;
	for (int i = 0; i <= n1; ++i) {
		dp[i][0] = i;
	}

	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = std::min({ dp[i - 1][j - 1] + 1,dp[i][j - 1] + 1,dp[i - 1][j] + 1 });
		}
	}
	return dp[n1][n2];

}
void test01()
{

}
int main()
{
	test01();
}
#endif
#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ������������������������ٿ����ü�����ȫƽ�������

���ڷָ������⣬��̬�滮��״̬ת�Ʒ���ͨ�����������ڵ�λ��
���ǰ�������ָ�������λ��

dp[i]ֻ����i-k^2��λ��
*/

int numSquares(int n) {
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	return dp[n];
}
bool issqrt(int n) {
    int k = sqrt(n);
    return k * k == n;
}
//2021��6��9�ո�ϰ����,����ķ���
int numSquares2(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    unordered_set<int> squ;
    squ.insert(1);
    for (int i = 2; i <= n; ++i) {
        if (issqrt(i)) {
            dp[i] = 1;
            squ.insert(i);
        }
        else {
            dp[i] = INT_MAX;
            for (auto iter : squ) {
                dp[i] = std::min(dp[i], dp[iter] + dp[i - iter]);
            }
        }
    }//for
    return dp[n];

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
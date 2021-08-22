#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

��������cost ����Ϊn��n�����ݾ���0,n-1��¥�㶥����n
����ȼ��ڵ����±�n����С����

dp[0]=dp[1]=0

2<=i<=n
dp[i]���Դ�i-1����cos[i-1]����,Ҳ����ͨ��i-2����cos[i-2]����
dp[i]=min(dp[i-1]+cos[i-1],dp[i-2]+cos[i-2])

return dp[n]����
*/
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
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
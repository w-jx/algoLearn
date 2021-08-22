#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����1

*/

/// <summary>
/// ����ճɽ��amount��Ҫ����СӲ����
/// </summary>
/// <param name="coins">��ͬ����Ӳ��</param>
/// <param name="amount">Ҫ�ճɵĽ��</param>
/// <returns>�ܴճɣ�������СӲ���������򷵻�-1</returns>
int coinChange(vector<int>& coins, int amount)
{
	/*Ϊ�˱�����⣬����Ӳ����2��5��7���֣�Ҫ�յĽ��Ϊ27
	��һ��:ȷ��״̬  köӲ�� a1+a2+...ak=27
		1.���һ��  ���һöӲ����ak
		Ҳ����ǰ���Ӳ����27-ak
		Ϊ����������С�ģ���ô27-akҲ��ҪӲ������С
		2.�����⣺27-ak�����ö���öӲ�����
		f(x)����ճ�x��Ҫ����СӲ����
	�ڶ�����ת�Ʒ���
	�������һö��2  ��ôf(27)=f(27-2)+1
		���һö��5  ��ôf(27)=f(27-5)+1
		���һö��7	 ��ôf(27)=f(27-7)+1
	���� f(27) = min{f(27-2)+1,f(27-5)+1,f(27-7)+1}

	f(x) = min(f(x-2)+1,f(x-5)+1,f(x-7)+1)

	����������ʼ���� �� �߽����
	����ƴ��Y��f(Y)=������
	F[0]=0
	���x-2 ,x-5,x-7С��0��Ӧ����������
	���Ĳ���ȷ������˳��
	f(0)=0
	Ȼ�����μ��㣬��Ϊ��һ���Ľ������ǰһ���Ľ��
	*/
	vector<int> dp(amount + 1, 0);
	int len = coins.size();
	for (int i = 1; i <= amount; ++i) {
		dp[i] = INT_MAX;
		for (int j = 0; j < len; ++j) {
			if (i>=coins[j] && dp[i-coins[j]]!=INT_MAX)
				dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
		}
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}
//leetcode ˢ���ķ���
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1,-1);//���amount�����С��Ӳ����
	dp[0] = 0;
	
	for (int i = 1; i <= amount; ++i) {

	}


	for (int i = 1; i <= amount; ++i) {//ѭ��������ֵ
		for (int j = 0; j < coins.size(); ++j) {
			if (i - coins[j] >= 0 && dp[i - coins[j] != -1]) {
				if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
					dp[i] = dp[i - coins[j]] + 1;
				}
			}
		}
	}//for

	return dp[amount];
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
#if 0
#include "../headers/wjxHeaders.h"

/*
��̬�滮

*/
//������i��̨��,Ҫô�ӵ�i-1��̨������һ��
//Ҫô�ӵ�i-2��̨������2��,���Կ���֪��
//������i��̨�׵ķ�������������i-1��̨�׵ķ�������������i-2��̨�׵ķ�����֮��
int climbStairs(int n) {
	//dp[i]����������i��̨�׵ķ�����
	vector<int> dp(n + 3, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
		dp[n] = dp[n - 1] + dp[n - 2];
	return dp[n];
}
int climbStairs2(int n) {
	//dp[i]����������i��̨�׵ķ�����
	int first = 1;//������һ��̨��
	int second = 2;//�����ڶ���̨��
	int solus = 0;//������
	for (int i = 3; i <= n; ++i) {
		solus = first + second;
		first = second;
		second = solus;
	}
	return solus;
}
//�������ڿ�������̨����������1,2.����1,2,5,�Ǹ���������,Ӧ����ôд
int climbStairs3(int n,vector<int>&steps) {
	vector<int> dp(n + 1);
	dp[0] = 1;
	int len = steps.size();
	for (int i = 1; i <= n; ++i) {
		for (const int& step : steps) {
			if (i < step)continue;//��Խ�Ĳ���С��̨����
			dp[i] += dp[i - step];
		}
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
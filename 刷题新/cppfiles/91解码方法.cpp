#if 0
#include "../headers/wjxHeaders.h"


int numDecodings(string s) {
	int n = s.size();
	if (s[0] == '0')
		return 0;
	vector<int> dp(n, 0);
	dp[0] = 1;
	//"06","0","306"
	for (int i = 1; i < n; ++i) {
		if ((s[i - 1] == '1' && s[i] >= '1' && s[i] <= '9') || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
			if (i > 2)
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1] + 1;
		}
		//10011
		else if (s[i] == '0') {
			if (s[i - 1] >= '3' || s[i - 1] <= '0')
				return 0;
			if (i > 2)
				dp[i] = dp[i - 2];
			else
				dp[i] = 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	return dp[n - 1];
}
//2021年6月6日复习
int numDecodings2(string s) {
	int n = s.size();
	//dp[i]代表到s[i]有多少种映射方法
	vector<int> dp(n);

	if (s[0] == '0')
		return 0;
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == 0 && (s[i - 1] < '1' || s[i - 1]>'2'))
			return 0;
		if (s[i] == 0)
			dp[i] = 1;
		else {
			if ((s[i - 1] == '1' && s[i] > '0' && s[i] <= '9') || (s[i - 1] == '2' && s[i] > '0' && s[i] <= '6'))
				dp[i] = dp[i - 1] + 1;
		}
	}
	return dp[n - 1];
}
//题解
int numDecodings3(string s) {
	int n = s.size();
	//之所以要n+1,因为dp(i)可能和dp(i-2)有关
	//可以简化边界
	vector<int> dp(n + 1);
	//dp[0]=1,空字符串也有1种解码方法,空字符串
	//解析的方法=只用当前字符方法+用当前字符和前一个字符方法
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		//只要当前字符不为'0',那么就有前一个字符的解码数
		if (s[i - 1] != '0')
			dp[i] += dp[i - 1];
		//用两个字符,不能大于26
		//想用2个字符,i至少要大于1才行

		//i为1->字符串下标0,i为2->字符串下标1(此时有0,1两个字符)
		if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26) {
			dp[i] += dp[i - 2];//前i-2个字符组成dp[i-2]方法
		}
	}
	return dp[n];
}
//题解的基础上状态压缩
int numDecodings4(string s) {
	int n = s.size();
	int first = 1, second = 1, cur = 0;
	for (int i = 1; i <= n; ++i) {
		//只要当前字符不为'0',那么就有前一个字符的解码数
		if (s[i - 1] != '0')
			cur += second;
		//用两个字符,不能大于26
		//想用2个字符,i至少要大于1才行

		//i为1->字符串下标0,i为2->字符串下标1(此时有0,1两个字符)
		if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26) {
			cur += first;//前i-2个字符组成dp[i-2]方法
		}
		first = second;
		second = cur;
		cur = 0;
	}
	return second;
}
void test01()
{
	cout << numDecodings2("10") << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
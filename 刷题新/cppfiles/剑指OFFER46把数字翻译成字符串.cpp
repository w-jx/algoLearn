#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>

//dp[n-1]代表结果的
int translateNum2(int num) {
	stringstream s(to_string(num));
	int n = s.str().size();
	vector<int> dp(n + 1,0);
	dp[0] = 1;
	auto numstr = s.str();
	for (int i = 1; i <n; ++i) {
		if (numstr[i - 1] == '1' ||(numstr[i] <= '5' && numstr[i-1] == '2')) {
			if (i > 1)
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1] + 1;
		}
		else
			dp[i] = dp[i - 1];
	}
	return dp[n-1];
}
//dp[n]代表结果的
int translateNum(int num) {
	stringstream s(to_string(num));
	int n = s.str().size();
	vector<int> dp(n + 1, 1);

	auto numstr = s.str();
	for (int i = 2; i <= n; ++i) {
		if (numstr[i - 2] == '1' || (numstr[i - 2] == '2' && numstr[i - 1] <= '5'))
			dp[i] = dp[i - 1] + dp[i - 2];
		else
			dp[i] = dp[i - 1];
	}
	return dp[n];
}
void test01()
{
	cout << translateNum2(18580) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
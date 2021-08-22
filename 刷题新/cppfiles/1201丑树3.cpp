#if 0
#include "../headers/wjxHeaders.h"

int nthUglyNumber(int n, int a, int b, int c) {
	vector<int> dp(n + 1);
	dp[0] = 1;
	
	int pa = 0, pb = 0, pc = 0;
	for (int i = 1; i <= n; ++i) {
		int numa = dp[pa] * a;
		int numb = dp[pb] * b;
		int numc = dp[pc] * c;

		dp[i] = std::min({ numa, numb, numc });
		if (numa == dp[i])
			++pa;
		if (numb == dp[i])
			++pb;
		if (numc == dp[i])
			++pc;
	}
	return dp[n];
	
}
void test01()
{
	cout << nthUglyNumber(5, 2, 11, 13) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
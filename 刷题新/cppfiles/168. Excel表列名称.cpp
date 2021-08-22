#if 0
#include "../headers/wjxHeaders.h"
/*
701 = 26*26+25
701%26 = 25-->Y
701/26 = 26...25(26.9,截取了变成26了)

701->ZY
701 = 26*26+25

52->AY
52 = 26+26

52/26 = 2...0;


*/
string convertToTitle(int columnNumber) {
	char num_set[27];
	for (int i = 1; i <= 26; ++i)
		num_set[i] = 'A' + i - 1;
	num_set[0] = 'Z';

	string ret;
	while (columnNumber > 0) {
		int cur = columnNumber % 26;
		ret += num_set[cur];
		columnNumber -= (cur == 0 ? 26 : cur);
		columnNumber /= 26;
	}

	reverse(ret.begin(), ret.end());
	return ret;
}
void test01()
{
	cout << convertToTitle(2147483647) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif
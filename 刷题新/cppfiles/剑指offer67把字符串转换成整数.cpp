#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。
如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。




*/
//方法1
int strToInt(string str) {
	int n = str.size();
	int i = 0;
	//找到第一个不为空的位置
	for (; i < n && str[i] == ' '; i++);
	if (i >= n) return 0;

	bool negative = (str[i] == '-');
	if (str[i] == '+' || str[i] == '-') i++;
	long long res = 0;//保存中间结果，判断是否溢出
	for (; i < n; i++) {
		if (str[i] > '9' || str[i] < '0') break;//遇到非数字的了，结束累加
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX) {
			if (!negative) return INT_MAX;//
			if (res - 1 > INT_MAX) return INT_MIN;//首先上面的符号标志位
			//如果现在还没有加符号，long long 可以保存更小的数值  INT_MIN -2147483648 
			//例如此时保存的数值  2147483649  减去1就是 2147483648  比INT_MAX  2147483647大
			//所以加上符号位肯定溢出了，返回INT_MIN
		}
	}
	if (negative) res *= -1;
	return static_cast<int>(res);
}
void test01()
{
	int m1 = INT_MIN;
	int m2 = INT_MAX;
	long long  m = INT_MIN;
	int k = m - 1;
	long long i = INT_MIN - 1000;
	long long j = INT_MIN - 1;
	cout << m1 << endl; //-2147483648 
	cout << m2 << endl; //2147483647 
	cout << m << endl;//-2147483648
	cout << k << endl;// 2147483647
	cout << i << endl;//2147482648
	cout << j << endl;//2147483647
	cout << INT_MAX << endl;//2147483647

	long long res = INT_MIN - 10;
	if (res-1 > INT_MAX)
		cout << ">\n";
	else
		cout << "<\n";

	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
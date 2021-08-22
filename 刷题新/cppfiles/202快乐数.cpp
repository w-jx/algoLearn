#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

*/

vector<int> getnumbits(int n) {
	
	if (n < 10) return { n };
	vector<int> v;

	while (n >10) {
		v.push_back(n % 10);
		n = n / 10;

	}
	v.push_back(n);

	return v;
}

int getSquareSum(int n) {
	if (n < 10) return { n*n };
	

	int sum = 0;
	while (n > 10) {
		int temp = n % 10;
		sum += temp * temp;
		
		n = n / 10;

	}
	sum += n * n;

	return sum;
}

int isHappy2(int n) {
	return getSquareSum(n);
}
bool isHappy(int n) {

	int val = getSquareSum(n);
	if (val == 1)
		return true;
	else 
		return isHappy(val);

	
}
void test01()
{
	//printVector(getnumbits(18));
	//cout << getSquareSum(18) << endl;
	//cout << getSquareSum(7) << endl;
	//cout << getSquareSum(10) << endl;

	cout << isHappy(19) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
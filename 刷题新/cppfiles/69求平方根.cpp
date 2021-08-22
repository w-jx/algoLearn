#if 0
#include "../headers/wjxHeaders.h"



//int mySqrt(int x) {
//	if (x == 0 || x == 1)
//		return x;
//	double left = 0.0, right = x/2.0;
//	//cout << "right=" << right << endl;
//	double mid = 0.0,value=0;
//	while (value <x) {
//		//mid = static_cast<double>(left) + ( static_cast<double>(right) - static_cast<double>(left) ) / 2;
//		//mid = left + static_cast<double>((right - left)) / 2;
//		mid = left + (right - left) / 2.0;
//		//cout << "-----》mid=" << mid << endl;
//		value = mid * mid;
//		//cout << "------》value=" << value << endl;
//		if (value == x)
//			return mid;
//		else if (value < x)
//			left = mid + 1.0;
//		else
//			right = mid - 1.0;
//	}
//
//	return mid;
//
//}

int mySqrt(int x) {
	int l = 0, r = x, ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if ((long long)mid * mid <= x) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}

void test01()
{
	for (int i = 0; i < 20; i++)
		cout << "i=" << i << "," << mySqrt(i) << endl;
	//auto i = 2;
	//cout << i << "," << mySqrt(i) << endl;

}
void test02()
{
	int a = 10;
	double b = a / static_cast<double>(3);
	cout << "b=" << b << endl;

	double c = a / 3;//整数除法运算 结果 先去尾再转换为浮点数
	cout << "c=" << c << endl;

	cout << 10 / 2 << endl;
	cout << 10 / 2.0 << endl;
	cout << a / 2.0 << endl;//3个都是5，后两个类型double

	auto ptest = [=]()->int {
		double b = 2.99;
		double c = 1.37;
		int a = b - c;
		cout << "a=" << a << endl;//输出结果是1，先运算再截断
		int m = 5;
		int n = 2;
		double x = (m - n) / 2;  //3/2=1,先截断再赋值的
		cout << "x=" << x << endl;
		return b;
	};
	cout << "ptest=" << ptest() << endl;//输出结果是2，直接截断


}
//字节跳动,抖音,腾讯面试题,要求精确到3位小数
float sqrtf(int x) {
	long left = 0, right = x, mid = 0;
	long N = x;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (fabs(mid * mid- N)<1e-7)
			return mid;
		else if (mid * mid > N)
			right = mid;
		else if (mid * mid < N)
			left = mid + 1;
	}
	if (fabs(left * left-x)<1e-7)
		return x;
	return left - 1;
}
void test03() {
	cout << sqrtf(8) << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}


#endif
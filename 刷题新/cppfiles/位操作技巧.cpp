#if 0
#include "../headers/wjxHeaders.h"
/*
	位操作技巧
1.



*/

void test01()
{
	////大小写转换
	//char ch = 'a';
	//auto ch2 = (ch ^ ' ');//小写可以转大写，大写可以转小写
	//cout << (char)ch2 << endl;

	////判断两个数是否异号
	//int x = -1, y = 2, z = 3;
	//bool flag1 = ((x ^ y) < 0);//true
	//bool flag2 = ((y ^ z) < 0);//false 
	//cout << (bool)flag1 << "," << (bool)flag2 << endl;


	int a = INT_MIN;
	long long b = INT_MIN * (-1);
	cout << a << endl;
	cout << b << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
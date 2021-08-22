#if 0
#include "../headers/wjxHeaders.h"

/*
* 如果一个一个累加，时间复杂度达到O(N),
例如求x^64
x---x^2----x^4----x^8-----x^16---->x^32---->x64
这样只要6次

遇到例如2^77,77不能被2整除,先除以x即可
x^77---x76---x38----x19---x18---x9----x8---x4---x2---x
一共需要9次，比起77次也是减少了
*/


double quickMul(double x, long long N)
{
	if (N == 0) return 1.0;
	double y = quickMul(x, N / 2);//例如77/2=38.5-->38    ,例如64/2=32
	return N % 2 == 0 ? y * y : y * y * x;//77%2==38...1,所以x^77=x^38*x^38*x ,64%2==0,x^64=x^32*x^32
}
double myPow(double x, int n) {
	//if (x == 0) return 0;//底数不能是0
	//if (n == 0) return 1; //
	long long N = n;
	return N >= 0 ? quickMul(x, N) : 1.0 / (quickMul(x, -N));
	
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
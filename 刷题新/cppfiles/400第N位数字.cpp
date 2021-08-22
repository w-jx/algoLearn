#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>
/*
leecode题目介绍:


*/

//leetcode 答案题解
/*
1-9		有1*9个数字
10-99	有2*90个数字
100-999 有3*900个数字

第一步:确定n数字有几位数

第二步:找到n具体停留在那个数字上

第三步:找到n是数字的哪一位上

n是待查数字,dig代表数字几位数,base从9-90-900,num代表dig位数的起始数字
例如n=197   dig=1,base=9 num=0
	while (n>dig*base) {
		++dig;
		num+=base;//0-9
		base*=10;
		n-=dig*base;
	}
	//因为n从 1开始计数的,所以要n-1
	退出循环的时候n=8,dig=3,base=900,num=99
	num += (n-1)/dig+1 =99+(8-1)/3+1=102;
	再确定数字在102的第几位:
	idx = (n-1)%dig+1=2

	102的第二位,即0

*/
//给定的序列从1开始,N也是从1开始计数的
int findNthDigit(int n) {
	long dig = 1, base = 9, num = 0;//数的范围大一点
	while (n > dig * base) {
		num += base;//num从0开始到99,再到999
		n -= dig * base;
		base *= 10;
		++dig;//
	}
	num += (n - 1) / dig + 1;
	int idx = (n - 1) % dig + 1;
	
	/*
	idx=1,2,3  dig=3 ,num=102
	idx=3  
	不管num是多少,num%10都是取的最后一个数字
	1178&10=8,256%10=6...
	dig=1的时候,我们应该取第一个数字,只有让数字变成1位数,才能通过%10得到第一位数
		所以102/10=10,10/10=1
	dig=2的时候,我们应该取第二个数字,只有让数字变成2位数,才能通过%10得到第二位数
		102/10=10
	dig=3的时候,我们应该取第三个数字,只有让数字变成3位数,才能通过%10得到第二位数
		无需处理

	可以发现dig-idx 即是num需要除以10 的次数
	*/
	while (dig-- > idx)
		num /= 10;
	return num % 10;
	//stringstream s(to_string(num));
	//return s.str()[idx - 1]-'0';
	
}
void test01()
{
	//cout << findNthDigit(3) << endl;
	cout << findNthDigit(197) << endl;

	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
int get1nums(int n) {
	int cnt = 0;
	while (n) {
		if (n % 10==1)
			++cnt;
		n /= 10;
	}
	return cnt;
}
bool has1nums(int n) {

	while (n) {
		if (n % 10)
			return true;
		n /= 10;
	}
	return false;
}
//先暴力解法
int countDigitOne(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += get1nums(i);
	}
	return cnt;
}
//题解的解法
int countDigitOne2(int n) {
	//4560234    456 0 234
	int cnt = 0;
	//例如代求的是1234,k=10000的时候跳出循环,处理了4位
	for (int k = 1; k <= n; k *= 10) {
		//例如k=1000
		int low = n % k;//low=234
		int highwithmid = n / k;//highwithmid=4560
		int mid = highwithmid % 10;//mid =0 
		int high = highwithmid / 10;//high = 456

		cnt += high * k;
		if (mid == 1) {
			cnt += low + 1;
		}
		if (mid > 1)
			cnt += k;
		if (high == 0)//high==0,代表处理到了最高位,退出
			break;//不退出,k可能会溢出
	}
	return cnt;
}
int countDigitOne3(int n) {
	//4560234    456 0 234
	int cnt = 0;
	//例如代求的是1234,k=10000的时候跳出循环,处理了4位
	for (long k = 1; k <= n; k *= 10) {
		//例如k=1000
		int low = n % k;//low=234
		int highwithmid = n / k;//highwithmid=4560
		int mid = highwithmid % 10;//mid =0 
		int high = highwithmid / 10;//high = 456

		cnt += high * k;
		if (mid == 1) {
			cnt += low + 1;
		}
		if (mid > 1)
			cnt += k;
		//让k 设置成long 类型,超过INT_MAX,就不怕溢出了,这个判断就可以不用了
		//if (high == 0)//high==0,代表处理到了最高位,退出
		//	break;//不退出,k可能会溢出
	}
	return cnt;
}
/*
* 
* 
if n = xyzdabc  
and we are considering the occurrence of one on thousand, it should be:
(1) xyz * 1000                     if d == 0
(2) xyz * 1000 + abc + 1           if d == 1
(3) xyz * 1000 + 1000              if d > 1


如果n = 4560234
让我们统计一下千位有多少个 1
xyz 可以取 0 到 455, abc 可以取 0 到 999
4551000 to 4551999 (1000)
4541000 to 4541999 (1000)
4531000 to 4531999 (1000)
...
0021000 to  0021999 (1000)
0011000 to  0011999 (1000)
0001000 to  0001999 (1000)
总共就是 456 * 1000

如果 n = 4561234
xyz 可以取 0 到 455, abc 可以取 0 到 999
4551000 to 4551999 (1000)
4541000 to 4541999 (1000)
4531000 to 4531999 (1000)
...
0001000 to 0001999 (1000)
xyz 还可以取 456, abc 可以取 0 到 234
4561000 to 4561234 (234 + 1)
总共就是 456 * 1000 + 234 + 1

如果 n = 4563234
xyz 可以取 0 到 455, abc 可以取 0 到 999
4551000 to 4551999 (1000)
4541000 to 4541999 (1000)
4531000 to 4531999 (1000)
...
0001000 to 1999 (1000)
xyz 还可以取 456, abc 可以取 0 到 999
4561000 to 4561999 (1000)
总共就是 456 * 1000 + 1000

*/
void test01()
{
	cout << countDigitOne(1999) << endl;
	
}
int main()
{
	test01();
}
#endif
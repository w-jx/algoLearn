#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


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
//�ȱ����ⷨ
int countDigitOne(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += get1nums(i);
	}
	return cnt;
}
//���Ľⷨ
int countDigitOne2(int n) {
	//4560234    456 0 234
	int cnt = 0;
	//����������1234,k=10000��ʱ������ѭ��,������4λ
	for (int k = 1; k <= n; k *= 10) {
		//����k=1000
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
		if (high == 0)//high==0,�����������λ,�˳�
			break;//���˳�,k���ܻ����
	}
	return cnt;
}
int countDigitOne3(int n) {
	//4560234    456 0 234
	int cnt = 0;
	//����������1234,k=10000��ʱ������ѭ��,������4λ
	for (long k = 1; k <= n; k *= 10) {
		//����k=1000
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
		//��k ���ó�long ����,����INT_MAX,�Ͳ��������,����жϾͿ��Բ�����
		//if (high == 0)//high==0,�����������λ,�˳�
		//	break;//���˳�,k���ܻ����
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


���n = 4560234
������ͳ��һ��ǧλ�ж��ٸ� 1
xyz ����ȡ 0 �� 455, abc ����ȡ 0 �� 999
4551000 to 4551999 (1000)
4541000 to 4541999 (1000)
4531000 to 4531999 (1000)
...
0021000 to  0021999 (1000)
0011000 to  0011999 (1000)
0001000 to  0001999 (1000)
�ܹ����� 456 * 1000

��� n = 4561234
xyz ����ȡ 0 �� 455, abc ����ȡ 0 �� 999
4551000 to 4551999 (1000)
4541000 to 4541999 (1000)
4531000 to 4531999 (1000)
...
0001000 to 0001999 (1000)
xyz ������ȡ 456, abc ����ȡ 0 �� 234
4561000 to 4561234 (234 + 1)
�ܹ����� 456 * 1000 + 234 + 1

��� n = 4563234
xyz ����ȡ 0 �� 455, abc ����ȡ 0 �� 999
4551000 to 4551999 (1000)
4541000 to 4541999 (1000)
4531000 to 4531999 (1000)
...
0001000 to 1999 (1000)
xyz ������ȡ 456, abc ����ȡ 0 �� 999
4561000 to 4561999 (1000)
�ܹ����� 456 * 1000 + 1000

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
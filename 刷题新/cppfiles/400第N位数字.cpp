#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>
/*
leecode��Ŀ����:


*/

//leetcode �����
/*
1-9		��1*9������
10-99	��2*90������
100-999 ��3*900������

��һ��:ȷ��n�����м�λ��

�ڶ���:�ҵ�n����ͣ�����Ǹ�������

������:�ҵ�n�����ֵ���һλ��

n�Ǵ�������,dig�������ּ�λ��,base��9-90-900,num����digλ������ʼ����
����n=197   dig=1,base=9 num=0
	while (n>dig*base) {
		++dig;
		num+=base;//0-9
		base*=10;
		n-=dig*base;
	}
	//��Ϊn�� 1��ʼ������,����Ҫn-1
	�˳�ѭ����ʱ��n=8,dig=3,base=900,num=99
	num += (n-1)/dig+1 =99+(8-1)/3+1=102;
	��ȷ��������102�ĵڼ�λ:
	idx = (n-1)%dig+1=2

	102�ĵڶ�λ,��0

*/
//���������д�1��ʼ,NҲ�Ǵ�1��ʼ������
int findNthDigit(int n) {
	long dig = 1, base = 9, num = 0;//���ķ�Χ��һ��
	while (n > dig * base) {
		num += base;//num��0��ʼ��99,�ٵ�999
		n -= dig * base;
		base *= 10;
		++dig;//
	}
	num += (n - 1) / dig + 1;
	int idx = (n - 1) % dig + 1;
	
	/*
	idx=1,2,3  dig=3 ,num=102
	idx=3  
	����num�Ƕ���,num%10����ȡ�����һ������
	1178&10=8,256%10=6...
	dig=1��ʱ��,����Ӧ��ȡ��һ������,ֻ�������ֱ��1λ��,����ͨ��%10�õ���һλ��
		����102/10=10,10/10=1
	dig=2��ʱ��,����Ӧ��ȡ�ڶ�������,ֻ�������ֱ��2λ��,����ͨ��%10�õ��ڶ�λ��
		102/10=10
	dig=3��ʱ��,����Ӧ��ȡ����������,ֻ�������ֱ��3λ��,����ͨ��%10�õ��ڶ�λ��
		���账��

	���Է���dig-idx ����num��Ҫ����10 �Ĵ���
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
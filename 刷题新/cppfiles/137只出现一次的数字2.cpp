#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
1.����1 ������ ��ϣ���¼ÿ�����ֳ��ֵĴ���
2.����2 

*/

int singleNumber(vector<int>& nums) {
 
	vector<int> cnt(32);
	for (int num : nums) {//���ÿһ������
		for (int i = 0; i < 32; ++i) {//���ÿһ�����ֵ�ÿһλ
			if (num & (1 << i))
				cnt[i]++;
		}
	}
	int res = 0;//�����ҵ��Ľ��
	for (int i = 0; i < 32; ++i) {
		if (cnt[i] % 3 & 1) {//��3ȡ���,�ж��Ƿ���1
			res += 1 << i;//��0λ��1,��1,��1λ��1,��2,��2λ��1,��4
		}
	}

	return res;
}
void test01()
{
	vector<int> nums{ 1,1,1,3 };
	cout << singleNumber(nums) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif
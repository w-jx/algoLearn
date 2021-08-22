#if 0
#include "../headers/wjxHeaders.h"

/*
����
17/5=3...2
12/5=2...2
17-12=5 �ܱ�5����,���Գ���һ����������ͬ���������Ĳ��ܱ����������

ͬ�ඨ��
��������ԵĴ���ʽ���� C/Java һ�£������� truncate ������������ C/Java ������:
-17 % 10 �ļ��������£�r = (-17) - (-17 / 10) x 10 = (-17) - (-1 x 10) = -7
17 % -10 �ļ��������£�r = 17 - (17 / -10) x (-10) = (17) - (-1 x -10) = 7
-17 % -10 �ļ��������£�r = (-17) - (-17 / -10) x (-10) = (-17) - (1 x -10) = -7

-17%5������Ӧ����
=-17-(-17/5)*5=-17-(-15)=-2,�Ǹ�����
���Ǹ�������Ϊ����
(-2+5)%5=3;

�ҵ�����һ������23 
23%5=3

23-(-17) = 40,��5�ı���,��֤���㷨����ȷ��
*/
int subarraysDivByK(vector<int>& nums, int k) {
	unordered_map<int, int> hashmap;
	hashmap[0] = 1;//������ǰ׺�ͱ��� K ����
	int cnt = 0;
	int n = nums.size();
	int pre = 0, remain = 0;

	/*
	���pre������,k������

	 (pre%k+k)%k
	=pre%k%k+k%k
	=pre%k+0
	=pre%k
	������k������һ����С��k��,С��k������kȡ��,һ����������
	k%kȡ����0,���Զ������ǲ�Ӱ���
	
	*/

	for (int i = 0; i < nums.size(); ++i) {
		pre += nums[i];
		//remain = pre % k,���Ǹ�������Ĵ���
		remain = (pre % k + k) % k;//��֤����������
		//��ǰ��������remain,�����ϣ�������Ѿ���������remain��,��ô
		//����֮�����k��������
		if (hashmap.count(remain) > 0) {
			cnt += hashmap[remain];
		}
		hashmap[remain]++;
	}
}
//�������������hash,����ʧ��!!!
int subarraysDivByK2(vector<int>& nums, int k) {
	int n = nums.size();
	int maxelem = *max_element(nums.begin(), nums.end());

	vector<int> hashmap(maxelem%2);
	hashmap[0] = 1;
	int pre = 0;//����ǰ׺�͵�
	int remain = 0;//����������
	int cnt = 0;//����������ĸ�����

	for (int i = 0; i < n; ++i) {
		pre += nums[i];
		remain = (pre % k + k) % k;
		cnt += hashmap[remain];
		hashmap[remain]++;
	}
	return cnt;
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
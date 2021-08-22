#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

ǰ׺��
*/
//2021��5��24�������İ汾,��[1,1,2,1,1]3,���ִ���
//��ȷ�����2,�ҵ����3
int numberOfSubarrays(vector<int>& nums, int k) {
	int n = nums.size();
	unordered_map<int, int> hashmap;
	hashmap[0] = 1;
	int pre = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		pre += nums[i] % 2;
		if (hashmap.find(k - pre) != hashmap.end()) {
			cnt += hashmap[k - pre];
		}
		hashmap[pre]++;
	}
	return cnt;
}
//���˵����ķ���
//Ϊʲôpre-k�ܹ�ͨ��,��k-pre����ͨ��
int numberOfSubarrays2(vector<int>& nums, int k) {
	int n = nums.size();
	unordered_map<int, int> hashmap;
	hashmap[0] = 1;
	int pre = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		pre += nums[i] % 2;
		//��ǰ�����ĸ���Ϊpre,�����������Ϊpre-k��ǰ׺���Ǵ��ڵ�
		//˵��һ����ǰ׺��Ϊk��
		if (hashmap.find(pre - k) != hashmap.end()) {
			cnt += hashmap[pre - k];
		}
		hashmap[pre]++;
	}
	return cnt;
}

//ͳ�������ĸ���,�����ĸ������ᳬ������ĳ���,������������ģ��hash
int numberOfSubarrays3(vector<int>& nums, int k) {
	int n = nums.size();
	//ע��ȫ�����������,���Դ�СӦ�ÿ���n+1
	vector<int> hashmap(n+1);
	hashmap[0] = 1;
	int pre = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		//λ�����ж���ż��ͨ���ж϶��������һλ���� x&1==1���棩 x&1==0��ż��
		//pre += nums[i] % 2;
		pre += nums[i] & 1;
		if (pre-k>=0)
			cnt += hashmap[pre - k];
		hashmap[pre]++;
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
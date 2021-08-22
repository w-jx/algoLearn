#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

前缀和
*/
//2021年5月24日我做的版本,在[1,1,2,1,1]3,出现错误
//正确结果是2,我的输出3
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
//别人的题解的方法
//为什么pre-k能够通过,而k-pre不能通过
int numberOfSubarrays2(vector<int>& nums, int k) {
	int n = nums.size();
	unordered_map<int, int> hashmap;
	hashmap[0] = 1;
	int pre = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		pre += nums[i] % 2;
		//当前奇数的个数为pre,如果奇数个数为pre-k的前缀和是存在的
		//说明一定有前缀和为k的
		if (hashmap.find(pre - k) != hashmap.end()) {
			cnt += hashmap[pre - k];
		}
		hashmap[pre]++;
	}
	return cnt;
}

//统计奇数的个数,奇数的个数不会超过数组的长度,可以用数组来模拟hash
int numberOfSubarrays3(vector<int>& nums, int k) {
	int n = nums.size();
	//注意全是奇数的情况,所以大小应该开辟n+1
	vector<int> hashmap(n+1);
	hashmap[0] = 1;
	int pre = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		//位运算判断奇偶（通过判断二进制最后一位）： x&1==1（奇） x&1==0（偶）
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
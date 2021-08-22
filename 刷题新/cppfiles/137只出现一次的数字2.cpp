#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
1.方法1 最好理解 哈希表记录每个数字出现的次数
2.方法2 

*/

int singleNumber(vector<int>& nums) {
 
	vector<int> cnt(32);
	for (int num : nums) {//检查每一个数字
		for (int i = 0; i < 32; ++i) {//检查每一个数字的每一位
			if (num & (1 << i))
				cnt[i]++;
		}
	}
	int res = 0;//最终找到的结果
	for (int i = 0; i < 32; ++i) {
		if (cnt[i] % 3 & 1) {//对3取余后,判断是否是1
			res += 1 << i;//第0位是1,加1,第1位是1,加2,第2位是1,加4
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
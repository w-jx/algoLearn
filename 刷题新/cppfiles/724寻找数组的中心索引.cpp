#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。

我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。


*/
int pivotIndex(vector<int>& nums) {
	if (nums.empty()) return -1;
	int sums = 0;
	for (auto iter : nums)
		sums += iter;

	int left = 0;
	for (int i = 0; i < nums.size(); i++) {
		int right = sums - left - nums[i];
		if (right == left)
			return i;
		left += nums[i];
	}
	return -1;
}
/*
从第一个元素到最后一个元素,分别检查左侧元素之和和右侧元素之和是否相等
我上面写的是能够通过的,但是思维上不够清晰
leetcode 题解的分析

数组中所有元素之和为total
假如当前在nums[i],左侧元素之和是sum,
右侧元素之和=total-sum-nums[i]
当左侧元素之和等于右侧元素之和的时候
sum = total-sum-nums[i]
也就是
2*sum+nums[i] = total,可以利用这个条件来判断
初始的时候左侧元素之和为0

*/
int pivotIndex2(vector<int>& nums) {
	int sum = 0;
	int total = accumulate(nums.begin(), nums.end(), 0);
	for (int i = 0; i < nums.size(); ++i) {
		if (2 * sum + nums[i] == total)
			return i;
		sum += nums[i];
	}
	return -1;
}
void test01()
{
	vector<int> nums = { 1, 7, 3, 6, 5, 6 };
	cout << pivotIndex(nums);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif